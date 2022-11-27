#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidgetMain1->setHorizontalHeaderLabels(QStringList() << "Xi" << "Vi" << "V2i" << "Vi - V2i" << "ОЛП" << "Hi" << "C1" << "C2" << "Ui" << "|Ui - Vi|");
    ui->tableWidgetMain1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->graph->xAxis->setLabel("x");
    ui->graph->yAxis->setLabel("Сила тока I");
    ui->graphTestTrue->xAxis->setLabel("Истинная траектория");
    ui->graph->xAxis->setLabel("Численная траектория");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButtonMainRun_clicked()
{
    double L = ui->lineEdit_L->text().toDouble();
    double R = ui->lineEdit_R->text().toDouble();
    double E0 = ui->lineEdit_E0->text().toDouble();
    double omega = ui->lineEdit_omega->text().toDouble();
    double initial_value= ui->lineEdit_I0->text().toDouble();
    double right_border = ui->lineEdit_rborder->text().toDouble();
    double initial_step =ui->lineEdit_h0->text().toDouble();
    int max_steps = ui->lineEdit_Nmax->text().toInt();
    bool ctrl_local_err = ui->radioButton->isChecked();
    double eps;

    if(ctrl_local_err == true)
        eps = ui->lineEditEPS->text().toDouble();
    else
        eps = 1e-8;

    MainWork Prog(L, R, E0, omega, right_border, initial_value, initial_step, max_steps, ctrl_local_err, eps);
    Prog.Run();
    QVector<double> x(Prog.grid.begin(), Prog.grid.end());
    QVector<double> y(Prog.final_num_values.begin(), Prog.final_num_values.end());
    QVector<double> y_true = QVector<double>(Prog.true_values.begin(), Prog.true_values.end());

    ui->graph->addGraph();
    ui->graph->graph(0)->setData(x, y);
    ui->graph->graph(0)->rescaleAxes();
    ui->graph->replot();

    ui->graphTestTrue->addGraph();
    ui->graphTestTrue->graph(0)->setData(x, y_true);
    ui->graphTestTrue->rescaleAxes();
    ui->graphTestTrue->replot();

    Prog.grid_step.pop_back();
    Prog.grid_step.insert(Prog.grid_step.begin(), initial_step);
    ui->tableWidgetMain1->clearContents();
    ui->tableWidgetMain1->setRowCount(0);

    double maxOLP = 0, maxTrueDiff = 0;
    int indMaxStep = 0, indMinStep = 0,indMaxTrueDiff = 0;
    for (int i = 0; i < Prog.grid.size(); i++)
    {
        QTableWidgetItem *x = new QTableWidgetItem(QString::number(Prog.grid[i]));
        QTableWidgetItem *v = new QTableWidgetItem(QString::number(Prog.num_values[i]));
        QTableWidgetItem *v2 = new QTableWidgetItem(QString::number(Prog.d_num_values[i]));
        QTableWidgetItem *diff = new QTableWidgetItem(QString::number(Prog.num_values[i] - Prog.d_num_values[i]));
        double tmp1 = std::abs(Prog.d_num_values[i] - Prog.num_values[i]) / 15 * 16;
        if (tmp1 > maxOLP)
            maxOLP = tmp1;
        QTableWidgetItem *OLP = new QTableWidgetItem(QString::number(tmp1));
        double tmp2 = Prog.grid_step[i];
        if (Prog.grid_step[indMaxStep] < tmp2)
            indMaxStep = i;
        if (Prog.grid_step[indMinStep] > tmp2)
            indMinStep = i;
        QTableWidgetItem *h = new QTableWidgetItem(QString::number(Prog.grid_step[i]));
        int tmp4 = i > 0 ? Prog.div2[i] - Prog.div2[i-1] : 0;
        int tmp5 = i > 1 ? Prog.mult2[i-1] - Prog.mult2[i-2] : 0;
        QTableWidgetItem *c1 = new QTableWidgetItem(QString::number(tmp4));
        QTableWidgetItem *c2 = new QTableWidgetItem(QString::number(tmp5));
        QTableWidgetItem *u = new QTableWidgetItem(QString::number(Prog.true_values[i]));
        double tmp3 = std::abs(Prog.true_values[i] - Prog.final_num_values[i]);
        if (tmp3 > maxTrueDiff)
        {
            maxTrueDiff = tmp3;
            indMaxTrueDiff = i;
        }
        QTableWidgetItem *true_diff = new QTableWidgetItem(QString::number(tmp3));
        ui->tableWidgetMain1->insertRow(i);
        ui->tableWidgetMain1->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        ui->tableWidgetMain1->setItem(i, 0, x);
        ui->tableWidgetMain1->setItem(i, 1, v);
        ui->tableWidgetMain1->setItem(i, 2, v2);
        ui->tableWidgetMain1->setItem(i, 3, diff);
        ui->tableWidgetMain1->setItem(i, 4, OLP);
        ui->tableWidgetMain1->setItem(i, 5, h);
        ui->tableWidgetMain1->setItem(i, 6, c1);
        ui->tableWidgetMain1->setItem(i, 7, c2);
        ui->tableWidgetMain1->setItem(i, 8, u);
        ui->tableWidgetMain1->setItem(i, 9, true_diff);
    }

    /*QString ref = "Число шагов метода: "  + QString::number(Prog.grid.size()-1) + "\nb - xN = " +  QString::number(Prog.right_border - Prog.grid.back())
            + "\nmax|ОЛП| = " + QString::number(maxOLP) + "\nОбщее число удвоений шага: " + QString::number(Prog.mult) + "\nОбщее число делений шага: "
            + QString::number(Prog.div) + "\nmax{Hi} = " + QString::number(Prog.grid_step[indMaxStep]) + " при x = " + QString::number(Prog.grid[indMaxStep])
            + "\nmin{Hi} = " + QString::number(Prog.grid_step[indMinStep]) + " при x = " + QString::number(Prog.grid[indMinStep]);
    ui->textBrowser->setText(ref);*/

    QString ref = "\tСправка\nМетод Рунге-Кутта явный порядка p = 4 \nНачальное значение силы тока: " + QString::number(initial_value) + "А"
            + "\nЧисло шагов метода: "   + QString::number(Prog.grid.size()-1)
            + "\nНачальное время счёта = 0 сек.\nУсловие остановки счёта = " + QString::number(Prog.right_border)
            + "\nРасстояние до правой границы счёта = "   + (QString::number(Prog.right_border - Prog.grid.back()));
             ref = ref +(ctrl_local_err? "\nКонтроль модуля локальной погрешности включён\nEps граничный = " +  QString::number(Prog.eps)
                   : "\nКонтроль модуля локальной погрешности выключен");

          ref+= "\n\nКоэффициент самоиндукции  = " + QString::number(Prog.L) + "Гн"
            + "\nСопротивление = " + QString::number(Prog.R) + "Ом"
            + "\nАмплитудное значение ЭДС = " + QString::number(Prog.E0) + "B"
            + "\nЦиклическая частота = " + QString::number(Prog.omega) + "рад/c"

            + "\n\nmax|ОЛП| = " + QString::number(maxOLP)
            + "\nОбщее число удвоений шага: " + QString::number(Prog.mult)
            + "\nОбщее число делений шага: " + QString::number(Prog.div)
            + "\nМаксимальный шаг = " + QString::number(Prog.grid_step[indMaxStep])
            + " при x = " + QString::number(Prog.grid[indMaxStep])
            + "\nМинимальный шаг = " + QString::number(Prog.grid_step[indMinStep])
            + " при x = " + QString::number(Prog.grid[indMinStep]);
     ui->textBrowser->setText(ref);


}

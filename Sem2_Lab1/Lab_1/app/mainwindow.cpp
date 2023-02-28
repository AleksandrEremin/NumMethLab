#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graph->xAxis->setRange(-8,8);// Для примера;
    ui->graph->yAxis->setRange(-4,9);// Для примера;


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PushApproximate_clicked() // Для примера;
{
    double h = 0.1;
    MainWork Prog(-7, 7+h);
    Prog.N = (Prog.xEnd - Prog.xBegin)/h + 2;
    ui->graph->clearGraphs();

    QString Func = ui->FuncList->currentItem()->text();

    if(ui->radioButtonFunc->isChecked())// Можно switch
       {
        if(Func == "F(x) = sinx")
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back(sin(Prog.X));
           }
       }
       else if(Func == "F(x) = cosx")
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back(cos(Prog.X));
           }
       }
       else
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back(tan(Prog.X));
           }
       }
    }
    if(ui->radioButtonFunc1->isChecked())
    {
        if(Func == "F(x) = sinx")
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back(cos(Prog.X));
           }
       }
       else if(Func == "F(x) = cosx")
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back(-sin(Prog.X));
           }
       }
       else
       {
           for(Prog.X = Prog.xBegin; Prog.X<Prog.xEnd; Prog.X+=h)
           {
               Prog.x.push_back(Prog.X);
               Prog.y.push_back((1/cos(Prog.X))*(1/cos(Prog.X)));
           }
       }
    }
       ui->graph->addGraph();
       ui->graph->graph(0)->addData(Prog.x, Prog.y);
       ui->graph->replot();
       Prog.x.clear();
       Prog.y.clear();
}





void MainWindow::on_FuncList_clicked(const QModelIndex &index)
{

}

void MainWindow::on_pushButtonMainRun_clicked()
{

}


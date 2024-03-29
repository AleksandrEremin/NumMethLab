#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "MainWork.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonMainRun_clicked();

    void on_PushApproximate_clicked();

    void on_FuncList_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

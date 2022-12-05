#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Команда №3, задача 9, вариант 6. Отвечает - Еремин АН.");
    w.show();
    return a.exec();
}

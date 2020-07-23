#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/images/images/satellite.png"));
    w.setWindowTitle("BestXYZ Processor");

    w.show();
    return a.exec();
}


/*
 * Special Thanks to the noun project
 * URL: thenounproject.com
 *
 * Communication Satellite by ProSymbols from the Noun Project
 *
 * create folder by Raphaël Buquet from the Noun Project
 * */

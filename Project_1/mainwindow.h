#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    bool checkPermissions(QFile *file, int fileType);
    //Checks that the permissions of a file coincide with the type of file
    //provided.
    //fileType can currently accept 0 for input files and any value greater than 0 for output files.


private slots:
    void on_SelectFile_Button_clicked();
    //Button to finalize the selection of an input file

    void on_SelectFile2_Button_clicked();
    //Button to finalize the selection of an output file

    void on_InputSearch_Button_clicked();
    //Button for searching for an input file through the file explorer

    void on_OutputSearch_Button_clicked();
    //Button for searching for an output file through the file explorer

private:
    Ui::MainWindow *ui;
    QFile *inputFile;
    QFile *outputFile;
    QString inputFileName;
    QString outputFileName;
};
#endif // MAINWINDOW_H

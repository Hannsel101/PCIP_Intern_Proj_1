#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GPS_Sensor.h"
#include "messages.h"
#include "myThread.h"

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QDoubleValidator>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    myThread* mThread;

private:
    bool checkPermissions(QFile *file, int fileType);
    /*
     * Checks file permissions for input/output files.
     * Returns a boolean TRUE if the file passes all checks.
     * Returns a boolean FALSE otherwise
     *
     * file = a pointer to a file specified by the user during runtime
     * fileType = an integer that accepts "0" for input files and "1"
     *            for output files.
     * */

    bool checkOutputFile();
    bool checkLogFile();
    /*
     * The check""File() functions run through a series of checks to
     * ensure that a suitable input/output/log file has been selected.
     *
     * If no output/log file has been selected then one will be generated
     * for the user automatically in the same directory as the selected
     * input file.
     * */

    QString generateOutputFile(QString inputPath, QString fileType);
    /*
     * Generates an output file based on the inputPath specified by the user and the extension
     * expected for the file.
     *
     * inputPath = absolute path leading up to the input file
     * fileType = the extension for the newly generated file
     * */

    void setFormEnable(bool enable);

public slots:
    void onNumberChanged(int);
    void onLogUpdate(unsigned int);
    void onStartTimeUpdated(double);
    void onEndRunUpdated(double, unsigned int, double);

private slots:
    void on_InputSearch_Button_clicked();
    //Button for selecting an input file through the file explorer

    void on_OutputSearch_Button_clicked();
    //Button for selecting an output file through the file explorer

    void on_LogSearch_Button_clicked();
    //Button for selecting a log file through the file explorer

    void on_process_Button_clicked();
    //Upon clicking the process button a series of checks will begin on the file selections.
    //If no file is selected as input, then a message will prompt the user to select an input file.
    //else if no file is selected for the


    void on_antennaPosition_Button_clicked();



private:
    Ui::MainWindow *ui;
    QFile *inputFile;
    QFile *outputFile;
    QFile *logFile;
    QString inputFileName = "";
    QString outputFileName = "";
    QString logFileName = "";
    GPS_Sensor sensor;
};
#endif // MAINWINDOW_H

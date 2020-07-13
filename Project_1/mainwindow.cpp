#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set pointers to null
    inputFile = nullptr;
    outputFile = nullptr;
    logFile = nullptr;

    //Hide file selection status labels
    ui->outputFile_Confirm->setText("");
    ui->inputFile_Confirm->setText("");
    ui->logFile_Confirm->setText("");
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_InputSearch_Button_clicked()
{
    //Begin the search from the home directory of the current profile
    inputFileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());

    //update the textfield in the GUI to show the selected filepath
    ui->Input_LineEdit->setText(inputFileName);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_OutputSearch_Button_clicked()
{
    //Begin the search from the home directory of the current profile
    outputFileName = QFileDialog::getSaveFileName(this, "Open a file", QDir::homePath());

    //update the textfield in the GUI to show the selected filepath
    ui->output_LineEdit->setText(outputFileName);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_LogSearch_Button_clicked()
{
    //Begin the search from the home directory of the current profile
    logFileName = QFileDialog::getSaveFileName(this, "Select a log file", QDir::homePath());

    //update the textfield in the GUI to show the selected filepath
    ui->log_LineEdit->setText(logFileName);

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool MainWindow::checkPermissions(QFile *file, int fileType)
{
    if(fileType == 0)//Input file
    {
        if(file->exists())
        {
            if(!file->open(QFile::WriteOnly | QFile::Text))
            {
                return false;
            }
            return true;
        }
        return false;
    }
    else if(fileType == 1)//Output file
    {
        if(file->exists())
        {
            if(!file->open(QFile::ReadOnly | QFile::Text))
            {
                return false;
            }
            return true;
        }
        else
        {
            //file->open(QIODevice::WriteOnly);//Create a write only file
            return false;
        }
    }
    else if(fileType == 2)//Log file
    {
        return false;//placeholder
    }
    else
    {
        return false;
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_process_Button_clicked()
{
    //pull the selected file names from the input fields
    inputFileName = ui->Input_LineEdit->text();
    outputFileName = ui->output_LineEdit->text();
    logFileName = ui->log_LineEdit->text();

    //Check if an input file as been selected
    if(inputFileName.length() > 0)
    {
        //Open input file and check permissions
        inputFile = new QFile(inputFileName);
        if(!checkPermissions(inputFile, 0))
        {
            QMessageBox::warning(this, "Permissions Error", "Input file not opened!");
            ui->inputFile_Confirm->setText("Error: File does not have read permissions");
            ui->inputFile_Confirm->setStyleSheet("QLabel { background-color:#96201a; color:white;}");
            ui->Input_LineEdit->setStyleSheet("border: 1px solid red");
        }
        else
        {

            ui->inputFile_Confirm->setText("Success: Input file has been selected");
            ui->inputFile_Confirm->setStyleSheet("QLabel { background-color:#1f6327; color:white;}");
            ui->Input_LineEdit->setStyleSheet("border: 1px solid green");

            //Check if an output and log file have been specified or will be generated based on input
            if(outputFileName.length() > 0)
            {
                outputFile = new QFile(outputFileName);
                if(!checkPermissions(outputFile, 1))
                {
                    QMessageBox::warning(this, "Permissions Error", "Output file not opened!");
                    ui->outputFile_Confirm->setText("Error: File does not have write permissions. (To automatically generate a file leave the field blank and begin processing again)");
                    ui->outputFile_Confirm->setStyleSheet("QLabel { background-color:#96201a; color:white;}");
                    ui->output_LineEdit->setStyleSheet("border: 1px solid red");
                }
                else
                {
                    ui->outputFile_Confirm->setText("Success: Output file has been selected");
                    ui->outputFile_Confirm->setStyleSheet("QLabel { background-color:#1f6327; color:white;}");
                    ui->output_LineEdit->setStyleSheet("border: 1px solid green");
                }
            }
            else//Generate an output file based on input
            {
                ui->outputFile_Confirm->setText("Warning: An output file has been generated based on input file name");
                ui->outputFile_Confirm->setStyleSheet("QLabel {background-color:#ad6c0a; color:white;}");
                ui->output_LineEdit->setStyleSheet("border: 1px solid orange");
            }


            //Check if a log file has been selected
            if(logFileName.length() > 0)
            {
                ui->logFile_Confirm->setText("Success: log file has been selected");
                ui->logFile_Confirm->setStyleSheet("QLabel { background-color:#1f6327; color:white;}");
                ui->log_LineEdit->setStyleSheet("border: 1px solid green");
            }
            else
            {
                ui->logFile_Confirm->setText("Warning: A log file has been generated based on input file name");
                ui->logFile_Confirm->setStyleSheet("QLabel {background-color:#ad6c0a; color:white;}");
                ui->log_LineEdit->setStyleSheet("border: 1px solid orange");
            }
        }
    }
    else
    {
        ui->inputFile_Confirm->setText("Error: An input file must be specified");
        ui->inputFile_Confirm->setStyleSheet("QLabel { background-color:#96201a; color:white;}");
        ui->Input_LineEdit->setStyleSheet("border: 1px solid red");
        ui->logFile_Confirm->setText("");
        ui->logFile_Confirm->setStyleSheet("");
        ui->outputFile_Confirm->setText("");
        ui->outputFile_Confirm->setStyleSheet("");
        ui->log_LineEdit->setStyleSheet("");
        ui->output_LineEdit->setStyleSheet("");
    }
    ui->inputFile_Confirm->show();
}


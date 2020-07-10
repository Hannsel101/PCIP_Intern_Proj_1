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

    //Initial configurations of labels
    ui->inputFile_Confirm->setText("- No input file selected");
    ui->inputFile_Confirm->setStyleSheet("QLabel { background-color:red; color:white;}");
    ui->outputFile_Confirm->setStyleSheet("QLabel { background-color:red; color:white;}");
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_SelectFile_Button_clicked()
{
    //Extract the text entered by the user and store it in a QFile object
    //for further processing
    inputFileName = ui->Input_LineEdit->text();
    inputFile = new QFile(inputFileName);

    //Verify the file exists before continuing
    if(inputFile->exists())
    {
        //Check that the file does not have write only permissions and notify
        //the user of successful or failed file access
        if(!inputFile->open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Permissions Error", "File not opened!");
        }
        else
        {
            QMessageBox::information(this, "Success", "Input file has been selected");
            QString confirmSelection = "Input File: " + inputFileName;
            ui->inputFile_Confirm->setText(confirmSelection);
            ui->inputFile_Confirm->setStyleSheet("QLabel { background-color:green; color:white;}");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "File does not exist");
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_SelectFile2_Button_clicked()
{
    outputFileName = ui->output_LineEdit->text();
    outputFile = new QFile(outputFileName);

    bool goodFile = checkPermissions(outputFile, 1);

    if(goodFile)
    {
        QMessageBox::information(this, "Success", "Output file has been selected");
        QString confirmSelection = "Output File: " + outputFileName;
        ui->outputFile_Confirm->setText(confirmSelection);
        ui->outputFile_Confirm->setStyleSheet("QLabel { background-color:green; color:white;}");
    }
    else
    {
        QMessageBox::warning(this, "Permissions Error", "File does not have write permissions");
    }

    //Verify the file exist before continuing
    //if(outputFile->exists())
    //{
        //Check the file permissions
      //  if(!outputFile->open(QFile::ReadOnly | QFile::Text))
       // {
         //   QMessageBox::warning(this, "Permissions Error", "File does not have write permissions");
        //}
        //else
        //{
         //   QMessageBox::information(this, "Success", "Output file has been selected");
          //  QString confirmSelection = "Output File: " + outputFileName;
           // ui->outputFile_Confirm->setText(confirmSelection);
           // ui->outputFile_Confirm->setStyleSheet("QLabel { background-color:green; color:white;}");
        //}
    //}
    //***ADD OUTPUT SELECT HERE LATER*******//
    //***ADD OUTPUT SELECT HERE LATER*******//
    //***ADD OUTPUT SELECT HERE LATER*******//
    //***ADD OUTPUT SELECT HERE LATER*******//
    //***ADD OUTPUT SELECT HERE LATER*******//

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_InputSearch_Button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());
    QMessageBox::information(this, "..", fileName);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_OutputSearch_Button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());
    QMessageBox::information(this, "..", fileName);
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
    else if(fileType > 0)//Output file
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
            file->open(QIODevice::WriteOnly);//Create a write only file
            return true;
        }
    }
    else
    {
        return false;
    }
}

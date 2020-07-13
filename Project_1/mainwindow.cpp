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
            QMessageBox::warning(this, "Permissions Error", "Invalid input file!");
            ui->Input_LineEdit->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->Input_LineEdit->setStyleSheet("border: 1px solid green");

            //Check if an output and log file have been specified or will be generated based on input
            if(outputFileName.length() > 0)
            {
                outputFile = new QFile(outputFileName);
                if(!checkPermissions(outputFile, 1))
                {
                    QMessageBox::warning(this, "Permissions Error", "Please select a different output file");
                    ui->output_LineEdit->setStyleSheet("border: 1px solid red");
                }
                else
                {
                    ui->output_LineEdit->setStyleSheet("border: 1px solid green");
                }
            }
            else//Generate an output file based on input
            {
                outputFileName = generateOutputFile(inputFileName, "Output.txt");

                if(outputFile != nullptr)
                {
                    outputFile->close();
                    outputFile=nullptr;
                }

                outputFile = new QFile(outputFileName);
                int currentIndex = outputFileName.length()-1;
                for(;currentIndex>0; --currentIndex)
                {
                    if(outputFileName.at(currentIndex) == '.')
                    {
                        break;
                    }
                }
                char nameInt = '0';
                while(outputFile->exists())
                {
                    if(nameInt == '0')//If first run through the loop
                    {
                        nameInt++;
                        outputFileName.insert(currentIndex, nameInt);
                    }
                    else
                    {
                        outputFile->close();
                        outputFile = nullptr;
                        outputFileName.replace(currentIndex, 1, nameInt);
                        outputFile = new QFile(outputFileName);
                        nameInt++;
                    }

                }
                //create file and update text field
                outputFile->open(QIODevice::WriteOnly);
                ui->output_LineEdit->setText(outputFileName);
            }


            //Check if a log file has been selected
            if(logFileName.length() > 0)
            {
                logFile = new QFile(logFileName);

                if(!checkPermissions(logFile,1))//Check the permissions of the selected log file
                {
                    QMessageBox::warning(this, "Permissions Error", "Please select a different log file");
                    ui->log_LineEdit->setStyleSheet("border: 1px solid red");
                }
                else
                {
                    ui->log_LineEdit->setStyleSheet("border: 1px solid green");
                }
            }
            else//Generate a log file based on input file name
            {
                logFileName = generateOutputFile(inputFileName, "Log.txt");

                if(logFile != nullptr)
                {
                    logFile->close();
                    logFile=nullptr;
                }

                logFile = new QFile(logFileName);
                int currentIndex = logFileName.length()-1;
                for(;currentIndex>0; --currentIndex)
                {
                    if(logFileName.at(currentIndex) == '.')
                    {
                        break;
                    }
                }
                char nameInt = '0';
                while(logFile->exists())
                {
                    if(nameInt == '0')//If first run through the loop
                    {
                        nameInt++;
                        logFileName.insert(currentIndex, nameInt);
                    }
                    else
                    {
                        logFile->close();
                        logFile = nullptr;
                        logFileName.replace(currentIndex, 1, nameInt);
                        logFile = new QFile(logFileName);
                        nameInt++;
                    }

                }
                //create file and update text field
                logFile->open(QIODevice::WriteOnly);
                ui->log_LineEdit->setText(logFileName);
            }//End Generate log file
        }
    }
    else
    {
        ui->Input_LineEdit->setStyleSheet("border: 1px solid red");
        ui->log_LineEdit->setStyleSheet("");
        ui->output_LineEdit->setStyleSheet("");
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
QString MainWindow::generateOutputFile(QString inputPath, QString fileType)
{
    for(int i=inputPath.length()-1; i>0; --i)
    {
        if(inputPath.at(i) == ".")//if the beginning of the extension is found
        {
            //Remove the extension and append to the new filename
            inputPath.remove(i,inputPath.length()-i);
            inputPath.append("_" + fileType);
            return inputPath;
        }
    }
}

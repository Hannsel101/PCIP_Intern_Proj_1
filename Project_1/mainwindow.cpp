#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setting up the folder images for file search buttons
    QPixmap folderPixmap(":/images/images/folder.png");
    ui->InputSearch_Button->setIcon(folderPixmap);
    ui->OutputSearch_Button->setIcon(folderPixmap);
    ui->LogSearch_Button->setIcon(folderPixmap);

    //Ensure only doubles are allowed in (E,F,G) coordinate input
    ui->E_Input->setValidator(new QDoubleValidator(0,100,10,this));
    ui->F_Input->setValidator(new QDoubleValidator(0,100,10,this));
    ui->G_Input->setValidator(new QDoubleValidator(0,100,10,this));

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
            if(!file->open(QFile::ReadOnly))
            {
                return false;
            }
            file->close();
            return true;
        }
        return false;
    }
    else if(fileType == 1)//Output file
    {
        if(file->exists())
        {
            if(!file->open(QFile::WriteOnly | QFile::Text))
            {
                return false;
            }

            file->close();
            return true;

        }
        return true;
        //else
        //{
          //  return false;
        //}
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
        if(!checkPermissions(inputFile, 0))//Failed the permissions check
        {
            QMessageBox::warning(this, "Permissions Error", "Invalid input file!");
            ui->Input_LineEdit->setStyleSheet("border: 1px solid red");
        }
        else//Passed the permissions check
        {

            //Update the GUI and check for the output and log file text entry fields
            ui->Input_LineEdit->setStyleSheet("border: 1px solid green");
            checkOutputFile();
            checkLogFile();

            //For Debugging**************************************
            //****************************************************
            messages mes1;
            mes1.readAndProcess(inputFileName, outputFileName, logFileName);
            //For Debugging**************************************
            //****************************************************

            if((ui->E_Input->text() > 0) && (ui->F_Input->text() > 0) && (ui->G_Input->text() > 0))
            {
                double E = ui->E_Input->text().toDouble();
                double F = ui->F_Input->text().toDouble();
                double G = ui->G_Input->text().toDouble();
                sensor.setPos(E, F, G);
                QString valueAsString = QString::number(E);
                ui->endTime->setText(valueAsString);
            }
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
void MainWindow::checkOutputFile()
{
    //Check if an output file has been specified or will be generated based on input
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

        //create file and update text field
        //outputFile->open(QIODevice::WriteOnly);
        qDebug() << endl << outputFileName << endl;
        ui->output_LineEdit->setText(outputFileName);
        ui->output_LineEdit->setStyleSheet("border: 1px solid green");
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::checkLogFile()
{
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

        ui->log_LineEdit->setText(logFileName);
        ui->log_LineEdit->setStyleSheet("border: 1px solid green");
    }//End Generate log file
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
    return "";
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::on_antennaPosition_Button_clicked()
{
    QString antennaFileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath());
    bool test = sensor.setFile(antennaFileName);

    if(test)
    {
        if(sensor.extractPos())
        {
            //QString updateGUI = QString::number(sensor.getPosE());
            //ui->E_Input->setText(updateGUI);

            //updateGUI = QString::number(sensor.getPosF());
            //ui->F_Input->setText(updateGUI);

            //updateGUI = QString::number(sensor.getPosG());
            //ui->G_Input->setText(updateGUI);

            QStringList line = sensor.getDebug().split(',');
            sensor.setPos(line[0].toDouble(), line[1].toDouble(), 0);
            QString conversion = QString::number(sensor.getPosE());
            ui->E_Input->setText(conversion);

            conversion = QString::number(sensor.getPosF());
            ui->F_Input->setText(conversion);

        }
        else
        {
            qDebug("Wrong file format!");
        }
    }
    else
    {
        qDebug("Invalid file name");
    }

    //messages message1;
    //char msgBuf[1024];
    //message1.readIntoBuffer(msgBuf);
}

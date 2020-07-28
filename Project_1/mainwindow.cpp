#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup extra Thread
    mThread = new myThread(this);
    connect(mThread, SIGNAL(updateStartTime(double)), this, SLOT(onStartTimeUpdated(double)));
    connect(mThread, SIGNAL(endRunUpdate(double, unsigned int, double)), this, SLOT(onEndRunUpdated(double, unsigned int, double)));
    //connect(mThread, SIGNAL(logUpdate(unsigned int)), this, SLOT(onLogUpdate(unsigned int)));


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
            if(!checkOutputFile())
                return;
            if(!checkLogFile())
                return;

            mThread->InputFileName = inputFileName;
            mThread->OutputFileName = outputFileName;
            mThread->LogFileName = logFileName;

            //Check if antenna position is valid
            if((ui->E_Input->text() == 0) || (ui->F_Input->text() == 0) || (ui->G_Input->text() == 0))
            {
                //Prompt the user to select an input file
                MainWindow::on_antennaPosition_Button_clicked();

                //Validate entered antenna position
                if((ui->E_Input->text() == 0) || (ui->F_Input->text() == 0) || (ui->G_Input->text() == 0))
                {
                    QMessageBox::warning(this, "Invalid Antenna Position", "Please input E, F, and G coordinates");
                    return;
                }
            }


            double E = ui->E_Input->text().toDouble();
            double F = ui->F_Input->text().toDouble();
            double G = ui->G_Input->text().toDouble();
            mThread->sensor.setPos(E, F, G);

            setFormEnable(false);
            //Start Processing Thread
            mThread->start();
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
bool MainWindow::checkOutputFile()
{
    bool status = false;
    //Check if an output file has been specified or will be generated based on input
    if(outputFileName.length() > 0)
    {
        QFile* outputFile = new QFile(outputFileName);

        if(!outputFile->exists() || !checkPermissions(outputFile, 1))
        {
            QMessageBox::warning(this, "Permissions Error", "Please select a different output file");
            ui->output_LineEdit->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->output_LineEdit->setStyleSheet("border: 1px solid green");
            status = true;
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
        ui->output_LineEdit->setText(outputFileName);
        ui->output_LineEdit->setStyleSheet("border: 1px solid green");
        status = true;
    }

    if(outputFile != nullptr)
    {
        outputFile->close();
        outputFile = nullptr;
    }
    return status;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool MainWindow::checkLogFile()
{
    bool status = false;
    //Check if a log file has been selected
    if(logFileName.length() > 0)
    {
        logFile = new QFile(logFileName);

        if(!logFile->exists() || !checkPermissions(logFile,1))//Check the permissions of the selected log file
        {
            QMessageBox::warning(this, "Permissions Error", "Please select a different log file");
            ui->log_LineEdit->setStyleSheet("border: 1px solid red");
        }
        else
        {
            ui->log_LineEdit->setStyleSheet("border: 1px solid green");
            status = true;
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
        status = true;
    }//End Generate log file

    if(logFile != nullptr)
    {
        logFile->close();
        logFile = nullptr;
    }
    return status;
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
            //Split the input from the position file into three comma seperated numbers
            QStringList line = sensor.getDebug().split(',');

            if(line.size() < 3)
            {
                QMessageBox::warning(this, "Antennal Load Position Error", "Invalid File Selected");
                return;
            }

            sensor.setPos(line[0].toDouble(), line[1].toDouble(), line[2].toDouble());

            //Update the text entry fields corresponding with ECEF(E, F, G) coordinates
            //to show the extracted comma seperated values
            QString conversion = QString::number(sensor.getPosE(), 'f', 10);
            ui->E_Input->setText(conversion);

            conversion = QString::number(sensor.getPosF(), 'f', 10);
            ui->F_Input->setText(conversion);

            conversion = QString::number(sensor.getPosG(), 'f', 10);
            ui->G_Input->setText(conversion);
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
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::onNumberChanged(int number)
{
    ui->endTime->setText(QString::number(number));
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::onLogUpdate(unsigned int recordsProcessed)
{
    QString update = "Records Processed: " + QString::number(recordsProcessed);
    ui->recordsProcessed->setText(update);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void MainWindow::onStartTimeUpdated(double startTime)
{
    QString update = "Start Time GPS: " + QString::number(startTime, 'f', 1);
    ui->startTime->setText(update);
}

void MainWindow::onEndRunUpdated(double endTime, unsigned int recordsProcessed, double pcnt)
{
    QString update = "End Time: " + QString::number(endTime, 'f', 1);
    ui->endTime->setText(update);

    update = "Records Processed: " + QString::number(recordsProcessed);
    ui->recordsProcessed->setText(update);

    update = "% RSS > 0.5m: " + QString::number(pcnt, 'f', 1);
    ui->percentRSS->setText(update);

    setFormEnable(true);
}

void MainWindow::setFormEnable(bool enable)
{
    ui->Input_LineEdit->setEnabled(enable);
    ui->output_LineEdit->setEnabled(enable);
    ui->log_LineEdit->setEnabled(enable);
    ui->E_Input->setEnabled(enable);
    ui->F_Input->setEnabled(enable);
    ui->G_Input->setEnabled(enable);
    ui->process_Button->setEnabled(enable);
    ui->InputSearch_Button->setEnabled(enable);
    ui->OutputSearch_Button->setEnabled(enable);
    ui->LogSearch_Button->setEnabled(enable);
    ui->antennaPosition_Button->setEnabled(enable);
}

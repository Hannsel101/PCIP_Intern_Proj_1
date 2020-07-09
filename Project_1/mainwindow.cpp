#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SelectFile_Button_clicked()
{
    //Extract the text entered by the user and store it in a QFile object
    //for further processing
    inputFile = ui->Input_LineEdit->text();
    input = new QFile(inputFile);

    //Verify the file exists before continueing
    if(input->exists())
    {
        //Check that the file does not have read permissions and notify
        //the user of successful or failed file access
        if(!input->open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::warning(this, "Permissions Error", "File not opened!");
        }
        else
        {
            QMessageBox::information(this, "Success", "File opened successfully");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "File does not exist");
    }
}

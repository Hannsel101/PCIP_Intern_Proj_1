#include "myThread.h"

#include <QDebug>

myThread::myThread(QObject *parent):
    QThread(parent)
{
    threadInt = 0;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void myThread::run()
{
    this->Stop = false;

    if(!Stop)
    {
        messages mes1;
        mes1.readAndProcess(this->InputFileName, this->OutputFileName, this->LogFileName, this->sensor);
        //this->Stop = true;
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//

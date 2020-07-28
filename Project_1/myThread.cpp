#include "myThread.h"
#include <QDebug>

myThread::myThread(QObject *parent):
    QThread(parent)
{
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void myThread::run()
{
        messages mes1;
        connect(&mes1, SIGNAL(startTimeUpdated(double)), this, SLOT(onStartTimeUpdated(double)));
        connect(&mes1, SIGNAL(endRunUpdate(double, unsigned int, double)), this, SLOT(onEndRunUpdated(double, unsigned int, double)));
        mes1.readAndProcess(this->InputFileName, this->OutputFileName, this->LogFileName, this->sensor);


        //Emit updates to the GUI
        //emit logUpdate(recordsProcessed);

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void myThread::onStartTimeUpdated(double updatedTime)
{
    emit updateStartTime(updatedTime);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void myThread::onEndRunUpdated(double endTime, unsigned int recordsProcessed, double pcnt)
{
    emit endRunUpdate(endTime, recordsProcessed, pcnt);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//

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
    while(!this->Stop)
    {
        //QMutex mutex;
        //mutex.lock();
        //if(this->myThread::Stop())
        //{
          //  break;
        //}
        //mutex.unlock();
        myThread::threadInt++;
        if(threadInt%10 == 0)
        {
            emit NumberChanged(threadInt);
        }
        this->msleep(100);
    }

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//

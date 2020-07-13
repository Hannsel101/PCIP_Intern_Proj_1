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
    for(int i = 0; i < 10; ++i)
    {
        QMutex mutex;
        mutex.lock();
        if(this->myThread::Stop())
        {
            break;
        }
        mutex.unlock();
        myThread::threadInt++;
    }

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
int myThread::getInt()
{
    return myThread::threadInt;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool myThread::Stop()
{
    return true;
}

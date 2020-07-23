#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>
#include "messages.h"
#include "GPS_Sensor.h"

class myThread: public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);
    void run();
    bool Stop;
    QString InputFileName;
    QString OutputFileName;
    QString LogFileName;
    GPS_Sensor sensor;

public slots:

signals:
    void NumberChanged(int);


private:
    int threadInt = 0;
};


#endif // MYTHREAD_H

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
    void onStartTimeUpdated(double);
    void onEndRunUpdated(double, unsigned int, double);

signals:
    void logUpdate(unsigned int);
    void updateStartTime(double);
    void endRunUpdate(double, unsigned int, double);


private:
};


#endif // MYTHREAD_H

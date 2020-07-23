#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtCore>

class myThread: public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = 0);
    void run();
    bool Stop;

public slots:

signals:
    void NumberChanged(int);


private:
    int threadInt = 0;
};


#endif // MYTHREAD_H

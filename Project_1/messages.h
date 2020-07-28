#ifndef MESSAGES_H
#define MESSAGES_H

#include "structs.h"
#include <QtCore>
#include "GPS_Sensor.h"

class messages: public QObject
{
    Q_OBJECT
public:
    explicit messages(QObject *parent = nullptr);
    void readAndProcess(QString inputFileName,
                        QString outputFileName, QString logFileName, GPS_Sensor sensor);
    /*
     * Read message contents into buffer
     * */
    unsigned int getNumRecordsProcessed();

    virtual ~messages() {};

signals:
    void startTimeUpdated(double);
    void endRunUpdate(double, unsigned int, double);

private:
    bool checkIndexes(int read_Index, int write_Index, int count);
    double utc_Offset;
    unsigned int gpsSats;
    unsigned int recordsProcessed;
    unsigned int RSS_Over_half;
    double startTimeGPS;
    double endTimeGPS;
};

#endif // MESSAGES_H

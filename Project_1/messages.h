#ifndef MESSAGES_H
#define MESSAGES_H

#include "structs.h"
#include <QtCore>

class messages
{
public:
    void readAndProcess(QString inputFileName,
                        QString outputFileName, QString logFileName);
    /*
     * Read message contents into buffer
     * */


    messages();
    ~messages();

private:
    bool checkIndexes(int read_Index, int write_Index, int count);
    double utc_Offset;
    unsigned int gpsSats;

};

#endif // MESSAGES_H

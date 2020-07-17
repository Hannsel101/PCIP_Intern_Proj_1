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
    NovaHeader nova_msg;
    unsigned char *sync_ptr;
    unsigned char *msg_ptr;

};

#endif // MESSAGES_H

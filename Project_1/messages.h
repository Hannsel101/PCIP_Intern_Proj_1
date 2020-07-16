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
    char *sync_ptr;
    char *msg_ptr;

};

#endif // MESSAGES_H

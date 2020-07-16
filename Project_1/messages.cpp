#include "messages.h"

#include <stdio.h>
#include <string>

#define BUFF_SIZE 1024
#define RING_WRITE(idx, sz) {idx++; idx &= (unsigned int)(BUFF_SIZE-1); sz++;}
#define RING_READ(idx, sz) {idx++; idx &= (unsigned int)(BUFF_SIZE-1); sz--;}


messages::messages()
{
    sync_ptr = nullptr;
    msg_ptr = nullptr;
}

messages::~messages()
{

}

void messages::readAndProcess(QString inputFileName,
                              QString outputFileName, QString logFileName)
{

        FILE* inputFile;
        FILE* outputFile;


        //Convert QString into a byte array to use in fopen_s
        QByteArray baif = inputFileName.toLocal8Bit();
        char msgBuffer[BUFF_SIZE];
        const char* inputName = baif.data();

        baif = outputFileName.toLocal8Bit();
        const char* outputName = baif.data();


        //Open input file in read binary
        fopen_s(&inputFile, inputName, "rb");
        errno_t err = fopen_s(&outputFile, outputName, "wt");

        if(err == 0)
            printf("\n\n\n**************Success\n\n\n\n");
        else
            printf("\n\n\n**************Error\n\n\n\n");


        int numread;
        bool lastRead = false;



        while(!lastRead)
        {

            //Read up to 1024 bytes out of the input file stream
            numread = fread(msgBuffer, 1, BUFF_SIZE, inputFile);

            //Edge case when end of file has been reached
            if (numread < BUFF_SIZE)
            {
                lastRead = true;
                for (int k = 0; k < numread; ++k)
                    printf("%.2X ", msgBuffer[k]);
                printf("\n");
            }




        }//for (int i = 0; i < 9; ++i)

        //fprintf(outputFile, "%.2X", msgBuffer[0]);

        fclose(inputFile);
        fclose(outputFile);
}

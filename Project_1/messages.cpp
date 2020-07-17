#include "messages.h"

#include <stdio.h>

#define BUFF_SIZE 8192
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
        //File pointers for input and output files
        FILE* inputFile;
        FILE* outputFile;
        FILE* logFile;

        //File reading flags
        int numread;
        unsigned int sz = 0;
        bool lastRead = false;

        //Ring buffer variables
        unsigned char msgBuffer[BUFF_SIZE];
        unsigned char* read = msgBuffer;
        unsigned char* write = msgBuffer;
        unsigned int read_Index=0;
        unsigned int write_Index=0;



        //Convert QString into a byte array to use in fopen_s
        QByteArray baif = inputFileName.toLocal8Bit();
        const char* inputName = baif.data();
        QByteArray baof = outputFileName.toLocal8Bit();
        const char* outputName = baof.data();

        //Open input and output files
        fopen_s(&inputFile, inputName, "rb");
        errno_t err = fopen_s(&outputFile, outputName, "wt");



        //When the last stream of memory has been read from the file
        //set the lastRead flag to true to indicate a final read.
        while(!lastRead)
        {

            //Read up to 1024 bytes out of the input file stream
            numread = fread(msgBuffer, 1, BUFF_SIZE, inputFile);

            //0 items have been processed from the ring buffer
            //numread total items have been stored into the buffer
            read_Index = 0;
            write_Index = numread-1;
            sz = numread;



            //Edge case when end of file has been reached
            if (numread < BUFF_SIZE)
            {
                lastRead = true;
            }

            for (int k = 0; k < numread; ++k)
            {
                //If novatel sync found then set a pointer to the end of sync
                if(msgBuffer[k] == 0xAA && msgBuffer[k+1] == 0x44 && msgBuffer[k+2] == 0x12)//strncmp((msgBuffer+k), "AA 44 12", 3) == 0)
                {
                    printf("\n%.2X %.2X %.2X\n", msgBuffer[k], msgBuffer[k+1], msgBuffer[k+2]);

                    sync_ptr = (msgBuffer+k);
                    printf("\n\n%.2X ", *(sync_ptr));
                    printf("%.2X ", *(sync_ptr+1));
                    printf("%.2X ", *(sync_ptr+2));



                    printf("\n\n\n**********Found the nova sync message*********\n\n\n");
                    lastRead = true;
                    break;
                }
            }//for (int k = 0; k < numread; ++k)


        }//for (int i = 0; i < 9; ++i)

        //fprintf(outputFile, "%.2X", msgBuffer[numread-1]);

        fclose(inputFile);
        fclose(outputFile);
}

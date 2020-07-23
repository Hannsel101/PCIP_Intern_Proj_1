#include "messages.h"

#include <stdio.h>
#include <vector>
#include <iterator>

#define CRC32_POLYNOMIAL 0xEDB88320L

#define BUFF_SIZE 8192
#define CHUNK_SIZE (BUFF_SIZE/2)

#define RING_WRITE(idx, sz) {idx++; idx &= (unsigned int)(BUFF_SIZE-1); sz++;}
#define RING_READ(idx, sz) {idx++; idx &= (unsigned int)(BUFF_SIZE-1); sz--;}


messages::messages()
{
    utc_Offset = 0;
    gpsSats = 0;
}

messages::~messages()
{

}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
unsigned int RING_IDX(unsigned int idx)
{
    return idx & (unsigned int)(BUFF_SIZE-1);
}
/* --------------------------------------------------------------------------
Calculate a CRC value to be used by CRC calculation functions.
-------------------------------------------------------------------------- */
unsigned long CRC32Value(int i) {
    int j;
    unsigned long ulCRC;
    ulCRC = i;
    for ( j = 8 ; j > 0; j-- ) {
        if ( ulCRC & 1 )
            ulCRC = ( ulCRC >> 1 ) ^ CRC32_POLYNOMIAL;
        else
            ulCRC >>= 1;
    }
    return ulCRC;
}
/* --------------------------------------------------------------------------
Calculates the CRC-32 of a block of data all at once
ulCount - Number of bytes in the data block
ucBuffer - Data block
-------------------------------------------------------------------------- */
unsigned long CalculateBlockCRC32( unsigned long ulCount, unsigned char
                                   *ucBuffer, unsigned int startIdx ) {
    unsigned long ulTemp1;
    unsigned long ulTemp2;
    unsigned int t;
    unsigned char v;
    unsigned long ulCRC = 0;
    unsigned int endIdx = RING_IDX(startIdx + ulCount);
    //while ( ulCount-- != 0 ) {
    for(unsigned int currIdx = startIdx; currIdx != endIdx; ){
        t = RING_IDX(currIdx);
        v = ucBuffer[t];
        ulTemp1 = ( ulCRC >> 8 ) & 0x00FFFFFFL;
        ulTemp2 = CRC32Value( ((int) ulCRC ^ ucBuffer[t] ) & 0xFF );
        ulCRC = ulTemp1 ^ ulTemp2;
        RING_IDX(++currIdx);
    }
    return( ulCRC );
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void messages::readAndProcess(QString inputFileName,
                              QString outputFileName, QString logFileName)
{


        //File pointers for input and output files
        FILE* inputFile;
        FILE* outputFile;
        FILE* logFile;

        //File reading flags
        int numread;
        bool lastRead = false;
        bool DONE = false;

        //Ring buffer variables
        unsigned char msgBuffer[BUFF_SIZE];
        unsigned int read_Index=0;
        unsigned int write_Index=0;
        unsigned int sz = 0;

        memset(msgBuffer, 0, BUFF_SIZE);

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
        while(!DONE && !lastRead)
        {


            /*
             * READING PORTION
             * */
            //If space available for another read then read
            if(!lastRead && (sz < CHUNK_SIZE))
            {

                for(int k=0; k<CHUNK_SIZE; ++k)
                {
                    //Read up to 4096 bytes out of the input file stream
                    numread = fread(&msgBuffer[write_Index], 1, 1, inputFile);

                    //If no values were read
                    if(numread <1)
                    {
                        lastRead = true;
                        break;
                    }
                    else
                    {
                        RING_WRITE(write_Index, sz);
                    }
                }//for(int k=0; k<CHUNK_SIZE; ++k)
            }
            /*
             * READING DONE
             * */

            /*
             * PROCESSING LOOP
             * */
            if(!DONE)
            {

                //While there is still data to process
                while(read_Index != write_Index)
                {

                    //End condition
                    if(!checkIndexes(read_Index, write_Index, 3))
                        break;

                    if((msgBuffer[RING_IDX(read_Index)] != 0xAA) ||
                            (msgBuffer[RING_IDX(read_Index+1)] != 0x44) ||
                            (msgBuffer[RING_IDX(read_Index+2)] != 0x12))
                    {
                        //Advance the pointer by 1
                        RING_READ(read_Index, sz);                      
                        continue;
                    }
                    //Get sync position in buffer
                    unsigned int syncPos = read_Index;

                    int headerSize = sizeof(NovaHeader);
                    NovaHeader header;
                    unsigned char* ptr = (unsigned char*)&header;


                    if(!checkIndexes(read_Index, write_Index, headerSize))
                        break;


                    for(int i=0; i<headerSize; ++i)
                    {
                        *ptr = msgBuffer[RING_IDX(read_Index)];
                        ptr++;

                        RING_READ(read_Index, sz);
                    }//for(int i=0; i<headerSize; ++i)

                    /*
                     * CHECKSUM CHECKING
                     * */
                    //Check if there is enough space between read and write pointer for CRC check
                    if(!checkIndexes(read_Index, write_Index, header.Message_Length+4))
                    {
                        read_Index = syncPos;
                        break;
                    }


                    //Full size of message
                    unsigned int CRCsz = headerSize + header.Message_Length;
                    unsigned int msgCRC = (msgBuffer[RING_IDX(syncPos+CRCsz+3)] << 24) |
                            (msgBuffer[RING_IDX(syncPos+CRCsz+2)] << 16) |
                            (msgBuffer[RING_IDX(syncPos+CRCsz+1)] << 8) |
                            (msgBuffer[RING_IDX(syncPos+CRCsz)]);

                    unsigned int calcCRC = CalculateBlockCRC32(CRCsz, msgBuffer, syncPos);

                    //Error condition when CRC calculations do not match
                    if(calcCRC != msgCRC)
                    {
                        read_Index = syncPos+1;
                        continue;
                    }
                    /*
                     * CHECKSUM CHECKING END
                     * */

                    switch(header.Msg_ID)
                    {
                    case 43://RANGE
                    {
                        unsigned long numObs = msgBuffer[RING_IDX(read_Index+3)] << 24 |
                                               msgBuffer[RING_IDX(read_Index+2)] << 16 |
                                               msgBuffer[RING_IDX(read_Index+1)] << 8 |
                                               msgBuffer[RING_IDX(read_Index)];

                        //Increment the pointer pass number of observations
                        for(int i=0; i<4; ++i)
                            RING_READ(read_Index,sz);

                        gpsSats = 0;
                        std::vector<unsigned short> *foundSVIDs = new std::vector<unsigned short>();
                        for(int i=0; i<numObs; ++i)
                        {
                            RANGE rangeMSG;
                            ptr = (unsigned char*) &rangeMSG;

                            // Read an observation
                            for(int i=0; i<header.Message_Length; ++i)
                            {
                                *ptr = msgBuffer[RING_IDX(read_Index)];
                                ptr++;

                                RING_READ(read_Index, sz);
                            }//for(int i=0; i<headerSize; ++i)

                            //Process an observation
                            unsigned int chk = (rangeMSG.Ch_Tr_Status & 0x03E00000) >> 21;

                            switch(chk)//GPS Signals Observed
                            {
                            case 0://L1C/A
                            case 5://L2P
                            case 9://L2P(Y), semi-codeless
                            case 14://L5(Q)
                            case 16://L1C(P)
                            case 17://L2C(M)
                            {
                                bool found = false;
                                foundSVIDs->push_back(rangeMSG.PRN_Slot);
                                /*
                                //Search the list to see if SVID is already present
                                if(foundSVIDs.size() == 0)
                                    foundSVIDs.push_back(rangeMSG.PRN_Slot);
                                else
                                {
                                    for(std::vector<unsigned short>::iterator iter=foundSVIDs.begin(); iter < foundSVIDs.end(); iter++)
                                    {

                                        unsigned short val = (*iter);

                                        if(val == rangeMSG.PRN_Slot)
                                        {
                                            found = true;
                                            break;
                                        }
                                    }

                                 //If the SVID is not already in list then insert at the end
                                 if(!found)
                                 {
                                     foundSVIDs.push_back(rangeMSG.PRN_Slot);
                                 }
                                }*/
                                 break;
                            }
                            default:
                                break;
                            }

                            //Update the number of GPS satellites found
                            gpsSats = foundSVIDs->size();
                        }
                        delete foundSVIDs;
                        break;
                    }//case 43://RANGE
                    case 101://Time
                    {
                         TIME timeMSG;
                        ptr = (unsigned char*) &timeMSG;

                        for(int i=0; i<header.Message_Length; ++i)
                        {
                            *ptr = msgBuffer[RING_IDX(read_Index)];
                            ptr++;

                            RING_READ(read_Index, sz);
                        }//for(int i=0; i<headerSize; ++i)

                        utc_Offset = timeMSG.utc_offset;
                        break;
                    }//case 101://Time
                    case 241://BestXYZ
                    {
                        BestXYZ bestMSG;
                        ptr = (unsigned char*) &bestMSG;

                        for(int i=0; i<header.Message_Length; ++i)
                        {
                            *ptr = msgBuffer[RING_IDX(read_Index)];
                            ptr++;

                            RING_READ(read_Index, sz);
                        }//for(int i=0; i<headerSize; ++i)

                        printf("E: %.9f, F: %.9f, G: %.9f\n", bestMSG.PX, bestMSG.PY, bestMSG.PZ);
                        break;


                    }//case 241://BestXYZ
                    default://Message we dont need
                        for(int i=0; i<header.Message_Length; ++i)
                            RING_READ(read_Index, sz);
                    }//switch(header.Msg_ID)

                    for(int i=0; i<4; ++i)
                        RING_READ(read_Index, sz);

                }//while(read_Index != write_Index)
            }//if(!DONE)


        }//while(!DONE && !lastRead)




        fclose(inputFile);
        fclose(outputFile);
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool messages::checkIndexes(int read_Index,int write_Index, int count)
{
    for(int i=0; i<count; ++i)
    {
        if(RING_IDX(read_Index+i) == write_Index)
        {
            return false;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//

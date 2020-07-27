#include "GPS_Sensor.h"

GPS_Sensor::GPS_Sensor()
{
    EFEC_File = nullptr;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
GPS_Sensor::~GPS_Sensor()
{
    if(EFEC_File != nullptr)
    {
        EFEC_File->close();
    }
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
void GPS_Sensor::setPos(double E, double F, double G)
{
    antennaPos[0] = E;
    antennaPos[1] = F;
    antennaPos[2] = G;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
double GPS_Sensor::getPosE()
{
    return antennaPos[0];
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
double GPS_Sensor::getPosF()
{
    return antennaPos[1];
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
double GPS_Sensor::getPosG()
{
    return antennaPos[2];
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool GPS_Sensor::setFile(QString fileName)
{
    if(fileName.length() > 0)
    {
        EFEC_FileName = fileName;
        return true;
    }

    return false;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
bool GPS_Sensor::extractPos()
{

    //Open file containing antenna position coordinates
    EFEC_File = new QFile(EFEC_FileName);

    //Check that the file exists
    if(EFEC_File->exists())
    {
        //Check that file supports reading
        if(!EFEC_File->open(QIODevice::ReadOnly))
        {
            return false;
        }


        //Read in a single line from input file stream
        //Initialize variables to handle parsing the values out of the file
        QTextStream in(EFEC_File);
        debugString = in.readLine();
        return true;



    }
    return false;
}
//-----------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------//
QString GPS_Sensor::getDebug()
{
    return debugString;
}

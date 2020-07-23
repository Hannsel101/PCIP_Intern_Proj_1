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






/*if(singleLine.at(index) < 47 || singleLine.at(index) > 57)//if the current value is not 0-9 in ascii
{
    if(singleLine.at(index) != 46)//if the current value is not a decimal point in ascii
    {
        foundNumber = false;

        switch(numbersPulled)
        {
        case 0:
            antennaPos[0] = number.toDouble();
            break;
        case 1:
            antennaPos[1] = number.toDouble();
            break;
        case 2:
            antennaPos[2] = number.toDouble();
            break;
        default:
            return false;
            break;
        }

        numbersPulled++;
        number = "";
    }
    else
    {
        number.append(singleLine.at(index));
    }
}
else
{
    number.append(singleLine.at(index));
}*/

/*
QTextStream in(EFEC_File);
QString singleLine = in.readLine();

QString number = "";
int numbersPulled = 0;
int index = 0;
bool foundNumber = false;

while(numbersPulled < 3 || index == singleLine.length())
{
if(foundNumber)
{
if(singleLine.at(index) < 49 || singleLine.at(index) > 57)//if the current value is not 0-9 in ascii
{
if(singleLine.at(index) != 46)//if the current value is not a decimal point in ascii
{
    foundNumber = false;

    switch(numbersPulled)
    {
    case 0:
        antennaPos[0] = number.toDouble();
        break;
    case 1:
        antennaPos[1] = number.toDouble();
        break;
    case 2:
        antennaPos[2] = number.toDouble();
        break;
    default:
        qDebug("Error: incorrect number of antenna coordinates");
        break;
    }

    numbersPulled++;
    number = "";
}
else
{
    number.append(singleLine.at(index));
}
}
else
{
number.append(singleLine.at(index));
}
}
else if(singleLine.at(index) > 49 && singleLine.at(index) < 57)
{
//Set found number flag to true to indicate a number has been found
foundNumber = true;

//Store the most significant digit into number
number.append(singleLine.at(index));
}
index++;
}

if(numbersPulled == 3)
return true;

return false;
*/

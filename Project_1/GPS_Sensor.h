#ifndef GPS_SENSOR_H
#define GPS_SENSOR_H

#include <QFile>
#include <QTextStream>

class GPS_Sensor
{
public:
    GPS_Sensor();
    ~GPS_Sensor();
    void setPos(double E, double F, double G);
    /*
     * Setter function to set the (E,F,G) coordinates of the antennas
     * position.
     * */

    double getPosE();
    /*
     * Getter function to return the E position of an earth fixed earth
     * centered coordinate system.
     *
     * Returns a value of type double
     * */

    double getPosF();
    /*
     * Getter function to return the F position of an earth fixed earth
     * centered coordinate system.
     *
     * Returns a value of type double
     * */

    double getPosG();
    /*
     * Getter function to return the G position of an earth fixed earth
     * centered coordinate system.
     *
     * Returns a value of type double
     * */

    bool setFile(QString fileName);
    /*
     * sets the private data member EFEC_File to an input file
     * specified by the fileName input.
     *
     * Returns TRUE if file exists()
     * Returns FALSE otherwise
     * */

    bool extractPos();
    /*
     * Extract the position from an input file.
     * Returns TRUE if sucessfully finds three coordinates.
     * Returns FALSE if the format is not compatible
     * */

    QString getDebug();
    /*
     * Getter function to return the debugString for testing
     * purposes only
     * */

private:
    void parseFile(double EFG[]);
    /*
     * parses a txt file containing the reference antenna position in
     * EFEC(E, F, G) coordinates.
     *
     * EFG[] = an array passed by reference and returned with the extracted
     * E, F, and G coordinate values in meters.
     *
     * Expected File Format:
     * E, F, G
     * */

private:
    double antennaPos[3];
    QString EFEC_FileName;
    QFile *EFEC_File;
    QString debugString;
};

#endif // GPS_SENSOR_H

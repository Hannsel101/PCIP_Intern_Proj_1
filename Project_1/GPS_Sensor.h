#ifndef GPS_SENSOR_H
#define GPS_SENSOR_H

class GPS_Sensor
{
public:
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
private:
    double antennaPos[3];
};

#endif // GPS_SENSOR_H

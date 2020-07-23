#ifndef STRUCTS_H
#define STRUCTS_H


#pragma pack(1)
//Novatel Header structure
struct NovaHeader
{
    unsigned char Sync[3];
    unsigned char Header_Length;
    unsigned short Msg_ID;
    unsigned char Msg_Type;
    unsigned char Port_Address;
    unsigned short Message_Length;
    unsigned short Sequence;
    unsigned char Idle_Time;
    unsigned char Time_Status;
    unsigned short Week;
    unsigned int GPSec;//Possibly not right size
    unsigned long Receiver_Status;
    unsigned short Reserved;
    unsigned short Receiver_SW_Version;
    //string Response;
};

//Structure to handle the BestXYZ message formats
struct BestXYZ
{
    unsigned int Psol_Status;
    unsigned int Pos_Type;
    double PX;
    double PY;
    double PZ;
    float PX_sigma;
    float PY_sigma;
    float PZ_sigma;
    unsigned int Vsol_Status;
    unsigned int Vel_Type;
    double VX;
    double VY;
    double VZ;
    float VX_sigma;
    float VY_sigma;
    float VZ_sigma;
    char station_ID[4];
    float V_latency;
    float Diff_Age;
    float Sol_Age;
    unsigned char num_SVs;
    unsigned char num_Sol_In_SVs;
    unsigned char num_ggL1;
    unsigned char num_Sol_In_MultiSVs;
    unsigned char Reserved;
    unsigned char Ext_Sol_Stat;
    unsigned char Gal_And_Bei_Sig_Mask;
    unsigned char GPS_And_GLONASS_Sig_Mask;
    //[CR][LF] terminated message
};


//Structure to handle Range message formats
struct RANGE
{
    unsigned short PRN_Slot;
    unsigned short Glofreq;
    double Psr;
    float Psr_sigma;
    double Adr;
    float Adr_sigma;
    float Dopp;
    float Carrier_to_Noise;
    float Locktime;
    unsigned long Ch_Tr_Status;
    //[CR][LF] terminated message
};

struct TIME
{
    unsigned int clock_status;
    double offset;
    double offset_std;
    double utc_offset;
    unsigned long utc_year;
    unsigned char utc_month;
    unsigned char utc_day;
    unsigned char utc_hour;
    unsigned char utc_min;
    unsigned long utc_ms;
    unsigned int utc_status;
};
#pragma pack()

#endif // STRUCTS_H

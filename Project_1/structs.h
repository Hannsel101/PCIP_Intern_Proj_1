#ifndef STRUCTS_H
#define STRUCTS_H


#pragma pack(1)

//Novatel Header structure
struct NovaHeader
{
    unsigned char Sync[3];
    unsigned char Header_Length;
    unsigned short Msg_ID;
    char Msg_Type;
    unsigned char Port_Address;
    unsigned short Message_Length;
    unsigned short Sequence;
    unsigned char Idle_Time;
    unsigned char Time_Status;
    unsigned short Week;
    unsigned short GPSec;//Possibly not right size
    unsigned long Receiver_Status;
    unsigned short Reserved;
    unsigned short Receiver_SW_Version;
    unsigned short Response_ID;
    char Response[2];
    //string Response;
};

//Structure to handle the BestXYZ message formats
struct BestXYZ
{
    unsigned short Psol_Status;
    unsigned short Pos_Type;
    double PX;
    double PY;
    double PZ;
    float PX_sigma;
    float PY_sigma;
    float PZ_sigma;
    unsigned short Vsol_Status;
    unsigned short Vel_Type;
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
    char Reserved;
    char Ext_Sol_Stat;
    char Gal_And_Bei_Sig_Mask;
    char GPS_And_GLONASS_Sig_Mask;
    char CRC[4];
    //string Ext_Sol_Stat;
    //string Gal_And_Bei_Sig_Mask;
    //string GPS_And_GLONASS_Sig_Mask;
    //string CRC;
    //[CR][LF] terminated message
};


//Structure to handle Range message formats
struct RANGE
{
    unsigned long Num_Observations;
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
    unsigned long CRC;
    //[CR][LF] terminated message
};

#pragma pack()

#endif // STRUCTS_H

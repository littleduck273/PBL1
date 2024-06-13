#ifndef VEHICLE_H
#define VEHICLE_H

#include <time.h>
#include <cstring>

class Vehicle{
    private:
        char parkingID[100];
        char type[100];
        char license[100];
        char position[10];
        time_t createdAt;
    public: 
        void setVehicle(char parkingID[], char type[] ,char license[], char position[]);
        void setParkingID(char parkingID[]);
        void setType(char type[]);
        void setLicense(char license[]);
        char* getParkingID();
        char* getType();
        char* getLicense();
        char* getPosition();
        char* getStringCreatedAt();
        time_t* getTimeCreatedAt();
};

#endif
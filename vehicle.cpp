#include "vehicle.h"

void Vehicle::setVehicle(char parkingID[], char type[] ,char license[], char position[]) {
    strcpy(this->parkingID,parkingID);
    strcpy(this->type,type);
    strcpy(this->license,license);
    strcpy(this->position,position);
    this->createdAt = time(nullptr);
	// this->createdAt = localtime(&now);
	// strncpy(createdAt, ctime(&timeptr), 26);
	// assert("\n" == createdAt[strlen(createdAt)-1]);
	// this->createdAt->tm_mon ++;
	// this->createdAt->tm_year += 1900;
}

void Vehicle::setParkingID(char parkingID[]) {
    strcpy(this->parkingID,parkingID);
}
void Vehicle::setType(char type[]) {
    strcpy(this->type,type);
}
void Vehicle::setLicense(char license[]) {
    strcpy(this->license,license);
}

char* Vehicle::getParkingID() {
    return this->parkingID;
}

char* Vehicle::getType() {
    return this->type;
}

char* Vehicle::getLicense() {
    return this->license;
}

char* Vehicle::getPosition() {
    return this->position;
}

char* Vehicle::getStringCreatedAt() {
    return ctime(&(this->createdAt));
}

time_t* Vehicle::getTimeCreatedAt() {
    return &(this->createdAt);
}
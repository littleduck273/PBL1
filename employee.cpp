#include "employee.h"

void Employee::setEmployee(char username[], char password[]){
    strcpy(this->username, username);
    strcpy(this->password, password);
}

char* Employee::getUsername() {
    return this->username;
}

char* Employee::getPassword() {
    return this->password;
}
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<cstring>

class Employee{
    private:
        char username[50];
        char password[50];
    public:
        void setEmployee(char username[], char password[]);
        char* getUsername();
        char* getPassword();
};

#endif
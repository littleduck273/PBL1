#ifndef RUN_H
#define RUN_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "processor.h"
#include "vehicle.h"
#include "employee.h"

using namespace std;

#define USERNAME "ThienVO" 
#define PASSWORD "123Thien"
#define PRICEPERHOUR 2000

bool run();
short int isAdmin();
bool homePage();
bool adminPage();
void addEmployee();
void deleteEmployee();
void showAllEmployee();
void showMenu();
void dataEntry();
void dataDelete();
void dataSearch();
void printOut();
bool exitProgram();
bool logout();
#endif
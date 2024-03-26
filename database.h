#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
int numberOfCars;
typedef struct
{
    char *plate;
    char *model;
    char *color;
    char *ownerName;
    char *problems;
    char *repairStatus;
    int year;
    int parts_cost;
    int repair_price;
}car;
extern void ReadCar(car*);
extern void ReadNumberOfCars();
extern void SaveCarChange(car*);
extern void DeleteCarFromDB(car*,int);
extern void AddNewCar();
#endif // DATABASE_H_INCLUDED

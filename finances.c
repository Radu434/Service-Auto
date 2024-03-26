#include"finances.h"
#include"menu.h"
#include"database.h"
#include"cars.h"
void FinanceMenu()
{

    car *cars_ptrL;
    cars_ptrL=(car *)calloc(numberOfCars+1,sizeof(car));
    ReadNumberOfCars();
    ReadCar(cars_ptrL);//read all car data into a local car struct
    int totalProfit=0;
    float totalProfitAfterTax=0.00;
    int totalPartsCost=0;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    for(int i=0;i<=numberOfCars;i++)
    {
        totalProfit+=cars_ptrL[i].repair_price;//sum repair prices
        totalPartsCost+=cars_ptrL[i].parts_cost;//sum part prices
    }

    free(cars_ptrL);//free car struct
    totalProfitAfterTax=(float)totalProfit;//cast as float
    totalProfitAfterTax=totalProfitAfterTax-totalProfitAfterTax*0.3;//calc after tax as float

        system("cls");
        printf("Finances|| Press Anything to exit\n",totalProfit);
        printf("Total profit before taxes:.............................. %d\n",totalProfit);
        printf("Total profit after taxes:...............................%.2f\n",totalProfitAfterTax);
        printf("Total Part Cost:........................................%d\n",totalPartsCost);
        HighlightChoice(1,1);
        printf("<Back to Main>\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        if(_getch())//wait until any key is pressed
        {

        }


}

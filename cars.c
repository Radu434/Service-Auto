#include"cars.h"
#include"database.h"
#include"menu.h"
//V3.0
void DisplayCarList(int n)
{
    int choice=0;
    int key=0;
    int continueLoop=1;
    int pageMax=7;
    int pageMin=0;
    car *CarsList;
    ReadNumberOfCars();
    CarsList=(car *)calloc(numberOfCars+1,sizeof(car));
    ReadCar(CarsList);
    if(numberOfCars<8)
    {
        pageMax=numberOfCars;
    }


    while(continueLoop==1)
    {

        system("cls");
        if(key==UP_ARROW&&choice<numberOfCars)
        {
            choice++;
            if(choice>=8)
            {

                pageMax++;
                pageMin++;

            }





        }
        if(key==DOWN_ARROW&&choice>0)
        {
            choice--;

            if(pageMax>=8)
            {

                pageMax-=1;
                pageMin--;
            }

        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("Cars List|| Car Number #%d / %d ||Press ESC to go back to cars menu\n",choice+1,numberOfCars+1);
        printf("***************************************************************\n");
        for(int i=pageMin; i<=pageMax; i++)
        {


            HighlightChoice(choice,i);
            printf("%s -%s\n",CarsList[i].ownerName,CarsList[i].plate);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(i+1)%2+7);
            printf("***************************************************************\n");

        }
        key=_getch();
        if(key==ENTER_KEY)//enter key
        {
            DisplaySelectedCar(choice, CarsList);
            continueLoop=0;

        }
        if(key==ESC_KEY)
        {
            continueLoop=0;
            free(CarsList);
            MenuCarsLoop();

        }


    }

}
void DisplaySelectedCar(int n, car *cars_ptr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    char changeFieldBuffer[200]={'\0'};
    int choice=0;
    int key=0;
    int continueLoop=1;
    while(continueLoop==1)
    {
        system("cls");
        if(key==UP_ARROW&&choice<11)
        {
            choice++;
        }
        if(key==DOWN_ARROW&&choice>0)
        {
            choice--;
        }
        printf("Cars List|| Car Number #%d / %d Press ENTER to change data\n",n+1,numberOfCars+1);

        printf("Plate: ");
        HighlightChoice(choice,0);
        printf("%s\n",cars_ptr[n].plate);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Model: ");
        HighlightChoice(choice,1);
        printf("%s\n",cars_ptr[n].model);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Color: ");
        HighlightChoice(choice,2);
        printf("%s\n",cars_ptr[n].color);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Owner Name: ");
        HighlightChoice(choice,3);
        printf("%s\n",cars_ptr[n].ownerName);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Problems: ");
        HighlightChoice(choice,4);
        printf("%s\n",cars_ptr[n].problems);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Repair Status: ");
        HighlightChoice(choice,5);
        printf("%s\n",cars_ptr[n].repairStatus);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Fabrication Year: ");
        HighlightChoice(choice,6);
        printf("%d\n",cars_ptr[n].year);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Parts cost: ");
        HighlightChoice(choice,7);
        printf("%d\n",cars_ptr[n].parts_cost);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        printf("Repair Cost:  ");
        HighlightChoice(choice,8);
        printf("%d\n",cars_ptr[n].repair_price);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

        HighlightChoice(choice,9);
        printf("Save\n");
        HighlightChoice(choice,10);
        printf("DELETE\n");
        HighlightChoice(choice,11);
        printf("Back to Cars list\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        key=_getch();
        if(key==ENTER_KEY)//enter key
        {
            strcpy(changeFieldBuffer,"");
            switch(choice)
            {
            case 0:
            {
                system("cls");
                printf("Enter new Number Plate, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].plate=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                    strcpy(cars_ptr[n].plate,changeFieldBuffer);
                }
                else
                {
                    break;
                }


                // modify Number Plate
                break;
            }


            case 1:
            {
                system("cls");
                printf("Enter new model, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].model=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                    strcpy(cars_ptr[n].model,changeFieldBuffer);
                }
                else
                {
                    break;
                }


                // modify model
                break;
            }

            case 2:
            {
                system("cls");
                printf("Enter new color, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {

                    cars_ptr[n].color=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                    strcpy(cars_ptr[n].color,changeFieldBuffer);
                }
                else
                {
                    break;
                }
                //modify color
                break;
            }
            case 3:
            {
                system("cls");
                printf("Enter new owner name, or leave empty to abort: ");//scanf("%[^\n]s",changeFieldBuffer)!=NULL&&strcmp(changeFieldBuffer,"/")!=0&&strlen(changeFieldBuffer)<200
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {
                    if(changeFieldBuffer)
                    {
                        cars_ptr[n].ownerName=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                        strcpy(cars_ptr[n].ownerName,changeFieldBuffer);

                    }
                }
                else
                {
                    break;
                }

                // modify ownerName
                break;
            }

            case 4:
            {
                system("cls");
                printf("Enter Car Problems, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].problems=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                    strcpy(cars_ptr[n].problems,changeFieldBuffer);
                }
                else
                {
                    break;
                }


                // modify Problems
                break;
            }

            case 5:
            {
                system("cls");
                printf("Enter new Repair Status, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<200&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].repairStatus=(char*)calloc(strlen(changeFieldBuffer),sizeof(char));
                    strcpy(cars_ptr[n].repairStatus,changeFieldBuffer);
                }
                else
                {
                    break;
                }


                // modify Repair Status
                break;
            }

            case 6:
            {
                system("cls");
                printf("Enter new year, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<5&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].year=atoi(changeFieldBuffer);
                }
                else
                {
                    break;
                }
                // modify year
                break;
            }

            case 7:
            {
                system("cls");
                printf("Enter new parts cost, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<5&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].parts_cost=atoi(changeFieldBuffer);
                }
                else
                {
                    break;
                }
                // modify Parts Cost
                break;
            }

            case 8:
            {
                system("cls");
                printf("Enter new repair price, or leave empty to abort: ");
                if(gets(changeFieldBuffer)!=NULL&&strlen(changeFieldBuffer)<5&&strlen(changeFieldBuffer)>0)
                {
                    cars_ptr[n].repair_price=atoi(changeFieldBuffer);
                }
                else
                {
                    break;
                }
                break;
            }

            case 9:
            {
                free(changeFieldBuffer);
                SaveCarChange(cars_ptr);
                // save
                break;
            }
            case 10:
            {
                system("cls");
                printf("Are you sure you want to delete this car? Press ESC to abort or Enter to confirm ");
                if(_getch()==ESC_KEY)
                {
                    break;
                }
                if(_getch()==ENTER_KEY)
                {
                    DeleteCarFromDB(cars_ptr,n);

                    free(changeFieldBuffer);
                    continueLoop=0;
                    ReadNumberOfCars();
                    DisplayCarList(numberOfCars);

                }

                break;//Delete selected Car
            }
            case 11:
            {
                free(changeFieldBuffer);
                // go back
                continueLoop=0;
                ReadNumberOfCars();
                DisplayCarList(numberOfCars);
                break;
            }
            }


        }
    }
}


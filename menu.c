#include "menu.h"
#include "cars.h"
#include "database.h"
#include"finances.h"
void ReadSettings()
{
    //reads data from settings.txt
    int themeSettingsValue, startSettingsOnOff;
    FILE *f_ptr=fopen("settings.txt","r");//opens settings file
    fscanf(f_ptr,"%d%d",&themeSettingsValue, &startSettingsOnOff);//reads first 2 values from the settings file
    themeForeColor=themeSettingsValue;
    MenuStartSequeceOnOff=startSettingsOnOff;
    if(f_ptr==NULL||themeSettingsValue>NUMBER_OF_THEMES||themeSettingsValue<1||startSettingsOnOff>1||startSettingsOnOff<0)//in case the settings file is missing or the values are invalid
    {
        printf("\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
        printf("Settings File Missing or corrupted!\nApp returned to default state!");//print error message
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        f_ptr=fopen("settings.txt","w");//create new settings file in write mode
        fprintf(f_ptr,"%d %d",4, 0);//write default settings in the file
        themeForeColor=4;
        MenuStartSequeceOnOff=0;
        sleep(1);
        printf("\nPress anything to continue!");
        _getch();
    }
    fclose(f_ptr);

}
void WriteSettings()
{
    //saves settings in settings.txt
    FILE *f_ptr=fopen("settings.txt","w");
    fprintf(f_ptr,"%d %d",themeForeColor, MenuStartSequeceOnOff);
    fclose(f_ptr);
    printf("\nSAVED!");
    usleep(100000);
}
void MenuStartSequece()
{
    ReadSettings();
    for(int k=0; k<125; k++)
    {
        printf("\n");
    }
    for(int i=0; i<30; i++)
    {
        printf("           ");// prints empty spaces to make the start screen flow from bellow

        for(int j=0; j<100; j++)
        {

            if(j+i+19>=99||i+j-20<=i+i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),themeForeColor);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            }

            printf("*");

            if(i==10&&j==41)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),themeForeColor*16); // color text for | SERVICE AUTO |
                printf("| S");
                usleep(50000);
                printf("E");
                usleep(50000);
                printf("R");
                usleep(50000);
                printf("V");
                usleep(50000);
                printf("I");
                usleep(50000);
                printf("C");
                usleep(50000);
                printf("E ");
                usleep(50000);
                printf("A");
                usleep(50000);
                printf("U");
                usleep(50000);
                printf("T");
                usleep(50000);
                printf("O |");
                j=57;

            }
            if(i==11&&j==35)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),themeForeColor*16);
                printf("|Press anything to continue|");// displays colored text
                j=63;
            }

        }

        printf("\n");
        usleep(100000);



    }
    _getch();
    system("cls");
}
void HighlightChoice(int choice,int position )
{

    if(choice==position)//checks if the current choice matches the displayed row
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),themeForeColor*16);

    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    }
}
void MenuCarsLoop()
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    int choice=1;
    int key;
    int continueLoop=1;
    while(continueLoop)
    {
        system("cls");
        printf("Cars Menu\n\n");
        HighlightChoice(choice,1);
        printf("<Add car>\n");
        HighlightChoice(choice,2);
        printf("<Car List>\n");
        HighlightChoice(choice,3);
        printf("<Back to Main>\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        key=_getch();//listents for key strokes
        if(key==UP_ARROW&&choice<3)
        {
            choice++;
        }
        if(key==DOWN_ARROW&&choice>1)
        {
            choice--;
        }
        if(key==ENTER_KEY)//enter key pressed
        {
            switch(choice)
            {
            case 1:
            {
                AddNewCar();
                break;
            }
            case 2:
            {

                continueLoop=0;
                ReadNumberOfCars();
                DisplayCarList(numberOfCars);
                //choice 2
                break;
            }
            case 3:
            {
                continueLoop=0;
                MenuMainLoop();
                break;
            }

            }
        }

    }

}
void MenuSettingsLoop()
{
    char Theme[7][10]= {"","Blue","Green","Cyan","Red","Magenta","Brown"};
    char StartSequenceOnOff[2][3]= {"On","Off"};
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    int choice=1;
    int key;
    int continueLoop=1;
    int choiceHorizontal[2]= {themeForeColor,MenuStartSequeceOnOff};//declare vector that holds settings values until saved
    while(continueLoop)
    {
        system("cls");
        printf("Settings Menu\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("Theme: ");
        HighlightChoice(choice,1);
        printf("<%s>\n", Theme[themeForeColor]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        printf("Start Sequence: ");
        HighlightChoice(choice,2);
        printf("<%s>\n\n",StartSequenceOnOff[MenuStartSequeceOnOff]);

        HighlightChoice(choice,3);
        printf("<Save>\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        HighlightChoice(choice,4);
        printf("<Back to Main>\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        key=_getch();
        if(key==UP_ARROW&&choice<4)//up arrow
        {
            choice++;
        }
        if(key==DOWN_ARROW&&choice>1)//down arrow
        {
            choice--;
        }
        if(key==RIGHT_ARROW)//right arrow
        {
            switch(choice)
            {
            case 1:
            {
                if(choiceHorizontal[0]<6)
                {
                    choiceHorizontal[0]++;
                    themeForeColor=choiceHorizontal[0];// change color scheme

                }
                break;
            }
            case 2:
            {
                if(choiceHorizontal[1]==0)
                {
                    choiceHorizontal[1]=1;// turn the intro sequence on
                    MenuStartSequeceOnOff=choiceHorizontal[1];

                }
                break;
            }
            }
        }
        if(key==LEFT_ARROW)//left arrow
        {
            switch(choice)
            {
            case 1:
            {
                if(choiceHorizontal[0]>1)
                {
                    choiceHorizontal[0]--;
                    themeForeColor=choiceHorizontal[0];

                }
                break;
            }
            case 2:
            {
                if(choiceHorizontal[1]==1)
                {
                    choiceHorizontal[1]=0;
                    MenuStartSequeceOnOff=choiceHorizontal[1];

                }
                break;
            }
            }
        }
        if(key==ENTER_KEY)
        {
            switch(choice)
            {
            case 1:
            {
                //choice 1
                break;
            }
            case 2:
            {
                //choice 2
                break;
            }
            case 3:
            {
                WriteSettings();
                break;
            }
            case 4:
            {

                continueLoop=0;
                MenuMainLoop();
                break;
            }

            }
        }

    }
}
void MenuMainLoop()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    int choice=1;
    int key;
    int continueLoop=1;
    while(continueLoop)
    {
        system("cls");
        printf("Main Menu\n\n");
        HighlightChoice(choice,1);
        printf("<Cars>\n");
        HighlightChoice(choice,2);
        printf("<Finances>\n");
        HighlightChoice(choice,3);
        printf("<Settings>\n");
        HighlightChoice(choice,4);
        printf("<Exit>\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        key=_getch();//listen for key press
        if(key==UP_ARROW&&choice<4)
        {
            choice++;
        }
        if(key==DOWN_ARROW&&choice>1)
        {
            choice--;
        }
        if(key==ENTER_KEY)
        {
            switch(choice)
            {
            case 1:
            {
                //choice 1
                continueLoop=0;
                 ReadNumberOfCars();
                MenuCarsLoop(numberOfCars);//open cars submenu
                break;
            }
            case 2:
            {
                FinanceMenu();
                //finances submenu;
                break;
            }
            case 3:
            {
                continueLoop=0;
                MenuSettingsLoop();//open settings submenu
                break;
                //choice 5
            }
            case 4:
            {
                //choice 4
                continueLoop=0;//stop loop
                break;

            }
            }
        }

    }
}


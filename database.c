#include"database.h"
#include"menu.h"
/*void ReadNumberOfCars()
{
    FILE *f_ptr=fopen("carsDB.txt","r");

    fscanf(f_ptr,"%d",&numberOfCars);
    fclose(f_ptr);
}*/
void ReadNumberOfCars()
{
    FILE *f_ptr;
    if(f_ptr=fopen("carsDB.txt","r"))
    {

        fscanf(f_ptr,"%d",&numberOfCars);
            fclose(f_ptr);
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4*16);
        printf("CarsDB file missing, created a blank one");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        sleep(1);
       f_ptr=fopen("carsDB.txt","w");
       fprintf(f_ptr,"%d\n",-1);
       numberOfCars=-1;
      fclose(f_ptr);
    }
}
void ReadCar(car *cars_ptr)
{
    //ReadNumberOfCars();
    FILE *f_ptr=fopen("carsDB.txt","r");
    char ReadBuffer[200]= {'\0'};
    fgets(ReadBuffer,200,f_ptr);
    for(int i=0; i<=numberOfCars; i++)
    {

        if(fgets(ReadBuffer,200,f_ptr))
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].plate=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].plate,ReadBuffer);
        }
        //printf("%s",ReadBuffer);

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].model=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].model,ReadBuffer);
        }
        //printf("%s",ReadBuffer);

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].color=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].color,ReadBuffer);
        }
        //printf("%s",ReadBuffer);

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].ownerName=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].ownerName,ReadBuffer);
        }
        //printf("%s",ReadBuffer);

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].problems=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].problems,ReadBuffer);
        }
        //printf("%s",ReadBuffer);

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            ReadBuffer[strcspn(ReadBuffer,"\n")]='\0';
            cars_ptr[i].repairStatus=(char*)calloc(strlen(ReadBuffer)+1,sizeof(char));
            strcpy(cars_ptr[i].repairStatus,ReadBuffer);
        }

        if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            //cars_ptr[i].year=(int*)malloc(sizeof(int));
            cars_ptr[i].year=atoi(ReadBuffer);
        }
         if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            //cars_ptr[i].parts_cost=(int*)malloc(sizeof(int));
            cars_ptr[i].parts_cost=atoi(ReadBuffer);
        }
         if(fgets(ReadBuffer,200,f_ptr)!=NULL)
        {
            //cars_ptr[i].repair_price=(int*)malloc(sizeof(int));
            cars_ptr[i].repair_price=atoi(ReadBuffer);
        }
        //printf("%s",ReadBuffer);


    }
    fclose(f_ptr);
}

void SaveCarChange(car *cars_ptr)
{
    FILE *file_ptr=fopen("carsDB.txt","w");
    fprintf(file_ptr,"%d\n",numberOfCars);

    for(int i=0; i<=numberOfCars; i++)
    {
        fprintf(file_ptr,"%s\n",cars_ptr[i].plate);
        fprintf(file_ptr,"%s\n",cars_ptr[i].model);
        fprintf(file_ptr,"%s\n",cars_ptr[i].color);
        fprintf(file_ptr,"%s\n",cars_ptr[i].ownerName);
        fprintf(file_ptr,"%s\n",cars_ptr[i].problems);
        fprintf(file_ptr,"%s\n",cars_ptr[i].repairStatus);
        fprintf(file_ptr,"%d\n",cars_ptr[i].year);
        fprintf(file_ptr,"%d\n",cars_ptr[i].parts_cost);
        fprintf(file_ptr,"%d\n",cars_ptr[i].repair_price);

    }
    fclose(file_ptr);
    printf("\nSAVED!");
    sleep(1);
}
void DeleteCarFromDB(car *cars_ptr,int CarToDelete)
{
    FILE *file_ptr=fopen("CarsDBTEMP.txt","w");

    fprintf(file_ptr,"%d\n",numberOfCars-1);

    for(int i=0; i<=numberOfCars; i++)
    {
        if(i!=CarToDelete)
        {
            fprintf(file_ptr,"%s\n",cars_ptr[i].plate);
            fprintf(file_ptr,"%s\n",cars_ptr[i].model);
            fprintf(file_ptr,"%s\n",cars_ptr[i].color);
            fprintf(file_ptr,"%s\n",cars_ptr[i].ownerName);
            fprintf(file_ptr,"%s\n",cars_ptr[i].problems);
            fprintf(file_ptr,"%s\n",cars_ptr[i].repairStatus);
            fprintf(file_ptr,"%d\n",cars_ptr[i].year);
            fprintf(file_ptr,"%d\n",cars_ptr[i].parts_cost);
            fprintf(file_ptr,"%d\n",cars_ptr[i].repair_price);
        }
    }
    fclose(file_ptr);
    remove("CarsDB-BeforeDeletion.txt");
    rename("CarsDB.txt","CarsDB-BeforeDeletion.txt");
    rename("CarsDBTEMP.txt","CarsDB.txt");


    printf("\nCar Deleted!");
    sleep(1);

}
void AddNewCar()
{
    // numberOfCars+=1;
    car *cars_ptrL;
    cars_ptrL=(car *)calloc(numberOfCars+1,sizeof(car));
    ReadNumberOfCars();
    ReadCar(cars_ptrL);
    char ReadBuffer[200]= {'\0'};
    remove("CarsDBTEMP.txt");
    FILE *f_ptr=fopen("carsDBTEMP.txt","a");
    fprintf(f_ptr,"%d\n",numberOfCars+1);
    for(int i=0; i<=numberOfCars; i++)
    {
        fprintf(f_ptr,"%s\n",cars_ptrL[i].plate);
        fprintf(f_ptr,"%s\n",cars_ptrL[i].model);
        fprintf(f_ptr,"%s\n",cars_ptrL[i].color);
        fprintf(f_ptr,"%s\n",cars_ptrL[i].ownerName);
        fprintf(f_ptr,"%s\n",cars_ptrL[i].problems);
        fprintf(f_ptr,"%s\n",cars_ptrL[i].repairStatus);
        fprintf(f_ptr,"%d\n",cars_ptrL[i].year);
        fprintf(f_ptr,"%d\n",cars_ptrL[i].parts_cost);
        fprintf(f_ptr,"%d\n",cars_ptrL[i].repair_price);

    }
    printf("\nEnter Car Number Plate: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Car Model: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Car Color: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Car Owner Name: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Car Problems: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);


    printf("\nEnter Repair status: ");
    // scanf("%s",ReadBuffer);
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Car Fabrication Year: ");
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Parts Cost: ");
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    printf("\nEnter Repair Price: ");
    gets(ReadBuffer);
    fprintf(f_ptr,"%s\n",ReadBuffer);

    fclose(f_ptr);
    free(ReadBuffer);
    free(cars_ptrL);
    printf("Press Enter to confirm: ");
    if(_getch()==ENTER_KEY)
    {
    remove("CarsDB.txt");
    rename("CarsDBTEMP.txt","CarsDB.txt");
    }
}


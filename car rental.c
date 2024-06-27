#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
struct inventory
{
	char brand[15][20];
	char model[15][20];
	int year, price;
};

struct booking
{
	char name[15];
	char date[10];
	int days;
};

void Add_Inventory();
void Delete_All_Inventory();
void Booking();
void Browse_Inventory();
void All_Transactions();
void Clear_Transactions();

void Add_Inventory()
{
	char temp2,password[]="fastrental3602",p[100];
    int l, choice, i, entries, x;
    FILE *fp;
    struct inventory cars[20];
    printf("Welcome Dear Admin!\nIf you wish to proceed press 1\nIf you wish to go back press 2\n");
    scanf("%d", &choice);
    switch(choice)
    {
    	case 1:
    {
    			login:
        {
            l=0;
            printf("\nEnter Password:\n");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                 continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                    
                }
            }
            
            if(strcmp(p,password)==0)
            {
                system("cls");
                printf("Password matched...\n");
				printf("\nEnter N.o of Cars to Add: ");
				fflush(stdin);
                scanf("%d", &entries);
                for(i=0; i<entries; i++)
                {
                	printf("Enter Car No.%d Brand:", (i+1));
                    scanf("%s", &cars[i].brand);
                    printf("Enter Car No.%d Model Name:", (i+1));
                    fflush(stdin);
                    scanf("%s", &cars[i].model);
                    printf("Enter Car No.%d Model Year:", (i+1));
                    fflush(stdin);
                    scanf("%d", &cars[i].year);
                    printf("Enter Car No.%d Daily Rent:", (i+1));
                    fflush(stdin);
                    scanf("%d",&cars[i].price);
                    fp=fopen("data.txt","a");
                if(fp==NULL)
                {
                    printf("File not Found");
                }
                else
                {
                	
                    fprintf(fp,"%s\n%s\n%d\n%d\n",cars[i].brand, cars[i].model, cars[i].year, cars[i].price);
                    printf("\nAdding Inventory\nPlease wait");
                    Sleep(500);
                    printf(".");
                    Sleep(500);
                    printf(".");
                    Sleep(500);
                    printf(".");
                    Sleep(500);
                    printf("\nInventory Sucessfully Added...\n");
                }
                printf("\n");
                fclose(fp);
				}
				system("cls");
				printf("All Inventory's have Successfully Been Stored!!!\n\n");
			}
            else 
            {
            	printf("\nInvalid Password Entered!\n");
            	goto login;
			}
        }
		}
		break;
        case 2:
        	{
                printf("\nOperation Cancelled!!\nRedirecting to Dashboard");
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                Sleep(500);
                printf(".");
                system("cls");
                main();
            }
            break;
	}
}
void Delete_All_Inventory()
{
	int l;
	FILE *fp;
	char temp2, password[]="fastrental3602", p[100];
	login:
		{
			 l=0;
            printf("\nEnter Password:");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                    break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                 continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                }
			}
			 if(strcmp(p,password)==0)
            {
                printf("\nPassword matched...\n");
                fp = fopen("data.txt","w");
                if(fp == NULL)
                {
                    printf("file does not found!");
                    exit(1);
                }
                else
                {
                    printf("\nDeleting Inventory\nPlease Wait");
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf("\nInventory Deleted Successfully!!!\n\n");
                    printf("Redirecting to Dashboard!!!");
                    printf(".");
                    Sleep(500);
                    printf(".");
                    Sleep(500);
                    printf(".");
                    Sleep(500);
                    printf(".");
                    system("cls");
                    main();    
				}
                fclose(fp);
            }
            else
            goto login;
        }
}
void Booking()
{
	struct inventory cars[20];
	struct booking bookings[20]; 
	FILE *fp;
	FILE *ufp;
	int total_amount,i,j,k,days;
    long long int mobile;
    char name1[15],name2[15];
    char ch,choice,ch1;
    fp=fopen("data.txt","r");
    if(fp==NULL)
    {
        printf("File Not Found!");
        exit(1);
    }
    else if(ch=fgetc(fp)==EOF)
    {
        printf("\nWe Apologize for the Inconvenice:(\nNo Cars are Available Right Now!!!");
        main();
    }
    else if((ch=fgetc(fp))!=EOF);
    {
    	{
        system("cls");
            fp=fopen("data.txt","r");
        	fscanf(fp,"%s\n%s\n%d\n%d\n", &cars[i].brand, &cars[i].model, &cars[i].year, &cars[i].price);
            printf("\n================ Inventory =====================");
            printf("\nCar Brand: %s", cars[i].brand);
            printf("\nCar Model: %s", cars[i].model);
            printf("\nModel Year: %d", cars[i].year);
            printf("\nRent per Day: %d Rs.", cars[i].price);
            printf("\n================================================\n");
        }
    choose:
    {
        fp=fopen("data.txt","r");
        fscanf(fp,"%s\n%s\n%d\n%d\n", &cars[i].brand, &cars[i].model, &cars[i].year, &cars[i].price);
        fclose(fp);
        printf("\nDo you want to Book a Car?(y/n)\n");
        scanf("%s",&choice);
        if((choice=='y')||(choice=='Y'))
        {
            printf("\n***Fill Your Details***");
            name:
                printf("\nEnter your Full Name:");
                scanf("%s %s",name1,name2);
            next:
                mobile=0;
                printf("\nEnter mobile number :");
                scanf("%lld",&mobile);
                goto day;
            day: 
               days=0;
               printf("\nEnter the Number of Days you want to Book For: ");
               scanf("%d", &days);
               goto booking;
            booking:
            {
                total_amount= cars[i].price * days;
                printf("\nCar Booked Successfully!!!\n*** ENJOY YOUR RENTAL ***\nGenerating Bill");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf("\n\t\t*** Bill ***");
                printf("\n========================================================");
                printf("\n\t\tName: %s %s", name1, name2);
                printf("\n\t\tMobile Number: %lld", mobile);
                printf("\n\t\tCar Brand & Model: %s %s", cars[i].brand, cars[i].model);
                printf("\n\t\tRent per Day: %d", cars[i].price);
                printf("\n\t\tTotal Amount : %d Rs.",total_amount);
                printf("\n========================================================");

                printf("\n\nThank You! Visit again!!!\n\n");
                Sleep(2000);
                ufp=fopen("OldTransaction.txt","a");
                if(ufp == NULL)
                {
                    printf("File not Found!");
                }
                else
                {
                    fprintf(ufp,"%s %s %lld %s %s %d %d\n", name1, name2, mobile, cars[i].brand, cars[i].model, cars[i].price, total_amount);                }
                printf("\n");
                fclose(ufp);
                ufp=fopen("data.txt","w");
                 fscanf(fp,"%s  %s  %d  %d  %d", &cars[i].brand, &cars[i].model, &cars[i].year, &cars[i].price, days);
                //fclose(fp);
                fclose(ufp);
            }
        }
        else if((choice=='n')||(choice=='N'))
        {
            printf(" ***************We Hope You Visit Soon**************\n");
            printf("***************Redirecting to Dashboard***************");
            printf(".");
            Sleep(750);
            printf(".");
            Sleep(750);
            printf(".");
            Sleep(750);
            system("cls");
            main();
        }
        else
        {
            printf("\nWrong Choice!!!");
            goto choose;
        }
    }
}
}
void Browse_Inventory()
{
	int i;
	struct inventory cars[20];
	int entry;
	char ch;
	FILE *fp;
    fp = fopen("data.txt","r");
    if(fp == NULL)
    {
        printf("File Not Found!");
        exit(1);
    }
    else
    {
        system("cls");
        if((ch=fgetc(fp))!=EOF)
        {
            fp=fopen("data.txt","r");
        	fscanf(fp,"%s\n%s\n%d\n%d\n", &cars[i].brand, &cars[i].model, &cars[i].year, &cars[i].price);
            printf("\n================ Inventory =====================");
            printf("\nCar Brand: %s", cars[i].brand);
            printf("\nCar Model: %s", cars[i].model);
            printf("\nModel Year: %d", cars[i].year);
            printf("\nRent per Day: %d Rs.", cars[i].price);
            printf("\n================================================\n");
        }
            Sleep(2000);
            dashboard:
            printf("\nEnter '1' to go back to Dashboard: ");
            scanf("%d", &entry);
            if(entry==1)
            {
            	fclose(fp);
            	system("cls");
                main();
			}
			else
			{
				printf("Input Error! Try Again\n");
				goto dashboard;
			}
        }
    fclose(fp);
}
void All_Transactions()
{
	char temp2,ch,password[]="fastrentals3602",p[100],p2[100];
    int l;
    FILE *fp;
    //system("clear");
    fp = fopen("AllTransaction.txt","r");
    if(fp == NULL)
    {
        printf("File Not Found!");
        exit(1);
    }
    else
    {
        system("cls");
        login:
        {
            l=0;
            printf("\nEnter Password:");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                 continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                }
            }
            //scanf("%s",&p);
            if(strcmp(p,password)==0)
            {
                system("cls");
                printf("\nPassword matched...\nFetching All Transactions");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf(".");
                Sleep(1000);
                printf("\n\n\t***Old Car Booking Records***");
                printf("\n===============================================");
                printf("\nName  Mobile  Brand  Model  Days  Rent/day  Bill");
                printf("\n================================================\n");
                while( ( ch = fgetc(fp))!=EOF)
                printf("%c",ch);
                  printf("===============================================\n\n");
            }
            else
            {
                printf("\nInvalid Password!!!");
                goto login;
            }
        }
    }
    fclose(fp);
}
void Clear_Transactions()
{
    int l;
    FILE *fp;
    char temp2,password[]="fastrental3602",p[100];
        login:
        {
            l=0;
            printf("\nEnter Password:");
            while(1)
            {
                temp2=getch();
                if(temp2=='\r')
                {
                    p[l]='\0';
                break;
                }
                else if(temp2=='\b')
                {
                    if(l>0)
                    {
                        l--;
                        printf("\b \b");
                    }
                }
                else if(temp2=='\t'||temp2==' ')
                {
                 continue;
                }
                else
                {
                    p[l]=temp2;
                    l++;
                    printf("*");
                }
            }
            //scanf("%s",&p);
            if(strcmp(p,password)==0)
            {
                printf("\nPassword matched...");
                fp = fopen("OldTransaction.txt","w");
                if(fp == NULL)
                {
                    printf("File Not found!");
                    exit(1);
                }
                else
                {
                    printf("\nDeleting All transactions");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf(".");
                    Sleep(1000);
                    printf("\nAll Transactions Deleted Successfully!!!\n");
                    Sleep(2000);
                    main();
                }
            }
            else
            {
            	printf("\nInvalid Password Entered!\n");
            	goto login;
			}
        }
    fclose(fp);
}
int main()
{
	int ch;
	do
	 {
		printf("|--------------------------------------------------------------------|\n");
		printf("|                     WELCOME TO FAST CAR RENTALS                    |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [1] To Book A Car                                   |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [2] To View Our Inventory                           |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [3] To Add to Existing Inventory                    |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [4] To Delete from Existing Inventory               |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [5] To View All Transactions                        |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [6] To Clear All Transactions                       |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("|          Press [7] Exit                                            |\n");
		printf("|--------------------------------------------------------------------|\n");
		printf("\n\nChoose Your Desired Selection : ");
		scanf("%d", &ch);
		switch (ch)
		{
		   	case 1 :
				{
					Booking();
					break;
				}
		    case 2 :
				{
					Browse_Inventory();
					break;
				}
			case 3 :
				{
					Add_Inventory();
					break;
				}
			case 4 :
				{
					Delete_All_Inventory();
					break;
				}
			case 5 :
				{
					All_Transactions();
					break;
				}
			case 6 :
				{
					Clear_Transactions();
					break;
				}
			case 7 :
				{
					printf("\n------------We Hope You Visit Soon!!!----------\n\n");
					exit(0);
				}
			default:
				printf("\nInvalid Input...\nTry Again!!!");
				break;
		}		
    }
    while(ch!=7);
}





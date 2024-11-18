#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <string.h>
#include<time.h>
#define MIN_CREDIT_SCORE 600  // Minimum credit score for loan eligibility
#define MAX_LOAN_AMOUNT 10000  // Maximum loan amount

int i,j;
int exit_func,exit_func2,acc;
void menu();

struct date
{
    int month,day,year;

    };

struct
{

    char name[60];
    int acc_no,age;
    char address[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,update,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
//Function to add some delay to the code to give it a realistic feel.
void delay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//Function to create a new account
void new_acc()
{
    int choice;
    FILE *ptr;
    int acc_no=6387257608;
    account_no:
    ptr=fopen("record.dat","a+");
    //The goto statement allows us to transfer control of the program to the specified label.


    system("cls");
    printf("\t\t\t\||===================================||\n");
    printf("\t\t\t\||           ADD RECORD              ||\n");
    printf("\t\t\t\||===================================||\n");
    printf("\n\n\nEnter today's date(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.deposit.day,&add.deposit.month,&add.deposit.year);

  /* Seed the random number generator with the current time
  srand(time(0));

  // Generate a random 16-digit number
  long long int number = rand();
  number = number * 1000 + rand();
  number = number * 10000 + rand();
  number = number * 10000 + rand();

  // Print the number with dashes between each group of 4 digits
  printf("Account number is : %04lld-%04lld-%04lld-%04lld\n",
         number / 10000 / 10000 / 10000,
         number / 10000 / 10000 % 10000,
         number / 10000 % 10000,
         number % 10000);*/

    printf("\nEnter the account number (10 digits):");
    scanf("%d",&check.acc_no);


    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.day,
                 &add.dob.month,&add.dob.year,&add.age,add.address,add.aadhar,&add.phone,add.acc_type,
                 &add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {
                    printf("\nAccount no. already in use!");
                    invalid_choice:
                    printf("\nEnter 0 to try again,1 to go to main menu, 2 to exit");
                    scanf("%d",&exit_func2);
                    if (exit_func2==0)
                    {
                       goto account_no;
                    }
                    else if (exit_func2==1)
                    {
                        menu();
                    }
                    else if (exit_func2==2)
                    {
                        close();
                    }
                    else
                    {
                    printf("\nInvalid!");
                    goto invalid_choice;
                    }

            }
    }

    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(dd/mm/yyyy):");
    scanf("%d/%d/%d",&add.dob.day,&add.dob.month,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the aadhar number:");
    scanf("%s",add.aadhar);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:Rs");
    scanf("%f",&add.amt);
    /*Difference between savings and current account:A savings account is most suitable for people who are salaried
    employees or have a monthly income, whereas, Current Accounts work best for traders and entrepreneurs who need
    to access their accounts frequently.
    Savings accounts earn interest at a rate of around 4%, while there is no such earning from a Current Account.*/
    acc_type:
    printf("\nType of account:\n");
    printf("\n\t Enter [1] for Savings Account");
    printf("\n\t Enter [2] for Current Account");
    printf("\n\t Enter [3] for Fixed(for 1 year) ");
    printf("\n\t Enter [4] for Fixed (for 2 year)");
    printf("\n\t Enter [5] for Fixed(for 3 year) ");
    printf("\nYour Choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                strcpy(add.acc_type,"Savings");
                break;
        case 2:
                strcpy(add.acc_type,"Current");
                break;
        case 3:
                strcpy(add.acc_type,"Fixed1");
                break;
        case 4:
                strcpy(add.acc_type,"Fixed2");
                break;
        case 5:
               strcpy(add.acc_type,"Fixed3");
                break;
        default:
                Invalid_choice:
                printf("\nInvalid Choice!!");
                printf("\nEnter 0 to try again , 1 to go to main menu and 2 to exit: ");
                scanf("%d",&exit_func);
                if(exit_func==0)
                {
                    goto acc_type;
                }
                else if(exit_func==1)
                {
                    menu();
                }
                else if(exit_func==2)
                {
                    close();
                }
                else
                {
                    goto Invalid_choice;
                }

                break;
    }

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,
                add.dob.day,add.dob.month,add.dob.year,add.age,add.address,add.aadhar
                ,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&exit_func);
    system("cls");

    if (exit_func==1)
    {
        menu();
    }

    else if(exit_func==0)
            {
                close();
            }

    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

//Function to view the present data

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("NAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,
                 add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,
                 add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,
                 &add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%10s\t\t%10s\t\t%.0lf",add.name,add.address,add.phone);
           test++;
       }

    fclose(view);

    if (test==0)
        {   system("cls");
            printf("\t\t\t\||===================================||\n");
            printf("\t\t\t\||           NO RECORD FOUND         ||\n");
            printf("\t\t\t\||===================================||\n");
        }

            view_list_invalid:
            printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&exit_func);
            system("cls");
            if (exit_func==1)
            {
            menu();
            }
            else if(exit_func==0)
            {
                close();
            }
            else
            {
                printf("\nInvalid!\a");
                goto view_list_invalid;
            }
}

void balance_list()

{
    int flag=0;
   FILE *check;
   check=fopen("record.dat","r");
    printf("\nEnter the account no.:");
    scanf("%d",&acc);

   while(fscanf(check,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,
                 add.name,&add.dob.day,&add.dob.month,&add.dob.year,&add.age,
                 add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,
                 &add.deposit.day,&add.deposit.year)!=EOF)
                 {

                     if(add.acc_no==acc)
                     {
                         printf("\nCurrent Balance : %f",add.amt);
                         flag++;
                     }

                 }
                 fclose(check);
                 if(flag==0)
                 {
                    printf("Account Number is Invalid");
                    checkbal_invalid:
                    printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                    scanf("%d",&exit_func);
                    system("cls");
                    if (exit_func==0)
                    {
                        balance_list();
                    }
                    else if (exit_func==1)
                    {
                                menu();
                    }
                    else if (exit_func==2)
                    {
                        close();
                    }
                    else
                    {
                    printf("\nInvalid!");
                    goto checkbal_invalid;
                    }
                 }
                 else
                    {
                        printf("\nEnter 1 to go to the main menu and 0 to exit:");
                        scanf("%d",&exit_func);
                        system("cls");
                        if (exit_func==1)
                        {
                            menu();
                        }
                        else
                        {
                            close();
                        }
                    }

}


//Function to update some information of the account

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&update.acc_no);

    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,
                 &add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,
                 &add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==update.acc_no)
        {   test=1;
            inf_change:
            printf("\nWhich information do you want to change?");
            printf("\nEnter [1] to change Address");
            printf("\nEnter [2] to change Phone number");
            printf("\nEnter [3] to change Aadhar Number");
            printf("\nEnter [4] to change Date of Birth");
            printf("\nEnter your choice:");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {
                    printf("Enter the new address:");
                    scanf("%s",update.address);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,
                        add.name,add.dob.month,add.dob.day,add.dob.year,add.age,update.address,
                        add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%lf",&update.phone);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                        add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,
                        add.age,add.address,add.aadhar,update.phone,add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                 else if(choice==3)
                {
                    printf("Enter the  new Aadhar number:");
                    scanf("%lf",&update.aadhar);
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                        add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,
                        add.age,add.address,update.aadhar,add.phone,add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                 else if(choice==4)
                {
                    printf("\nEnter the date of birth(dd/mm/yyyy):");
                    scanf("%d/%d/%d",&update.dob.day,&update.dob.month,&update.dob.year);
                    printf("\nEnter correct age:");
                    scanf("%d",&update.age);

                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                        add.acc_no,add.name,update.dob.month,update.dob.day,update.dob.year,
                        update.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("Changes saved!");
                }
                else
                {
                    invalid:
                    printf("\nInvalid Choice!!");
                    printf("\nEnter 0 to try again, 1 to go to main menu and 2 to exit:");
                    scanf("%d",&exit_func2);
                    if(exit_func2==0)
                    {
                        goto inf_change;
                    }
                    else if (exit_func2==1)
                    {
                        menu();
                    }
                    else if(exit_func2==2)
                    {
                        close();
                    }
                    else
                    {
                        goto invalid;
                    }

                }



        }
        else
        {

            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,
                    add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
                    add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_func);
              system("cls");
                 if (exit_func==1)
                   {
                       menu();
                   }
                else if (exit_func==2)
                    {
                        close();
                    }
                else if(exit_func==0)
                    {
                        edit();
                    }
                else
                    {
                        printf("\nInvalid!\a");
                    goto edit_invalid;
                    }
        }
    else
        {
            invalid_option:
            printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_func);
        system("cls");
        if (exit_func==1)
            {
                menu();
            }
        else if(exit_func==0)
            {
                close();
            }
            else
            {
                printf("Invalid choice!!");
                delay(1000000000);
                goto invalid_option;
            }
         }
}

//Function to do some basic transactions

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,
                  add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,
                  add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\t\t\t||==================================================================||\n");
                    printf("\t\t\t||                                                                  ||\n");
                    printf("\t\t\t|| YOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!       ||\n");
                    printf("\t\t\t||                                                                  ||\n");
                    printf("\t\t\t||==================================================================||\n");
                    delay(10000000000);
                    system("cls");
                    retry:
                    printf("\nEnter 1 to go to main menu and 0 to exit ");
                    scanf("%d",&exit_func2);
                    if(exit_func2==0)
                    {
                        close();
                    }
                    else if(exit_func2==1)
                    {
                        menu();
                    }
                    else
                    {
                        printf("Invalid Choice!!");
                        goto retry;
                    }

                }
                attempt:
                printf("\nDo you want to:-");
                printf("\nEnter [1] to Deposit Money");
                printf("\nEnter [2] to Withdraw Money");
                printf("\nEnter Your Choice\n");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:Rs ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,
                            add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
                            add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n%f Rs has been deposited",transaction.amt);
                    printf("\nCurrent balance is Rs %f",add.amt);
                    printf("\n\nDeposited successfully!");
                }
                else if(choice ==2)
                {
                    printf("Enter the amount you want to withdraw:Rs ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,
                            add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,
                            add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n%f Rs has been deducted",transaction.amt);
                    printf("\nCurrent balance is Rs %f",add.amt);
                    printf("\n\nWithdrawn successfully!");
                }
                else
                {
                    invalid_done:
                    printf("\nInvalid Choice!!");
                    printf("\nEnter 0 to retry,1 to go to menu and 2 to exit");
                    scanf("%d",&exit_func2);
                    if(exit_func2==0)
                    {
                        goto attempt;
                    }
                    else if(exit_func2==1)
                    {
                        menu();
                    }
                    else if(exit_func2==2)
                    {
                        close();
                    }
                    else
                    {
                        goto invalid_done;
                    }

                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                       add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,
                       add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,
                       add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }

   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&exit_func);
      system("cls");
      if (exit_func==0)
        {
            transact();
        }
    else if (exit_func==1)
       {
           menu();
       }
    else if (exit_func==2)
        {
            close();
        }
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
        goback:
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_func);
        system("cls");
        if (exit_func==1)
           {
               menu();
           }
        else if(exit_func==0)
            {
                close();
            }
        else
            {
                printf("Invalid Choice!!");
                goto goback;
            }
   }

}
//Function to delete the account

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,
                  &add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.aadhar,
                  &add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
           {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.aadhar,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
           }
        else
            {
                test++;
                printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_func);

                 if (exit_func==1)
                   {
                       menu();
                   }
                else if (exit_func==2)
                    {
                        close();
                    }
                else if(exit_func==0)
                    {
                        erase();
                    }
                else
                    {
                        printf("\nInvalid!\a");
                    goto erase_invalid;
                    }
        }
    else
        {
            printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_func);
        system("cls");
        if (exit_func==1)
            {
                menu();
            }
        else
            {
                close();
            }
        }

}

//FUnction to check your account details

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    int year,date,month;
    float intrst;
    retry_account:
    ptr=fopen("record.dat","r");
    printf("\nDo you want to check by :-");
    printf("\nEnter [1] for Account Number");
    printf("\nEnter [2] for Name");
    printf("\nEnter Your Choice\n");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
                      &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,
                      &add.age,add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,
                      &add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)

            {   system("cls");
                test=1;
                printf("\nAccount number :%d ",add.acc_no);
                printf("\nName:%s" ,add.name);
                printf("\nDOB:%d/%d/%d",add.dob.month,add.dob.day,add.dob.year);
                printf("\nAge:%d",add.age);
                printf("\nAddress:%s",add.address);
                printf("\nAadhar No:%s",add.aadhar);
                printf("\nPhone number:%.0lf",add.phone);
                printf("\nType Of Account:%s ",add.acc_type);
                printf("\nAmount deposited:Rs %.2f",add.amt);
                printf("\nDate Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);

                if(strcmp(add.acc_type,"Fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"Fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"Fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"Savings")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmp(add.acc_type,"Current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,
                      add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,
                      add.address,add.aadhar,&add.phone,add.acc_type,&add.amt,&add.deposit.month,
                      &add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount number :%d ",add.acc_no);
                printf("\nName:%s" ,add.name);
                printf("\nDOB:%d/%d/%d",add.dob.month,add.dob.day,add.dob.year);
                printf("\nAge:%d",add.age);
                printf("\nAddress:%s",add.address);
                printf("\nAadhar No:%s",add.aadhar);
                printf("\nPhone number:%.0lf",add.phone);
                printf("\nType Of Account:%s ",add.acc_type);
                printf("\nAmount deposited:Rs %.2f",add.amt);
                printf("\nDate Of Deposit:%d/%d/%d\n\n",add.deposit.month,add.deposit.day,add.deposit.year);

              if(strcmp(add.acc_type,"Fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                    }
                else if(strcmp(add.acc_type,"Fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmp(add.acc_type,"Fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmp(add.acc_type,"Savings")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get Rs.%.2f as interest on %d of every month",intrst,add.deposit.day);

                     }
                 else if(strcmp(add.acc_type,"Current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else
    {
       printf("\nInvalid Choice!!");
       invalid_entry:
        printf("\nEnter 0 to try again , 1 to back to main menu and 2 to exit");
        scanf("%d",&exit_func2);
        if(exit_func2==0)
        {
            goto retry_account;
        }
        else if(exit_func2==1)
        {
            menu();
        }
        else if(exit_func2==2)
        {
            close();
        }
        else
        {
            printf("Invalid Choice!!");
            goto invalid_entry;
        }

    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_func);
              system("cls");
                 if (exit_func==1)
                    {
                        menu();
                    }
                else if (exit_func==2)
                    {
                        close();
                    }
                else if(exit_func==0)
                    {
                        see();
                    }
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;
                    }
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&exit_func);}
        if (exit_func==1)
        {
            system("cls");
            menu();
        }

        else
            {

                system("cls");
                close();
            }

}

//Function to apply for a loan

void loan()
{

  int credit_score;
  float loan_amount;

  printf("Enter your credit score: ");
  scanf("%d", &credit_score);

  if (credit_score >= MIN_CREDIT_SCORE)
    {
    printf("You are eligible for a loan.\n");
    printf("Enter the loan amount you want: ");
    scanf("%f", &loan_amount);

    if (loan_amount > MAX_LOAN_AMOUNT)
        {
                printf("Sorry, the maximum loan amount is %d.\n", MAX_LOAN_AMOUNT);
        }
    else
        {
            printf("Your loan of Rs%.2f has been approved.\n", loan_amount);
        }
    }
  else
    {
        printf("Sorry, your credit score is too low to qualify for a loan.\n");
    }
  printf("\nEnter 1 to return to main menu and 2 to exit:");
              scanf("%d",&exit_func);
              system("cls");
                 if (exit_func==1)
                    {
                        menu();
                    }
                else if (exit_func==2)
                    {
                        close();
                    }

}

//THe exit function of the code

void close(void)
{

    printf("\n\n\n\n\t\tThank you for visiting our bank.Make sure to fill the feedback form available at the counter so that we can get to know about your experience.\t\t");
    printf("\n Have a nice day!!\n");
    }

//Function for the main menu of the code

void menu(void)
{   int choice,i,n;
    system("cls");
    system("COLOR 07");
        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||                 KOTAK BANK MANAGEMENT SYSTEM                          ||");

        printf("\n||                                                                       ||");

        printf("\n||=======================================================================||");

        printf("\n||                    WELCOME TO MAIN MENU                               ||");

        printf("\n||=======================================================================||");

        printf("\n||                                                                       ||");

        printf("\n||-----------------------------------------------------------------------||");


        printf("\n||          Press [1]  TO CREATE NEW ACCOUNT                             ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [2] To UPDATE INFORMATION                              ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [3] To CHECK BALANCE                                   ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [4] To DO TRANSACTIONS                                 ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [5] To CHECK DETAILS OF EXISTING ACCOUNT               ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [6] To CLOSE YOUR ACCOUNT                              ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [7] To SEE LIST OF CUSTOMERS ACCOUNT                   ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [8] To APPLY FOR LOAN                                  ||");

        printf("\n||-----------------------------------------------------------------------||");

        printf("\n||          Press [9] To EXIT                                            ||");

        printf("\n||-----------------------------------------------------------------------||");


        printf("\n||=======================================================================||");

        printf("\n||          Please Enter Your Choice::                                   ||");

        printf("\n||=======================================================================||\n\n");

        fflush(stdin);
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:
            new_acc();
        break;
        case 2:
            edit();
        break;
        case 3:
            balance_list();
        break;
        case 4:
            transact();
        break;
        case 5:
            see();
        break;
        case 6:
            erase();
        break;
        case 7:
            view_list();
        break;
        case 8:
            loan();
        case 9:
            close();
        break;
        default:
            printf("\nInvalid choices");
            printf("\nEnter any number to go back to main menu\n");
            scanf("%d",&n);
            if(n+1)
                {
                    printf("Loading");
                    for( i=0;i<3;i++)
                    {
                        delay(1000000000);
                        printf(".");
                    }
                    menu();
                }
                    break;
    }



}
int main()
{
    char password[10]="12345678";
    //This function is used to give green color to the project
    /*Sets the default console foreground and background colors.

COLOR [attr]

  attr        Specifies color attribute of console output

Color attributes are specified by TWO hex digits -- the first
corresponds to the background; the second the foreground.  Each digit
can be any of the following values:

    0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White*/

    system("COLOR 07");

    int i=0;


	// Taking the password of 8 characters
	char pass[10];


	// To clear the screen
	system("cls");

	//The following code is used to enter the password from user secretly

	printf("\n\n\t\t Enter the password to login:");
	for (i = 0; i < 8; i++)
        {
            pass[i] = getch();
            printf("*");
        }
	pass[i] = '\0';
	printf("\n");

	/*printf("Entered password: ");
	for (i = 0; pwd[i] != '\0'; i++)
		printf("%c", pwd[i]);
	getch();*/


    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            delay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&exit_func);
            if (exit_func==1)
                    {

                        system("cls");
                        main();
                    }

            else if (exit_func==0)
                    {
                    system("cls");
                    close();
                    }
            else
                    {
                        printf("\nInvalid!");
                    delay(1000000000);
                    system("cls");
                    goto login_try;
                    }

        }
        return 0;
}


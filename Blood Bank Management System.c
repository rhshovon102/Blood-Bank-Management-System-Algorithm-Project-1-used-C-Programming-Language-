#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
struct database
{
    char name[100];
    char blood_group[100];
    int number;
};
struct login
{
    char username[100];
    char password[100];

};
void head_text()
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                 ALGORITHM PROJECT                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");
}
void welcome_text()
{
    head_text();
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =               BLOOD BANK                  =");
    printf("\n\t\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
    system("cls");
}
//admin mode
void View_List()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                 VIEW DONNER'S INFO LIST           ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n");

    struct database b;
    FILE *file = fopen("bloodbank.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    else
    {
        while(fread(&b,sizeof(b),1,file))
        {
            printf("\n\n\t\t\tDonner's Name: %s\n\t\t\tBlood Group: %s\n\t\t\tPhone Number: %d\n",b.name,b.blood_group,b.number);
        }
        fclose(file);
    }
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        AdminMode();
    }
}
//admin mode
void Add_People()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                   ADD DONNER'S INFO               ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct database b;
    FILE *file;
    file = fopen("bloodbank.txt","a");
    int n,count=0;
    if(file==NULL)
    {
        printf("File is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter How Many Donner Do You Want To Add: ");
    scanf("%d",&n);
    while(count<n)
    {
        printf("\n\t\t\tEnter Donner's Name: ");
        fflush(stdin);
        gets(b.name);
        printf("\t\t\tEnter Blood Group: ");
        fflush(stdin);
        gets(b.blood_group);
        printf("\t\t\tEnter Phone Number: ");
        scanf("%d",&b.number);
        fwrite(&b,sizeof(b),1,file);
        printf("\n\n");
        count++;

    }
    printf("\n\n\n\t\t\tDonner's Information Added Successfully");
    fclose(file);
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        AdminMode();
    }
}
//admin mode
void Search_BloodGroup()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SEARCH BLOOD GROUP               ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\t\t\t                         Use Upper Case To Search                         ");

    struct database b;
    int flag=0;
    char bgroup[100];
    FILE *file;
    file = fopen("book.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter The Blood Group Which You Want To Search: ");
    scanf("%s",bgroup);
    while(fread(&b,sizeof(b),1,file))
    {
        if(strcmp(bgroup,b.blood_group) == 0)
        {
            flag=1;
            printf("\n\n\t\t\tDonner's Name: %s\n\t\t\tBlood Group: %s\n\t\t\tPhone Number: %d\n",b.name,b.blood_group,b.number);
        }
    }
    if(!flag)
    {
        printf("\n\n\n\t\t\tBlood is not Available Right Now");
    }
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        AdminMode();
    }
}
//admin mode
void Total_Donner()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                     TOTAL DONNER                  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct database b;
    FILE *file;
    file = fopen("bloodbank.txt","r");
    fseek(file,0,SEEK_END);
    int n=ftell(file)/sizeof(b);
    printf("\n\n\n\t\t\tNumber of Total People in the Database is = %d",n);
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        AdminMode();
    }
}
//admin mode main
void AdminMode()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             WELCOME TO ADMIN MODE                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.View Donner's Info List"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Add Donner's Info"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"3.Search Donner by Blood Group"};
    printf("\n\t\t\t%s",c);
    char d[100]= {"4.Total Donners"};
    printf("\n\t\t\t%s",d);
    char e[100]= {"5.Back"};
    printf("\n\t\t\t%s",e);
    char f[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        View_List();
        break;
    case 2:
        Add_People();
        break;
    case 3:
        Search_BloodGroup();
        break;
    case 4:
        Total_Donner();
        break;
    case 5:
        AdminOrUser();
        break;
    }
}
//user mode
void Search_blood()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                 SEARCH BLOOD GROUP                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\t\t\t                         Use Upper Case To Search                         ");

    struct database b;
    int flag=0;
    char bgroup[100];
    FILE *file;
    file = fopen("bloodbank.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    printf("\n\n\n\t\t\tEnter The Blood Group That You Need: ");
    scanf("%s",bgroup);
    while(fread(&b,sizeof(b),1,file))
    {
        if(strcmp(bgroup,b.blood_group) == 0)
        {
            flag=1;
            printf("\n\n\t\t\tDonner's Name: %s\n\t\t\tBlood Group: %s\n\t\t\tPhone Number: %d\n",b.name,b.blood_group,b.number);
        }
    }
    if(!flag)
    {
        printf("\n\n\n\t\t\tBlood is not Available Right Now");
    }
    fclose(file);

    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode
void  Donner_lists()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                 VIEW DONNER'S INFO LIST           ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\n\n");

    struct database b;
    FILE *file = fopen("bloodbank.txt","r");
    if(file==NULL)
    {
        printf("\n\n\n\t\t\tFile is not Exist\n");
    }
    else
    {
        while(fread(&b,sizeof(b),1,file))
        {
            printf("\n\n\t\t\tDonner's Name: %s\n\t\t\tBlood Group: %s\n\t\t\tPhone Number: %d\n",b.name,b.blood_group,b.number);        }
        fclose(file);
    }
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}

//user mode
void Add_yourself()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                 ADD YOURSELF AS A DONNER          ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    struct database b;
    FILE *file;
    file = fopen("bloodbank.txt","a");
    if(file==NULL)
    {
        printf("File is not Exist\n");
    }
        printf("\n\n\t\t\tEnter Your Name: ");
        fflush(stdin);
        gets(b.name);
        printf("\t\t\tEnter Your Blood Group: ");
        fflush(stdin);
        gets(b.blood_group);
        printf("\t\t\tEnter Your Phone Number: ");
        scanf("%d",&b.number);
        fwrite(&b,sizeof(b),1,file);

    printf("\n\n\n\t\t\tYour Information Added Successfully");;
    fclose(file);
    printf("\n\n\n\t\t\tIf You Want To Go Back");
    char f[100]= {"Enter 1 => "};
    printf("\n\t\t\t%s",f);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        user();
    }
}
//user mode main
void user()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              WELCOME TO USER MODE                 ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.Donner's Info List"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Search Blood Group"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"3.Add Yourself"};
    printf("\n\t\t\t%s",c);
    char d[100]= {"4.Back"};
    printf("\n\t\t\t%s",d);
    char e[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",e);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Donner_lists();
        break;
    case 2:
        Search_blood();
        break;
    case 3:
        Add_yourself();
        break;
    case 4:
        AdminOrUser();
        break;
    }
}
void AdPass()
{
    system("cls");

    char userName[100]= {"Rakib@Hasan"};
    char password[100]= {"211-15-3948"};
    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                   LOGIN HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\n\t\t\tUser Name :");
    scanf("%s",userName);
    printf("\n\t\t\tPassword  :");
    scanf("%s",password);
    if (strcmp(userName,"Rakib@Hasan") == 0 && strcmp(password,"211-15-3948")==0)
    {
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############                  LOGIN SUCCESSFUL                 ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");

        printf("\n\n\n\n\t\t\tEnter any key to continue.....");
        getch();
        AdminMode();
    }
    else
    {
        system("cls");

        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t############            WRONG USERNAME OR PASSWORD             ############");
        printf("\n\t\t\t############                                                   ############");
        printf("\n\t\t\t###########################################################################");

        printf("\n\n\n\t\t\tEnter any Key to Try again...");
        getch();
        AdPass();

    }
}
void AdminOrUser()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SELECT HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    char a[100]= {"1.ADMIN"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.USER"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",c);
    int choice;
    scanf("%d",&choice);

    if(choice == 1)
    {
        AdPass();
    }
    else if(choice == 2)
    {
        UsPass();
    }
}
void log()
{

    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                    LOGIN HERE                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    char username[100];
    char password[100];
    struct login b;
    FILE *file;
    file = fopen("login.txt","r");
    printf("\n\n\n\t\t\tEnter User Name: ");
    fflush(stdin);
    gets(username);
    printf("\n\t\t\tEnter Password: ");
    fflush(stdin);
    gets(password);
    while(fread(&b,sizeof(b),1,file))
    {
        if (strcmp(username,b.username) == 0 && strcmp(password,b.password)==0)
        {
            system("cls");

            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t############                  LOGIN SUCCESSFUL                 ############");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t###########################################################################");

            printf("\n\n\n\n\t\t\tEnter any key to continue.....");
            getch();
            user();
        }
        else
        {
            system("cls");

            printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t############            WRONG USERNAME OR PASSWORD             ############");
            printf("\n\t\t\t############                                                   ############");
            printf("\n\t\t\t###########################################################################");

            printf("\n\n\n\t\t\tEnter any key to  Try again...");
            getch();
            log();
        }
    }
    fclose(file);
}
void reg()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############              REGISTRTION HERE                     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    struct login b;
    FILE *file;
    file = fopen("login.txt","w");
    printf("\n\n\n\t\t\tEnter User Name: ");
    fflush(stdin);
    gets(b.username);
    printf("\n\t\t\tEnter Password: ");
    fflush(stdin);
    gets(b.password);
    fwrite(&b,sizeof(b),1,file);
    fclose(file);

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############             REGISTRTION SUCCESSFUL                ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");

    printf("\n\n\n\n\t\t\tEnter any key to go to the Login page.....");
    getch();
    log();
}

void UsPass()
{
    system("cls");

    printf("\n\n\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                  SELECT HERE                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    char a[100]= {"1.Registration"};
    printf("\n\n\n\t\t\t%s",a);
    char b[100]= {"2.Login"};
    printf("\n\t\t\t%s",b);
    char c[100]= {"Enter choice => "};
    printf("\n\n\n\t\t\t%s",c);
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        reg();
        break;
    case 2:
        log();
        break;
    }

}
int main()
{
    welcome_text();
    AdminOrUser();
    getch();
}


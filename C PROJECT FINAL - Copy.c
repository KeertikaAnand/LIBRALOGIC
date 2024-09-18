#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


#define ENTER 13
#define TAB 9
#define BKSP 8
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void AdminPassword(void);
void menu(void);
void Student(void);
void Admin(void);

//Admin Functions
void addUser(void);
void modifyUser(void);
void listUser(void);
int searchUser(int);
void rentList(void);
void deleteUser(void);
void addBook(void);
int modifyBook(int);
void deleteBook(void);

//Student function

void listBook(void);
void rentBook(void);
int searchBook(int);


void main(){
   menu();
}

int passTerminator = 1;
    int bookStock = 0;
    char rentName[255], bookName[255];


void menu(){

    system("cls");
    fflush(stdin);

    int number;

   gotoxy(80, 3);
	printf("---------------WELCOME TO LIBRARY MANAGEMENT SYSTEM---------------");
gotoxy(95, 8);

    printf("> ADMIN\n");
    gotoxy(95, 10);
    printf("> STUDENT \n\n");
    gotoxy(95, 12);
    printf("> Enter Choice: ");
    scanf("%d",&number);

    fflush(stdin);

   switch(number)
    {
        case 1:
            AdminPassword();
            break;
        /*case 2:
            bookPanel();
            break;*/
        default:
            printf("\n> Invaild Input! <");
            Sleep(2000);
            menu();
    }
}
void AdminPassword(){

    system("cls");


    char passWord[255];
    char code[255] = {"Library123"};
    int i = 0;
	char ch;

gotoxy(95, 7);
printf("----------ADMIN LOGIN CREDENTIALS----------\n");
gotoxy(95,13 );
	printf("Enter your password \n");
	gotoxy(95, 16);
	printf("Password:");
	 for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != ENTER) {
            passWord[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else
            break;
    }


    if(strcmp(code, passWord) == 0)
    {
    	gotoxy(95, 25);
        printf("\nCorrect Password!");
        Sleep(2000);
        Admin();
    }
    else
    {
    	gotoxy(95, 25);
        printf("\nInvaild Password!");
        (passTerminator == 3) ? exit(0) : passTerminator++;
        Sleep(2000);
        AdminPassword();
    }
}


void Admin(){

    system("cls");
    fflush(stdin);

    int number;

    gotoxy(95, 3);
    printf("  ----------ADMIN PANEL----------\n");
    gotoxy(95, 8);
    printf("> 1. Add User \n");
    gotoxy(95, 10);
    printf("> 2. Modify User \n");
    gotoxy(95, 12);
    printf("> 3. List User \n");
    gotoxy(95, 14);
    printf("> 4. List Rentals \n");
    gotoxy(95, 16);
    printf("> 5. Search User \n");
    gotoxy(95, 18);
    printf("> 6. Delete User \n");
    gotoxy(95,20);
    printf(">7.Add Book");
    gotoxy(95,22);
    printf(">8.Modify Book");
    gotoxy(95,24);
    printf(">9.Delete Book");
    gotoxy(95,26);
    printf("> 10. Open Main Menu \n");
    gotoxy(95,28);
    printf("> 11. Close the Program... \n\n");
	gotoxy(95,32);
    printf("> Enter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

   switch(number)
    {
        case 1:
            addUser();
            break;
        case 2:
            modifyUser();
            break;
        case 3:
            listUser();
            break;
       /* case 4:
            rentList();
            break;
        case 5:
            searchUser(0);
            break;
        case 6:
            deleteUser();
            break;
		case 7:
            addBook();
            break;
        case 8:
            modifyBook(0);
            break;
		case 9:
			deleteBook();
            break;
		case 10:
            menu();
            break;
        case 11:
            endScreen();
            break;*/
        default:
            printf("Invaild Input!");
            Sleep(2000);
           Admin();
    }
}
void addUser(){

label1:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255];
    char gender;
    double sid, phone, balance;

    FILE *pF = fopen("user_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Enter the First Name: ");
        gets(fname) ;

        printf("Enter the Last Name: ");
        gets(lname);

        printf("Enter Gender [M/F]: ");
        scanf("%c",&gender);

        printf("Enter Student ID: ");
        scanf("%lf",&sid);

        printf("Enter Phone Number: ");
        scanf("%lf",&phone);

        fprintf(pF, "%s %s %c %.0lf %.0lf \n", fname, lname, gender, sid, phone);
system("cls");
gotoxy(95,25);
        printf("\n>>> User Record Added Successfully <<< \n");

    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF);

    fflush(stdin);

    //retry screen
    char input;
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label1;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirecting to User Panel.");
        Sleep(2000);
        Admin();
    }
    else
    {
        printf("\nInvaild input. Redirecting to User Panel.");
        Sleep(2000);
        Admin();
    }
}

// Edit the user details and saves it
void modifyUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf("Enter the name of the person you want to modify the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Found, Allowing Modifications <<<\n");
            printf("-----------------------------------------------\n\n");

            printf("> Enter First Name: ");
            gets(fname1);

            printf("> Enter Last Name: ");
            gets(lname1);

            printf("> Enter Gender: ");
            gets(gender1);

            printf("> Enter Student ID: ");
            scanf("%lf",&sid1);

            printf("> Enter Phone Number: ");
            scanf("%lf",&phone1);

            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname1, lname1, gender1, sid1, phone1);
            printf("\n\nProcessing your changes....");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to User Panel...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
   Admin();

}

// Lists all the user records from user_Records.txt file
void listUser(){

    system("cls");
    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter=0;

    printf("-------------------------------\n");
    printf(">>> List of Users Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
       strcat(fname, " ");
       strcat(fname, lname);

        printf("-------------------------------\n");
        printf("> Full Name: %s \n", fname);
        //printf("> Last Name: %s \n", lname);
        printf("> Gender: %s \n", gender);
        printf("> Student-ID: %.0lf \n", sid);
        printf("> Phone No.: %.0lf \n", phone);
        printf("-------------------------------\n\n\n");

        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no user records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to User Panel.\n");
    getch();
    Admin();
}


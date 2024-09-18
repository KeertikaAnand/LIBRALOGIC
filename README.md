# LIBRALOGIC
LibraLogic is a library management platform designed to  optimize operations with features like detailed book  insights, easy access, and a simple interface.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

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

void endScreen(void);



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
        case 2:
            Student();
            break;
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
        case 4:
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
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
           Admin();
    }
}


void Student(){

    system("cls");
    fflush(stdin);

    int number;

     gotoxy(95, 3);
    printf("-----------------STDENT PANEL-----------------\n");

     gotoxy(95, 7);
    printf("> 1. List Book \n");
     gotoxy(95, 9);
    printf("> 2. Rent Book \n");
     gotoxy(95, 11);
    printf("> 3. Search Book \n");
    gotoxy(95,13);
    printf("> 4. Open Main Menu \n");
     gotoxy(95,15);

    printf("> 5. Close the Program... \n");
gotoxy(95,25);
    printf("\nEnter the number & hit ENTER: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {

        case 1:
            listBook();
            break;
        case 2:
            rentBook();
            break;
        case 3:
            searchBook(0);
            break;

        case 4:
            menu();
            break;
        case 5:
            endScreen();
            break;
        default:
            printf("Invaild Input!");
            Sleep(2000);
            Student();
    }
}







void addUser(){

label1:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255];
    char gender;
    double sid, phone;

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
int searchUser(int nameSearcher){

label2:

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    double sid, phone;

    int flag=0;
    int compare;
    char find[255];

    (nameSearcher != 3) ? printf("Search by First name of the student: ") : printf("Search by First name of the student who wants to rent book: ");
    gets(find);

    FILE *pF = fopen("user_Records.txt", "r");

     while(fscanf(pF, "%s %s %s %lf %lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        //strcmp(variable, variable1) -- if both the strings are equal then it will return 0 otherwise a random number.
        compare = strcmp(find, fname);

        if(compare == 0)
        {
            if(nameSearcher != 3)
            {
                strcat(fname, " ");
                strcat(fname, lname);

                printf("\n---------------------\n");
                printf(">>> Record Found <<< \n");
                printf("---------------------\n\n");

                printf("-------------------------------\n");
                printf("> Full Name: %s \n", fname);
                printf("> Gender: %s \n", gender);
                printf("> Student-ID: %.0lf \n", sid);
                printf("> Phone Number: %.0lf \n", phone);
                printf("-------------------------------\n\n");

            }
            strcpy(rentName, fname);
            flag=1;
        }
    }

    fclose(pF);

    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    fflush(stdin);

    if(nameSearcher != 3)
    {
        printf("Press any key to redirect back to Panel.");
        getch();
        Admin();
    }
    else if(nameSearcher == 3 && flag == 1)
    {
        return 5;
    }
}

// deletes the user information from user_Records.txt file
void deleteUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf("Enter the name of the person you want to delete the detail: ");
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
            printf(">>> Record Deleted <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirecting to User Panel...");


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

// Book Functions
// add the books record in book_Records.txt file
void addBook(){

label3:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    FILE *pF = fopen("book_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf("Enter Book Name: ");
        gets(name);

        printf("Enter Book Author: ");
        gets(author);

        printf("Enter Book Publisher: ");
        gets(publisher);

        fflush(stdin);

        printf("Enter Book ID: ");
        scanf("%lf",&bookid);

        printf("Enter Book Quantity: ");
        scanf("%lf",&quantity);

        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);

        printf("\n>>> Book Record Added Successfully <<< \n");
    }
    else
    {
        printf("Unable to open/locate the file.");
    }

    fclose(pF);

    fflush(stdin);

    char input;
    printf("\nDo you wanna enter more records [y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label3;
    }
    else if(input=='n' || input=='N')
    {
        printf("\nRedirecting to Book Panel.");
        Sleep(2000);
       Admin();
    }
    else
    {
        printf("\nInvaild input. Redirecting to Book Panel.");
        Sleep(2000);
        Admin();
    }
}

// edits the book details according to you and saves it again
int modifyBook(int rentModifier){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;
    char find[255];

    if (rentModifier != 5)
    {
        printf("Enter the name of the book you want to see the detail: ");
        gets(find);
        fflush(stdin);
    }
    else
    {
        strcpy(find, bookName);
    }

    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            if(rentModifier != 5)
            {
                printf("\n---------------------------------------------\n");
                printf(">>> Record Found, Allowing Modifications <<<\n");
                printf("-----------------------------------------------\n\n");

                printf("> Enter Book Name: ");
                gets(name1);

                printf("> Enter Authour: ");
                gets(author1);

                printf("> Enter Publisher: ");
                gets(publisher1);

                fflush(stdin);

                printf("> Enter Book ID: ");
                scanf("%lf",&bookid1);

                printf("> Enter Quantity: ");
                scanf("%lf",&quantity1);

                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name1, author1, publisher1, bookid1, quantity1);
                printf("\n\nProcessing your changes....");
            }
            else
            {
                quantity = bookStock;
                fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
            }
            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("book_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to Book Panel...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    if(rentModifier != 5)
    {
        Sleep(2000);
       Admin();
    }
}

void rentList(){

    system("cls");
    fflush(stdin);

    char rentListUser[255], rentListBook[255];
    int counter = 0;

    FILE *pF = fopen("rent_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> List of Books Rental <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s \n", rentListUser, rentListBook) != EOF)
    {
        printf("> Rent User: %s \n", rentListUser);
        printf("> Rent Book(s): %s \n\n", rentListBook);

        counter++;
    }

    fclose(pF);
    fflush(stdin);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no rent records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("\nPress any key to get back to User Panel.\n");
    getch();
    Admin();
}
void deleteBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;

    char find[255];
    printf("Enter the name of the book you want to delete the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            printf("\n---------------------------------------------\n");
            printf(">>> Record Deleted <<<\n");
            printf("-----------------------------------------------\n\n");
            printf("Redirecting to Book Panel...");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("book_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf("\n\n-------------------------------\n");
        printf(">>> Record Not Found <<<\n");
        printf("-------------------------------\n\n");
        printf("Redirecting to Book Panel...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s %s %s %.0lf %.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    Sleep(2000);
    Admin();
}

void listBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double quantity, bookid;
    int counter=0;

    FILE *pF = fopen("book_Records.txt", "r");

    printf("-------------------------------\n");
    printf(">>> List of Books Record <<< \n");
    printf("-------------------------------\n\n");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        printf("-------------------------------\n");
        printf("> Book Name: %s \n", name);
        printf("> Auhtor: %s \n", author);
        printf("> Publisher: %s\n", publisher);
        printf("> Book ID: %.0lf \n", bookid);
        printf("> Quantity: %.0lf \n", quantity);
        printf("-------------------------------\n\n\n");
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf("-------------------------------------\n");
        printf("There is no book records added yet...\n");
        printf("--------------------------------------\n\n");
    }

    printf("Press any key to get back to Book Panel.\n");
    getch();
    Student();
}

void calculateDueDate(int borrowDays) {
    time_t currentTime = time(NULL);
    time_t dueDate = currentTime + borrowDays * 24 * 60 * 60;

    printf("Due Date: %s", ctime(&dueDate));
}

void rentBook(){

    int terminator=1, nameFound, bookFound;
      int borrowDays=30;


label5:

    fflush(stdin);

    // check if user exists
    nameFound = searchUser(3);

    if(nameFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? Student() : terminator++;
        goto label5;
    }
    else if(nameFound == 5)
    {
        printf("\nUser Found in Records! \nPlease wait... \n");
        terminator = 1;
        Sleep(2000);
    }

label6:

    fflush(stdin);

    // check if book exists
    bookFound = searchBook(3);

    if(bookFound != 5 && terminator != 4)
    {
        printf("Press any key to re-enter the name. \n");
        getch();
        (terminator == 3) ? Student() : terminator++;
        goto label6;
    }
    else if(bookFound == 5)
    {
        // check if book quantity is > 0
        if(bookStock > 0)
        {
            printf("\nBook Found & In-Stock! \nPlease wait... \n");
        }
        else
        {
            printf("\nSorry, Out of Stock! \nPlease wait... ");
            Sleep(2000);
            (terminator == 3) ? Student() : terminator++;
            goto label6;
        }
    }

    fflush(stdin);

    if(nameFound == 5 && bookFound == 5)
    {
        // Adding record in rent_Records.txt file
        FILE *pF = fopen("rent_Records.txt", "ab+");

        if(pF != NULL)
        {
            fprintf(pF, "%s %s \n", rentName, bookName);


        }
        else
        {
            printf("Unable to open/locate the file.");
        }

        fclose(pF);

        // reducing quantity of book by 1
        bookStock--;
        modifyBook(5);

        printf("---------------------------------------------\n");
        printf(">>> Rent Record Added Successfully <<< \n");
        printf("---------------------------------------------\n");
          calculateDueDate(borrowDays);



        printf("\nRedirecting to Book Panel...\n");
        Sleep(3500);
        Student();
    }
}

int searchBook(int bookSearcher){

label4:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    int flag=0;
    int compare;

    char find[255];

    (bookSearcher != 3) ? printf("Serach the book by Author name or Book name: ") : printf("Serach the book by Author name or Book name: ");
    gets(find);

    FILE *pF = fopen("book_Records.txt", "r");

    while(fscanf(pF, "%s %s %s %lf %lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);
        compare = strcmp(find, author);

        if(compare == 0)
        {
            if(bookSearcher != 3)
            {
                printf("\n-------------------------\n");
                printf(">>> Record Found <<< \n");
                printf("-------------------------\n\n");

                printf("-------------------------------\n");
                printf("> Book Name: %s \n", name);
                printf("> Auhtor: %s \n", author);
                printf("> Publisher: %s\n", publisher);
                printf("> Book ID: %.0lf \n", bookid);
                printf("> Quantity: %.0lf \n", quantity);
                printf("-------------------------------\n\n");
            }
            strcpy(bookName, name);
            bookStock = quantity;
            flag=1;
        }
    }

    fclose(pF);

    fflush(stdin);

    if(flag == 0)
    {
        printf("\n>>> Record Not Found <<< \n\n");
    }

    if(bookSearcher != 3)
    {
        printf("Press any key to redirect to Book Panel.");
        getch();
        Student();
    }
    else if(bookSearcher == 3 && flag == 1)
    {
        return 5;
    }

}

void endScreen()
{

    system("cls");
    fflush(stdin);

   gotoxy(95,4);
    printf("--------LIBRARY MANAGEMENT SYSTEM-------------\n");

	 gotoxy(95,6);
	 printf("DONE BY:\n");
	  gotoxy(95,8);
    printf("> BHARAT VIKRAMAN      -    71762231010 \n");
    gotoxy(95,10);
    printf("> GURU SATURA          -    71762231022 \n");
    gotoxy(95,12);
	printf("> KEERTIKA             -    71762231025 \n");
	gotoxy(95,14);
	printf("> RITHIKA              -    71762231043 \n");


    exit(0);
}

#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_BOOKS 100
int bookCount = 0;

const char* filename = "add.txt";
struct Book{
int bookId;
char title[40];
char author[30];
char category[25];
int year;

int status;
};
struct Library {
    struct Book books[MAX_BOOKS];
    int num_books;
};
void addBook(struct Library *library, const char *title, const char *author, int year,const char *category) {
    if (library->num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book newBook;
    strcpy(newBook.title, title);
    strcpy(newBook.author, author);
     strcpy(newBook.category, category);
    newBook.year = year;
    newBook.status = 1;

    library->books[library->num_books] = newBook;
    library->num_books++;

    printf("Book added successfully.\n");

     FILE* file = fopen("add.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int i;
    for (i = 0; i < library->num_books; i++) {
        fprintf(file, "%d,%s,%s,%d\n", library->books[i].bookId, library->books[i].title, library->books[i].author, library->books[i].category);
    }

    fclose(file);

    printf("Books have been written to the file: %s\n", file);
}
void displayBooks(const struct Library *library,int bookCount) {
    if (library->num_books == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Title: %s\n", library->books[i].title);
        printf("Author: %s\n", library->books[i].author);
        printf("Year: %d\n", library->books[i].year);
        printf("Category : %s\n",library->books[i].category);
        printf("Status: %s\n\n", library->books[i].status? "Available" : "Not available");
    }
}
void searchBook(const struct Library *library, const char *title) {
    int found = 0;

    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            found = 1;
            printf("Book found:\n");
            printf("Title: %s\n", library->books[i].title);
            printf("Author: %s\n", library->books[i].author);
            printf("Year: %d\n", library->books[i].year);
             printf("Category: %s\n", library->books[i].category);
            printf("Status: %s\n", library->books[i].status ? "Available" : "Not available");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}
void calculateIssueDate() {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    // Add days to current date
    localTime->tm_mday ;

    // Convert the updated time back to a time_t object
    time_t issueTime = mktime(localTime);

    // Convert the time_t object to a formatted date string
    char issueDate[20];
    strftime(issueDate, sizeof(issueDate), "%Y-%m-%d", localtime(&issueTime));

    printf("Issue Date: %s\n", issueDate);
}
void borrowBook(struct Library *library, const char *title) {
    int found = 0;

    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            found = 1;
            if (library->books[i].status==1) {
                library->books[i].status = 0;
                printf("Book borrowed successfully.\n");
                printf("BORROWED ON :");
                calculateIssueDate();
            } else {
                printf("Book is not available for borrowing.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}
void returnBook(struct Library *library, const char *title) {
    int found = 0;

    for (int i = 0; i < library->num_books; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            found = 1;
            if (library->books[i].status==0) {
                library->books[i].status = 1;
                printf("Book returned successfully.\n");
            } else {
                printf("Book was not borrowed.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}
void suggestBooksByCategory(struct Library *library,const char* category) {
    printf("Books in the '%s' category:\n", category);
    int found = 0;

    for (int i = 0; i <library->num_books; i++) {
        if (strcmp(library->books[i].category, category) == 0) {
            printf("- %s\n", library->books[i].title);
            found++;
        }
    }

    if (found== 0) {
        printf("No books found in the '%s' category.\n", category);
    }
}

void readBooksFromFile(struct Library *library, int* bookCount, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    *bookCount = 0;

    while ((*bookCount < MAX_BOOKS) && fscanf(file, "%d,%[^,],%[^,],%d\n",library->books[*bookCount].bookId, library->books[*bookCount].title,
                                              library->books[*bookCount].author, library->books[*bookCount].category) == 4) {
        (*bookCount)++;
    }

    fclose(file);

    printf("Books have been read from the file: %s\n", filename);
}

void printIssuedBooks(struct Library *library, int bookCount) {
    int i, count = 0;
    printf("List of Issued Books:\n");
    for (i = 0; i < bookCount; i++) {
        if (library->books[i].status==0){
            printf("Book ID: %d\n",library-> books[i].bookId);
            printf("Book Name: %s\n",library-> books[i].title);
            printf("Author: %s\n",library-> books[i].author);
             printf("Category: %s\n",library-> books[i].category);
            printf("------------------------\n");
            count++;
        }
    }
    if (count == 0) {
        printf("No books are currently issued.\n");
    }
}

void calTime()
{
	time_t currentTime = time(NULL);
    struct tm *currentLocalTime = localtime(&currentTime);

    // Extract time components
    int hours = currentLocalTime->tm_hour;
    int minutes = currentLocalTime->tm_min;
    int seconds = currentLocalTime->tm_sec;

    // Print the current time
    printf("Current Time: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
void Admin()
{
	struct Library library;
    library.num_books = 0;

    int choice;
    char title[100];
    char author[100];
    int year;
    char category[30];
int regno;
int password;
int user;


	int adminId;
int adpass;
	printf("ENTER ADMINID   : ");
scanf("%d",&adminId);
printf("ENTER PASSWORD  : ");
scanf("%d",&adpass);
if(adminId==adpass){
    printf("1.ADD BOOK\n2.DISPLAY BOOK\n3.ISSUED BOOKS\n4.EXIT");
    do{
    printf("\nEnter your  choice :");
    scanf("%d",&choice);
    switch(choice)
    {
case 1:
printf("Enter book title: ");
                scanf(" %[^\n]s", title);
                printf("Enter book author: ");
                scanf(" %[^\n]s", author);
                printf("Enter publication year: ");
                scanf("%d", &year);
                printf("Enter book Category: ");
                scanf(" %[^\n]s", category);
                addBook(&library, title, author, year,category);
                break;
case 2:
	readBooksFromFile(&library, &bookCount, filename);
	displayBooks(&library,bookCount);
                break;
case 3:


    readBooksFromFile(&library, &bookCount, filename);
    printIssuedBooks(&library, bookCount);
case 4:
	login();
    }
    }while(choice!=4);
}
else
{
printf("\nINVALID LOGIN CREDENDIALS");
}
}
void login()
{
	printf("\n1.LOGIN AS ADMIN\n\n2.LOGIN AS STUDENT");
	int choice;
	printf("\n\nENTER CHOICE :");
	scanf("%d",&choice);

	system("cls");
	if(choice==1)
	{
		Admin();
	}
	else{
	Student();
	}
}
void Student()
{
	struct Library library;
    library.num_books = 0;

    int choice;
    char title[100];
    char author[100];
    int year;
    char category[30];
int regno;
int password;
int user;
printf("ENTER REGNO   : ");
scanf("%d",&regno);
printf("ENTER PASSWORD  : ");
scanf("%d",&password);
system("cls");

if(regno==password){
    printf("1.DISPLAY BOOK\n2.SEARCH\n3.BORROW\n4.RETURN\n5.SUGGESTION\n6.EXIT");
    do{
    printf("\nEnter your  choice :");
    scanf("%d",&choice);
    switch(choice)
    {

case 1:
	readBooksFromFile(&library, &bookCount, filename);
	displayBooks(&library,&bookCount);
                break;
case 2:
                printf("Enter book title to search: ");
                scanf(" %[^\n]s", title);
                searchBook(&library, title);
                break;
case 3:
                printf("Enter book title to borrow: ");
                scanf(" %[^\n]s", title);
                borrowBook(&library, title);
                break;
case 4:
                printf("Enter book title to return: ");
                scanf(" %[^\n]s", title);
                returnBook(&library, title);
                break;
case 5:
                printf("Enter category: ");
                scanf(" %[^\n]s", category);
                suggestBooksByCategory(&library,category);
                break;
case 6:
	exit(0);
    }
    }while(choice!=7);
}
else{
	printf("\nINVALID LOGIN CREDENDIALS");
}

}
int main()
{

login();
}

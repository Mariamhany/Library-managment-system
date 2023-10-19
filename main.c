/*
 * main.c
 *
 *  Created on: Oct 16, 2023
 *      Author: HP
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void addBook();
void printBooks();
void buyBook();
void borrowBook();
void deleteBook();

#define MAX_BOOK_SIZE 100

//struct to take details of book from user
typedef struct{
	char book_title[100];
	char author_name[100];
    int publication_year;
    float price;

} Book_details;

//struct that store details of the books and its copies and status.
//status either "borrowed" or "available"
typedef struct {
    Book_details Book;
    int no_of_copies;
    char status[50];
} Library;

Library books[MAX_BOOK_SIZE];
int bookcount=0;

/*
 *
 Function take book title and search for the book.
 *
 */
int search(char *str)
{
    if (bookcount==0)
    return -1;
for (int i=0;i<MAX_BOOK_SIZE ;i++)
    {
        if (strcmp(books[i].Book.book_title,str)==0)
        return i;
    }
 return -1;

}
/*
 *
 Function adds a book to the system
 *If the max book size reached give error message
 *If book already exist, number of copies are increased
 *
 */
void addBook(){
    printf("\n **Adding a book** \n");
if (bookcount==MAX_BOOK_SIZE)
{
    printf(" SORRY ! Library is Full!!!\n");
    return;
}
else {
	printf("Enter details of the book\n");
	printf("Book title:");
	char s[100];
    scanf(" %[^\n]s ",s);
    getchar();
    if(strlen(s)>100)
    {
       printf("Error: you exceeded the limit of string\n");
    }
    else{
    int index=search(s);
    if (index==-1){
    strcpy(books[bookcount].Book.book_title, s);
    printf("Author Name:");
   scanf("%[^\n]s",books[bookcount].Book.author_name);
   //getchar();
    printf("Publication Year:");
    scanf("%d",&books[bookcount].Book.publication_year);
    printf("Price:");
    scanf("%f",&books[bookcount].Book.price);
    books[bookcount].no_of_copies=1;
    strcpy(books[bookcount].status, "Available");

    bookcount++;
    }
    else {
        books[index].no_of_copies++;
        strcpy(books[bookcount].status, "Available");
    }
    }//end of if (strlen(s)>100)
  }//end of if(bookcount==100)
}
/*
 *
 *Function borrows a book from the system
 *If book exist, number of copies are decreased
 *If all copies are borrowed,message is displayed to the user
 */
void borrowBook()
{
    printf("\n** Borrow Book **\n");
    printf(" Enter the Book you want to borrow \n");
    char s1[100];
    scanf(" %[^\n]s ",s1);
    getchar();
    int index=search(s1);
    if (index==-1)
    {
        printf("\n Book not found!! \n");
    }
    else if ((books[index].no_of_copies)==0)
    {
        printf("\n Book is borrowed, no copies avaiable!! \n");
    }
    else
    {
        books[index].no_of_copies--;
        strcpy(books[index].status, "Borrowed");
    }

}
/*
 *
 Function buys more copies from already existing book and adds the copies to the system
 *
 */
void buyBook()
{
    printf("\n** Buy Book **\n");
    printf(" Enter the Book you want to buy copies from \n");
    char s1[100];
    int copies;
    scanf(" %[^\n]s ",s1);
    getchar();
    int index=search(s1);
    if (index==-1)
    {
        printf("\n Book not found!! \n");
    }
    else
    {
        printf(" please enter the number of copies you want to buy \n");
        scanf("%d",&copies);
        books[index].no_of_copies+=copies;
    }
}
/*
 *
 *Function deletes all copies of a book from the system
 *
 */
void deleteBook()
{
    printf("\n** Delete Book **\n");
    printf(" Enter the Book you want to delete \n");
    char s1[100];
    scanf(" %[^\n]s ",s1);
    getchar();
    int index=search(s1);
    if (index==-1)
    {
        printf("\n Book not found!! \n");
    }
    else
    {
        for (int i=index;i<bookcount;i++) //shift all books one place backward to rearrange the library.
    {
         books[i]=books[i+1];
    }
    bookcount--;
    }

}
/*
 *
 * Function prints details of each book
 *
 */
void printBooks()
{
    printf("\n****Printing Library*****\n");
    for (int i=0;i<bookcount;i++)
        {
    printf("Book title: %s\n",books[i].Book.book_title );
    printf("Author Name: %s\n",books[i].Book.author_name );
    printf("Publication Year: %d\n",books[i].Book.publication_year );
    printf("Price: %f\n",books[i].Book.price);
    printf("Number of Copies: %d\n" ,books[i].no_of_copies);
    printf("Status: %s\n",books[i].status);

    }

}




int main(){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("\n****Welcome to Library Management System*****\n");
	addBook();
	addBook();
	addBook();
	addBook();
	printBooks();
    borrowBook();
    printBooks();
	buyBook();
    printBooks();
	deleteBook();
	printBooks();
	return 0;
}




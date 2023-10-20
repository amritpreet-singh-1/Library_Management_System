#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


int k=0;                  // -> to keep track of books entered in lib array
typedef struct Books{   // -> global datatype(user-defined)
    int ISBN;
    char Title[50];
    char Author[50];
    char Publisher[50];
    char Genre[30];
    int Year;
    int Stock;
    float Price;
} book;

book Library[500];    // -> global array
//Library[0]={101,"HarryPotter","JKRowling","Bloombury","Fiction",2012,20,345.353};
void createMenu();       // creates the main menu & takes choice as input from user
void addInventory();     // allows the user to add book details in the library
void search();               // takes a keyword from user and and searches the book in library
void purchase_book();  // searches for book entered by user by keyword & allows the user to purchase a book
void return_book();        // searches for book entered by user by keyword & allows the user to return a book
void deleteRecord();       // deletes an entire book record
void displayBooks();       // displays book records stores in library
void retry();                      // asks the user whether he wants to print the menu again or exit the program and takes input
void quit();                       // exits the program

int main(){

    createMenu();

}

void createMenu(){

    int choice;
    do{
        system("cls");
        printf("<-------------------LIBRARY MANAGEMENT SYSTEM-------------------->\n\n");
        printf("Press 1 to add new books to the inventory:-> \n");
        printf("press 2 to search book by a keyword:-> \n");
        printf("Press 3 to enter the purchase or return menu:--> \n");
        printf("Press 4 to remove a book from the system:-> \n");
        printf("Press 5 to display one or more book details:-> \n");
        printf("Press 6 to exit the system menu:--> \n");
        printf("Enter your choice:-> \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:

                    addInventory();
                    k++;
                    retry();
                    break;

            case 2:
                    search();
                    retry();
                    break;

            case 3:
                    char  ch;
                    printf("Do you want to purchase or return a book? /n To purchase a book press P \n To return a book press R ");
                    scanf("%s",&ch);
                    if(ch=='P' || ch=='p'){
                        purchase_book();
                        retry();
                    }
                    else if(ch=='R' || ch=='r'){
                            return_book();
                            retry();
                    }
                     else{
                        printf("Invalid input!");
                     }
                    break;

            case 4:
                    deleteRecord();
                    retry();
                    break;

            case 5:
                    displayBooks();
                    retry();
                    break;

            case 6:
                    quit();
        }

    }while(choice<1 || choice>6);
}

void addInventory(){
    //char ans;
    printf("Enter ISBN Id:-> ");
    scanf("%d",&Library[k].ISBN);
    printf("Enter Book Name or Title:-> ");
    scanf("%s",Library[k].Title);
    printf("Enter Author name:--> ");
    scanf("%s",Library[k].Author);
    printf("Enter Book's Publisher's name:--> ");;
    scanf("%s",Library[k].Publisher);
    printf("Enter the type or Genre of book:--> ");
    scanf("%s",Library[k].Genre);
    printf("Enter the Year of release or publication of book:--> ");
    scanf("%d",&Library[k].Year);
    printf("Enter the quantity of book you want to add to Stock:--> ");
    scanf("%d",&Library[k].Stock);
    printf("Enter the Selling Price of book --> ");
    scanf("%f",&Library[k].Price);
    printf("\nBook record added successfully");
   /* printf("\nDo you want to go to the main menu again(Y/N)?");
    scanf("%s",&ans);
    if(ans=='Y' || ans=='y'){
        createMenu();
    }
    else{
        quit();
    }*/

}

void search(){
    char sch[50];
    printf("Please enter the book Title, author or the publisher name to search a book in the system:--> ");
    scanf("%s",&sch);

    for(int j=0;j<k;j++){
        if(strcmp(Library[j].Title,sch) ||
           strcmp(Library[j].Publisher,sch) ||
           strcmp(Library[j].Author,sch)){
               // display_book(j);
               printf("ISBN:--> %d\n",Library[j].ISBN);
               printf("Title:--> %s\n",Library[j].Title);
               printf("Author name:--> %s\n",Library[j].Author);
               printf("Publisher name:--> %s\n",Library[j].Publisher);
               printf("Genre:--> %s\n",Library[j].Genre);
               printf("Year of publication:--> %d\n",Library[j].Year);
               printf("Stock:--> %d\n",Library[j].Stock);
               printf("Price:--> %f\n",Library[j].Price);
               }
               else{
                    printf("\nSorry the Book you are trying to search was not found in the System");
                }
    }

}

void purchase_book(){
   // int j;
    char pbook[50];
    //bool x= false;
    printf("\nPlease enter the book Title, author or the publisher name to search a book in the system:--> ");
    scanf("%s",&pbook);
    for(int j=0;j<k;j++){
        if(strcmp(Library[j].Title,pbook) ||
           strcmp(Library[j].Author,pbook) ||
           strcmp(Library[j].Publisher,pbook)){

                    Library[j].Stock=Library[j].Stock--;
                    displayBooks();
        }
        else{
                printf("\nSorry the Book you are trying to search was not found in the library");
        }
    }
}

void return_book(){
    char rbook[50];
    bool y= false;
    int j;
    printf("\nPlease enter the book Title, author or the publisher name to search a book in the system:--> ");
    scanf("%s",&rbook);
    for(j=0;j<k;j++){
        if (strcmp(Library[j].Title,rbook) ||
           strcmp(Library[j].Author,rbook) ||
           strcmp(Library[j].Publisher,rbook)){

               Library[j].Stock=Library[j].Stock++;
                displayBooks();
        }
        else{
                printf("\nSorry the Book you are trying to search was not found in the System");
        }
    }
}

void deleteRecord(){
    int id;
    bool check=false;
    printf("To delete a book from the Library, enter the ISBN number of the book --> ");
    scanf("%d",&id);
    for(int i=0;i<k;i++){
                Library[i]=Library[i+1];
        }
    }


void displayBooks(){
    printf("*************************************************\n");
    for(int i=0;i<k;i++){
        printf("ISBN:--> %d\n",Library[i].ISBN);
        printf("Title:--> %s\n",Library[i].Title);
        printf("Author name:--> %s\n",Library[i].Author);
        printf("Publisher name:--> %s\n",Library[i].Publisher);
        printf("Genre:--> %s\n",Library[i].Genre);
        printf("Year of publication:--> %d\n",Library[i].Year);
        printf("Stock:--> %d\n",Library[i].Stock);
        printf("Price:--> %f\n",Library[i].Price);
        printf("***************************************************\n");
    }
}

void retry(){
      int flag;
     printf("\nDo you want to enter the main menu again? \nPress 1 for menu and 0 to exit the program");
     scanf("%d",&flag);
     if(flag=1)
        createMenu();
    else{
            quit();
    }

}

void quit(){
    exit(0);
}

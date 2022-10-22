/* Exercise Instructions

Write a program able to:
• Create a class Book with following members: Title, Year, Author, Editor
• Load a Book type Array[N] //this means N books
• The user will load the Book Array elements members (title, year, author, editor per each book)
• The program will show all the books loaded
• The program will ask the user to enter a specific year and a specific author
• The program will show all books written by that author and all books written in that year

Use the following functions:
void loadBook(Book px[], int pn);
void showBooks(Book px[],
int pn);void findAuthor(Book px[], int pn, string pauthor);
void findYear(Book px[], int pn, int pyear);

*/
#include <iostream>

using namespace std; 

class book
{

public:
    string bookName;
    string bookAut;
    int bookYear;
    string bookPub;
};

void loadBook(book px[], int pn)
{

    for(int i=0; i<pn; i++)
    {
        cout<<"Enter the title of the book:   ";
        cin>>px[i].bookName;
        cout<<"Enter the author of the book:   ";
        cin>>px[i].bookAut;
        cout<<"Enter the year the book was published:   ";
        cin>>px[i].bookYear;
        cout<<"Enter the publisher of the book:   ";
        cin>>px[i].bookPub;

    }

}

    void showBook(book px[], int pn) {

        for(int i =0; i<pn;i++){
            cout<<"-------------------------"<<endl; 
            cout<<px[i].bookName<<endl; 
            cout<<px[i].bookAut<<endl; 
            cout<<px[i].bookYear<<endl; 
            cout<<px[i].bookPub<<endl; 
            cout<<"-------------------------"<<endl; 
        }


    }
    void findAuthor(book px[], int pn, string pauthor)
    {
        for(int i = 0; i < pn; i++)
        {
            if(pauthor == px[i].bookAut)
            {

                cout << px[i].bookName << endl;
            };
        };
    }


    void findYear(book px[], int pn, int pyear)
    {
          for(int i = 0; i < pn; i++)
          {
            if(pyear == px[i].bookYear)
            {
                cout << "Book titles by this author: "<< endl << px[i].bookName << endl;
            };


        };
    }




int main(){
    int *p; 
    int pn = 1; 
    book books[pn]; // initialize an object of books which works as an array
    int c;
    string author; 
    int year;
    
    // initialize a do-while loop to simulate a menu
    do{
        cout << "\n1. Upload a book! \n2. Search for a book by author\n3. Search for a book by year\n4. Show all books." << endl;
        cout << "Enter 0 to exit the library." << endl; 
        cin>>c;
        switch (c) {
            case 1: 
            loadBook(books,pn);
            break;

            case 2: 
            showBook(books,pn);
            break;

            case 3: 
            cout<<"Which author would you like to look up? ";
            cin>>author; 
            findAuthor(books,pn,author);
            break;

            case 4: 
            cin>>year;
            findYear(books,pn, year);
            break;
        
            default:
            cout<<"Invalid choice";
            break;
        };
        
    } while(c != 0);
   
    cout<<"Exiting...";
    return 0; 
    }

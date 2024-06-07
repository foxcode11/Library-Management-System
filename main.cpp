#include<bits/stdc++.h>
using namespace std;
static int counter=0;
class Book{
  private:
   string isbn,title,author,edition,publication;
  public:
  Book(){};
  Book(string i,string t,string a,string e,string p){
    isbn=i;
    title=t;
    author=a;
    edition=e;
    publication=p;
  }
  void display(){
    cout<<"ISBN: "<<isbn<<endl;
    cout<<"TITLE: "<<title<<endl;
    cout<<"AUTHOR: "<<author<<endl;
    cout<<"EDITION: "<<edition<<endl;
    cout<<"PUBLICATION: "<<publication<<endl;
  }
  string getIsbn(){ return isbn;}
  string getTitle(){ return title;}
  string getAuthor(){ return author;}
  string getEdition(){ return edition;}
  string getPublication(){ return publication;}
  void setIsbn(){
     string isbn;
     cout<<"\nEnter the ISBN: ";
     getline(cin,isbn);
     fflush(stdin);
     this->isbn=isbn;
  }
  void setTitle(){ 
    string title;
    cout<<"\nEnter the Title: ";
    getline(cin,title);
    fflush(stdin);
    this->title=title;
  }
  void setAuthor(){
    string author;
    cout<<"\nEnter the Author: ";
    getline(cin,author);
    fflush(stdin);
    this->author=author;    
  }
  void setEdition(){
    string edition;
    cout<<"\nEnter the Edition: ";
    getline(cin,edition);
    fflush(stdin);
    this->edition=edition;
  }
  void setPublication(){ 
    string publication;
    cout<<"\nEnter the Publication: ";
    getline(cin,publication);
    fflush(stdin);
    this->publication=publication;
  }
};
void addBook();
void deleteBook();
void searchBook();
void editBook();
void viewAllBook();
void quit();
Book books[10];
void menu()
{
  cout<<"LIBRARY MANAGEMENT SYSTEM\n";
  cout<<"[1] : ADD BOOK\n";
  cout<<"[2] : DELETE BOOK\n";
  cout<<"[3] : EDIT BOOK\n";
  cout<<"[4] : SEARCH BOOK\n";
  cout<<"[5] : VIEW ALL BOOKs\n";
  cout<<"[6] : QUIT\n";
  cout<<"ENTER YOUR CHOICE\n";
  int choice;
  cin>>choice;
  fflush(stdin);
  switch(choice)
  {
    case 1:addBook();
    break;
    case 2:deleteBook();
    break;
    case 3:editBook();
    break;
    case 4:searchBook();
    break;
    case 5:viewAllBook();
    break;
    case 6:quit();
    break;
    default: cout<<"Invalid Input";
  }
}
int main()
{
  menu();
  return 0;
}
void addBook(){
  string isbn,title,author,edition,publication;
  int n=1;
  cout<<"Add Book:"<<endl;
  while(n)
  {
    if(counter<10)
    {
      Book Books[counter];
      cout<<"Enter ISBN: ";
      cin>>isbn;
      fflush(stdin);
      cout<<"Enter Title: ";
      getline(cin,title);
      fflush(stdin);
      cout<<"Enter Author: ";
      getline(cin,author);
      fflush(stdin);
      cout<<"Enter Edition: ";
      getline(cin,edition);
      fflush(stdin);
      cout<<"Enter Publication: ";
      getline(cin,publication);
      fflush(stdin);
      books[counter]=Book(isbn,title,author,edition,publication);
      counter++;
      cout<<"\nBOOK ADDED SUCCESSFULLY\n"<<counter<<endl;
    }
    else
    {
      cout<<"DATABASE FULL\n";
      cout<<"Press any Key to continue . . .\n";
      cin.get();
      menu();
    }
    fflush(stdin);
    cout<<"\nDo you want to add more boooks ? \n[1] for yes, [0] for no\n";
    cin>>n;
    fflush(stdin);
  }
  if(n==0)
  {
      cout<<"Press any Key to continue . . .\n";
      cin.get();
      menu();
  }
}
void deleteBook(){
  cout<<"Delete Book:"<<endl;
  if(counter<=0)
  {
    cout<<"\nNO BOOK IS AVAILABLE !\n";
  }
  else
  {
    string isbn;
    int temp=1;
    cout<<"\nEnter ISBN of the book you want to delete: ";
    getline(cin,isbn);
    for(int i=0;i<counter;i++)
    {
      if(books[i].getIsbn()==isbn)
      {
        cout<<"\nBOOK FOUND\n";
        for(int j=i;j<counter;j++)
        {
          books[j]=books[j+1];
        }
        counter--;
        cout<<"\nBOOK DELETED SUCCESSFULLY\n";
        temp=0;
      }
    }
    if(temp)
      cout<<"\nBOOK NOT FOUND !!\n";
    cout<<"\nPress any key to continue . . .\n";
    cin.get();
    menu();
  }
}
void editBook(){
  cout<<"\nEdit Book:"<<endl;
  string isbn;
  int temp=1;
  cout<<"Enter the ISBN: ";
  getline(cin,isbn);
  fflush(stdin);
  for(int i=0;i<counter;i++)
  {
    if(books[i].getIsbn()==isbn)
    {
      cout<<"\nBOOK FOUND\nBOOK DETAILS\n";
      books[i].display();
      int c,n=1;
      temp=0;
      cout<<"[1]. Title\n[2]. Author\n[3]. Edition\n[4]. Publication\n";
      cout<<"\nChoose what you want to edit: ";
      while(n)
      {
        cin>>c;
        fflush(stdin);
        switch (c)
        {
          case 1:books[i].setTitle();
                break;
          case 2:books[i].setAuthor();
                break;
          case 3:books[i].setEdition();
                break;
          case 4:books[i].setPublication();
                break;
          default:cout<<"\nInvalid Choice\n";
        }
        cout<<"\nDo you want to continue editing? \n[1] for yes, [0] for no\n";
        cin>>n;
        fflush(stdin);
      }
    }
  }
  if(temp)
  cout<<"\nBOOK NOT FOUND !!\n";
  cout<<"\nPress any key to continue . . .\n";
  cin.get();
  menu();
}
void searchBook(){
  cout<<"Search Book:"<<endl;
  string isbn;
  getline(cin,isbn);
  fflush(stdin);
  for(int i=0;i<counter;i++)
  {
    if(books[i].getIsbn()==isbn)
    {
      cout<<"\nBOOK FOUND\nBOOK DETAILS\n";
      books[i].display();
      cout<<"\nPress any key to continue . . .\n";
      cin.get();
      menu();
      }
      }
      cout<<"\nBOOK NOT FOUND !!\n";
      cout<<"\nPress any key to continue . . .\n";
      cin.get();
      menu();
}
void viewAllBook(){
  cout<<"View All Book"<<endl;
  for(int i=0;i<counter;i++)
  {
    cout<<"\nBOOK DETAILS\n";
    books[i].display();
    cout<<"\n";
  }
  cout<<"\nPress any key to continue . . .\n";
  cin.get();
  menu();
}
void quit(){
  cout<<"Exiting Program...";
  exit(0);
};
#include<iostream>
#ifndef Library_H
#define Library_H
#include<fstream>
#define FILENAME "empFile.txt"
#define FILEname "books.txt"
#define filename "borrowrecord.txt"
using namespace std;
class book{
      public:
	  string topic;
	  string type;
	  string writer;
	  string category;
	  int state;
	  long ownerid;
	  
};
class user{
	  public:
	  long account;
	  long password;
	  void usermenu();
	  
};
class record{
	  public:
	  long ownerid;
	  string topic;
	  string writer;
	  int state;
};
class library{
	  public:
	  int booksnum;
	  int recordnum;
	  book booksarray[10000];
	  user userarray[5000];
	  record recordarray[10000];
	  
	  //user.cpp
	  void iniuser(); 
	  void save();
	  library();
	  
	  //library.cpp
	  void zongmenu();
	  void checkmenu();
	  void signmenu();
	  void xinxitypemenu();
	  
	  
	  
	  //books.cpp
	  int getbooksnum();
	  void inibooks();
	  void booksave();
	  void showbook(book Book);
	  void search();
	  void borrowbook(long);
	  void givebook(long); 
	  
	  //borrowrecord.cpp
	  void borrowrecord();
	  void recordsave(book);
	  void inirecord();
	  int getrecordnum();
	   
};

//new
class administrator{
	  public:
	  long account;
	  long password;
	  void administratormenu();
};
//new	  
	  

#endif

#include<iostream>
#ifndef Library_H
#define Library_H
#include<fstream>
#define FILENAME "empFile.txt"
#define FILEname "books.txt"
#define filename "borrowrecord.txt"
#define a_acount "adminaccount.txt"
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
	  string password;
	  void usermenu();
	  
};

class administrator{
	  public:
	  long account;
	  string password;
	  void administratormenu();
	  void manage_accountmenu();
	  void modify_bookmenu(); 
	  void account_management();
	  
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
	  administrator adminarray[50];
	  record recordarray[10000];
	  
	  //user.cpp
	  void iniuser(); 
	  void save();
	  library();
	  void iniadmin();
	  
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
	  
	  //login_check
	  int login_user(int account,string password); 
	  int login_admin(int account,string password);
	  
	  //admin.h
	  void admin_save();
	  void admin_out();
	   
};

  
#endif

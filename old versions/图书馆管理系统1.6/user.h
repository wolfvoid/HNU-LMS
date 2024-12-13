#include"library.h"
using namespace std;

void library::save() {//写文件 
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件--写文件 
	//将每个人的数据写入到文件中
	for (int i = 0; i < usernum; i++) {
		ofs << userarray[i].account << " "
			<< userarray[i].password << endl;
	}
	ofs.close();
}

void library::iniuser(){//读文件 
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	long account1;
	string password1;
	int i = 0;
	while (ifs >> account1 && ifs >> password1) {
		userarray[i].account = account1;
		userarray[i].password = password1;
	i++; 
	}
	usernum=i;
	ifs.close();
	return;
}

library::library()//构造函数
{  
    booksnum=getbooksnum();
    recordnum=getrecordnum(); 
//1、文件不存在 
  int flag=0;
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  
if(!ifs.is_open()){
	flag++;
  cout<<"文件不存在"<<endl;
  usernum=5000;
  for(int i=0;i<usernum;i++){
  long temp=20210000;
  userarray[i].account=temp+i;
  userarray[i].password="123456";
  }
  ifs.close();
  this->save(); 
}

 ifstream ifs2; 
  ifs2.open(a_acount,ios::in);
if(!ifs2.is_open()){
	flag++;
  cout<<"文件不存在"<<endl;
  for(int i=0;i<50;i++){
  long temp=0;
  adminarray[i].account=temp+i;
  adminarray[i].password="123456";
  }
  ifs2.close();
  this->admin_save(); 
}
if(flag==2) return;

////文件存在且数据为空 
//char ch;
//ifs>>ch; 
//if(ifs.eof()){
//cout<<"文件为空"<<endl;
//for(int i=0;i<5000;i++){
//  long temp=20210000;
//  userarray[i].account=temp+i;
//  userarray[i].password="123456";
//  }
//this->save(); 
//ifs.close();}

//3.文件存在，并且记录数据
cout<<"读取文件"<<endl;
this->iniuser();
this->inibooks();
this->inirecord();
this->iniadmin();

}

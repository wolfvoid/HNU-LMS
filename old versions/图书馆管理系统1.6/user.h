#include"library.h"
using namespace std;

void library::save() {//д�ļ� 
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < usernum; i++) {
		ofs << userarray[i].account << " "
			<< userarray[i].password << endl;
	}
	ofs.close();
}

void library::iniuser(){//���ļ� 
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

library::library()//���캯��
{  
    booksnum=getbooksnum();
    recordnum=getrecordnum(); 
//1���ļ������� 
  int flag=0;
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  
if(!ifs.is_open()){
	flag++;
  cout<<"�ļ�������"<<endl;
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
  cout<<"�ļ�������"<<endl;
  for(int i=0;i<50;i++){
  long temp=0;
  adminarray[i].account=temp+i;
  adminarray[i].password="123456";
  }
  ifs2.close();
  this->admin_save(); 
}
if(flag==2) return;

////�ļ�����������Ϊ�� 
//char ch;
//ifs>>ch; 
//if(ifs.eof()){
//cout<<"�ļ�Ϊ��"<<endl;
//for(int i=0;i<5000;i++){
//  long temp=20210000;
//  userarray[i].account=temp+i;
//  userarray[i].password="123456";
//  }
//this->save(); 
//ifs.close();}

//3.�ļ����ڣ����Ҽ�¼����
cout<<"��ȡ�ļ�"<<endl;
this->iniuser();
this->inibooks();
this->inirecord();
this->iniadmin();

}

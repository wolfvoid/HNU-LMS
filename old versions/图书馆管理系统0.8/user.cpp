#include"library.h"
using namespace std;

void library::save() {//д�ļ� 
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < 5000; i++) {
		ofs << userarray[i].account << " "
			<< userarray[i].password << endl;
	}
	ofs.close();
}
 void library::iniuser(){//���ļ� 
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	long account1;
	long password1;
	int i = 0;
	while (ifs >> account1 && ifs >> password1) {
		userarray[i].account = account1;
		userarray[i].password = password1;
	i++; 
	}
	ifs.close();
	return;
}
library::library()//���캯��
{  
    booksnum=getbooksnum();
    recordnum=getrecordnum(); 
/*	//1���ļ������� 
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  if(!ifs.is_open()){
  cout<<"�ļ�������"<<endl;
  for(int i=0;i<5000;i++){
  long temp=20210000;
  userarray[i].account=temp+i;
  userarray[i].password=123456;
  }
  this->save(); 
  ifs.close();
return;
}
//�ļ�����������Ϊ��
char ch;
ifs>>ch; 
if(ifs.eof()){
cout<<"�ļ�Ϊ��"<<endl;
for(int i=0;i<5000;i++){
  long temp=20210000;
  userarray[i].account=temp+i;
  userarray[i].password=123456;
  }
this->save(); 
ifs.close();
return;
} */
//3.�ļ����ڣ����Ҽ�¼����
cout<<"��ȡ�ļ�"<<endl;
this->iniuser();
this->inibooks();
this->inirecord();
}

#include<iostream>
#include"library.h"
using namespace std;
library hnu;
int main(){
sign: hnu.signmenu(); 
    int signselect;//ѡ���¼��ʽ
	cin>>signselect;
	switch(signselect)
    {
case 1://�û�ģʽ 
    user a;
    cout<<"�������˺�:"<<endl;
    cin>>a.account;
	cout<<"����������:"<<endl;
	cin>>a.password;
if((a.account>=20210000&&a.account<=20214999)&&a.password==hnu.userarray[a.account-20210000].password){
    system("cls");
    cout<<"��¼�ɹ�"<<endl;
	long a_account=a.account-20210000;
userfunc:hnu.userarray[a_account].usermenu();
            int userselect;//ѡ���û�ģʽ���� 
            cin>>userselect;
            switch(userselect)
           {
    case 1://�޸����� 
	       system("cls");
           cout<<"������������:"<<endl;
           cin>>hnu.userarray[a_account].password;
           cout<<"��ȷ�����������:"<<endl;
           cin>>hnu.userarray[a_account].password;
           hnu.save();
           cout<<"�޸ĳɹ�"<<endl;
           system("pause");
           system("cls");
	       goto userfunc; 
	       break;
    case 2://����ͼ�� 
           hnu.search();
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 3://��ͼ�� 
           hnu.borrowbook(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 4://��ͼ�� 
           hnu.givebook(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 5://�鿴���ļ�¼ 
           hnu.borrowrecord();
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 0://�˳���¼ 
	       cout<<"��ӭ�´�ʹ��"<<endl;
    default:
	       goto userfunc;
           break;
           }
           }
else{
	system("cls");
	cout<<"�����µ�¼"<<endl; 
	goto sign;
    }
	break;
case 2://����Աģʽ //new
	administrator b;
    cout<<"�������˺�:"<<endl;
    cin>>b.account;
	cout<<"����������:"<<endl;
	cin>>b.password;
	if(1){}
    system("cls");
    cout<<"��¼�ɹ�"<<endl;
	break;//new
default:
	system("cls");
	goto sign;
	}
}



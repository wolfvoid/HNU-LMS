#include<iostream>
#include"library.h"
#include"books.h"
#include"borrowrecord.h"
#include"user.h"
#include"admin.h" 
#include"login_check.h" 
using namespace std;
library hnu;
int main(){
sign: hnu.signmenu(); 
    int signselect;//ѡ���¼��ʽ
	cin>>signselect;
    user a; 
	administrator b;
	switch(signselect)
    {
case 1://�û�ģʽ 
    cout<<"�������˺�:"<<endl;
    cin>>a.account;
	cout<<"����������:"<<endl;
	cin>>a.password;
	cin.get(); 
	//(a.account>=20210000&&a.account<=20214999)&&a.password==hnu.userarray[a.account-20210000].password
if(hnu.login_user(a.account,a.password)==1){
    system("cls");
    cout<<"��¼�ɹ�"<<endl;
	long temp_account=a.account-20210000;
userfunc:hnu.userarray[temp_account].usermenu();
            int userselect;//ѡ���û�ģʽ���� 
            cin>>userselect;
            switch(userselect)
           {
    case 1://�޸����� 
	       system("cls");
           cout<<"������������:"<<endl;
           cin>>hnu.userarray[temp_account].password;
           cout<<"��ȷ�����������:"<<endl;
           cin>>hnu.userarray[temp_account].password;
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
else if (hnu.login_user(a.account,a.password)==2){//new 
	system("cls");
	cout<<"�˺Ų����ϸ�ʽ�������µ�¼"<<endl; 
	goto sign;
    }
else if (hnu.login_user(a.account,a.password)==3){
	system("cls");
	cout<<"�˺Ż�������������µ�¼"<<endl; 
	goto sign;
    }//new
	break;
case 2://����Աģʽ 
    cout<<"�������˺�:"<<endl;
    cin>>b.account;
	cout<<"����������:"<<endl;
	cin>>b.password;
	if (hnu.login_admin(b.account,b.password)==1){}//������Ҫ������֤�������ú������㣬��txt���� 
    system("cls");
    cout<<"��¼�ɹ�"<<endl;
administrator_menu_func:
	hnu.adminarray[b.account].administratormenu();
	int adminselect;//ѡ�����Աģʽ���� 
            cin>>adminselect;
            switch(adminselect)
           {
           	case 1:
//				hnu.administratorarray[b.account].
           	case 2:
           	case 3:
           	case 4:
           	case 0:
           	default:
           		goto administrator_menu_func;
           		break;
		   }
	break;
default:
	system("cls");
	goto sign;
	}
}



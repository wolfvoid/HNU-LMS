#include<iostream>
#include"library.h"
#include"books.h"
#include"borrowrecord.h"
#include"user.h"
#include"admin.h" 
#include"login_check.h" 
#include"showlist.h"
#include <windows.h>
using namespace std;
void colour(int x)
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,x);	
} 
library hnu;
int main(){
	colour(11); 
sign: //��¼���� 
	hnu.signmenu(); 
    int signselect;//ѡ���¼��ʽ
	cin>>signselect;
    user a; 
	administrator b;
	string tempstr1,tempstr2; 
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
userfunc:
			hnu.userarray[temp_account].usermenu();
            int userselect;//ѡ���û�ģʽ���� 
            cin>>userselect;
            switch(userselect)
           {
    case 1://�޸����� 
    	again:
	       system("cls");
           cout<<"������������:"<<endl;
           cin>>tempstr1;
           cout<<"��ȷ�����������:"<<endl;
           cin>>tempstr2;
           if (tempstr1==tempstr2)
           {
           	hnu.userarray[temp_account].password=tempstr1;
		   }
		   else goto again;
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
           hnu.userborrowrecord(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 0://�˳���¼ 
    			cout<<"�Ƿ�ȷ���˳���"<<endl;
           		cout<<"0��ȡ��   1��ȷ��"<<endl;
           		int temp4;
				cin>>temp4;
				if (temp4==1)
				{
					cout<<"�˳���¼�ɹ����������ص�¼����"<<endl; 
					cout<<"��ӭ�´�ʹ��"<<endl;
					system("pause"); 
           			system("cls");
           			goto sign;//���ص�¼���� 
				}
				else
				{
					cout<<"��ȡ��������������һ������"<<endl; 
					system("pause"); 
           			system("cls");
					goto userfunc;//���صڶ���Ŀ¼
				}
           		break; 
    default:
	       goto userfunc;
           break;
           }
           }
else if (hnu.login_user(a.account,a.password)==2){
	system("cls");
	cout<<"�˺Ų����ϸ�ʽ�������µ�¼"<<endl; 
	goto sign;//���ص�½���� 
    }
else if (hnu.login_user(a.account,a.password)==3){
	system("cls");
	cout<<"�˺Ż�������������µ�¼"<<endl; 
	goto sign;//���ص�½���� 
    }
	break;
case 2://����Աģʽ 
    cout<<"�������˺�:"<<endl;
    cin>>b.account;
	cout<<"����������:"<<endl;
	cin>>b.password;
	if (hnu.login_admin(b.account,b.password)==1)
	{ 
    system("cls");
    cout<<"��¼�ɹ�"<<endl;
administrator_menu_func://��һ��Ŀ¼ 
	hnu.adminarray[b.account].administratormenu();
	int adminselect;//ѡ�����Աģʽ���� 
            cin>>adminselect;
            system("cls");
            switch(adminselect)
           {
           	case 1:
           		accountmenufunc://�ڶ���Ŀ¼
				hnu.adminarray[b.account].manage_accountmenu();
				int temp;
				cin>>temp;
				switch(temp) 
				{
					case 1:
						hnu.addaccount();
						system("pause");
						system("cls");
						goto accountmenufunc;//���صڶ���Ŀ¼ 
						break;
					case 2:
						hnu.deleteaccount();
						system("pause");
						system("cls");
						goto accountmenufunc;//���صڶ���Ŀ¼ 
						break;
					case 3:
						hnu.modifypassword();
						system("pause");
						system("cls");
						goto accountmenufunc;//���صڶ���Ŀ¼ 
						break;
					case 4:
						hnu.resetpassword();
						system("pause");
						system("cls");
						goto accountmenufunc;//���صڶ���Ŀ¼ 
						break;
					case 0:
						cout<<"���������ϼ�Ŀ¼"<<endl;
						system("pause"); 
						system("cls");
						goto administrator_menu_func;//���ص�һ��Ŀ¼ 
						break;
					default:
						cout<<"�����ʽ��������������"<<endl;
						system("pause"); 
						system("cls");
						goto accountmenufunc;//���صڶ���Ŀ¼ 
						break;
				}
				break; 
           	case 2:
           		bookmanagement://�ڶ���Ŀ¼
				hnu.adminarray[b.account].book_management_menu();
				int temp5;
				cin>>temp5;
           		switch(temp5) 
				{
					case 1:
						hnu.addbook();
						system("pause");
						system("cls");
						goto bookmanagement;//���صڶ���Ŀ¼ 
						break;
					case 2:
						hnu.deletebook();
						system("pause");
						system("cls");
						goto bookmanagement;//���صڶ���Ŀ¼ 
						break;
					case 3:
						hnu.modifybook();
						system("pause");
						system("cls");
						goto bookmanagement;//���صڶ���Ŀ¼ 
						break; 
					case 0:
						cout<<"���������ϼ�Ŀ¼"<<endl;
						system("pause"); 
						system("cls");
						goto administrator_menu_func;//���ص�һ��Ŀ¼ 
						break;
					default:
						cout<<"�����ʽ��������������"<<endl;
						system("pause"); 
						system("cls");
						goto bookmanagement;//���صڶ���Ŀ¼ 
						break;
				}
				break; 
           	case 3:
           		hnu.search();
           		system("pause");
           		system("cls");
           		goto administrator_menu_func;//���ص�һ��Ŀ¼ 
           		break;
           	case 4:
           		hnu.allborrowrecord();
           		break;
           	case 5:
           		hnu.showbooklist();
           		system("pause");
           		system("cls");
           		goto administrator_menu_func;//���ص�һ��Ŀ¼ 
           		break;
			case 6:
				hnu.showuserlist();
				system("pause");
				system("cls");
           		goto administrator_menu_func;//���ص�һ��Ŀ¼ 
				break;
           	case 0:
           		cout<<"�Ƿ�ȷ���˳���"<<endl;
           		cout<<"0��ȡ��   1��ȷ��"<<endl;
           		int temp3;
				cin>>temp3;
				if (temp3==1)
				{
					cout<<"�˳���¼�ɹ����������ص�¼����"<<endl; 
					system("pause"); 
           			system("cls");
           			goto sign;//���ص�¼���� 
				}
				else
				{
					cout<<"��ȡ�������������ϼ�Ŀ¼"<<endl; 
					system("pause"); 
           			system("cls");
					goto accountmenufunc;//���صڶ���Ŀ¼
				}
           		break; 
           	default:
           			cout<<"�����ʽ��������������"<<endl;
					system("pause"); 
					system("cls");
					goto administrator_menu_func;//���ص�һ��Ŀ¼ 
		   }
	}
	else if (hnu.login_admin(b.account,b.password)==2)
	{
		system("cls");
		cout<<"�˺Ų����ϸ�ʽ�������µ�¼"<<endl; 
		goto sign;//���ص�½���� 
	}
	else if (hnu.login_admin(b.account,b.password)==3)
	{
		system("cls");
		cout<<"�˺Ż�������������µ�¼"<<endl; 
		goto sign;//���ص�½���� 
	}
	break;
case 0:
	system("cls");
	hnu.developerinfor();
	system("pause");
	cout<<"���������ϼ�Ŀ¼"<<endl;
	system("pause");
	system("cls");
	goto sign;//���ص�½����
default:
	cout<<"�����ʽ��������������"<<endl;
	system("pause"); 
	system("cls");
	goto sign;//���ص�½���� 
	}
}

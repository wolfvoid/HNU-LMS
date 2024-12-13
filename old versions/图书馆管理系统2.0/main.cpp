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
sign: //登录界面 
	hnu.signmenu(); 
    int signselect;//选择登录方式
	cin>>signselect;
    user a; 
	administrator b;
	string tempstr1,tempstr2; 
	switch(signselect)
    {
case 1://用户模式 
    cout<<"请输入账号:"<<endl;
    cin>>a.account;
	cout<<"请输入密码:"<<endl;
	cin>>a.password;
	cin.get(); 
	//(a.account>=20210000&&a.account<=20214999)&&a.password==hnu.userarray[a.account-20210000].password
if(hnu.login_user(a.account,a.password)==1){
    system("cls");
    cout<<"登录成功"<<endl;
	long temp_account=a.account-20210000;
userfunc:
			hnu.userarray[temp_account].usermenu();
            int userselect;//选择用户模式功能 
            cin>>userselect;
            switch(userselect)
           {
    case 1://修改密码 
    	again:
	       system("cls");
           cout<<"请输入新密码:"<<endl;
           cin>>tempstr1;
           cout<<"请确认你的新密码:"<<endl;
           cin>>tempstr2;
           if (tempstr1==tempstr2)
           {
           	hnu.userarray[temp_account].password=tempstr1;
		   }
		   else goto again;
           hnu.save();
           cout<<"修改成功"<<endl;
           system("pause");
           system("cls");
	       goto userfunc; 
	       break;
    case 2://搜索图书 
           hnu.search();
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 3://借图书 
           hnu.borrowbook(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 4://还图书 
           hnu.givebook(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 5://查看借阅记录 
           hnu.userborrowrecord(a.account);
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 0://退出登录 
    			cout<<"是否确认退出？"<<endl;
           		cout<<"0：取消   1：确认"<<endl;
           		int temp4;
				cin>>temp4;
				if (temp4==1)
				{
					cout<<"退出登录成功，即将返回登录界面"<<endl; 
					cout<<"欢迎下次使用"<<endl;
					system("pause"); 
           			system("cls");
           			goto sign;//返回登录界面 
				}
				else
				{
					cout<<"已取消，即将返回上一级界面"<<endl; 
					system("pause"); 
           			system("cls");
					goto userfunc;//返回第二级目录
				}
           		break; 
    default:
	       goto userfunc;
           break;
           }
           }
else if (hnu.login_user(a.account,a.password)==2){
	system("cls");
	cout<<"账号不符合格式，请重新登录"<<endl; 
	goto sign;//返回登陆界面 
    }
else if (hnu.login_user(a.account,a.password)==3){
	system("cls");
	cout<<"账号或密码错误，请重新登录"<<endl; 
	goto sign;//返回登陆界面 
    }
	break;
case 2://管理员模式 
    cout<<"请输入账号:"<<endl;
    cin>>b.account;
	cout<<"请输入密码:"<<endl;
	cin>>b.password;
	if (hnu.login_admin(b.account,b.password)==1)
	{ 
    system("cls");
    cout<<"登录成功"<<endl;
administrator_menu_func://第一级目录 
	hnu.adminarray[b.account].administratormenu();
	int adminselect;//选择管理员模式功能 
            cin>>adminselect;
            system("cls");
            switch(adminselect)
           {
           	case 1:
           		accountmenufunc://第二级目录
				hnu.adminarray[b.account].manage_accountmenu();
				int temp;
				cin>>temp;
				switch(temp) 
				{
					case 1:
						hnu.addaccount();
						system("pause");
						system("cls");
						goto accountmenufunc;//返回第二级目录 
						break;
					case 2:
						hnu.deleteaccount();
						system("pause");
						system("cls");
						goto accountmenufunc;//返回第二级目录 
						break;
					case 3:
						hnu.modifypassword();
						system("pause");
						system("cls");
						goto accountmenufunc;//返回第二级目录 
						break;
					case 4:
						hnu.resetpassword();
						system("pause");
						system("cls");
						goto accountmenufunc;//返回第二级目录 
						break;
					case 0:
						cout<<"即将返回上级目录"<<endl;
						system("pause"); 
						system("cls");
						goto administrator_menu_func;//返回第一级目录 
						break;
					default:
						cout<<"输入格式错误，请重新输入"<<endl;
						system("pause"); 
						system("cls");
						goto accountmenufunc;//返回第二级目录 
						break;
				}
				break; 
           	case 2:
           		bookmanagement://第二级目录
				hnu.adminarray[b.account].book_management_menu();
				int temp5;
				cin>>temp5;
           		switch(temp5) 
				{
					case 1:
						hnu.addbook();
						system("pause");
						system("cls");
						goto bookmanagement;//返回第二级目录 
						break;
					case 2:
						hnu.deletebook();
						system("pause");
						system("cls");
						goto bookmanagement;//返回第二级目录 
						break;
					case 3:
						hnu.modifybook();
						system("pause");
						system("cls");
						goto bookmanagement;//返回第二级目录 
						break; 
					case 0:
						cout<<"即将返回上级目录"<<endl;
						system("pause"); 
						system("cls");
						goto administrator_menu_func;//返回第一级目录 
						break;
					default:
						cout<<"输入格式错误，请重新输入"<<endl;
						system("pause"); 
						system("cls");
						goto bookmanagement;//返回第二级目录 
						break;
				}
				break; 
           	case 3:
           		hnu.search();
           		system("pause");
           		system("cls");
           		goto administrator_menu_func;//返回第一级目录 
           		break;
           	case 4:
           		hnu.allborrowrecord();
           		break;
           	case 5:
           		hnu.showbooklist();
           		system("pause");
           		system("cls");
           		goto administrator_menu_func;//返回第一级目录 
           		break;
			case 6:
				hnu.showuserlist();
				system("pause");
				system("cls");
           		goto administrator_menu_func;//返回第一级目录 
				break;
           	case 0:
           		cout<<"是否确认退出？"<<endl;
           		cout<<"0：取消   1：确认"<<endl;
           		int temp3;
				cin>>temp3;
				if (temp3==1)
				{
					cout<<"退出登录成功，即将返回登录界面"<<endl; 
					system("pause"); 
           			system("cls");
           			goto sign;//返回登录界面 
				}
				else
				{
					cout<<"已取消，即将返回上级目录"<<endl; 
					system("pause"); 
           			system("cls");
					goto accountmenufunc;//返回第二级目录
				}
           		break; 
           	default:
           			cout<<"输入格式错误，请重新输入"<<endl;
					system("pause"); 
					system("cls");
					goto administrator_menu_func;//返回第一级目录 
		   }
	}
	else if (hnu.login_admin(b.account,b.password)==2)
	{
		system("cls");
		cout<<"账号不符合格式，请重新登录"<<endl; 
		goto sign;//返回登陆界面 
	}
	else if (hnu.login_admin(b.account,b.password)==3)
	{
		system("cls");
		cout<<"账号或密码错误，请重新登录"<<endl; 
		goto sign;//返回登陆界面 
	}
	break;
case 0:
	system("cls");
	hnu.developerinfor();
	system("pause");
	cout<<"即将返回上级目录"<<endl;
	system("pause");
	system("cls");
	goto sign;//返回登陆界面
default:
	cout<<"输入格式错误，请重新输入"<<endl;
	system("pause"); 
	system("cls");
	goto sign;//返回登陆界面 
	}
}

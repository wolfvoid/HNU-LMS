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
    int signselect;//选择登录方式
	cin>>signselect;
    user a; 
	administrator b;
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
userfunc:hnu.userarray[temp_account].usermenu();
            int userselect;//选择用户模式功能 
            cin>>userselect;
            switch(userselect)
           {
    case 1://修改密码 
	       system("cls");
           cout<<"请输入新密码:"<<endl;
           cin>>hnu.userarray[temp_account].password;
           cout<<"请确认你的新密码:"<<endl;
           cin>>hnu.userarray[temp_account].password;
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
           hnu.borrowrecord();
           system("pause");
           system("cls");
           goto userfunc;
	       break;
    case 0://退出登录 
	       cout<<"欢迎下次使用"<<endl;
    default:
	       goto userfunc;
           break;
           }
           }
else if (hnu.login_user(a.account,a.password)==2){
	system("cls");
	cout<<"账号不符合格式，请重新登录"<<endl; 
	goto sign;
    }
else if (hnu.login_user(a.account,a.password)==3){
	system("cls");
	cout<<"账号或密码错误，请重新登录"<<endl; 
	goto sign;
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
administrator_menu_func:
	hnu.adminarray[b.account].administratormenu();
	int adminselect;//选择管理员模式功能 
            cin>>adminselect;
            system("cls");
            switch(adminselect)//第一级目录 
           {
           	case 1:
           		accountmenufunc:
				hnu.adminarray[b.account].manage_accountmenu();
				int temp;
				cin>>temp;
				switch(temp)//第二级目录 
				{
					case 1:
						hnu.addaccount();
						system("pause");
						system("cls");
						goto administrator_menu_func;
						break;
					case 2:
						hnu.deleteaccount();
						system("pause");
						system("cls");
						goto administrator_menu_func;
						break;
					case 3:
						hnu.modifypassword();
						system("pause");
						system("cls");
						goto administrator_menu_func;
						break;
					case 4:
						hnu.resetpassword();
						system("pause");
						system("cls");
						goto administrator_menu_func;
						break;
					case 0:
						system("cls");
						goto administrator_menu_func;
						break;
					default:
						break;
				}
				break; 
           	case 2:
           		break;
           	case 3:
           		break;
           	case 4:
           		break;
           	case 0:
           		system("cls");
           		goto administrator_menu_func;
           		break; 
           	default:
           		break;
		   }
	}
	else if (hnu.login_admin(b.account,b.password)==2)
	{
		system("cls");
		cout<<"账号不符合格式，请重新登录"<<endl; 
		goto sign;
	}
	else if (hnu.login_admin(b.account,b.password)==3)
	{
		system("cls");
		cout<<"账号或密码错误，请重新登录"<<endl; 
		goto sign;
	}
	break;
default:
	system("cls");
	goto sign;
	}
}

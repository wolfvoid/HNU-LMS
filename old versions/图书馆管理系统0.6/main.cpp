#include<iostream>
#include"library.h"
using namespace std;
library hnu;
int main(){
sign: hnu.signmenu(); 
    int signselect;//选择登录方式
	cin>>signselect;
	switch(signselect)
    {
case 1://用户模式 
    user a;
    cout<<"请输入账号:"<<endl;
    cin>>a.account;
	cout<<"请输入密码:"<<endl;
	cin>>a.password;
if((a.account>=20210000&&a.account<=20214999)&&a.password==hnu.userarray[a.account-20210000].password){
    system("cls");
    cout<<"登录成功"<<endl;
	long a_account=a.account-20210000;
userfunc:hnu.userarray[a_account].usermenu();
            int userselect;//选择用户模式功能 
            cin>>userselect;
            switch(userselect)
           {
    case 1://修改密码 
	       system("cls");
           cout<<"请输入新密码:"<<endl;
           cin>>hnu.userarray[a_account].password;
           cout<<"请确认你的新密码:"<<endl;
           cin>>hnu.userarray[a_account].password;
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
else{
	system("cls");
	cout<<"请重新登录"<<endl; 
	goto sign;
    }
	break;
case 2://管理员模式 //new
	administrator b;
    cout<<"请输入账号:"<<endl;
    cin>>b.account;
	cout<<"请输入密码:"<<endl;
	cin>>b.password;
	if(1){}
    system("cls");
    cout<<"登录成功"<<endl;
	break;//new
default:
	system("cls");
	goto sign;
	}
}



#include "library.h"
#include <iostream>
using namespace std;

int library::login_user(int account, string password) // 用户登录处理
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	long account1;
	string password1;
	while (ifs >> account1 && ifs >> password1)
	{
		if (account1 == account)
		{
			if (password1 == password)
			{
				return 1; /*账号、密码正确*/
			}
			else
			{
				return 3; /*账号正确，但密码错误*/
			}
		}
	}
	return 2; /*账号格式错误*/
	ifs.close();
	return 0;
}

int library::login_admin(int account, string password) // 管理员登录处理
{
	ifstream ifs;
	ifs.open(a_acount, ios::in);
	long account1;
	string password1;
	while (ifs >> account1 && ifs >> password1)
	{
		if (account1 == account)
		{
			if (password1 == password)
			{
				return 1; /*账号、密码正确*/
			}
			else
			{
				return 3; /*账号正确，但密码错误*/
			}
		}
	}
	return 2; /*账号格式错误*/
	ifs.close();
	return 0;
}

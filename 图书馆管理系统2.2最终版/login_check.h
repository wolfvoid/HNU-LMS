#include<iostream>
#include"library.h"
using namespace std;

int library::login_user(int account,string password)//�û���¼���� 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	long account1;
	string password1;
	while (ifs >> account1 && ifs >> password1) {
		if (account1==account)
		{
			if (password1==password) {return 1;/*�˺š�������ȷ*/ }
			else {return 3;/*�˺���ȷ�����������*/ }
		}
	}
	return 2; /*�˺Ÿ�ʽ����*/ 
	ifs.close();
}
	
int library::login_admin(int account,string password)//����Ա��¼���� 
{
	ifstream ifs;
	ifs.open(a_acount, ios::in);
	long account1;
	string password1;
	while (ifs >> account1 && ifs >> password1) {
		if (account1==account)
		{
			if (password1==password) {return 1;/*�˺š�������ȷ*/ }
			else {return 3;/*�˺���ȷ�����������*/ }
		}
	}
	return 2; /*�˺Ÿ�ʽ����*/ 
	ifs.close();
}

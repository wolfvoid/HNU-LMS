#include"library.h"
using namespace std;

void library::showbooklist()//����ԱȨ�ޣ���չʾ�����鼮��Ϣ 
{
	for (int i=0;i<=booksnum;i++)
	{
		book Book;
		Book=booksarray[i];
		if (Book.topic!="") 
		{
			cout<<"�����������"<<Book.topic<<endl;
			cout<<"  �����ISBN/ISNN��"<<Book.type<<endl;
			cout<<"  ��������ߣ�"<<Book.writer<<endl;
			cout<<"  ����ķ���ţ�"<<Book.category<<endl;
			if(Book.state==1) cout<<"  ����Ľ���״����δ���"<<endl; 
			else if(Book.state==0){	 
			cout<<"  ����Ľ���״�����ѽ��"<<endl;
			cout<<"  ����Ľ����ߣ�"<<Book.ownerid<<endl;
		}
	}
	}
	return;
}

void library::showuserlist()//����ԱȨ�ޣ���չʾ�����û���Ϣ 
{
	for (int i=0;i<=usernum;i++)
	{
		if (userarray[i].account!=0) cout<<userarray[i].account<<endl;
	}
	return;
}


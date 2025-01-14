#include "library.h"
using namespace std;

void library::showbooklist() // 管理员权限：：展示所有书籍信息
{
	for (int i = 0; i <= booksnum; i++)
	{
		book Book;
		Book = booksarray[i];
		if (Book.topic != "")
		{
			cout << "该书的题名：" << Book.topic << endl;
			cout << "  该书的ISBN/ISNN：" << Book.type << endl;
			cout << "  该书的作者：" << Book.writer << endl;
			cout << "  该书的分类号：" << Book.category << endl;
			if (Book.state == 1)
				cout << "  该书的借阅状况：未借出" << endl;
			else if (Book.state == 0)
			{
				cout << "  该书的借阅状况：已借出" << endl;
				cout << "  该书的借阅者：" << Book.ownerid << endl;
			}
		}
	}
	return;
}

void library::showuserlist() // 管理员权限：：展示所有用户信息
{
	for (int i = 0; i <= usernum; i++)
	{
		if (userarray[i].account != 0)
			cout << userarray[i].account << endl;
	}
	return;
}

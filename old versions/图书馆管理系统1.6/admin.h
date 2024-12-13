#include"library.h"
using namespace std;

void library::admin_save() {//写文件 
	ofstream ofs;
	ofs.open(a_acount, ios::out);//用输出的方式打开文件--写文件 
	//将每个人的数据写入到文件中
	for (int i = 0; i < 50; i++) {
		ofs << adminarray[i].account << " "
			<< adminarray[i].password << endl;
	}
	ofs.close();
}
void library::iniadmin(){//读admin文件 
	ifstream ifs;
	ifs.open(a_acount, ios::in);
	long account1;
	string password1;
	int i = 0;
	while (ifs >> account1 && ifs >> password1) {
		adminarray[i].account = account1;
		adminarray[i].password = password1;
	i++; 
	}
	ifs.close();
	return;
}


void library::addaccount()
{
	system("cls");
	usernum++;
//	if (usernum>7999) //处理越界问题 
//	{
//		cout<<
//		return;
//	} 
//	if ()//处理添加账户重复问题 
	cout<<"请输入要添加的账号:"<<endl;
    cin>>userarray[usernum-1].account;
	cout<<"请输入密码:"<<endl;
	cin>>userarray[usernum-1].password;
	ofstream ofs;
	ofs.open(FILENAME,ios::out|ios::app);
	ofs<<userarray[usernum-1].account;
	ofs<<" ";
	ofs<<userarray[usernum-1].password;
	ofs.close(); 
	cout<<"添加成功"<<endl;
	cout<<"即将返回上级目录"<<endl;
	return;
}
void library::deleteaccount()
{
	long temp_account;
	system("cls"); 
	cout<<"请输入要删除的账号:"<<endl;
    cin>>temp_account;
    for (int i=0;i<=usernum-1; i++)
    {
    	if (userarray[i].account==temp_account)
    	{
    		userarray[i].account=0;
    		this->save();
    		cout<<"删除成功"<<endl;
    		cout<<"即将返回上级目录"<<endl;
    		return;
		}
	}
	cout<<"未找到该账号"<<endl; 
	return;
}
void library::modifypassword()
{
	long temp_account;
	string temp_password,temp2_password;
	system("cls"); 
	cout<<"请输入要重置的账号:"<<endl;
    cin>>temp_account;
repasswordfunc:
    cout<<"请输入要重置的密码:"<<endl;
	cin>> temp_password;
	cout<<"请确认要重置的密码:"<<endl;
	cin>> temp2_password;
	if (temp_password!=temp2_password) 
	{
		cout<<"密码不一致，请重新输入密码"<<endl;
		system("pause");
		system("cls"); 
		goto repasswordfunc;
	}
    for (int i=0;i<=usernum-1; i++)
    {
    	if (userarray[i].account==temp_account)
    	{
    		userarray[i].password=temp_password;
    		this->save();
    		cout<<"修改成功"<<endl;
    		cout<<"即将返回上级目录"<<endl; 
			system("pause"); 
    		return;
		}
	}
	cout<<"未找到该账号"<<endl; 
	return;
}
void library::resetpassword()
{
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  for(int i=0;i<usernum;i++){
  long temp=20210000;
  userarray[i].account=temp+i;
  userarray[i].password="123456";
  }
  this->save(); 
  ifs.close();
  cout<<"初始化所有用户密码成功"<<endl;
  cout<<"即将返回上级目录"<<endl;
	return;
}

void library::book_manage()
{
	
}

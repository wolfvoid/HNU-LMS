#include"library.h"
using namespace std;

void library::admin_save() {//д�ļ� 
	ofstream ofs;
	ofs.open(a_acount, ios::out);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < 50; i++) {
		ofs << adminarray[i].account << " "
			<< adminarray[i].password << endl;
	}
	ofs.close();
}
void library::iniadmin(){//��admin�ļ� 
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
//	if (usernum>7999) //����Խ������ 
//	{
//		cout<<
//		return;
//	} 
//	if ()//��������˻��ظ����� 
	cout<<"������Ҫ��ӵ��˺�:"<<endl;
    cin>>userarray[usernum-1].account;
	cout<<"����������:"<<endl;
	cin>>userarray[usernum-1].password;
	ofstream ofs;
	ofs.open(FILENAME,ios::out|ios::app);
	ofs<<userarray[usernum-1].account;
	ofs<<" ";
	ofs<<userarray[usernum-1].password;
	ofs.close(); 
	cout<<"��ӳɹ�"<<endl;
	cout<<"���������ϼ�Ŀ¼"<<endl;
	return;
}
void library::deleteaccount()
{
	long temp_account;
	system("cls"); 
	cout<<"������Ҫɾ�����˺�:"<<endl;
    cin>>temp_account;
    for (int i=0;i<=usernum-1; i++)
    {
    	if (userarray[i].account==temp_account)
    	{
    		userarray[i].account=0;
    		this->save();
    		cout<<"ɾ���ɹ�"<<endl;
    		cout<<"���������ϼ�Ŀ¼"<<endl;
    		return;
		}
	}
	cout<<"δ�ҵ����˺�"<<endl; 
	return;
}
void library::modifypassword()
{
	long temp_account;
	string temp_password,temp2_password;
	system("cls"); 
	cout<<"������Ҫ���õ��˺�:"<<endl;
    cin>>temp_account;
repasswordfunc:
    cout<<"������Ҫ���õ�����:"<<endl;
	cin>> temp_password;
	cout<<"��ȷ��Ҫ���õ�����:"<<endl;
	cin>> temp2_password;
	if (temp_password!=temp2_password) 
	{
		cout<<"���벻һ�£���������������"<<endl;
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
    		cout<<"�޸ĳɹ�"<<endl;
    		cout<<"���������ϼ�Ŀ¼"<<endl; 
			system("pause"); 
    		return;
		}
	}
	cout<<"δ�ҵ����˺�"<<endl; 
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
  cout<<"��ʼ�������û�����ɹ�"<<endl;
  cout<<"���������ϼ�Ŀ¼"<<endl;
	return;
}

void library::book_manage()
{
	
}

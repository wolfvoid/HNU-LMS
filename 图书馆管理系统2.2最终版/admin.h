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
 
void library::addaccount()//����ԱȨ�ޣ�������˺� 
{
	system("cls");
	usernum++;
	if (usernum>7999) //����Խ������ 
	{
		cout<<"�û���ģ�Ѿ��ﵽ���ޣ�����ɾ�������û�"<<endl; 
		return;
	} 
retry:
	cout<<"������Ҫ��ӵ��˺�:"<<endl;
    cin>>userarray[usernum-1].account;
    for (int i=0;i<=usernum-2;i++)//��������˻��ظ�����
    {
    	if (userarray[usernum-1].account==userarray[i].account){
    	cout<<"Ҫ��ӵ��˺��ظ�������������"<<endl;
		system("pause");
		system("cls");
		goto  retry;}
	}
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
void library::deleteaccount()//����ԱȨ�ޣ���ɾ���˺� 
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
void library::modifypassword()//����ԱȨ�ޣ����޸��û����� 
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
void library::resetpassword()//����ԱȨ�ޣ�����ʼ���û����� 
{
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  for(int i=0;i<usernum;i++){
  userarray[i].password="123456";
  }
  this->save(); 
  ifs.close();
  cout<<"��ʼ�������û�����ɹ�"<<endl;
  cout<<"���������ϼ�Ŀ¼"<<endl;
	return;
}

void library::addbook()//����ԱȨ�ޣ�������鼮��Ϣ 
{
	system("cls");
	booksnum++;
	cout<<"��ʽ������ ISBN/ISSN ���� �����"<<endl;
	cout<<"example������� 978-7-80179-793-3 (��ϣ��)����ͼ��;�������� B502.232/23"<<endl;
	cout<<"������������������:"<<endl;
    cin>>booksarray[booksnum-1].topic;
	cout<<"������ISBN/ISSN:"<<endl;
	cin>>booksarray[booksnum-1].type;
	cout<<"����������:"<<endl;
    cin>>booksarray[booksnum-1].writer;
	cout<<"���������ţ�"<<endl;
	cin>>booksarray[booksnum-1].category;
	booksarray[booksnum-1].state=1;
	booksarray[booksnum-1].ownerid=0;
	ofstream ofs;
	ofs.open(FILEname,ios::out|ios::app);
	ofs<<booksarray[booksnum-1].topic<<" ";
	ofs<<booksarray[booksnum-1].type<<" ";
	ofs<<booksarray[booksnum-1].writer<<" ";
	ofs<<booksarray[booksnum-1].category<<" ";
	ofs<<booksarray[booksnum-1].state<<" ";
	ofs<<booksarray[booksnum-1].ownerid<<endl;
	ofs.close(); 
	cout<<"��ӳɹ�"<<endl;
	cout<<"���������ϼ�Ŀ¼"<<endl;
	return;
}

void library::deletebook()//����ԱȨ�ޣ���ɾ���鼮��Ϣ 
{    
borrowfunc:	 
	system("cls");
	 cout<<"��Ҫɾ���ı�ͼ�飿������"<<endl;
	 this->xinxitypemenu(); 
	 cout<<"������Ϣ������"<<endl;
	 int xinxitype;
	 cin>>xinxitype;
if(xinxitype==1){
	 cout<<"����������"<<endl;
	 string topic_;
	 cin>>topic_;
	 int i=0;
	 for(;i<this->booksnum;i++){
	 if(topic_==this->booksarray[i].topic){
	  cout<<"�����ɹ�"<<endl;
	  this->showbook(this->booksarray[i]);
	   if(this->booksarray[i].state==1){
	      cout<<"��ȷ��Ҫɾ�������� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ�ɾ��"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
	      this->booksarray[i].topic="";
	      this->booksarray[i].type=""; 
	      this->booksarray[i].writer=""; 
	      this->booksarray[i].category=""; 
	      this->booksarray[i].state=2;
	      this->booksarray[i].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }
	 }}
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
     }
else if(xinxitype==2){
	 cout<<"������ISBN/ISSN"<<endl;
	 string type_;
	 cin>>type_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(type_==this->booksarray[i].type){
	 cout<<"�����ɹ�"<<endl;
	 this->showbook(this->booksarray[i]);
	 if(this->booksarray[i].state==1){
	      cout<<"��ȷ��Ҫɾ�������� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ�ɾ��"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
	      this->booksarray[i].topic="";
	      this->booksarray[i].type=""; 
	      this->booksarray[i].writer=""; 
	      this->booksarray[i].category=""; 
	      this->booksarray[i].state=2;
	      this->booksarray[i].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }
	 }}
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
     }
else if(xinxitype==3){
writersearch:	 cout<<"������������"<<endl;
	 string writer_;
	 cin>>writer_;
	 int sum1=0;
for(int i=0;i<=this->booksnum;i++){
	 if(writer_==this->booksarray[i].writer){
	 //cout<<"�����ɹ�"<<endl;
	 sum1++;
	 cout<<sum1<<".";
	 this->showbook(this->booksarray[i]);
	 cout<<"  ����ı��:"<<i<<endl;
	 }
}
if(sum1==0){
	 cout<<"��������ȷ��������"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"��������Ҫɾ���ı�ţ�"<<endl;
	  int bianhao;cin>>bianhao;
	  if(booksarray[bianhao].writer==writer_){
	      cout<<"��ȷ��Ҫɾ�������� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ�ɾ��"<<"��"<<this->booksarray[bianhao].topic<<"��"<<endl; 
	      this->booksarray[bianhao].topic="";
	      this->booksarray[bianhao].type=""; 
	      this->booksarray[bianhao].writer=""; 
	      this->booksarray[bianhao].category=""; 
	      this->booksarray[bianhao].state=2;
	      this->booksarray[bianhao].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"��������ȷ�ı��"<<endl;
	  goto  bianhaofunc;
	  } 
	 }
     }
}

void library::modifybook()//����ԱȨ�ޣ����޸��鼮��Ϣ 
{
borrowfunc:	 
	system("cls");
	 cout<<"��Ҫ�޸��ı�ͼ�飿������"<<endl;
	 this->xinxitypemenu();
	 cout<<"������Ϣ������"<<endl;
	 int xinxitype;
	 cin>>xinxitype;
if(xinxitype==1){
	 cout<<"����������"<<endl;
	 string topic_;
	 cin>>topic_;
	 int i=0;
	 for(;i<this->booksnum;i++){
	 if(topic_==this->booksarray[i].topic){
	  cout<<"�����ɹ�"<<endl;
	  this->showbook(this->booksarray[i]);
	      cout<<"��ȷ��Ҫ�޸ĸ����� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
modifyfunc1: 
	      	cout<<"��Ϣ��ʽ��"<<endl; 
	      	cout<<"example������� 978-7-80179-793-3 (��ϣ��)����ͼ��;�������� B502.232/23"<<endl;
	      	cout<<"��������Ҫ�޸ĵ���Ϣ����"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.�����ϼ�Ŀ¼  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"������������������:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc1;
					        break;
	      		case 2:
	      			        cout<<"������ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc1;
					        break;
	      		case 3:
	      				  	cout<<"����������:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
				      	    goto modifyfunc1;
				      	    break;
	      		case 4:
	      			        cout<<"���������ţ�"<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					 	    goto modifyfunc1;
					 	    break;
				case 0:     
							cout<<"���������ϼ�Ŀ¼"<<endl; 
							system("pause");
							return;
				default:
							cout<<"�����ʽ��������������"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc1;
							break;		
			  }
	      cout<<"���ѳɹ�ɾ��"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
	      this->booksave();
	      return;
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }
	 }
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
     }
else if(xinxitype==2){
	 cout<<"������ISBN/ISSN"<<endl;
	 string type_;
	 cin>>type_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(type_==this->booksarray[i].type){
	 cout<<"�����ɹ�"<<endl;
	 this->showbook(this->booksarray[i]);
	      cout<<"��ȷ��Ҫ�޸ĸ����� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      modifyfunc2: 
	      	cout<<"��Ϣ��ʽ��"<<endl; 
	      	cout<<"example������� 978-7-80179-793-3 (��ϣ��)����ͼ��;�������� B502.232/23"<<endl;
	      	cout<<"��������Ҫ�޸ĵ���Ϣ����"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.�����ϼ�Ŀ¼  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"������������������:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc2;
					        break;
	      		case 2:
	      			        cout<<"������ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc2;
					        break;
	      		case 3:
	      				  	cout<<"����������:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
				      	    goto modifyfunc2;
				      	    break;
	      		case 4:
	      			        cout<<"���������ţ�"<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					 	    goto modifyfunc2;
					 	    break;
				case 0:     
							cout<<"���������ϼ�Ŀ¼"<<endl; 
							system("pause");
							return;
				default:
							cout<<"�����ʽ��������������"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc2;
							break;		
			  }
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	 }}
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
     }
else if(xinxitype==3){
writersearch:	 cout<<"������������"<<endl;
	 string writer_;
	 cin>>writer_;
	 int sum1=0;
for(int i=0;i<=this->booksnum;i++){
	 if(writer_==this->booksarray[i].writer){
	 //cout<<"�����ɹ�"<<endl;
	 sum1++;
	 cout<<sum1<<".";
	 this->showbook(this->booksarray[i]);
	 cout<<"  ����ı��:"<<i<<endl;
	 }
}
if(sum1==0){
	 cout<<"�����������޸ĵ�������"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"��������Ҫ�޸ĵı�ţ�"<<endl;
	  int bianhao;cin>>bianhao;
	  if(booksarray[bianhao].writer==writer_){
	      cout<<"��ȷ��Ҫ�޸ĸ����� ȷ��������1��ȡ��������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      modifyfunc3: 
	      	cout<<"��Ϣ��ʽ��"<<endl; 
	      	cout<<"example������� 978-7-80179-793-3 (��ϣ��)����ͼ��;�������� B502.232/23"<<endl;
	      	cout<<"��������Ҫ�޸ĵ���Ϣ����"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.�����ϼ�Ŀ¼  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"������������������:"<<endl;
					        cin>>booksarray[bianhao].topic;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc3;
					        break;
	      		case 2:
	      			        cout<<"������ISBN/ISSN:"<<endl;
					        cin>>booksarray[bianhao].type;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc3;
					        break;
	      		case 3:
	      				  	cout<<"����������:"<<endl;
				      	    cin>>booksarray[bianhao].writer;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
				      	    goto modifyfunc3;
				      	    break;
	      		case 4:
	      			        cout<<"���������ţ�"<<endl;
					 	    cin>>booksarray[bianhao].category;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					 	    goto modifyfunc3;
					 	    break;
				case 0:     
							cout<<"���������ϼ�Ŀ¼"<<endl; 
							system("pause");
							return;
				default:
							cout<<"�����ʽ��������������"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc3;
							break;		
			  }
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"��������ȷ�ı��"<<endl;
	  goto  bianhaofunc;
	  } 
	 }
     }
else if(xinxitype==4){
	 cout<<"����������"<<endl;
	 string category_;
	 cin>>category_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(category_==this->booksarray[i].category){
	 cout<<"�����ɹ�"<<endl;
	 this->showbook(this->booksarray[i]);
	 if(this->booksarray[i].state==1){
	      cout<<"��ȷ��Ҫ�޸ĸ����� ȷ��������1��ȡ������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	     modifyfunc4: 
	      	cout<<"��Ϣ��ʽ��"<<endl; 
	      	cout<<"example������� 978-7-80179-793-3 (��ϣ��)����ͼ��;�������� B502.232/23"<<endl;
	      	cout<<"��������Ҫ�޸ĵ���Ϣ����"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.�����ϼ�Ŀ¼  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"������������������:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc4;
					        break;
	      		case 2:
	      			        cout<<"������ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					        goto modifyfunc4;
					        break;
	      		case 3:
	      				  	cout<<"����������:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
				      	    goto modifyfunc4;
				      	    break;
	      		case 4:
	      			        cout<<"���������ţ�"<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"�޸ĳɹ�"<<endl;
							system("pause"); 
					 	    goto modifyfunc4;
					 	    break;
				case 0:     
							cout<<"���������ϼ�Ŀ¼"<<endl; 
							system("pause");
						    return;
				default:
							cout<<"�����ʽ��������������"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc4;
							break;		
			  }
	      }else{
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      } 
	    }}}
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
}else{
goto borrowfunc; 
}
}   


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
 
void library::addaccount()//管理员权限：：添加账号 
{
	system("cls");
	usernum++;
	if (usernum>7999) //处理越界问题 
	{
		cout<<"用户规模已经达到上限，请先删除部分用户"<<endl; 
		return;
	} 
retry:
	cout<<"请输入要添加的账号:"<<endl;
    cin>>userarray[usernum-1].account;
    for (int i=0;i<=usernum-2;i++)//处理添加账户重复问题
    {
    	if (userarray[usernum-1].account==userarray[i].account){
    	cout<<"要添加的账号重复，请重新输入"<<endl;
		system("pause");
		system("cls");
		goto  retry;}
	}
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
void library::deleteaccount()//管理员权限：：删除账号 
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
void library::modifypassword()//管理员权限：：修改用户密码 
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
void library::resetpassword()//管理员权限：：初始化用户密码 
{
  ifstream ifs; 
  ifs.open(FILENAME,ios::in);
  for(int i=0;i<usernum;i++){
  userarray[i].password="123456";
  }
  this->save(); 
  ifs.close();
  cout<<"初始化所有用户密码成功"<<endl;
  cout<<"即将返回上级目录"<<endl;
	return;
}

void library::addbook()//管理员权限：：添加书籍信息 
{
	system("cls");
	booksnum++;
	cout<<"格式：书名 ISBN/ISSN 作者 分类号"<<endl;
	cout<<"example：理想国 978-7-80179-793-3 (古希腊)柏拉图著;吴献书译 B502.232/23"<<endl;
	cout<<"请输入题名（书名）:"<<endl;
    cin>>booksarray[booksnum-1].topic;
	cout<<"请输入ISBN/ISSN:"<<endl;
	cin>>booksarray[booksnum-1].type;
	cout<<"请输入作者:"<<endl;
    cin>>booksarray[booksnum-1].writer;
	cout<<"请输入分类号："<<endl;
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
	cout<<"添加成功"<<endl;
	cout<<"即将返回上级目录"<<endl;
	return;
}

void library::deletebook()//管理员权限：：删除书籍信息 
{    
borrowfunc:	 
	system("cls");
	 cout<<"你要删除哪本图书？请搜索"<<endl;
	 this->xinxitypemenu(); 
	 cout<<"输入信息的种类"<<endl;
	 int xinxitype;
	 cin>>xinxitype;
if(xinxitype==1){
	 cout<<"请输入题名"<<endl;
	 string topic_;
	 cin>>topic_;
	 int i=0;
	 for(;i<this->booksnum;i++){
	 if(topic_==this->booksarray[i].topic){
	  cout<<"搜索成功"<<endl;
	  this->showbook(this->booksarray[i]);
	   if(this->booksarray[i].state==1){
	      cout<<"你确定要删除该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功删除"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksarray[i].topic="";
	      this->booksarray[i].type=""; 
	      this->booksarray[i].writer=""; 
	      this->booksarray[i].category=""; 
	      this->booksarray[i].state=2;
	      this->booksarray[i].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }
	 }}
	 cout<<"找不到该书"<<endl; 
	 return; 
     }
else if(xinxitype==2){
	 cout<<"请输入ISBN/ISSN"<<endl;
	 string type_;
	 cin>>type_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(type_==this->booksarray[i].type){
	 cout<<"搜索成功"<<endl;
	 this->showbook(this->booksarray[i]);
	 if(this->booksarray[i].state==1){
	      cout<<"你确定要删除该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功删除"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksarray[i].topic="";
	      this->booksarray[i].type=""; 
	      this->booksarray[i].writer=""; 
	      this->booksarray[i].category=""; 
	      this->booksarray[i].state=2;
	      this->booksarray[i].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }
	 }}
	 cout<<"找不到该书"<<endl; 
	 return; 
     }
else if(xinxitype==3){
writersearch:	 cout<<"请输入作者名"<<endl;
	 string writer_;
	 cin>>writer_;
	 int sum1=0;
for(int i=0;i<=this->booksnum;i++){
	 if(writer_==this->booksarray[i].writer){
	 //cout<<"搜索成功"<<endl;
	 sum1++;
	 cout<<sum1<<".";
	 this->showbook(this->booksarray[i]);
	 cout<<"  该书的编号:"<<i<<endl;
	 }
}
if(sum1==0){
	 cout<<"请输入正确的作者名"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"请输入您要删除的编号："<<endl;
	  int bianhao;cin>>bianhao;
	  if(booksarray[bianhao].writer==writer_){
	      cout<<"你确定要删除该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功删除"<<"《"<<this->booksarray[bianhao].topic<<"》"<<endl; 
	      this->booksarray[bianhao].topic="";
	      this->booksarray[bianhao].type=""; 
	      this->booksarray[bianhao].writer=""; 
	      this->booksarray[bianhao].category=""; 
	      this->booksarray[bianhao].state=2;
	      this->booksarray[bianhao].ownerid=0;  
	      this->booksave();
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"请输入正确的编号"<<endl;
	  goto  bianhaofunc;
	  } 
	 }
     }
}

void library::modifybook()//管理员权限：：修改书籍信息 
{
borrowfunc:	 
	system("cls");
	 cout<<"你要修改哪本图书？请搜索"<<endl;
	 this->xinxitypemenu();
	 cout<<"输入信息的种类"<<endl;
	 int xinxitype;
	 cin>>xinxitype;
if(xinxitype==1){
	 cout<<"请输入题名"<<endl;
	 string topic_;
	 cin>>topic_;
	 int i=0;
	 for(;i<this->booksnum;i++){
	 if(topic_==this->booksarray[i].topic){
	  cout<<"搜索成功"<<endl;
	  this->showbook(this->booksarray[i]);
	      cout<<"你确定要修改该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
modifyfunc1: 
	      	cout<<"信息格式："<<endl; 
	      	cout<<"example：理想国 978-7-80179-793-3 (古希腊)柏拉图著;吴献书译 B502.232/23"<<endl;
	      	cout<<"请输入你要修改的信息种类"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.返回上级目录  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"请输入题名（书名）:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc1;
					        break;
	      		case 2:
	      			        cout<<"请输入ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc1;
					        break;
	      		case 3:
	      				  	cout<<"请输入作者:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
				      	    goto modifyfunc1;
				      	    break;
	      		case 4:
	      			        cout<<"请输入分类号："<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					 	    goto modifyfunc1;
					 	    break;
				case 0:     
							cout<<"即将返回上级目录"<<endl; 
							system("pause");
							return;
				default:
							cout<<"输入格式错误，请重新输入"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc1;
							break;		
			  }
	      cout<<"你已成功删除"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksave();
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }
	 }
	 cout<<"找不到该书"<<endl; 
	 return; 
     }
else if(xinxitype==2){
	 cout<<"请输入ISBN/ISSN"<<endl;
	 string type_;
	 cin>>type_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(type_==this->booksarray[i].type){
	 cout<<"搜索成功"<<endl;
	 this->showbook(this->booksarray[i]);
	      cout<<"你确定要修改该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      modifyfunc2: 
	      	cout<<"信息格式："<<endl; 
	      	cout<<"example：理想国 978-7-80179-793-3 (古希腊)柏拉图著;吴献书译 B502.232/23"<<endl;
	      	cout<<"请输入你要修改的信息种类"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.返回上级目录  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"请输入题名（书名）:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc2;
					        break;
	      		case 2:
	      			        cout<<"请输入ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc2;
					        break;
	      		case 3:
	      				  	cout<<"请输入作者:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
				      	    goto modifyfunc2;
				      	    break;
	      		case 4:
	      			        cout<<"请输入分类号："<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					 	    goto modifyfunc2;
					 	    break;
				case 0:     
							cout<<"即将返回上级目录"<<endl; 
							system("pause");
							return;
				default:
							cout<<"输入格式错误，请重新输入"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc2;
							break;		
			  }
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	 }}
	 cout<<"找不到该书"<<endl; 
	 return; 
     }
else if(xinxitype==3){
writersearch:	 cout<<"请输入作者名"<<endl;
	 string writer_;
	 cin>>writer_;
	 int sum1=0;
for(int i=0;i<=this->booksnum;i++){
	 if(writer_==this->booksarray[i].writer){
	 //cout<<"搜索成功"<<endl;
	 sum1++;
	 cout<<sum1<<".";
	 this->showbook(this->booksarray[i]);
	 cout<<"  该书的编号:"<<i<<endl;
	 }
}
if(sum1==0){
	 cout<<"请重新输入修改的作者名"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"请输入您要修改的编号："<<endl;
	  int bianhao;cin>>bianhao;
	  if(booksarray[bianhao].writer==writer_){
	      cout<<"你确定要修改该书吗？ 确认请输入1，取消请输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      modifyfunc3: 
	      	cout<<"信息格式："<<endl; 
	      	cout<<"example：理想国 978-7-80179-793-3 (古希腊)柏拉图著;吴献书译 B502.232/23"<<endl;
	      	cout<<"请输入你要修改的信息种类"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.返回上级目录  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"请输入题名（书名）:"<<endl;
					        cin>>booksarray[bianhao].topic;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc3;
					        break;
	      		case 2:
	      			        cout<<"请输入ISBN/ISSN:"<<endl;
					        cin>>booksarray[bianhao].type;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc3;
					        break;
	      		case 3:
	      				  	cout<<"请输入作者:"<<endl;
				      	    cin>>booksarray[bianhao].writer;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
				      	    goto modifyfunc3;
				      	    break;
	      		case 4:
	      			        cout<<"请输入分类号："<<endl;
					 	    cin>>booksarray[bianhao].category;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					 	    goto modifyfunc3;
					 	    break;
				case 0:     
							cout<<"即将返回上级目录"<<endl; 
							system("pause");
							return;
				default:
							cout<<"输入格式错误，请重新输入"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc3;
							break;		
			  }
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"请输入正确的编号"<<endl;
	  goto  bianhaofunc;
	  } 
	 }
     }
else if(xinxitype==4){
	 cout<<"请输入分类号"<<endl;
	 string category_;
	 cin>>category_;
	 int i=0;
	 for(;i<=this->booksnum;i++){
	 if(category_==this->booksarray[i].category){
	 cout<<"搜索成功"<<endl;
	 this->showbook(this->booksarray[i]);
	 if(this->booksarray[i].state==1){
	      cout<<"你确定要修改该书吗？ 确定请输入1，取消输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	     modifyfunc4: 
	      	cout<<"信息格式："<<endl; 
	      	cout<<"example：理想国 978-7-80179-793-3 (古希腊)柏拉图著;吴献书译 B502.232/23"<<endl;
	      	cout<<"请输入你要修改的信息种类"<<endl;
	      	xinxitypemenu();
	      	cout<<"*****  0.返回上级目录  *****"<<endl;
	      	cout<<"****************************"<<endl;
	      	int option;
	      	cin>>option;
	      	system("cls");
	      	switch(option)
	      	{
	      		case 1:
	      				    cout<<"请输入题名（书名）:"<<endl;
					        cin>>booksarray[i].topic;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc4;
					        break;
	      		case 2:
	      			        cout<<"请输入ISBN/ISSN:"<<endl;
					        cin>>booksarray[i].type;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					        goto modifyfunc4;
					        break;
	      		case 3:
	      				  	cout<<"请输入作者:"<<endl;
				      	    cin>>booksarray[i].writer;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
				      	    goto modifyfunc4;
				      	    break;
	      		case 4:
	      			        cout<<"请输入分类号："<<endl;
					 	    cin>>booksarray[i].category;
					        this->booksave();
					        cout<<"修改成功"<<endl;
							system("pause"); 
					 	    goto modifyfunc4;
					 	    break;
				case 0:     
							cout<<"即将返回上级目录"<<endl; 
							system("pause");
						    return;
				default:
							cout<<"输入格式错误，请重新输入"<<endl;
							system("pause"); 
							system("cls");
							goto modifyfunc4;
							break;		
			  }
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      } 
	    }}}
	 cout<<"找不到该书"<<endl; 
	 return; 
}else{
goto borrowfunc; 
}
}   


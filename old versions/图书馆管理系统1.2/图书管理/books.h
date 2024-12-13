#include"library.h"
using namespace std;

int library::getbooksnum(){//统计书的数量 
	ifstream ifs;
    ifs.open(FILEname,ios::in);
	string topic1;
	string type1;
	string writer1;
	string category1;
	long ownerid1;
	int state1;
	int num=0;
	while(ifs>>topic1&&ifs>>type1&&ifs>>writer1&&ifs>>category1&&ifs>>state1&&ifs>>ownerid1){
		num++;
	} 
	return num;
}
void library::inibooks() {//读文件 
	ifstream ifs;
	ifs.open(FILEname,ios::in);
	string topic1;
	string type1;
	string writer1;
	string category1;
	int state1;
	long ownerid1;
	int i = 0;
	while (ifs>>topic1&&ifs>>type1&&ifs>>writer1&&ifs>>category1&&ifs>>state1&&ifs>>ownerid1) {
		booksarray[i].topic=topic1;
		booksarray[i].type=type1;
		booksarray[i].writer=writer1;
		booksarray[i].category=category1;
		booksarray[i].state=state1;
	    booksarray[i].ownerid=ownerid1;
	i++; 
	}
	ifs.close();
	return;
}
//写文件 
void library::booksave(){
	 ofstream ofs;
	ofs.open(FILEname,ios::out);//用输出的方式打开文件--写文件 
	//将每个人的数据写入到文件中
	for (int i = 0; i<this->booksnum; i++){
		ofs<<booksarray[i].topic<<" ";
		ofs<<booksarray[i].type<<" ";
		ofs<<booksarray[i].writer<<" ";
		ofs<<booksarray[i].category<<" ";
		ofs<<booksarray[i].state<<" ";
		ofs<<booksarray[i].ownerid<<endl;
	}
	ofs.close();
}

//展示图书信息 
void library::showbook(book Book){
	  cout<<"该书的题名："<<Book.topic<<endl;
	  cout<<"  该书的ISBN/ISNN："<<Book.type<<endl;
	  cout<<"  该书的作者："<<Book.writer<<endl;
	  cout<<"  该书的分类号："<<Book.category<<endl;
	  if(Book.state==1) cout<<"  该书的借阅状况：未借出"<<endl; 
	  else if(Book.state==0){	 
	  cout<<"  该书的借阅状况：已借出"<<endl;
	  cout<<"  该书的借阅者："<<Book.ownerid<<endl;
	  }
	  }
//搜索图书 
void library::search(){ 
searchfunc:	system("cls");
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
	 this->showbook(this->booksarray[i]);
	 return;
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
	 this->showbook(this->booksarray[i]);
	 return;
	 }
	 }
	 cout<<"找不到该书"<<endl; 
	 return; 
     }
else if(xinxitype==3){
	 cout<<"请输入作者名"<<endl;
	 string writer_;
	 cin>>writer_;
	 int i=0;
	 int sum1=0; 
	 for(;i<=this->booksnum;i++){
	 if(writer_==this->booksarray[i].writer){
	 sum1++;
	 cout<<sum1<<".";
	 this->showbook(this->booksarray[i]);
	 }
	 }
	 if(sum1==0){
	 cout<<"找不到该作者的书籍"<<endl; 
	 return;}else return;
     }
else if(xinxitype==4){
	 cout<<"请输入分类号"<<endl;
	 string category_;
	 cin>>category_;
	 int i=0;
	 int sum2=0; 
	 for(;i<=this->booksnum;i++){
	 if(category_==this->booksarray[i].category){
	 sum2++;
	 cout<<sum2<<".";
	 this->showbook(this->booksarray[i]);
	 }
	 }
	if(sum2==0){
	 cout<<"找不到该作者的书籍"<<endl; 
	 return;}else return;
}else{
goto searchfunc; 
}}
//借图书 
void library::borrowbook(long id){
borrowfunc:	 system("cls");
	 cout<<"你要借出哪本图书？请搜索"<<endl;
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
	      cout<<"你确定要借该书吗？ 借书请输入1，否则输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功借出"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksarray[i].state=0;
	      this->booksarray[i].ownerid=id; 
	      this->booksave();
	      this->recordsave(booksarray[i]);
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }else if(this->booksarray[i].state==0){
	   cout<<"已借出，你不可借阅"<<endl;
	   return;
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
	      cout<<"你确定要借该书吗？ 借书请输入1，否则输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功借出"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksarray[i].state=0;
		  this->booksarray[i].ownerid=id; 
	      this->booksave();
	      this->recordsave(booksarray[i]);
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	   }else if(this->booksarray[i].state==0){
	   cout<<"已借出，你不可借阅"<<endl;
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
	 cout<<"请输入正确的作者名"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"请输入您要借书的编号："<<endl;
	  int bianhao;cin>>bianhao;
	  if(this->booksarray[bianhao].state==1&&this->booksarray[bianhao].writer==writer_){
	      cout<<"你确定要借书吗？ 借书请输入1，否则输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功借出"<<"《"<<this->booksarray[bianhao].topic<<"》"<<endl; 
	      this->booksarray[bianhao].state=0; 
	      this->booksarray[bianhao].ownerid=id;
	      this->booksave();
	      this->recordsave(booksarray[bianhao]);
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      }
	  }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"请输入正确的编号"<<endl;
	  goto  bianhaofunc;
	  }else if(this->booksarray[bianhao].state==0){
	  cout<<"已借出，你不可借阅"<<endl;
	  return;
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
	      cout<<"你确定要借该书吗？ 借书请输入1，否则输入0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"你已成功借出"<<"《"<<this->booksarray[i].topic<<"》"<<endl; 
	      this->booksarray[i].state=0; 
	      this->booksarray[i].ownerid=id;
	      this->booksave();
	      this->recordsave(booksarray[i]);
	      return;
	      }else{
	      cout<<"你已取消本次操作"<<endl; 
	      return; 
	      } 
	     }else if(this->booksarray[i].state==0){
	   cout<<"已借出，你不可借阅"<<endl;
	 return;
	 }
	 }}
	 cout<<"找不到该书"<<endl; 
	 return; 
}else{
goto borrowfunc; 
}
}
//还图书 
void library::givebook(long id){
borrowfunc:	 cout<<"你已借阅的图书："<<endl;
	 int sum=0;
	 for(int i=0;i<this->booksnum;i++){
	 if(this->booksarray[i].ownerid==id){
	 sum++;
	 cout<<sum<<"."<<"该书的编号："<<i<<endl; 
	 cout<<"  该书的题名："<<this->booksarray[i].topic<<endl;
	 cout<<"  该书的ISBN/ISNN："<<this->booksarray[i].type<<endl;
	 cout<<"  该书的作者："<<this->booksarray[i].writer<<endl;
	 cout<<"  该书的分类号："<<this->booksarray[i].category<<endl;
	 }}
	 if(sum==0){
	 cout<<"你还未借阅书籍"<<endl; 
	 }else{
     cout<<"请输入你所要还的书的编号:"<<endl;
     int bookid;cin>>bookid;
     cout<<"你已成功归还"<<"《"<<this->booksarray[bookid].topic<<"》"<<endl; 
     this->booksarray[bookid].state=1;
	 this->booksarray[bookid].ownerid=0;
	 this->booksave();
	 sum--;
	 if(sum>0){
	 cout<<"请问你是否需要继续归还？1-是 2-否"<<endl;
	 int select;cin>>select;
	 if(select==1)
	 goto borrowfunc;
	 else return;}
	 else return;
     } 
}


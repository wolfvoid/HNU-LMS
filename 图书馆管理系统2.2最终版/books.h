#include"library.h"
#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;
string match(string s,int begin,int end){
	 string temp="";
     for(int i=begin;i<end;i++){
     temp+=s[i];
     }
     return temp;
}
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
else if(xinxitype==4){//new 
	 string onecategory_,twocategory_,threecategory_;
	 int a1,a2,a3;
	 cout<<"请输入一级分类号"<<endl;
     cin>>onecategory_;
 onesearch:int sum1=0;
	 for(int i=0;i<=this->booksnum;i++){
	 	
	    if(onecategory_[0]==this->booksarray[i].category[0]){
	    sum1++;
	    cout<<sum1<<".";
	    this->showbook(this->booksarray[i]);
	    if(sum1%10==0){
	    cout<<endl;
        cout<<"第"<<sum1/10+1<<"页已到底"<<endl;
		cout<<"1.继续下一级搜索"<<endl;
	    cout<<"2.退出搜索"<<endl; 
		cout<<"3.下一页"<<endl; 
		int select;cin>>select;
		if(select==1){a1=1;system("pause");system("cls");goto search2;} 
		if(select==2){a1=2;system("pause");system("cls");goto search2;} 
		if(select==3){system("pause");system("cls");}
	    }
	    }}
	    if(sum1==0){cout<<"没有找到书籍"<<endl;return;}
	    cout<<"1.继续搜索"<<endl;
	    cout<<"2.退出搜索"<<endl; 
	    cin>>a1;
	    
search2:   if(a1==1){
	       system("cls");
	       cout<<"请输入二级分类号"<<endl;
	       cin>>twocategory_;
	  twosearch:int sum2=0; 
	       for(int i=0;i<=this->booksnum;i++){
	       	 int end1=booksarray[i].category.find("/");
	       	 string p=match(booksarray[i].category,1,end1);
	       	 if(onecategory_[0]==this->booksarray[i].category[0]&&twocategory_==p){
	       	 sum2++;
	       	 cout<<sum2<<"."<<endl; 
	         this->showbook(this->booksarray[i]);
	         if(sum2%10==0){
	         cout<<endl;
             cout<<"第"<<sum1/10+1<<"页已到底"<<endl;
	 	     cout<<"1.继续下一级搜索"<<endl;
	 	     cout<<"2.返回上一级搜索"<<endl; 
	         cout<<"3.退出搜索"<<endl; 
	         cout<<"4.下一页"<<endl; 
		     int select;cin>>select;
		     if(select==1){a2=1;system("pause");system("cls");goto search3;} 
		     if(select==2){a2=2;system("pause");system("cls");goto search3;} 
		     if(select==3){a2=3;system("pause");system("cls");goto search3;} 
		     if(select==4){system("pause");system("cls");}
	         }
	         }}
	         if(sum2==0){cout<<"没有找到书籍"<<endl;return;}
	         cout<<"1.继续搜索"<<endl;
	         cout<<"2.返回上一级搜索"<<endl;
	         cout<<"3.退出搜索"<<endl; 
	         cin>>a2;
	           
search3:	   if(a2==1){
	           system("cls");
	           cout<<"请输入三级分类号"<<endl;
	           cin>>threecategory_;
	      threesearch:int sum3=0;
	           for(int i=0;i<=this->booksnum;i++){
	       	   int begin=booksarray[i].category.find("/")+1;
	       	   int end=booksarray[i].category.size();
	       	   string p1=match(booksarray[i].category,1,begin-1);
	       	   string p2=match(booksarray[i].category,begin,end);
	       	   if(onecategory_[0]==this->booksarray[i].category[0]&&twocategory_==p1&&threecategory_==p2){
	       	   sum3++;
	       	   cout<<1<<"."; 
	           this->showbook(this->booksarray[i]);
	           }}
	           if(sum3==0){cout<<"没有找到书籍"<<endl;return;}
	           cout<<"1.返回上一级搜索"<<endl;
	           cout<<"2.退出搜索"<<endl; 
	           cin>>a3;
	              if(a3==1) goto twosearch;
	              else if(a3==2) return;
	              else{
	              system("cls");
	              goto threesearch;
	               }
	           }else if(a2==2) goto onesearch;
			   else if(a2==3) return;
			   else{
	           system("cls");
	           goto twosearch;
	           }
	       }else if(a1==2){
	       return;
	       }else{
	       system("cls");
	       goto onesearch;
	       }
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
	      recordarray[recordnum].ownerid=id;
	      recordarray[recordnum].topic=booksarray[i].topic;
	      recordarray[recordnum].writer=booksarray[i].writer;
	      recordarray[recordnum].category=booksarray[i].category;
	      recordarray[recordnum].state=0;
	      recordnum++;
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
	      recordarray[recordnum].ownerid=id;
	      recordarray[recordnum].topic=booksarray[i].topic;
	      recordarray[recordnum].writer=booksarray[i].writer;
	      recordarray[recordnum].category=booksarray[i].category;
	      recordarray[recordnum].state=0;
	      recordnum++;
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
	      recordarray[recordnum].ownerid=id;
	      recordarray[recordnum].topic=booksarray[bianhao].topic;
	      recordarray[recordnum].writer=booksarray[bianhao].writer;
	      recordarray[recordnum].category=booksarray[bianhao].category;
	      recordarray[recordnum].state=0;
	      recordnum++;
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
	      recordarray[recordnum].ownerid=id;
	      recordarray[recordnum].topic=booksarray[i].topic;
	      recordarray[recordnum].writer=booksarray[i].writer;
	      recordarray[recordnum].category=booksarray[i].category;
	      recordarray[recordnum].state=0;
	      recordnum++;
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


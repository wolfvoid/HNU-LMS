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
int library::getbooksnum(){//ͳ��������� 
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
void library::inibooks() {//���ļ� 
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
//д�ļ� 
void library::booksave(){
	 ofstream ofs;
	ofs.open(FILEname,ios::out);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ���˵�����д�뵽�ļ���
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

//չʾͼ����Ϣ 
void library::showbook(book Book){
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
//����ͼ�� 
void library::search(){ 
searchfunc:	system("cls");
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
	 this->showbook(this->booksarray[i]);
	 return;
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
	 this->showbook(this->booksarray[i]);
	 return;
	 }
	 }
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
     }
else if(xinxitype==3){
	 cout<<"������������"<<endl;
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
	 cout<<"�Ҳ��������ߵ��鼮"<<endl; 
	 return;}else return;
     }
else if(xinxitype==4){//new 
	 string onecategory_,twocategory_,threecategory_;
	 int a1,a2,a3;
	 cout<<"������һ�������"<<endl;
     cin>>onecategory_;
 onesearch:int sum1=0;
	 for(int i=0;i<=this->booksnum;i++){
	 	
	    if(onecategory_[0]==this->booksarray[i].category[0]){
	    sum1++;
	    cout<<sum1<<".";
	    this->showbook(this->booksarray[i]);
	    if(sum1%10==0){
	    cout<<endl;
        cout<<"��"<<sum1/10+1<<"ҳ�ѵ���"<<endl;
		cout<<"1.������һ������"<<endl;
	    cout<<"2.�˳�����"<<endl; 
		cout<<"3.��һҳ"<<endl; 
		int select;cin>>select;
		if(select==1){a1=1;system("pause");system("cls");goto search2;} 
		if(select==2){a1=2;system("pause");system("cls");goto search2;} 
		if(select==3){system("pause");system("cls");}
	    }
	    }}
	    if(sum1==0){cout<<"û���ҵ��鼮"<<endl;return;}
	    cout<<"1.��������"<<endl;
	    cout<<"2.�˳�����"<<endl; 
	    cin>>a1;
	    
search2:   if(a1==1){
	       system("cls");
	       cout<<"��������������"<<endl;
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
             cout<<"��"<<sum1/10+1<<"ҳ�ѵ���"<<endl;
	 	     cout<<"1.������һ������"<<endl;
	 	     cout<<"2.������һ������"<<endl; 
	         cout<<"3.�˳�����"<<endl; 
	         cout<<"4.��һҳ"<<endl; 
		     int select;cin>>select;
		     if(select==1){a2=1;system("pause");system("cls");goto search3;} 
		     if(select==2){a2=2;system("pause");system("cls");goto search3;} 
		     if(select==3){a2=3;system("pause");system("cls");goto search3;} 
		     if(select==4){system("pause");system("cls");}
	         }
	         }}
	         if(sum2==0){cout<<"û���ҵ��鼮"<<endl;return;}
	         cout<<"1.��������"<<endl;
	         cout<<"2.������һ������"<<endl;
	         cout<<"3.�˳�����"<<endl; 
	         cin>>a2;
	           
search3:	   if(a2==1){
	           system("cls");
	           cout<<"���������������"<<endl;
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
	           if(sum3==0){cout<<"û���ҵ��鼮"<<endl;return;}
	           cout<<"1.������һ������"<<endl;
	           cout<<"2.�˳�����"<<endl; 
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
//��ͼ�� 
void library::borrowbook(long id){
borrowfunc:	 system("cls");
	 cout<<"��Ҫ����ı�ͼ�飿������"<<endl;
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
	      cout<<"��ȷ��Ҫ������� ����������1����������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ����"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
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
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }else if(this->booksarray[i].state==0){
	   cout<<"�ѽ�����㲻�ɽ���"<<endl;
	   return;
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
	      cout<<"��ȷ��Ҫ������� ����������1����������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ����"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
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
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	   }else if(this->booksarray[i].state==0){
	   cout<<"�ѽ�����㲻�ɽ���"<<endl;
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
	 cout<<"��������ȷ��������"<<endl; 
	 goto writersearch;
//}else if(sum1==1){
}else{
bianhaofunc:cout<<"��������Ҫ����ı�ţ�"<<endl;
	  int bianhao;cin>>bianhao;
	  if(this->booksarray[bianhao].state==1&&this->booksarray[bianhao].writer==writer_){
	      cout<<"��ȷ��Ҫ������ ����������1����������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ����"<<"��"<<this->booksarray[bianhao].topic<<"��"<<endl; 
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
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      }
	  }else if(booksarray[bianhao].writer!=writer_){
	  cout<<"��������ȷ�ı��"<<endl;
	  goto  bianhaofunc;
	  }else if(this->booksarray[bianhao].state==0){
	  cout<<"�ѽ�����㲻�ɽ���"<<endl;
	  return;
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
	      cout<<"��ȷ��Ҫ������� ����������1����������0"<<endl;
	      bool borrow;cin>>borrow;
	      if(borrow){
	      cout<<"���ѳɹ����"<<"��"<<this->booksarray[i].topic<<"��"<<endl; 
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
	      cout<<"����ȡ�����β���"<<endl; 
	      return; 
	      } 
	     }else if(this->booksarray[i].state==0){
	   cout<<"�ѽ�����㲻�ɽ���"<<endl;
	 return;
	 }
	 }}
	 cout<<"�Ҳ�������"<<endl; 
	 return; 
}else{
goto borrowfunc; 
}
}
//��ͼ�� 
void library::givebook(long id){
borrowfunc:	 cout<<"���ѽ��ĵ�ͼ�飺"<<endl;
	 int sum=0;
	 for(int i=0;i<this->booksnum;i++){
	 if(this->booksarray[i].ownerid==id){
	 sum++;
	 cout<<sum<<"."<<"����ı�ţ�"<<i<<endl; 
	 cout<<"  �����������"<<this->booksarray[i].topic<<endl;
	 cout<<"  �����ISBN/ISNN��"<<this->booksarray[i].type<<endl;
	 cout<<"  ��������ߣ�"<<this->booksarray[i].writer<<endl;
	 cout<<"  ����ķ���ţ�"<<this->booksarray[i].category<<endl;
	 }}
	 if(sum==0){
	 cout<<"�㻹δ�����鼮"<<endl; 
	 }else{
     cout<<"����������Ҫ������ı��:"<<endl;
     int bookid;cin>>bookid;
     cout<<"���ѳɹ��黹"<<"��"<<this->booksarray[bookid].topic<<"��"<<endl; 
     this->booksarray[bookid].state=1;
	 this->booksarray[bookid].ownerid=0;
	 this->booksave();
	 sum--;
	 if(sum>0){
	 cout<<"�������Ƿ���Ҫ�����黹��1-�� 2-��"<<endl;
	 int select;cin>>select;
	 if(select==1)
	 goto borrowfunc;
	 else return;}
	 else return;
     } 
}


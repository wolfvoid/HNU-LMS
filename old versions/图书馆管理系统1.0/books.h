#include"library.h"
using namespace std;

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
else if(xinxitype==4){
	 cout<<"����������"<<endl;
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
	 cout<<"�Ҳ��������ߵ��鼮"<<endl; 
	 return;}else return;
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


#include"library.h"
using namespace std;
int library::getrecordnum(){//ͳ�Ƽ�¼������ 
	ifstream ifs;
    ifs.open(filename,ios::in);
	long ownerid1;
	string topic1;
	string writer1;
	int state1;
	string category1;
     int num=0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1&&ifs>>category1) {
	num++;
	}
	return num;
}
void library::inirecord(){//���ļ� 
	ifstream ifs;
	ifs.open(filename,ios::in);
	long ownerid1;
	string topic1;
	string writer1;
	int state1;
	string category1;
     int i = 0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1&&ifs>>category1){
		recordarray[i].ownerid=ownerid1;
		recordarray[i].topic=topic1;
		recordarray[i].writer=writer1;
		recordarray[i].category=category1; 
	    i++; 
	}
	ifs.close();
	return;
}
//д�ļ� 
void library::recordsave(book Book){
	ofstream ofs;
	ofs.open(filename,ios::out|ios::app);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ�ν��ĵ�����д�뵽�ļ���
	    ofs<<endl;
		ofs<<Book.ownerid<<" ";
		ofs<<Book.topic<<" ";
		ofs<<Book.writer<<" ";
		ofs<<Book.category<<" ";
	    ofs.close();
}
void library::userborrowrecord(long id){//new 
	 int sum=0;
	 for(int i=recordnum-1;i>=0;i--){
	 	if(recordarray[i].ownerid==id){
	 	sum++;
	 	cout<<sum<<".";
		cout<<recordarray[i].topic<<" ";
		cout<<recordarray[i].writer<<" ";
		cout<<recordarray[i].category<<" ";
		for(int j=0;j<booksnum;j++){
	     if(recordarray[i].category==booksarray[j].category){
	     recordarray[i].state=booksarray[j].state;
	       if(recordarray[i].state==1){
		   cout<<"�ѹ黹"<<endl; 
		   break;
		  }else{cout<<"δ�黹"<<endl;
		  break;}
	     } 
		}
	 }
	 }
	 if (sum==0) cout<<"��δ�����κ�ͼ��"<<endl<<"���������ϼ�Ŀ¼"<<endl;
	 
	 return; 
}

void library::allborrowrecord()
{
	 for(int i=0;i<recordnum;i++){
	    cout<<recordarray[i].ownerid<<" ";
		cout<<recordarray[i].topic<<" ";
		cout<<recordarray[i].writer<<" ";
		cout<<recordarray[i].category<<" ";
		for(int j=0;j<booksnum;j++){
	     if(recordarray[i].category==booksarray[j].category){
	     recordarray[i].state=booksarray[j].state;}}
	       if(recordarray[i].state==1){
		   cout<<"�ѹ黹"<<endl; 
		  }else{cout<<"δ�黹"<<endl;}
	}
}


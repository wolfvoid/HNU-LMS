#include"library.h"
using namespace std;
int library::getrecordnum(){//ͳ�Ƽ�¼������ 
	ifstream ifs;
    ifs.open(filename,ios::in);
	long ownerid1;
	string topic1;
	string writer1;
	int state1;
     int num=0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1) {
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
     int i = 0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1){
		recordarray[i].ownerid=ownerid1;
		recordarray[i].topic=topic1;
		recordarray[i].writer=writer1; 
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
		this->recordnum++;
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
		for(int j=0;j<booksnum;j++){
	     if(recordarray[i].topic==booksarray[j].topic){
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
}//new 


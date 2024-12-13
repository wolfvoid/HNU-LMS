#include"library.h"
using namespace std;

int library::getrecordnum(){//统计记录的数量 
	ifstream ifs;
    ifs.open(filename,ios::in);
	long ownerid1;
	string topic1;
	string writer1;
	int state1;
     int num=0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1&&ifs>>state1) {
	num++;
	}
	return num;
}
void library::inirecord(){//读文件 
	ifstream ifs;
	ifs.open(filename,ios::in);
	long ownerid1;
	string topic1;
	string writer1;
	int state1;
     int i = 0;
	while(ifs>>ownerid1&&ifs>>topic1&&ifs>>writer1) {
		recordarray[i].ownerid=ownerid1;
		recordarray[i].topic=topic1;
		recordarray[i].writer=writer1; 
	    i++; 
	}
	ifs.close();
	return;
}
//写文件 
void library::recordsave(book Book){
	ofstream ofs;
	ofs.open(filename,ios::out|ios::app);//用输出的方式打开文件--写文件 
	//将每次借阅的数据写入到文件中
		ofs<<Book.ownerid<<" ";
		ofs<<Book.topic<<" ";
		ofs<<Book.writer<<" ";
	    ofs.close();
}
void library::borrowrecord(){
	 for(int i=0;i<recordnum;i++){
	    cout<<recordarray[i].ownerid<<" ";
		cout<<recordarray[i].topic<<" ";
		cout<<recordarray[i].writer<<" ";
	/*	if(recordarray[i].state==1){
		cout<<"已归还"<<endl; 
		}else cout<<"未归还"<<endl; */
	 }
	 }


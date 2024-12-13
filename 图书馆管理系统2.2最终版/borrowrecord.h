#include"library.h"
using namespace std;
int library::getrecordnum(){//统计记录的数量 
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
void library::inirecord(){//读文件 
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
//写文件 
void library::recordsave(book Book){
	ofstream ofs;
	ofs.open(filename,ios::out|ios::app);//用输出的方式打开文件--写文件 
	//将每次借阅的数据写入到文件中
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
		   cout<<"已归还"<<endl; 
		   break;
		  }else{cout<<"未归还"<<endl;
		  break;}
	     } 
		}
	 }
	 }
	 if (sum==0) cout<<"您未借阅任何图书"<<endl<<"即将返回上级目录"<<endl;
	 
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
		   cout<<"已归还"<<endl; 
		  }else{cout<<"未归还"<<endl;}
	}
}


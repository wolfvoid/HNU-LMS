#include"library.h"
using namespace std;
 
void library::zongmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.馆藏图书列表       *****"<<endl;
cout<<"***** 2.用户列表           *****"<<endl;
cout<<"***** 3.在馆记录           *****"<<endl;
cout<<"***** 4.用户借阅记录       *****"<<endl;
cout<<"***** 0.退出功能           *****"<<endl;
cout<<"********************************"<<endl;	
}
void library::checkmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.根据题名检索       *****"<<endl;
cout<<"***** 2.根据ISBN/ISSN检索  *****"<<endl;
cout<<"***** 3.根据作者检索       *****"<<endl;
cout<<"***** 4.根据分类号检索     *****"<<endl;
cout<<"***** 0.退出功能           *****"<<endl;
cout<<"********************************"<<endl;	}
void library::signmenu(){
cout<<"********************************"<<endl;	
cout<<"*****欢迎来到湖南大学图书馆*****"<<endl;
cout<<"*********请选择用户模式*********"<<endl;
cout<<"********************************"<<endl;	
cout<<"********************************"<<endl;	
cout<<"*****      1.用户模式     ******"<<endl;
cout<<"*****     2.管理员模式    ******"<<endl;
cout<<"*****   0.查看开发者信息  ******"<<endl;
cout<<"********************************"<<endl;	
}
void user::usermenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.修改密码          *****"<<endl;
cout<<"***** 2.搜索图书          *****"<<endl;
cout<<"***** 3.借图书            *****"<<endl;
cout<<"***** 4.还图书            *****"<<endl;
cout<<"***** 5.查看借阅记录      *****"<<endl;
cout<<"***** 0.退出登录          *****"<<endl;
cout<<"********************************"<<endl;
}
void library::xinxitypemenu(){
	 cout<<"****************************"<<endl;	
     cout<<"***** 1.topic          *****"<<endl;
     cout<<"***** 2.ISBN/ISSN      *****"<<endl;
     cout<<"***** 3.writer         *****"<<endl;
     cout<<"***** 4.category       *****"<<endl;
     cout<<"****************************"<<endl;
}
void administrator::administratormenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.管理用户账号       *****"<<endl;
cout<<"***** 2.修改图书信息       *****"<<endl;
cout<<"***** 3.搜索图书信息       *****"<<endl;
cout<<"***** 4.查看借阅情况       *****"<<endl;
cout<<"***** 0.退出登录           *****"<<endl;
cout<<"********************************"<<endl;
}
void administrator::manage_accountmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.添加用户账号       *****"<<endl;
cout<<"***** 2.删除用户账号       *****"<<endl;
cout<<"***** 3.重置用户密码       *****"<<endl;
cout<<"***** 4.初始化用户密码     *****"<<endl;
cout<<"***** 0.返回上一级目录     *****"<<endl;
cout<<"********************************"<<endl;
}
void administrator::modify_bookmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.管理用户账号       *****"<<endl;
cout<<"***** 2.修改图书信息       *****"<<endl;
cout<<"***** 3.搜索图书信息       *****"<<endl;
cout<<"***** 4.查看借阅情况       *****"<<endl;
cout<<"***** 0.退出登录           *****"<<endl;
cout<<"********************************"<<endl;
}
void library::borrowrecord(){
	 for(int i=0;i<recordnum;i++){
	    cout<<recordarray[i].ownerid<<" ";
		cout<<recordarray[i].topic<<" ";
		cout<<recordarray[i].writer<<" ";
		for(int j=0;j<booksnum;j++){
	     if(recordarray[i].topic==booksarray[j].topic){
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

void library::developerinfor()
{
	cout<<"*************************************************"<<endl;	
	cout<<"*****     恭喜成为第"<<1<<"位发现本系统的大佬     *****"<<endl;
	cout<<"*****       《湖南大学图书馆管理系统》      *****"<<endl;
	cout<<"*****      由湖南大学信息科学与工程学院     *****"<<endl;
	cout<<"*****     计科2102班 黄政、梅炳寅 编写      *****"<<endl;
//	cout<<"*****鸣谢 星空不费电 粗心大法斩IDE的波波老师*****"<<endl;//全靠bilibili 
//	cout<<"*****         和周二晚答疑谭彦恺助教        *****"<<endl;
	cout<<"*****                                       *****"<<endl;
	cout<<"*****           感谢您的使用与支持          *****"<<endl;
	cout<<"*************************************************"<<endl;
}




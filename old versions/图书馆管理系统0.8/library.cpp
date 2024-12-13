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
void administrator::administratormenu(){//new
cout<<"********************************"<<endl;	
cout<<"***** 1.修改密码          *****"<<endl;
cout<<"***** 2.搜索图书          *****"<<endl;
cout<<"***** 3.借图书            *****"<<endl;
cout<<"***** 4.还图书            *****"<<endl;
cout<<"***** 5.查看借阅记录      *****"<<endl;
cout<<"***** 0.退出登录          *****"<<endl;
cout<<"********************************"<<endl;
}//new



#include"library.h"
using namespace std;
 
void library::zongmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.�ݲ�ͼ���б�       *****"<<endl;
cout<<"***** 2.�û��б�           *****"<<endl;
cout<<"***** 3.�ڹݼ�¼           *****"<<endl;
cout<<"***** 4.�û����ļ�¼       *****"<<endl;
cout<<"***** 0.�˳�����           *****"<<endl;
cout<<"********************************"<<endl;	
}
void library::checkmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.������������       *****"<<endl;
cout<<"***** 2.����ISBN/ISSN����  *****"<<endl;
cout<<"***** 3.�������߼���       *****"<<endl;
cout<<"***** 4.���ݷ���ż���     *****"<<endl;
cout<<"***** 0.�˳�����           *****"<<endl;
cout<<"********************************"<<endl;	}
void library::signmenu(){
cout<<"********************************"<<endl;	
cout<<"*****��ӭ�������ϴ�ѧͼ���*****"<<endl;
cout<<"*********��ѡ���û�ģʽ*********"<<endl;
cout<<"********************************"<<endl;	
cout<<"********************************"<<endl;	
cout<<"*****      1.�û�ģʽ     ******"<<endl;
cout<<"*****     2.����Աģʽ    ******"<<endl;
cout<<"*****   0.�鿴��������Ϣ  ******"<<endl;
cout<<"********************************"<<endl;	
}
void user::usermenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.�޸�����          *****"<<endl;
cout<<"***** 2.����ͼ��          *****"<<endl;
cout<<"***** 3.��ͼ��            *****"<<endl;
cout<<"***** 4.��ͼ��            *****"<<endl;
cout<<"***** 5.�鿴���ļ�¼      *****"<<endl;
cout<<"***** 0.�˳���¼          *****"<<endl;
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
cout<<"***** 1.�����û��˺�       *****"<<endl;
cout<<"***** 2.�޸�ͼ����Ϣ       *****"<<endl;
cout<<"***** 3.����ͼ����Ϣ       *****"<<endl;
cout<<"***** 4.�鿴�������       *****"<<endl;
cout<<"***** 0.�˳���¼           *****"<<endl;
cout<<"********************************"<<endl;
}
void administrator::manage_accountmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.����û��˺�       *****"<<endl;
cout<<"***** 2.ɾ���û��˺�       *****"<<endl;
cout<<"***** 3.�����û�����       *****"<<endl;
cout<<"***** 4.��ʼ���û�����     *****"<<endl;
cout<<"***** 0.������һ��Ŀ¼     *****"<<endl;
cout<<"********************************"<<endl;
}
void administrator::modify_bookmenu(){
cout<<"********************************"<<endl;	
cout<<"***** 1.�����û��˺�       *****"<<endl;
cout<<"***** 2.�޸�ͼ����Ϣ       *****"<<endl;
cout<<"***** 3.����ͼ����Ϣ       *****"<<endl;
cout<<"***** 4.�鿴�������       *****"<<endl;
cout<<"***** 0.�˳���¼           *****"<<endl;
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
		   cout<<"�ѹ黹"<<endl; 
		   break;
		  }else{cout<<"δ�黹"<<endl;
		  break;}
	     } 
		}
	 }
}

void library::developerinfor()
{
	cout<<"*************************************************"<<endl;	
	cout<<"*****     ��ϲ��Ϊ��"<<1<<"λ���ֱ�ϵͳ�Ĵ���     *****"<<endl;
	cout<<"*****       �����ϴ�ѧͼ��ݹ���ϵͳ��      *****"<<endl;
	cout<<"*****      �ɺ��ϴ�ѧ��Ϣ��ѧ�빤��ѧԺ     *****"<<endl;
	cout<<"*****     �ƿ�2102�� ������÷���� ��д      *****"<<endl;
//	cout<<"*****��л �ǿղ��ѵ� ���Ĵ�նIDE�Ĳ�����ʦ*****"<<endl;//ȫ��bilibili 
//	cout<<"*****         ���ܶ������̷��������        *****"<<endl;
	cout<<"*****                                       *****"<<endl;
	cout<<"*****           ��л����ʹ����֧��          *****"<<endl;
	cout<<"*************************************************"<<endl;
}




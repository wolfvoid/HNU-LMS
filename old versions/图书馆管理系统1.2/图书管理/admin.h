#include"library.h"
using namespace std;

void library::admin_save() {//д�ļ� 
	ofstream ofs;
	ofs.open(a_acount, ios::out);//������ķ�ʽ���ļ�--д�ļ� 
	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < 50; i++) {
		ofs << adminarray[i].account << " "
			<< adminarray[i].password << endl;
	}
	ofs.close();
}
void library::iniadmin(){//��admin�ļ� 
	ifstream ifs;
	ifs.open(a_acount, ios::in);
	long account1;
	string password1;
	int i = 0;
	while (ifs >> account1 && ifs >> password1) {
		adminarray[i].account = account1;
		adminarray[i].password = password1;
	i++; 
	}
	ifs.close();
	return;
}

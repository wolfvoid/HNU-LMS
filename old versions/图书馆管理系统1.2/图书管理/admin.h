#include"library.h"
using namespace std;

void library::admin_save() {//写文件 
	ofstream ofs;
	ofs.open(a_acount, ios::out);//用输出的方式打开文件--写文件 
	//将每个人的数据写入到文件中
	for (int i = 0; i < 50; i++) {
		ofs << adminarray[i].account << " "
			<< adminarray[i].password << endl;
	}
	ofs.close();
}
void library::iniadmin(){//读admin文件 
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

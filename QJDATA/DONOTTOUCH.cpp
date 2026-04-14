#include <bits/stdc++.h>
using namespace std;

string a,b,c,d;
bool tmp;

bool checkyesno()
{
	string T;
	while(1)
	{
		cout<<"是否使用上次文件位置？y/n"<<endl;
		getline(cin,T);
		if(!cin.good())continue;
		if(T=="y")return 1;
		else if(T=="n")break;
		cout<<"请输入y或n哦"<<endl<<endl;
	}
	return 0;
}

string getfilename(int NUM)
{
	string tmpstr,tmpstr2;
	cout<<endl<<"请把exe["<<NUM<<"]拖拽进来，有无双引号无影响"<<endl;
//	if(NUM==1)getline(cin,tmpstr);
	getline(cin,tmpstr);
	if(tmpstr[0]=='\"')
	{
		tmpstr2=tmpstr;
//		cout<<"读取成功！文件路径为"<<tmpstr2<<endl;
	}
	else
	{
		tmpstr2="\""+tmpstr+"\"";
//		cout<<"读取成功！文件路径为"<<tmpstr2<<endl;
	}
	return tmpstr2;
}

string str_analyze(string AN)
{
	int ANtmpcnt=0;
	for(size_t i=0; i<AN.length(); ++i)
	{
//	    cout<<AN[i]<<endl;
		if(AN[i]=='\\')
		{
			ANtmpcnt=i;
//			cout<<i<<endl;
		}
//		cout<<i<<endl;
	}
	string ANtmp;
	ANtmp=AN.substr(ANtmpcnt+1,AN.length()-ANtmpcnt-2);
	return ANtmp;
}

const int BLACKLISTNUM=2;
string BLACKLIST[BLACKLISTNUM]= {"DONOTTOUCH.exe","DONOTTOUCH2.exe"};

bool scanBLACK(string T)
{
	int TL=T.length();
	if(TL<=3)return 1;
	if(T[TL-1]!='e'||T[TL-2]!='x'||T[TL-3]!='e'||T[TL-4]!='.')return 1;
	for(int i=0; i<BLACKLISTNUM; ++i)if(T==BLACKLIST[i])return 1;
	return 0;
}

int main()
{

	//确认是否覆写
	tmp=checkyesno();
	if(tmp)return 0;

	//获取文件
	a=getfilename(1);
	b=getfilename(2);

	//分析文件名
	c=str_analyze(a);
	d=str_analyze(b);
	
	//防呆安全措施
	if(scanBLACK(c)||scanBLACK(d))
	{
		cout<<endl<<"检测到违规输入！此次输入无效，将执行上次运行结果。按回车确认"<<endl<<endl;
		system("pause");
		return 0;
	}
	
	//打开bat
	freopen("copyfile.bat","w",stdout);

	//编写复制bat
	cout<<"copy "<<a<<" ."<<endl;
	cout<<"copy "<<b<<" ."<<endl;

	//编写重命名bat
	cout<<"del 1.exe"<<endl;
	cout<<"del 2.exe"<<endl;
	cout<<"ren \""<<c<<"\" "<<"1.exe"<<endl;
	cout<<"ren \""<<d<<"\" "<<"2.exe"<<endl;

	cout<<endl;
	return 0;
}


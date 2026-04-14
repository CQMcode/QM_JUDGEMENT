#include <bits/stdc++.h>
using namespace std;
const int MAXCR=6;
string compare_request[MAXCR+1]= {"","TC","TC trim right","TC display normal","TC display detailed","TC maxline","FC"};
int temp_input;

void OUTPUT_PROMPT()
{
	cout<<"请确认compare参数:"<<endl;
	for(int i=1; i<=MAXCR; ++i)
	{
		cout<<i<<" : "<<compare_request[i]<<endl;
	}
}

void INPUT_COMPARE()
{
	while(1)
	{
		cout<<endl;
		cout<<"请输入1-"<<MAXCR<<":"<<endl;
		cin>>temp_input;
		if(cin.good()&&temp_input>0&&temp_input<=MAXCR)return;
		cout<<"输入有误！请检查输入"<<endl;
	}
	return;
}

void FULFILL_REQUEST()
{
	int MAXLINE=0;
	if(temp_input==5)
	{
		while(1)
		{
			cout<<endl<<"请额外输入一个参数（比如541）:"<<endl;
			cin>>MAXLINE;
			if(cin.good()&&MAXLINE>0)break;
			else cout<<"输入不合法！"<<endl<<endl;
		}
	}
	cout<<"=====SUCCESS.====="<<endl;
	
	freopen("checkfile.bat","w",stdout);
	
	cout<<"@echo off"<<endl;
	cout<<"echo."<<endl;
	cout<<"echo ========== 比较文件 =========="<<endl;
	
	switch(temp_input)
	{
	case 1:
		cout<<"txt_compare --file1 1.out --file2 2.out"<<endl;
		break;
	case 2:
		cout<<"txt_compare --trim right --file1 1.out --file2 2.out"<<endl;
		break;
	case 3:
		cout<<"txt_compare --display normal --file1 1.out --file2 2.out"<<endl;
		break;
	case 4:
		cout<<"txt_compare --display detailed --file1 1.out --file2 2.out"<<endl;
		break;
	case 5:
		cout<<"txt_compare --file1 1.out --file2 2.out --max_line "<<MAXLINE<<endl;
		break;
	case 6:
		cout<<"FC 1.out 2.out"<<endl;
	}
}

int main()
{
	OUTPUT_PROMPT();
	INPUT_COMPARE();
	FULFILL_REQUEST();
	return 0;
}

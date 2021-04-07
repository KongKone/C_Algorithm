#include<iostream>
#include<cstring>
#include<assert.h>
#include<vector>
#include<cstdio>
#define _f(i,a,b) for(int i=(a);i<(b);i++)
#define MAXSIZE 105
using namespace std;//记错，vector的pushback不能加入一个数组 
void check(const char[],const char[],const int,int&);
char a[MAXSIZE],b[MAXSIZE];
int lenb,lena;
int main()
{
	//freopen("input.txt","r",stdin);
	bool flag=false;
	while(cin>>a>>b){
		lena = strlen(a);
		lenb= strlen(b);
		assert((lena>0 && lena <MAXSIZE)||(lenb>0 && lenb<MAXSIZE));
		int LEN1=0,LEN2=0;
		check(a,b,lena,LEN1);
		check(b,a,lenb,LEN2);
		int sumlen=lena+lenb;
		LEN1=sumlen-LEN1;
		LEN2=sumlen-LEN2;
		if(flag) cout<<endl;
		if(LEN1<LEN2) cout<<LEN1;
		else cout<<LEN2;
		flag=true;
	}
	return 0;
}
inline int min(int lena,int lenb){
	if(lena<lenb) return lena;
	else return lenb;
}
void check(const  char *a,const char *b,const int len,int &LEN){
	bool legal;
	_f(i,0,len){ 
		legal=true;
		_f(j,0,len-i)
			if(a[i+j]=='2'&&b[j]=='2') {legal=false;break;}//a数组相当于左移 
		if(legal&&LEN<min(len-i,lenb)) LEN=min(len-i,lenb);//如果匹配成功则记录长度 
	}
}

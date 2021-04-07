#include<cmath>
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const double EPS = 1e-6;
double M[11][35];
int E[11][35];
int main()
{
	//freopen("input.txt","r",stdin);
	double A,t;int B;
	char line[255];
	double m;
	long long e;
	while(scanf("%s",&line)==1&&strcmp(line,"0e0")!=0){
		*strchr(line,'e')=' ';//这个函数会返回line字符串内第一次出现的'e'字符的地址。
		sscanf(line,"%lf%d",&A,&B);//printf("%.15llf %d",A,B);
		//cout<<log2(floor(log2(pow(10,B+1))))+1<<endl;
		for(int i=1;i<10;i++){// 打表 
			for(int j=1;j<=30;j++){
				m=1-1.0/(1<<(i+1)); 
				e=(1<<j)-1;
				t=log10(m)+e*log10(2);
				E[i][j]=floor(t);//t-->log10(m)+e*log10(2)=log10(A)+B;   t-log10(A)=B. 由于1=<A<=9,B为整数 所以log10为t的小数。 
				M[i][j]=pow(10,t-B);//A=10^(t-B) 
			}
		}
		//check
		for(int i = 0 ; i < 10 ; i++)
		for(int j = 0 ; j <= 30 ;j++){
			if((E[i][j]==B)&&(A-M[i][j] <= EPS)){
				cout<<i<<" "<<j<<endl;	
				goto end;
			}
		}
		end:;
	}
	return 0;
} 

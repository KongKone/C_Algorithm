#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
 
using namespace std;
 
double M[11][33];	//�洢��Ӧβ��
long long E[11][33];	//�洢��Ӧָ��
const double min_differ=1e-5;	//�������
void solve(double m,long long e);
 
int main()
 {
	int i,j;
	double m,t;
	long long e;
	char str[22];
	for(i=0;i<=9;i++)
		for(j=1;j<=30;j++)
		{
			e=(1<<j)-1;		//����������ʽ���ÿһ����Ӧλ��β����ָ���ֱ�洢
			m=1-1.0/(1<<(i+1));
			t=log10(m)+e*log10(2);
			E[i][j]=t/1;
			M[i][j]=pow(10,t-E[i][j]);
		}
	while(cin>>str,strcmp(str,"0e0"))
	{
		*(strchr(str,'e'))=' ';		//���ַ����е�e�滻�ɿո�
		sscanf(str,"%lf %lld",&m,&e);	//����sscanf����ָ�β����ָ��
		solve(m,e);
	}
 
	return 0;
}
void solve(double m,long long e)	//��ƥ����̷ŵ������У�ƥ�����Լ�ʱ�ж�
{
	int i,j;
	for(i=0;i<=9;i++)
		for(j=1;j<=30;j++)
			if(e==E[i][j]&&fabs(m-M[i][j])<min_differ)	//��ָ�����ڱ�����������β����ֵ����ֵС�����ʱ��ƥ�䣬����𰸣���������
			{
				cout<<i<<" "<<j<<endl;
				return;
			}
} 


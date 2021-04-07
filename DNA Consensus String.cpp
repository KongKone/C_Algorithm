#include<cstdio> 
#include<cstring>
#include<string.h>
#include<assert.h>
#include<vector> 
#include<iostream>
using namespace std;
#define maxn 1005
#define maxm 55
using namespace std;
int max(int a[]);
char maxC(int maxi);
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T){
		int m,n;
		scanf("%d%d",&m,&n);		
		vector<string> s1;
		string line;
		//��ȡ 
		for(int i = 0; i < m ; i++){
			cin>>line;
			assert(line.size()==n);
			s1.push_back(line);
		}
		string s2="";//�洢���Ž� 
		int Econsensus=0;//ͳ�Ʒǹ������� 
		int mark[4];//�洢���ֵ���ĸ�ĸ��� 
		for(int i = 0 ; i < n ; i++){
			memset(mark,0,sizeof(mark));//���� 
			for(int j = 0; j < m ; j++){//ͳ�� 
				if(s1[j][i]=='A') mark[0]++;
				if(s1[j][i]=='C') mark[1]++;
				if(s1[j][i]=='G') mark[2]++;
				if(s1[j][i]=='T') mark[3]++;
			}
			int maxi = max(mark);//�ҳ��ִ���������ֵ�������С������ 
			s2+=(maxC(maxi));
			Econsensus += (m-mark[maxi]);
		}
		///���/// 
		cout<<s2<<endl;
		cout<<Econsensus;
		T--;
		if(T) printf("\n"); 
	}
	return 0;
}
inline int max(int a[]){
	int maxi=0;
	for(int i = 1 ;i < 4 ; i++) if(a[maxi]<a[i]) maxi=i;
	return maxi;
}
inline char maxC(int maxi){
	if(maxi == 0) return 'A';
	else if(maxi == 1) return 'C';
	else if(maxi == 2) return 'G';
	else return 'T';
}

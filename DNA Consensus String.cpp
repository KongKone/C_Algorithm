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
		//读取 
		for(int i = 0; i < m ; i++){
			cin>>line;
			assert(line.size()==n);
			s1.push_back(line);
		}
		string s2="";//存储最优解 
		int Econsensus=0;//统计非共性总数 
		int mark[4];//存储出现的字母的个数 
		for(int i = 0 ; i < n ; i++){
			memset(mark,0,sizeof(mark));//归零 
			for(int j = 0; j < m ; j++){//统计 
				if(s1[j][i]=='A') mark[0]++;
				if(s1[j][i]=='C') mark[1]++;
				if(s1[j][i]=='G') mark[2]++;
				if(s1[j][i]=='T') mark[3]++;
			}
			int maxi = max(mark);//找出现次数最多且字典序列最小的坐标 
			s2+=(maxC(maxi));
			Econsensus += (m-mark[maxi]);
		}
		///输出/// 
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

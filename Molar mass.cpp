#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define maxn 85
const double a[]={12.01,1.008,16.0,14.01};

double what(char c){
	if(c=='C') return a[0];
	if(c=='H') return a[1];
	if(c=='O') return a[2];
	if(c=='N') return a[3];
}
int fold(int x){
	if(x==1) return 1;
	if(x==2) return 10;
	if(x==3) return 100;
	if(x==4) return 1000;
	if(x==5) return 10000; 
}
char s[maxn];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		double sum = 0.0;
		for(int i = 0;i < strlen(s);i++)
		{
			if(isalpha(s[i])){
				if(isdigit(s[i + 1])){
					int count = 0;//count统计位数，
					char b[5];//b数组存储数字
					for(int j = i + 1;isdigit(s[j]);j++){
						b[count++] = s[j];
					}//获取数字
		
					int x = 0,a = count;
					for(int z = 0;z < count; z++){
						x += (b[z]-'0') * fold(a--);
					}//求得数字
					
					sum+=x*what(s[i]);
				}else{
					sum += what(s[i]);
				}
			}
		}
		printf("%.3f\n",sum);
	}
	return 0;
}

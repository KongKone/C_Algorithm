#include<stdio.h>
#include<string.h>

#define maxn 85

char a[maxn];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",a);
		int len=strlen(a);
		char s[len];
		
		for(int i=0;i<len;i++){
			s[i]=a[i];//逐个尝试 
			int j;
			for(j=0;j<len;j=(j+i+1)){//对比 
				for(int z=0;z<i+1;z++){
					if(s[z]!=a[j+z]){
						goto again;//跳出循环 
					}
				}
			}
			again:
			if(T){
				if(j == len){
					printf("%d\n\n",i+1);
					break;
				}
			}else{
				if(j == len){
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}
}

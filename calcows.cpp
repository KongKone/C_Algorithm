#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define maxn 60
int a[maxn];
int main(){
	int n,cows;
	for(int i=1;i<5;i++){//初始化 
		a[i]=1;
	}
	while(scanf("%d",&n)){
		if(n==0) break;
		if(n<5){
			printf("%d\n",n);	
		}else{
			cows=4;
			for(int year=4;year<n;year++){//数组记录母牛 
				a[year+1]=a[year]+a[year-2];
				cows+=a[year+1];//累加 
			}
			printf("%d\n",cows);
		}
	}
	return 0;
} 

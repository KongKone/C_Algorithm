#include<stdio.h>
#define maxn 1000000
int a[maxn];//只有数组a放在外面时，才能开得很大。否则会异常退出。 
int main()
{
	
	int x,n=0;
	while(scanf("%d",&x)==1){
		a[n++]=x;
	}
	for(int i=n-1;i>=1;i--){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[0]);
return 0;
}//比较大的数组应该尽量声明在main函数外，否则程序可能无法运行。 

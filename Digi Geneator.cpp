#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxn 100000
int a[maxn];
int main()
{
	memset(a,0,sizeof(a));
	for(int m=1;m<maxn;m++)//枚举1到100000之间的正整数的m，然后标记“m加上m的各个数字之和”作为a数组的下标，最后把m赋值给a[y]。 
	{
		int x,y;
		x=m;y=m;
		while(x>0){
			y+=x%10;
			x/=10;
		}
		if(a[y]==0||m<a[y]) a[y]=m;//判断条件，为了求得最小 生成元 
	}
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	
	return 0;
}

#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)//for(int i=2;i<=(n-1)*2;i=i+2)
	{
		printf("%d\n",i*2);//printf("%d\n",2*i);
	}
	return 0;
}

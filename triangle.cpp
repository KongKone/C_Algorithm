#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n>20||n<1)
		n=20;
	int j=1+(n-1)*2;//��an����ֵ 
	for(int z=n;z>0;z--){//������������� 
		for(int n1=0;n1<n-z;n1++)//��������ո������ 
			printf(" ");
		for(int j1=0;j1<j;j1++)//�������#������ 
			printf("#");
		printf("\n");
		j=j-2;
	}
	return 0;
}

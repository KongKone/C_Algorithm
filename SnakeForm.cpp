#include<stdio.h>
#include<string.h>
#define max 20
int a[max][max];
int main()
{
	int n,x,y;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	int tot=1;
	a[x=0][y=n-1]=1;
	while(tot<n*n){
		while(x<n-1&&!a[x+1][y]) a[++x][y]=++tot;//�� 
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;//�� 
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;//�� 
		while(y<n-1&&!a[x][y+1]) a[x][++y]=++tot;//�� 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0; 
} 

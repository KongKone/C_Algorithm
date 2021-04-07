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
		while(x<n-1&&!a[x+1][y]) a[++x][y]=++tot;//об 
		while(y-1>=0&&!a[x][y-1]) a[x][--y]=++tot;//вС 
		while(x-1>=0&&!a[x-1][y]) a[--x][y]=++tot;//ио 
		while(y<n-1&&!a[x][y+1]) a[x][++y]=++tot;//ср 
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

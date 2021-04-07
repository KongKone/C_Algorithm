#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
int deng[max];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) //初始化灯笼开关 
		deng[i]=0;
	/*另一种写法*/	
	//memset(a,0,sizeof(a)); 
		
	for(int j=1;j<=k;j++)//控制开关灯的次数 ，以k人数为封顶 
	{
		for(int z=1;z<=n;z++){//遍历灯笼编号 
			if(z%j==0){//把第z个人与灯笼编号取余求是否为倍数 
				if(deng[z]==0){
					deng[z]=1;
				}
				else{
					deng[z]=0;
				}
			}
		}
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(deng[i]==1){
			if(flag){
				flag=false;
			}else{
				printf(" ");
			}
			printf("%d",i);
		}
	}
	return 1;
} 

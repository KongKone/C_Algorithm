#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1000
int deng[max];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) //��ʼ���������� 
		deng[i]=0;
	/*��һ��д��*/	
	//memset(a,0,sizeof(a)); 
		
	for(int j=1;j<=k;j++)//���ƿ��صƵĴ��� ����k����Ϊ�ⶥ 
	{
		for(int z=1;z<=n;z++){//����������� 
			if(z%j==0){//�ѵ�z������������ȡ�����Ƿ�Ϊ���� 
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

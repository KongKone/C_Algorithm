#include<stdio.h>
#include<ctype.h>
#include<string.h>
 
 
 int main(){
 	freopen("input.txt","r",stdin);
 	freopen("output.txt","w",stdout);
 	int a[10];
 	int T;
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		int N;
		scanf("%d",&N);
		for(int i=1;i<=N;i++){//����1~N 
			int j=i;
			while(j){//���� 
				int digit=j%10;
				a[digit]++;//��¼���ֵ����� 
				j/=10;
			}
		}
		for(int j=0;j<9;j++){
			printf("%d ",a[j]);
		}
		printf("%d\n",a[9]);
	}
 	
 }

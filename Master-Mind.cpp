#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define maxn 1000
int main()
{
	int n,Case = 0,a[maxn],b[maxn];
	while(n){
	AG:	system("cls");
		printf("########################################\n");
		printf("# 猜数字小游戏！！！！                 #\n");
		printf("# 提示：                               #\n");
		printf("#     A为多少个数字位置正确。          #\n");
		printf("#     B为两个序列都出现过但是位置不同。#\n");
		printf("########################################\n");
		printf("先输入序列长度："); 
		scanf("%d",&n); 
		for(int i = 0;i < n;i++){
			a[i]=rand()%8+1;
		}
		if(a[0]) printf("序列已生成。。。\n\n");
		printf("Game %d:\n",++Case);
		printf("可以开始猜了。\n"); 
		for(;;){
			int A = 0,B = 0;
			for(int i = 0;i < n;i++){
				scanf("%d",&b[i]);
				if(b[i] == a[i]) A++;
			}
			if(b[0] == 0) break;
			for(int d = 1;d < 9;d++){
				int c1 = 0,c2 = 0;
				for(int j = 0;j < n;j++){
					if(b[j] == d) c1++;
					if(a[j] == d) c2++;
				}
				if(c1<c2) B+=c1; else B+=c2;
			}//统计两个序列都出现过的数字的数量
			printf("   (A%d,B%d)\n",A,B-A);
			if(A==n){
				printf("恭喜你答对了！\n\n\n");
				char y;
				printf("是否继续y/n:");
				fflush(stdin);
				scanf("%c",&y);
				if(y=='y'||y=='Y') 
					goto AG;
				else{
					printf("886!!");
					exit(0);
				}		
			}
		}
	}
	return 0;
}

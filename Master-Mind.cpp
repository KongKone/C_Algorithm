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
		printf("# ������С��Ϸ��������                 #\n");
		printf("# ��ʾ��                               #\n");
		printf("#     AΪ���ٸ�����λ����ȷ��          #\n");
		printf("#     BΪ�������ж����ֹ�����λ�ò�ͬ��#\n");
		printf("########################################\n");
		printf("���������г��ȣ�"); 
		scanf("%d",&n); 
		for(int i = 0;i < n;i++){
			a[i]=rand()%8+1;
		}
		if(a[0]) printf("���������ɡ�����\n\n");
		printf("Game %d:\n",++Case);
		printf("���Կ�ʼ���ˡ�\n"); 
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
			}//ͳ���������ж����ֹ������ֵ�����
			printf("   (A%d,B%d)\n",A,B-A);
			if(A==n){
				printf("��ϲ�����ˣ�\n\n\n");
				char y;
				printf("�Ƿ����y/n:");
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

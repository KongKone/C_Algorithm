#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#define maxn 100000
int a[maxn];
int main()
{
	memset(a,0,sizeof(a));
	for(int m=1;m<maxn;m++)//ö��1��100000֮�����������m��Ȼ���ǡ�m����m�ĸ�������֮�͡���Ϊa������±꣬����m��ֵ��a[y]�� 
	{
		int x,y;
		x=m;y=m;
		while(x>0){
			y+=x%10;
			x/=10;
		}
		if(a[y]==0||m<a[y]) a[y]=m;//�ж�������Ϊ�������С ����Ԫ 
	}
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	
	return 0;
}

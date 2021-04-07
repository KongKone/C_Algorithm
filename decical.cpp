#include<stdio.h>
#include<math.h>
#define INF 1000000
int main()
{
	int a,b,c;
	int decimal;
	int count=0;
	while(scanf("%d%d%d",&a,&b,&c)&&a&&b&&c){
	printf("Case%d: %d.",++count,(a/b));
	for(int i=1;i<c;i++){
		a=a*10;
		decimal=a/b;
		printf("%d",decimal%10);
	}
	decimal=round((double)a*10/b);//round is to ËÄÉáÎåÈë 
	printf("%d\n",decimal%10);
	}
	return 0;
}

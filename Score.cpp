#include <stdio.h>
#include <string.h>
#define maxn 85
#define _for(i,a,b) for(int i=a;i<b;i++)
char s[maxn];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		int score=0;
		int sum=0;
		_for(i,0,strlen(s))
		{
			if(s[i]=='O'){
				if(s[i]=='O') sum++;
				score+=sum;
			}else if(s[i]=='X'){
				sum=0;
			}
		}
		printf("%d\n",score);
	}
	return 0;
}

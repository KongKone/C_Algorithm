#include<stdio.h>
#include<string.h>
#define maxn 105
char s[maxn];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int n=2;
while(n--!=0){
	scanf("%s",s);
	int len=strlen(s);
	int ans=0;
	for(int i=1;i<len;i++)
	for(int j=0;j<len;j++){
		if(s[(i+j)%len]!=s[(ans+j)%len]){
			if(s[(i+j)%len]<s[(ans+j)%len]){
				ans=i;
			}
			break;
		}
	}
	for(int i=0;i<len;i++){
		putchar(s[(ans+i)%len]);
	}
	printf("\n");
}
return 0;
}

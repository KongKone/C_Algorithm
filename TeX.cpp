#include<stdio.h>
int main()
{
	int c,q=1;
	while((c=getchar())!=EOF){//getchar返回的是int值，一i那位getchar（）在结束时会返回一个特殊标记EOF， 
		if(c=='"'){				//如果返回的是char则无法把特殊标记EOF无法和普通标记区分开来 
			printf("%s",q?"“":"”");//双引号要用s形式输出 因为双引号不再ASCII表内 
			q=!q; 
		}else{
			printf("%c",c);
		}
	}
	return 0;
} 

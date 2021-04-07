#include<stdio.h>
#include<string.h>
int main()
{
	char s[20],buf[100];
	scanf("%s",s);
	int count=0;
	for(int abc=111;abc<999;abc++)
	for(int de=11;de<99;de++)
	{
		bool Yes=true;
		int x=abc*(de%10),y=abc*(de/10),sum=abc*de;
		sprintf(buf,"%d%d%d%d%d",abc,de,x,y,sum);
		for(int i=0;i<strlen(buf);i++)
		{
			if(strchr(s,buf[i])==NULL){//strchr 在参数 s 所指向的字符串中搜索第一次出现字符 buf[i]（一个无符号字符）的位置。
				Yes=false;
			//	break;
			}
		}
		if(Yes){
			printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",++count,abc,de,x,y,sum); 
		}
	}
	printf("The number of solutions = %d",count);
	return 0 ;
}
//先输入一个特定数集s 
//然后求得x，y，积 
// 把x,y,积放入buf字符组内，然后逐个与 s对比，如存在非子集，则给Yes=false，说明没解
//最后输出完整竖型 

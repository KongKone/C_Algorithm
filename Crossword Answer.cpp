#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 15 
/*我的思路：
	1.先解决输入问题。
	2.横向计算要比纵向简单
	3.纵向比较麻烦。
		我是这样想的。
		第一行的所有字母，必定都是起始格。所以我事先输出第一行的所有纵向单词。
		而后再去想办法找出从第二行开始的所有纵向单词。
		我找到这么一个规律，从第二行开始的纵向单词，上一行必定有一个
		'*'符号，所以我只要判定上一行有没有这个符号，就能找到下一个单词了。 
 */ 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int count=1;
	while(1){
		int r,c;
		char s[maxn][maxn];
		//memset(s,'&',sizeof(s));//不知道为什么，Debug的时候，第二次循环时 ，这里的s字符组 没有清空字符组里面的字符， 
		//会引起结果输出错误的答案 ，只能出此下策 
		
		scanf("%d",&r);
		if(r==0) goto end; 
		scanf("%d",&c);
		getchar();//清掉输入的'\n' 
		
		
		//这里是存储样式 
		for(int i = 0 ; i < r ; i++)
		{
			char c = getchar();
			for(int j = 0;c != '\n' ;)
			{
				if(c=='*'||isalpha(c)){
					s[i][j++]=c;
				}
				c=getchar();
				
				
//				s[i][j++]=cc;
//				cc=getchar();
			}
		}
		
		////////////////从这里开始计算Answer/////////////////
		 
		if(count==1){
			printf("puzzle #%d:\n",count++);
			printf("Across");
		}
		else{
			printf("\npuzzle #%d:",count++);
			printf("\nAcross");
		}
		int Case=0;
		int flag=1;//用于控制序号 
		//这里是输出横向单词
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				
				if(isalpha(s[i][j])&&((i-1)<0||(j-1)<0||s[i][j-1]=='*'||s[i-1][j]=='*')){//判断是否为起始格 
					Case++;
				}
				
				if(isalpha(s[i][j])){//如果为字母 
					if(flag){
						printf("\n %2d.",Case);
						flag=0;
					}
					printf("%c",s[i][j]);
				}else{
					flag=1;
				}
			}
			flag=1;
		} 
		
		
		Case=0;
		flag=1; 
		printf("\nDown");
		//这里是输出第一行的纵向单词 
		for(int i = 0 ; i < c ; i++){
			for(int j = 0 ; j < r ; j++){

				if(isalpha(s[j][i])){//如果为字母 
					if(flag){
						printf("\n %2d.",++Case);
						flag=0;
					}
					printf("%c",s[j][i]);
				}else{
					flag=1;
					break;
				}
				
			}
			flag = 1;
		}
		//////////这里是输出从第二行开始的纵向单词//////// 
		//遍历每一个单词 
		for(int i = 1 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if(isalpha(s[i][j])&&(j==0||s[i][j-1]=='*'||s[i-1][j]=='*')){//判断是否为起始格 
					Case++;
					if(s[i-1][j]=='*'){//判断上一行同一列的字符是否为*  如果是则说明为下一个输出的单词。 
						printf("\n %2d.",Case);
					
						//只需输出纵列的字符 
						for(int x = i ; x < r ; x++){
							if(s[x][j] != '*'){
								printf("%c",s[x][j]);
							}else{
								break;
							}
						}
					}
				}else{
					continue;
				}
			}
		}
		printf("\n");
		
/*		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
				printf("%c",s[i][j]);
			printf("\n");
		}*/
	}
	end:
	return 0;
}

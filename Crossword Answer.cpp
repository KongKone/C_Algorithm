#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 15 
/*�ҵ�˼·��
	1.�Ƚ���������⡣
	2.�������Ҫ�������
	3.����Ƚ��鷳��
		����������ġ�
		��һ�е�������ĸ���ض�������ʼ�����������������һ�е��������򵥴ʡ�
		������ȥ��취�ҳ��ӵڶ��п�ʼ���������򵥴ʡ�
		���ҵ���ôһ�����ɣ��ӵڶ��п�ʼ�����򵥴ʣ���һ�бض���һ��
		'*'���ţ�������ֻҪ�ж���һ����û��������ţ������ҵ���һ�������ˡ� 
 */ 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int count=1;
	while(1){
		int r,c;
		char s[maxn][maxn];
		//memset(s,'&',sizeof(s));//��֪��Ϊʲô��Debug��ʱ�򣬵ڶ���ѭ��ʱ �������s�ַ��� û������ַ���������ַ��� 
		//���������������Ĵ� ��ֻ�ܳ����²� 
		
		scanf("%d",&r);
		if(r==0) goto end; 
		scanf("%d",&c);
		getchar();//��������'\n' 
		
		
		//�����Ǵ洢��ʽ 
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
		
		////////////////�����￪ʼ����Answer/////////////////
		 
		if(count==1){
			printf("puzzle #%d:\n",count++);
			printf("Across");
		}
		else{
			printf("\npuzzle #%d:",count++);
			printf("\nAcross");
		}
		int Case=0;
		int flag=1;//���ڿ������ 
		//������������򵥴�
		for(int i = 0 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				
				if(isalpha(s[i][j])&&((i-1)<0||(j-1)<0||s[i][j-1]=='*'||s[i-1][j]=='*')){//�ж��Ƿ�Ϊ��ʼ�� 
					Case++;
				}
				
				if(isalpha(s[i][j])){//���Ϊ��ĸ 
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
		//�����������һ�е����򵥴� 
		for(int i = 0 ; i < c ; i++){
			for(int j = 0 ; j < r ; j++){

				if(isalpha(s[j][i])){//���Ϊ��ĸ 
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
		//////////����������ӵڶ��п�ʼ�����򵥴�//////// 
		//����ÿһ������ 
		for(int i = 1 ; i < r ; i++){
			for(int j = 0 ; j < c ; j++){
				if(isalpha(s[i][j])&&(j==0||s[i][j-1]=='*'||s[i-1][j]=='*')){//�ж��Ƿ�Ϊ��ʼ�� 
					Case++;
					if(s[i-1][j]=='*'){//�ж���һ��ͬһ�е��ַ��Ƿ�Ϊ*  �������˵��Ϊ��һ������ĵ��ʡ� 
						printf("\n %2d.",Case);
					
						//ֻ��������е��ַ� 
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

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
			if(strchr(s,buf[i])==NULL){//strchr �ڲ��� s ��ָ����ַ�����������һ�γ����ַ� buf[i]��һ���޷����ַ�����λ�á�
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
//������һ���ض�����s 
//Ȼ�����x��y���� 
// ��x,y,������buf�ַ����ڣ�Ȼ������� s�Աȣ�����ڷ��Ӽ������Yes=false��˵��û��
//�������������� 

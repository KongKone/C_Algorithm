#include<stdio.h>
int main()
{
	int c,q=1;
	while((c=getchar())!=EOF){//getchar���ص���intֵ��һi��λgetchar�����ڽ���ʱ�᷵��һ��������EOF�� 
		if(c=='"'){				//������ص���char���޷���������EOF�޷�����ͨ������ֿ��� 
			printf("%s",q?"��":"��");//˫����Ҫ��s��ʽ��� ��Ϊ˫���Ų���ASCII���� 
			q=!q; 
		}else{
			printf("%c",c);
		}
	}
	return 0;
} 

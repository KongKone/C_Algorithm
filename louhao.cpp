#include<stdio.h>
#include<string.h>
#define maxn 100
int max(int,int);
int min(int,int);
int isPlu(int);
int a[maxn],b[maxn];
int main()
{
	int w,m,n,minInstance;
	scanf("%d%d%d",&w,&m,&n);   
	int j=w;
	b[0]=1;
	for(int i=1 ;i<w;i++)//���ڸ����㣬���ж�x1-x2��ľ���  b={1,w,w-1,w-2,w-3,2} 
	{
		b[i]=j--;
	}

	a[0]=w;
	j=1;
	for(int i=1;i<w;i++)//���ڵ����㣬���ж�x1-x2��ľ���  b={w,1,2,3,4,....w-1} 
	{	
		a[i]=j++;
	}
	//////////////////////////////////////////
/*		for(int i=0;i<w;i++)//˫����a���飬�����ж�x����� 
	{	
		printf("%d ",a[i]);
	}
		for(int i=0;i<w;i++)//˫����a���飬�����ж�x����� 
	{	
		printf("%d ",b[i]);
	} */ //����ֻ��Ϊ�˲鿴a��b�����ʼ���Ƿ���ȷ 



	int Xm,Xn;
	if(m>w){
		if(m%w==0)//�ж�m��¥�Ƿ������� ,���m���ڲ��� 
			Xm=m/w;
		else
			Xm=m/w+1;
	}else if(m<w||m==w)
		Xm=1;
		
	if(n>w){
		if(n%w==0)//�ж�n��¥�Ƿ������� ,���n���ڲ� 
			Xn=n/w;
		else
			Xn=n/w+1;
	}else if(n<w||n==w)
		Xn=1;
		
	int y=max(Xm,Xn)-min(Xm,Xn);//���y����� 
///////////////////////////////////////////////////////////////////////////////	


	//����Xm��Xn���������ã�һ����Ϊ�����y����롣  ��������x�����ʱ����Ҫ�õ������ж��Ƿ�Ϊ�����㡣 
	
	
	
	int x1,x2;
	if(isPlu(Xm))//�жϲ���Xm�Ƿ�Ϊ�����㣬�Դ�����������a���黹��b���顣 
		x1=b[m%w]; 
	else
		x1=a[m%w];
//		printf(" %d %d ",Xm,Xn); ����ֻ��Ϊ�˲鿴�����Ƿ������ȷ 
		
	if(isPlu(Xn))//�жϲ���Xn�Ƿ�Ϊ�����㣬�Դ�����������a���黹��b���顣 
		x2=b[n%w];
	else
		x2=a[n%w];
		 
	int x=max(x1,x2)-min(x1,x2);// �ó�x1��x2�ľ���x
////////////////////////////////////////////////////////////////////////////////

	
	minInstance=x+y;//���y������ x�������� �ó��ܾ��� 
	printf("%d\n",minInstance); 
	return 0;
	
} 
int max(int a,int b)//�ж���� 
{
	if(a>b)
	return a;
	else
	return b;
}
int min(int a,int b)//�ж���С 
{
	if(a<b)
	return a;
	else
	return b;
}
int isPlu(int a)// �жϸ��� 
{
	if(a%2==0)
		return 1;
	else
		return 0;
}

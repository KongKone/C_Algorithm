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
	for(int i=1 ;i<w;i++)//用于复数层，以判断x1-x2轴的距离  b={1,w,w-1,w-2,w-3,2} 
	{
		b[i]=j--;
	}

	a[0]=w;
	j=1;
	for(int i=1;i<w;i++)//用于单数层，以判断x1-x2轴的距离  b={w,1,2,3,4,....w-1} 
	{	
		a[i]=j++;
	}
	//////////////////////////////////////////
/*		for(int i=0;i<w;i++)//双数层a数组，用于判断x轴距离 
	{	
		printf("%d ",a[i]);
	}
		for(int i=0;i<w;i++)//双数层a数组，用于判断x轴距离 
	{	
		printf("%d ",b[i]);
	} */ //这里只是为了查看a，b数组初始化是否正确 



	int Xm,Xn;
	if(m>w){
		if(m%w==0)//判断m号楼是否有余数 ,求得m所在层数 
			Xm=m/w;
		else
			Xm=m/w+1;
	}else if(m<w||m==w)
		Xm=1;
		
	if(n>w){
		if(n%w==0)//判断n号楼是否有余数 ,求得n所在层 
			Xn=n/w;
		else
			Xn=n/w+1;
	}else if(n<w||n==w)
		Xn=1;
		
	int y=max(Xm,Xn)-min(Xm,Xn);//求得y轴距离 
///////////////////////////////////////////////////////////////////////////////	


	//层数Xm，Xn有两个作用，一：是为了求得y轴距离。  二：在求x轴距离时，需要用到层数判断是否为复数层。 
	
	
	
	int x1,x2;
	if(isPlu(Xm))//判断层数Xm是否为复数层，以此来决定它用a数组还是b数组。 
		x1=b[m%w]; 
	else
		x1=a[m%w];
//		printf(" %d %d ",Xm,Xn); 这里只是为了查看层数是否计算正确 
		
	if(isPlu(Xn))//判断层数Xn是否为复数层，以此来决定它用a数组还是b数组。 
		x2=b[n%w];
	else
		x2=a[n%w];
		 
	int x=max(x1,x2)-min(x1,x2);// 得出x1到x2的距离x
////////////////////////////////////////////////////////////////////////////////

	
	minInstance=x+y;//最后y轴距离和 x轴距离相加 得出总距离 
	printf("%d\n",minInstance); 
	return 0;
	
} 
int max(int a,int b)//判断最大 
{
	if(a>b)
	return a;
	else
	return b;
}
int min(int a,int b)//判断最小 
{
	if(a<b)
	return a;
	else
	return b;
}
int isPlu(int a)// 判断复数 
{
	if(a%2==0)
		return 1;
	else
		return 0;
}

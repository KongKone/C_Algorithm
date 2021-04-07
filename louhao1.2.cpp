#include<stdio.h>
#include<string.h>
int main()
{
	int w,m,n,minInstance;
	scanf("%d%d%d",&w,&m,&n);  
	
	
	int Xm,Xn;
	if(m>w){//判断m房间号非第一层 
		if(m%w==0)
			Xm=m/w;
		else
			Xm=m/w+1;
	}else if(m<w||m==w)//判断m房间号第一层 
		Xm=1;
		
	if(n>w){//判断n房间号非第一层  
		if(n%w==0)
			Xn=n/w;
		else
			Xn=n/w+1;
	}else if(n<w||n==w)//判断n房间号第一层
		Xn=1;
		
	int y=Xm-Xn; if(y<0) y=-y;//求得y轴距离 
	
	
///////////////////////////////////////////////////////////////////////

	
	int X1,X2;//接下来求X轴距离 
	if(m%w==0&&n%w==0)//如果m层和n层取余等于0，那么说明他们X轴的距离是最远的。 
		minInstance=w-1;
	else{
		if(Xm%2==0)//如果是复数层
			X1=(w+1)-m%w; 
			else 
			X1=m%w;//得X1
		 
		if(Xn%2==0)
			X2=(w+1)-n%w ;
			else 
			X2=n%w;// 得X2      
	}
	int x=X1-X2; if(x<0) x=-x;//求得x轴距离
	
	
/////////////////////////////////////////////////////////////////////////

	
	minInstance=x+y;//最后y轴距离和 x轴距离相加 得出总距离 
	printf("%d\n",minInstance); 
	return 0;
}

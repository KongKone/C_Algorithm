#include<stdio.h>
#include<string.h>
int main()
{
	int w,m,n,minInstance;
	scanf("%d%d%d",&w,&m,&n);  
	
	
	int Xm,Xn;
	if(m>w){//�ж�m����ŷǵ�һ�� 
		if(m%w==0)
			Xm=m/w;
		else
			Xm=m/w+1;
	}else if(m<w||m==w)//�ж�m����ŵ�һ�� 
		Xm=1;
		
	if(n>w){//�ж�n����ŷǵ�һ��  
		if(n%w==0)
			Xn=n/w;
		else
			Xn=n/w+1;
	}else if(n<w||n==w)//�ж�n����ŵ�һ��
		Xn=1;
		
	int y=Xm-Xn; if(y<0) y=-y;//���y����� 
	
	
///////////////////////////////////////////////////////////////////////

	
	int X1,X2;//��������X����� 
	if(m%w==0&&n%w==0)//���m���n��ȡ�����0����ô˵������X��ľ�������Զ�ġ� 
		minInstance=w-1;
	else{
		if(Xm%2==0)//����Ǹ�����
			X1=(w+1)-m%w; 
			else 
			X1=m%w;//��X1
		 
		if(Xn%2==0)
			X2=(w+1)-n%w ;
			else 
			X2=n%w;// ��X2      
	}
	int x=X1-X2; if(x<0) x=-x;//���x�����
	
	
/////////////////////////////////////////////////////////////////////////

	
	minInstance=x+y;//���y������ x�������� �ó��ܾ��� 
	printf("%d\n",minInstance); 
	return 0;
}

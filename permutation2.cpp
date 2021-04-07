#include<stdio.h>
int main()
{
	double i;
	int count=0;
	for(i=0;i!=10;i+=0.1)
	{	
		printf("%.1f\n",i);
		count++;
	}
	return 0;
}

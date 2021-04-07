#include<stdio.h>
#include<time.h>
int main()
{
	int i,j,z;
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(z=0;z<=9;z++)
			{
				if((i*100+j*10+z)==(i*i*i)+(j*j*j)+(z*z*z)){
					printf("%d%d%d=%d.+%d.+%d.\n",i,j,z,i*i*i,j*j*j,z*z*z);
				}
			}//水仙花  完成。
			printf("Time used:%.2f\n",(double)clock()/CLOCKS_PER_SEC);
			return 0;
}

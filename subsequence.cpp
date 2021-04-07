#include<stdio.h>
#define INF 1000000000
int main()							//fopen方法 
{	//重定向方法								//FILE *fin,fout;
#ifdef INF
	freopen("input.txt","r",stdin);//fin=fopen("data.in","rb")
	freopen("output.txt","w",stdout);//fout=fopen("data.out","wb")
#endif
	long n,m;
	double sum=0;
	int count=0;
	while(scanf("%d%d",&n,&m)&&n&&m){//fscanf(fin,"%d",&x);
		while(n<=m)
		{
			sum+=1.0/(n*n);
			n++;
		}
	//		for (long i = n; i <= m; i++) {
	//		sum += 1.0 / (i*i);// trip1, int(1/2)=0, set numerator to 1.0
	//	}
		if(sum<1)
		printf("Case %d: %.5f\n",++count,sum);//fprintf(fout,"Case %d: %.5f\n",++count,sum);
		else{
		printf("Case %d: 0.00001\n",++count);
		}
	}
	fclose(stdin);//fclose(fin);
	fclose(stdout);//fclose(fout);
	return 0;
} 



#include<stdio.h>
#include<string.h>
#include<ctype.h>
//every function must hava a return-值，不然就出错  
int above(char a[5][5], int *x, int *y)//上移动 
{
	int X, Y;
	X = *x, Y = *y;
	if ((Y + 1) - 1 < 1) {
		return 0;//out of boundary
	}
	a[Y][X] = a[Y - 1][X];
	a[--Y][X] = ' ';
	*y=Y;
	return 1;//not out of boundary
}
int below(char a[5][5], int *x, int *y)//下移动 
{
	int X, Y;
	X = *x, Y = *y;
	if ((Y + 1) + 1 > 5) {
		return 0;//out of boundary
	}
	a[Y][X] = a[Y + 1][X];
	a[++Y][X] = ' ';
	*y=Y;
	return 1;//not out of boundary
}
int left(char a[5][5], int *x, int *y)//左移动 
{
	int X, Y;
	X = *x, Y = *y;
	if ((X + 1) - 1 < 1) {
		return 0;//out of boundary 
	}
	a[Y][X] = a[Y][X - 1];
	a[Y][--X] = ' ';
	*x=X;
	return 1;//not out of boundary
}
int right(char a[5][5], int *x, int *y)//右移动 
{
	int X, Y;
	X = *x, Y = *y;
	if ((X + 1) + 1 > 5) {
		return 0;//out of boundary
	}
	a[Y][X] = a[Y][X + 1];
	a[Y][++X] = ' ';
	*x=X;
	return 1;//not out of boundary
} 

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int count = 1;
	while (1) {
		int x, y;
		char s[5][5];
		char o[85];
		for (int i = 0; i < 5; i++)
		{
			char c =getchar();//original configuration 
			for (int j = 0; c!='\n';)
			{
				if (c == 'Z') {//if 'Z' exit all program 
					goto end;
				}
				if ((c == ' ')&&j<5) {//find correct Space ' '
					y = i;
					x = j;
					s[i][j++]=c;//controll subscipt j
				}
				if(isalpha(c)){
					s[i][j++]=c;//only reserve alphabet
				}	
				c=getchar();
			}
		}
		
		char cc;
		int ii = 0;
		while ((cc = getchar()) != '0'){//reserve order
			if(isalpha(cc)){
				o[ii++] = cc;
			}
		}
		getchar();//delete exceeding '\n'   because the last character of the strings of order is '\n'    

		int flag=1;
		for (int i = 0; i < ii; i++) { 
			if (o[i] == 'A') {
				flag=above(s, &x, &y);
			}
			else if (o[i] == 'B') {
				flag=below(s, &x, &y);
			}
			else if (o[i] == 'L') {
				flag=left(s, &x, &y);
			}
			else if (o[i] == 'R') {
				flag=right(s, &x, &y);
			}else{
				flag=0;//incorrect order 
			}
			
		}
		if(count>1) cout<<endl;//adjust the correct format of output
		printf("\nPuzzle #%d:\n", count++);
		if(flag){
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<4;j++)
					printf("%c ",s[i][j]);
				printf("%c\n",s[i][4]);
			}
		}else{
			printf("This puzzle has no final configuration.\n");
		}
	}
end:
	return 0;
}

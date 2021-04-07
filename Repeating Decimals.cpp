#include<iostream>
#include<vector>
#include<string.h>
#define MAXSIZE 3100
using namespace std;
int existYu[MAXSIZE];
int main(){
	int a,b;//被除数，除数 

//	while(1){ 
	cin>>a>>b;
	
	vector<int>decimals;
	memset(existYu,0,sizeof(existYu));
	
	cout<<a<<"/"<<b<<" = "<<a/b<<".";
	
	int i=1;//用记录小数个数 
	while(1){
		a=a%b;	
		if(existYu[a]) break;//判断余数是否重复出现 
		existYu[a]=i;//标记坐标 
		a=a*10;//借位 
		decimals.push_back(a/b); //从左到右存储小数点 
		i++; 	
	}
	int end=i-1;//i在while循环会多运算一次 ，所以要-1 
	for(int j = 0 ;j < end && j < 50 ; j++){
		if(j  == 0)	cout << "(";
		cout << decimals[j];
	}
	if(end >= 50) cout << "...";
	
	cout<< ")\n" << " "<< end << " = number of digits in repeating cycle\n";
//	}
	return 0;
}

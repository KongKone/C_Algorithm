#include<iostream>
#include<vector>
#include<string.h>
#define MAXSIZE 3100
using namespace std;
int existYu[MAXSIZE];
int main(){
	int a,b;//������������ 

//	while(1){ 
	cin>>a>>b;
	
	vector<int>decimals;
	memset(existYu,0,sizeof(existYu));
	
	cout<<a<<"/"<<b<<" = "<<a/b<<".";
	
	int i=1;//�ü�¼С������ 
	while(1){
		a=a%b;	
		if(existYu[a]) break;//�ж������Ƿ��ظ����� 
		existYu[a]=i;//������� 
		a=a*10;//��λ 
		decimals.push_back(a/b); //�����Ҵ洢С���� 
		i++; 	
	}
	int end=i-1;//i��whileѭ���������һ�� ������Ҫ-1 
	for(int j = 0 ;j < end && j < 50 ; j++){
		if(j  == 0)	cout << "(";
		cout << decimals[j];
	}
	if(end >= 50) cout << "...";
	
	cout<< ")\n" << " "<< end << " = number of digits in repeating cycle\n";
//	}
	return 0;
}

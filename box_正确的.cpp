#include<vector>
#include<iostream>
#include<string.h>
#include<assert.h>
#include<algorithm>
#include<stdio.h>
#define MAXSIZE 10010
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout); 
	int w,h;
	int pallets[6][2];
	while(cin>>w>>h){
		assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1)); 	
		if(w<h) swap(w,h);//��ʱ�������Ҵ�С����ֲ��죬�����ý�������һ�¡� 
		pallets[0][0]=w;
		pallets[0][1]=h;
		cout<<pallets[0][0]<<" ";
		cout<<pallets[0][1]<<endl;
		for(int i=1;i<6;i++){//������ 
			cin>>w>>h;
			assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1));  
			if(w<h) swap(w,h); 
			pallets[i][0]=w;
			pallets[i][1]=h;
			cout<<pallets[i][0]<<" ";cout<<pallets[i][1]<<endl;
		}
		int max=pallets[0][0],maxi=0; 
		int a=0,b=0,c=0;//�洢�����ߵĸ��� 
		for(int i=1;i<6;i++){//�ҵ�һ�ڶ����� 
			if(max<pallets[i][0]){
				max=pallets[i][0];
				maxi=i;
			}
		} cout<<"max,maxi:"<<max<<" "<<maxi<<endl;
		int cc;//������� 
		for(int i=0;i<6;i++)
		for(int j=0;j<2;j++){//�ҵ������� 
			if(pallets[i][j]!=max&&pallets[i][j]!=pallets[maxi][1]){
				cc=pallets[i][j];
				break;
			}
		}
		for(int i=0;i<6;i++)
		for(int j=0;j<2;j++){
			if(pallets[i][j]==max) a++;//max��a 
			if(pallets[i][j]==pallets[maxi][1]) b++;// pallets[maxi][1]��b 
			else if(pallets[i][j]==cc)c++;//cc��c 
		}
		cout<<"abc:"<<a<<b<<c<<endl;
		if((a==4&&b==4&&c==4)||(a==8&&b==4)||(a==8&&c==4)||(a==4&&b==8)) cout<<"POSSIBLE"<<endl; 
		else cout<<"IMPOSSIBLE"<<endl;
	}
}

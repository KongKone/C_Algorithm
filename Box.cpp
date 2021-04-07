#include<vector>
#include<iostream>
#include<string.h>
#include<assert.h>
#include<algorithm>
#include<stdio.h>
#define MAXSIZE 10010
struct pallets{
	int x,y;
};
bool cmp(const pallets &a,const pallets &b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>a.y;
}
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout); 
	int w,h;
	pallets pal[6];
	while(cin>>w>>h){
		assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1)); 	
		if(w<h) swap(w,h);//��ʱ�������Ҵ�С����ֲ��죬�����ý�������һ�¡� 
		pal[0].x=w;
		pal[0].y=h;
		//cout<<pal[0].x<<" ";cout<<pal[0].y<<endl;
		for(int i=1;i<6;i++){//������ 
			cin>>w>>h;
			assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1));  
			if(w<h) swap(w,h); 
			pal[i].x=w;
			pal[i].y=h;
			//cout<<pal[i].x<<" ";cout<<pal[i].y<<endl;
		}
		sort(pal,pal+6,cmp);//��pal�������������Ƚ�x�������� Ȼ������y�������� 
		//cout<<"abc:"<<a<<b<<c<<endl;
		if(isvalid(pal)) 
			cout<<"POSSIBLE"<<endl; 
		else cout<<"IMPOSSIBLE"<<endl;
	}
}

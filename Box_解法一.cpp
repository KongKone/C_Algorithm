#include<vector>
#include<iostream>
#include<string.h>
#include<assert.h>
#include<algorithm>
#include<stdio.h>
#define MAXSIZE 10010
using namespace std;
struct pallets{
	int x,y;
}pal[6];
bool cmp(const pallets &a,const pallets &b){
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>a.y;
}
bool isValid(const pallets[]);
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout); 
	int w,h;
	while(cin>>w>>h){
		assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1)); 	
		if(w<h) swap(w,h);//��ʱ�������Ҵ�С����ֲ��죬�����ý�������һ�¡� 
		pal[0].x=w;
		pal[0].y=h;
		//cout<<"����ǰ��"<<endl; //check
		//cout<<pal[0].x<<" ";cout<<pal[0].y<<endl;//check
		for(int i=1;i<6;i++){//������ 
			cin>>w>>h;
			assert(!(w>MAXSIZE||w<1)||(h>MAXSIZE||h<1));  
			if(w<h) swap(w,h); 
			pal[i].x=w;
			pal[i].y=h;
		//cout<<pal[i].x<<" ";cout<<pal[i].y<<endl;//check 
	}

	sort(pal,pal+6,cmp);//��pal�������������Ƚ�x�������� Ȼ������y�������� 
	
	//cout<<"�����:"<<endl; //check
//	for(int i=0;i<6;i++){//check
//		cout<<pal[i].x<<" ";cout<<pal[i].y<<endl;
//	}

	if(isValid(pal)) cout<<"POSSIBLE"<<endl; 
	else cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}
bool isValid(const pallets pal[]){
	if(pal[0].x != pal[1].x || pal[2].x != pal[3].x || pal[4].x != pal[5].x
		|| pal[0].y != pal[1].y || pal[2].y != pal[3].y || pal[4].y != pal[5].y)
		return false;
	else if(pal[0].x != pal[2].x || pal[0].y != pal[4].x || pal[2].y != pal[4].y)
		return false;
	return true;
}

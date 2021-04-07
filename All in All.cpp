#include<string.h>
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
#define MAXSIZE 100100
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	char a[MAXSIZE],b[MAXSIZE];
	int alen,blen;
	bool flag=false;
	while(cin>>a>>b){
		alen=strlen(a);
		blen=strlen(b);
		int k=0;
		for(int i = 0 ; i < blen ; i++ ){
			if(b[i]==a[k]){
				k++;
			}
			if(k==alen) break;
		}
		if(flag) cout<<endl;
		if(k==alen) 
			cout<<"Yes";
		else
			cout<<"No";
		flag=true;
	}	
	return 0;
}

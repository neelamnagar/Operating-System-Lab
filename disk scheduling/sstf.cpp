#include<bits/stdc++.h>
using namespace std;
int main(){

	int n,pre,head,track=0,pos;
	cin>>n;
	int re[n],vis[n];
	for(int i=0;i<n;i++){
		cin>>re[i];
	}
	cout<<"enter header\t";
	cin>>head;
	for(int i=0;i<n;i++){
		vis[i]=0;
	}

	for(int i=0;i<n;i++){
		int min=10000;
		for(int j=0;j<n;j++){
			if(min>abs(re[j]-head) && vis[j]==0){
				min=abs(re[j]-head);
				pos=j;
			}
		}
		vis[pos]=1;
		track+=min;
		head=re[pos];
		cout<<re[pos]<<"->";
	}
	cout<<"track  "<<track;
}
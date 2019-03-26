#include<bits/stdc++.h>
using namespace std;
int main(){

	int n,pre,head,track=0,pos;
	cin>>n;
	int re[n],vis[n];
	
	cout<<"enter header\t";
	cin>>head;

	for(int i=0;i<n;i++){
		cin>>re[i];
		track+=abs(re[i]-head);
		cout<<re[i]<<"->";
		head=re[i];
	}
	cout<<"track  "<<track;
}

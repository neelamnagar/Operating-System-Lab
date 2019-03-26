#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,pre,head,limit,track=0,pos;
	cin>>n;
	int re[n+4];
	for(int i=0;i<n;i++){
		cin>>re[i];
	}
	cout<<"enter header\t";
	cin>>head;
	cout<<"enter previous\t";
	cin>>pre;
	cout<<"enter limit\t";
	cin>>limit;

	int choice;
	if(head>pre){
		choice=1;
	}
	else{
		choice=2;
	}
	re[n]=head;
	n++;
	re[n]=limit-1;
	sort(re,re+n);

	for(int i=0;i<n;i++){
			if(re[i]==head){
				pos=i;
				break;
			}
		}
	if(choice==1){
		
		for(int i=pos;i<n;i++){
			cout<<re[i]<<"->";
			
		}
		cout<<re[n]<<"-> 0 ->";
		track+=(re[n]-re[pos]);

		for(int i=0;i<pos;i++){
			cout<<re[i]<<"->";
		}
		track+=re[pos-1]-0;


	}
	else{
		for(int i=pos;i>=0;i--){
			cout<<re[i]<<"->";
		}
		track+=re[pos];
		cout<<" 0 ->";
		for (int i = n; i >=pos+1; i--)
		{
			cout<<re[i]<<"->";
		}
		
		track+=(re[n]-re[pos+1]);

	}
	cout<<endl<<"track   "<<track<<endl;
}
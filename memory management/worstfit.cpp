#include<bits/stdc++.h>
using namespace std;

int main(){
	int m,n;
	cout<<"enetr block size\t";
	cin>>m;
	int i,j;
	int block[m];
	for(i=0;i<m;i++){
		cin>>block[i];
	}
	cout<<"enter process no\t";
	cin>>n;
	int pro[n],alloc[n];
	for(int i=0;i<n;i++){
		cin>>pro[i];
	}
	for(i=0;i<n;i++)
		alloc[i]=0;

	for(i=0;i<n;i++){
		int index=-1;
		for(j=0;j<m;j++){
			if(pro[i]<=block[j]){
				if(index==-1)
					index=j;
				else if(block[j]>block[index])
					index=j;
			}
		}
		if(index!=-1){
			block[index]-=pro[i];
			alloc[i]=index+1;
		}
	}
	for(i=0;i<n;i++){
		if(alloc[i]==0){
			cout<<i+1<<"\t"<<pro[i]<<"\tnot allocated"<<endl;
		}
		else{
			cout<<i+1<<"\t"<<pro[i]<<"\t"<<alloc[i]<<endl;
		}
	}


}

#include<iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter no. of free blocks:";cin>>m;cout<<endl;
	cout<<"Enter no. of processes:";cin>>n;cout<<endl;
	int block[m],process[n],vis[m];
	

	cout<<"\nEnter block size array:"<<endl;
	for(int i=0;i<m;i++)
	cin>>block[i];
	cout<<"Enter process size array:"<<endl;
	for(int i=0;i<n;i++)
	cin>>process[i];


for(int i=0;i<n;i++){
	vis[i]=0;
}
	int alloc[n],k;
	for(int i=0;i<n;i++)
	alloc[i]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(process[i]<=block[j] && vis[j]==0){
				
					alloc[i]=j+1;
					block[j]-=process[i];
					vis[j]=1;
					break;
				
			}
		}
	}
	cout<<"\nProcess no.  Process size  Block no."<<endl;
	for(int i=0;i<n;i++){
		if(alloc[i]==0)
		cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<"Not allocated"<<endl;
		else 
		cout<<i+1<<"\t\t"<<process[i]<<"\t\t"<<alloc[i]<<endl;
	}
	cout<<"Fragmentation table"<<endl<<"Block no.  Fragmentation"<<endl;
	for(int i=0;i<m;i++)
	cout<<i+1<<"\t\t"<<block[i]<<endl;
	return 0;
}

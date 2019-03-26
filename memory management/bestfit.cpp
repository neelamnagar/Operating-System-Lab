#include<iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter no. of free blocks:";cin>>m;cout<<endl;
	cout<<"Enter no. of processes:";cin>>n;cout<<endl;
	int block[m],process[n],b[m];
	
	int alloc[n];

	cout<<"\nEnter block size array:"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>block[i];
		
	}

	cout<<"Enter process size array:"<<endl;
	for(int i=0;i<n;i++)
	cin>>process[i];

	for(int i=0;i<n;i++)
	alloc[i]=0;
	for(int i=0;i<n;i++){
		int index=-1;
		for(int j=0;j<m;j++){
			if(process[i]<=block[j]){
				if(index==-1)
				index=j;
				else if(block[j]<block[index])
				index=j;
			}
		}
		if(index!=-1){
			alloc[i]=index+1;
			block[index]-=process[i];
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

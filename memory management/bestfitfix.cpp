#include<iostream>
using namespace std;

int main(){

	int m,n,i;
	cout<<"enter no of block size   ";
	cin>>m;
	cout<<"enter no. of process  ";
	cin>>n;

	int block[m];
	int b[m];
	int process[n];
	cout<<"enter the block sizes"<<endl;
	for(i=0;i<m;i++)
	{	cin>>block[i];
		b[i]=block[i];
	}
	cout<<"enter process sizes"<<endl;
	for(i=0;i<n;i++)
		cin>>process[i];
	

	int alloc[n]={0};

	for( i=0;i<n;i++){
		int index=-1;
		for(int j=0;j<m;j++){

			if(process[i]<=block[j] && b[j]==block[j]){
				if(index==-1)
				index=j;
				else if(block[j]<block[index] )
				index=j;
			}
		}
		if(index!=-1 ){
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
	cout<<"Fragmentation table"<<endl<<"Block no.  internal frag"<<endl;
	for(int i=0;i<m;i++)
	cout<<i+1<<"\t\t"<<block[i]<<endl;
	return 0;
}

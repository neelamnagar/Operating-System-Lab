#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cout<<"enter the no of process\t";
	cin>>n;
	cout<<"enter the no. of resources\t";
	cin>>m;
	int i,j,alloc[n][m],finish[n],work[m], max[n][m],availa[m],seq[n],need[n][m];
int count=0;
	cout<<"enter allocation"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>alloc[i][j];
		}
		finish[i]=0;
	}

	cout<<" insert maximum"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>max[i][j];
		}
	}

	cout<<"enter available"<<endl;
	for(i=0;i<m;i++){
			cin>>availa[i];
			
	}

	for(i=0;i<m;i++)
		work[i]=availa[i];


	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	while(count<n){
		int x=0;
		
		for(i=0;i<n;i++){
			if(finish[i]==0){
				for(j=0;j<m;j++){
					if(need[i][j]>work[j]){
						break;
					}
				}

				if(j==m){
					finish[i]=1;
					for(int j=0;j<m;j++){
						work[j]+=alloc[i][j];
					}
					x=1;
					seq[count++]=i;
				}
			}
		}
		if(x==0){
			cout<<"not safe"<<endl;
			return 0;
		}
	}
	cout<<"safe state"<<endl;
	for(i=0;i<n;i++){
	cout<<seq[i]<<" ";
			}



	int request1;
	cout<<"enter the process no. whose request you want to give\t";
	cin>>request1;
	int req[m];
	for(i=0;i<m;i++)
	cin>>req[i];
	int k=0;
	while(k<m){
		
		if(need[request1][k]<req[k] || availa[k]<req[k]){
		cout<<"not requested"<<endl;			break;
		}

		k++;
	}
	if(k==m){
		for(i=0;i<m;i++){
		availa[i]=availa[i]-req[i];
		alloc[request1][i]=alloc[request1][i]+req[i];
		need[request1][i]=need[request1][i]-req[i];
		}
	}

	for(j=0;j<m;j++){
	cout<<alloc[request1][j]<<" ";
}
	for(j=0;j<m;j++){
	cout<<need[request1][j]<<" ";
}
	for(j=0;j<m;j++){
	cout<<availa[j]<<" ";
}




}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j,k,m,flag1,flag2,time=0,fault=0,hit=0,flag3;
	cout<<"enter no of pages\t";
	cin>>n;
	int pages[n],time1[n];
	cout<<"enter pages"<<endl;
	for(i=0;i<n;i++){
		cin>>pages[i];
	}
	cout<<"enter no of frames\t";
	cin>>m;
	int frames[m],temp[m];
	for(i=0;i<m;i++){
			frames[i]=-1;
			temp[i]=-1;
	}

	for(i=0;i<n;i++){
		flag2=0;
		flag1=0;
		for(j=0;j<m;j++){
			if(frames[j]==pages[i]){
				hit++;
				flag1=flag2=flag3=1;
				break;
				
			}
		}
		if(flag1==0){
			for(j=0;j<m;j++){
				if(frames[j]==-1){
					frames[j]=pages[i];
					fault++;
					flag2=1;
					
					
					break;
				}
			}
		}
		if(flag2==0){
			flag3=0;
			for(j=0;j<m;j++){
				temp[j]=-1;
				for(k=i+1;k<n;k++){
					if(frames[j]==pages[k]){
						temp[j]=k;
						break;
					}
				}
			}
			for(j=0;j<m;j++){
				if(temp[j]==-1){
					frames[j]=pages[i];
					fault++;
					flag3=1;
					break;
				}
			}
		}
		if(flag3==0){
			int max=temp[0];
			int pos=0;
			for(j=1;j<m;j++){
				if(max<temp[j]){
					max=temp[j];
					pos=j;
				}
			}
			frames[pos]=pages[i];
			fault++;

		}
			for (j = 0;j < m;j++)
				{
					cout<<frames[j]<<" ";
				}
				cout<<endl;
		
		
	}

	cout<<"hit   "<<hit<<endl;
	cout<<"fault   "<<fault<<endl;



}
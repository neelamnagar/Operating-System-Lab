#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,i,j,m,flag1,flag2,time=0,fault=0,hit=0;
	cout<<"enter no of pages\t";
	cin>>n;
	int pages[n],time1[n];
	cout<<"enter pages"<<endl;
	for(i=0;i<n;i++){
		cin>>pages[i];
	}
	cout<<"enter no of frames\t";
	cin>>m;
	int frames[m];
	for(i=0;i<m;i++){
			frames[i]=-1;
	}

	for(i=0;i<n;i++){
		flag2=0;
		flag1=0;
		for(j=0;j<m;j++){
			if(frames[j]==pages[i]){
				hit++;
				time++;
				time1[j]=time;
				flag1=flag2=1;
				break;
				
			}
		}
		if(flag1==0){
			for(j=0;j<m;j++){
				if(frames[j]==-1){
					frames[j]=pages[i];
					fault++;
					time++;
					time1[j]=time;
					flag2=1;
					
					
					break;
				}
			}
		}
		if(flag2==0){
			int pos=0,min=time1[0];

			for(j=1;j<m;j++){
				if(time1[j]<min){
					min=time1[j];
					pos=j;
				}
			}
			frames[pos]=pages[i];
			fault++;
			time++;
			
			time1[pos]=time;
		
		}
			for (j = 0;j < m;j++)
				{
					cout<<frames[j]<<"  ";
				}
	}
	cout<<"hit   "<<hit<<endl;
	cout<<"fault   "<<fault<<endl;
	for (i = 0; i < m; ++i)
	{
		cout<<frames[i]<<"  ";
	}


}

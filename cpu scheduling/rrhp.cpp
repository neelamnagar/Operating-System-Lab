#include <iostream>
#include<algorithm>
using namespace std;

typedef struct process{
    int wt,at,bt,ct,tt;
    char pid;
    float rt;
    
}pro;

bool compare(pro a, pro b)
{
    return a.at<b.at;
}
bool compare1(pro a, pro b)
{
    return a.rt>b.rt;
}

int main() {
pro p[20];
int n,j;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>p[i].at>>p[i].bt>>p[i].pid;
    p[i].rt=p[i].wt=0;
        // your code goes here
}
sort(p,p+n,compare);
p[0].ct = p[0].at+p[0].bt;
p[0].wt=p[0].at-0;
cout<<"DASF"<<endl;
p[0].rt=1+(float)(p[0].wt/p[0].bt);
int i=1;
while(i<n-1)
{
    for(j=i;j<n;j++)
    {
        if(p[i].at>p[i-1].ct)
        {
            p[i-1].ct=p[i].at;
            break;
        }
        if(p[j].at>p[i-1].ct)
        break;
    }
    for(int k=i;k<j;k++){
       
        p[k].wt=p[k-1].ct-p[k].at;
        cout<<"DASF"<<endl;
        if(p[k].wt<0)
        	p[k].wt=0;
        p[k].rt=1+(float)(p[k].wt/p[k].bt);
        cout<<"DASF"<<endl;
    }
   // cout<<i<<j<<"\n";
    sort(p+i,p+j,compare1);
    cout<<"abcgh4"<<endl;
    
    p[i].ct = p[i-1].ct+p[i].bt;
i++;
}
	p[i].ct = p[i-1].ct+p[i].bt;
	    
	    for(int i=0;i<n;i++)
	    {
	        cout<<p[i].pid<<"   "<<p[i].at<<"  "<<p[i].bt<<"   "<<p[i].ct<<endl;
	    }
}

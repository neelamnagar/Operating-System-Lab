
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef struct proccess
{
	int at,bt,ct,ta,wt,rt,pr;
	string pro_id;

}schedule;

bool compare(schedule a,schedule b)
{
	if(a.at==b.at)
	return a.pr>b.pr;
	else
	return a.at<b.at;

}

bool compare2(schedule a,schedule b)
{
	return a.pr>b.pr;
}

int main()
{
	float avgtt=0;
	float avgwt=0;
	schedule pro[10];
	int n,i,j,count;

	cout<<"Enter the number of process::";
	cin>>n;
	cout<<"Enter the Process id arrival time burst time and priority :::";
	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		pro[i].rt=pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);
	int time=0;
	count=0;
	while(count<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>time)
			break;
		}
		sort(pro,pro+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>time)
			time=pro[j].at;
			cout<<pro[j].pro_id;
			pro[j].ct=time+1;
			pro[j].bt--;
		}
		
		time++;
		count=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			count++;
		}
	}
cout<<endl;
	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].rt;
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].rt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		avgtt=(float)avgtt+pro[i].ta;
		avgwt=(float)avgwt+pro[i].wt;
		cout<<endl;
	}
	cout<<avgtt/(float)n<<endl;
	cout<<avgwt/(float)n<<endl;
	return 0;
}

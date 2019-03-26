
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct proccess
{
	int at,bt,pr,ct,ta,wt;
	string pro_id;

}process;

bool compare(process a,process b)
{
	if(a.at == b.at) 
	    return a.pr>b.pr;  
	else
	    return a.at<b.at; 

}

bool compare2(process a,process b)
{
	return a.pr>b.pr;

}

int main()
{
	process pro[10];
	int n,i,j;
	float avgtt=0;
	float avgwt=0;
	cout<<"Enter the number of process::";
	cin>>n;
	cout<<"Enter the process id arrival time burst time and priority :::";

	for(i=0;i<n;i++)
	{
		cin>>pro[i].pro_id;
		cin>>pro[i].at;
		cin>>pro[i].bt;
		cin>>pro[i].pr;
	}

	sort(pro,pro+n,compare);

	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;
	i=1;

	while(i<n-1)
	{

		for(j=i;j<n;j++)
		{
			if(pro[i].at>pro[i-1].ct)
			{	cout<<"idle time from\t"<<pro[i-1].ct<<"\tto\t"<<pro[i].at<<endl;
				pro[i-1].ct=pro[i].at; break;
			}
			if(pro[j].at>pro[i-1].ct)
			break;
		}
		sort(pro+i,pro+i+(j-i),compare2);

		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
		i++;
	}
		pro[i].ct=pro[i-1].ct+pro[i].bt;
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;

	for(i=0;i<n;i++)
	{
		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt<<"\t"<<pro[i].pr;
		cout<<endl;
		avgtt=(float)avgtt+pro[i].ta;
		avgwt=(float)avgwt+pro[i].wt;
	}
	cout<<avgtt/(float)n<<endl;
	cout<<avgwt/(float)n<<endl;
	return 0;
}




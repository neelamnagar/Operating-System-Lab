#include<stdio.h>
struct pro{
	int at,bt,wt,tt,ct;
	char pid;

}p[20];

int main(){

int n;
printf("enter no. process\t");
scanf("%d",&n);

for(int i=0;i<n;i++)
{
	//scanf("%c",&p[i].pid);
	scanf("%d",&p[i].at);
	scanf("%d",&p[i].bt);
}
 for(int i=0;i<n;i++)
  {
     for(int j=0;j<n;j++)
     {
        if(p[i].at<p[j].at)
        { 
           struct pro temp=p[i];
           p[i]=p[j];
           p[j]=temp;
        }
        else if(p[i].at==p[j].at)
	      {
          if(p[i].bt>p[j].bt)
          {
             struct pro temp=p[i];
             p[i]=p[j];
             p[j]=temp;
          }
       }
     }
  }
int st[20];
st[0]=0;
p[0].wt=0;
for(int i=1;i<n;i++)
{
	st[i]=st[i-1]+p[i-1].bt;
	p[i].wt=st[i]-p[i].at;
	if(p[i].wt<0)
	p[i].wt=0;

}

for(int i=0;i<n;i++)
{
	p[i].tt=p[i].wt+p[i].bt;
	p[i].ct=p[i].tt+p[i].at;
	printf("%c\t%d\t%d\t%d\t%d\t%d\t",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);

}
}

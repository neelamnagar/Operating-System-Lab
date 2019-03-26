#include<stdio.h>
struct proc
{
	int wt,tt,at,bt,rt;
	char name;
	int completed;
}p[20];
int n;
int q[20];
int front=-1;
int rear=-1;
float avgtt, avgwt;
int enqueue(int i)
{
rear++;
q[rear]=i;
if(front ==-1)
{
front=0;
}
}

int dequeue()
{
int temp;
if(front==-1)
printf("underflow\n");

temp=q[front];

	if(front==rear)
	front=rear=-1;
	else 
	front++;
return temp;
}

int inqueue(int i)
{
	int j;
	for(j=front;j<=rear;j++)
	{
		if(q[j]==i)
		return 1;
	}
		
		return 0;
}

void sortbyat()
{
	struct proc temp;
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
		if(p[i].at>p[j].at)
		{	temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
}

int main()
{
	int i,j,time=0;
	int tq,sum_bt=0;
	char c;
	avgtt=0;
	avgwt=0;
	printf("enter no. process\t");
	scanf("%d",&n);

	for(i=0,c='A';i<n;i++,c++)
	{
		p[i].name=c;
		printf("enter arrival and burst time\n");
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].rt=p[i].bt;
		p[i].completed=0;
		sum_bt+=p[i].bt;

	}
printf("enter time quamtum \t");
scanf("%d",&tq);

sortbyat();
enqueue(0);
printf("process in order\n");
for(time=p[0].at;time<sum_bt;)
{
	i=dequeue();
	
if(p[i].rt<=tq)
{	time+=p[i].rt;
	p[i].completed=1;
	p[i].rt=0;
	
	p[i].wt=time-p[i].at-p[i].bt;
	p[i].tt=time-p[i].at;
	
	printf("  %c  ",p[i].name);	
	for(j=0;j<n;j++)
	{
		if(p[j].at<=time && inqueue(j)!=1 && p[j].completed!=1)
		enqueue(j);
	}
}
else
{	
	time+=tq;
	p[i].rt-=tq;
	printf("  %c  ",p[i].name);
	for(j=0;j<n;j++)
	{	
			if(p[j].at<=time && inqueue(j)!=1 && (i!=j) && p[j].completed!=1)
			{	enqueue(j);	}
	}
	enqueue(i);

}
}
	printf("\np_id\tAT\tBT\tCT\tTT\tWT\n");
	for(i=0;i<n;i++)
	{
	avgtt=avgtt+(float)p[i].tt;
	avgwt=avgwt+(float)p[i].wt;
	printf("%c\t%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].tt+p[i].at,p[i].tt,p[i].wt);
	}

	printf("average turnaroundtime  %f\n average waiting time  %f\n",avgtt/n,avgwt/n);

}

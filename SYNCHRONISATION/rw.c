#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define SIZE 16

pthread_t readerthread[50],writerthread[50];
sem_t mutex;
sem_t wrt;
int rc,c;
int buffer[SIZE];
void init(){
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	rc=0;
	c=0;
}


void *writer(int i){

	sem_wait(&wrt);
	int item;
	item=rand()%5;
	buffer[c]=item;
	printf("written by %d is %d\n",i+1,buffer[c]);
	c++;
	sleep(1);
	sem_post(&wrt);
}
void *reader(int i)
{
	sem_wait(&mutex);
	rc++;
	if(rc==1)
	{sem_wait(&wrt);	}
	sem_post(&mutex);
	c--;
	printf("data read by %d is %d\n",i+1,buffer[c]);
	sleep(1);
	
	sem_wait(&mutex);
	rc--;
	if(rc==0)
	{sem_post(&wrt);	}
	sem_post(&mutex);

}
int main()
{
	init();
	int no_of_writers,no_of_readers;
	printf("Enter number of readers: ");
	scanf("%d",&no_of_readers);
	printf("Enter number of writers: ");
	scanf("%d",&no_of_writers);
	int i;
	for(i=0;i<no_of_writers;i++)
	{
		pthread_create(&writerthread[i],NULL,writer,&i);
	}
	for(i=0;i<no_of_readers;i++)
	{
		pthread_create(&readerthread[i],NULL,reader,&i);
	}
	for(i=0;i<no_of_writers;i++)
	{
		pthread_join(writerthread[i],NULL);
	}
	for(i=0;i<no_of_readers;i++)
	{
		pthread_join(readerthread[i],NULL);
	}
}



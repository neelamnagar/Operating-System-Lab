#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
sem_t chop[5];
int i;
pthread_t t[5];
void *philospher(void *arg)
{
int a = *(int*)arg;
sem_wait(&chop[a]);
sem_wait(&chop[(a+1)%5]);
printf("\nPhilosopher %d is eating",a);
sem_post(&chop[(a+1)%5]);
sem_post(&chop[a]);
printf("\nPhilosopher %d is thinking",a);
}
int main()
{
int pid;
for(i=0;i<5;i++)
{
sem_init(&chop[i],0,1);
}
for(i=0;i<5;i++)
{
pthread_create(&t[i],NULL,philospher,(void *)&i);
}
for(i=0;i<5;i++)
{
pthread_join(t[i],NULL);
}
return 0;

}

#include<iostream>
#include<semaphore.h>
using namespace std;
//int data=0;
int rc=0;
sem_t write;
sem_t mutex;

void writer(int ele){
	sem_wait(&write);
	cout<<endl<<"Writer writing: "<<ele;
	sem_post(&write);
}

void reader(){
	sem_wait(&mutex);
	rc++;
	if(rc==1)
	sem_wait(&write);
	sem_post(&mutex);
	cout<<endl<<"Reader reading: ";
	sem_wait(&mutex);
	rc--;
	if(rc==0)
	sem_post(&write);
	sem_post(&mutex);
}
int main(){
	sem_init(&write,0,1);
	sem_init(&mutex,0,1);
	writer(2);
	reader();
	reader();
	writer(45);
	reader();
	return 0;
}


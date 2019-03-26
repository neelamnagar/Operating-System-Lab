#include<iostream>
#define SIZE 5
#include<semaphore.h>
using namespace std;
sem_t full;
sem_t empty;
int buff[SIZE];
int in=0;
void producer(int ele){

	if(in<5){
	sem_wait(&empty);
	buff[in]=ele;
	in=(in+1)%5;
	cout<<endl<<"Producer: "<<ele;
	sem_post(&full);
	}
	else
          printf("\nfull\n");
}
void consumer(){
	if(in>0){
	sem_wait(&full);
	int item=buff[out];
	in=(in-1);
	cout<<endl<<"Consumer: "<<item;
	sem_post(&empty);
	}
	else
	printf("empty\n");
}
int main(){
	sem_init(&full,0,0);
	sem_init(&empty,0,SIZE);
	producer(1);
	producer(5);
	producer(10);
	producer(2);
	consumer();
	consumer();
	consumer();
	producer(12);
	consumer();
	consumer();
	producer(13);
	consumer();
	return 0;
}
	

	
	

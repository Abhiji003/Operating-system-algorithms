#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
sem_t full,empty,mutex;
int b[5],x=0,l=-1,e,f,m;
void* producer()
{
    sem_wait(&mutex);
	sem_wait(&empty);
    x++;
	printf("\nProducer produces item %d",x);
    l++;
    b[l]=x;
	sem_post(&full);
    sem_post(&mutex);
}
void* consumer()
{
    sem_wait(&mutex);
    sem_wait(&full);
	printf("\nConsumer consumes item %d",b[l]);
    l--;
	sem_post(&empty);
    sem_post(&mutex);
}
int main()
{
    int n,i=50,j=0;
    pthread_t thread_id[100];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    while (1==1) {
        sem_getvalue(&mutex,&m);    
        sem_getvalue(&empty,&e);
        if(m==1 && e!=0)
        {
            pthread_create(&thread_id[i],NULL,producer,NULL);
		    i++;
		    sleep(0);
        }

        else if(e==0)
            printf("\nBuffer full\n");
        sem_getvalue(&mutex,&m);
        sem_getvalue(&full,&f);
        
        if(m==1 && f!=0)
        {
            pthread_create(&thread_id[j],NULL,consumer,NULL);
            j++;
            sleep(3);
        }
        else if(f == 0)
        {
            printf("\nBuffer empty\n");
        }
    }
}


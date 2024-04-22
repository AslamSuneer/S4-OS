#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>


pthread_t philosophers[5];
sem_t chopsticks[5];
sem_t mutex;

void *philosopher(void *args){
int id=*(int*)args;
int left=id;
int right=(id+1)%5;
printf("Philosopher %d is thinking\n",id+1);
sleep(2);
printf("Philosopher %d wants to eat\n", id+1);
sem_wait(&mutex);
sem_wait(&chopsticks[right]);
printf("Philosopher %d picks up right chopstick\n",id+1);
printf("Philosopher %d is eating\n", id+1);
printf("Philosopher %d finished eating\n",id+1);
sem_post(&mutex);      
sleep(2);
sem_post(&chopsticks[right]);
sem_post(&chopsticks[left]);


return NULL;

}

int main(){

int i;
int ids[5];

sem_init(&mutex, 0, 1);

for (i = 0; i < 5; i++) {
sem_init(&chopsticks[i], 0, 1);
}

for (i = 0; i < 5; i++) {
ids[i] = i;
pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
}

for (i = 0; i < 5; i++) {
pthread_join(philosophers[i], NULL);
}

for (i = 0; i < 5; i++) {
sem_destroy(&chopsticks[i]);
}

sem_destroy(&mutex);

return 0;

}

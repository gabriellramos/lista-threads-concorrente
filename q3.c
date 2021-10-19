#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define COUNT_MAX 500  
 
int countC = 1;
int countD = 500;

pthread_mutex_t mutexsum;
 
 
void *crescente(void *tid){
    long id = (long)tid;
 
    while(countC <= COUNT_MAX){
        pthread_mutex_lock (&mutexsum);     
        printf("Thread %ld: %d\t", id, countC++);
        pthread_mutex_unlock (&mutexsum);
    }
    pthread_exit(NULL);
}

void *decrescente(void *tid){
    long id = (long)tid;
 
    while(countD > 0){
        pthread_mutex_lock (&mutexsum);
        printf("Thread %ld: %d\t", id, countD--);
        pthread_mutex_unlock (&mutexsum);
    }
    pthread_exit(NULL);
}
 
 
int main(){
    pthread_t t1, t2, t3; //criando t1 e t2 do tipo thread
    int create; //variável que recebe o retorno da função pthread_create()
    long num; //identificador da thread
 
    pthread_mutex_init(&mutexsum, NULL);
    num = 1;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t1, NULL, crescente, (void *)num); //criando thread 1
 
    num = 2;
    printf("Main: criando a thread %ld\n", num);
    create = pthread_create(&t2, NULL, decrescente, (void *)num); //criando thread 2
 
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("\n\nMain: finalizando\n");
 
    pthread_mutex_destroy(&mutexsum);
 
    return 0;
}

//descrição
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define N 99999
#define NUM_THREADS getNumThreads()

pthread_mutex_t mutexsum;
int inicio=0, fim=999;
int k;	

int getNumThreads(){
	return (N / 1000)+1;
}

void *imprimePrimos(void *tid){
	int cont=0,i,aux,j;
	int id = (int)tid;
	

	pthread_mutex_lock (&mutexsum);
	printf ("\nTHREAD %d - (%d a %d)\n ",id, inicio, fim);
	for (i=inicio;i<fim;i++){
		if (i>1){
			cont=1;
			for (j=2;cont && j<=sqrt(i);j++){
				if (i % j == 0){
					cont = 0;
					break;
				}
			}
		}
		
		if (cont){
			printf ("%5d\t",i);
			k++;
			if (k==10){
				printf ("\n");
				k=0;
			}
		}
	}
		
	pthread_mutex_unlock (&mutexsum);
	pthread_exit(NULL);
}

int main(){
	pthread_mutex_init(&mutexsum, NULL);
	printf ("%d",NUM_THREADS);
	pthread_t threads[NUM_THREADS];
	
	int i, status;
	for (i=0;i<NUM_THREADS;i++){
		status = pthread_create(&(threads[i]), NULL, imprimePrimos, (void*)i);
		_sleep(1);
		inicio = fim+1;
		fim += 1000;
	}
	
	for (i=0;i<NUM_THREADS;i++){
		pthread_join(threads[i],NULL);
	}
	pthread_mutex_destroy(&mutexsum);
	return 0;
}

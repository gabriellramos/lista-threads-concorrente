#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10
#define M 1000

int vetor[M];
int k;
int inicio=0;
int fim=99;

pthread_mutex_t mutexsum;

void *multiplicacao(void *tid);
void imprime(int *vetor, int inicio, int fim);


int main(void *args){
	pthread_t threads[N];
	int i=0;
	int create; //variável que recebe o retorno da função pthread_create()
    long num; //identificador da thread
 
    pthread_mutex_init(&mutexsum, NULL);
	
	for (i=0;i<M;i++)
		vetor[i] = rand() % 1000 + 1;

	for (i=0;i<M;i++){
		printf ("%d  ",vetor[i]);
	}
	
	printf ("\n\nInsira um escalar para multiplicacao do vetor: ");
	scanf ("%d", &k);
	num = 1;
	for (i=0;i<N;i++){
		pthread_create(&(threads[i]), NULL, multiplicacao,(void *)num);
		num++;
	}
	
	for(i=0; i<N; i++) {
		pthread_join(threads[i], NULL);
	}

	printf ("\n\nVetor escalado\n");
	imprime(vetor,0,999);
	pthread_mutex_destroy(&mutexsum);
	return 0;
}

void *multiplicacao(void *tid){
	long id = (long)tid;
	int i;	
	
	for (i=inicio;i<=fim;i++){
		pthread_mutex_lock (&mutexsum);
		vetor[i] *= k;
		pthread_mutex_unlock (&mutexsum);
	}
	inicio=fim+1;
	fim+=100;
    pthread_exit(NULL);
	
}

void imprime(int *vetor, int inicio, int fim){
	int i;
	for (i=inicio;i<=fim;i++){
		printf ("%d  ",vetor[i]);
	}
		
}


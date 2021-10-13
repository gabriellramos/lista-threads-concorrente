#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 10
#define M 1000

void *multiplicacao(int *vetor, int k, int inicio, int fim);

void *imprime(int *vetor, int inicio, int fim);

int main(void *args){
	pthread_t threads[N];
	int i=0, inicio=0, fim=99, k;
	int vetor[M];
	
	for (i=0;i<M;i++)
		vetor[i] = rand() % 1000 + 1;

	for (i=0;i<M;i++){
		printf ("%d  ",vetor[i]);
	}
	
	printf ("\n\nInsira um escalar para multiplicacao do vetor: ");
	scanf ("%d", &k);
	
	for (i=0;i<N;i++){
	
		printf ("THREAD %d - (%d a %d)\n ",i+1, inicio, fim);
		pthread_create(&(threads[i]), NULL, multiplicacao(vetor, k, inicio,fim), NULL);
		inicio=fim+1;
		fim+=100;
		
	}
	
	for(i=0; i<N; i++) {
		pthread_join(threads[i], NULL);
	}

	printf ("oi");
	return 0;
}

void *multiplicacao(int *vetor, int k, int inicio, int fim){
	int i;	
	//printf ("\n\n");
	for (i=inicio;i<=fim;i++){
		vetor[i] *= k;
		//printf ("%d  ",vetor[i]);
	}
	
}

void *imprime(int *vetor, int inicio, int fim){
	int i;
	for (i=inicio;i<=fim;i++){
		printf ("%d  ",vetor[i]);
	}
		
}

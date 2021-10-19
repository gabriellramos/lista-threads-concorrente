#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 3

int M[N][N];
int somas[N]={0,0,0};

void recebeMatriz();
void imprimeMatriz();

pthread_mutex_t mutexsum;

void *somaLinha(void *tid);
void imprime(int *vetor, int inicio, int fim);


int main(void *args){
	pthread_t threads[N];
	int i=0;
	int create; //variável que recebe o retorno da função pthread_create()
    long num; //identificador da thread
 
   	pthread_mutex_init(&mutexsum, NULL);
	recebeMatriz();
	imprimeMatriz();
	num = 0;
	for (i=0;i<N;i++){
		pthread_create(&(threads[i]), NULL, somaLinha,(void *)num);
		num++;
	}
	
	for(i=0; i<N; i++) {
		pthread_join(threads[i], NULL);
	}
	
	printf ("\n\nMatriz\n");
	imprimeMatriz();
	
	for (i=0;i<N;i++){
		printf ("Soma linha[%d]: %d\n", i+1,somas[i]);
	}
	pthread_mutex_destroy(&mutexsum);
	return 0;
}

void *somaLinha(void *tid){
	long id = (long)tid;
	int i;	
	pthread_mutex_lock (&mutexsum);
	printf ("Thread %ld\n",id);
	for (i=0;i<N;i++){	
		printf ("%d ",M[id][i]);
		somas[id] += M[id][i];
		
	}
	printf ("\n");
	pthread_mutex_unlock (&mutexsum);
    pthread_exit(NULL);
	
}

void recebeMatriz(){
	FILE *file = fopen("matriz.txt","r");
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			fscanf(file,"%d ",&M[i][j]);
		}
	}
}

void imprimeMatriz(){
	int i, j;
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf ("%2d", M[i][j]);
		printf ("\n");
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int M[3][3];

void *inverteLinha(void *tid);
void recebeMatriz();
void imprimeMatriz();

int main(){
	pthread_t thread1, thread2, thread3;
	
	int i, status;
	
	recebeMatriz(M);
	
	pthread_create(&thread1, NULL, inverteLinha,(void*)0);
	pthread_create(&thread2, NULL, inverteLinha, (void*)1);
	pthread_create(&thread3, NULL, inverteLinha, (void*)2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	
	imprimeMatriz(M);
	
	return 0;
}

void *inverteLinha(void *tid){
	int i, aux, j=2, meio=j/2;
	long linha = (long)tid;
	for (i=0; i<meio; i++, j--){
		aux=M[linha][i];
		M[linha][i] = M[linha][j];
		M[linha][j] = aux;
	}
	
}

void recebeMatriz(){
	FILE *file = fopen("matriz.txt","r");
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			fscanf(file,"%d ",&M[i][j]);
		}
	}
}

void imprimeMatriz(){
	int i, j;
	for (i=0;i<3;i++){
		for(j=0;j<3;j++)
			printf ("%2d", M[i][j]);
		printf ("\n");
	}
}

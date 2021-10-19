#include <pthread.h>
#define N 10

void *imprimePrimos(int inicio, int fim);

int main(){
	pthread_t threads[N];
	int i=0, status, inicio=0, fim=999;
	
	for (i=0;i<N;i++){
		printf ("THREAD %d - (%d a %d)\n ",i+1, inicio, fim);
		pthread_create(&(threads[i]), NULL, imprimePrimos(inicio,fim), NULL);
		inicio=fim+1;
		fim+=999;
		printf ("\n");
	}
	
	for(i=0; i<N; i++) {
		pthread_join(threads[i], NULL);
	}
		return 0;
	}
	
	void *imprimePrimos(int inicio, int fim){
	int i, cont=0, j,aux;
	for (i=inicio;i<=fim;i++){
		cont=1;
		
		for (j=3;cont && (j<=i/2);j+=2)
			if (i % j == 0) cont =0;
		
		if (cont)
			printf ("%d ", i);
	}
}

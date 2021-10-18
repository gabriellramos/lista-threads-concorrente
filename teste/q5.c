#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 3

void imprimeDadosMatriz(int M[TAM][TAM]);
void *inverteValoresLinhas(int M[TAM][TAM]);

int main() {

    pthread_t thread;
    int M[TAM][TAM], i , j, thread_status;

    // adicionando valores as celulas da matriz
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            M[i][j] = rand()%10;
        }
    }

    printf("\nMatriz principal: \n");
    imprimeDadosMatriz(M);

    // inicializando a thread
    thread_status = pthread_create(&thread, NULL, inverteValoresLinhas(M), NULL);
    
    // verificar se ocorreu algum erro na chamada de pthread_create
    if(thread_status != 0){
        printf ("Erro ao criar o thread.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread, NULL);

    return 0;
}

void imprimeDadosMatriz(int matriz[3][3]) {
    // dados da matriz
    int i,j;
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// invertendo os valores para matriz
void *inverteValoresLinhas(int M[TAM][TAM]) {
    int aux[TAM][TAM], i, j;
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            aux[i][j] = M[i][TAM-1-j];
        }
    }
    imprimeDadosMatriz(aux);
}

#include <stdio.h>
#include <locale.h>
#define N 1000

int main(){
	setlocale(LC_ALL,"");
	char pergunta[N] = {"2) O exercício anterior requer alguma forma de sincronismo entre as threads?\n"
					"Ilustre uma situação em que o sincronismo é necessário quando se trabalha com threads. \nQuais os"
					"mecanismos existentes em C pra se realizar sincronia entre threads.\n\n"};
	char resposta[N] = {"Sim, como estamos trabalhando com um volume de dados que vai ficando cada vez mais alto,\n "
						"além da sua complexidade de processamento, é necessário que as Threads trabalhem de forma\n "
						"sincronizada para atingir todo o volume de dados. Em C, a execução de Threads em paralelo\n "
						"pode ser dada pela função pthread_join(id_thread,variavel_resposta);"};
	
	printf ("%s\n\n%s",pergunta, resposta);
	return 0;
}


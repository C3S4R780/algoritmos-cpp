#include <stdio.h>
#include <stdlib.h>

// Estrutura N�
typedef struct no {
	int num;
	struct no *prox;
} No;

// Fun��o para checar se a fila est� vazia
int isEmpty(No *headPtr){
	
	// Retorna True se a cabe�a da fila (inicio) for nulo
	return headPtr == NULL;
}

// Fun��o para adicionar um n� na fila
// ** = pointer-to-pointer, um ponteiro apontando para outro ponteiro
int addNo(No **headPtr, No **tailPtr, int valor) {

	// Alocando espa�o para o novo n�
	No* newPtr = (No*)malloc(sizeof(No));

	/*
		Se o espa�o alocado for nulo, 
		significa que n�o tem espa�o na memoria para adicionar outro n�.
	*/
	if (newPtr == NULL) return printf("Sem espaco na memoria.\n", valor);
	
	/*
		Atribuindo o valor informado para o novo n�,
		e informando que o proximo item da lista � NULL,
		ou seja, que n�o tem um proximo item, sendo esse
		o ultimo item da lista.
	*/
	newPtr->num = valor;
	newPtr->prox = NULL;
	
	// Se a fila estiver vazia...
	if (isEmpty(*headPtr)){
		
		// Adicionamos o novo n� na cabe�a (inicio) da fila
		*headPtr = newPtr;
		
	} else { // Sen�o...
		
		// Adicionamos o novo n� na calda (fim) da lista
		(*tailPtr)->prox = newPtr;
	}
	
	// Atualiza a calda (fim) da fila para ser o novo n� adicionado
	*tailPtr = newPtr;
}

// Fun��o para remover um n� da fila
int removeNo(No **headPtr, No **tailPtr) {

	// Armazena o valor do n� a ser deletado
	int num = (*headPtr)->num;
	
	// Cria um n� temporario recebendo o endere�o do inicio da fila
	No *tmpPtr = *headPtr;
	
	// Move o inicio da fila para o proximo n�
	*headPtr = (*headPtr)->prox;
	
	// Se o inicio da fila for vazio, o final tambem dever� ser, para indicar o final da fila
	if (*headPtr == NULL) {
		*tailPtr = NULL;
	}

	// Limpa o ponteiro temporario da memoria
	free(tmpPtr);
	
	// Retorna o numero que havia no antigo primeiro n�
	return num;
}

// Fun��o para listar todos os n�s de uma determinada fila
int listarFila(No *currentPtr) {

	// Se o n� atual for nulo, significa que a fila esta vazia
	if(currentPtr == NULL) return printf("A fila esta vazia. \n\n");

	printf("{ ");
	
	// Enquanto o n� atual n�o for nulo...
	// (caso o n� atual seja nulo, significa que chegamos no final da fila)
	while(currentPtr != NULL){

		printf("%d, ", currentPtr->num);
		
		// Atualiza o n� atual para o proximo n� da fila		
		currentPtr = currentPtr->prox;
	}
	printf("}\n");
}

int main () {

	int opt = 0;
	No *filaHead = NULL;
	No *filaTail = NULL;

	printf("-------------------------------\n");
	printf("| 1. Inserir um valor na fila |\n");
	printf("| 2. Remover um valor na fila |\n");
	printf("| 3. Listar fila              |\n");
	printf("| 4. Finalizar programa       |\n");
	printf("-------------------------------\n");
	scanf("%i", &opt);
	
	while (opt != 4) {
		system("cls");

		switch (opt) {

			case 1: {
				int num = 0;
				printf("Insira um numero:\n");
				scanf("%d", &num);
				addNo(&filaHead, &filaTail, num);
				break;
			}

			case 2: {
				int num = removeNo(&filaHead, &filaTail);
				printf("%d removido da fila\n", num);
				break;
			}

			case 3:
				listarFila(filaHead);
				break;

			default:
				printf("Opcao invalida.\n");
				break;
		}
		printf("\n-------------------------------\n");
		printf("| 1. Inserir um valor na fila |\n");
		printf("| 2. Remover um valor na fila |\n");
		printf("| 3. Listar fila              |\n");
		printf("| 4. Finalizar programa       |\n");
		printf("-------------------------------\n");
		scanf("%d", &opt);
	}
}

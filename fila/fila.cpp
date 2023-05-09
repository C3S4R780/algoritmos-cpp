#include <stdio.h>
#include <stdlib.h>

// Estrutura Nó
typedef struct no {
	int num;
	struct no *prox;
} No;

// Função para checar se a fila está vazia
int isEmpty(No *headPtr){
	
	// Retorna True se a cabeça da fila (inicio) for nulo
	return headPtr == NULL;
}

// Função para adicionar um nó na fila
// ** = pointer-to-pointer, um ponteiro apontando para outro ponteiro
int addNo(No **headPtr, No **tailPtr, int valor) {

	// Alocando espaço para o novo nó
	No* newPtr = (No*)malloc(sizeof(No));

	/*
		Se o espaço alocado for nulo, 
		significa que não tem espaço na memoria para adicionar outro nó.
	*/
	if (newPtr == NULL) return printf("Sem espaco na memoria.\n", valor);
	
	/*
		Atribuindo o valor informado para o novo nó,
		e informando que o proximo item da lista é NULL,
		ou seja, que não tem um proximo item, sendo esse
		o ultimo item da lista.
	*/
	newPtr->num = valor;
	newPtr->prox = NULL;
	
	// Se a fila estiver vazia...
	if (isEmpty(*headPtr)){
		
		// Adicionamos o novo nó na cabeça (inicio) da fila
		*headPtr = newPtr;
		
	} else { // Senão...
		
		// Adicionamos o novo nó na calda (fim) da lista
		(*tailPtr)->prox = newPtr;
	}
	
	// Atualiza a calda (fim) da fila para ser o novo nó adicionado
	*tailPtr = newPtr;
}

// Função para remover um nó da fila
int removeNo(No **headPtr, No **tailPtr) {

	// Armazena o valor do nó a ser deletado
	int num = (*headPtr)->num;
	
	// Cria um nó temporario recebendo o endereço do inicio da fila
	No *tmpPtr = *headPtr;
	
	// Move o inicio da fila para o proximo nó
	*headPtr = (*headPtr)->prox;
	
	// Se o inicio da fila for vazio, o final tambem deverá ser, para indicar o final da fila
	if (*headPtr == NULL) {
		*tailPtr = NULL;
	}

	// Limpa o ponteiro temporario da memoria
	free(tmpPtr);
	
	// Retorna o numero que havia no antigo primeiro nó
	return num;
}

// Função para listar todos os nós de uma determinada fila
int listarFila(No *currentPtr) {

	// Se o nó atual for nulo, significa que a fila esta vazia
	if(currentPtr == NULL) return printf("A fila esta vazia. \n\n");

	printf("{ ");
	
	// Enquanto o nó atual não for nulo...
	// (caso o nó atual seja nulo, significa que chegamos no final da fila)
	while(currentPtr != NULL){

		printf("%d, ", currentPtr->num);
		
		// Atualiza o nó atual para o proximo nó da fila		
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

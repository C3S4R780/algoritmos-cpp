#include <stdio.h>
#include <stdlib.h>

// Estrutura Nó
typedef struct no {
	int num;
	struct no *ant;
} No;

// Função para checar se a pilha está vazia
int isEmpty(No *pilha){
	
	// Retorna True se a cabeça da pilha (inicio) for nulo
	return pilha == NULL;
}

// Função para adicionar um nó na pilha
// ** = pointer-to-pointer, um ponteiro apontando para outro ponteiro
int addNo(No **pilha, int valor) {

	// Alocando espaço para o novo nó
	No *newPtr = (No*)malloc(sizeof(No));

	/*
		Se o espaço alocado for nulo, 
		significa que não tem espaço na memoria para adicionar outro nó.
	*/
	if (newPtr == NULL) return printf("Sem espaco na memoria.\n");
	
	// Atribuindo o valor informado para o novo nó
	newPtr->num = valor;
	
	// Se a pilha estiver vazia...
	if (isEmpty(*pilha)){

		// Informamos que não temos nós anteriores na lista
		newPtr->ant = NULL;

	} else { // Senão...

		// Informamos que o nó anterior a este é o ultimo da pilha atual
		newPtr->ant = *pilha;
	}

	// Atualiza a pilha com o novo nó
	*pilha = newPtr;
}

// Função para remover um nó da fila
int removeNo(No **pilha) {

	// Armazena o valor do nó a ser deletado
	int num = (*pilha)->num;
			
	// Move o final da pilha para o nó anterior
	*pilha = (*pilha)->ant;
		
	// Retorna o numero que havia no antigo ultimo nó
	return num;	
}

// Função para listar todos os nós de uma determinada pilha
int listarPilha(No *currentPtr) {

	// Se o nó atual for nulo, significa que a pilha esta vazia
	if(isEmpty(currentPtr)) return printf("A pilha esta vazia. \n\n");

	printf("{ ");
	
	// Enquanto o nó atual não for nulo...
	// (caso o nó atual seja nulo, significa que chegamos no final da pilha)
	while(currentPtr != NULL){

		printf("%d, ", currentPtr->num);
		
		// Atualiza o nó atual para o proximo nó da pilha		
		currentPtr = currentPtr->ant;
	}
	printf("}\n");
}

int main () {

	int opt = 0;
	No *pilha = NULL;
	
	printf("--------------------------------\n");
	printf("| 1. Inserir um valor na pilha |\n");
	printf("| 2. Remover um valor na pilha |\n");
	printf("| 3. Listar pilha              |\n");
	printf("| 4. Finalizar programa        |\n");
	printf("--------------------------------\n");
	scanf("%d", &opt);
	
	while (opt != 4) {
		system("cls");

		switch (opt) {

			case 1: {
				int num = 0;
				printf("Insira um numero:\n");
				scanf("%d", &num);
				addNo(&pilha, num);
				break;
			}

			case 2: {
				int num = removeNo(&pilha);
				printf("%d removido da pilha\n", num);
				break;
			}

			case 3:
				listarPilha(pilha);
				break;

			default:
				printf("Opcao invalida.\n");
				break;
		}
		printf("\n--------------------------------\n");
		printf("| 1. Inserir um valor na pilha |\n");
		printf("| 2. Remover um valor na pilha |\n");
		printf("| 3. Listar pilha              |\n");
		printf("| 4. Finalizar programa        |\n");
		printf("--------------------------------\n");
		scanf("%d", &opt);
	}
}

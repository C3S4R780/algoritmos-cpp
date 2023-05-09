#include <stdio.h>
#include <stdlib.h>

// Estrutura N�
typedef struct no {
	int num;
	struct no *ant;
} No;

// Fun��o para checar se a pilha est� vazia
int isEmpty(No *pilha){
	
	// Retorna True se a cabe�a da pilha (inicio) for nulo
	return pilha == NULL;
}

// Fun��o para adicionar um n� na pilha
// ** = pointer-to-pointer, um ponteiro apontando para outro ponteiro
int addNo(No **pilha, int valor) {

	// Alocando espa�o para o novo n�
	No *newPtr = (No*)malloc(sizeof(No));

	/*
		Se o espa�o alocado for nulo, 
		significa que n�o tem espa�o na memoria para adicionar outro n�.
	*/
	if (newPtr == NULL) return printf("Sem espaco na memoria.\n");
	
	// Atribuindo o valor informado para o novo n�
	newPtr->num = valor;
	
	// Se a pilha estiver vazia...
	if (isEmpty(*pilha)){

		// Informamos que n�o temos n�s anteriores na lista
		newPtr->ant = NULL;

	} else { // Sen�o...

		// Informamos que o n� anterior a este � o ultimo da pilha atual
		newPtr->ant = *pilha;
	}

	// Atualiza a pilha com o novo n�
	*pilha = newPtr;
}

// Fun��o para remover um n� da fila
int removeNo(No **pilha) {

	// Armazena o valor do n� a ser deletado
	int num = (*pilha)->num;
			
	// Move o final da pilha para o n� anterior
	*pilha = (*pilha)->ant;
		
	// Retorna o numero que havia no antigo ultimo n�
	return num;	
}

// Fun��o para listar todos os n�s de uma determinada pilha
int listarPilha(No *currentPtr) {

	// Se o n� atual for nulo, significa que a pilha esta vazia
	if(isEmpty(currentPtr)) return printf("A pilha esta vazia. \n\n");

	printf("{ ");
	
	// Enquanto o n� atual n�o for nulo...
	// (caso o n� atual seja nulo, significa que chegamos no final da pilha)
	while(currentPtr != NULL){

		printf("%d, ", currentPtr->num);
		
		// Atualiza o n� atual para o proximo n� da pilha		
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

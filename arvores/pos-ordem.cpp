#include <stdio.h>

typedef struct no {
	int chave;
	struct no *filho_esquerda;
	struct no *filho_direita;
} No;

// Ordem: Esquerda, Raiz, Direita.
void pos_ordem(No *ptr) {
	
	// Percorre recursivamente em p�s-ordem a sub�rvore esquerda
	if (ptr->filho_esquerda != NULL) {
		pos_ordem(ptr->filho_esquerda); 
	}
	
	// Percorre recursivamente em p�s-ordem a sub�rvore direita
	if (ptr->filho_direita != NULL) {
		pos_ordem(ptr->filho_direita);
	}
	
	// Visita o n�
	printf ("%d", ptr->chave);
}

int main() {
	return 1;
}

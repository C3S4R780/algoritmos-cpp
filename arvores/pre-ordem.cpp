#include <stdio.h>

typedef struct no {
	int chave;
	struct no *filho_esquerda;
	struct no *filho_direita;
} No;

// Ordem: Raiz, Esquerda, Direita.
void pre_ordem(No *ptr) {

	// Visita o nó
	printf ("%d", ptr->chave);
	
	// Percorre recursivamente em pré-ordem a subárvore esquerda
	if (ptr->filho_esquerda != NULL) {
		pre_ordem(ptr->filho_esquerda); 
	}
	
	// Percorre recursivamente em pré-ordem a subárvore direita
	if (ptr->filho_direita != NULL) {
		pre_ordem(ptr->filho_direita);
	}
}

int main() {
	return 1;
}

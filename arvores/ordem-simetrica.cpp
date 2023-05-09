#include <stdio.h>

typedef struct no {
	int chave;
	struct no *filho_esquerda;
	struct no *filho_direita;
} No;

// Ordem: Esquerda, Raiz, Direita.
void ordem_simetrica(No *ptr) {
	
	// Percorre recursivamente em ordem simetrica a sub�rvore esquerda
	if (ptr->filho_esquerda != NULL) {
		ordem_simetrica(ptr->filho_esquerda); 
	}
	
	// Visita o n�
	printf ("%d", ptr->chave);
	
	// Percorre recursivamente em ordem simetrica a sub�rvore direita
	if (ptr->filho_direita != NULL) {
		ordem_simetrica(ptr->filho_direita);
	}
}

int main() {
	return 1;
}

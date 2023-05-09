#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int *nums, int size) {
	
	// Flag para indicar troca de valores
	int troca = 1;

	// Enquanto precisar trocar valores...
	while (troca) {
		int i = 0;
		
		// Enquanto i for menor que o tamanho do vetor...
		while (i < size-1) {
			
			// Se o elemento atual for maior que o proximo elemento da lista...
			if (nums[i] > nums[i+1]) {
				
				// Realiza a troca de posições entre os valores
				int aux = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = aux;
				
				// Flag indicando que teve troca de valores
				troca = 1;
			}
			
			// Segue para o proximo elemento do vetor
			i++;
		}
		
		// Flag indicando que não teve troca de valores
		troca = 0;
	}
}

int main() {

	printf("Quantos numeros deseja inserir ?\n");
	int size;
	scanf("%d", &size);

	int nums[size];

	for (int i = 0; i < size; i++) {
		printf("%d numero: ", i+1);
		scanf("%d", &nums[i]);
	}

	system("cls");
	
	printf("Antes do bubble_sort:\n{");
	for (int i = 0; i < size; i++) {
		printf("%d,", nums[i]);
	}
	printf("}");
	
	bubble_sort(nums, size);
	
	printf("\n\nDepois do bubble_sort:\n{");
	for (int i = 0; i < size; i++) {
		printf("%d,", nums[i]);
	}
	printf("}");

}

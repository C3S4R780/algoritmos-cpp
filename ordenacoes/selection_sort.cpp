#include <stdio.h>
#include <stdlib.h>

int selection_sort(int *nums, int size) {
	
	// Para cada elemento do array...
    for (int i = 0; i < size-1; i++) {
    	
    	// Para cada proximo elemento do array...
        for (int j = i+1; j < size; j++) {
        	
        	// Se o numero atual é maior que o proximo numero do array...
            if (nums[i] > nums[j]) {
            	
            	// Realiza a troca de posições entre os valores 
                int aux = nums[i];
                nums[i] = nums[j];
                nums[j] = aux;
            }
        }
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
	
	selection_sort(nums, size);
	
	printf("\n\nDepois do selection_sort:\n{");
	for (int i = 0; i < size; i++) {
		printf("%d,", nums[i]);
	}
	printf("}");

}

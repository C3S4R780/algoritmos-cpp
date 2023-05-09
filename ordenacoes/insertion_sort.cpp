#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *nums, int size) {
	
	// Para cada elemento do array...
    for (int i = 0; i < size-1; i++) {
    	
    	// Armazena o proximo elemento do array
        int j = i+1;
        
        // Enquanto o numero anterior for maior que o numero atual E o numero atual for mair que 0
        while (nums[j-1] > nums[j] && j > 0) {
        	
        	// Realiza a troca de posições entre os valores
            int aux = nums[j-1];
            nums[j-1]=nums[j];
            nums[j]=aux;
            
            // Volta uma posição dentro do array
            j--;
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
	
	insertion_sort(nums, size);
	
	printf("\n\nDepois do insertion_sort:\n{");
	for (int i = 0; i < size; i++) {
		printf("%d,", nums[i]);
	}
	printf("}");

}

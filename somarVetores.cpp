#include <stdlib.h>
#include <iostream>

using namespace std;

void popularVetor(int* vet, int tamanhoVetor) {
	for (int i=0; tamanhoVetor > i; i++) {
		cout << "Insira o valor para a " << i+1 << " posicao do vetor: ";
		cin >> vet[i];
	}
}

void mostrarVetor(int* vet, int tamanhoVetor) {
	cout << "vet[] = {";
	for (int i=0; tamanhoVetor > i; i++) {
		cout << vet[i];
		if (tamanhoVetor != i+1) {
			cout << ", "
		}
	}
	cout << "}" << endl;
}

void somarVetores(int* vet1, int* vet2, int* vet3, int tamanhoVetor) {
	for (int i=0; tamanhoVetor > i; i++) {
		vet3[i] = vet1[i] + vet2[i];
	}
}

int main() {

	int tamanhoVetor;
	cout << "Insira o tamanho dos vetores:" << endl;
	cin >> tamanhoVetor;
	
	int* vet1 = (int*)malloc(tamanhoVetor * sizeof(int));
	cout << endl << "Valores para o primeiro vetor:" << endl;
	popularVetor(vet1, tamanhoVetor);
	mostrarVetor(vet1, tamanhoVetor);

	int* vet2 = (int*)malloc(tamanhoVetor * sizeof(int));
	cout << endl << "Valores para o segundo vetor:" << endl;
	popularVetor(vet2, tamanhoVetor);
	mostrarVetor(vet2, tamanhoVetor);

	int* vet3 = (int*)malloc(tamanhoVetor * sizeof(int));
	somarVetores(vet1, vet2, vet3, tamanhoVetor);

	cout << endl << "Soma dos vetores:" << endl;
	mostrarVetor(vet3, tamanhoVetor);
	
	free(vet1);
	free(vet2);
	free(vet3);
}


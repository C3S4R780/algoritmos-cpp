#include <iostream>

using namespace std;

int main() {
	int tamanhoVetor;
	cout << "Insira o tamanho do vetor:" << endl;
	cin >> tamanhoVetor;
	
	int vet[tamanhoVetor];
	for (int i=0; tamanhoVetor > i; i++) {
		cout << "Insira o valor para a " << i << " posicao do vetor: ";
		cin >> vet[i];
	}
	
	cout << endl << "vet[] = {";
	for (int i=0; tamanhoVetor > i; i++) {
		cout << vet[i];
		if (tamanhoVetor != i+1) {
			cout << ", ";
		}
	}
	cout << "}";
}


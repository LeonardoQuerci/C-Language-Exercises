#include <stdio.h>

void inserir(int heap[], int *tamanho, int valor){
	heap[*tamanho] = valor;
	int indPai = (*tamanho-1)/2;
	if(heap[indPai]<heap[*tamanho]){
		int aux;
		aux = heap[indPai];
		heap[indPai] = heap[*tamanho];
		heap[*tamanho] = aux;
	}
}
int removerRaiz(int heap[], int *tamanho){
}

void imprimirHeap(int heap[], int tamanho){
	
}

int main(){
	int heap[] = {50,30,20,15,10,8};
	
	return 0;
}


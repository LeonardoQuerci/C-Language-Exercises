#include <stdio.h>
#define MAX 3
typedef struct{
	char cpf[20];
}Usuario;

typedef struct {
	Usuario v[MAX];
	int inicio;
	int final;
}Fila;

void init(Fila *f){
	f->inicio = 0;
	f->final = 0;
}

int filaCheia(Fila f){
	return ((f.final+1) % MAX == f.inicio);
}

int filaVazia(Fila f){
	return (f.final== f.inicio);
}

int inserir(Fila *f, Usuario u){
	f->v[f->final] = u;
	f->final = (f->final+1) % MAX;
	return 0;
}

int remover (Fila *f){
	f->inicio = (f->inicio+1)%MAX;
	return 0;
}

int main(){

	return 0;
}


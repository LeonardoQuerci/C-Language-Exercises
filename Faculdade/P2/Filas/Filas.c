#include <stdio.h>
#define MAX 5;

typedef struct{
	char cpf[20];
}Usuario;


typedef struct{
	Usuario v[MAX];
	int final;
	int inicio;
}Fila;

void init (Fila *f){
	f->inicio = 0;
	f->final = 0;
}

int filaCheia(Fila f){
	if(f.final == MAX-1){
		return 1;
	}else{
		return 0;
	}
}

int filaVazia(Fila f){
	if(f.final == f.inicio){
		return 1;
	}else{
		return 0;
	}
}

void inserir(Fila *f, Usuario l){
	if(filaCheia(*f)){
		printf("A FILA ESTA CHEIA\n");
	}else{
		f->v[f->final] = l;
		f->final++;
	}
}

void retirar(Fila *f, Usuario *l){
	if(filaVazia(*f)){
		printf("A FILA ESTA VAZIA\n");
	}else{
		f->inicio++;
		
		if(f->final == f->inicio){
			init(f);
		}
	}
}
int main(){

	return 0;
}


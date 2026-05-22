/*
Fila — Simulador de atendimento
Você tem uma fila de banco com clientes identificados por número (1, 2, 3...). Implemente uma fila que suporte:

enfileirar(cliente) — adiciona um cliente no fim
atender() — remove e retorna o primeiro da fila
proximo() — mostra quem será atendido sem remover

Desafio: Dados os clientes [5, 3, 8, 1, 9] chegando nessa ordem, simule o atendimento de 3 deles e mostre quem ainda está esperando.
*/

#include <stdio.h>
#define MAX 7

typedef struct{
	int codigo;
}Cliente;

typedef struct{
	Cliente v[MAX];
	int inicio;
	int final;
}Fila;

int filaVazia(Fila f){
	return (f.inicio == f.final);
}

void init (Fila *f){
	f->inicio=0;
	f->final=0;
}

int filaCheia(Fila f){
	return (f.final==MAX);
}

int enfileirar(Fila *f, Cliente c){
	if (filaCheia(*f))return -1;
	else{
		f->v[f->final] = c;
		f->final++;
		return 0;
	}
}

Cliente atender(Fila *f){
	Cliente vazio = {-1};
    if (filaVazia(*f)) return vazio;
	else{
		Cliente atendido = f->v[f->inicio];
		f->inicio++;
		return atendido;
	}
}

void proximo(Fila f){
	if (filaVazia(f)) return;
    printf("Próximo: %d\n", f.v[f.inicio].codigo);
}

void mostrarTodos(Fila f){
	if (filaVazia(f))return;
	else {
		int quant = f.final-f.inicio;
		int i;
		for (i = f.inicio;i<f.final;i++){
			printf("Cliente --> %d\n",f.v[i].codigo);
		}	
	}
}

int main(){
	Fila f;
	init(&f);
	Cliente c1,c2,c3,c4,c5;
	c1.codigo=5;
	c2.codigo=3;
	c3.codigo=8;
	c4.codigo=1;
	c5.codigo=9;
	enfileirar(&f,c1);
	enfileirar(&f,c2);
	enfileirar(&f,c3);
	enfileirar(&f,c4);
	enfileirar(&f,c5);
	atender(&f);
	atender(&f);
	atender(&f);
	mostrarTodos(f);
	return 0;
}


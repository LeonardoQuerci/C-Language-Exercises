#include <stdio.h>
#include <string.h>
#define MAX 5
/*Listas lineares - Aula 27/04/2026 
	São coleções unidimensionais de estruturas como:
	-Lista de compras
	-Lista de chamadas
	Esses elementos sçao acessados sequencialmente, usando aoenas as operações previstas para a lista
	PILHA = (LAST IN, FIRST OUT) -- PENSAR EM ALGO VERTICAL ( A ORDEM QUE AS PESSOAS CHEGAREM É O INVERSO DA ORDEM DE SAIDA)
	FILA = (FIRST IN, FIRST OUT) -- PENSAR EM ALGO HORIZONTAL ( A ORDEM QUE AS PESSOAS CHEGAREM É A ORDEM DE SAIDA)
*/

typedef struct {
	char isbn[20];
	char titulo[20];
}Livro;

typedef struct{
	Livro v[MAX];
	int topo; //Vazio se for -1
}Pilha;

void init(Pilha *p){
	p->topo = -1;
}

int listaVazia(Pilha p){
	if (p.topo == -1){
		return 1;
	}else{
		return 0;
	}
}

int listaCheia(Pilha p){
	if (p.topo == MAX-1){
		return 1;
	}else{
		return 0;
	}
}

void push(Pilha *p, Livro l){
	if (listaCheia(*p)){
		printf("A lista esta cheia, retire algum livro para adicionar mais \n");
	}else{
		p->topo += 1;
		p->v[p->topo] = l;
		printf("Livro adicionado com sucesso\n");
	}
}

void pop(Pilha *p, Livro *l){
	if (listaVazia(*p)){
		printf("A lista ja esta vazia\n");
	}else{
		*l = p->v[p->topo] ;
		p->topo -= 1;
		printf("Livro removido com sucesso\n");
	}
}

void mostrarPilha(Pilha p){
    int i;
    printf("\n\n*****************************************************************\n");

    for (i = 0; i <= p.topo; i++){
        if(i == 0){
            printf("%-25s ---> %s\n","FUNDO DA PILHA", p.v[i].titulo);
        }else if(i == p.topo){
            printf("%-25s ---> %s\n","TOPO DA PILHA", p.v[i].titulo);
        }else{
            printf("%-25s ---> %s\n","ITEM", p.v[i].titulo);
        }
    }

    printf("*****************************************************************\n\n");
}

int main(){
	Pilha biblioteca;
	init(&biblioteca);
	Livro p;
	strcpy(p.isbn,"001");
	strcpy(p.titulo,"001");
	push(&biblioteca,p);
	strcpy(p.isbn,"002");
	strcpy(p.titulo,"002");
	push(&biblioteca,p);
	strcpy(p.isbn,"003");
	strcpy(p.titulo,"003");
	push(&biblioteca,p);
	strcpy(p.isbn,"004");
	strcpy(p.titulo,"004");
	push(&biblioteca,p);
	mostrarPilha(biblioteca);
	pop(&biblioteca,&p);
	printf("\n\nLivro retirado == %s",p.titulo);
	mostrarPilha(biblioteca);
	
	
	
	return 0;
}

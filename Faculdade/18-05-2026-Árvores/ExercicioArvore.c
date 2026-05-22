/*
Árvore — Soma dos nós
Dada uma árvore binária de busca (BST), implemente uma função que retorna a soma de todos os valores dos nós. Depois, implemente outra que retorna apenas a soma das folhas (nós sem filhos).
Teste com essa árvore:
        10
       /  \
      5    15
     / \     \
    3   7    20

Soma total ? 60
Soma das folhas (3, 7, 20) ? 30

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
	int codigo;
	struct Pessoa *esq;
	struct Pessoa *dir;
}Pessoa;

typedef Pessoa * Arvore;

void init (Arvore *a){
	*a = NULL;
}

void inserir(Pessoa **a, Pessoa p){
	if(*a == NULL){
		*a = (Pessoa *)malloc(sizeof(Pessoa));
		p.esq = NULL;
		p.dir = NULL;
		**a = p;
	}else{
		if((*a)->codigo == p.codigo)return;
		else if ((*a)->codigo<p.codigo)inserir(&(*a)->dir,p);
		else inserir(&(*a)->esq,p);
	}
}
int somaTotal=0;
int somaFilhos = 0;
void ordem(Arvore a){
	if(a!=NULL){
		somaTotal += a->codigo;
		
		if(a->esq == NULL && a->dir == NULL){
			somaFilhos += a->codigo;
		}
		ordem(a->esq);
		ordem(a->dir);
	}
}

int main(){
	Arvore princ;
	init(&princ);
	Pessoa p1 = {10};
	Pessoa p2 = {15};
	Pessoa p3 = {20};
	Pessoa p4 = {5};
	Pessoa p5 = {3};
	Pessoa p6 = {7};
	inserir(&princ,p1);
	inserir(&princ,p2);
	inserir(&princ,p3);
	inserir(&princ,p4);
	inserir(&princ,p5);
	inserir(&princ,p6);
	ordem(princ);
	
	printf("Soma total = %d\n",somaTotal);
	printf("Soma Filhos = %d\n",somaFilhos);
	return 0;
}


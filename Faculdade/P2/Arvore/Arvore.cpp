#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct Usuario{
	char cpf[20];
	struct Usuario *esquerdo;
	struct Usuario *direito;
}Usuario;

typedef Usuario *Arvore;

int inserir(Usuario **a, Usuario p){
	if(*a == NULL){
		*a =(Usuario *) malloc(sizeof(Usuario));
		p.direito = NULL;
		p.esquerdo = NULL;
		**a = p;
		return 1;
	}else{
		int comp = strcmp((*a)->cpf,p.cpf);
		if(comp<0) return inserir(&(*a)->direito, p);
		else if(comp>0) return inserir(&(*a)->esquerdo, p);
		else return -1;
	}
}

void mostra(Usuario p){
	printf("\nCPF[%s]", p.cpf);
}

void preOrdem(Arvore a){
	if(a!=NULL){
		mostra(*a);
		preOrdem(a->esquerdo);
		preOrdem(a->direito);
	}
}

void ordem(Arvore a){
	if(a!=NULL){
		ordem(a->esquerdo);
		mostra(*a);
		ordem(a->direito);
	}
}

void posOrdem(Arvore a){
	if(a!=NULL){
		posOrdem(a->esquerdo);
		posOrdem(a->direito);
		mostra(*a);
	}
}

void init (Arvore *a){
	*a = NULL;
}

int main(){

	return 0;
}


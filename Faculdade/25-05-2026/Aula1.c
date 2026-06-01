#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa{
	char cpf[30];
	char nome[40];
	char apelido[30];
	char sexo; //M ou F
	struct Pessoa *esq;
	struct Pessoa *dir;
}Pessoa ;

void mostra(Pessoa p){
	printf("\nCPF[%s] | %s | %s | %c", p.cpf,p.nome,p.apelido,p.sexo);
}

typedef Pessoa *Arvore;

void init(Arvore *a){
	*a = NULL;
}

int inserir(Pessoa **a, Pessoa p){
	if(*a == NULL){
		*a = (Pessoa *)malloc(sizeof(Pessoa));
		p.esq = NULL;
		p.dir =NULL;
		**a = p;
		return 1;
	}else{
		if(strcmp((*a)->cpf,p.cpf)==0){
			return -1; //Cpf cadastrado 
		}else if ((strcmp((*a)->cpf,p.cpf)<0)){
			inserir(&(*a)->dir,p);
		}else{
			inserir(&(*a)->esq,p);
		}
	}
}
//raiz,toda esquerda,toda direita 
void preOrdem(Arvore a){
	if(a!=NULL){
		mostra(*a);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
} 
//toda esquerda, raiz, toda direita
void ordem (Arvore a){
	if(a!=NULL){
		ordem(a->esq);
		mostra(*a);
		ordem(a->dir);
	}
}

void posOrdem(Arvore a){
	if(a!=NULL){
		posOrdem(a->esq);
		posOrdem(a->dir);
		mostra(*a);
	}
}

int main(){
	Arvore seringueira;
	init(&seringueira);
	Pessoa p1 = {"11111111","Leonardo", "Leo", 'M'};
	Pessoa p2 = {"22222222","Julia", "Juu", 'F'};
	Pessoa p3 = {"33333333","Carlos", "kk", 'M'};
	Pessoa p4 = {"44444444","Edson", "ED", 'M'};
	Pessoa p5 = {"55555555","Fulano", "Ciclano", 'M'};
	inserir(&seringueira, p3);
	inserir(&seringueira, p1);
	inserir(&seringueira, p5);
	inserir(&seringueira, p4);
	inserir(&seringueira, p2);
	
	printf("MOSTRANDO EM PRE - ORDEM\n");
	preOrdem(seringueira);
	printf("\n\nMOSTRANDO EM ORDEM\n");
	ordem(seringueira);
	printf("\n\nMOSTRANDO EM POS - ORDEM\n");
	posOrdem(seringueira);
	
	
	
	return 0;
}


/**************************************** �RVORES ******************************************
S�o estruturas de interliga��o de 'n�s' bastante �til para construir estruturas hier�rquicas
-- Pr�-ordem : visita o n�, visita em pr�-ordem sua sub-�rvore da esquerda, visita em pr�-
ordem sua sub-�rvore da direita

-- Ordem : visita em ordem a sub-�rvore da esquerda, visita o n�, visita em ordem a sub-�rvore
da direita.

-- P�s-ordem : visita em p�s-ordem a sub-�rvore da esquerda, visita em p�s-ordem a sub-
�rvore da direita, visita o n�
********************************************************************************************/

//arvore de pessoas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
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

typedef Pessoa * Arvore;

int inserir(Pessoa **a, Pessoa p){
	if(*a == NULL){
		*a = (Pessoa *) malloc(sizeof(Pessoa));
		p.esq = NULL;
		p.dir = NULL;
		**a = p;
		//mostra(**a);
		return 1;
	}else{
		if(strcmp((*a)->cpf, p.cpf)==0){
			return -1; // cpf ja cadastrado
		}else if (strcmp((*a)->cpf, p.cpf)<0){
			return inserir(&(*a)->dir,p);
		}else{
			return inserir(&(*a)->esq,p);
		}
		
	}
}
/*
typedef struct{
	Pessoa *raiz;
} Arvore;
*/
void init(Arvore *a){
	//a->raiz = NULL;
	*a = NULL;
}

void ordem(Arvore a){
	if(a!= NULL){
		ordem(a->esq);
		mostra(*a);
		ordem(a->dir);
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
	
	ordem(seringueira);
	return 0;
}


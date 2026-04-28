#include <stdio.h>
#include <malloc.h>
typedef struct{
	int codigo;
	char nome[35];
}Pessoa;
void main(){
	Pessoa joao = {123, "Fulano de tal"};
	Pessoa *p=(Pessoa *) malloc(sizeof(Pessoa));
	//*p=joao;
	Pessoa vPessoa[]={
		{234,"Trump"},
		joao	
	};
	p=vPessoa;
	printf("\n%s \n",p->nome);
	free(p);
}




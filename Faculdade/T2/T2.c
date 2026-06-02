#include <stdio.h>
#include <string.h>

typedef struct Pessoa{
	char cpf[20];
	char nome[20];
	char email[30];
	char celular[15];
	char profissao[20];
}Pessoa;

typedef struct No{
	char cpf[20];
	int indice;
	struct No *esquerda;
	struct No *direita;
}No;

typedef No* Arvore;
Arvore treeBi;

void pedirDados(){
	Pessoa p;
	printf("Digite seu CPF: ");
	scanf(" %[^\n]s", p.cpf);
	printf("Digite seu nome: ");
	scanf(" %[^\n]s", p.nome);
	printf("Digite seu email: ");
	scanf(" %[^\n]s", p.email);
	printf("Digite seu celular: ");
	scanf(" %[^\n]s", p.celular);
	printf("Digite seu profissão: ");
	scanf(" %[^\n]s", p.profissao);
	
	FILE * arquiBin = fopen("./arquivoBinario.dat", "a+b");
	fwrite(&p,sizeof(Pessoa),1,arquiBin);
	fclose(arquiBin);
}

void inserir(No **a, No n){
	if (*a==NULL){
		*a = (No *)malloc(sizeof(No));
		n.esquerda=NULL;
		n.direita=NULL;
		**a = n;
	}
	else{
		if(strcmp((*a)->cpf,n.cpf)==0)return;
		else if (strcmp((*a)->cpf,n.cpf)<0)inserir(&(*a)->direita,n);
		else inserir(&(*a)->esquerda,n);
	}
}

void carregarDados(){	
	treeBi = NULL;
	int indi = 0;
	int verificar=1;
	FILE * arquiBin = fopen("./arquivoBinario.dat", "rb");
	rewind(arquiBin);
	//loop
	while(verificar)){
		indi = ftell(arquiBin);
		Pessoa p;
		verificar = fread(&p,sizeof(Pessoa),1,arquiBin);
		No n1={p.cpf, indi};
		inserir(&treeBi, n1);
	}
	fclose(arquiBin);
}

void localizar(){
}

void gerarRelatorio(){
}

int main(){
	pedirDados();

	return 0;
}


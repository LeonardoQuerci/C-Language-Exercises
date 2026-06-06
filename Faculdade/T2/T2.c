#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	scanf(" %[^\n]", p.cpf);
	printf("Digite seu nome: ");
	scanf(" %[^\n]", p.nome);
	printf("Digite seu email: ");
	scanf(" %[^\n]", p.email);
	printf("Digite seu celular: ");
	scanf(" %[^\n]", p.celular);
	printf("Digite seu profissão: ");
	scanf(" %[^\n]", p.profissao);
	
	FILE * arquiBin = fopen("./arquivoBinario.dat", "a+b");
	fwrite(&p,sizeof(Pessoa),1,arquiBin);
	fclose(arquiBin);
}

void inserir(No **a, No n){
	if (*a==NULL){
		*a = (No*)malloc(sizeof(No));
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
	while(verificar){
		indi = ftell(arquiBin);
		Pessoa p;
		verificar = fread(&p,sizeof(Pessoa),1,arquiBin);
		if (verificar ==0)break;
		No n1;
		strcpy(n1.cpf,p.cpf);
		n1.indice = indi;
		inserir(&treeBi, n1);
	}
	fclose(arquiBin);
}

int comparar(No **a, char cpfDesejado[20]){
	if ((*a) == NULL)return -1;
	int comp = strcmp(cpfDesejado, (*a)->cpf);
	if (comp<0)return comparar(&(*a)->esquerda,cpfDesejado);
	else if (comp>0)return comparar(&(*a)->direita,cpfDesejado);
	else return (*a)->indice;
}

void localizar(){
	char cpfDesejado[20];
	printf("Qual o cpf que deseja consultar ---> ");
	scanf("%s",cpfDesejado); //se algo der errado
	int indiceEncontrado = comparar(&(treeBi),cpfDesejado);
	
	if (indiceEncontrado != -1){
		FILE * arquiBin = fopen("./arquivoBinario.dat", "rb");
		rewind(arquiBin);
		fseek(arquiBin,indiceEncontrado,SEEK_SET);
		Pessoa aux;
		fread(&aux,sizeof(Pessoa),1,arquiBin);
		printf("%s | %s | %s | %s | %s\n",aux.cpf,aux.nome,aux.email,aux.celular, aux.profissao);
	}else{
		printf("******* CPF NAO ENCONTRADO *******");
	}
}

void ordem(Arvore a, FILE * arq, FILE * arquiRel){ 
	if(a!= NULL){
			ordem(a->esquerda,arq,arquiRel);
			
			fseek(arq,a->indice,SEEK_SET);
			Pessoa aux;
			fread(&aux,sizeof(Pessoa),1,arq);
			fprintf(arquiRel,"%s | %s | %s\n",aux.cpf,aux.nome,aux.profissao);
			ordem(a->direita,arq,arquiRel);
	}
}

void gerarRelatorio(Arvore a){
	FILE * arquiBin = fopen("./arquivoBinario.dat", "rb");
	rewind(arquiBin);
	FILE * arquiRel = fopen("./arquivoRelatorio.txt", "w+");
	ordem(a,arquiBin, arquiRel);
	
}
int main(){
	carregarDados();
	gerarRelatorio(treeBi);

	return 0;
}


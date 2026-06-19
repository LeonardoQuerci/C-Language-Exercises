#include <stdio.h>
#include <stdlib.h>
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

typedef No *Arvore;
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
	printf("Digite sua profissao: ");
	scanf(" %[^\n]", p.profissao);

	FILE *arquiBin = fopen("./arquiBin.dat", "a+b");
	if(arquiBin == NULL){
		printf("Erro ao abrir arquivo binario.\n");
		return;
	}
	fwrite(&p, sizeof(Pessoa), 1, arquiBin);
	fclose(arquiBin);
}

void inserir(No **a, No n){
	if(*a == NULL){
		*a = (No *)malloc(sizeof(No));
		n.esquerda = NULL;
		n.direita = NULL;
		**a = n;
	}else{
		// BUG 5 CORRIGIDO: padronizado strcmp(novo, atual) igual ao comparar()
		int comp = strcmp(n.cpf, (*a)->cpf);
		if(comp == 0) return;
		else if(comp < 0) inserir(&(*a)->esquerda, n);
		else inserir(&(*a)->direita, n);
	}
}

void carregarDados(){
	treeBi = NULL;
	int indi = 0;
	int verificar = 1;

	// BUG 3 CORRIGIDO: verificar se arquivo existe antes de ler
	FILE *arquiBin = fopen("./arquiBin.dat", "rb");
	if(arquiBin == NULL){
		printf("Nenhum dado encontrado. Arquivo nao existe ainda.\n");
		return;
	}
	rewind(arquiBin);

	while(verificar){
		indi = ftell(arquiBin);
		Pessoa p;
		verificar = fread(&p, sizeof(Pessoa), 1, arquiBin);
		// BUG 1 CORRIGIDO: era "=0" (atribuicao), corrigido para "==0" (comparacao)
		if(verificar == 0) break;
		No n1;
		strcpy(n1.cpf, p.cpf);
		n1.indice = indi;
		inserir(&treeBi, n1);
	}
	fclose(arquiBin);
}

int comparar(No **a, char cpfDesejado[20]){
	if((*a) == NULL) return -1;
	int comp = strcmp(cpfDesejado, (*a)->cpf);
	if(comp < 0) return comparar(&(*a)->esquerda, cpfDesejado);
	else if(comp > 0) return comparar(&(*a)->direita, cpfDesejado);
	else return (*a)->indice;
}

void localizar(){
	char cpfDesejado[20];
	printf("Qual o cpf que deseja consultar ---> ");
	scanf("%s", cpfDesejado);
	int indiceEncontrado = comparar(&(treeBi), cpfDesejado);

	if(indiceEncontrado != -1){
		FILE *arquiBin = fopen("./arquiBin.dat", "rb");
		if(arquiBin == NULL){
			printf("Erro ao abrir arquivo binario.\n");
			return;
		}
		fseek(arquiBin, indiceEncontrado, SEEK_SET);
		Pessoa aux;
		fread(&aux, sizeof(Pessoa), 1, arquiBin);
		printf("%s | %s | %s | %s | %s\n", aux.cpf, aux.nome, aux.email, aux.celular, aux.profissao);
		fclose(arquiBin);
	}else{
		printf("******* CPF NAO ENCONTRADO *******\n");
	}
}

void ordem(Arvore a, FILE *arq, FILE *arquiRel){
	if(a != NULL){
		ordem(a->esquerda, arq, arquiRel);

		fseek(arq, a->indice, SEEK_SET);
		Pessoa aux;
		fread(&aux, sizeof(Pessoa), 1, arq);
		// BUG 2 CORRIGIDO: era fprintf(arq,...), corrigido para fprintf(arquiRel,...)
		fprintf(arquiRel, "%s | %s | %s\n", aux.cpf, aux.nome, aux.profissao);

		ordem(a->direita, arq, arquiRel);
	}
}

void gerarRelatorio(Arvore a){
	FILE *arquiBin = fopen("./arquiBin.dat", "rb");
	if(arquiBin == NULL){
		printf("Nenhum dado para gerar relatorio.\n");
		return;
	}
	FILE *arquiRel = fopen("./arquiRelatorio.txt", "w+");
	if(arquiRel == NULL){
		printf("Erro ao criar arquivo de relatorio.\n");
		fclose(arquiBin);
		return;
	}
	ordem(a, arquiBin, arquiRel);
	// BUG 4 CORRIGIDO: arquivos nao eram fechados
	fclose(arquiBin);
	fclose(arquiRel);
	printf("Relatorio gerado em arquiRelatorio.txt\n");
}

int main(){
	int opcao;
	carregarDados();

	do {
		printf("\n1 - Cadastrar pessoa\n");
		printf("2 - Localizar por CPF\n");
		printf("3 - Gerar relatorio\n");
		printf("0 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				pedirDados();
				carregarDados();
				break;
			case 2:
				localizar();
				break;
			case 3:
				gerarRelatorio(treeBi);
				break;
		}
	} while(opcao != 0);

	return 0;
}

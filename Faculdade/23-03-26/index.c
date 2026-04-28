#include <stdio.h>
#define cadastrar 1
#define listar 2
#define buscar 3
#define fim 4

//CONSTRUINDO UM MENU QUALQUER 
void cadastro(){
	char c;
	printf("-----------------------------------------");
	printf("\nVoce esta na opcao CADASTRAR ALUNO\n");
	printf("Clique <ENTER> para voltar");
	printf("\n-----------------------------------------");
	fflush(stdin);
	c=getchar();
}
void lista(){
	char c;
	printf("-----------------------------------------");
	printf("\nVoce esta na opcao LISTAR ALUNOS\n");
	printf("\nClique <ENTER> para voltar");
	printf("\n-----------------------------------------");
	fflush(stdin);
	c=getchar();
}

void busca(){
	char c;
	printf("-----------------------------------------");
	printf("\nVoce esta na opcao BUSCAR ALUNO\n");
	printf("\nClique <ENTER> para voltar");
	printf("\n-----------------------------------------");
	fflush(stdin);
	c=getchar();
}

int menu(){
	int desejo;
	printf("----------MENU----------\n");
	printf("1-CADASTRAR ALUNOS\n2-LISTAR ALUNOS\n3-BUSCAR ALUNOS\n4-SAIR DO SISTEMA");
	printf("\nDigite a opcao desejada\n");
	scanf("%d",&desejo);
	return desejo;
}

int main(){
	int escolha=menu();
	while (escolha!=fim){
		switch(escolha){
		case cadastrar:
			cadastro();
			break;
		case listar:
			lista();
			break;
		case buscar:
			busca();
			break;
		default:
			printf("\nOPCAO INVALIDA\n");
		}
		escolha=menu();
	}
	return 0;
}

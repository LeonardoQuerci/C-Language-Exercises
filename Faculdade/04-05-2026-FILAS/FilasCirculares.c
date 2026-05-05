#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define MAX 3
#include <stdlib.h>

//ESTOU USANDO O MESMO EXEMPLO DE FILAS LINEARES MAS AGORA UTILIZAREI LISTAS CIRCULARES

typedef struct{
	char titulo[20];
	char interprete[20];
	char caminho[60];
}Musica;

typedef struct{
	Musica v[MAX];
	int inicio; //onde a musica que vai sair vai ser retirada
	int final; //onde a musica nova vai entrar 
}Fila;

int filaVazia(Fila f){
	return(f.inicio == f.final); 
}

int filaCheia(Fila f){
	return ((f.final+1) % MAX == f.inicio);
}

void init(Fila *f){
	f->inicio = 0;
	f->final = 0;
}

int inserir(Fila *f, Musica m){
	f->v[f->final] = m;
	f->final = (f->final+1) % MAX;
	printf("Musica adicionada!\n");
	return 0;

}

int retirar(Fila *f){
	f->inicio = (f->inicio+1) % MAX;
	return 0;
}

void mostrar(Fila f){
	int i = f.inicio;
	
	if(filaVazia(f)){
		printf("Fila vazia!\n");
		return;
	}
	
	printf("\nMusicas na fila:\n");
	printf("%-10s %-15s %-20s\n", "TITULO", "INTERPRETE", "CAMINHO");
	
	while(i!=f.final){
		printf("%-10s %-15s %-20s\n",
			f.v[i].titulo,
			f.v[i].interprete,
			f.v[i].caminho);
		i=(i+1)%MAX;
	}
}

int menu(){
	int op;
	
	printf("\n===== MENU =====\n");
	printf("1 - Inserir musica\n");
	printf("2 - Remover musica da fila e tocar\n");
	printf("3 - Mostrar fila\n");
	printf("0 - Sair\n");
	printf("Escolha: ");
	scanf("%d", &op);
	getchar(); // limpar buffer
	
	return op;
}

int main(){
	Fila discoteca;
	init(&discoteca);
	
	int opcao;
	Musica m;

	do{
		opcao = menu(); // chamada da função
		system("cls");
		switch(opcao){
			case 1:
				if(filaCheia(discoteca)){
					printf("Fila cheia!\n");
				}else{
					printf("Titulo: ");
					scanf(" %19[^\n]", m.titulo);

					printf("Interprete: ");
					scanf(" %19[^\n]", m.interprete);

					printf("Caminho: ");
					scanf(" %59[^\n]", m.caminho);

					inserir(&discoteca, m);	
				}
				break;
			case 2:
				system("cls");
				if(retirar(&discoteca) == -1){
					printf("Fila vazia!\n");
				}else{
					printf("Musica removida!\n");
				}
				break;
			case 3:
				mostrar(discoteca);
				break;
			case 0:
				printf("Saindo...\n");
				break;

			default:
				printf("Opcao invalida!\n");
		}

	}while(opcao != 0);

	return 0;
}

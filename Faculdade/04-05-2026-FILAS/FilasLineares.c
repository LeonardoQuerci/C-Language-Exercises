#include <stdio.h>
#include <string.h>
#define MAX 3
#include <stdlib.h>
//Ja falamos de pilhas na ultima aula e agora iremos ver sobre filas lineares

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
	return(f.inicio == f.final); //inicio =0 e final =0
}

int filaCheia(Fila f){
	return (f.final == MAX);
}

void init(Fila *f){
	f->inicio = 0;
	f->final = 0;
}

int inserir(Fila *f, Musica m){
	if (filaCheia(*f)){
		return -1;
	}else{
		f->v[f->final] = m;
		f->final++;
		return 0;
	}
}

int retirar(Fila *f){
	if (filaVazia(*f)){
		return -1;
	}else{
		f->inicio++;
		
		if (f->inicio==f->final){
			init(f);
		}
		return 0;
	}
}

void mostrar(Fila f){
	int i;
	
	if(filaVazia(f)){
		printf("Fila vazia!\n");
		return;
	}
	
	printf("\nMusicas na fila:\n");
	printf("%-10s %-15s %-20s\n", "TITULO", "INTERPRETE", "CAMINHO");
	
	for(i = f.inicio; i < f.final; i++){
		printf("%-10s %-15s %-20s\n",
			f.v[i].titulo,
			f.v[i].interprete,
			f.v[i].caminho);
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
					printf("Musica adicionada!\n");
				}
				system("cls");
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
				system("cls");
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

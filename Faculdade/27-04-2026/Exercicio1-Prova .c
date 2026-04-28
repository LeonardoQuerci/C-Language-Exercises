#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int quantidade = 8;
int contribuicaoTotal=0;
typedef struct{
	char nome[20];
	char cpf[15];
	int contribuicao;
}Contribuinte;

Contribuinte c[8] = {
    {"Ana", "11111111111", 10},
    {"Carlos", "33333333333", 20},
    {"Gabriel", "77777777777", 25},
    {"Bruno", "22222222222", 15},
    {"Eduardo", "55555555555", 22},
    {"Daniela", "44444444444", 18},
    {"Fernanda", "66666666666", 13},
    {"Helena", "88888888888", 17}
};

void troca(Contribuinte c[], int x, int y){
	Contribuinte aux;
	aux=c[x];
	c[x]=c[y];
	c[y]=aux;
}

void acharValorTotal(Contribuinte c[]){
	int i;
	contribuicaoTotal=0;
	for (i=0;i<quantidade;i++){
		contribuicaoTotal+=c[i].contribuicao; 		
	}
}
void mostrar(Contribuinte c[]){
	int i;
	acharValorTotal(c);
	printf("\n===============================================================\n");
    printf("%-15s %-20s %-15s %6s\n",
           "CPF", "NOME", "CONTRIB.", "%");
    printf("---------------------------------------------------------------\n");

    for(i = 0; i < quantidade; i++){
        float porcentagem = (float)c[i].contribuicao / contribuicaoTotal * 100;

        printf("%-15s %-20s %-15d %8.2f%%\n",
               c[i].cpf,
               c[i].nome,
               c[i].contribuicao,
               porcentagem);
    }
    printf("\n");
}

void bubbleSortCpf(Contribuinte c[]){
	int i,j;
	for (i=0;i<quantidade-1;i++){
		for (j=0;j<quantidade-i-1;j++){
			int comp = strcmp(c[j].cpf,c[j+1].cpf);
			if (comp>0){
				troca(c,j,j+1);
			}
		}
	}
	mostrar(c);
}

void binarySearch(Contribuinte c[]){
	bubbleSortCpf(c);//Necessário para que a busca binaria funcione corretamente
	int inicio=0,fim=quantidade-1,meio;
	char cpfDesejado[15];
	printf("DIGITE O CPF DESEJADO ---->");
	scanf("%s",cpfDesejado);
	while(inicio<=fim){
		meio=(int)(inicio+fim)/2;
		int comp= strcmp(c[meio].cpf,cpfDesejado);
		if(comp<0){
			inicio = meio + 1;
		}else if (comp>0){
			fim = meio - 1;
		}else{
			printf("\n*********CONTRIBUINTE ENCONTRADO*********\n");
			printf("NOME: %s | CPF: %s | CONTRIBUICOES: %d\n\n",c[meio].nome,c[meio].cpf,c[meio].contribuicao);
			
			return;
		}
	}
	printf("NENHUM CONTRIBUINTE FOI ENCONTRADO COM ESSE CPF\n\n");
}

int menu(){
	int desejo;
	printf("**********SEJA BEM VINDO**********\n");
	printf("1-ORDENAR VETOR POR CPF E MOSTRAR TODOS OS CONTRIBUINTES\n");
	printf("2-MOSTRAR OS CONTRIBUINTES DO JEITO QUE ESTAO SEM NENHUM CRITERIO DE ORGANIZACAO\n");
	printf("3-LOCALIZAR CONTRIBUINTE POR CPF\n");
	printf("4-SAIR\n");
	printf("DIGITE A OPCAO DESEJADA E DEPOIS APERTE <ENTER> ---->");
	scanf("%d",&desejo);
	return desejo;
}
int main(){
	int escolhido = menu();
	while (escolhido!=4){
		system("cls");
		switch(escolhido){
			case 1:
				bubbleSortCpf(c);
				break;
			case 2:
				mostrar(c);
				break;
			case 3:
				binarySearch(c);
				break;
			default:
				printf("\n***********OPCAO INVALIDA***********");
				break;
		}
		escolhido=menu();
	}
	return 0;
	
}

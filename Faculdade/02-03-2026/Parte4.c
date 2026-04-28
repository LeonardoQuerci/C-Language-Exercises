//vetor de struct
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct{
	char codigo[3];
	char nome[40];
	int populacao;
	float rpc;//renda per capita
}Estado;

Estado e[] = {
    {"SP", "Sao Paulo", 45919049, 51200.50},
    {"RJ", "Rio de Janeiro", 17366189, 45100.75},
    {"MG", "Minas Gerais", 21411923, 32000.40},
    {"PR", "Parana", 11516840, 38000.20},
    {"RS", "Rio Grande do Sul", 10880506, 42000.10}
};

void mostrarEstado(Estado e){
    printf("\nMostrando o estado desejado:\n");
    printf("Codigo: %s\n", e.codigo);
    printf("Nome: %s\n", e.nome);
    printf("Populacao: %d\n", e.populacao);
    printf("Renda per capita: %.2f\n", e.rpc);
}

int buscaEstado(char siglaProcurada[3]){
	int i;
	for (i=0;i<4;i++){
		if(strcmp(e[i].codigo,siglaProcurada)==0){
			return i;
		}
	}
	return -1;
}

void maiuscula(char siglaProcurada[3]){
	int i=0;
	while(siglaProcurada[i]!='\0'){
		siglaProcurada[i]=toupper(siglaProcurada[i]);
		i++;
	}
}

void main(){
	char desejado[3];
	printf("Informe a sigla do estado desejado --->");
	scanf("%2s",desejado);
	maiuscula(desejado);	
	int posicao = buscaEstado(desejado);
	if (posicao == -1){
		printf("Sigla nao identificada");
	}else{
		mostrarEstado(e[posicao]);
	}
}

//linear search and binary search
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
typedef struct{
	char codigo[3];
	char nome[40];
	int populacao;
	float rpc;//renda per capita
}Estado;

Estado e[] = {
	{"MG", "Minas Gerais", 21411923, 32000.40},
	{"PR", "Parana", 11516840, 38000.20},
	{"RJ", "Rio de Janeiro", 17366189, 45100.75},
	{"RS", "Rio Grande do Sul", 10880506, 42000.10},
    {"SP", "Sao Paulo", 45919049, 51200.50}
};

void mostrarEstado(Estado e){
    printf("\nMostrando o estado desejado:\n");
    printf("Codigo: %s\n", e.codigo);
    printf("Nome: %s\n", e.nome);
    printf("Populacao: %d\n", e.populacao);
    printf("Renda per capita: %.2f\n", e.rpc);
}

//linear search function
int buscaEstado(char siglaProcurada[3]){
	int i =0;
	for (i=0;i<sizeof(e)/sizeof(Estado);i++){
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
//binary search function
// Works only because the array is sorted by state code
char* pesquisaBinaria(Estado e[],char siglaProcurada[3],int n){
	int inf=0;
	int sup=n-1;
	int meio;
	while(inf<=sup){
		meio =(int)(sup+inf)/2;
		int comp=strcmp(e[meio].codigo,siglaProcurada);
		if(comp==0){
			printf("\n-------------Binary Search-------------\n");
			mostrarEstado(e[meio]);
			return e[meio].codigo;
		}else if(comp<0){
			inf=meio+1;
		}else{
			sup=meio-1;
		}	
	}
	return NULL;
}


void main(){
	setlocale(LC_ALL,"");
	char desejado[3];
	printf("Informe a sigla do estado desejado --->");
	scanf("%2s",desejado);
	maiuscula(desejado);	
	int posicao = buscaEstado(desejado);
	if (posicao == -1){
		printf("Sigla não identificada");
	}else{
		printf("\n-------------Linear Search-------------\n");
		mostrarEstado(e[posicao]);
	}
	//binary searched
	char *nome= pesquisaBinaria(e,desejado,5);
	if (nome == NULL){
		printf("Sigla não identificada");
	}else{
		
		printf("Estado encontrado: %s\n", nome);
	}
}

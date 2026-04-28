#include <stdio.h>
#include <string.h>

typedef struct{
	int id;
	char nome[50];
	int idade;
	char cpf[15];
}Pessoa;

void merge(Pessoa h[],int tamanhoH, Pessoa p[],int tamanhoP, Pessoa e[],int tamanhoE){
	int i=0,j=0,k=0;
	while(i<tamanhoP && j<tamanhoE){
    	int comparacao = strcmp(p[i].cpf,e[j].cpf);
    	if(comparacao<0){
    		h[k]=p[i];
    		i++;
    	}else if (comparacao>0){
    		h[k]=e[j];
    		j++;
    	}else{
    		h[k]=p[i];
    		i++;
    		j++;
    	}
    	k++;
    }
    while(i<tamanhoP){
    	h[k]=p[i];
    	i++;
    	k++;
	}
	while(j<tamanhoE){
		h[k]=e[j];
    	j++;
    	k++;
	}
}

void mostrarVetor(Pessoa p[],int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("ID: %d | Nome: %s | Idade: %d | CPF: %s\n", p[i].id, p[i].nome, p[i].idade,p[i].cpf);
	}
	printf("\n\n");
}

int main(){
	Pessoa p[] = {
        {10, "Leonardo Querci", 40, "111.111.111-11"},
        {20, "Fulano de tal",   50, "222.222.222-22"},
		{27, "Ciclano de tal",  80, "333.333.333-33"},
        {33, "FULANINHO",40, "444.444.444-44"},
    };
    Pessoa e[] = {
        {55, "Carlos Souza",    25, "555.555.555-55"},
        {66, "Mariana Lima",    32, "666.666.666-66"},
        {77, "Roberto Alves",   47, "777.777.777-77"},
        {88, "Fernanda Costa",  19, "888.888.888-88"},
        {99, "Paulo Henrique",  61, "999.999.999-99"}
    };
    
    int tamanhoP=sizeof(p)/sizeof(p[0]);
    int tamanhoE=sizeof(e)/sizeof(e[0]);
    int tamanhoH=tamanhoP+tamanhoE;
    Pessoa h[tamanhoH];
    
    merge(h,tamanhoH,p,tamanhoP,e,tamanhoE);
    mostrarVetor(h,tamanhoH);
	return 0;
	
}

#include <stdio.h>

typedef struct{
	int id;
	char nome[50];
	int idade;
}Pessoa;

//COM RECURSIVIDADE
void inverterCampos(Pessoa e[],int i,int f){
	Pessoa temp;	
	if(i>f)return;
	temp=e[i];
	e[i]=e[f];
	e[f]=temp;
	i++;
	f--;
	inverterCampos(e,i,f);
}

/*
SEM RECURSIVIDADE
void inverterCampos(Pessoa e[],int tamanho){
	int i,f;
	i = 0;
	f = tamanho - 1;
	Pessoa temp;
	while(i<f){
		temp=e[i];
		e[i]=e[f];
		e[f]=temp;
		i++;
		f--;
	}
}*/

void mostrarVetor(Pessoa p[],int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("ID: %d | Nome: %s | Idade: %d\n", p[i].id, p[i].nome, p[i].idade);
	}
	printf("\n\n");
}

main(){
	Pessoa p[] = {
        {10, "Leonardo Querci", 40},
        {20, "Fulano de tal", 50},
        {21, "Ciclano de tal", 80},
        {41, "FULANINHO", 40}
    };
    
    Pessoa e[] = {
        {10, "Leonardo Querci", 40},
        {20, "Fulano de tal", 50},
        {21, "Ciclano de tal", 80},
        {41, "FULANINHO", 40},
        {24,"Qual um",75}
    };
    
    int tamanho = sizeof(p)/sizeof(p[0]);
    int tamanhoImpar=sizeof(e)/sizeof(e[0]);
    
	printf("-------------------VETOR PAR-------------------\n");
	//verificando como está a ordem do vetor
	mostrarVetor(p,tamanho);
	
	//invertendo o vetor
	inverterCampos(p,0,tamanho-1);
	
	//mostrando o vetor após a inversão
	mostrarVetor(p,tamanho);
	
	printf("\n\n-------------------VETOR IMPAR-------------------\n");
	//verificando como está a ordem do vetor
	mostrarVetor(e,tamanhoImpar);
	
	//invertendo o vetor
	inverterCampos(e,0,tamanhoImpar-1);
	
	//mostrando o vetor após a inversão
	mostrarVetor(e,tamanhoImpar);
	
}

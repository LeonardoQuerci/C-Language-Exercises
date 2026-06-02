#include <stdio.h>

typedef struct Pessoa{
	char cpf[20];
	char nome[20];
	int idade;
	float salario;
}Pessoa;


int main(){
	Pessoa p1 = {"1111111","Mario", 40, 50000.00};
	
	//Criando um arquivo de textos normalmente
	FILE * arquiText = fopen("./PessoasEstrut.txt", "w");
	fprintf(arquiText,"%20s %30s %4d R$ %8.2f\n",p1.cpf,p1.nome,p1.idade,p1.salario);
	fclose(arquiText);
	
	//criando arquivo binário
	FILE * arquiBin = fopen("./PessoasBinar.dat", "wb");
	fwrite(&p1,sizeof(Pessoa),1,arquiBin);
	fclose(arquiBin);
	return 0;
}


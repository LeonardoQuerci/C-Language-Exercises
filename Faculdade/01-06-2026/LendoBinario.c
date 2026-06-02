#include <stdio.h>

typedef struct Pessoa{
	char cpf[20];
	char nome[20];
	int idade;
	float salario;
}Pessoa;

void mostra(Pessoa p){
	printf("\n%20s %30s %4d R$%8.2f\n",p.cpf,p.nome,p.idade,p.salario);
}

int main(){
	Pessoa p1;
	
	//criando arquivo binário
	FILE * arquiBin = fopen("./PessoasBinar.dat", "rb");
	//rewind();
	//ftell();
	fread(&p1,sizeof(Pessoa),1,arquiBin);
	
	fclose(arquiBin);
	
	
	mostra(p1);
	printf("\n%s",p1.cpf);

	return 0;
}


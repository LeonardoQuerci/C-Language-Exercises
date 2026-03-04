/*
//Falamos sobre typedef e struct
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct{
	char nome [30];
	int idade;
	float salario;
}Pessoa;
void criaPessoa(Pessoa *p){
	printf("Digite o seu nome--->");
	scanf("%[^\n]",p->nome);
	printf("Digite a sua idade--->");
	scanf("%d",&p->idade);
	printf("Digite o seu salario--->");
	scanf("%f",&p->salario);
}
void apresentaPessoa (Pessoa p){
	printf("\n-----Apresentação da pessoa-----\n");
	printf("Nome: %s\n",p.nome);
	printf("Idade: %d\n",p.idade);
	printf("Salario: %.2f\n",p.salario);
	printf("-----Fim da apresentação-----\n");
}
void dobrarSalario(Pessoa *p){
	//mudando o salario
	p->salario*=2;
	printf("\n\n-------Função dobrar salário-------\n");
	printf("Mudando o salario de %s para ---> R$%.2f",p->nome,p->salario);
	printf("\n--------------------------------------\n");
}
void main(){
	setlocale(LC_ALL, "Portuguese");
	Pessoa p;
	criaPessoa(&p);
	apresentaPessoa(p);
	dobrarSalario(&p);
}
*/
//----------------------------------------------------------------------------------------
/*
//falaremos agora sobre recursividade
#include <stdio.h>
long long fatorial(int x){
	if (x<1){
		return 1;
	}else{
		return (long long)x*fatorial(x-1);
	}
}

void main(){
	int x;
	
	printf("Tamanho do tipo int: %zu bytes\n", sizeof(int));
	printf("Tamanho da variavel x: %zu bytes\n", sizeof(x));
	printf("Tamanho do tipo LONG LONG: %zu bytes\n", sizeof(long long));
	printf("Tamanho do tipo LONG: %zu bytes\n", sizeof(long));
	
	printf("Digite um numero para saber o seu fatorial--->");
	scanf("%d",&x);
	printf("O fatorial de x e -->%lld\n",fatorial(x));
		
	printf("Tamanho do retorno da funcao fatorial: %zu bytes\n", sizeof(fatorial(x)));
}*/
//---------------------------------------------------------------------------------------
/*
#include <stdio.h>
#include <string.h>

void mostra1(char *s){
	int tamanho= strlen(s);
	int i;
	printf("\n%s tem %d letras",s,tamanho);
	for (i=0;i<tamanho;i++){
		printf("\n%c",s[i]);
	}
}
void mostra2(char *s){
	if(s[0]!='\0'){
		printf("\n%c",s[0]);
		mostra2(s+1);
	} 
}

void main(){
	char nome[]="Sabado";
	mostra1(nome);
	printf("\n--------------------\n");
	mostra2(nome);
}
*/
//------------------------------------------------------------------------------------------
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

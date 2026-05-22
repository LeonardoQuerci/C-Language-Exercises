/*
Pilha — Verificador de parênteses
Dado uma string com parênteses, colchetes e chaves, verifique se ela está balanceada. Uma string é balanceada quando todo ( fecha com ), todo [ fecha com ], e na ordem correta.

"({[]})" ? válido
"({[})" ? inválido
"(((" ? inválido

Dica: Toda vez que abre um símbolo, empilha. Quando fecha, desempilha e verifica se combina.
*/

#include <stdio.h>
#define MAX 7
typedef struct{
	char v[MAX];
	int topo;
}Pilha;

void init(Pilha *p){
	p->topo = -1; //Pilha vazia
}

int pilhaVazia(Pilha p){
	return (p.topo==-1);
}

int pilhaCheia(Pilha p){
	return (p.topo == MAX-1);
}

int empilhar(Pilha *p, char c){
	if(pilhaCheia(*p))return -1;
	else{
		p->topo++;
		p->v[p->topo]=c;
		return 0;
	}
}

char desempilhar(Pilha *p){
	if(pilhaVazia(*p))return '\0';
	else{
		char comp = p->v[p->topo];
		p->topo--;
		return comp;
	}
}

int main(){
	Pilha p;
	init(&p);
	char string[7] = "([{}])";
	int valido = 1; //1 true 0 false
	int i=0;
	for (i=0;string[i]!='\0';i++){
		char atual = string[i];
		if (atual=='(' || atual=='[' || atual=='{'){
			if(empilhar(&p, atual) == -1){
				printf("Estouro de memoria\n");
				valido =0;
				break;
			}
		}
		
		else if (atual==')' || atual==']' || atual=='}'){
			char topo = desempilhar(&p);
			if((atual== ')' && topo != '(') ||
			   (atual== ']' && topo != '[') ||
			   (atual== '}' && topo != '{')){
				valido = 0;
				break;
			}
		}
	}
	if(!pilhaVazia(p))valido = 0;
	
	if (valido) {
        printf("A string \"%s\" eh VALIDA!\n", string);
    } else {
        printf("A string \"%s\" eh INVALIDA!\n", string);
    }
	return 0;
}


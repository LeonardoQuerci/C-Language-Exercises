#include <stdio.h>
#define MAX 5

typedef struct {
	char cpf[20]; 
}Livro;

typedef struct{
	Livro v[MAX];
	int topo; //-1 está fazia
}Pilha;

void init(Pilha *p){
	p->topo = -1;
}

int filaVazia(Pilha p){
	if(p.topo == -1){
		return 1;
	}else{
		return 0;
	}
}

int filaCheia(Pilha p){
	if(p.topo == MAX-1){
		return 1;
	}else{
		return 0;
	}
}

void push(Pilha *p, Livro l){
	if (filaCheia(*p)){
		printf("A PILHA ESTA CHEIA\n");
	}else{
		p->topo+=1;
		p->v[p->topo] = l;
	}
}

void pop(Pilha *p, Livro *l){
	if(filaVazia(*p)){
		printf("A PILHA JA ESTA VAZIA\n");
	}else{
		*l = p->v[p->topo];
		p->topo-=1;
		printf("Livro removido\n");
	}
}

void mostrarPilha(Pilha p){
    int i;
    printf("\n\n*****************************************************************\n");

    for (i = 0; i <= p.topo; i++){
        if(i == 0){
            printf("%-25s ---> %s\n","FUNDO DA PILHA", p.v[i].cpf);
        }else if(i == p.topo){
            printf("%-25s ---> %s\n","TOPO DA PILHA", p.v[i].cpf);
        }else{
            printf("%-25s ---> %s\n","ITEM", p.v[i].cpf);
        }
    }

    printf("*****************************************************************\n\n");
}

int main(){
	Pilha biblioteca;
	init(&biblioteca);
	Livro p;
	strcpy(p.cpf,"001");
	push(&biblioteca,p);
	
	strcpy(p.cpf,"002");
	push(&biblioteca,p);
	
	strcpy(p.cpf,"003");
	push(&biblioteca,p);
	
	strcpy(p.cpf,"004");
	push(&biblioteca,p);
	mostrarPilha(biblioteca);
	pop(&biblioteca,&p);
	printf("\n\nLivro retirado == %s",p.cpf);
	mostrarPilha(biblioteca);
	
	
	
	return 0;
}

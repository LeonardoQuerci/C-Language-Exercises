#include <stdio.h>
#define MAX 55
char cartas[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char naipes[] = {'c','d','h','s'};

//Criando a estrutura de filas que será utilizada no jogo WAR
typedef struct{
	int mao[MAX];
	int inicio;
	int final;
}Fila;

void init(Fila *f){
	f->inicio = 0;
	f->final = 0;
}

int filaCheia(Fila f){
	return ((f.final + 1) % MAX == f.inicio);
}

int filaVazia(Fila f){
	return (f.inicio == f.final);
}

void inserir(Fila *f, int carta){
	if(filaCheia(*f))printf("A fila esta cheia");
	else{
		f->mao[f->final] = carta;
		f->final = (f->final+1)%MAX;
	}
}

int retirar(Fila *f){
	int carta;
	if(filaVazia(*f))printf("A fila esta Vazia");
	else{
		carta = f->mao[f->inicio];
		f->inicio = (f->inicio+1)%MAX;
	}
	return carta;
}

//converter a carta do jogador para um numero
int rankCard(char *carta){	
	int i, indiceValor = 0, indiceNaipe = 0;
	for (i=0;i<13;i++){
		if(cartas[i] == carta[0])indiceValor = i;
	}
	for(i=0;i<4;i++){
		if(naipes[i] == carta[1])indiceNaipe = i;
	}
	return (indiceValor*4) + indiceNaipe;
}

//tornando o numero na carta do jogador
char value(int rankCard){
	int valor = rankCard / 4;
	return cartas[valor];
}
char naipe(int rankCard){
	int valor = rankCard % 4;
	return naipes[valor];
}

void transferir(Fila *origem, Fila *destino){
	while(!filaVazia(*origem)){
        inserir(destino, retirar(origem));
    }
}

void war(Fila *jogador1, Fila *jogador2){
	int contador = 0 ;
	int inWar = 0; // 0 sem Guerra 1 com Guerra
	Fila aux;
	init(&aux);
	while(!filaVazia(*jogador1)&& !filaVazia(*jogador2)){
		contador++;
		int carta1 = retirar(jogador1);
		int carta2 = retirar(jogador2);
		inserir(&aux,carta1);
		inserir(&aux,carta2);
		if(inWar == 1){	
			inWar = 0;
		}else{
			if (value(carta1)>value(carta2)){
				transferir(&aux,jogador1);
			}else if(value(carta1)<value(carta2)){
				transferir(&aux,jogador2);
			}else{
				inWar = 1;
			}
		}
	}
	if(!filaVazia(*jogador1))
        printf("Jogador 1 venceu em %d passos\n", contador);
    else if(!filaVazia(*jogador2))
        printf("Jogador 2 venceu em %d passos\n", contador);
}


int main(){
    Fila jogador1, jogador2;
    char carta[2];
    char c;
    int i;

    init(&jogador1);
    init(&jogador2);

    // Le cartas do jogador 1
    while((c = getchar()) != '\n'){
        if(c == EOF) return 0;
        if(c != ' '){
            carta[0] = c;
            carta[1] = getchar();
            inserir(&jogador1, rankCard(carta));
        }
    }

    // Le cartas do jogador 2
    while((c = getchar()) != '\n' && c != EOF){
        if(c != ' '){
            carta[0] = c;
            carta[1] = getchar();
            inserir(&jogador2, rankCard(carta));
        }
    }

    war(&jogador1, &jogador2);

    return 0;
}


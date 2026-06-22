#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
	int rank;
	int valores[5];
}ResultadoMao;

int obterPeso (char c){
	if(c>='2' && c<='9')return c-'0';
	if(c=='T')return 10;
	if(c=='J')return 11;
	if(c=='Q')return 12;
	if(c=='K')return 13;
	if(c=='A')return 14;
	return 0;
}

void ordenar(char a[5][3]){
	int i,j;
	for (i=0;i<5-1;i++){
		for(j=0;j<5-1-i;j++){
			int peso1 = obterPeso(a[j][0]);
			int peso2 = obterPeso(a[j+1][0]);
			
			if(peso1>peso2){
				//trocar
				char aux[3];
				strcpy(aux,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],aux);
			}
		}
	}
}

int ehFlush(char a[5][3]){
	int i,j;
	for(i=0;i<5-1;i++){
		if(a[i][1] != a[i+1][1])return 0;
	}
	return 1;
}

int ehStraight(char a[5][3]){
	int i;
	for (i=0;i<5-1;i++){
		int peso1 = obterPeso(a[i][0]);
		int peso2 = obterPeso(a[i+1][0]);
		if(peso2!=peso1+1)return 0;
	}
	return 1;
}

// Rank 8: Straight Flush
int checarRank8(char a[5][3], int p[5], ResultadoMao *res) {
    if (ehStraight(a) && ehFlush(a)) {
        res->rank = 8;
        res->valores[0] = p[4]; // Maior carta define o desempate
        return 1;
    }
    return 0;
}

// Rank 7: Four of a Kind (Quadra)
int checarRank7(int p[5], ResultadoMao *res) {
    if (p[0] == p[3]) { // [X, X, X, X, Y]
        res->rank = 7;
        res->valores[0] = p[0]; res->valores[1] = p[4];
        return 1;
    }
    if (p[1] == p[4]) { // [Y, X, X, X, X]
        res->rank = 7;
        res->valores[0] = p[1]; res->valores[1] = p[0];
        return 1;
    }
    return 0;
}

// Rank 6: Full House (Trinca + Par)
int checarRank6(int p[5], ResultadoMao *res) {
    if (p[0] == p[2] && p[3] == p[4]) { // [T, T, T, P, P]
        res->rank = 6;
        res->valores[0] = p[0]; res->valores[1] = p[3];
        return 1;
    }
    if (p[0] == p[1] && p[2] == p[4]) { // [P, P, T, T, T]
        res->rank = 6;
        res->valores[0] = p[2]; res->valores[1] = p[0];
        return 1;
    }
    return 0;
}

// Rank 5: Flush
int checarRank5(char a[5][3], int p[5], ResultadoMao *res) {
    if (ehFlush(a)) {
        res->rank = 5;
        // Desempate: compara todas as cartas da maior para a menor
        res->valores[0] = p[4]; res->valores[1] = p[3]; res->valores[2] = p[2]; res->valores[3] = p[1]; res->valores[4] = p[0];
        return 1;
    }
    return 0;
}

// Rank 4: Straight (Sequência)
int checarRank4(char a[5][3], int p[5], ResultadoMao *res) {
    if (ehStraight(a)) {
        res->rank = 4;
        res->valores[0] = p[4]; // Maior carta define
        return 1;
    }
    return 0;
}

// Rank 3: Three of a Kind (Trinca)
int checarRank3(int p[5], ResultadoMao *res) {
    if (p[0] == p[2]) { // [T, T, T, X, Y]
        res->rank = 3;
        res->valores[0] = p[0]; res->valores[1] = p[4]; res->valores[2] = p[3];
        return 1;
    }
    if (p[1] == p[3]) { // [X, T, T, T, Y]
        res->rank = 3;
        res->valores[0] = p[1]; res->valores[1] = p[4]; res->valores[2] = p[0];
        return 1;
    }
    if (p[2] == p[4]) { // [X, Y, T, T, T]
        res->rank = 3;
        res->valores[0] = p[2]; res->valores[1] = p[1]; res->valores[2] = p[0];
        return 1;
    }
    return 0;
}

// Rank 2: Two Pairs (Dois Pares)
int checarRank2(int p[5], ResultadoMao *res) {
    if (p[0] == p[1] && p[2] == p[3]) { // [P1, P1, P2, P2, K]
        res->rank = 2;
        res->valores[0] = p[2]; res->valores[1] = p[0]; res->valores[2] = p[4]; // p[2] é o maior par
        return 1;
    }
    if (p[0] == p[1] && p[3] == p[4]) { // [P1, P1, K, P2, P2]
        res->rank = 2;
        res->valores[0] = p[3]; res->valores[1] = p[0]; res->valores[2] = p[2];
        return 1;
    }
    if (p[1] == p[2] && p[3] == p[4]) { // [K, P1, P1, P2, P2]
        res->rank = 2;
        res->valores[0] = p[3]; res->valores[1] = p[1]; res->valores[2] = p[0];
        return 1;
    }
    return 0;
}

// Rank 1: Pair (Um Par)
int checarRank1(int p[5], ResultadoMao *res) {
    if (p[0] == p[1]) { // [P, P, K1, K2, K3]
        res->rank = 1; res->valores[0] = p[0];
        res->valores[1] = p[4]; res->valores[2] = p[3]; res->valores[3] = p[2];
        return 1;
    }
    if (p[1] == p[2]) { // [K1, P, P, K2, K3]
        res->rank = 1; res->valores[0] = p[1];
        res->valores[1] = p[4]; res->valores[2] = p[3]; res->valores[3] = p[0];
        return 1;
    }
    if (p[2] == p[3]) { // [K1, K2, P, P, K3]
        res->rank = 1; res->valores[0] = p[2];
        res->valores[1] = p[4]; res->valores[2] = p[1]; res->valores[3] = p[0];
        return 1;
    }
    if (p[3] == p[4]) { // [K1, K2, K3, P, P]
        res->rank = 1; res->valores[0] = p[3];
        res->valores[1] = p[2]; res->valores[2] = p[1]; res->valores[3] = p[0];
        return 1;
    }
    return 0;
}

// Rank 0: High Card (Carta Alta)
void checarRank0(int p[5], ResultadoMao *res) {
    res->rank = 0;
    res->valores[0] = p[4]; res->valores[1] = p[3]; res->valores[2] = p[2]; res->valores[3] = p[1]; res->valores[4] = p[0];
}
ResultadoMao avaliarMao(char a[5][3]) {
    ResultadoMao res;
    memset(&res, 0, sizeof(res));
	int i;
    int p[5];
    for (i = 0; i < 5; i++)
        p[i] = obterPeso(a[i][0]);

    if (checarRank8(a, p, &res)) return res;
    if (checarRank7(p, &res))    return res;
    if (checarRank6(p, &res))    return res;
    if (checarRank5(a, p, &res)) return res;
    if (checarRank4(a, p, &res)) return res;
    if (checarRank3(p, &res))    return res;
    if (checarRank2(p, &res))    return res;
    if (checarRank1(p, &res))    return res;
    checarRank0(p, &res);
    return res;
}

int compararMaos(ResultadoMao *b, ResultadoMao *w) {
    if (b->rank != w->rank)
        return b->rank - w->rank;
	int i;
    for (i = 0; i < 5; i++) {
        if (b->valores[i] != w->valores[i])
            return b->valores[i] - w->valores[i];
    }
    return 0;
}

int main(){
	
	char black[5][3];
	char white[5][3];
	while (scanf("%s %s %s %s %s %s %s %s %s %s", 
    black[0], black[1], black[2], black[3], black[4], 
    white[0], white[1], white[2], white[3], white[4]) != EOF){
    	ordenar(black);
		ordenar(white);
		
		ResultadoMao resBlack = avaliarMao(black);
		ResultadoMao resWhite = avaliarMao(white);
		int cmp = compararMaos(&resBlack, &resWhite);
		if (cmp > 0)
		    printf("Black wins.\n");
		else if (cmp < 0)
		    printf("White wins.\n");
		else
		    printf("Tie.\n");        	
    }

	return 0;
}


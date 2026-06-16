#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Mapeamento dos 7 segmentos para os dígitos de '0' a '9'
// Ordem: topo, sup_esq, sup_dir, meio, inf_esq, inf_dir, base
const bool digits[10][7] = {
    {true,  true,  true,  false, true,  true,  true},  // 0
    {false, false, true,  false, false, true,  false}, // 1
    {true,  false, true,  true,  true,  false, true},  // 2
    {true,  false, true,  true,  false, true,  true},  // 3
    {false, true,  true,  true,  false, true,  false}, // 4
    {true,  true,  false, true,  false, true,  true},  // 5
    {true,  true,  false, true,  true,  true,  true},  // 6
    {true,  false, true,  false, false, true,  false}, // 7
    {true,  true,  true,  true,  true,  true,  true},  // 8
    {true,  true,  true,  true,  false, true,  true}   // 9
};

void print_horizontal(char *str, int len, int s, int segmento){
	int i,j;
	for (i=0; i < len;i++){
		int d = str[i] - '0';
		bool active = digits[d][segmento];
		
		printf(" ");
		for(j=0;j<s;j++){
			printf("%c", active ? '-': ' ');
		}
		printf(" ");
		
		if(i<len-1){
			printf(" ");
		}
	}
	printf("\n");
}

void print_vertical(char *str, int len, int s, int segmentoEsq, int segmentoDir){
	int r,i,j;
	for (r=0;r<s;r++){
		for(i = 0;i<len;i++){
			int d = str[i] - '0';
			bool activeLeft = digits[d][segmentoEsq];
			bool activeRight = digits[d][segmentoDir];
			
			printf("%c", activeLeft ? '|' : ' ');
            for (j = 0; j < s; j++) {
                printf(" ");
            }
            printf("%c", activeRight ? '|' : ' ');
            if(i<len-1)printf(" ");
		}
		printf("\n");
	}
}

int main(){
	int s;
    char n_str[10];

    // Loop de leitura até encontrar "0 0"
    while (scanf("%d %s", &s, n_str) == 2) {
        if (s == 0 && strcmp(n_str, "0") == 0) {
            break;
        }

        int len = strlen(n_str);

        // 1. Renderiza a linha do TOPO (segmento índice 0)
        print_horizontal(n_str, len, s, 0);

        // 2. Renderiza as linhas SUPERIORES (segmentos 1 e 2)
        print_vertical(n_str, len, s, 1, 2);

        // 3. Renderiza a linha do MEIO (segmento índice 3)
        print_horizontal(n_str, len, s, 3);

        // 4. Renderiza as linhas INFERIORES (segmentos 4 e 5)
        print_vertical(n_str, len, s, 4, 5);

        // 5. Renderiza a linha da BASE (segmento índice 6)
        print_horizontal(n_str, len, s, 6);

        // Linha em branco exigida após cada número completo
        printf("\n");
    }

    return 0;

	return 0;
}


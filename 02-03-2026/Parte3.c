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

//------------------------------------------------------------------------------------------

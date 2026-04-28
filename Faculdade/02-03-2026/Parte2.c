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

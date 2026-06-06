#include <stdio.h>
#include <stdbool.h>

//Descobrir o cycle lenght de x
int cycleLenght(int x){
	int cicleX = 0;
	
	while (true) {
    	cicleX++; 
    
    	if (x == 1) {
        	break;
    	} else {
        	if (x % 2 == 0) x /= 2;
			else x = (x * 3) + 1; 
    	}
	}
	return cicleX;
}

int main(){
	int x,y,i, biggerCicle = 0;
	//input 
	if(scanf("%d %d", &x, &y)!=2)return 0;
	
	//verificando se o primeiro é menor que o segundo
	if (x>y){
		int aux = x;
		x=y;
		y=aux;
	}
	
	//loop para percorrer todos os numeros entre eles
	for(i=x;i<=y;i++){
		int z = cycleLenght(i);
		if (z>biggerCicle){
			biggerCicle = z;
		}
	}
	
	//output	
	printf("%d %d %d\n",x,y,biggerCicle);
	
	return 0;
}


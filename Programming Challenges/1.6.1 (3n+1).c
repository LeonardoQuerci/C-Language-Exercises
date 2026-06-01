/*

*/
#include <stdio.h>
#include <stdbool.h>


int main(){
	int x,y;
	//input 
	if(scanf("%d %d", &x, &y)!=2)return 0;
	
	int cicleX = 0, nX = x;
	int cicleY = 0, nY = y;
	
	//Descobrir o cycle lenght de x
	while (true) {
    	cicleX++; 
    
    	if (nX == 1) {
        	break;
    	} else {
        	if (nX % 2 == 0) nX /= 2;
			else nX = (nX * 3) + 1; 
    	}
	}
	
	//Descobrir o cycle lenght de y
	while (true) {
    	cicleY++;
    
    	if (nY == 1) {
        	break; 
    	}else {
        	if (nY % 2 == 0)nY /= 2;
			else nY = (nY * 3) + 1; 
    	}
	}
	
	int cicleT = cicleX + cicleY;
	printf("%d %d %d\n",x,y,cicleT);
	
	return 0;
}


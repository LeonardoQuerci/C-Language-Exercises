#include <stdio.h>

//m = Coluna N = LINHA

//se resposta for I
char** I(int m, int n){
	char** image = (char**)malloc(m*sizeof(char*));
	int i,j;
	for (i=0;i<m;i++){
		image[i] = (char*)malloc(n*sizeof(char));
		for(j=0;j<n;j++){
			image[i][j] = '0';
		}
	}
	return image;
}
//resposta C
char** C(char ** image){
	int i,j;
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			image[i][j] = '0';
		}
	}
	return image;
}
//resposta L
char** L(char ** image, int x, int Y, char a){
	image[y][x] =  a;
	return image;
}
//resposta V
char** V(char ** image, int coluna, int y1, int y2, char c){
	int i;
	
	for(i=y1;i<=y2;i++){
		image[i][coluna] = c;
	}
	return image;
}

//resposta H
char** V(char ** image, int x1, int x2, int linha, char c){
	int i;
	
	for(i=x1;i<=x2;i++){
		image[linha][i] = c;
	}
	return image;
}

//resposta K NAO FIZ AINDA 
/*char** V(char ** image, int x1, int x2, int linha, char c){
	int i;
	
	for(i=x1;i<=x2;i++){
		image[linha][i] = c;
	}
	return image;
}*/

//reposra F 




int main(){

	return 0;
}


#include <stdio.h>

int main(){
	int x, y, i, j;
	while(scanf("%d %d",&x, &y)==2 && (x!=0 || y!=0)){
		char matrizOriginal[x][y];
		
		//lendo a matrizOriginal
		for (i=0;i<x;i++){
			for (j=0;j<y;j++){
				scanf(" %c",&matrizOriginal[i][j]);
			}
		}
		char mineSweeper[x][y];
		
		//criando a matriz MineSweeper
		for (i=0;i<x;i++){
			for (j=0;j<y;j++){
				if (matrizOriginal[i][j] == '*')mineSweeper[i][j] = '*';
				else{
					int minas = 0;
					int dx[8] = {-1,-1,-1,0,0,1,1,1};
					int dy[8] = {-1,0,1,-1,1,-1,0,1};
					int k;
					for (k = 0; k < 8; k++){
					    int ni = i + dx[k];
					    int nj = j + dy[k];
					    if (ni >= 0 && ni < x && nj >= 0 && nj < y){
					        if (matrizOriginal[ni][nj] == '*'){
					            minas++;
					        }
					    }
					}
					mineSweeper[i][j] = '0' + minas;
				}
			}
		}
		//output
		for (i = 0;i<x;i++){
			for (j = 0; j < y; j++) {
	            if (j > 0) printf(" ");
	            printf("%c", mineSweeper[i][j]);
	        }
	        printf("\n");
		}	
	}
	
	

	return 0;
}


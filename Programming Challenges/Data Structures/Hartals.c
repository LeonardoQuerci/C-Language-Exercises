#include <stdio.h>
#include <stdbool.h>

void resolver(){
	int n,p,i, dia;
	scanf("%d",&n);
	scanf("%d",&p);
	
	int h[p];
	//lendo o parametro de cada partido
	for(i = 0;i<p;i++){
		scanf("%d",&h[i]);
	}
	//
	int diasGreve = 0;
	for(dia=1;dia<=n;dia++){
		if(dia % 7 == 6 || dia % 7 == 0)continue;
		
		bool teveGreve = false;
		for(i=0;i<p;i++){
			if(dia%h[i] == 0){
				teveGreve = true;
				break; //apenas um partido basta
			}
		}
		if(teveGreve)diasGreve++;
	}
	printf("\n************************************\n");
	printf("Resultado do caso ---->%d",diasGreve);
	printf("\n************************************\n");	
}

int main(){
	
	int casos;
	if (scanf("%d",&casos) == 1){
		while(casos--){
			resolver();
		}
	}
	return 0;
}


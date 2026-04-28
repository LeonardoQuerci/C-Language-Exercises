#include <stdio.h>
#include <string.h>

typedef char codigo[20];

typedef struct {
	codigo ismn;
	char titulo[30];
	char interprete[30];
	int ano;
}Musica;

void troca(Musica m[], int a, int b){
	Musica auxiliar = m[a];
	m[a]=m[b];
	m[b]=auxiliar;
}

void divide ( Musica n[ ], int start, int end, int *newfirst, int *newlast ) {
	codigo ref;
	int meio, begin1, final1 ;
	meio = ( start + end ) / 2 ;
	strcpy(ref, n[meio].ismn);
	begin1 = start ;
	final1 = end ;
	while ( begin1 < final1 ) {
		while (strcmp(n[begin1].ismn, ref) < 0) begin1++ ;
		while (strcmp(n[final1].ismn, ref) > 0) final1-- ;
		if ( begin1 <= final1 ) {
			troca(n, begin1, final1) ;
			begin1++ ;
			final1-- ;
		}
	}
	*newfirst = begin1 ;
	*newlast = final1 ;
}

void quick ( Musica n[ ], int primeiro, int ultimo ) {
	int newf, newl ;
	if ( primeiro < ultimo ) {
		divide(n, primeiro, ultimo, &newf, &newl ) ;
		quick(n, primeiro, newl ) ;
		quick(n, newf, ultimo ) ;	
	}
}

void mostra(Musica song[], int quantas){
	int i=0;
	while (i<quantas){
		printf("\nISMN = %s, ",song[i].ismn);
		printf("Titulo = %20s, ",song[i].titulo);
		printf("Interprete = %20s \t%d",song[i].interprete,song[i].ano);
		i++;
	}
}

int main(){
	Musica acervo[]={
		{"678","Sexta musica", "Sexta interprete",1574},
		{"123","Encontre aqui", "Drops",1977},
		{"567","Quinta musica", "Quinto interprete",1967},
		{"234","So tu es santo", "Morada",1990},
		{"789","Sétima musica", "Sétimo interprete",1777},
		{"345"," Eu te amo", "central 3",1970},
		{"456","Quarta musica", "Quarto interprete",1888},
		{"890","Oitava musica", "Oitava interprete",1477},
	};
	int tamanho=sizeof(acervo)/sizeof(acervo[0]);
	printf("---------ACERVO ORIGINAL---------\n");
	mostra(acervo,tamanho);
	quick(acervo,0,tamanho-1);
	printf("\n\n---------ACERVO ORDENADO PELO QUICK SORT---------\n");
	mostra(acervo,tamanho);
	return 0;
}

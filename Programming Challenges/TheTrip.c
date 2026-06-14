#include <stdio.h>

int main(){
	int n;
	while (scanf("%d",&n)==1 && n!=0){
		int i =0;
		int matrix[n];
		int somaTotal=0;
		
		for (i = 0; i < n; i++){
			double aux;
			scanf("%lf",&aux);
			matrix[i] = (int)(aux * 100.00 + 0.5);
			somaTotal+=matrix[i];
		}
	 	int media = somaTotal / n;
	 	int centavosSobrando = somaTotal%n;
	 	
		double totalPagar=0;
		for(i = 0; i < n; i++){
			if(matrix[i]<media){
				totalPagar+=media - matrix[i];
			}
		}
		// Se a quantidade de pessoas que pagaram ACIMA da média alta for menor 
        // que os centavos que sobraram, precisamos ajustar a diferença.
        // Uma forma robusta para esse problema é calcular o que falta e o que sobra,
        // mas para o problema "The Trip", a lógica abaixo cobre a troca mínima:
        
        int totalReceber = 0;
        for (i = 0; i < n; i++) {
            if (matrix[i] > media) {
                totalReceber += (matrix[i] - media);
            }
        }
        // Os centavos que sobraram mitigam parte do que precisa ser transferido
        totalReceber -= centavosSobrando;
        
        // A resposta final ideal é o maior valor entre o que deve ser pago e recebido
        double resultadoFinal = (totalPagar > totalReceber) ? totalPagar : totalReceber;
        
        // Divide por 100.0 para voltar a exibir em formato de dólares/reais
        printf("$%.2f\n", resultadoFinal / 100.0);
	}
	
	return 0;
}


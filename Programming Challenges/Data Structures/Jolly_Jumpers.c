#include <stdio.h>
#include <stdbool.h>

int main(){	
	int n;
	
	while(scanf("%d",&n) == 1 && n!=0){	
		int array[n];
		int i;
		
		for(i=0;i<n;i++){
			scanf("%d",&array[i]);
		}
		//quando só tiver um número sempre será jolly
		if (n == 1) {
	        printf("Jolly\n");
	        continue;
	    }
		
		bool visto[3000] = {false};
	    bool jolly = true;
	    
		for(i=1;i<n;i++){
			int diff = abs(array[i]-array[i-1]);
			if (diff < 1 || diff >= n || visto[diff]) {
	            jolly = false;
	            break;
	        }
	        visto[diff] = true;
		} 
		
		printf(jolly ? "Jolly\n" : "Not jolly\n");
	}
	return 0;
}


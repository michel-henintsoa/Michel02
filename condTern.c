#include <stdio.h>

int main(){
	int x=4, y=1;
	for (int i=0; i<(x<y?y:x)+4; i++){
		printf("0_");
	}printf("\n");
	for (int i=0; i<(x<y?y:x)+4; i++){
		printf("0_");
	}
	for(int i=0; i<(x<y?(x>y?x:y):x); i++){
		for(int j=i; j>0; j--){
		//	printf("%d_", j);
			if(j!=1) printf(" ");
			else printf("0_*0");
		}
		printf("\n");
	}
	for(int i=(x<y?(x>y?x:y):x); i>0; i--){
		for(int j=i; j>0; j--){
		//	printf("%d_", j);
			
			if(j!=1) printf(" ");
			else printf("0_*0");
		}
		printf("\n");
	}
	for (int i=0; i<(x<y?y:x)+4; i++){
		printf("0_");
	}printf("\n");
	for (int i=0; i<(x<y?y:x)+4; i++){
		printf("0_");
	}
	return 0;
}

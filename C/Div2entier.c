#include<stdio.h>

int main() {
	int n1=1, n2=1, tst1, tst2 ;
	printf("Entrez deux nombres strictement entiers\n");
	printf(" n1=") ;
	scanf("%d",&n1);
		tst1=scanf("%d",&n1);
	printf("\n n2=");
	scanf("%d",&n2);
		tst2=scanf("%d",&n2);
	if((tst1!=1)&&(tst2!=1)){
		printf("veuillez entrer des entier");
		main();
	}
	if(n2==0){
		printf("la division par 0 est impossible\n");
	}
	else{
		int q;
		q=n1/n2;
		printf("resultat=%d\n",q);
	}
	return 0;
}

#include<stdio.h>

int main(){
	int n=0,x=1;
	printf("Entrez un nobre pour la calcul de la multiplication");
	scanf("%d",&n);
	printf("la table de multiplication par %d \n",n)
	for(int i;i<=10;i++){
		x = n*i;
	printf("%d = %d*i \n",x,n);
	}
	return 0;
}

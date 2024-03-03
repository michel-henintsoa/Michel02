#include <stdio.h>
void entrerTab(int *tab);
void afficheTab(int *tab);
int main(){
	int tab[5][5];
	entrerTab( *tab );
/*	printf("entrer des valeur pour le tableau de dimension 2 d'order 5\n");
	for(int i=0; i<5 ; i++){
		for(int j=0; j<5; j++){
			printf("tab[%d][%d]:",i, j);
			scanf("%d",&(tab[i][j]));
		}
		*/
	
	afficheTab(*tab);
/*	printf("AFFICHAGE DU TABLEAU\n");
	for(int i=0; i<5 ; i++){
		printf("\n\n");
		for(int j=0; j<5 ; j++){
			printf("[%d]\t",tab[i][j]);
		}
	}
	printf("\n");
*/
	return 0;
}
void entrerTab(int *tab){
	printf("entrer des valeur pour le tableau de dimension 2 d'order 5");
	for(int i=0; i<5 ; i++){
		for(int j=0; j<5; j++){
			printf("\n tab[%d][%d]:",i,j);
			scanf("%d",((tab+i)+j));
		}
	}

}
void afficheTab(int *tab){
	printf("********//AFFICHAGE DU TABLEAU//*********");
	for(int i=0; i<5 ; i++){
		printf("\n");
		for(int j=0; j<5 ; j++){
			printf("%d\t",*((tab+i)+j));
		}
	}
}

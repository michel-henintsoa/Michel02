#include<stdio.h>
void getArr(int *tab,int dim);
void TriTab(int *tab,int dim);
int main(){
	int tab[10],dim=10;
	getArr(tab,dim);
	afficheTab(tab,dim);
	TriTab(tab,dim)
	return 0;
}
void getArr(int *tab,int dim){
	printf("entrez une valeur pour chaque element du tableau\n");
	int i=1234;
	for(i=0; i<dim; i++){
		scanf("%d",(tab+i));
	}
}
void afficheTab(int *tab,int dim){
	for(int i=0;i<dim;i++){
		printf("tab[%d]=%d\n",i,*(tab+i));
	}
}
void TriTab(int *tab,int dim){
	int max=0;
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j=++){
			if(tab[i]<)
		}
	}
}

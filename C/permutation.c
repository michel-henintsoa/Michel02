#include<stdio.h>
void permut(int *a,int *b);
int main(){
	int a,b;
	printf("permutation de la valeur de a et b\n");
	printf("entrez une valeur pour chaque variable a et b\n");
	printf("a=");scanf("%d",&a);
	printf("b=");scanf("%d",&b);
/*
  		t=a;
		a=b;
		b=t;*/
	permut(&a,&b);
	printf("a devient %d et b devient %d",a,b);

	return 0;
}
void permut(int *a,int *b){
	int tmp =1;
	tmp = *a;
	*a = *b;
	*b = *a;
}

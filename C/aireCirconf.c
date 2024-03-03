#include<stdio.h>
#define PI 3.1415
void Affiche(double *r);
double CalcCirconf(double r);
double CalcAire(double r);
void displayResult(double a,double c ,double r);

int main(){
	printf("Calcul de l'aire et de la circoférence d'un cercle\n");
///entrée de données
	double 	r, c, a;
	Affiche(&r);
///traitement de données
	c = CalcCirconf(r);
	a = CalcAire(r);
///sortis de résultats
	displayResult(a,c,r);
	return 0;
}
void Affiche(double *r){
	printf("entrer une valeur de la rayon de cercle\t");
	scanf("%lf",r);
}
double CalcCirconf(double r){
	double c;
	c = 2 * PI * r;
	return c;
}
double CalcAire(double r){
	double a;
	a = PI * r * r;
	return a;
}
void displayResult(double a,double c, double r){
	printf("\nle cercle de rayon %lf a une circonfonférence %lf et une aire de  %lf",r,c,a);
}

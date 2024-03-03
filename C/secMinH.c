#include <stdio.h>
#include <stdlib.h>
char *allocDyn( int dim);
int dimFirst(char *date);
char *takFirst(char *date, int dimF);
int countchar(char *trans);
int wrComa(char *chr);
double puisse(double iva, double avo);
int charToNbre(char *trans);
void cut(char *chr, char *chr1, char *chr2, int indC);
double charToDec(int chr2, int count, int indC);

int main(){
	char *date = "12.53/05/23";
	char *chr = NULL;
	int dimF = 0;
	char *chr1 = NULL;
	char *chr2 = NULL;
	int ldate = countchar(date);
	int nchr2 = 0;
	double day = 0;
	
	dimF = dimFirst(date);
	chr = allocDyn(dimF+1);
	chr = takFirst(date, dimF);
	
	int indC = wrComa(chr);
	int count = countchar(chr);
	
	chr1 = allocDyn(indC + 1);
	chr2 = allocDyn(count - indC + 1);
	cut(chr, chr1, chr2, indC);
	nchr2 = charToNbre(chr2);
	printf("%s\t%s\t%s\n%d", chr, chr1, chr2, nchr2);
	day = charToDec(nchr2, count, indC);
	printf("\n%lf", day);
	return 0;
}

char *allocDyn( int dim){
	char *car=NULL;
	car = (char *)malloc(dim);
	return car;
}

char *takFirst(char *date, int dimF){
	char *tmp = NULL;
	tmp = allocDyn(dimF+1);
	for(int j=0; j< dimF; j++){
		*(tmp+j) = *(date+j);
	}
	*(tmp + dimF) = '\0'; 
	return tmp;
}
int dimFirst(char *date){
	int dimF = 0;
	for(int i=0; *(date+i)!= '/'; i++){
		dimF++;
	}
	return dimF;
}

int countchar(char *trans){
	int tmp=0;
	for(int i=0; *(trans+i)!='\0'; i++){
		tmp++;
	}
	return tmp;
}

void cut(char *chr, char *chr1, char *chr2, int indC ){
	int count = countchar(chr);
	for(int i = 0; i<indC ; i++){
		*(chr1 + i)= *(chr + i);
	}
	int i=0;
	for(int k = indC +1; k<=count; k++){
		*(chr2 + i)= *(chr + k);
		i++;
	}
}

int wrComa(char *chr){
	int tmp=0;
	for(int i=0; *(chr+i)!='.'; i++){
		tmp ++;
	}
	return tmp;
}

int charToNbre(char *trans){
	int n=0,i=0,j=0;
	for(i = countchar(trans); i>=0 && j<countchar(trans); i--, j++){
		n += (*(trans+j)-48) * puisse(10 , i-1);
	}
	return n;
}

double puisse(double iva, double avo){
	int i=0;
	double tmp=1;
	if(avo==0)
		return tmp;
	else{
		while(i<avo){
			tmp *=iva ;
			i++;
		}
		return tmp;
	}
}

double charToDec(int chr2, int count, int indC){
	double nber = 0.0;
	nber = chr2 / (puisse(10, count-indC-1));
	return nber;
}

void dayToHMS(double day, int *heure, int *minute, int *seconde){
	double daysec=0.0;
	double j=24.0, h=60.0, min=60.0;									///jour en heure(j),heure en min(h),min en sec(min)
	daysec = (day*j*h*min);
	*seconde = (int *)(daysec%min);
	*minute = (int *)(((int)(daysec/min))%h);
	*heure = (int*)()
}

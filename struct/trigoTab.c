#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	FILE *trigo;
	trigo = fopen("trigo.csv", "w+");
	if(trigo==NULL) exit(1);
	fprintf(trigo, "x/cos(x)/sin(x/tan(x)/cotan(x)\n");
	for(int i=0; i<=360; i++){
		double x=(double)(i*M_PI)/(double)180;
		fprintf(trigo, "%lf/%lf/%lf/%lf/%lf\n",x, cos(x), sin(x), tan(x), 1/tan(x));
	}
	printf("%lf", M_PI);
	fclose(trigo);
	return 0;
}

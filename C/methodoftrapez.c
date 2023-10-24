#include <stdio.h>
#include <math.h>
double f(double a);
int main(){
	double s=0.0, rect=0.0, a=2.0, b=4.0, i=a;
	while(i<=b-0.00001){
		s+=((f(i)+f(i+0.00001))/(double)2)*(0.00001);
		i+=0.00001;
	}
	i=a;
	while(i<=b){
		rect+=f(i)*(0.00001);
		i+=0.00001;
	}
	printf("%lf\n", s-rect);
	return 0;
}
double f(double a){
	//expo(2x)-1
	//return exp(2*a);
	//log(x)-1
	return log(a)-1;
}
#include <stdio.h>
#include <math.h>
double f(double a);
double bowstring(double a, double i);
double testapprox(double a, double b);
double testall(double a, double b);
int main(){
	double a=1.0, b=3.0;
	double d=testapprox(a, b), s=0.0, e=testall(a, b);
	int i=1;
	while(f(s)!=0){
		s=bowstring(d, e);
		d=s;
		i++;
	}
	printf("iterate for %d\n%lf\n", i, s);
	return 0;
}
double f(double a){
	return log(a)-1;
}
double bowstring(double a, double i){
	double m=(f(i)-f(a))/(i-a);
	double p=f(a)-m*a;
	return -p/m;
}
double testapprox(double a, double b){
	double c=(double)fabs(a-b)/2.0;
	return (f(c)*f(b)<=0)?b:a;
}
double testall(double a, double b){
	double c=(double)fabs(a-b)/2.0;
	return (f(c)*f(b)<=0)?a:b;
}
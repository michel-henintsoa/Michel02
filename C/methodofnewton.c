#include <stdio.h>
#include <math.h>
double f(double a);
//Method fo tangent(det f(x)=0) ///y = f'(a)(x-a) + f(a)///
double fp(double a);
double testapprox(double a, double b);
double testall(double a, double b);
double tg(double i, double a);
int main(){
	double a=1.0, b=3.0;
	double d=testapprox(a,b), s=0.0;
	double e=testall(a, b);
	int i=1;
	while(f(s)!=0){
		s=tg(d, e);
		d=s;
		i++;
	}
	printf("iterate for %d\n%lf\n", i, s);
	return 0;
}
double f(double a){
	//log(a)-1
	return log(a)-1;
}
double fp(double a){
	return 1.0/a;
}
double tg(double i, double a){
	return i-f(i)/fp(i);
}
double testapprox(double a, double b){
	double c=(double)fabs(a-b)/2.0;
	return (f(c)*f(b)<=0)?b:a;
}
double testall(double a, double b){
	double c=(double)fabs(a-b)/2.0;
	return (f(c)*f(b)<=0)?a:b;
}
#include <stdio.h>
#include <math.h>
double f(double a);
int main(){
    double s=0.0, d=0.0;
    double i=0.0, a=3.0, b=6.0;
    i=a;
    while(i<b){
        s+=f(i)*(0.001);
        i+=0.001;
        printf("%lf\n", s);
    }
    while

    return 0;
}
double f(double a){
    return log(a)-1;
}
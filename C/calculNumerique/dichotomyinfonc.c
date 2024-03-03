#include <stdio.h>
#include <math.h>
double dichotomy(double a, double b, double e, int *i);
double f(double a);
int main(){
    double e=0.0000000001;
    double a=1.0, b=4.0;
    int i=1;
    double c=dichotomy(a, b, e, &i);
    printf("iterate for %d\n%lf\n", i, c);
    return 0;
}
double dichotomy(double a, double b, double e, int *i){
    //log(x)-1=0
    double c=0.0;
    while(!(fabs(b-a)<e)){
        c=((a+b)/2.0);
        if(f(c)*f(b)<=0){
            a=c;
        }
        else{
            b=c;
        }
        (*i)++;
    }
    return c;
}
double f(double a){
    return log(a)-1;
    //return sin(a);
}
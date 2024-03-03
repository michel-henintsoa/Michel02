#include<stdio.h>
#include <math.h>
int testIfPrem(int n);
int main()
{
    int n;
    printf("entrez le nombre à tester\t");scanf("%d", &n);
    int m=testIfPrem(n);
    if(m==0) printf("le nombre n'est pas premier \n");
    if(m==1) printf("le nombre est premier \n");
    return 0;
}

int testIfPrem(int n){
    int tmp=(int)sqrt(n)+1;
    for(int i=2; i<tmp; i++){
        if(n%i==0) return 0;
    }
    return 1;
}
#include<stdio.h>
int facto(int n);

int main()
{
    printf("Hello world!\n");
    int n = 0, fact =0;
    printf("entrez un nomnre\n");scanf("%d", &n);
    fact = facto(n);
    printf("\nle nombre factoriel de %d est %d",n, fact);
    return 0;
}
int facto(int n){
    if(n == 0 || n == 0 ){
        printf("PAR CONVENTION");
        return 1;
    }
    if(n ==2)
        return 2;
    
    return n*facto(n-1);
}
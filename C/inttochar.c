#include<stdio.h>
#include <math.h>
int countDigit(int nbre);
char *intToChar(int nbre, int taille);

int main(){
    int nbre = 02;
    int taille = countDigit(nbre);
    char *isa = (char*)malloc(taille);
    isa = intToChar(nbre, taille);
    printf("%s", isa); 
    return 0;
}
int countDigit(int nbre){
    int tmp=0;
    for(tmp = 0; nbre>0; tmp++){
        nbre /= 10; 
    }
    return tmp;
}
char *intToChar(int nbre, int taille){
    char *nisa = (char*)malloc(taille);
    char *invisa =(char*)malloc(taille);
    if(nbre==0){
        *(nisa+1)= '0';
     //   *(nisa+2)='\0';
    }
    for(int i=0; i<taille; i++){
        *(nisa+i)=nbre%10 + 48;
        nbre /= 10;
    }
    printf("%s\n", nisa);
    int i = taille-1;
    int j = 0;
    while(i>=0){
        *(invisa+j)=*(nisa+i);
        i--;
        j++;
    }
    return invisa;
}
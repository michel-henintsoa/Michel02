#include<stdio.h>
#include <stdlib.h>
int main()
{
    int n=7;
    n++;
    char **w=NULL;
    w=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        *(w+i)=(char*)malloc(n);
    }
    char c;
    for(int i=0; i<n; i++){
        for(int j=0, c='A'; j<i; j++){
            w[i][j]=c;
            c++;
        }
    }
    for(int i=0; i<n; i++){
        printf("%s\n", w[i]);
    }
    return 0;
}
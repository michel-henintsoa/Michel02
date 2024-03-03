#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("-------------------------\n| JEU DE DEVINETTE \t|\n-------------------------\n");
    int num = 0, setnum = 0;
    srand(time(NULL));
    num = 1+((int)(100.0*rand()/(RAND_MAX+1.0)));
    for(int coup = 7; coup !=0 && num != setnum; coup--){
        printf("Entrez un nombre\n");
        scanf("%d", setnum);
            if(num < setnum) {
                puts("TROP GRAND\n");
                printf("plus que %d essai\n", coup-1);
            }
            if(num > setnum) {
                puts("TROP PETIT");
                printf("plus que %d essai", coup-1);
             //   coup--;
            } 
    }
    if(num == setnum){
        printf("GAGNER\n le nombre était %d\n",num);
    }
    else{
        printf("PERDU\n le nombre était %d\n",num);
        int choise;
        puts("tapez 1 pour rejouer et 2 pour quitter\n");
        scanf("%d", &choise);
        if(choise == 1){
            main();
        }
        if(choise == 2){
            system("exit");
        }
    }
    return 0;
}
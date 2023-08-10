#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *t;
	t=fopen("info","r+");
	if(t==NULL)exit(1);
	char c;
	while(c!=EOF){
		c=fgetc(t);
		printf("%c", c);
	}
	char nom[50];
	printf("Entrer votre nom:\t");
	scanf("%s", nom);
	sprintf(t,"\nNom: %s", nom);
	fclose(t);
	return 0;
}

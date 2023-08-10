#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *t;
	t=fopen("info","r");
	if(t==NULL)exit(1);
	char l[256];
	while(fgets(l, 255, t)!=NULL){
		printf("%s", l);
	}
	fclose(t);
	return 0;
}

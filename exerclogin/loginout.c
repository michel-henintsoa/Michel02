#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
int hexToDec(char *hex);
int toint(char c);
char *replace(char * nom);

void introhtml(char* title);
void css();

typedef struct Info{
	char id[100];
	char fname[200];
	char mail[200];
	char uname[100];
	char pw[100];
}Info;
int main(){
	char title[100];
	char* user=getenv("QUERY_STRING");

	strcpy(user, replace(user));
	strcpy(title, "Acceuil");

	introhtml(title);
	for(char *take=strtok(user, "&"), i=0; take!=NULL; take=strtok(NULL, "&"), i++){
		char *take1=strtok(take, "=");
		take1=strtok(NULL, "=");
		if(i==1){
			if(!strcmp(take1, "log")){
				
			}
		}
	}
	return 0;
}


char *replace(char * nom){
    for(int i=0; i<strlen(nom); i++){
        char spec[4];
        if(nom[i]=='%'){
            for(int j=i, k=0; j<strlen(nom); j++,k++){
                if(k<2)spec[k]=nom[j+1];
                nom[j+1]=nom[(j+3)];
            }
        }
        nom[i]=(nom[i]=='%')?hexToDec(spec):nom[i];
    }

    return nom;
}
int hexToDec(char *hex){
    int dec=0;
    for(int i=strlen(hex)-1,power=0; i>=0; i--, power+=16){
        if(hex[i]<='9' && hex[i]>='0'){
            dec+=toint(hex[i])*((i!=strlen(hex)-1)?power:power+1);
            printf("%d\n",dec);
        }
        else if(isalpha(hex[i]) && ((hex[i]<='F' && hex[i]>='A') || (hex[i]<='f' && hex[i]>='a'))){
            hex[i]=(islower(hex[i]))?toupper(hex[i]):hex[i];
            dec+=(hex[i]-'A'+10)*((i!=strlen(hex)-1)?power:1);
        }
    }
    return dec;
}
int toint(char c){
    return c-'0';
}


void introhtml(char* title){
	printf(
		"Content-Type: text/html\n\n"
		"<html>"
	);
	printf(
		"<head>"
			"<title>%s<title>",title
	);
	css();
	printf("</head>");

}
void css(){
	"<style>"

	"<style>"
}


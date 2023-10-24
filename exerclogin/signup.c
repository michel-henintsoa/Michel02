#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
//int hexToDec(char *hex);
//int toint(char c);
char *replace(char * nom);

typedef struct Infosign{
	char type[20];
	char fname[200];
	char mail[200];
	char uname[100];
	char pw[100];
	char olona[1001];
}Infosign;

Infosign writtepass(char* cgi);
//Info readpass(char* row, FILE* file);

int main(){
	char* info=getenv("QUERY_STRING");
	char row[1001];
	FILE* file=fopen("passwd.txt", "r");

	char id[200];

//	char info[]="type=sign&fullname=test&mail=michelherilalaina%40gmail.com&username=MichelCH&passwd=123456";
	Infosign user=writtepass(info);
	/*sprintf(id, "../.connect/%s", user.uname);
	sprintf(create, "touch %s", id);
	system(create);
	FILE* connect=fopen(id, "w+");fprintf(connect, "%d\n", 1);*/
//	printf("%s<br/>%s<br/>%s<br/>%s<br/>", user.fname, user.mail, user.uname, user.pw);
	printf("Set-Cookie: authenticated=true; Path=/\n");
	printf("Location: http://www.exercice-login.mit/cgi-bin/paginationauthlog.cgi?id=%s\n\n", user.uname);
//	printf("Content-Type: text/html\n\n");
//	fclose(connect);
	fclose(file);
	return 0;
}
char *replace(char * nom){
	char spec[4];
    for(int i=0; i<strlen(nom); i++){
 //       if(isalpha(nom[i] && islower(nom[i])))nom[i]=toupper(nom[i]);
        if(nom[i]=='%'){
            for(int j=i, k=0; j<strlen(nom); j++,k++){
                if(k<2)spec[k]=nom[j+1];
                nom[j+1]=nom[(j+3)];
            }
        }
        if(nom[i]=='%')nom[i]='@';
//        if(nom[i]=='%')nom[i]=hexToDec(spec);
//        printf("%d<br/>", hexToDec(spec));
    }
    return nom;
}
Infosign writtepass(char* cgi){
	FILE* pass;
	char olona[1001];
	Infosign user;

	strcpy(user.olona, "");
	pass=fopen("passwd.txt", "a+");
	if(pass==NULL) exit(0);
	sscanf(
		cgi, "type=%[^&]&fullname=%[^&]&mail=%[^&]&username=%[^&]&passwd=%[^\n]",
		user.type, user.fname, user.mail, user.uname, user.pw
	);
	char* mail=replace(user.mail);
	strtok(user.mail, mail);
	sprintf(user.olona, "%s&%s&%s&%s", user.fname, user.mail, user.uname, user.pw);
//	fprintf(pass, "%s\n", user.olona);
	fclose(pass);
	return user;
}
/*Info readpass(char* row, FILE* file){
	Info izy;
	sscanf(row, "%[^&]&%[^&]&%[^&]&%[^\n]", izy.fname, izy.mail, izy.uname, izy.pw);
	return izy;
}*/
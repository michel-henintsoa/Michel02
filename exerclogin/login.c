#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Infolog{
	char type[20];
	char uname[200];
	char pw[200];
}Infolog;
typedef struct Infosign{
	char type[20];
	char fname[200];
	char mail[200];
	char uname[100];
	char pw[100];
	char olona[1001];
}Infosign;
Infolog split(char* log);
Infosign takerow(char* row);
int logpossible(Infolog log);
int count(char* filename);

int main(){
//	char* log=getenv("QUERY_STRING");
	char* log="type=log&username=MichelCH&passwd=123456";
	Infolog user=split(log);
	int i=logpossible(user);
/*	if(logpossible(user)){
		printf("Set-Cookie: authenticated=true; Path=/\n");
		printf("Location: http://www.exercice-login.mit/cgi-bin/paginationauthlog.cgi?id=%s\n\n", user.uname);
	}
	else{
		printf("Location: http://www.exercice-login.mit/login.html\n\n");
	}*/
	printf("%d\n", i);
	return 0;
}
int logpossible(Infolog log){
	int poss=0;
	FILE* file=fopen("passwd.txt", "r");
	if(file==NULL)return 0;
	char* row=(char*)malloc(1001);
	int i=0;
	while(i<count("passwd.txt")){
		Infosign cmp=takerow(row);
		printf("BLABLABLA%s\n", row);
		if(!strcmp(cmp.uname, log.uname)){
			if(!strcmp(cmp.pw, log.pw)){
				poss=1;
				break;
			}
		}
		i++;
	}
	return poss;
}
int count(char* filename){
    int line=0;
    char c;
    FILE *f;
    f=fopen(filename, "r");
    if(f==NULL)return 0;
    c=fgetc(f);
    while(c!=EOF){c=fgetc(f);line+=(c=='\n')?1:0;}
    fclose(f);
    return line;
}
Infolog split(char* log){
	Infolog user;
	sscanf(log, "type=%[^&]&username=%[^&]&passwd=%[^\n]", user.type, user.uname, user.pw);
	printf("Content-Type: text/html\n\n");
	printf("%s|%s\n", user.uname, user.pw);
	return user;
}
Infosign takerow(char* row){
	Infosign user;
	sscanf(row, "%[^&]&%[^&]&%[^&]&%[^\n]", user.fname, user.mail, user.uname, user.pw);
	printf("%s|%s\n", user.uname, user.pw);
	return user;
}
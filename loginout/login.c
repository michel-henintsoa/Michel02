#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Login{
    char uname[200];
    char pw[100];
    char ip[30];
    char ck[50];
}Login;
typedef struct Id{
    char ulong[200];
    char mail[100];
    char uname[200];
    char pw[100];
}Id;

void displaylogin();
int takelog(char** name);
void createlog(int id, char* name);

int main(){
    
    printf("Cache-Control: no-cache, no-store, must-revalidate\n"
	    "Pragma: no-cache\n"
	    "Expires: 0\n"
    );

    char* name=(char*)malloc(200);
    int res=takelog(&name);
    char* ck=getenv("HTTP_COOKIE");
//    char* ck="chk";
    if(ck!=NULL){
        printf(
            "Status: 302 Found\n"
            "Location: http://www.site-of-login.mit/cgi-bin/paginationauthlog.cgi?id=%s&page=1\n\n"
            ,name
        );
    }
//    printf("%d\n", res);
    createlog(res, name);
    return 0;
}
void displaylogin(){
    printf("Content-Type: text/html\n\n");
    printf(
        "<html><head>"
            "<title>Login</title>"
            "<link rel=\"stylesheet\" type=\"text/css\" href=\"/style.css\">"
        "</head>"
    );
    printf(
        "<body>"
            "<div class='container-login'>"
                "<form action='http://www.site-of-login.mit/cgi-bin/login.cgi' methode='get'>"
                    "<font>User Name</font>"
                    "<br/>"
                    "<input type='text' name='uname' placeholder='User Name'/>"
                    "<br/><br/>"
                    "<font>Password</font>"
                    "<br/>"
                    "<input type='password' name='pw' placeholder='Password'/>"
                    "<br/><br/>"
                    "<button id='log'><ln>Login</ln></button>"
                    "<br/><br/>"
                "</form>"
            "<div>"
        "</body>"
        "</html>"
    );
}
int takelog(char** name){
    int test=0;
    char* login=getenv("QUERY_STRING");
//    char login[]="uname=Michel&pw=1234560";
    Login user;
    if(strcmp(login, "")==0){return 0;}
    else{
        sscanf(login, "uname=%[^&]&pw=%[^\n]", user.uname, user.pw);
        if(strcmp(user.uname, "")==0)return 0;
        
        FILE* f=fopen("pass.csv", "r");
            
        char row[1001];
        if(f==NULL){
//            printf("error");
//            printf("blabla\n");
            exit(1);
        }
        while(fgets(row, 500, f)!=NULL){
            Id one;
            sscanf(row, "%[^&]&%[^&]&%[^&]&%[^\n]", one.ulong, one.mail, one.uname, one.pw);
            if(strcmp(user.uname, one.uname)==0 && strcmp(user.pw, one.pw)==0){
                test=1;
                strcpy(*name, user.uname);
//                printf("%s&%s\n", one.uname, user.uname);
                break;
            }
        }
    }
    return test;
}
void createlog(int id, char* name){
    if(id==1){
        printf(
            "Set-Cookie: %s=%d; expires: Wed, 23 Oct 2030 00:00:00 GMT; HttpOnly\n",name, id
        );
        printf(
            "Status: 302 Found\n"
            "Location: http://www.site-of-login.mit/cgi-bin/paginationauthlog.cgi?id=%s&page=1\n\n"
            , name
        );
    }
    else{
        displaylogin();
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char* fielname);
char* split(char* object, char* sep);
typedef struct Auth{
    char time[100];
    char opcl[20];
    char user[100];
}Auth;
typedef struct Rest {
    char add[20];
    char log[50];
    char session[30];
    char fr[10];
    char us[5];
    char rest[100];
    char div[500];
}Rest;

int main(){
    FILE *f;
    int nline=count("/var/log/auth.log");
    char c[1001];
    Auth *authlog=(Auth*)malloc(nline*sizeof(Auth));
    char* cgi=getenv("QUERY_STRING");
    char *cgi1=split(cgi, "=");
    char* login=(char*)malloc(500);
    strcpy(login, cgi1);

    printf("Content-Type: text/html\n\n");
    printf("<html><head>");
    printf(
        "<title>auth.log_FILE</title>"
        "<style>"
            "table   {"
                     "padding: 1.5em;"
                     "text-align: center;"
                     "margin-left: auto;"
                     "margin-right: auto;"
                     "width: auto;"
                     "border: 2px solid black;"
                     "border-collapse: collapse;"
                     
                    "}"
            "th, td {"
                      "border: 1px solid black;"
                      "padding: 1em;"
                    "}"
    );
    printf(
            ".opened{"
                      "color: #278A24;"
                    "}"
            ".closed{"
                    "color: #B61010;"
                    "}"
            ".for-head{"
                      "border: 1px solid black;"
                      "padding: 1.25em;"
                      "font-size: 1.125em;"
                      "font-style: italic"
                    "}"
        "</style>"
    );
    printf("</head><body>");
    f=fopen("/var/log/auth.log", "r");
//    printf("%s", login);
    if(f==NULL){
        printf(
            "<h1 style=\"font-weight: bold;\">Forbidden</h1>"
            "<div style=\"font-style:oblique;\">"
                "You don't have the requered permission to access this file"
            "</div>"
        );
        exit(EXIT_FAILURE);
    }
    if(strcmp(login,"")!=0){
        printf(
            "<table>"
                "<thead style=\"background: linear-gradient(to bottom right , #DF2D2D 20%, #FF3636\">"
                    "<tr>"
                        "<td class=\"for-head\">Time</td>"
                        "<td class=\"for-head\">Opened/Closed</td>"
                        "<td class=\"for-head\">User</td>"
                    "</tr>"
                "</thead>\n"
                "<tbody>"
        );
        int i=0;
        while (fgets(c, 500, f) != NULL) {
            Rest r;
            sscanf(c, "%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^\n]",
                authlog[i].time, r.div, r.add, r.log, r.session, authlog[i].opcl, r.fr, r.us, authlog[i].user, r.rest);
            char tmp[100], tmp1[100];
            //sscanf(authlog[i].user, "%[^(](%[^)])", tmp, tmp1);
            //strcpy(authlog[i].user, tmp);
            if (!strcmp(r.session, "session")) {
                if (!strcmp(authlog[i].user, login)) {
                    printf("<tr class=\"%s\"><td>%s</td><td>%s</td><td>%s</td></tr>",
                        authlog[i].opcl, authlog[i].time, authlog[i].opcl, authlog[i].user
                    );
                }
            }
            i++;
        }
        printf("</tbody></table>");
    }
    else {
        printf(
            "<font style=\"font-size:3em; font-weight: bold;font-style: italic;\">Do you want to return to the last page?</font><br/>"
            "<a href=\"http://www.exercice-michel.mit/\"><button style=\"height: 3em; border-radius: 4px; border: none; background: #C2C3EF;\">Clic here</button></a>"
        );

    }
    printf(
        "</body></html>\n"
    );
    fclose(f);
    return 0;
}
char* split(char* object, char* sep){
    char* ret=(char*)malloc(500);
    //char ret[500];
    sscanf(object, "name=%s", ret);
    return ret;
}
int count(char* filename){
    int line=0;
    char c;
    FILE *f;
    f=fopen(filename, "r");
    if(f==NULL)return EXIT_FAILURE;
    c=fgetc(f);
    while(c!=EOF){c=fgetc(f);line+=(c=='\n')?1:0;}
    fclose(f);
    return line;
}
/*char* tostring(char* time){
    char day[2][200];
    char date[200];

    strcpy(date, strtok(time, "."));
    char*c=strtok(date,"T");
    strcpy(day[0], c);
    c=strtok(NULL, "T");
    strcpy(day[1], c);
    
    return day;
}*/
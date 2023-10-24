#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char* filename);
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
    FILE *file;
    file=fopen("/var/log/auth.log", "r");
    int nline=count("/var/log/auth.log");
    int numpage;
    char* page;
    Auth *authlog=(Auth* )malloc(sizeof(Auth) * nline);
    Rest* r=(Rest* )malloc(sizeof(Rest)*nline);
    char c[1001];
    int i=0;
    int sess=0;
    printf("Content-Type: text/html\n\n");
    printf(
        "<html><head>"
            "<title>authlog pagin</title>"
            "<style>"
                ".page{"
                    "height: 1em;"
                    "width: 1em;"
                    "border-radius: 100%;"
                    "backgdround: linear-gradient(to bottom left, #767C9E, #667BFF);"
                    "}"
            ".for-head{"
                    "border: 1px solid black;"
                    "padding: 1.25em;"
                    "font-size: 1.125em;"
                    "font-style: italic"
                    "}"
            "</style>"
        "</head>"
    );
    printf("<body>");
    printf(
        "<table>"
            "<thead style=\"background: linear-gradient(to bottom right , #BCC5FF 20%, #5367E9\">"
                "<tr>"
                    "<td class=\"for-head\">Time</td>"
                    "<td class=\"for-head\">Opened/Closed</td>"
                    "<td class=\"for-head\">User</td>"
                "</tr>"
            "</thead>\n"
            "<tbody>"
    );

    /*while (fgets(c, 500, file) != NULL) {
        sscanf(c, "%[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^ ] %[^\n]",
            authlog[i].time, r[i].div, r[i].add, r[i].log, r[i].session, authlog[i].opcl, r[i].fr, r[i].us, authlog[i].user, r[i].rest);
        char tmp[100], tmp1[100];
        sscanf(authlog[i].user, "%[^(](%[^\n]", tmp, tmp1);
        strcpy(authlog[i].user, tmp);
        if(!strcmp(r[i].session, "session\0"))sess++;
        i++;
    }*/
    i=0;
    page=getenv("QUERY_STRING");
    sscanf(page, "page=%d", &numpage);
    /*for(int i=(numpage*10), j=0; j<10, i<nline; i++){
        if(!strcmp(r[i].session, "session") && (!strcmp(authlog[i].opcl, "opened") || !strcmp(authlog[i].opcl, "closed") || !strcmp(authlog[i].opcl, "opened\0") || !strcmp(authlog[i].opcl, "closed\0"))){
            printf("<tr class=\"%s\"><td>%s</td><td>%s</td><td>%s</td></tr>",
                authlog[i].opcl, authlog[i].time, authlog[i].opcl, authlog[i].user
            );j++;
        }
    }*/

    printf(
        "</tbody></table>"
    );
    for(int i=0; i<nline%10==0?nline/10:1+nline/10; i++){
        printf(
            "<div class=\"page\">"
                "<a href=\"http://www.michel.com/cgi-bin/selectpage.cgi?page=%d\">"
                    "<i>%d|%s<i>"
                "</a>"
            "</div>", i, i+1, page
        );
    }
    printf("</body></html>");
    fclose(file);
    return 0;
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
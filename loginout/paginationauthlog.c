#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count(char* filename);
void css();
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
}Rest;
void displayPages(Auth *user, int start, int end, int page, int f, char* session);

int main(){
    printf("Cache-Control: no-cache, no-store, must-revalidate\n"
	    "Pragma: no-cache\n"
	    "Expires: 0\n"
    );
    
    char* cookie=getenv("HTTP_COOKIE");
    if(cookie==NULL){
        printf(
            "Status: 302 Found\n"
            "Location: http://www.site-of-login.mit/cgi-bin/login.cgi\n\n"
        );
    }
    else{
        char c[1001];
        int i=0;
        char *query=getenv("QUERY_STRING");
        int page=0;
        FILE* file = fopen("/var/log/auth.log" , "r");
        if(file==NULL)exit(0);
        int nline = count("/var/log/auth.log");
        int f=0;
        Auth* user = (Auth*)malloc(sizeof(Auth) * nline);
        while(fgets(c,500, file)!=NULL){
            char time[100], session[100], opcl[50], usr[100];
            for(char *t=strtok(c, " "), i=0; t!=NULL; t=strtok(NULL, " "), i++){
                if(i==0)strcpy(time, t);
                if(i==4)strcpy(session, t);
                if(i==5)strcpy(opcl, t);
                if(i==8)strcpy(usr, t);
            }
            if(!strcmp(session, "session") && !(strcmp(opcl, "opened") && strcmp(opcl, "closed"))){
                char* naka=strtok(usr, "(");
                strcpy(usr, naka);
                strcpy(user[i].time, time);
                strcpy(user[i].opcl, opcl);
                strcpy(user[i].user, usr);
                i++;
            }
        }f=i;
        fclose(file);
        char id[200];
        if(query!=NULL){
            sscanf(query, "id=%[^&]&page=%d", id, &page);
        }
        int start=(page-1)*10;
        if(start<0)start=0;
        int end=start+10;
        displayPages(user, start, end, page, f, id);
    }
//    printf("%d\n", nline);
    
    return 0;
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
void displayPages(Auth *user,int start, int end, int page, int f, char* session){
    printf("Content-Type: text/html\n\n");
    printf(
        "<head>"
            "<title>pageAuthlog</title>\n"
    );
    css();
    printf(
        "</head><body>\n"
    );
    printf(
        "<div class='textToRight'>"
            "<a href='http://www.site-of-login.mit/cgi-bin/logout.cgi?id=%s'>"
                "<button class='teboka'>Log out</button>"
            "</a>"
        "</div>"
        ,session
    );
    /* printf(
        "<div class='textToRight'>"
            "<a href='http://www.site-of-login/cgi-bin/logout.cgi'>"
                "<button class='teboka'>Log out</button>"
            "</a>"
        "</div>"
    ); */
    printf(
        "<table>\n"
            "<thead style=\"background: linear-gradient(to bottom right , #DF2D2D 20%, #FF3636\">\n"
                "<tr>"
                    "<td class=\"for-head\">Time</td>\n"
                    "<td class=\"for-head\">Opened/Closed</td>\n"
                    "<td class=\"for-head\">User</td>\n"
                "</tr>\n"
            "</thead>\n"
            "<tbody>\n"
    );
    for(int i=start; i<end && i<f; i++){
        printf(
            "<tr class=\"%s\">\n"
                "<td>%s</td>\n"
                "<td>%s</td>"
                "<td>%s</td>\n"
            "</tr>\n"
            ,user[i].opcl, user[i].time, user[i].opcl, user[i].user
        );
    }
    printf(
        "</tbody></table>\n"
    );
        if (start > 0) {
        printf("<a href='paginationauthlog.cgi?id=%s&page=%d' style='position:absolute;'><button class='teboka'>Previous</button></a>\n", session, page - 1);
    }
    
    /*for(int i=0; i<f/10; i++){
        printf(
            "<a href='paginationauthlog.cgi?page=%d"
        );
    }*/
    printf("<div class='textToRight'>");
        /*for(int i=0; i<f/10+1; i++){
            printf("<a href='paginationauthlog.cgi?page=%d><button>%d</button></a>\n", i+1, i+1);
        }*/
        if (end < f+1) {
            printf("<a href='paginationauthlog.cgi?id=%spage=%d'><button class='teboka'>Next</button></a>\n",session, page + ((page==0)?2:1));
        }
    printf("</div>");
    printf("</body></html>\n");

}

void css(){
    printf(
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
            ".textToRight{"
                    "text-align: right;"
                    "}"
            ".teboka{"
                  //  "height: 1.5em;"
                    "width: 6em;"
                    "margin-left: 3em;"
                    "margin-right: 3em;"
                    "font-style: italic;"
                    "font-size: 1em;"
                    "color: white;"
                    "border: none;"
                    "border-radius: 7px;"
                    "background: rgba(22, 7, 7, 0.77);"
                    "padding: 0.75em;"
                    "transition: 20ms;"
                    "cursor: pointer;"
                    "}"
            ".teboka:hover{"
                    "text-decoration: underline white;"
                    "}"
            ".lien{"

                "}"
        "</style>\n"
    );
}
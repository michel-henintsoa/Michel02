#include <stdio.h>
#include <stdlib.h>

int main(){
//    printf("Content-type: text/html\n");
    /* char* session=getenv("QUERY_STRING");
    char id[200];
    sscanf(session, "id=%[^\n]", id);
	printf("Set-Cookie:%s=; expires=Thu, 01 Jan 1970 00:00:00 GMT; HttpOnly\n", id); */
    printf("Set-Cookie:Michel=; expires=Thu, 01 Jan 1970 00:00:00 GMT; HttpOnly\n");
	printf("Cache-Control: no-cache, no-store, must-revalidate\n");
	printf("Pragma: no-cache\n");
	printf("Expires: 0\n");

	printf(
            "Status: 302 Found\n"
            "Location: http://www.site-of-login.mit/cgi-bin/login.cgi\n\n"
        );		
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
typedef struct User{
	char user[100];
	char rest[500];
	int uid;
}User;
int main(){
	FILE* file;
	file=fopen("/etc/passwd", "r");
	if(file==NULL)exit(1);
	char c[255];
	printf("Content-Type: text/html\n\n");
	printf("<html>");
	printf("<head><style>"
				"table {"
					"margin: 100px auto;"
					"border: 1px solid black;"
					"width: 15em;"
					"position: relative;"
				"}"
				".border_t{"
					"border: 1px solid black;"
					"text-align: center;"
					"padding: 1em;"
				"}"
				".bgimage{"
					"position: absolute;"
					
					"background-repeat: no-repeat;"
					"z-index: -1;"
					"width: 100%;"
					"height: 100%;"
				"}"
				"</style></head>"
		  );
	printf("<body>");
	printf("<table>");
	printf("<image />"

	);
	printf(	"<thead>"
				"<tr class=\"border_t\" style=\"font-style: italic;\">"
					"<th>User</th><th>Uid</th>"
				"</tr>"
			"</thead>"
			"<tbody>"
			);
	User human;
	int i=0;
    while(fgets(c, 255, file)!=NULL){
		sscanf(c,"%[^:]:x:%d:%[^\n]", human.user, &human.uid, human.rest);
		if(human.uid>999 && human.uid<60001)printf("<tr><td class=\"border_t\">%s</td><td class=\"border_t\">%d</td></tr>",human.user, human.uid);
		i++;
	}
	printf("</tbody></table></body></html>");
	fclose(file);
    return 0;
}

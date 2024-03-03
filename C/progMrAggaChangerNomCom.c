#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("Renommer une commande\n");
	char com[300], newcom[300];
//		char Pack[301];
		char package[400];
		char version0[50], version[10]="1.0";
		char name[100], mail[100], maintainer[200];
		char about[400], description[500];
		char cmdLink[700], cmdLinkCommand[800];
		char cmdPath[900], cmdNewpath[900];

		puts("entrer le nom de la commande a changer "); scanf("%s", com);
		puts("entrer le nom que vous souhater donner à la commande"); scanf("%s", newcom);
		system("mkdir -p ./newcom/DEBIAN/ ./newcom/usr/bin");
		
///**********ECRIT DANS LE FICHIER CONTROL**********///

		system("touch ./newcom/DEBIAN/control");
		sprintf(package,"echo 'Package:%s'>> ./newcom/DEBIAN/control",newcom);
//			system("echo 'Package : %s'>> ./newcom/DEBIAN/control");::
		system(package);
//		printf("%s",echo);
		sprintf(version0, "echo 'version:%s'", version);
		system(version0);
		system("echo 'Section:base'>>./newcom/DEBIAN/control");
		system("echo 'Priority:optional'>>./newcom/DEBIAN/control");
		system("echo 'Architecture:all'>>./newcom/DEBIAN/control");
		system("echo 'Depends:bash'>>./newcom/DEBIAN/control");
		puts("entrer votre prénom");
		puts("puis entrer adresse mail");
		scanf("%s %s",name, mail);
		strcat(name, "<");
		strcat(name,mail);
		strcat(name,">");
		sprintf(maintainer,"echo 'Maintainer:%s'>> ./newcom/DEBIAN/control",name);
		system(maintainer);
		puts("decriver courement la commande");
		scanf("%s",about);
		sprintf(description,"echo 'Desription:%s'>>./newcom/DEBIAN/control",about);
		system(description);
		system("echo 'Homepage:http://mit.mit.mg'>>./newcom/DEBIAN/control");
		
///**********CREATION DU FICHIER POUR L'EXECUTION DE LA COMMANDE PAR CREATION DE LIEN SYMBOLIQUE DU FICHIER ORIGINAL**********/// 
		system("mkdir -p usr/local/scr/");
		system("mkdir -p usr/local/scr/fileForNewcom");

		system("echo '#include <stdio.h>'>/usr/local/scr/fileForNewcom/commande.c");
		system("echo '#include <unistd.h>'>>/usr/local/scr/fileForNewcom/commande.c");
		system("echo '#include <stdlib.h>'>>/usr/local/scr/fileForNewcom/commande.c");
		system("echo 'int main(){'>>/usr/local/scr/fileForNewcom/commande.c");
		system("echo 'char link[100];'>>/usr/local/scr/fileForNewcom/commande.c");  
		sprintf(cmdLink, "echo 'which %s'", com);
		sprintf(cmdLinkCommand, "echo '	link=%s'>>/usr/local/scr/fileForNewcom/commande.c", cmdLink);
		system(cmdLinkCommand);
		sprintf(cmdPath,"echo '%s' >>/usr/local/scr/fileForNewcom/link",cmdLink);
		system(cmdPath);
		sprintf(cmdNewpath, "cp %s usr/local/scr/fileForNewcom/",cmdLink);
		system(cmdNewpath);
		char oldPath[700];
		system("echo '		if(link){'>>/fileForNewcom/commande.c");
		sprintf(oldPath,"echo '			symlink(%s,%s)'",);
		
/*	if(choix==2){
		puts("entrer le nom de la commande a changer ");scanf("%s",com);	
		puts("entrer le nom que vous souhater donner à la commande");
		scanf("%s",newcom);
		system("mkdir -p newcom/DEBIAN/ newcom/usr/bin");
	}
	else{
		system("exit");
	}*/
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	printf("Renommer une commande\n");
	char com[300], newcom[300];
//		char Pack[301];

		char package[400];
		char version0[50], version[10]="1.0";
/*		char name[100], mail[100], maintainer[200];
		char about[400], description[500];*/
		char comande[700],exec[700];
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
		system("echo 'Maintainer:Rakoto<bory@gmail.com>'>>./newcom/DEBIAN/control");
		system("echo 'Description:exec newname with same comande'>>./newcom/DEBIAN/control");
/*		
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
		system(description);*/
		system("echo 'Homepage:http://mit.mit.mg'>>./newcom/DEBIAN/control");
		
///**********CREATION DU FICHIER POUR L'EXECUTION DE LA COMMANDE**********/// 
		system("mkdir ./usr/local");
		system("mkdir ./usr/local/src");
		system("mkdir /fileForNewcom");
		system("echo '#include <stdio.h>'>./usr/local/src/fileForNewcom/commande.c");
		system("echo '#include <unistd.h>'>>./usr/local/src/fileForNewcom/commande.c");
		system("echo '#include <stdlib.h>'>>./usr/local/src/fileForNewcom/commande.c"); 
		system("echo 'int main(){'>>./usr/local/src/fileForNewcom/commande.c");
		system("echo 'char cmd[100];'>>./usr/local/src/fileForNewcom/commande.c");
		sprintf(comande,"echo 'cmd = %s ;'>> ./usr/local/src/fileForNewcom/commande.c",com);
		system(comande);
		sprintf(exec,"echo'system(%s);'>>./usr/local/src/fileForNewcom/commande.c",com);
		system(exec);
		system("echo'reurn 0;}'>>./usr/local/src/fileForNewcom/commande.c");
		
///**********COMPILATION**********///
		system("gcc -Wall ./usr/local/src/fileForNewcom/commande.c -o ./usr/bin/commande");
		
///**********CONVERSION EN .deb**********///
		system("sudo dpkg -b newcom");
		
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

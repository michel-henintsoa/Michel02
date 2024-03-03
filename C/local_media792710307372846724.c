#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** getNbrCopie(int nbrFich,int longueur,char** file);
void compressfile(char** file);
int main (){
	char** file=NULL;  
	int nbrFich=0;                         ///nombre de fichier
	int longueur=10;                       ///longueur du fichier
	
	getNbrCopie(nbrFich,longueur,file);     ///allouer l' emplacement du fichier et saisi des ficiers à copier dans un  repertoire
	compressfile(file);                     ///fonction pour la compression  des fichiers dans un repertoire 
	
			
	return 0;
}	


char** getNbrCopie(int nbrFich,int longueur,char** file){
	char creer[50];
	char cmd[90];
	printf("entrer le nombre de fichier : ");             ///saisi nombre du fichier
	scanf("%d",&nbrFich);
	file=(char**)malloc(nbrFich* sizeof(char*));          ///allocation
	for(int i=0;i<longueur;i++){
	*(file +i)=(char*)malloc(longueur* sizeof(char));
	}
	
	sprintf(creer,"mkdir -v repertory  2> /dev/null _\\;");
	system(creer);                                      ///creation du repertoire 
	printf("Entrez les noms du fichier à sauvegarder: \n");
	for(int i=0;i<nbrFich;i++){
		printf("%d: ",i+1);                            ///saisi des fichizrs à sauvegarder
		scanf("%s",file[i]);
		sprintf(cmd,"find -name %s -exec cp -r {} repertory/ 2> /dev/null \\;\n",file[i]);
		system(cmd);                                  ///commande pour copier les fichiers dans un repertpoire
		
	}

	return file;
}
void compressfile(char** file){
	char arch[50];                                                    ///emplacement  du fichier d' archive
	char cmd[200];  
	printf("Entrez le nom de l'emplacement de l' archive: ");          ///saisi du fichier archive
	scanf("%s",arch);
	sprintf(cmd,"find -name repertory -print0|tar -cvzf %s.tar.gz --null -T -\n",arch);
	system(cmd);                                                       ///commande pour l' execution du compression
	
}	

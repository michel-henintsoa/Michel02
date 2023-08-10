#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void decompression(char *fichier,char *dossier,char *cree_dossier,char *commande1,char *commande2);

int main(){
	char fichier[256];		//fichier .tar.gz
	char dossier[256];		//dossier pour contenir ke fichier decompressé
	
	char cree_dossier[50]="mkdir ";		//utilie pour la creation du dossier
	
	char decomp1[256]="tar xzf ";	//tous les deux utilisé pour :
	char decomp2[1000];				//	decompressé le fichier et le 
									//	deplacé vers le dossier	
	/*
	printf("Entrez le nom du fichier a recuperer\n");
	scanf("%s",fichier);

	printf("Dossier de recuperation\n");
	scanf("%s",dossier);

	strcat(cree_dossier,dossier);;
	
	system(cree_dossier);

	
	sprintf(decomp2,"%s -C %s",fichier,dossier);
	strcat(decomp1,decomp2);
	
	system(decomp1);
	*/
	decompression(fichier,dossier,cree_dossier,decomp1,decomp2);
	/*
	char ip[30];		//adresse de l'utilisateur
	char machine[30];	//nom du machine
	char chemin[30];	//chemin de destination
	char copy[1000]="scp ";	//variable utile pour l'execution du commande scp 
	char vide[10]=" ";	
	char utile[10]="@";
	char utile2[10]=":";
	
	printf("entrez le nom de votre machine\n");
	scanf("%s",machine);
	
	printf("entrez l'ip de votre machine\n");
	scanf("%s",ip);
	
	printf("entrez le chemin de destination\n");
	printf("en version /chemin/absolue/");
	scanf("%s",chemin);

	strcat(copy,dossier);
	strcat(copy,vide);
	strcat(copy,machine);
	strcat(copy,utile);
	strcat(copy,ip);
	strcat(copy,utile2);
	strcat(copy,chemin);
	
	system(copy);
	//printf("%s\n",copy);
	*/
	return 0;
}
void decompression(char *fichier,char *dossier,char *cree_dossier,char *decomp1,char *decomp2){	
	printf("Entrez le nom du fichier a recuperer\n");
	scanf("%s",fichier);

	printf("Dossier de recuperation\n");
	scanf("%s",dossier);

	strcat(cree_dossier,dossier);
	
	system(cree_dossier);

	
	sprintf(decomp2,"%s -C %s",fichier,dossier);
	strcat(decomp1,decomp2);
	
	system(decomp1);	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Fonction utilisé pour avoir le choix de l'utilisateur
int Choix(int choix);

/// Compression des fichiers
void compression(char* dirname);

/// Entrée des caractéristiques et envoi
void entrer_crtsq(char* user, char* passwd, char* ip, char* ssh, char* scp);
void nouvel_utilisateur(char* passwd, char* user, char* ip);
void donnees_new_user(char* name, char* password);
void utilisateur_actuel(char* user, char* ip, char* passwd, char* arch, char* ssh, char* scp);
void transfert_de_fichiers(char* user);

/// Décompression des fichiers
void decompression(char *fichier,char *dossier,char *cree_dossier,char *decomp1,char *decomp2);

int main() {

	/* Variable utilisé pour le choix de l'utilisateur */
	int choix = -1;

	/* Variables utilisées pour la compression */
	char dirname[100];

	/* Variables utilisées pour les informations de l'autre machine */
	char user[63];		// Le nom de l'utilisateur dans la machine distant
	char passwd[63];	// le mot de passe
	char ip[15];		// l'adresse IP de la machine distant

	/* Variables utilisé pour faciliter la vie */
	char ssh[500];
	char scp[500];

	/* Variables utilisées pour la décompression */
	char fichier[256];				//fichier .tar.gz
	char dossier[256];				//dossier pour contenir ke fichier decompressé
	char cree_dossier[50]="mkdir ";	// utilisé pour la création du dossier
		/* Utilisés pour : */
	char decomp1[256]="tar xzf ";	//	decompressé le fichier et le
	char decomp2[1000];				//	deplacé vers le dossier

	/* Le choix de l'utilisateur */
	choix = Choix(choix);


	/* Introduction du groupe */


	/* Compression des fichiers */
	if(choix == 1){
		compression(dirname);  ///allouer l' emplacement du fichier et saisi des ficiers à copier dans un  repertoire
	}
	/* Decompression des fichiers */
	if(choix == 2){
		decompression(fichier,dossier,cree_dossier,decomp1,decomp2);
	}
	/* Entrer les caractéristiques de l'autre machine */
	entrer_crtsq(user, passwd, ip, ssh, scp);

	/* si utiliser l'utilisateur actuel */
	utilisateur_actuel(user, ip, passwd, arch, ssh, scp);

	/* si créer un nouvel utilisateur */
//	nouvel_utilisateur(passwd, user, ip);

	return 0;
}
/// Le choix de l'utilisateur
int Choix(int choix){
	
	while(1) {
		system("clear");

		system("figlet \"Bienvenu dans ce programme.\" | echo \"\\033[1;34m$(cat)\\033[0m\"");
		printf("\nCe programme vous permet de faire 3 choses : \n\n");
	
		system("echo \"\\e[1m1. SAUVEGARDER DES FICHIERS SUR UNE MACHINE DISTANTE\\e[0m\"");
		printf("\n");
		system("echo \"\\e[1m2. PRENDRE DES FICHIERS SUR UNE MACHINE DISTANTE\\e[0m\"");
		printf("\n");
		system("echo \"\\e[1m3. TRANSFÉRER DES FICHIERS ENTRE MACHINES\\e[0m\"");
		printf("\n");

		printf("Votre choix :\n-[] : ");
		char input[256];
		
		fgets(input, sizeof(input), stdin);
		
		if(sscanf(input, "%d", &choix) != 1 || (int)choix != choix || choix > 3 ) { 
			continue;
		}
		else break;
	}
	return choix;

}
/// Fonction pour avoir les caractéristiques
void entrer_crtsq(char* user, char* passwd, char* ip, char* ssh, char* scp){
	char choix = 'n';
	while(choix != 'o' || choix != 'O' || choix != 'y' || choix != 'Y'){
	 if(choix == 'n' || choix == 'N'){
		printf("Entrer le nom d'utilisateur  : ");
		scanf("%s", user);

		printf("Entrer le mot de passe : ");
		scanf("%s", passwd);

		printf("Entrer l'IP du serveur : ");
		scanf("%s", ip);

		printf("Ces informations sont-elles correctes[o/n] : ");
		scanf("%s", &choix);
	 }
	 else break;
	}
	sprintf(ssh, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null", passwd);
	sprintf(scp, "sshpass -p \"%s\" scp -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null", passwd);
}

/// Si l'utilisateur est l'utilisateur actuel
void utilisateur_actuel(char* user, char* ip, char* passwd, char* arch, char* ssh, char* scp){
	char commande[400];
	char creation[100];
	char permission[1000];

	/* Création du dossier contenant */
	sprintf(creation, "%s %s@%s \"mkdir ~/Backup%s 2> /dev/null\"", ssh, user, ip, user);
	system(creation);

	sprintf(commande,"%s ~/%s.tar.gz %s@%s:~/Backup/ ", scp, arch, user, ip);
	system(commande);
	
	sprintf(permission, "%s %s@%s \"chmod 700 ~/Backup%s/%s.tar.gz \"", ssh, user, ip, user, arch);

	system("clear");
	
	printf("L'archive de vos fichiers a été copié dans ~/Backup%s/%s", user, arch);
	printf("\n\tTravail terminé, à ma prochaine execution !");
}
/// Si on veut un nouvel utilisateur
void nouvel_utilisateur(char* passwd, char* user, char* ip){

	char cmduser[100];		// la commande qui permet d'ajouter l' utilisateur
	char commande[400];			// la commande qui permet d'entrer dans la machine distant
	char copieTemporaire[100];	// La commande qui copie le fichier temporaire

	/* le nom du nouvel utilisateur */
	char name[64];

	/* Le mot de passe du nouvel utilisateur */
	char password[64];

	donnees_new_user(name, password);

	/* Écriture du fichier temporaire */
	FILE *fichier = fopen("Temporarfile.txt", "w");
	fprintf(fichier, "%s\n%s\n%s\n\n\n\n\n\nyes\n", passwd, password, password);
	fclose(fichier);

 	sprintf(cmduser, "sudo -S adduser %s ", name);

 	// Copie le fichier Temporaire dans la mahine distante
 	sprintf(copieTemporaire, "scp ~/Temporarfile.txt %s@%s:~/ ", user, passwd);
 	system(copieTemporaire);

	sprintf(commande, "sshpass -p \"%s\" ssh %s@%s \"%s < Temporarfile.txt ; rm Temporarfile.txt\"", passwd, user, ip, cmduser);

	printf("%s\n", commande);
	system(commande);
}
void donnees_new_user(char* name, char* password){
	printf("Entrez le nom du nouvel utilisateur : ");
	scanf("%s", name);
	printf("Entrez le mot de passe du nouvel utilisateur : ");
	scanf("%s", password);
}
//void transfert_de_fichiers(char* name){

//	system();
//}


char compression(){
	
	int categorie = 0;
	char fichier[100];
	char variable[1000];
	
	while(1){
		system("clear");
		
		system("echo \"\\033[1;34m\\tCOMPRESSION DES FICHIERS...\\033[0m\"");

		printf("DANS QUEL CATÉGORIE APPARTIENT VOTRE FICHIER ?\n");
		printf("1. Fichier C\n");
		printf("2. Image \n");
		printf("3. Video \n");
		printf("4. Autre \n");
		printf("-[] : ");

		/* Condition pour sortir de la boucle */
		char entree[63];
		fgets(entree, sizeof(entree), stdin);

		if(sscanf(entree, "%d", &categorie) != 1 || (int)categorie != categorie || categorie > 4){
			continue;
		}
		else break;
	}

	system("clear");

	if(categorie == 1){
		system("echo \"\\e[1m\\e[4m\\tVOICI LA LISTE DE VOS FICHIERS C\\e[0m\"");
		system("find . -type f -name \"*.c\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
		printf("\nEntrez ici le nom du/des fichier(s)(espacées) : ");
		fgets(variable, sizeof(variable), stdin);
	}

	if(categorie == 2){
		system("echo \"\\e[1m\\e[4m\\e[33mVOICI LA LISTE DE VOS IMAGES\\e[0m\"");
		system("find . -type f -name \"*.jpg\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
		printf("\nEntrez ici le nom du/des fichier(s)(espacées) : \n-[]:");
        fgets(variable, sizeof(variable), stdin);
	}

	if(categorie == 3){
		system("echo \"\\e[1m\\e[4m\\e[34mVOICI LA LISTE DE VOS VIDÉOS\\e[0m\"");
		system("find . -type f -name \"*.mp4\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
		printf("\nEntrez ici le nom du/des fichier(s)(espacées) : \n-[]:");
		fgets(variable, sizeof(variable), stdin);

	}

	if(categorie == 4){
		printf("Donnez le nom de votre(vos) fichier(s) : \n-[]");
		fgets(variable, sizeof(variable), stdin);
	}
	
	char delim[] = " \n";		// La delimitation 
	char *token = strtok(variable, delim);
	char commande[2050];
	char dirname[1000];
	char nom_fichier[1000];

	
	printf("Quel est le nom du fichier de compression ?\n");
	scanf("%s", dirname);
	
	sprintf(commande, "mkdir %s", dirname);
	system(commande);
	

	while(token != NULL){
		strcpy(nom_fichier, token);
		sprintf(commande ,"find . -name %s -exec cp {} \"%s\" \\; 2> /dev/null", nom_fichier, dirname);
		system(commande);
		token = strtok(NULL, delim);
	}
	
	char cmd[1000];
	sprintf(cmd, "tar -czvfk %s.tar.gz %s 2> /dev/null", dirname, dirname);
	system(cmd);
	
	return dirname;

}

/// Fonction utilisé pour la décompression du fichier
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

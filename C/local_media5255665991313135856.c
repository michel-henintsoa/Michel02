#include <stdio.h>
#include <stdlib.h>

void entrer_crtsq(char* user, char* passwd, char* ip);
void nouvel_utilisateur(char* passwd, char* user, char* ip);
void utilisateur_actuel(char* user, char* ip, char* passwd);
void transfert_de_fichiers(char* user);

int main() {

	char user[63];		// Le nom de l'utilisateur dans la machine distant
	char passwd[63];	// le mot de passe
	char ip[15];		// l'adresse IP de la machine distant


	/* Introduction du groupe */


	/* Entrer les caractéristiques de l'autre machine */
	entrer_crtsq(user, passwd, ip);

	/* si utiliser l'utilisateur actuel */
	utilisateur_actuel(user, ip, passwd);

	/* si créer un nouvel utilisateur */
	nouvel_utilisateur(passwd, user, ip);

	return 0;
}
/// Fonction pour avoir les caractéristiques
void entrer_crtsq(char* user, char* passwd, char* ip){
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
}

/// Si l'utilisateur est l'utilisateur actuel
void utilisateur_actuel(char* user, char* ip, char* passwd){
	char commande[400];

	FILE *fichier = fopen("mot_de_passe777.txt", "w");
		fprintf(fichier,"%s", passwd);
	fclose(fichier);

	system("ssh %s@%s \"mkdir ~/Backup 2> /dev/null\"", user, ip);

	sprintf(commande,"scp %s@%s:%s %s < %s", user, ip, chemin_du_fichier, chemin_du_fichier2, mot_de_passe777.txt);

	system(commande);

	printf("\n\tTravail terminé, à ma prochaine execution !");

}

/// Si on veut un nouvel utilisateur
void nouvel_utilisateur(char* passwd, char* user, char* ip){

	char cmdadduser[100];	// la commande qui permet d'ajouter l' utilisateur
	char commande[400];	// la commande qui permet d'entrer dans la machine distant

	char name[64];		// le nom du nouvel utilisateur
	printf("Entrez le nom du nouvel utilisateur : ");
	scanf("%s", name);

	char password[64];	// le mot de passe du nouvel utilisateur
	printf("entrez le mot de passe du nouvel utilisateur : ");
	scanf("%s", password);

	FILE *fichier = fopen("Temporarfile.txt", "w");

	fprintf(fichier, "%s\n%s\n%s\n\n\n\n\n\nyes\n", passwd, password, password);

	fclose(fichier);

 	sprintf(cmduser, "sudo -S adduser %s ", name);
	sprintf(commande, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no %s@%s \"%s < Temporarfile.txt ; rm Temporarfile.txt\"", passwd, user, ip, cmduser);

	printf("%s\n", commande);
	system(commande);
}
void transfert_de_fichiers(char* name){

	system();
}

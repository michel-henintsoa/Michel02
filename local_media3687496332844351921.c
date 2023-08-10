#include <stdio.h>
#include <stdlib.h>
void entrer_crtsq(char* user, char* passwd, char* ip, char choix);

int main() {

	char user[63];
	char passwd[63];
	char ip[15];
	char commande[400];
	char choix = 'n';


	char cmduser[100];

	entrer_crtsq(user, passwd, ip, choix);
/* à utiliser si l'utilisateur veut créer un autre utilisateur pour la sauvegarde du ficher*/

	char name[64];
	printf("Entrez le nom du nouvel utilisateur : ");
	scanf("%s", name);

	char password[64];
	printf("entrez le mot de passe du nouvel utilisateur : ");
	scanf("%s", password);

	FILE *fichier;

	fichier = fopen("Temporarfile.txt", "w");
	fprintf(fichier, "%s\n%s\n%s\n\n\n\n\n\nyes", passwd, password, password);

	fclose(fichier);

	sprintf(cmduser, "sudo -S adduser %s ", name);
	sprintf(commande, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no %s@%s \"%s\"", passwd, user, ip, cmduser);

	printf("%s\n", commande);
	system(commande);

	



	return 0;
}
/// Fonction pour avoir les caractéristiques
void entrer_crtsq(char* user, char* passwd, char* ip, char choix){
//	while(choix != 'o' || choix !='O' || choix != 'y' || choix != 'Y'){
//	 if(choix == 'n' || choix == 'N'){
		printf("Entrer le nom d'utilisateur : ");
		scanf("%s", user);

		printf("Entrer le mot de passe : ");
		scanf("%s", passwd);

		printf("Entrer l'IP du serveur : ");
		scanf("%s", ip);

		printf("Ces informations sont-elles correctes[o/n] :");
		scanf("%s", &choix);
//	 }
//	}
}
/// Si on veut un nouvel utilisateur
//void nouvel_utilisateur(

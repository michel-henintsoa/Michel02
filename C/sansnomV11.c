#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <unistd.h>

/// Fonction utilisé pour avoir les différents choix de l'utilisateur
int Choix(int choix);
int Choix2(int choix2);

/// Compression des fichiers
void compression(char* dirname);

/// Entrée des caractéristiques et envoi
void entrer_crtsq(char* user, char* passwd, char* ip, char* ssh, char* scp);
void se_connecter(char* user, char* ip, char* passwd, char* dirname, char* ssh, char* scp);

void new_user_data(char* name, char* password, char* dirname, char* ssh, char* scp);
void nouvel_utilisateur(char* passwd, char* user, char* ip, char* dirname, char* ssh, char* scp);
void userCreate(char* user, char* passwd, char* ip, char* name, char* password, char* dirname, char* ssh, char* scp);
void transfertN(char* name, char* password, char* ip, char* dirname);

/// Transfert de fichiers
void transfert_de_fichiers(char* user);

/// Décompression des fichiers
void decompression(char *fichier1,char *dossier,char *cree_dossier,char *decomp1,char *decomp2);

void creerdossier(char *dossier,char *dossier1,char *dossier2,char *dossier3,char *dossier5);
void sansnoms_transfert(char *choix,char *ip,char *user,char *fichier,char *locate,char *transfert,char *secure);


int main() {

    /* Variable utilisé pour le choix de l'utilisateur */
    int choix = -1;
    int choix2 = -1;

    /* Variable utilisée pour la compression */
    char dirname[100];

    /* Variables utilisées pour les informations de l'utilisateur dans l'autre machine */
    char user[63];        // Le nom de l'utilisateur dans la machine distant
    char passwd[63];    // le mot de passe
    char ip[30];        // l'adresse IP de la machine distant

    /* Variables utilisées pour se faciliter la vie */
    char ssh[500];
    char scp[500];

    /* Variables utilisées pour la décompression */
    char fichier[256];                //fichier .tar.gz
    char dossier[256];                //dossier pour contenir ke fichier decompressé
    char cree_dossier[50]="mkdir ";    // utilisé pour la création du dossier
    /* Utilisés pour : */
    char decomp1[256]="tar xzf ";    //    decompressé le fichier et le
    char decomp2[1000];                //    deplacé vers le dossier

//--------------------------------------------------------------------//
    ///variable:
    char choix0[30];                        //send or receive
    char ip0[30];                        //ip du machine du machine recepteur
    char user0[30];                        //nom de l'utiisateur du machine recepteur
    char fichier0[30];                    //le fichier a envoyer

//--------------------------------------------------------------------//
///variable:
    //utile pour les dossiers crée par defaut
    //utiliser pour classer les fichiers envoyées
    char dossier0[30]="mkdir -p ./sans_nom";
    char dossier10[30]="mkdir -p sans_nom/folder";
    char dossier20[30]="mkdir -p sans_nom/other";
    char dossier30[30]="mkdir -p sans_nom/video";
    char dossier50[30]="mkdir -p sans_nom/fichier_C";
//--------------------------------------------------------------------//

    char locate0[300];               //trouvons le fichier
    char transfert0[1000];           //transferons le fichier
    char secure0[50];                //simple securite utile
    char lance[10];
    do {
        /* Le choix de l'utilisateur */
        choix = Choix(choix);

        /* Compression des fichiers */
        if(choix == 1) {
            compression(dirname);                  /// Fonction pour la compression des fichiers

            choix2 = -1;
            choix2 = Choix2(choix2);

            /* Si se connecter à un utilisateur déjà présent */
            if(choix2 == 1) {
                entrer_crtsq(user, passwd, ip, ssh, scp);            /// Entre les caractéristiques de l'utilisateur
                se_connecter(user, ip, passwd, dirname, ssh, scp);
            }

            /* si créer un nouvel utilisateur */
            if (choix2 == 2) {
                nouvel_utilisateur(passwd, user, ip, dirname, ssh, scp);
            }
        }
        /* Decompression des fichiers */
        if(choix == 2) {
            decompression(fichier,dossier,cree_dossier,decomp1,decomp2);
        }

        /* Transfert des fichiers */
        if(choix == 3) {
//--------------------------------------------------------------------//
            creerdossier(dossier0, dossier10, dossier20, dossier30, dossier50);
            //fonction qui cree le dossier ou les fichier transferée seront placés
//--------------------------------------------------------------------//
            sansnoms_transfert(choix0, ip0, user0, fichier0, locate0, transfert0, secure0);
            //Transfert du fichier
//--------------------------------------------------------------------//

        }
        printf("Continuer ou arreter(oui/non)\n");
        scanf("%s",lance);
    } while(strcmp(lance,"oui") == 0);



    return 0;
}
/// Le choix de l'utilisateur
int Choix(int choix) {

    while(1) {
        system("clear");

        system("figlet \"Bienvenu dans ce programme.\" | echo \"\\033[1;34m$(cat)\\033[0m\"");
        printf("\nCe programme vous permet de faire 3 choses : \n\n");

        system("echo \"\\e[1m1. SAUVEGARDER DES FICHIERS SUR UNE MACHINE DISTANTE\\e[0m\"");
        printf("\n");
        system("echo \"\\e[1m2. PRENDRE DES FICHIERS SAUVEGARDÉS SUR UNE MACHINE DISTANTE\\e[0m\"");
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

/// Fonction utilisé pour la compression des fichiers
void compression(char* dirname) {

    int categorie = 0;
    char variable[1000];

    while(1) {
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

        if(sscanf(entree, "%d", &categorie) != 1 || (int)categorie != categorie || categorie > 4) {
            continue;
        }
        else break;
    }

    system("clear");

    if(categorie == 1) {
        system("echo \"\\e[1m\\e[4m\\tVOICI LA LISTE DE VOS FICHIERS C\\e[0m\"");
        system("find . -type f -name \"*.c\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
        printf("\nEntrez ici le nom du/des fichier(s)(espacées) : \n-[] : ");
        fgets(variable, sizeof(variable), stdin);
    }

    if(categorie == 2) {
        system("echo \"\\e[1m\\e[4m\\e[33mVOICI LA LISTE DE VOS IMAGES\\e[0m\"");
        system("find . -type f -name \"*.jpg\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
        printf("\nEntrez ici le(s) nom du/des fichier(s)(espacées) : \n-[] :");
        fgets(variable, sizeof(variable), stdin);
    }

    if(categorie == 3) {
        system("echo \"\\e[1m\\e[4m\\e[34mVOICI LA LISTE DE VOS VIDÉOS\\e[0m\"");
        system("find . -type f -name \"*.mp4\" -execdir sh -c 'lsd \"$1\"' sh {} \\;");
        printf("\nEntrez ici le(s) nom du/des fichier(s)(espacées) : \n-[] :");
        fgets(variable, sizeof(variable), stdin);

    }

    if(categorie == 4) {
        system("lsd --tree ~/");
        printf("Donnez le(s) nom de votre(vos) fichier(s)(espacées) : \n-[] : ");
        fgets(variable, sizeof(variable), stdin);
    }

    char delim[] = " \n";        // La delimitation
    char *token = strtok(variable, delim);
    char commande[2050];
    char nom_fichier[1000];


    printf("Quel est le nom de l'archive compressé ?\n");
    scanf("%s", dirname);

    sprintf(commande, "mkdir %s", dirname);
    system(commande);


    while(token != NULL) {
        strcpy(nom_fichier, token);
        sprintf(commande,"find . -name %s -exec cp {} \"%s\" \\; 2> /dev/null", nom_fichier, dirname);
        system(commande);
        token = strtok(NULL, delim);
    }

    char cmd[1000];
    sprintf(cmd, "tar -czvf %s.tar.gz %s 2> /dev/null && rm -r %s", dirname, dirname, dirname);
    system(cmd);

}
/// Fonction pour faire le choix de l'utilisateur
int Choix2(int choix2) {
    char input[10];

    while(1) {
        system("clear");

        system("echo \"\\e[1m VOUS AVEZ DEUX CHOIX DE SAUVEGARDE : \\e[0m\"");
        printf("\n");

        printf("1. Se connecter dans un utilisateur présent \n");

        printf("2. Créer un nouvel utilisateur \n(requiert les privilèges de superutilisateur sur votre machine)\n");

        printf("Votre choix : \n---- : ");

        fgets(input, sizeof(input), stdin);

        if(sscanf(input, "%d", &choix2) != 1 || (int)choix2 != choix2 || choix2 > 2) {
            continue;
        }
        else break ;
    }
    return choix2;
}

/// Fonction pour avoir les caractéristiques
void entrer_crtsq(char* user, char* passwd, char* ip, char* ssh, char* scp) {

    char choix = 'n';

    while(choix != 'o' || choix != 'O' || choix != 'y' || choix != 'Y') {
        if(choix == 'n' || choix == 'N') {

            system("clear");

            printf("Entrer votre nom d'utilisateur : ");
            scanf("%s", user);

            strcpy(passwd, getpass("Entrer votre mot de passe : "));

            printf("Entrer l'adresse IP de la machine : ");
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
void se_connecter(char* user, char* ip, char* passwd, char* dirname, char* ssh, char* scp) {

    char commande[400];        // La commande pour la copie
    char creation[100];        // La commande pour la création du repertoire
    char permission[1000];        // La commande pour changer la permission du fichier
    int test = 20;            // Variable utilisé pour tester le retour des fonctions

    /* Création du dossier contenant */
    sprintf(creation, "%s %s@%s \"mkdir -p ~/Backup 2> /dev/null\"", ssh, user, ip);
    test = system(creation);

    if(test == 0) {
        printf("Répertoire créée avec succès.\n");
    } else {
        printf("Erreur lors de la création du repertoire\n");
    }

    sprintf(commande,"%s ./%s.tar.gz %s@%s:~/Backup/ ", scp, dirname, user, ip);
    system(commande);

    sprintf(permission, "%s %s@%s \"chmod 700 ~/Backup/%s.tar.gz \"", ssh, user, ip, dirname);
    system(permission);

    system("clear");

    printf("L'ARCHIVE DE VOS FICHIERS A ÉTÉ COPIÉ AVEC SUCCÈS DANS ~/Backup/");
    printf("\n\tTravail terminé, retour au menu !");

}
void new_user_data(char* name, char* password, char* dirname, char* ssh, char* scp) {
    int choix = 10;
    char Choix[100];

    while(1) {
        system("clear");
        printf("Pour créer un nouvel utilisateur dans la machine,\nvous devez avoir un compte administrateur.\n");
        printf("Si vous voulez en faire usage,entrer 1 sinon pour quitter 0\n\t");

        fgets(Choix, sizeof(Choix), stdin);
        if(sscanf(Choix,"%d", &choix) != 1 || (int)choix != choix || choix > 2 || choix < 0) {
            continue;
        } else {
            break;
        }
    }


    if(choix == 1) {

        char michel = 'n';
        char user[100];
        char ip[100];
        char passwd[100];

        while(michel != 'o' || michel != 'O' || michel != 'y' || michel != 'Y') {
            if( michel == 'n' || michel == 'N') {

                system("clear");

                printf("Entrer l'identifiant  de l'administrateur : ");
                scanf("%s", user);

                strcpy(passwd, getpass("Entrer votre mot de passe : "));

                printf("Entrer l'adresse IP de la machine : ");
                scanf("%s", ip);

                printf("Ces informations sont-elles correctes[o/n] : ");
                scanf("%s", &michel);

            }
            else break;
        }
        system("clear");

        printf("Entrez le nom du nouvel utilisateur : ");
        scanf("%s", name);
        printf("Entrez le mot de passe du nouvel utilisateur : ");
        scanf("%s", password);

        userCreate(user, passwd, ip, name, password, dirname, ssh, scp);

    }
}
/// Si on veut un nouvel utilisateur
void nouvel_utilisateur(char* passwd, char* user, char* ip, char* dirname, char* ssh, char* scp) {

    /* le nom du nouvel utilisateur */
    char name[64];

    /* Le mot de passe du nouvel utilisateur */
    char password[64];

    new_user_data(name, password, dirname, ssh, scp);
    transfertN(name, password, ip, dirname);

}
void transfertN(char* name, char* password, char* ip, char* dirname) {

    char commande[400];        // La commande pour la copie
    char creation[400];        // La commande pour la création du repertoire
    char permission[1000];        // La commande pour changer la permission du fichier
    int test = 20;            // Variable utilisé pour tester le retour des fonctions

    /* Création du dossier contenant */
    sprintf(creation, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null %s@%s \"mkdir -p ~/Backup 2> /dev/null\"", password, name, ip);
    test = system(creation);

    if(test == 0) {
        printf("Répertoire créée avec succès.\n");
    } else {
        printf("Erreur lors de la création du repertoire\n");
    }

    sprintf(commande,"sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null ~/%s.tar.gz %s@%s:~/Backup/ ", password, dirname, name, ip);
    system(commande);

    sprintf(permission, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null %s@%s \"chmod 700 ~/Backup/%s.tar.gz \"", password, name, ip, dirname);
    system(permission);

    system("clear");

    printf("L'ARCHIVE DE VOS FICHIERS A ÉTÉ COPIÉ AVEC SUCCÈS DANS /home/%s/Backup/", name);
    printf("\n\tTravail terminé, retour au menu !");


}

void userCreate(char* user, char* passwd, char* ip, char* name, char* password, char* dirname, char* ssh, char* scp) {
    char cmduser[100];            // la commande qui permet d'ajouter l' utilisateur
    char commande[400];            // la commande qui permet d'entrer dans la machine distant
    char copieTemporaire[100];    // La commande qui copie le fichier temporaire


    /* Écriture du fichier temporaire */

    FILE *fichier = fopen("Temporarfile.txt", "w");
    fprintf(fichier, "%s\n%s\n%s\n\n\n\n\n\nyes\n", passwd, password, password);
    fclose(fichier);

    sprintf(cmduser, "sudo -S adduser %s ", name);

    // Copie le fichier Temporaire dans la mahine distante
    sprintf(copieTemporaire, "sshpass -p \"%s\" scp -o StricthostKeyChecking=no ./Temporarfile.txt %s@%s:~/ 2> /dev/null", passwd, user, ip);
    system(copieTemporaire);

    sprintf(commande, "sshpass -p \"%s\" ssh -o StrictHostKeyChecking=no %s@%s \"%s < Temporarfile.txt\" 2> /dev/null", passwd, user, ip, cmduser);
    system(commande);

    system("clear");
    printf("Utilisateur créé avec succès.\n");
    printf("Vous pouvez maintenant sauvegarder des fichiers en vous connectant.");

}
/// Fonction utilisé pour la décompression du fichier
void decompression(char *fichier1,char *dossier,char *cree_dossier,char *decomp1,char *decomp2) {
    char user[100];
    char ip[100];
    char compte[100];
    char recu[512];
    char secure[20]="rm ";

    system("clear");

    system("echo \"\\e[1mBIENVENU DANS LA PRISE ET DÉCOMPRESSION DE FICHIERS\\e[0m\"");

    printf("\n");

    printf("Entrez le nom du fichier a recuperer(en .tar.gz)\n");
    scanf("%s", fichier1);

    printf("Entrez le nom de l'utilisateur\n");
    scanf("%s", user);

    printf("Entrez son adresse IP\n");
    scanf("%s", ip);

    printf("Entrez le nom de votre repertoire dans cette serveur\n");
    scanf("%s", compte);

    sprintf(recu,"scp %s@%s:/home/%s/Backup/%s ./", user, ip, compte, fichier1);
//      printf("%s\n",recu);
    system(recu);

    printf("Dossier de recuperation\n");
    scanf("%s",dossier);

    strcat(cree_dossier,dossier);
    system(cree_dossier);

    sprintf(decomp2,"%s -C %s",fichier1,dossier);
    strcat(decomp1,decomp2);

    strcat(secure,fichier1);
    system(decomp1);
//      printf("%s\n",secure);
    system(secure);
}



//void transfert_de_fichiers(char* name){

//    system();
//}
void sansnoms_transfert(char *choix,char *ip,char *user,char *fichier,char *locate,char *transfert,char *secure) {
    //action de l'utilisateur
///------------------------------------------------------------------///
    char uti[] = "Transfert de fichier : ";
    for(int i=0; uti[i] != '\0'; i++) {
        printf("%c",uti[i]);
        fflush(stdout);
        usleep(60000);
    }
    printf("\n");
    char uti0[] = "tput setaf 4;figlet -f big 1-recevoir  2-envoyer;tput sgr0";
    while(strcmp(choix,"1") != 0 && strcmp(choix,"2") != 0) {
        system(uti0);
        printf("\n");
        scanf("%s",choix);
    }
    system("clear");
///------------------------------------------------------------------///
    if(strcmp(choix,"1")==0) {
        char receive1[] ="Veuillez montrez ces informations à l'envoyeur : ";
        for(int i=0; receive1[i] != '\0'; i++) {
            printf("%c",receive1[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
        printf("\n");
        printf("Adresse IP : \n");
        system("hostname -I");
        printf("\n");
        printf("Nom d'utilisateur : \n");
        system("whoami");
    }
///------------------------------------------------------------------///
    //information sur le machine recepteur
//--------------------------------------------------------------------//
    if(strcmp(choix,"2")==0) {
        char uti1[] = "entrez l'adresse IP du machine distant : ";
        for(int i=0; uti1[i] != '\0'; i++) {
            printf("%c",uti1[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
        scanf("%s",ip);
        system("clear");
        char uti2[] = "entrez le nom d'utilisateur du machine distant : ";
        for(int i=0; uti2[i] != '\0'; i++) {
            printf("%c",uti2[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
        scanf("%s",user);
        system("clear");
//--------------------------------------------------------------------//
        //localisation du fichier
//--------------------------------------------------------------------//
        char uti3[] = "entrez le nom du fichier : ";
        for(int i=0; uti3[i] != '\0'; i++) {
            printf("%c",uti3[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
        scanf("%s",fichier);
        system("clear");

        char tmp[1000];
        sprintf(tmp,"Envoye du %s vers %s:%s",fichier,user,ip);
        for(int i=0; tmp[i] != '\0'; i++) {
            printf("%c",tmp[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
        char chargement[] = "Attendez un moment ...";
        for(int i=0; chargement[i] != '\0'; i++) {
            printf("%c",chargement[i]);
            fflush(stdout);
            usleep(30000);
        }
        sprintf(locate,"cp -r $(find /home -name \"%s\" 2>/dev/null) sans_nom/ 2>/dev/null",fichier);
        //      printf("%s\n",locate);
        system(locate);
        printf("\n");
        char send1[] = "Encore un peu";
        for(int i=0; send1[i] != '\0'; i++) {
            printf("%c",send1[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n");
//--------------------------------------------------------------------//

        //determination nature fichier
///------------------------------------------------------------------///
        char chemin[100];
        sprintf(chemin,"sans_nom/%s",fichier);
        struct stat s;
///------------------------------------------------------------------///
        //fichier de type repertoire
//--------------------------------------------------------------------//
        if(stat(chemin,&s) == 0) {
            if(S_ISDIR(s.st_mode)) {
                sprintf(transfert,"scp -r ./sans_nom/%s %s@%s:./sans_nom/folder",fichier,user,ip);
                //              printf("%s\n",transfert);
                system(transfert);
                char send2[] ="c'est presque,...";
                for(int i=0; send2[i] != '\0'; i++) {
                    printf("%c",send2[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sprintf(secure,"rm -r ./sans_nom/%s",fichier);
//                printf("%s\n",secure);
                system(secure);
                char utiF1[] ="Transfert finie";
                for(int i=0; utiF1[i] != '\0'; i++) {
                    printf("%c",utiF1[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n");

//--------------------------------------------------------------------//

            }
            //fichier regulier
//--------------------------------------------------------------------//
            else {

                ///fichier C:
                char *nature_fic = strrchr(fichier, '.');

                if(nature_fic == NULL) {
                    sprintf(transfert,"scp ./sans_nom/%s %s@%s:./sans_nom/other",fichier,user,ip);
                    //      printf("%s\n",transfert);
                    system(transfert);
                    char send10[] ="c'est presque,...";
                    for(int i=0; send10[i] != '\0'; i++) {
                        printf("%c",send10[i]);
                        fflush(stdout);
                        usleep(30000);
                    }
                }
                else if(strcmp(nature_fic,".c") == 0) {
                    sprintf(transfert,"scp ./sans_nom/%s %s@%s:./sans_nom/fichier_C",fichier,user,ip);
                    //      printf("%s\n",transfert);
                    system(transfert);
                    char send3[] ="c'est presque,...";
                    for(int i=0; send3[i] != '\0'; i++) {
                        printf("%c",send3[i]);
                        fflush(stdout);
                        usleep(30000);
                    }
                }
                ///fichier video:
                else if(strcmp(nature_fic,".mp4") == 0 || strcmp(nature_fic,".avi") == 0) {
                    sprintf(transfert,"scp ./sans_nom/%s %s@%s:./sans_nom/video",fichier,user,ip);
                    //      printf("%s\n",transfert);
                    system(transfert);
                    char send4[] ="c'est presque,...";
                    for(int i=0; send4[i] != '\0'; i++) {
                        printf("%c",send4[i]);
                        fflush(stdout);
                        usleep(30000);
                    }
                }

                ///fichier d'autre type

                else {
                    sprintf(transfert,"scp ./sans_nom/%s %s@%s:./sans_nom/other",fichier,user,ip);
                    //      printf("%s\n",transfert);
                    system(transfert);
                    char send5[] ="c'est presque,...";
                    for(int i=0; send5[i] != '\0'; i++) {
                        printf("%c",send5[i]);
                        fflush(stdout);
                        usleep(30000);
                    }
                }
                sprintf(secure,"rm ./sans_nom/%s",fichier);
//      printf("%s\n",secure);
                system(secure);
                char utiF[] ="Transfert finie";
                for(int i=0; utiF[i] != '\0'; i++) {
                    printf("%c",utiF[i]);
                    fflush(stdout);
                    usleep(30000);
                }
//      printf("finie\n");
            }
        }
//--------------------------------------------------------------------//
        //cas pour les bugs
//--------------------------------------------------------------------//
        else {
            printf("\n");
            char uti4[] ="Une erreur s'est produite !";
            for(int i=0; uti4[i] != '\0'; i++) {
                printf("%c",uti4[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n");
            char uti5[] ="Verifier votre fichier s'il existe vraiment.\n";
            for(int i=0; uti5[i] != '\0'; i++) {
                printf("%c",uti5[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n");
            char uti6[] ="Veuillez contacter les administrateurs si vous avez besoin d'aide.";
            for(int i=0; uti6[i] != '\0'; i++) {
                printf("%c",uti6[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n");
        }
    }
//--------------------------------------------------------------------//
///------------------------------------------------------------------///
}

void creerdossier(char *dossier,char *dossier1,char *dossier2,char *dossier3,char *dossier5) {
//--------------------------------------------------------------------//
    system(dossier);
    system(dossier1);
    system(dossier2);
    system(dossier3);
    system(dossier5);
//--------------------------------------------------------------------//
}


    
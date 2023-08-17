#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct Name {
    char nom[255], prenom[255];
    char numTel[20];
    char mail[255], adress[255];
    char dateN[10], lieuN[100];
    char obtBac[5];
    char genre[10];
    char CIN[20];
    char urlGit[255];
} Name;
int comparaison(const void *a, const void *b);

int main() {
    FILE *file;
    file = fopen("infoMpianatra.csv", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    Name mit[50];
    char line[MAX_LINE_LENGTH];
	int i=0;
    while (fgets(line, sizeof(line), file)) {
        int res = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                         mit[i].nom, mit[i].prenom, mit[i].numTel, mit[i].mail, mit[i].adress, mit[i].dateN,
                         mit[i].lieuN, mit[i].obtBac, mit[i].genre, mit[i].CIN, mit[i].urlGit);

        // Set default values for empty fields
        if (res < 11) {
            strcpy(mit[i].CIN, "");
            strcpy(mit[i].urlGit, "");
            if (res < 10) strcpy(mit[i].genre, "");
            if (res < 9) strcpy(mit[i].obtBac, "");
            if (res < 8) strcpy(mit[i].lieuN, "");
            if (res < 7) strcpy(mit[i].dateN, "");
            if (res < 6) strcpy(mit[i].adress, "");
            if (res < 5) strcpy(mit[i].mail, "");
            if (res < 4) strcpy(mit[i].numTel, "");
            if (res < 3) strcpy(mit[i].prenom, "");
            if (res < 2) strcpy(mit[i].nom, "");
        }

        printf("Nom : %s, Prénom : %s, Numéro de téléphone : %s, Email : %s\n%ld\n",
               mit[i].nom, mit[i].prenom, mit[i].numTel, mit[i].mail, strlen(mit[i].prenom));
        i++;
    }
    int nE=i;

    printf("STOP\n");

    fclose(file);
    qsort(mit, nE, sizeof(Name), comparaison);
    
    FILE* tri;
    tri=fopen("nomTriMpianatra.csv", "w");
    fprintf(tri, "Nom,Prenom,Numero Telephone,E-mail, Adresse,date de Naissance,Lieu de Naissance,Annee d'obtention du bac,Genre,CIN,URL Github\n");
    i=0;
    while(i<nE+1){
		fprintf(tri, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
                mit[i].nom, mit[i].prenom, mit[i].numTel, mit[i].mail, mit[i].adress, mit[i].dateN,
                mit[i].lieuN, mit[i].obtBac, mit[i].genre, mit[i].CIN, mit[i].urlGit);
                i++;
        
	}
    fclose(tri);
    return 0;
}

int comparaison(const void *a, const void *b){
	const Name *nA=(const Name*)a;
	const Name *nB=(const Name*)b;
	int cmp=strcmp(nA->nom, nB->nom);
	if(cmp==0) return strcmp(nA->prenom, nB->prenom);
	return cmp;
}

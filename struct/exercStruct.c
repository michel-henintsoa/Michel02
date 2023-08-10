#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pc{
	char mac[18];
	char mark[20];
	char prop[20];
} Pc;

typedef struct Etudiant{
	char nom[100];
	char prenom[200];
	char mention[50];
	char parcour[10];
	char grade[10];
	char numInsc[20];
} Etudiant;

int main(){
	Pc machine[50];
	int i=0;
	FILE *pc, *stud;
	pc=fopen("PhysicalComputer.csv", "a+");
	if(pc==NULL) exit(1);
	fputs("mac/mark/prop\n", pc);
	int choise=1;
	verina:
		printf("entrez le mac du numeros\t");
		scanf("%s", machine[i].mac);
		printf("\nentrez la marque de son pc\t");
		scanf("%s", machine[i].mark);
		printf("\netrez le nom du proprietaire\t");
		scanf("%s", machine[i].prop);
		fprintf(pc, "%s/%s/%s\n", machine[i].mac, machine[i].mark, machine[i].prop);
		printf("\nis there other person(1:oui or 0:no)\t");
		scanf("%d", &choise);
		if(choise==1){ 
			i++;
			goto verina;
		}
	fclose(pc);
	i=0;
	int choix;
	printf("voullez vous continuer avec les infos des etudiant(o:oui; n:non");
	scanf("%d", &choix);
	
	Etudiant std[50];
	stud=fopen("Student.csv", "a+");
	if(stud==NULL) exit(1);
	fputs("NOM/Prenom/Mention/Parcours/Grade/Numeros d'inscription\n", stud);
	int c=1;
	while(c==1){
		printf("entrez le nom du numero %d\t", i+1);
		scanf("%s", std[i].nom);
		printf("\tentrez son prenom\n");
		scanf("%s", std[i].prenom);
		strcpy(std[i].mention, "Portail1");
		strcpy(std[i].parcour, "MIT");
		strcpy(std[i].grade, "L1");
		printf("\nentrez le numeros d'inscrition\t");
		scanf("%s", std[i].numInsc);
		fprintf(stud,"%s/%s/%s/%s/%s/%s\n", std[i].nom, std[i].prenom ,std[i].mention, std[i].parcour, std[i].grade, std[i].numInsc);
		printf("\nvoulez vous continuer(1:oui,0:non)\t");
		scanf("%d", &c);
		i++;
	}
	fclose(stud);
	return 0;
}

Pc* triParNom(Pc *machine){
	Pc mach[50];
	
	return mach;
}

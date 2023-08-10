#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countLine();
//void triString(char** data, int a);
typedef struct Name{
	char nom[255];
	char prenom[255];
}Name;
Name takeName(char* all);
int maxlen(char* chr1, char* chr2);
int comparaison(const void *a, const void *b);

int main(){
	FILE* tri;
	char allName[255];
	Name sepName[50];
	tri=fopen("Tri.csv", "a+");
	int i=0;
	while(fgets(allName,255, tri)!=NULL){
		sepName[i]=takeName(allName);
		i++;
	}
	int tailleListe = sizeof(sepName) / sizeof(sepName[0]);
    
	qsort(sepName, tailleListe, sizeof(Name), comparaison);
	FILE *sortName;
	sortName=fopen("./nomTrierMichel02.csv", "w+");
	for (int i = 0; i < tailleListe; i++) {
		fprintf(sortName,"%s,%s", sepName[i].nom, sepName[i].prenom);
	}
    fclose(sortName);
    
	fclose(tri);
	return 0;
}

int countLine(){
	FILE* tri;
	tri=fopen("Tri.csv", "r");
	int ln=0;
	char c;
	if(tri==NULL) exit(1);
	while(c!=EOF){
		c=fgetc(tri);
		if(c=='\n') ln++;
//		printf("\n%d\n", ln);
	}
	fclose(tri);
	return ln;
}

Name takeName(char* all){
	Name name;
	char* naka=strtok(all, ",");
	strcpy(name.nom, naka);
	naka=strtok(NULL, ",");
	strcpy(name.prenom, naka);
//	printf("%s  ",name.nom);
//	printf("%s",name.prenom);
	return name;
}

int maxlen(char* chr1, char* chr2){
	return (strlen(chr1)<=strlen(chr2))?strlen(chr2):strlen(chr1);
}

int comparaison(const void *a, const void *b) {
	const Name *nomCompletA = (const Name *)a;
	const Name *nomCompletB = (const Name *)b;
    
	// Compare les noms complets
	int resultatNom = strcmp(nomCompletA->nom, nomCompletB->nom);
    
// Si les noms sont égaux, compare les prénoms
	if (resultatNom == 0) {
		return strcmp(nomCompletA->prenom, nomCompletB->prenom);
	}
    
	return resultatNom;
}


/*void triString(char** data, int a){
	char tmp[255];
	int len=0;
	for(int j=1; j<a; j++){
		for(int k=j+1; k<a; k++){
			len=maxlen(data[j], data[k]);
			if((data[j][0])<(data[k][0])) continue;
			else if((data[j][0])>(data[k][0])){
				strcpy(tmp, data[j]);
				strcpy(data[j], data[k]);
				strcpy(data[k], tmp);
			}
			else if((data[j][0])==(data[k][0])){
				for(int l=0; l<len; l++){
					if((data[j][l])<(data[k][l])) break;
					if((data[j][l])>(data[k][l])){
						strcpy(tmp, data[j]);
						strcpy(data[j], data[k]);
						strcpy(data[k],tmp);
						break;
					}
				}
			}
		}
	}
}*/

/*Name* triString(Name* sort, int a){
	Name tmp;
	int len=0;
	int  i=0;
	while(i<a){
		for(int j=i+1; j<a; j++){
			if(strcmp(sort[i].nom, sort[j].nom)!=0){
				if(sort[i].nom[0]<sort[j].nom[0]) {continue;}
				else if(sort[i].nom[0]>sort[j].nom[0]){
					tmp=sort[i];
					sort[i]=sort[j];
					sort[j]=tmp;
				}
				len=maxlen(sort[i].nom, sort[j].nom);
				else if(sort[i].nom[0]==sort[j].nom[0]){
					for(int k=1; k<len; k++){
						if(sort[i].nom[k]<sort[j].nom[k]) break;
						if(sort[i].nom[k]>sort[j].nom[k]){
							tmp=sort[i];
							sort[i]=sort[j];
							sort[j]=tmp;
							break;
						}
					}
				}
			}
			if(strcmp(sort[i].nom, sort[j].nom)==0){
				if(sort[i].prenom[0]<sort[j].prenom[0]) continue;
				else if(sort[i].prenom[0]>sort[j].prenom[0]){
					tmp=sort[i];
					sort[i]=sort[j];
					sort[j]=tmp;
				}
				len=maxlen(sort[i].prenom, sort[j].prenom);
				else if(sort[i].prenom[0]==sort[j].prenom[0]){
					for(int k=1; k<len; k++){
						if(sort[i].prenom[k]<sort[j].prenom[k]) break;
						if(sort[i].prenom[k]>sort[j].prenom[k]){
							tmp=sort[i];
							sort[i]=sort[j];
							sort[j]=tmp;
							break;
						}
					}
				}
			}
		}
		i++;
	}
	
	
	
	return sort;
}*/



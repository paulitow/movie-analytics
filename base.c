#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

void OuvertureBase(FILE* fp) {

	fprintf(stdout,"fp_OuvertureFichier: Begin\n");
	fp=fopen("database_2.csv","r+");
	if(fp==NULL)
	{
		fprintf(stdout,"Erreur ouverture fichier r+b\n");
		fp=fopen("database_2.csv","w+");
		if(fp==NULL)
		{
			fprintf(stdout,"Erreur ouverture fichier w+b. Sortie du programme\n");
			exit(-1);
		}
	}
	fprintf(stdout,"fp_OuvertureFichier: End\n");
}

void menu(FILE* base_menu) {

  int reponse = 0;
  Film recherche;
  char nom[60];

  do {

    memset(&recherche,0,sizeof(Film));
    printf("\n  BIENVENU SUR  \n");
    printf("\n  MOVIE ANALYTICS  \n");
    printf("      \n");
    printf("1. Rechercher un film\n");
    printf("2. Afficher les films par date, réalisateur...\n");
    printf("3. Afficher la moyenne des films par pays\n");
    printf("0. Sortir du programme\n");
	printf("4 : Lister la base\n");
    printf("\n Choix : \n");
    scanf("%d", &reponse);
    // Statistiques : calculer la moyenne de films par pays...

    switch (reponse) {

      case 0: break;
      case 1: 
        recherche_film(base_menu, nom); 
        break;
      case 2: 
        affiche_film(base_menu, &recherche); 
        break;
      case 3: 
        moyenne_pays(base_menu); 
        break;
      case 4:
        Lister_base(base_menu);
      default: 
        printf("Tapez une des commandes proposees");
    }
  }while(reponse != 0);
}
const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
            tok && *tok;
            tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}
void Lister_base(FILE* fp) {

	Film f1;
	//Film *f=&f1;
	fseek(fp,0,SEEK_SET);
	//filmtv_ID;film_title;year;genre;duration;country;director;actors;avg_vote;votes;
	//fscanf(fp, "%d;%s;%d;%s;%d;%s;%s;%s;%d;%d", &f1.id, f->titre, &f->annee, f->genre, &f->duree, f->pays, f->real, f->acteurs, &f->note, &f->nb_vote);
	//(*p).annee <==> p->annee
    //char line[500];
    //char *token;
	//fgets(line,1024,fp);
	//while(fgets(line,1024,fp)){
	//token = strtok(line, ";");
	//}//while
}

void recherche_film(FILE* base_recherche, char *nom) {

	Film film;
	int lire = 0, i = 0;

	if (base_recherche == NULL)

		printf("Erreur à l'ouverture\n");

	else {

			fseek(base_recherche,0,SEEK_SET);

			do {

				memset(&film,0,sizeof(Film));
				lire = fread(&film,sizeof(Film),1,base_recherche);

				if (lire) {

					if (strcmp(nom, film.titre)==0) {

						affiche_film(base_recherche, &film);
						//return film;
					}
					i++;
				}
			}while (!feof(base_recherche) && lire != 0);

			if (i == 0) printf("\nBase vide");

			else {
				printf("\nle film %s est inexistant !", nom);
				//return film;
			}
	} //return film;
}

void affiche_film(FILE *f, Film *film){

}

void moyenne_pays(FILE * f){

}
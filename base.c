#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

void OuvertureBase(FILE* fp) {

	fprintf(stdout,"fp_OuvertureFichier: Begin\n");
	fp=fopen("database.csv","r+b");
	if(fp==NULL)
	{
		fprintf(stdout,"Erreur ouverture fichier r+b\n");
		fp=fopen("database.csv","w+b");
		if(fp==NULL)
		{
			fprintf(stdout,"Erreur ouverture fichier w+b. Sortie du programme\n");
			exit(-1);
		}
	}
	fprintf(stdout,"fp_OuvertureFichier: End\n");
}

void Lister_base(FILE* fp) {

	Film f1;
	Film *f=&f1;
	fscanf(fp, "%d;%s;%d;%s;%d;%s;%s;%s;%d;%d", f->id, f->titre, f->duree);

}

void recherche_film(char *nom, FILE* base_recherche) {

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

						affiche_film(&nouveau);
						return film;
					}
					i++
				}
			}while (!feof(base_recherche) && lire != 0);

			if (i == 0) printf("\nBase vide");

			else {
				printf("\nle film %s est inexistant !", nom);
				return film;
			}
	} return film;
}

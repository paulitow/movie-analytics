#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movielib.h"

void OuvertureFichier(FILE** fp)
{
	fprintf(stdout,"fp_OuvertureFichier: Begin\n");

	*fp=fopen("dvdtheque.txt","r+b");
	if(*fp==NULL)
	{
		fprintf(stdout,"Erreur ouverture fichier r+b\n");

		*fp=fopen("dvdtheque.txt","w+b");
		if(*fp==NULL)
		{
			fprintf(stdout,"Erreur ouverture fichier w+b. Sortie du programme\n");
			exit(-1);
		}
	}
	fprintf(stdout,"fp_OuvertureFichier: End\n");
}

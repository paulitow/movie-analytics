#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

void OuvertureBase(FILE* fp)
{
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

void Lister_base(FILE* fp)
{
	Film f1;
	Film *f=&f1;
	fscanf(fp, "%d;%s;%d;%s;%d;%s;%s;%s;%d;%d", f->id, f->titre);

}

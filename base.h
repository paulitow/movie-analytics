#ifndef BASE_H
#define BASE_H
#include <stdio.h>
#include <string.h>


typedef struct {
  int id, duree, nb_vote, note, annee;
  char titre[60], genre[30], pays[15], real[60], acteurs[255];
} Film;

void OuvertureBase(FILE* fp);
#endif

void menu(FILE* fp);
void recherche_film(FILE* base_recherche, char *nom);
void affiche_film(FILE *f, Film *film);
void moyenne_pays(FILE * f);
void Lister_base(FILE* fp);
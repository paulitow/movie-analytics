#ifndef BASE_H
#define BASE_H
#include <stdio.h>
#include <string.h>

typedef struct {
  int id, duree, nb_vote, note;
  char titre[60], genre[30], pays[15], real[60], acteurs[255];
} Film;

void OuvertureBase(FILE* fp);
#endif

void menu(FILE* fp);
void recherche_film(char *nom, FILE* base_recherche);

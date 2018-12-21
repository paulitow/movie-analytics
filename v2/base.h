#ifndef BASE_H
#define BASE_H

typedef struct {
  int id, duree, nb_vote, note, annee;
  char titre[60], genre[30], pays[15], real[60], acteurs[255];
} Film;


void menu();
void init_bdd(FILE * f, int *n, Film *film);
int nb_ligne(FILE *f);


#endif // ne rien mettre après !
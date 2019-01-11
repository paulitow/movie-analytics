#ifndef BASE_H
#define BASE_H

typedef struct {
  int id, duree, nb_vote, note, annee;
  char titre[100], genre[30], pays[15], real[60], acteurs[255];
} Film;

typedef struct {
  char pays[15];
  int nombre_films;
} Pays;

void menu();
void menu_stat();
void menu_base();
int init_bdd(FILE * f, int *n, Film *film);
int nb_ligne(FILE *f);
void chercher_film(Film *film, char *nom, int *i);
int chercher_id_film(Film *film, char *nom, int *i);
void lister_film(Film *film, int arg, int *i);
void ajouter_film(FILE *f, Film *film, Film *new_film, int *i);
void creer_film(Film *new_film, int *id);
void supprimer_film(FILE *f , Film *del_film);
void extract_base(Film *film, int *i);
void ls_genre();
void ls_pays();
<<<<<<< HEAD
void stat_pays(Film *film, char *buffer, int nombre_elements);
=======
void stat_pays(Film *film, int nombre_elements);
>>>>>>> 77747c8db75f5fcec6ebb6b55207933a79f7a603
void bonus(); //???????????

#endif // ne rien mettre après !

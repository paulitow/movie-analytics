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

typedef struct {
  int year, nb_film, country;
} Annee;

void menu();
void menu_stat();
void menu_base();
void ls_genre();
void ls_pays();
int init_bdd(FILE * f, int *n, Film *film);
int nb_ligne(FILE *f);
void chercher_film(Film *film, char *nom, int *i);
int chercher_id_film(Film *film, char *nom, int *i);
void lister_film(Film *film, int arg, int *i);
void ajouter_film(FILE *f, Film *film, Film *new_film, int *i);
void creer_film(Film *new_film, int *id);
void supprimer_film(FILE *f , Film *del_film);
void extract_base(Film *film, int *i);
void evolution_sortie(Film *film, int from_year, int *i);

//void stat_pays(Film *film, char *buffer, int nombre_elements);
//void stat_pays(Film *film, int nombre_elements);
void bonus(); //???????????

#endif // ne rien mettre après !

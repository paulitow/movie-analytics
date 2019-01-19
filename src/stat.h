#ifndef USER_H
#define USER_H

typedef struct {
    int id, film_vu[50];
    char pseudo[30], genre_aime[30];
}User;
typedef struct {
  char nom_pays[200];
  int id_pays, nb_film;
} Pays_stat;

typedef struct {
  int year, nb_film, country;
  float x;
} Annee_evol;

void lister_film(Film *film, int arg, int *i);
void evolution_sortie(Film *film, int from_year, int for_year, int *i);
void global_stat(Film *film, int *i);
void trier_tb_c(Pays_stat *stat_country, int nb_pays);

#endif
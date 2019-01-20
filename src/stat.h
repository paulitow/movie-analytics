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
  char nom_genre[50];
  int id_genre, nb_film;
} Genre_stat;

typedef struct {
  int year, nb_film, country;
  float x;
} Annee_evol;

typedef struct {
  int year, nb_film;
  char genre[50];
} Annee_genre;

void lister_film(Film *film, int arg, int *i);
void evolution_sortie(Film *film, int from_year, int for_year, int *i);
void stat_genre(Film *film, int *i);
void global_stat(Film *film, int *i);
void trier_tb_pays(Pays_stat *stat_country, int nb_pays);
void trier_tb_genre(Genre_stat *stat_genre, int nb_genre);

#endif
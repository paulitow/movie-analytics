#ifndef BASE_H
#define BASE_H
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KRESET "\033[0m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
typedef struct {
  int id, duree, nb_vote, note, annee;
  char titre[200], genre[50], pays[200], real[100], acteurs[255];
} Film;

typedef struct {
  char pays[15];
  int nombre_films;
} Pays;



void menu();
void menu_stat();
void menu_base();
void ls_genre();
void ls_pays();
void splash();
int init_bdd(FILE * f, int *n, Film *film, int *id);
int nb_ligne(FILE *f);
void chercher_film(Film *film, char *nom, int *i);
int chercher_id_film(Film *film, char *nom, int *i);
void ajouter_film(FILE *f, Film *film, Film *new_film, int *i);
void creer_film(Film *new_film, int *id2, int *id);
void supprimer_film(FILE *f , Film *del_film);
void extract_base(Film *film, int *i);

void bonus(); //???????????

#endif // ne rien mettre après !

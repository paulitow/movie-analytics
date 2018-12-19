#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(FILE* base_menu) {

  int reponse = NULL;

  printf("\n  MOVIE ANALYTICS  \n");
  printf("      \n");
  printf("1. Rechercher un film\n");
  printf("2. Afficher les films par date, réalisateur");
  printf("3. Afficher le total des films par Pays");
  scanf("%d", &reponse);
// Statistiques : calculer la moyenne de films sortis par an...

  switch (reponse) {

    case 0: break;
    case 1: recherche_film(base); break;
    case 2: affiche_films(base); break;
    case 3: total_pays(base); break;
  }
}

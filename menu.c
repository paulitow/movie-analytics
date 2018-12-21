#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"


void menu(FILE* base_menu) {

  int reponse = 0;
  Film recherche;
  char nom[60];

  do {

    memset(&recherche,0,sizeof(Film));
    printf("\n  BIENVENU SUR  \n");
    printf("\n  MOVIE ANALYTICS  \n");
    printf("      \n");
    printf("1. Rechercher un film\n");
    printf("2. Afficher les films par date, réalisateur...");
    printf("3. Afficher la moyenne des films par pays");
    printf("0. Sortir du programme");
    printf("\n Choix : ");
    scanf("%d", &reponse);
    // Statistiques : calculer la moyenne de films par pays...

    switch (reponse) {

      case 0: break;
      case 1: recherche_film(base_menu); break;
      case 2: affiche_films(base_menu); break;
      case 3: moyenne_pays(base_menu); break;
      default: printf(Tapez une des commandes proposees);
    }
  }while(reponse != 0);
}

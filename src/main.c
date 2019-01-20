#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "stat.h"

/*####################V2.0###########################
              Projet Movie Analytics
    Auteurs : Paul Moyse - Damien Desmarets



*///#################################################

int main() {

  FILE* f = NULL;
  f=fopen("BDD_v2.csv", "r+");
  if(f==NULL){
      printf("Erreur d'ouverture de fichier !");
  }else{
      printf("Ouverture OK !\n");
  }
  int n=0, i=0,choix,choix2, id=0;
  char nom[50];
  n = nb_ligne(f);
  Film *f_bdd=NULL, *new_film=NULL;
  f_bdd = (Film*)malloc(sizeof(Film)*n); // On alloue la taille necessaire à l'init de la base
  new_film = (Film*)malloc(sizeof(Film));
  splash();
  do {
    menu(); // affichage simple du menu
    if (i<1){
        printf("\n--!! Attention !!--\n");
        printf("La base n'est pas initialisée ! Vous devriez le faire en tapant 1.\n");
    }
    scanf("%d", &choix);
    switch(choix){
        case 1: // initialisation de la base
            i=init_bdd(f, &n, f_bdd, &id); //  i=nb element dans base
        break;

        case 2: // Administration de la DB
            if (i!=0){
                menu_base();
                scanf("%d", &choix);
                switch(choix){
                    case 1: //Chercher film
                        printf("Entrez le nom du film recherché : \n");
                        scanf("%s", nom);
                        chercher_film(f_bdd, nom, &i);
                    break;

                    case 2: //ajouter film
                        f_bdd = (Film*)realloc(f_bdd, sizeof(Film)*i+1);
                        creer_film(new_film, &id, &i);
                        ajouter_film(f, f_bdd, new_film, &i);
                    break;

                    case 3:
                        extract_base(f_bdd, &i);
                    break;

                    default:
                    break;
                }//switch menu base
            } else{
                printf(KRED"Erreur "KRESET": la base n'est pas initialisée !\n");
            }    //if base init
        break; //break case menu base

        case 3: // STATISTIQUES
            if (i!=0){
                menu_stat();
                scanf("%d", &choix);
                switch(choix){
                    case 1: //Pays le plus cinéphile (production de film)
                        global_stat(f_bdd, &i);
                    break;

                    case 2: //Genre le mieux noté
                        stat_genre(f_bdd, &i);
                    break;

                    case 3: // évolution des sorties
                        printf("Saisisez l'année à partir de laquelle vous voulez calculer l'évolution (1 = 1911) :\n");
                        scanf("%d", &choix);
                        printf("Saisisez le nombre d'année à estimer : (1 = 5)\n");
                        scanf("%d", &choix2);
                        evolution_sortie(f_bdd, choix, choix2, &i);
                    break;

                    case 4: // lister par genre
                        lister_film(f_bdd, 0, &i);
                    break;

                    case 5: // lister par année
                        lister_film(f_bdd, 1, &i);
                    break;

                    case 6: // lister par pays
                        lister_film(f_bdd, 2 , &i);
                    break;
                }//switch menu base

            }else{
                printf(KRED"Erreur "KRESET": la base n'est pas initialisée !\n");
            }
        break; // break menu stat


        default:
        break;
    }
  }while(choix!=0);
  free(f_bdd); //C'est bon je te relache ! Va en paix mamen !
  fclose(f);
  printf("L'équipe Movie Analytics vous souhaite de bonnes fêtes !\n\n");
}

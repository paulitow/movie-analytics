#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "user.h"
/*#########################V1.0.1####################
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
  int n=0, i=0, id=0, annee=0,choix;
  char nom[50];
  n = nb_ligne(f);
  Film *f_bdd=NULL, *new_film=NULL;
  f_bdd = (Film*)malloc(sizeof(Film)*n); // On Alloue la taille necessaire à l'init de la base
  new_film = (Film*)malloc(sizeof(Film));
  do {
    menu(); // affichage simple du menu
    scanf("%d", &choix);
    switch(choix){
        case 1: // initialisation de la base
            i=init_bdd(f, &n, f_bdd); //  i=nb element dans base
        break;

        case 2: // Administration de la DB
            if (i!=0){
                menu_base();
                scanf("%d", &choix);
                switch(choix){
                    case 1: //Chercher film
                        printf("Entrez le nom du film à chercher : \n");
                        scanf("%s", nom);
                        chercher_film(f_bdd, nom, &i);
                    break;

                    case 2: //ajouter film
                        creer_film(new_film, &i);
                        ajouter_film(f, f_bdd, new_film, &i);
                    break;

                    case 3:
                        printf("Entrez le nom du film à chercher : \n");
                        scanf("%s", nom);
                        id=chercher_id_film(f_bdd, nom, &i);
                        printf("%d", id);
                    break;

                    case 4:
                        extract_base(f_bdd, &i);
                    break;
                }//switch menu base
            } else{
                printf("Erreur : la base n'est pas initialisée !\n");
            }    //if base init
        break; //break case menu base

        case 3: // STATISTIQUES
            if (i!=0){
                menu_stat();
                scanf("%d", &choix);
                switch(choix){
                    case 1: //Pays le plus cinéphile (production de film)
                        printf("Calcule en cours...");
                        //stat_pays(f_bdd, "France", i);
                    break;

                    case 2: //Genre le mieux noté
                        //stat_genre(); ???
                    break;

                    case 3: // évolution des sorties
                        //Prévision et calcul de la courbe des sorties
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
                printf("Erreur : la base n'est pas initialisée !\n");
            }
        break; // break menu stat

        case 4: //Panel user
            if (i!=0){
                printf("Non disponible dans cette version\n");
            }else{
                printf("Erreur : la base n'est pas initialisée !\n");
            }
        break;

        case 5:
            bonus();
        break;

        default:
        break;
    }
  }while(choix!=0);
  free(f_bdd); //C'est bon je te relache ! Va en paix mamen !
  printf("L'équipe Movie Analytics vous souhaite de bonnes fêtes !\n\n");
}

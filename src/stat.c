#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "stat.h"

 void lister_film(Film *film, int arg, int *i){
        char genre[50];
        Film best_film;
        int i2=0, rep=0, tmp=0, note=0;
        switch(arg){
            case 0: //Par genre
                i2=0;
                note=0;
                printf("Choix des genres :\n");
                printf("0 : Comédie\n");
                printf("1 : Drame\n");
                printf("2 : Thriller\n");
                printf("3 : Aventure\n");
                printf("4 : Action\n");
                printf("5 : Western\n");
                printf("6 : Horreur\n");
                printf("7 : Mythologie\n");
                printf("8 : Biographie\n");
                printf("9 : Musicale\n");
                printf("--------Choix ?---------\n");
                scanf("%d", &rep);
                switch(rep){
                    case 0:
                        strcpy(genre, "Comedy");
                    break;

                    case 1:
                        strcpy(genre, "Drama");
                    break;

                    case 2:
                        strcpy(genre, "Thriller");
                    break;

                    case 3:
                        strcpy(genre, "Adventure");
                    break;

                    case 4:
                        strcpy(genre, "Action");
                    break;

                    case 5:
                        strcpy(genre, "Western");
                    break;

                    case 6:
                        strcpy(genre, "Horror");
                    break;

                    case 7:
                        strcpy(genre, "Mythology");
                    break;

                    case 8:
                        strcpy(genre, "Biography");
                    break;

                    case 9:
                        strcpy(genre, "Musical");
                    break;
                }
                //une fois le genre initialiser, on peux référencer les films

                while(i2<=*i){
                    if (strcmp(genre, film[i2].genre)==0){
                        tmp++; //Compte le nombre de film du genre
                        if (film[i2].note>note){
                            best_film=film[i2];
                            note=film[i2].note;
                        }
                    }
                    i2++;
                }
                printf("Il y à %d film pour le genre %s\n", tmp, genre);
                printf("Le film le mieux noté de ce genre est :\n");
                printf("Titre : %s\n", best_film.titre);
                printf("Annee : %d\n", best_film.annee);
                printf("Genre : %s\n", best_film.genre);
                printf("Note : %d\n", best_film.note);
                printf("----------\n");

            break; //Fin recherche par genre

            case 1: //recherche par annee
                i2=0;
                note=0;
                printf("Entrez l'année recherchée :\n");
                scanf("%d", &rep);
                if (rep>2019){
                    printf("!! Eh Oh on peut pas aller plus vite que la musique !\n!! Regardes deja ceux de 2019 non ?\n");
                    rep=2019;
                } else if (rep<1911){
                    printf("Le cinéma n'était pas inventer à cette époque, un peu de patiente !\nVoici ceux pour 1911, la première année de la base :\n");
                    rep=1918;
                }
                while(i2<=*i){
                    if (film[i2].annee==rep){
                        tmp++; //Compte le nombre de film de cette année
                        if (film[i2].note>note){
                            best_film=film[i2];
                            note=film[i2].note;
                        }
                    }
                    i2++;
                }
                printf("Il y à %d film pour l'année %d\n", tmp, rep);
                printf("Le film le mieux noté de cette année est :\n");
                printf("Titre : %s\n", best_film.titre);
                printf("Annee : %d\n", best_film.annee);
                printf("Genre : %s\n", best_film.genre);
                printf("Note : %d\n", best_film.note);
                printf("----------\n");

            break;

            case 2: //recherche par pays
                i2=0;
                note=0;
                printf("Choix des pays :\n");
                printf("0 : France\n");
                printf("1 : Italie\n");
                printf("2 : USA\n");
                printf("3 : Allemagne\n");
                printf("4 : Suisse\n");
                printf("5 : Angleterre\n");
                printf("6 : Mexique\n");
                printf("7 : Russie\n");
                printf("8 : Suède\n");
                printf("9 : Canada\n");
                printf("--------Choix ?---------\n");
                scanf("%d", &rep);
                switch(rep){
                    case 0:
                        strcpy(genre, "France");
                    break;

                    case 1:
                        strcpy(genre, "Italy");
                    break;

                    case 2:
                        strcpy(genre, "United States");
                    break;

                    case 3:
                        strcpy(genre, "Germany");
                    break;

                    case 4:
                        strcpy(genre, "Switzerland");
                    break;

                    case 5:
                        strcpy(genre, "Great Britain");
                    break;

                    case 6:
                        strcpy(genre, "Mexico");
                    break;

                    case 7:
                        strcpy(genre, "Russia");
                    break;

                    case 8:
                        strcpy(genre, "Sweden");
                    break;

                    case 9:
                        strcpy(genre, "Canada");
                    break;
                }

                while(i2<=*i){
                    if (strcmp(film[i2].pays, genre)==0){ //la var s'appelle GENRE mais elle contient PAYS
                        tmp++; //Compte le nombre de film de cette année
                        if (film[i2].note>note){
                            best_film=film[i2];
                            note=film[i2].note;
                        }
                    }
                    i2++;
                }
                printf("Il y à %d film pour le pays %s\n", tmp, genre);
                printf("Le film le mieux noté de ce pays est :\n");
                printf("Titre : %s\n", best_film.titre);
                printf("Annee : %d\n", best_film.annee);
                printf("Genre : %s\n", best_film.genre);
                printf("Note : %d\n", best_film.note);
                printf("----------\n");
            break;
            default:
                printf("Mauvais arguments !");
            break;
        }
    }

// Evolution sortie : Methode de détermination de sortie de films par année
// Par régréssion linéaire

void evolution_sortie(Film *film, int from_year, int for_year, int *i) {
    if (from_year==1){
        from_year=2000;
    } else if(from_year<1911){
        from_year=1911;
        printf("1911 est la première année où il y a eu des films de réaliser.\n");
    }
    if (for_year==1){
        for_year=5;
    }
    Annee_evol *annee = NULL;
    int delta=0, i3=0, cpt_moy=0;
    float moyenne=0, prevision=0;

    delta=2018-from_year;
    printf("Calcul des prévision avec %d an(s) de données et sur %d an(s)\n", delta, for_year);
    annee=calloc(sizeof(Annee_evol), delta+1);
    annee[i3].x=1; // initialisation à 1 pour calcul de tendance première année
    while(delta>=0){
        annee[i3].year=from_year;
        for (int i2=0; i2<=*i; i2++) {
            if (film[i2].annee==from_year){
                (annee[i3].nb_film)++;
                if (i3!=0){ // on ne fait pas le calcul si on à pas le REX de l'année précédente
                    annee[i3].x=(((float)annee[i3].nb_film)/((float)annee[i3-1].nb_film));
                    
                }    
                //printf("Année %d || film : %s\n", from_year, film[i2].titre);
            }
        }
        printf("Pour l'année %d : %d Films | Tendance : %f",from_year,annee[i3].nb_film,annee[i3].x);
        if (annee[i3].x<1){
            printf(KRED"  V\n"KRESET);
        } else{
            printf(KGRN"  A\n"KRESET);
        }
        moyenne=(moyenne+annee[i3].x);
        cpt_moy++;
        from_year++;
        i3++;
        delta--;
    } // Fin while delta : 
    //on a fini de faire la moulinette pour chaques années, place au prévision !  
    
    moyenne=(moyenne/(float)cpt_moy);
    prevision=(annee[i3-1].nb_film*moyenne); // on fait dans la continuité de la dernière année
    printf("X prévisionnel : %f\n", moyenne);
    for (int cpt=0 ; cpt<for_year ; cpt++){
        printf("Pour %d : %.2f films sortiront.\n", from_year, prevision);
        prevision=(prevision*moyenne);   
        from_year++;
    }
    i3=0;
    
    free(annee);
    
}

void global_stat(Film *film, int *i){
    Pays_stat *country = NULL, *stat_country = NULL;
    char nom_pays[255];
    country=(Pays_stat*)malloc(sizeof(Pays_stat)*5000); // je ne sais pas à quoi m'attendre, je prends large !
    int nb_pays=0, occurence=0, nb_pays_stat=0;


    for (int i1=0 ; i1<*i ; i1++){ //Chaque film
        strcpy(nom_pays, strtok(film[i1].pays,","));
  
        for (int i2=0 ; i2<nb_pays ; i2++){ //on vérifie qu'on l'a pas en base, sinon, on l'enregistre
            if (strcmp(nom_pays, country[i2].nom_pays)==0){ //si correspondance, alors on ne fait rien
                occurence=1; // on l'a trouvé, il existe donc.
                country[i2].nb_film++;
            }
        }

        if (occurence!=1){ // si on ne l'a pas, on l'ajoute
            if (strlen(nom_pays)<=3){ // Mais on vérifie que ca n'est pas un nom degeu
                //printf(KRED " X "KRESET"| Je n'aime pas ce pays : %s\n", nom_pays);
            } else { //OK, là le pays est valable
                printf(KGRN" V "KRESET"| Nouveau pays : %s\n", nom_pays);
                country[nb_pays].id_pays=nb_pays+1;
                strcpy(country[nb_pays].nom_pays, nom_pays);
                country[nb_pays].nb_film=1;
                nb_pays++;
                }
        } else{
            occurence=0;
        }
    
    } // fin di traitement de chaques film


    printf("Total de pays réalisateur de films : %d\n", nb_pays);
    country=realloc(country, sizeof(Pays_stat)*nb_pays); // Maintenant que je sais le nombre de pays, j'adapte ma mémoire
    stat_country=malloc(sizeof(Pays_stat)*nb_pays); // et j'alloue (largement) le tableau final
    printf("Premier pays : %s ID : %d\n", country[0].nom_pays, country[0].id_pays);
    for (int i2=0 ; i2<nb_pays ; i2++){
        if (country[i2].nb_film>500){
            stat_country[nb_pays_stat].id_pays=country[i2].id_pays;
            stat_country[nb_pays_stat].nb_film=country[i2].nb_film;
            strcpy(stat_country[nb_pays_stat].nom_pays, country[i2].nom_pays);
            nb_pays_stat++;
        }
    }
    free(country); // on a fini le traitement, on libère la mémoire !
    stat_country=realloc(stat_country, sizeof(Pays_stat)*nb_pays_stat);//et on réalloue proprement notre tableau final
    //On passe au traitement d'affichage
    for (int i2=0 ; i2<nb_pays_stat ; i2++){
        printf("Pays : %s nb film : %d\n", stat_country[i2].nom_pays, stat_country[i2].nb_film);
    }
    free(stat_country);


}   
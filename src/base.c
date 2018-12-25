#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "user.h"
//#include "menu.c"

void menu(){ // affichage simple du menu
    printf("------MENU------\n");
    printf("1 : Initialiser la BDD\n");
    printf("2 : Administration de la base\n");
    printf("3 : Statistique\n");
    printf("4 : Panel Utilisateur\n");
    printf("5 : !! LE BONUS !!\n");
    printf("0 : Quitter...\n");
    printf("Votre choix ?\n");

}

void menu_stat(){
    printf("------STATISTIQUES------\n");
    printf("1 : Afficher le pays le plus cinéphile\n");
    printf("2 : Afficher le genre le mieux noté\n");
    printf("3 : Evolution des sorties\n");
    printf("4 : Lister les films par genre\n");
    printf("5 : Lister les films par année\n");
    printf("6 : Lister les films par pays\n");
    printf("0 : Quitter...\n");
    printf("Votre choix ?\n");
}

void menu_base(){
    printf("------DATABASE------\n");
    printf("1 : Rechercher un film\n");
    printf("2 : Ajouter un film\n");
    printf("3 : Récupérer l'ID d'un film\n");
    printf("4 : Sauvegarder la base dans un fichier CSV\n");
    printf("0 : Quitter...\n");
    printf("Votre choix ?\n");
}

int init_bdd(FILE * f, int *n, Film *film){ // retrourne le nombre d'éléments en base et init
    // filmtv_ID;film_title;year;genre;duration;country;director;actors;avg_vote;votes;
    char l[2555];
    char *o;
    int i=0;

    fseek(f,0,SEEK_SET);
    while(fgets(l, 2555, f)){ //Je ne sais pas si c'est la bonne valeur...
         
        (film+i)->id = atoi(strtok(l,";")); // ID
        printf("ID : %d\n", film[i].id);

        //printf("%s",strtok(NULL,";")); 
        strcpy((film+i)->titre,strtok(NULL,";"));// Titre
        printf("Titre : %s\n", film[i].titre);


        (film+i)->annee = atoi(strtok(NULL,";")); // Annee
        printf("Annee : %d\n", film[i].annee);

        strcpy((film+i)->genre,strtok(NULL,";"));// Genre
        printf("Genre : %s\n", film[i].genre);

        (film+i)->duree = atoi(strtok(NULL,";")); // Durée
        printf("Durée : %d\n", film[i].duree);

        strcpy((film+i)->pays,strtok(NULL,";"));// Pays
        printf("Pays : %s\n", film[i].pays);

        strcpy((film+i)->real,strtok(NULL,";"));// Réalisateur
        printf("Réalisateur : %s\n", film[i].real);

        strcpy((film+i)->acteurs,strtok(NULL,";"));// Acteurs
        printf("Acteurs : %s\n", film[i].acteurs);

        (film+i)->note = atoi(strtok(NULL,";")); // note moyenne
        printf("Note moyenne : %d\n", film[i].note);

        (film+i)->nb_vote = atoi(strtok(NULL,";")); // nombre de vote
        printf("Nombre de vote : %d\n", film[i].nb_vote);


        printf("----------\n");
        i++; // compteur tb de structure
    }
    printf("NB ligne fichier : %d\n", *n);
    printf("NB ligne strucutre : %d\n", i);
    if (i!=*n){
        printf("Erreur : Delta entre fichier et structure !!\n");
    }else{
        printf("Info : Base cohérente avec fichier\n");
    }
    printf("--Fin d'importation--\n");
    return i;
}

int nb_ligne(FILE *f){
    fseek(f,0,SEEK_SET);
    int n=0;
    char l[2555];
    while(fgets(l, 2555, f)){
        n++;
    }
    return n;
    
}

void chercher_film(Film *film, char *nom, int *i){
    int i2=0, nb_c=0;
    printf("OK, je vais chercher un film nommé %s sur %d éléments\n", nom, *i);
    while(i2<=*i){
        if (strcmp(nom, film[i2].titre)==0){
            printf("J'ai trouvé !\n");
            printf("ID : %d\n", film[i2].id);
            printf("Titre : %s\n", film[i2].titre);
            printf("Annee : %d\n", film[i2].annee);
            printf("Genre : %s\n", film[i2].genre);
            printf("----------\n");
            nb_c++;

        }
        i2++;
    }
    printf("Il y a %d correspondance(s)\n", nb_c);

}

int chercher_id_film(Film *film, char *nom, int *i){
    int i2=0, nb_c=0, id=0;
    printf("OK, je vais chercher un film nommé %s sur %d éléments\n", nom, *i);
    while(i2<=*i){
        if (strcmp(nom, film[i2].titre)==0){
            printf("J'ai trouvé !\n");
            printf("ID : %d\n", film[i2].id);
            printf("Titre : %s\n", film[i2].titre);
            printf("Annee : %d\n", film[i2].annee);
            printf("Genre : %s\n", film[i2].genre);
            printf("----------\n");
            id=film[i2].id;
            nb_c++;

        }
        i2++;
    }
    printf("Il y a %d correspondance(s)\n", nb_c);
    if (nb_c!=0){//il y à au moins 1 correspondance
        if (nb_c>1){//2 ou plus de correspondance
            printf("Il y à plusieurs correspondance, veuilez choisir l'ID :\n");
            scanf("%d", &id);
            return id;
        }else{ // qu'une seule corespondance
            return id;
        }
    }else{ //Pas de correspondance
        id=-1;//on indique une recherche nulle
        printf("Pas de film nommé %s", nom);
        return id;
    }

}

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
                if (rep>2018){
                    printf("!! Eh Oh on peut pas aller plus vite que la musique !\n!! Regarde deja ceux de 2018 non ?\n");
                    rep=2018;
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

    void ajouter_film(FILE *f,Film *film, Film *new_film, int *i){
        int choix, id;
        fseek(f,0,SEEK_END);
        printf("\n-------------Resumé-----------\n");
        printf("ID : %d\n", new_film->id);
        id=new_film->id;
        printf("Titre : %s\n", new_film->titre);
        printf("Année : %d\n", new_film->annee);
        printf("Genre : %s\n", new_film->genre);
        printf("Durée : %d\n", new_film->duree);
        printf("Pays : %s\n", new_film->pays);
        printf("Réalisateur : %s\n", new_film->real);
        printf("Acteurs : %s\n", new_film->acteurs);
        printf("Note : %d\n", new_film->note);
        printf("Nombre de vote : %d\n", new_film->nb_vote);
        printf("Voulez-vous importer ce film dans la base ?\n");
        printf("0 - NON || 1 - OUI\n");
        scanf("%d",&choix);
        switch(choix){
            case 0:
                printf("Abord mission !\n");
                free(new_film);
            break;
            case 1:
                film[id].id=new_film->id;
                strcpy(film[id].titre, new_film->titre);
                film[id].annee=new_film->annee;
                strcpy(film[id].genre, new_film->genre);
                film[id].duree=new_film->duree;
                strcpy(film[id].pays, new_film->pays);
                strcpy(film[id].real, new_film->real);
                strcpy(film[id].acteurs, new_film->acteurs);
                film[id].note=new_film->note;
                film[id].nb_vote=new_film->nb_vote;
                *i=id;
            break; // le film est ajouté !
        }
        printf("Voulez-vous sauvegarder la base dans le fichier CSV ?\n");
        printf("0 - NON || 1 - OUI\n");
        scanf("%d",&choix);
        switch(choix){
            case 0:
                printf("Vous travaillez donc sur une base non sauvegardée !\n");
            break;

            case 1:
                printf("Ajout au fichier...\n");
                fprintf(f,"%d;%s;%d;%s;%d;%s;%s;%s;%d;%d;\n",film[id].id,film[id].titre,film[id].annee,film[id].genre,film[id].duree,film[id].pays,film[id].real,film[id].acteurs,film[id].note,film[id].nb_vote);
            break;
        }    
    }

    void creer_film(Film *new_film, int *id){
        int choix, new_id=0;
        char genre[30];
        printf("-----création de film------\n");
        printf("Titre :");
        scanf("%s", new_film->titre);
        printf("%s", new_film->titre);
        printf("\nAnnée : ");
        scanf("%d", &(new_film)->annee);
        printf("%d", new_film->annee);
        ls_genre();
        scanf("%d", &choix);
        switch(choix){
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
        strcpy(new_film->genre, genre);
        printf("\nDurée : ");
        scanf("%d", &(new_film)->duree);
        ls_pays();
        scanf("%d", &choix);
        switch(choix){
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
        strcpy(new_film->pays, genre);
        printf("\nRéalisateur : ");
        scanf("%s", new_film->real);
        printf("\nActeurs : ");
        scanf("%s", new_film->acteurs);
        printf("\nNote moyenne : ");
        scanf("%d", &(new_film)->note);
        printf("\nNombre de vote : ");
        scanf("%d", &(new_film)->nb_vote);
        new_id = *id+1;
        new_film->id=new_id;

        

    }

    void ls_genre(){
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
    }

    void ls_pays(){
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
    }

    void supprimer_film(FILE *f , Film *del_film){ //A commleter
        int id;
        id=del_film->id;
        fseek(f,id,SEEK_SET);

    }

    void extract_base(Film *film, int *i){
        FILE *f_save=NULL;
        int id=0;
        f_save=fopen("./bdd_save.csv", "w+");
        while(id<*i){
            printf("Ajout au fichier du film %s...\n", film[id].titre);
                fprintf(f_save,"%d;%s;%d;%s;%d;%s;%s;%s;%d;%d;\n",film[id].id,film[id].titre,film[id].annee,film[id].genre,film[id].duree,film[id].pays,film[id].real,film[id].acteurs,film[id].note,film[id].nb_vote);
            id++;
        }
        printf("%d films sauvegardés dans le fichier bdd_save.csv !\n", id);
        fclose(f_save);
    }

    void evol_sortie(Film *film, int *i, int dep){
       int ecart=0, cpt_ecart=0, i2=0, i3=0;

       ecart=2018-dep;
       int sorties[ecart+1];
       cpt_ecart=ecart;

       while(cpt_ecart<2018){
           sorties[i3]=0;
           while(i2<*i){
               if (film[i2].annee==cpt_ecart){
                   sorties[i3]++;
               }
               i2++;
           }
           i2=0;
           i3++;
           cpt_ecart++;
        }
        cpt_ecart=2018-dep;
        i2=0;
        while(cpt_ecart<2018){
            printf("%d\n", sorties[i2]);
            i2++;
            cpt_ecart++;
        }
    }
void bonus(){

printf("               X   X   XXXXX   XXXXX   XXXXX   X   X\n");
printf("               XX XX   X       X   X   X   X    X X\n");
printf("               X X X   XXX     XXXXX   XXXXX     X\n");
printf("               X   X   X       X  X    X  X      X\n");
printf("               X   X   XXXXX   X   X   X   X     X\n");
printf("\n");
printf("\n");
printf("XXXXX   X   X   XXXXX   XXX   XXXXX   XXXXX   X   X   XXXXX   XXXXX\n");
printf("X       X   X   X   X    X    X         X     XX XX   X   X   X\n");
printf("X       XXXXX   XXXXX    X    XXXXX     X     X X X   XXXXX   XXXXX\n");
printf("X       X   X   X  X     X        X     X     X   X   X   X       X\n");
printf("XXXXX   X   X   X   X   XXX   XXXXX     X     X   X   X   X   XXXXX\n");


}
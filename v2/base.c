#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
//#include "menu.c"

void menu(){ // affichage simple du menu
    printf("------MENU------\n");
    printf("1 : Initialiser la BDD\n");
    printf("2 : Chercher un Film dans la base\n");
    printf("3 : Récupérer l'ID d'un film\n");
    printf("4 : Lister les films par genre\n");
    printf("5 : Calcul par département pour chaque question : du pourcentage de OUI et du pourcentage de NON\n");
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

    void lister_film(Film *film, int *arg, int *i){
        
        int i2=0, rep=0;
        switch(*arg){
            case 0: //Par genre
                printf("Choix des genres :\n");
                printf("0 : Comédie\n");
                printf("1 : Drame\n");
                printf("2 : Thriller\n");
                printf("3 : Aventure\n");
                printf("4 : Horreur\n");
                printf("5 : Western\n");
                printf("--------Choix ?---------");
                scanf("%d", &rep);

                while(i2<=*i){
                    if (strcmp("", film[i2].titre)==0){
                    }
                }    
            break;

            default:
                printf("Mauvais arguments !");
            break;
        }
    }
/*
void afficher_base(FILE *f){
    fseek(f,0,SEEK_SET);
    printf("NB ligne : %d", n);
    while(fgets(l, 255, f)){
        //printf("%s",l);
        o = strtok(l,";");
        while(o!=NULL){
            printf("%s\n",o);
            o = strtok(NULL,";");
        }
    }
}*/
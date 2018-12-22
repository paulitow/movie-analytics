#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
//#include "menu.c"

void menu(){ // affichage simple du menu
    printf("------MENU------\n");
    printf("1 : Initialiser la BDD\n");
    printf("2 : Ajout à la base d'informations existantes d'un fichier d'un nouveau point de manifestation\n");
    printf("3 : Calcul pour chaque question : du pourcentage de OUI et du pourcentage de NON\n");
    printf("4 : Calcul du nombre de gilets jaune par département\n");
    printf("5 : Calcul par département pour chaque question : du pourcentage de OUI et du pourcentage de NON\n");
    printf("0 : Quitter...\n");
    printf("Votre choix ?\n");

}

void init_bdd(FILE * f, int *n, Film *film){
    // filmtv_ID;film_title;year;genre;duration;country;director;actors;avg_vote;votes;
    char l[2555];
    char *o;
    
    int i=0;
    fseek(f,0,SEEK_SET);
    while(fgets(l, 2555, f)){
         
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
}
int nb_ligne(FILE *f){
    fseek(f,0,SEEK_SET);
    int n=0;
    char l[255];
    while(fgets(l, 255, f)){
        n++;
    }
    return n;
    
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
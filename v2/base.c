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
    char l[255];
    char *o;
    
    int i=0;
    fseek(f,0,SEEK_SET);
    printf("NB ligne : %d", *n);
    while(fgets(l, 255, f)){
         
        //printf("%s",strtok(l,";"));
        (film+i)->id = atoi(strtok(l,";"));
        printf(" ID : %d\n", film[i].id);
        //film[i].id = atoi(strtok(l,";"));
        //(f_base[i]->id)=strtok(l,";");
        printf("%s",strtok(NULL,";"));
        //strcpy((film+i)->titre, strtok(NULL,";"));

        (film+i)->annee = atoi(strtok(NULL,";"));
        printf("Annee : %d", film[i].annee);



        printf("----------\n");
        i++;
    }
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
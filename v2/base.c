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

void init_bdd(FILE * f){
    char l[255];
    char *o;
    while(fgets(l, 255, f)){
        //printf("%s",l);
        o = strtok(l,";");
        while(o!=NULL){
            printf("%s\n",o);
            o = strtok(NULL,";");
        }
    }
}


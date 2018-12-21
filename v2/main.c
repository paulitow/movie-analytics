#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
//#include "menu.c"

int main() {

  FILE* f = NULL;
  f=fopen("BDD_v2.csv", "r+");
  if(f==NULL){
      printf("Erreur d'ouverture de fichier !");
  }else{
      printf("Ouverture OK !\n");
  }
  int n=0;
  n = nb_ligne(f);
  Film *f_base[n];
  Film *f_bdd=NULL;
  f_bdd = (Film*)malloc(sizeof(Film)*n);

  int choix;
  do {
    menu();
    scanf("%d", &choix);
    switch(choix){
        case 1:
            init_bdd(f, &n, f_bdd);
        break;

        case 2:

        break;

        case 3:

        break;

        case 4:
        break;

        case 5:
        break;

        default:
        break;
    }
  }while(choix!=0);
}
#ifndef STRUCTURES_H
#define STRUCTURES_H
#define MAX_BUFF  20

#include <stdio.h>
#include <string.h>

typedef struct {

  int id;
  char nom;
  int annee;
  char genre;
  int duration;
  char pays;
  char realisateur;
  char acteur;
  float moyenne_notes;
  float nb_votes;
}film;

struct film = NULL;

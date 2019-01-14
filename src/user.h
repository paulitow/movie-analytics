#ifndef USER_H
#define USER_H

typedef struct {
    int id, film_vu[50];
    char pseudo[30], genre_aime[30];
}User;

void create_user(FILE *f_user, char *pseudo, int *con);
#endif
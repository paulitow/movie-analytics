#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "menu.c"

int main() {

  FILE* base = NULL;
  OuvertureBase(base);

  menu(base);

  if (base != NULL) {

    fclose(base);
    base = NULL;
  }
}

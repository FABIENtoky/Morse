#include "headers.h"

char** allouer2DChar (int nbT, int nbEPT) {
  
  int i;
  char** resultat;
  
  resultat = malloc (nbT * sizeof (char*));
  for (i = 0; i < nbT; i++) {
    *(resultat + i) = malloc (nbEPT * sizeof (char));
  }
  
  return resultat;
}

char** list () {

  int nbT = 26, nbEPT = 50;
  char** list = NULL;
  list = allouer2DChar (nbT, nbEPT);
  if (list == NULL) {exit (EXIT_FAILURE);}

  strcpy (list[0], "allo");
  strcpy (list[1], "bonaparte");
  strcpy (list[2], "cocacola");
  strcpy (list[3], "docile");
  strcpy (list[4], "eh");
  strcpy (list[5], "farandole");
  strcpy (list[6], "goldorak");
  strcpy (list[7], "hilarite");
  strcpy (list[8], "ici");
  strcpy (list[9], "jablonovo");
  strcpy (list[10], "koinor");
  strcpy (list[11], "limonade");
  strcpy (list[12], "moto");
  strcpy (list[13], "note");
  strcpy (list[14], "oporto");
  strcpy (list[15], "philosophe");
  strcpy (list[16], "qoqorico");
  strcpy (list[17], "ramoner");
  strcpy (list[18], "sardine");
  strcpy (list[19], "thon");
  strcpy (list[20], "union");
  strcpy (list[21], "valpareso");
  strcpy (list[22], "wagondor");
  strcpy (list[23], "xochimico");
  strcpy (list[24], "zorozizi");
  list[25] = NULL;

  return list;
}

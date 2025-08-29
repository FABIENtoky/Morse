#include "headers.h"
#define AUTHOR \
  proper_name ("Fabien T. Fandresena")

int main (int argc, char* argv[]) {

    char* option = argv[1];
    char* fichier = argv[2];

    if (argc != 3) {
        printf ("Utilisation : \n./exe [-OPTION] [FICHIER]\n");
        exit (0);
    }

    if ((strcmp (option, "-e") != 0) && (strcmp (option, "-d") != 0)) {
        printf ("Option invalide ! \n");
        exit (0);
    }

    if (strcmp (option, "-e") == 0) {
        printf ("ENCODAGE : \n");
        encodage (fichier);
    } else if (strcmp (option, "-d") == 0) {
        printf ("DECODAGE : \n");
        decodage (fichier);
    }

    return 0;
}
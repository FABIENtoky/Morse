#include "../header/headers.h"

int* transformChar (char lettre, int* nbCode) {

    char** liste = list ();
    char zero[] = "aieyu";
    char un[] = "o";
    int* morse = malloc (5 * sizeof (int));
    
    *nbCode = 0;
    for (int i = 0; liste[i] != NULL; i++) {
        if (lettre == liste[i][0]) {
            for (int j = 0; liste[i][j] != '\0'; j++) {
                if (strchr (zero, liste[i][j]) != NULL) {
                    morse[*nbCode] = 0;
                    (*nbCode)++;
                } else if (strchr (un, liste[i][j]) != NULL) {
                    morse[*nbCode] = 1;
                    (*nbCode)++;
                }
            }
        } else if (lettre == 'y') {
            morse[0] = 1;
            morse[1] = 0;
            morse[2] = 1;
            morse[3] = 1;
            *nbCode = 4;
            return morse;
        } else if (isdigit (lettre)) {
            int nombre = lettre - '0';
            morse = transformNumber (nombre);
            *nbCode = 5;
            return morse;
        }
    }

    return morse;
}

int* transformNumber (int number) {

    int* morse = malloc (5 * sizeof (int));
    int i;

    if ((number >= 0) && (number <= 4)) {
        for (i = 0; i < 5; i++) {
            morse[i] = 1;
        }
        for (i = 0; i < number; i++) {
            morse[i] = 0;
        }
    } else if ((number >= 5) && (number <= 9)) {
        for (i = 0; i < 5; i++) {
            morse[i] = 0;
        }
        for (i = 0; i < (number - 5); i++) {
            morse[i] = 1;
        }
    }

    return morse;
}

void transformChain (char* mot) {

    char lettre;
    int* morse = malloc (5 * sizeof (int));
    int nbCode;

    printf ("/");
    for (int i = 0; mot[i] != '\0'; i++) {
        lettre = mot[i];
        if (isupper (lettre)) {lettre = tolower (lettre);}
        morse = transformChar (lettre, &nbCode);
        for (int j = 0; j < nbCode; j++) {
            printf ("%d", morse[j]);
        }
        if (mot[i + 1] != '\0') {
            printf (" ");
        }
    }

    free (morse);
}

void encodage (char* fichier) {

    FILE* file = fopen (fichier, "r");
    if (file == NULL) {exit (EXIT_FAILURE);}
    char* word = malloc (128);
    int nbWord = 0;

    while (fscanf (file, "%s", word) == 1) {
        nbWord++;
        transformChain (word);
    }
    printf ("/\n");

    free (word);
    fclose (file);
}

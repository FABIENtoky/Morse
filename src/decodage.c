#include "../header/headers.h"

char transformCode (int* code, int size) {

    char liste[] = "abcdefghijklmnopqrstuvwxyz";

    int* morse = malloc (5 * sizeof (int));
    int nbCode;
    int equal = 1;
    
    for (int i = 0; liste[i] != '\0'; i++) {
        morse = transformChar (liste[i], &nbCode);
        if (nbCode != size) {
            equal = 0;
        } else {
            for (int j = 0; j < nbCode; j++) {
                if (morse[j] != code[j]) {
                    equal = 0;
                    break;
                } else if (morse[j] == code[j]) {
                    equal = 1;
                }
            }
        }
        if (equal == 1) {return liste[i];}
    }

}

void decodage (char* fichier) {

    FILE* file = fopen (fichier, "r");
    if (file == NULL) {exit (EXIT_FAILURE);}
    int* code = malloc (5 * sizeof (int));
    int single, size = 0;
    char lettre;

    while ((single = fgetc (file)) != EOF) {
        if (isdigit (single)) {
            code[size] = single - '0';
            size++;
        } else if (((single == ' ') || (single == '/')) && (size != 0)) {
            lettre = transformCode (code, size);
            printf ("%c", lettre);
            if (single == '/') {printf (" ");}
            size = 0;
        }
    }
    printf ("\n");

    free (code);
    fclose (file);
}

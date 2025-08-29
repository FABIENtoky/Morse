#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <math.h>

char** allouer2DChar (int nbT, int nbEPT);
char** list ();
int* transformChar (char lettre, int* nbCode);
int* transformNumber (int number);
void transformChain (char* mot);
void encodage (char* fichier);
char transformCode (int* code, int size);
void decodage (char* fichier);
#ifndef FICHIER_H_INCLUDED
#define FICHIER_H_INCLUDED

#include "case.h"
#include <stdio.h>
#include <stdlib.h>

extern void ecritureFichier(tCase mGrille[TAILLE][TAILLE],FILE *fic, const int nNumeroIteration);

#endif // FICHIER_H_INCLUDED

#include "fichier.h"
#include "case.h"

//BUT : Ecrire dans un fichier texte le nombre de cellules vivantes et le nombre de cellules mortes à chaque itération
//ENTREE : Tableau de tCase et fichier texte
//SORTIE : données saisies par le programme dans le fichier texte.

void ecritureFichier(tCase mGrille[TAILLE][TAILLE],FILE *fic, const int nNumeroIteration)
{
    int nCptX=0;
    int nCptY=0;
    int nCptVivantes=0;

    fprintf(fic,"Itération %d :\n",(nNumeroIteration+1));

    for (nCptX=0;nCptX<TAILLE;nCptX++)
    {
        for (nCptY=0;nCptY<TAILLE;nCptY++)
        {
            if (mGrille[nCptX][nCptY].Etat==vivante)
                nCptVivantes++;
        }
    }
    fprintf(fic,"Nombre de cellules vivantes : %d\n",nCptVivantes);
    fprintf(fic,"Nombre de cellules mortes : %d\n",((TAILLE*TAILLE)-nCptVivantes));
    fputs("\n",fic);
}

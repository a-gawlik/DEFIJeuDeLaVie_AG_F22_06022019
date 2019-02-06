#include <stdio.h>
#include <stdlib.h>
#include "case.h"
#include "fichier.h"

//BUT : Programme du jeu de la vie.
//ENTREES : Nombre d'itérations et taille de la grille (constantes dans case.h)
//SORTIE : affichage de toutes les itérations selon les règles du jeu de la vie

//--- PROGRAMME PRINCIPAL ---
int main()
{
    //Déclaration des variables
    tCase mGrille[TAILLE][TAILLE];
    int nCpt=0;
    FILE *fic = fopen("sauvegarde.txt","w");
    if (fic==NULL)
        exit(1);

    //Initialisation de la grille
    initGrille(mGrille);

    //disposition d'un planeur simple au sud-ouest allant vers le nord-est
    /*mGrille[TAILLE-3][1].Etat=vivante;
    mGrille[TAILLE-4][2].Etat=vivante;
    mGrille[TAILLE-4][3].Etat=vivante;
    mGrille[TAILLE-3][3].Etat=vivante;
    mGrille[TAILLE-2][3].Etat=vivante;*/

    //disposition d'une ligne de 10 formant un clignotant
    mGrille[TAILLE/2][(TAILLE/2)+4].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)+3].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)+2].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)+1].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)-1].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)-2].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)-3].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)-4].Etat=vivante;
    mGrille[TAILLE/2][(TAILLE/2)-5].Etat=vivante;

    printf("--- Position initiale : ---\n\n");
    affichageGrille(mGrille);
    printf("--- Lancement du programme : ---\n\n");


    //--- Boucle principale du programme ---
    for (nCpt=0;nCpt<NOMBRE_ITERATION;nCpt++)
    {
        verifVivanteAdjacentes(mGrille);
        preparationEtat(mGrille);
        changementEtat(mGrille);
        affichageGrille(mGrille);
        ecritureFichier(mGrille,fic,nCpt);
    }
    fclose(fic);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "case.h"

//BUT : initialiser toutes les cellules de mon tableau à etat=morte et secondEtat=devient_morte
//ENTREE : Tableau non initialisé
//SORTIE : Tableau initialisé
void initGrille (tCase mGrille[TAILLE][TAILLE])
{
    int nCptX=0;
    int nCptY=0;
    for (nCptX=0;nCptX<TAILLE;nCptX++)
    {
        for (nCptY=0;nCptY<TAILLE;nCptY++)
        {
            mGrille[nCptX][nCptY].Etat=morte;
            mGrille[nCptX][nCptY].SecondEtat=devient_morte;
            mGrille[nCptX][nCptY].nCptVivantes=0;
        }
    }
}

//BUT : afficher la grille sur la console en symbolisant les cases mortes par des 0 et les vivantes par 1
//ENTREE : Tableau de tCase
//SORTIE : affichage du tableau sur la console
void affichageGrille(tCase mGrille[TAILLE][TAILLE])
{
    int nCptX=0;
    int nCptY=0;
    for (nCptX=0;nCptX<TAILLE;nCptX++)
    {
        for (nCptY=0;nCptY<TAILLE;nCptY++)
        {
            if (mGrille[nCptX][nCptY].Etat==vivante)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//BUT : Vérifier pour chaque cellule le nombre de cases vivantes autour d'elle et stocker l'information dans la cellule.
//ENTREE : Tableau de cases
//SORTIE : Nombre de cellules vivantes proches pour chaque case
void verifVivanteAdjacentes (tCase mGrille[TAILLE][TAILLE])
{
    int nCptX=0;
    int nCptY=0;
    for (nCptX=0;nCptX<(TAILLE-1);nCptX++)
    {
        for (nCptY=0;nCptY<(TAILLE-1);nCptY++)
        {
            if (mGrille[nCptX-1][nCptY-1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX-1][nCptY].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX][nCptY-1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX-1][nCptY+1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX+1][nCptY-1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX][nCptY+1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX+1][nCptY].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
            if (mGrille[nCptX+1][nCptY+1].Etat==vivante)
            {
                mGrille[nCptX][nCptY].nCptVivantes++;
            }
        }
    }
}

//BUT : Prédire l'état d'une case à la prochaine itération. Il faut d'abord toutes les prédire et seulement ensuite les modifier afin de ne pas fausser les résultats.
//ENTREE : nb de cellules vivantes proches d'une case, pour toutes les cases de la grille
//SORTIE : Prévision de l'état au prochain tour : morte ou vivante
void preparationEtat (tCase mGrille[TAILLE][TAILLE])
{
    int nCptX=0;
    int nCptY=0;
    for (nCptX=0;nCptX<TAILLE;nCptX++)
    {
        for (nCptY=0;nCptY<TAILLE;nCptY++)
        {
            if (mGrille[nCptX][nCptY].Etat==vivante)
            {
                if ((mGrille[nCptX][nCptY].nCptVivantes==2)||(mGrille[nCptX][nCptY].nCptVivantes==3))
                {
                    mGrille[nCptX][nCptY].SecondEtat=devient_vivante;
                }
                else
                {
                    mGrille[nCptX][nCptY].SecondEtat=devient_morte;
                }
            }
            else
            {
                if (mGrille[nCptX][nCptY].nCptVivantes==3)
                {
                   mGrille[nCptX][nCptY].SecondEtat=devient_vivante;
                }
                else
                {
                    mGrille[nCptX][nCptY].SecondEtat=devient_morte;
                }
            }
        }
    }
}

//BUT : Changer toutes les valeurs du tableau à leur prochain etat et réinitialiser le compteur de cellules vivantes adjacentes
//ENTREE : etat prévisualisé pour chaque cellule
//SORTIE : Etat final pour chaque cellule + cpt réinitialisé
void changementEtat (tCase mGrille[TAILLE][TAILLE])
{
    int nCptX=0;
    int nCptY=0;
    for (nCptX=0;nCptX<TAILLE;nCptX++)
    {
        for (nCptY=0;nCptY<TAILLE;nCptY++)
        {
            if (mGrille[nCptX][nCptY].SecondEtat==devient_vivante)
            {
                mGrille[nCptX][nCptY].Etat=vivante;
            }
            else
            {
                mGrille[nCptX][nCptY].Etat=morte;
            }
            mGrille[nCptX][nCptY].nCptVivantes=0;
        }
    }
}

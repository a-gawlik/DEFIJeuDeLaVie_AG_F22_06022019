#include <stdio.h>
#include <stdlib.h>
#include "case.h"

//BUT : initialiser toutes les cellules de mon tableau � etat=morte et secondEtat=devient_morte
//ENTREE : Tableau non initialis�
//SORTIE : Tableau initialis�
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

//BUT : V�rifier pour chaque cellule le nombre de cases vivantes autour d'elle et stocker l'information dans la cellule.
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

//BUT : Pr�dire l'�tat d'une case � la prochaine it�ration. Il faut d'abord toutes les pr�dire et seulement ensuite les modifier afin de ne pas fausser les r�sultats.
//ENTREE : nb de cellules vivantes proches d'une case, pour toutes les cases de la grille
//SORTIE : Pr�vision de l'�tat au prochain tour : morte ou vivante
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

//BUT : Changer toutes les valeurs du tableau � leur prochain etat et r�initialiser le compteur de cellules vivantes adjacentes
//ENTREE : etat pr�visualis� pour chaque cellule
//SORTIE : Etat final pour chaque cellule + cpt r�initialis�
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

#ifndef CASE_H_INCLUDED
#define CASE_H_INCLUDED

#define TAILLE 30
#define NOMBRE_ITERATION 20

enum etat {morte,vivante};
enum secondEtat {devient_vivante,devient_morte};

typedef struct tCase{
    enum etat Etat;
    enum secondEtat SecondEtat;
    int nCptVivantes;
}tCase;

// --- PROTOTYPES ---

extern void initGrille (tCase mGrille[TAILLE][TAILLE]);
extern void affichageGrille(tCase mGrille[TAILLE][TAILLE]);
extern void verifVivanteAdjacentes (tCase mGrille[TAILLE][TAILLE]);
extern void preparationEtat(tCase mGrille[TAILLE][TAILLE]);
extern void changementEtat (tCase mGrille[TAILLE][TAILLE]);

#endif // CASE_H_INCLUDED

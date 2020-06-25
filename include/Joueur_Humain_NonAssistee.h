#ifndef JOUEUR_HUMAIN_NONASSISTEE_H
#define JOUEUR_HUMAIN_NONASSISTEE_H
#include <iostream>
#include "Joueur.h"

using namespace std;

class Joueur_Humain_NonAssistee:public Joueur
{
    public:
        void insererValeurNonAssistee(Sudoku& sudoku);
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // JOUEUR_HUMAIN_NONASSISTEE_H

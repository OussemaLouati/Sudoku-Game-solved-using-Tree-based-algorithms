#ifndef JOUEUR_HUMAIN_ASSISTE_H
#define JOUEUR_HUMAIN_ASSISTE_H
#include <iostream>
#include "Joueur.h"

using namespace std;

class Joueur_Humain_Assiste:public Joueur
{
    public:
        void insererValeurAssistee(Sudoku& sudoku);
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // JOUEUR_HUMAIN_ASSISTE_H

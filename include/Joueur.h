#ifndef JOUEUR_H
#define JOUEUR_H
#include "windows.h"
#include "Sudoku.h"
class Joueur
{
    public:
        virtual bool resoudreGrille(Sudoku& sudoku)=0;
};

#endif // JOUEUR_H

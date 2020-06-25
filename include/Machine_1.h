#ifndef MACHINE_1_H
#define MACHINE_1_H
#include "Joueur.h"

class Machine_1:public Joueur
{
    public:
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // MACHINE_1_H

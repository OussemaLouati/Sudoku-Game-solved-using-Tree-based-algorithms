#ifndef MACHINE_2_H
#define MACHINE_2_H
#include "Joueur.h"

class Machine_2:public Joueur
{
    public:
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // MACHINE_2_H

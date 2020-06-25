#ifndef MACHINE_3_H
#define MACHINE_3_H
#include <queue>
#include "Joueur.h"

class Machine_3:public Joueur
{
    public:
        queue<Sudoku*> file;
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // MACHINE_3_H

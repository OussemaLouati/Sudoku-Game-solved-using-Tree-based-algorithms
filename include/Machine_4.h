#ifndef MACHINE_4_H
#define MACHINE_4_H
#include <stack>
#include "Joueur.h"
#include "Cases_Simples.h"
class Machine_4:public Joueur
{
    public:
        stack<Cases_Simples> pile ;
        bool resoudreGrille(Sudoku& sudoku);
};

#endif // MACHINE_4_H

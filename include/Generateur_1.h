#ifndef GENERATEUR_1_H
#define GENERATEUR_1_H
#include <ctime>
#include <cstdlib>
#include "Generateur.h"

class Generateur_1:public Generateur
{
    public:
        bool remplirGrille(Sudoku& sudoku);
        Sudoku genererGrille();
};

#endif // GENERATEUR_1_H

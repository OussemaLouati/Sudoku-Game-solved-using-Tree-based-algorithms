#ifndef GENERATEUR_2_H
#define GENERATEUR_2_H
#include <ctime>
#include <cstdlib>
#include "Generateur.h"

class Generateur_2:public Generateur
{
    public:
        bool remplirGrille(Sudoku& sudoku);
        Sudoku genererGrille();
};

#endif // GENERATEUR_2_H

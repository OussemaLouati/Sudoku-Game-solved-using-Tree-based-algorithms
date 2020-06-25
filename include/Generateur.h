#ifndef GENERATEUR_H
#define GENERATEUR_H
#include "Sudoku.h"

class Generateur
{
    public:
        virtual Sudoku genererGrille()=0;
};

#endif // GENERATEUR_H

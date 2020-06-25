#ifndef GENERATEUR_SAISIE_H
#define GENERATEUR_SAISIE_H
#include <iostream>
#include "Generateur.h"

using namespace std;

class Generateur_Saisie:public Generateur
{
    public:
        Sudoku genererGrille();
};

#endif // GENERATEUR_SAISIE_H

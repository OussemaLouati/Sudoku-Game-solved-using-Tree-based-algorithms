#ifndef PARTIE_H
#define PARTIE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <typeinfo>
#include "windows.h"
#include "Sudoku.h"
#include "Joueur_Humain_Assiste.h"
#include "Joueur_Humain_NonAssistee.h"
#include "Machine_1.h"
#include "Machine_2.h"
#include "Machine_3.h"
#include "Machine_4.h"
#include "Generateur_1.h"
#include "Generateur_Saisie.h"

class Partie
{
    public:
        Partie();
        Joueur *joueur;
        Generateur *generateur;
        Sudoku sudoku;
        void choixTypePartie();
        void choixJoueur();
        Sudoku reprendrePartie();
        void sauvegarderPartie(Sudoku sudoku);
        void commencerPartie();
};

#endif // PARTIE_H

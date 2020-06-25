#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <termcolor.hpp>
#include "Coup.h"
#include "Cases.h"
using namespace std;

class Sudoku
{
    Cases Grille[9][9];
    public:
        Sudoku(){};
        Sudoku(Sudoku&);
        Cases getCase(int ligne,int colonne);
        void setValeurCase(int ligne,int colonne,int nombre);
        void setTypeCase(int ligne,int colonne,typeCase type);
        void setPossibilitesCase(int ligne,int colonne,int nombre);
        Coup *coup;
        bool existeSurLigne(int nombre,int ligne);
        bool existeSurColonne(int nombre,int colonne);
        bool existeSurBloc(int nombre,int ligneDeb,int colonneDeb);
        bool nombrePossible(int nombre,int ligne,int colonne);
        bool trouverCaseVide(int &lig,int &col);
        void verifierInputHumain(std::string input);
        bool verifierRemplissage();
        bool grilleRemplisse();
        void candidats(int lig,int col);
        friend ostream& operator<<(ostream& flux,Sudoku& sudoku);
};


#endif // SUDOKU_H

#include "Generateur_Saisie.h"

Sudoku Generateur_Saisie::genererGrille()
{
    Sudoku sudoku;
    int valeur;
    cout<<"Tapez les valeurs des cases:"<<endl;
    for (int ligne=0;ligne<9;ligne++)
    {
        for (int colonne=0;colonne<9;colonne++)
        {
            do
            {
                cin>>valeur;
                sudoku.setValeurCase(ligne,colonne,valeur);
            }while((valeur>9) || (valeur<0));
        }
    }
    for (int ligne=0;ligne<9;ligne++)
    {
        for (int colonne=0;colonne<9;colonne++)
        {
            if(sudoku.getCase(ligne,colonne).valeur==0)
                sudoku.setTypeCase(ligne,colonne,VIDE);
            else
                sudoku.setTypeCase(ligne,colonne,ORIGINALE);
        }
    }
    return sudoku;
}

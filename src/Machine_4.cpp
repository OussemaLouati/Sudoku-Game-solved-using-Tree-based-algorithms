#include "Machine_4.h"

bool Machine_4::resoudreGrille(Sudoku& sudoku)
{
    int ligne=0,colonne=0;
    Cases_Simples c1,c2;
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    else
    {
        sudoku.candidats(ligne,colonne);
        for(unsigned int i=0;i<sudoku.getCase(ligne,colonne).possibilites.size();i++)
        {
            c2.ligne=ligne ;
            c2.colonne=colonne ;
            c2.valeur=sudoku.getCase(ligne,colonne).possibilites[i];
            pile.push(c2) ;
        }
    }
    if(pile.empty())
        return false;
    c1=pile.top();
    sudoku.setValeurCase(c1.ligne,c1.colonne,c1.valeur);
    sudoku.setTypeCase(c1.ligne,c1.colonne,NOUVELLE);
    pile.pop();
    cout<<sudoku<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    Sleep(1000);
    if(resoudreGrille(sudoku))
        return true;
}

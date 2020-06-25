#include "Machine_2.h"
bool Machine_2::resoudreGrille(Sudoku& sudoku)
{
    int ligne=0,colonne=0;
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    sudoku.candidats(ligne,colonne);
    for(unsigned int i=0;i<sudoku.getCase(ligne,colonne).possibilites.size();i++){
        if(sudoku.nombrePossible(sudoku.getCase(ligne,colonne).possibilites[i],ligne,colonne))
        {
            sudoku.setValeurCase(ligne,colonne,sudoku.getCase(ligne,colonne).possibilites[i]);
            sudoku.setTypeCase(ligne,colonne,NOUVELLE);
            cout<<sudoku<<endl<<endl;
            cout<<"-------------------------------"<<endl<<endl;
            Sleep(1000);
            if (resoudreGrille(sudoku))
                return true;
        }
        sudoku.setValeurCase(ligne,colonne,0);
    }
    return false;
}

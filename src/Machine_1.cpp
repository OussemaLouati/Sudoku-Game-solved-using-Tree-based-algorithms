#include "Machine_1.h"

bool Machine_1::resoudreGrille(Sudoku& sudoku)
{
    int nombre,ligne=0,colonne=0;
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    for (nombre=1;nombre<=9;nombre++)
    {
        if(sudoku.nombrePossible(nombre,ligne,colonne))
        {
            sudoku.setValeurCase(ligne,colonne,nombre);
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

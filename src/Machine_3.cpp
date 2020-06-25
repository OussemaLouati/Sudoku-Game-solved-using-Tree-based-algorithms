#include "Machine_3.h"

bool Machine_3::resoudreGrille(Sudoku& sudoku)
{
    int ligne=0,colonne=0;
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    else
    {
        sudoku.candidats(ligne,colonne);
        for(unsigned int i=0;i<sudoku.getCase(ligne,colonne).possibilites.size();i++)
        {
            Sudoku *sudoku_a_enfiler;
            sudoku_a_enfiler = new Sudoku();
            *sudoku_a_enfiler=sudoku ;
            sudoku_a_enfiler->setValeurCase(ligne,colonne,sudoku.getCase(ligne,colonne).possibilites[i]);
            sudoku_a_enfiler->setTypeCase(ligne,colonne,NOUVELLE);
            file.push(sudoku_a_enfiler);
        }
    }
    if(file.empty())
        return false;
    sudoku=*file.front();
    file.pop();
    cout<<sudoku<<endl<<endl;
    cout<<"-------------------------------"<<endl<<endl;
    Sleep(1000);
    if(resoudreGrille(sudoku))
        return true;
}

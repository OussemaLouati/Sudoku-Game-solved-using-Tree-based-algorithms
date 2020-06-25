#include "Generateur_2.h"

bool Generateur_2::remplirGrille(Sudoku& sudoku)
{
    time_t horloge;
    int valeur,ligne=0,colonne=0;
    srand(time(&horloge));
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    do
    {
        valeur=rand()%9 + 1;
        if(sudoku.nombrePossible(valeur,ligne,colonne))
            sudoku.setValeurCase(ligne,colonne,valeur);
        cout<<sudoku<<endl;
    }while(!sudoku.nombrePossible(valeur,ligne,colonne));
    if(remplirGrille(sudoku))
        return true;
}

Sudoku Generateur_2::genererGrille()
{
    time_t horloge;
    int ligne,colonne,casesSupprimees,choixDifficulte;
    Sudoku sudoku;
    srand(time(&horloge));
    for(int ligne=0;ligne<9;ligne++)
    {
        for(int colonne=0;colonne<9;colonne++)
        {
            sudoku.setValeurCase(ligne,colonne,0);
        }
    }
    remplirGrille(sudoku);
    do
    {
        cin>>choixDifficulte;
        switch(choixDifficulte)
        {
            case 1:
                casesSupprimees=12;
                break;
            case 2:
                casesSupprimees=25;
                break;
            case 3:
                casesSupprimees=38;
                break;
            case 4:
                casesSupprimees=50;
                break;
            default:
                cout<<"Erreur du choix de difficulte"<<endl;
                break;
        }
    }while(choixDifficulte>4);
    while(casesSupprimees!=0)
    {
        ligne=(rand()%9)+1;
        colonne=(rand()%9)+1;
        if(sudoku.getCase(ligne,colonne).valeur!=0)
        {
            sudoku.setValeurCase(ligne,colonne,0);
            casesSupprimees--;
        }
    }
    for(int ligne=0;ligne<9;ligne++)
    {
        for(int colonne=0;colonne<9;colonne++)
        {
            if(sudoku.getCase(ligne,colonne).valeur==0)
                sudoku.setTypeCase(ligne,colonne,VIDE);
            else
                sudoku.setTypeCase(ligne,colonne,ORIGINALE);
        }
    }
    return sudoku;
}

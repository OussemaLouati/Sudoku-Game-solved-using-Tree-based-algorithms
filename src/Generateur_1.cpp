#include "Generateur_1.h"

bool Generateur_1::remplirGrille(Sudoku& sudoku)
{
    int ligne=0,colonne=0,nombre;
    if(!sudoku.trouverCaseVide(ligne,colonne))
        return true;
    for (nombre=1;nombre<=9;nombre++)
    {
        if(sudoku.nombrePossible(nombre,ligne,colonne))
        {
            (sudoku.setValeurCase(ligne,colonne,nombre));
            if (remplirGrille(sudoku))
                return true;
        }
        (sudoku.setValeurCase(ligne,colonne,0));
    }
    return false;
}

Sudoku Generateur_1::genererGrille()
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
            sudoku.setTypeCase(ligne,colonne,VIDE);
        }
    }
    sudoku.setValeurCase(0,0,(rand()%9)+1);
    sudoku.setValeurCase(4,4,(rand()%9)+1);
    sudoku.setValeurCase(8,8,(rand()%9)+1);
    remplirGrille(sudoku);
    do
    {
        cout<<"Choisir une difficulte:"<<endl<<endl;
        cout<<"(1) Niveau 1"<<endl<<"(2) Niveau 2"<<endl<<"(3) Niveau 3"<<endl<<endl;
        cin>>choixDifficulte;
        switch(choixDifficulte)
        {
            case 1:
                casesSupprimees=(rand()%5)+5;
                break;
            case 2:
                casesSupprimees=(rand()%11)+10;
                break;
            case 3:
                casesSupprimees=(rand()%12)+20;
                break;
            default:
                cout<<"Erreur du choix de difficulte"<<endl;
                break;
        }
    }while(choixDifficulte>3);
    while(casesSupprimees!=0)
    {
        ligne=rand()%9;
        colonne=rand()%9;
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


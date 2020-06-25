#include "Joueur_Humain_Assiste.h"

void Joueur_Humain_Assiste::insererValeurAssistee(Sudoku& sudoku)
{
    if(((sudoku.coup)->ligne<0) || ((sudoku.coup)->ligne>8) || ((sudoku.coup)->colonne<0) || ((sudoku.coup)->colonne>8) || ((sudoku.coup)->valeur<0) || ((sudoku.coup)->valeur>9))
       cout<<"Erreur du coup"<<endl;
    else
    {
        if((sudoku.getCase((sudoku.coup)->ligne,(sudoku.coup)->colonne).type==NOUVELLE) || (sudoku.getCase((sudoku.coup)->ligne,(sudoku.coup)->colonne).type==VIDE))
        {
            if(sudoku.nombrePossible((sudoku.coup)->valeur,(sudoku.coup)->ligne,(sudoku.coup)->colonne))
            {
                sudoku.setValeurCase((sudoku.coup)->ligne,(sudoku.coup)->colonne,(sudoku.coup)->valeur);
                sudoku.setTypeCase((sudoku.coup)->ligne,(sudoku.coup)->colonne,NOUVELLE);
            }
            else
                cout<<"Nombre non possible pour cette case"<<endl;
        }
        else
            cout<<"Case originale"<<endl;
    }
}

bool Joueur_Humain_Assiste::resoudreGrille(Sudoku& sudoku)
{
    std::string input;
    do
    {
        do
        {
            cout<<"Taper coup ou quit"<<endl<<endl;
            cin>>input;
            if((input.compare("quit")!=0) && (input.compare("coup")!=0))
                cout<<"Input invalide"<<endl<<endl;
        }while((input.compare("quit")!=0) && (input.compare("coup")!=0));
        cout<<endl;
        if(input.compare("quit")==0)
            return false;
        sudoku.verifierInputHumain(input);
        if(sudoku.coup != NULL)
        {
            cout<<sudoku.coup->ligne<<" "<<sudoku.coup->colonne<<" "<<sudoku.coup->valeur<<endl;
            insererValeurAssistee(sudoku);
            cout<<sudoku<<endl;
            if(sudoku.grilleRemplisse())
            {
                cout<<"Terminee"<<endl<<endl;
                return true;
            }
        }
    }while(1);
}

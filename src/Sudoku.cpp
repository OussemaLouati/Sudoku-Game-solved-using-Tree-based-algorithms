#include "Sudoku.h"
Cases Sudoku::getCase(int ligne,int colonne)
{
    return Grille[ligne][colonne];
}
bool Sudoku::existeSurLigne(int nombre,int ligne)
{
    for (int colonne = 0; colonne < 9; colonne++)
        if (getCase(ligne,colonne).valeur == nombre)
            return true;
    return false;
}
bool Sudoku::existeSurColonne(int nombre,int colonne)
{
    for (int ligne = 0; ligne < 9; ligne++)
        if (getCase(ligne,colonne).valeur == nombre)
            return true;
    return false;
}
bool Sudoku::existeSurBloc(int nombre,int ligneDeb,int colonneDeb)
{
    for (int ligne = 0; ligne < 3; ligne++)
        for (int colonne = 0; colonne < 3; colonne++)
            if (getCase(ligne+ligneDeb,colonne+colonneDeb).valeur == nombre)
                return true;
    return false;
}
bool Sudoku::nombrePossible(int nombre,int ligne,int colonne)
{
    return !existeSurLigne(nombre,ligne) &&
           !existeSurColonne(nombre,colonne) &&
           !existeSurBloc(nombre,ligne-ligne%3,colonne-colonne%3);
}
bool Sudoku::trouverCaseVide(int& ligne,int& colonne)
{
    for (ligne = 0; ligne < 9; ligne++)
        for (colonne = 0; colonne < 9; colonne++)
            if (getCase(ligne,colonne).valeur == 0)
                return true;
    return false;
}
ostream& operator<<(ostream& flux,Sudoku& sudoku)
{
    flux<<"   -------------------------"<<endl;
    for (int ligne=0;ligne<9;ligne++)
    {
        flux<<"   ";
        for (int colonne=0;colonne<9;colonne++)
        {
            if(colonne==0)
                flux<<"| ";
            if ((sudoku.Grille[ligne][colonne]).valeur==0)
                flux<<"  ";
            else
            {
                if((sudoku.Grille[ligne][colonne]).type==ORIGINALE)
                    flux<<termcolor::red<<(sudoku.Grille[ligne][colonne]).valeur<<termcolor::reset<<" ";
                else
                    flux<<termcolor::green<<(sudoku.Grille[ligne][colonne]).valeur<<termcolor::reset<<" ";
            }
            if ((colonne+1)%3 == 0)
                flux<<"| ";
        }
        if ((ligne+1)%3 == 0)
            flux<<endl<<"   -------------------------";
        flux<<endl;
    }
    return flux;
}

bool Sudoku::verifierRemplissage()
{
    for(int ligne=0;ligne<9;ligne++)
    {
        for(int colonne=0;colonne<9;colonne++)
        {
            if(!nombrePossible(Grille[ligne][colonne].valeur,ligne,colonne))
                return false;
        }
    }
    return true;
}

bool Sudoku::grilleRemplisse()
{
    int casesRemplisses=0;
    for(int ligne=0;ligne<9;ligne++)
    {
        for(int colonne=0;colonne<9;colonne++)
        {
            if(getCase(ligne,colonne).valeur!=0)
                casesRemplisses++;
        }
    }
    if(casesRemplisses==81)
        return true;
    else
        return false;
}

void Sudoku::verifierInputHumain(std::string input)
{
    coup = new Coup();
    cout<<"Ligne: ";
    cin>>coup->ligne;
    cout<<"Colonne: ";
    cin>>coup->colonne;
    cout<<"Valeur: ";
    cin>>coup->valeur;
}


Sudoku::Sudoku(Sudoku& sudoku)
{
    for(int ligne=0;ligne<9;ligne++)
    {
        for(int colonne=0;colonne<9;colonne++)
        {
            setValeurCase(ligne,colonne,sudoku.getCase(ligne,colonne).valeur);
            setTypeCase(ligne,colonne,sudoku.getCase(ligne,colonne).type);
        }
    }
}

 void Sudoku::candidats(int ligne,int colonne)
{
    for(int nombre=1;nombre<=9;nombre++)
        if(nombrePossible(nombre,ligne,colonne))
           setPossibilitesCase(ligne,colonne,nombre);
}

void Sudoku::setValeurCase(int ligne,int colonne,int nombre)
{
    Grille[ligne][colonne].valeur=nombre;
}
void Sudoku::setTypeCase(int ligne,int colonne,typeCase type)
{
    Grille[ligne][colonne].type=type;
}
void Sudoku::setPossibilitesCase(int ligne,int colonne,int nombre)
{
    Grille[ligne][colonne].possibilites.push_back(nombre);
}

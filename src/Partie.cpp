#include "Partie.h"
Partie::Partie()
{
    choixJoueur();
}

Sudoku Partie::reprendrePartie()
{
    int test;
    do{
    int ligne,colonne,valeur,type;
    Sudoku sudoku;
    std::string chemin;
    cout<<"Tapez le chemin:"<<endl<<endl;
    cin>>chemin;
    ifstream fichier (chemin.c_str());
    if (fichier.is_open())
    {
        while(fichier>>ligne>>colonne>>valeur>>type)
        {
            sudoku.setValeurCase(ligne,colonne,valeur);
            sudoku.setTypeCase(ligne,colonne,typeCase(type));
        }
        fichier.close();
        test=1;
        return sudoku;
    }
    else
    {
        cout<<"erreur:fichier introuvable"<<endl<<endl;
        Sleep(1000);
        system("CLS");
        test=0;
    }
    }while(test==0);

}

void Partie::sauvegarderPartie(Sudoku sudoku)
{
    std::string chemin;
    cout<<"Tapez le chemin:"<<endl<<endl;
    cin>>chemin;
    ofstream fichier(chemin.c_str(),ios::trunc);
    for (int ligne = 0; ligne < 9; ligne++)
    {
        for (int colonne = 0; colonne < 9; colonne++)
        {
            fichier<<ligne<<" "<<colonne<<" "<<sudoku.getCase(ligne,colonne).valeur<<" "<<sudoku.getCase(ligne,colonne).type<<endl;
        }
    }
}

void Partie::choixJoueur()
{
    int choix;
    do
    {
        cout<<"\tBienvenue au jeu du Sudoku"<<endl<<endl;
        cout<<"Choisir le joueur de cette partie:"<<endl<<endl;
        cout<<"(1) Humain Assiste"<<endl<<"(2) Humain Non Assiste"<<endl<<"(3) Machine 1"<<endl<<"(4) Machine 2"<<endl<<"(5) Machine 3"<<endl<<"(6) Machine 4"<<endl<<"(7) Quitter"<<endl<<endl;
        cin>>choix;
        switch(choix)
        {
            case 1:
                system("CLS");
                joueur = new Joueur_Humain_Assiste();
                choixTypePartie();
                break;
            case 2:
                system("CLS");
                joueur = new Joueur_Humain_NonAssistee();
                choixTypePartie();
                break;
            case 3:
                system("CLS");
                joueur = new Machine_1();
                choixTypePartie();
                break;
            case 4:
                system("CLS");
                joueur = new Machine_2();
                choixTypePartie();
                break;
            case 5:
                system("CLS");
                joueur = new Machine_3();
                choixTypePartie();
                break;
            case 6:
                system("CLS");
                joueur = new Machine_4();
                choixTypePartie();
                break;
            case 7:
                system("CLS");
                exit(0);
            default:
                cout<<"Choix invalide"<<endl;
                Sleep(1000);
                system("CLS");
                break;
        }
    }while(choix>7);
}

void Partie::choixTypePartie()
{
    int choix;
    do
    {
        cout<<"Choisir la methode d'obtention de la grille:"<<endl<<endl;
        cout<<"(1) Reprendre"<<endl<<"(2) Generer Manuellement"<<endl<<"(3) Generer Automatique 1"<<endl<<endl;
        cin>>choix;
        switch(choix)
        {
            case 1:
                system("CLS");
                sudoku=reprendrePartie();
                break;
            case 2:
                system("CLS");
                generateur = new Generateur_Saisie();
                sudoku=generateur->genererGrille();
                break;
            case 3:
                system("CLS");
                generateur = new Generateur_1();
                sudoku=generateur->genererGrille();
                break;
            default:
                cout<<"Choix invalide"<<endl;
                Sleep(1000);
                system("CLS");
                break;
        }
    }while(choix>3);
}

void Partie::commencerPartie()
{
    std::string input;
    cout<<sudoku<<endl;
    Sleep(3000);
    int test=joueur->resoudreGrille(sudoku);
    if(!test && ((typeid(*joueur)==typeid(Joueur_Humain_Assiste)) || (typeid(*joueur)==typeid(Joueur_Humain_NonAssistee))))
    {
        do
        {
            cout<<"Voulez vous sauvegarder la partie?"<<endl<<endl;
            cin>>input;
            cout<<endl;
            if((input.compare("oui")!=0) && (input.compare("non")!=0))
                cout<<"Input invalide"<<endl<<endl;
        }while((input.compare("oui")!=0) && (input.compare("non")!=0));

        if(input.compare("oui")==0)
        {
            sauvegarderPartie(sudoku);
        }
    }
    if(!test && !((typeid(*joueur)==typeid(Joueur_Humain_Assiste)) || (typeid(*joueur)==typeid(Joueur_Humain_NonAssistee))))
    {
        cout<<"Pas de solution"<<endl<<endl;
    }

    do
    {
        cout<<"Voulez vous jouer une autre partie?"<<endl<<endl;
        cin>>input;
        system("CLS");
        if((input.compare("oui")!=0) && (input.compare("non")!=0))
            cout<<"Input invalide"<<endl<<endl;
    }while((input.compare("oui")!=0) && (input.compare("non")!=0));

    if(input.compare("non")==0)
        exit(0);
}

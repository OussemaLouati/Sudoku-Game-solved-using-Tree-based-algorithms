#ifndef CASES_H
#define CASES_H
#include <vector>

using namespace std;

enum typeCase{VIDE,ORIGINALE,NOUVELLE};

class Cases
{
    public:
        int valeur;
        typeCase type;
        vector<int> possibilites;
};

#endif // CASES_H

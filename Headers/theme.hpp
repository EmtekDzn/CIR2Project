#ifndef THEME_H
#define THEME_H

/*!
 * theme.hpp
 * ---------
 *
 *
 * --> Une classe C++ pour stocker un theme recupere en BDD
 * --> Cette classe est utilisee dans les vecteurs de Theme
 *
 * --> Details des fonctions dans theme.cpp
 *                                ---------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */

#include "includes.hpp"

using namespace std;
class Theme {
    public:
        Theme(string ctg, int id_ctg); ///< Constructeur

        /// Getters
        string getCategorie();
        int getIdCategorie();

    private:
        string categorie;
        int id_categorie;
};

#endif // THEME_H

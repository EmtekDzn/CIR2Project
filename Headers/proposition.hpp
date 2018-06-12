#ifndef PROPOSITON_H
#define PROPOSITON_H

/*!
 * proposition.hpp
 * ---------------
 *
 *
 * --> Une classe C++ pour stocker une proposition recuperee en BDD
 * --> Cette classe est utilisee dans les vecteurs de Proposition
 *
 * --> Details des fonctions dans proposition.cpp
 *                                ---------------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */

#include "includes.hpp"

using namespace std;

class Proposition {

    public:
        Proposition(string prp, int id_qst); ///< Constructeur

        string getProposition(); ///< Getter pour recuperer l'attribut proposition

    private:
        string proposition;
        int id_question;
};

#endif // PROPOSITON_H

#ifndef PROPOSITON_H
#define PROPOSITON_H

/*!
 * \file proposition.hpp
 * \brief Fichier contenant la classe Proposition
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "includes.hpp"

using namespace std;

/*! \class Proposition
 * \brief Une classe C++ pour stocker une proposition recuperee en BDD
 *
 * Cette classe est utilisee dans les vecteurs de Proposition
 */
class Proposition {
    public:
         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe Proposition.
            *
            * \param std::string prp : La proposition
            * \param int id_qst : L'id de la question associée
            */
        Proposition(string prp, int id_qst);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe Proposition
            */
        ~Proposition(){};

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer la proposition
            * \return std::string proposition : La proposition
            */
        string getProposition();

    private:
        string proposition;
        int id_question;
};

#endif // PROPOSITON_H

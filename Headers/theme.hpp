#ifndef THEME_H
#define THEME_H

/*!
 * \file theme.hpp
 * \brief Fichier contenant la classe Theme
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "includes.hpp"

using namespace std;

/*! \class Themes
 * \brief Une classe C++ pour stocker un theme recupéré en BDD
 *
 * Cette classe est utilisee dans les vecteurs de Theme
 */
class Theme {
    public:
         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe Theme
            *
            * \param std::string ctg : Le nom du theme
            * \param int id_ctg : L'id du theme
            */
        Theme(string ctg, int id_ctg);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe Theme
            */
        ~Theme(){};

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer le theme
            * \return std::string categorie : Le theme
            */
        string getCategorie();

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer l'id du theme
            * \return int id_categorie : L'id du theme
            */
        int getIdCategorie();

    private:
        string categorie;
        int id_categorie;
};

#endif // THEME_H

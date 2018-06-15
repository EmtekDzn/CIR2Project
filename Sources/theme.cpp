#include "../Headers/theme.hpp"

/*!
 * \file theme.cpp
 * \brief Fichier contenant les methodes de la classe Theme
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

Theme::Theme(string ctg, int id_ctg)
{
    categorie = ctg;
    id_categorie = id_ctg;
}

string Theme::getCategorie() {
    return categorie;
}

int Theme::getIdCategorie() {
    return id_categorie;
}

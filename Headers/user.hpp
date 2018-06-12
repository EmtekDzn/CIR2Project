#ifndef USER_H
#define USER_H

/*!
 * user.hpp
 * --------
 *
 *
 * --> Une classe C++ pour stocker un utilisateur recupere en BDD
 * --> Cette classe est utilisee dans les vecteurs de User
 *
 * --> Details des fonctions dans user.cpp
 *                                --------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */

#include "includes.hpp"

using namespace std;

class User {
    public:
        User(int id_usr, string usrnm , string pwd); ///< Constructeur
        string getUsername(); ///< Getter pour recuperer l'attribut username

    private:
        int id_user;
        string username;
        string password;
};

#endif // USER_H

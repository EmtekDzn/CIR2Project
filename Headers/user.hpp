#ifndef USER_H
#define USER_H

/*!
 * \file user.hpp
 * \brief Fichier contenant la classe User
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "includes.hpp"

using namespace std;

/*! \class Themes
 * \brief Une classe C++ pour stocker un utilisateur recupere en BDD
 *
 * Cette classe est utilisee dans les vecteurs de User
 */
class User {
    public:
         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe User
            *
            * \param int id_usr : L'id de l'utilisateur
            * \param std::string usrnm : Le nom d'utilisateur
            * \param std::string pwd : Le mot de passe de l'utilisateur
            */
        User(int id_usr, string usrnm , string pwd);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe User
            */
        ~User(){};

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer le nom de l'utilisateur
            * \return std::string username : Le nom d'utilisateur
            */
        string getUsername();

    private:
        int id_user;
        string username;
        string password;
};

#endif // USER_H

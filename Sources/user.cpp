#include "../Headers/user.hpp"

/*!
 * \file user.cpp
 * \brief Fichier contenant les methodes de la classe User
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

User::User(int id_usr, string usrnm , string pwd) {
    id_user = id_usr;
    username = usrnm;
    password = pwd;
}

string User::getUsername() {
    return username;
}

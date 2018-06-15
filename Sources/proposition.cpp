#include "../Headers/proposition.hpp"

/*!
 * \file proposition.cpp
 * \brief Fichier contenant les methodes de la classe Proposition
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

Proposition::Proposition(string prp, int id_qst) {
    proposition = prp;
    id_question = id_qst;
}

string Proposition::getProposition() {
    return proposition;
}

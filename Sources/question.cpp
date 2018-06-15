#include "../Headers/question.hpp"

/*!
 * \file question.cpp
 * \brief Fichier contenant les methodes de la classe Question
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

Question::Question(string qst,int id_ctg, int id_qst)
{
    question = qst;
    id_categorie = id_ctg;
    id_question = id_qst;
}

string Question::getQuestion() {
    return question;
}

int Question::getIdQuestion() {
    return id_question;
}

int Question::getIdCategorie() {
    return id_categorie;
}

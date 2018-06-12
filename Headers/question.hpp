#ifndef QUESTION_H
#define QUESTION_H

/*!
 * question.hpp
 * ------------
 *
 *
 * --> Une classe C++ pour stocker une question recuperee en BDD
 * --> Cette classe est utilisee dans les vecteurs de Question
 *
 * --> Details des fonctions dans question.cpp
 *                                ------------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */

#include "includes.hpp"

using namespace std;

class Question {
    public:
        Question(string qst, int id_ctg, int id_qst); ///< Constructeur

        /// Getters
        string getQuestion();
        int getIdQuestion();
        int getIdCategorie();

    private:
        string question;
        int id_categorie;
        int id_question;
};

#endif // QUESTION_H

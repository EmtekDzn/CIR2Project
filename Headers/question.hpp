#ifndef QUESTION_H
#define QUESTION_H

/*!
 * \file question.hpp
 * \brief Fichier contenant la classe Question
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "includes.hpp"

using namespace std;

/*! \class Question
 * \brief Une classe C++ pour stocker une question recuperee en BDD
 *
 * Cette classe est utilisee dans les vecteurs de Question
 */
class Question {
    public:
         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe Question
            *
            * \param std::string qst : La question
            * \param int id_ctg : L'id du theme associé
            * \param int id_qst : L'id de la question
            */
        Question(string qst, int id_ctg, int id_qst);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe Question
            */
        ~Question(){};

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer la question
            * \return std::string question : La question
            */
        string getQuestion();

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer l'id de la question
            * \return int id_question : L'id de la question
            */
        int getIdQuestion();

        /*!
            *  \brief Getter
            *
            *  Permet de récupérer l'id du theme associé
            * \return id_categorie : L'id du theme
            */
        int getIdCategorie();

    private:
        string question;
        int id_categorie;
        int id_question;
};

#endif // QUESTION_H

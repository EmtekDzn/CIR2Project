/*!
 * database.hpp
 * ------------
 *
 *
 * --> Une classe pour se connecter à la base de données et effectuer des requetes SQL sur celle-ci
 *
 * --> Details des fonctions dans database.cpp
 *                                ------------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */


#ifndef DATABASE_H
#define DATABASE_H

#include "md5.hpp"
#include "proposition.hpp"
#include "question.hpp"
#include "theme.hpp"
#include "user.hpp"


namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;


class Database{

    public:

        Database(string ipAddress, string dbName, string dbPwd); ///< Constructeur
        ~Database(); ///< Destructeur

        /// Fonctions de récupération des données
        void listThemes();
        void listQuestions_order_by_Categorie();
        void listUsers();
        void listPropositions(int id_question);
        int getId(string id, string table, string row, string token);
        string getPwd(string user);

        /// Fonctions d'ajout de donnees
        void addTheme(string newName);
        void addQuestion(string newQuestion, int idTheme);
        void addProp(string proposition, int goodAnswer, int idQuestion);
        void addUser(string username, string password, int checkAdmin);

        /// Fonctions d'edition de donnees
        void editTheme(string theme, string newName);
        void editQuestion(string newQuestion, int id_question);
        void editProp(string proposition, int goodAnswer, int id_question, int id_proposition);
        void editUser(string user, string newName, string newPwd, int checkAdmin);

        /// Fonctions de suppressions de donnees
        void delUser(string username);
        void delProp(string proposition);
        void delQuestion(string question, int id_question);
        void delTheme(int id_ctg);

        /// Fonctions de tests
        bool testAdmin(string user, string pwd);
        bool checkIfExists(string table, string row, string token);
        string checkApostrophes(string statement);

        /// Getters
        vector <Theme> getThemes();
        vector <Question> getQuestions();
        vector <User> getUsers();
        vector <Proposition> getPropositions();


    private:

        /// Attributs SQL
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        /// Vecteurs
        vector <Theme> themes;
        vector <Question> questions;
        vector <Proposition> propositions;
        vector <User> users;
};

#endif // DATABASE_H

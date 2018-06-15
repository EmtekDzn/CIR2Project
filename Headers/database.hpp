/*!
 * \file database.hpp
 * \brief Fichier contenant la classe Database
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */
#ifndef DATABASE_H
#define DATABASE_H

#include "md5.hpp"
#include "proposition.hpp"
#include "question.hpp"
#include "theme.hpp"
#include "user.hpp"

using namespace std;

/*! \class Database
 * \brief Classe de la base de donnée
 *
 *   La classe se connecte a la bdd et contient les fonctions effectuant les requetes SQL
 */
class Database{

    public:

          /*!
              *  \brief Constructeur
              *
              *  Constructeur de la classe Database.
              *  Il recupere les drivers sql, se connecte a la BDD et initialise sql::Statement *stmt
              *
              *  \param std::string ipAddress : L'adresse ip de la BDD
              *  \param std::string dbName : Le nom de la BDD
              *  \param std::string dbPwd : Le mot de passe de la BDD
              */
        Database(string ipAddress, string dbName, string dbPwd);

        /*!
             *  \brief Destructeur
             *
             *  Destructeur de la classe Database
             */
        ~Database();

        /*!
             *  \brief Verification de syntaxe
             *
             * Cette fonction renvoie la chaine entrée après
             * avoir doublé les apostrophes s'il y en a.
             * Les apostrophes sont sources d'erreurs dans les
             * requetes SQL, on les double pour eviter ces problemes.
             *
             *  \param std::string statement : La chaine a verifier
             *  \return std::string statement : La chaine verifiée
             */
        string checkApostrophes(string statement);

        /*!
         * \brief Verification de syntaxe
         *
         * Cette fonction verifie si un utilisateur est un admin ou non.
         *
         * \param std::string user : Le nom d'utilisateur
         * \param std::string pwd : Le mot de passe de l'utilisateur
         *
         * \return true : L'utilisateur est un admin
         * \return false : L'utilisateur n'est pas un admin
         */
        bool testAdmin(string user, string pwd);

        /*!
         * \brief Fonction de test
         *
         * Cette fonction permet de verifier si l'entrée existe deja en bdd ou non.
         *
         * \param std::string table : Le nom de la table
         * \param std::string row : Le nom de la colonne a verifier
         * \param std::string token : La condition
         *
         * \return true : L'entrée existe en bdd
         * \return false : L'entrée n'existe pas en bdd
         */
        bool checkIfExists(string table, string row, string token);

        /*!
         * \brief Fonction de récupération de données
         *
         * Cette fonction remplit le vecteur de Theme
         */
        void listThemes();

        /*!
         * \brief Fonction de récupération de données
         *
         * Cette fonction remplit le vecteur de Question, trié par theme
         */
        void listQuestions_order_by_Categorie();

        /*!
        * \brief Fonction de récupération de données
        *
        * Cette fonction remplit le vecteur de Proposition
        * \param int id_question : L'id de la question dont ont veut récuperer les propositions
        */
        void listPropositions(int id_question);

        /*!
        * \brief Fonction de récupération de données
        *
        * Cette fonction remplit le vecteur de User
        */
        void listUsers();

        /*!
        * \brief Fonction de récupération de données
        *
        * Cette fonction renvoie l'id désiré
        * \param std::string id : L'id désiré
        * \param std::string table : La table sur laquelle effectuer la requete
        * \param std::string row : La condition a verifier
        * \param std::string token : La condition
        * \return int res->getInt(id) : L'id désiré
        * \return int 0 : Si le resultat n'a pas abouti
        */
        int getId(string id, string table, string row, string token);

        /*!
        * \brief Fonction de récupération de données
        *
        * Cette fonction renvoie le mot de passe de l'utilisateur entré
        * \param std::string user : Le nom de l'utilisateur dont on veut le mot de passe
        * \return std::string res->getString("password") : Le mot de passe
        * \return std::string "" : Un chaine vide si la requete n'a pas abouti
        */
        string getPwd(string user);

        /*!
        * \brief Fonction d'ajout de donnees
        *
        * Cette fonction permet d'ajouter un theme
        * \param std::string newName : Le nom du nouveau theme
        */
        void addTheme(string newName);

        /*!
        * \brief Fonction d'ajout de donnees
        *
        * Cette fonction permet d'ajouter une question
        * \param std::string newQuestion : Le nom de la nouvelle question
        * \param int idTheme : L'id du theme de la nouvelle question
        */
        void addQuestion(string newQuestion, int idTheme);

        /*!
        * \brief Fonction d'ajout de donnees
        *
        * Cette fonction permet d'ajouter une proposition
        * \param std::string proposition : Le nom de la nouvelle proposition
        * \param int goodAnswer : La bonne reponse choisie (1,2 ou 3)
        * \param int idQuestion : l'id de la question associée
        */
        void addProp(string proposition, int goodAnswer, int idQuestion);

        /*!
        * \brief Fonction d'ajout de donnees
        *
        * Cette fonction permet d'ajouter un utilisateur
        * \param std::string username : Le nom de l'utilisateur
        * \param std::string password : Le nouveau nom a donner a cet utilisateur
        * \param int checkAdmin : Etat de la QCheckBox (0,1 ou 2) pour mettre l'utilisateur en admin ou non
        */
        void addUser(string username, string password, int checkAdmin);

        /*!
        * \brief Fonction d'edition de donnees
        *
        * Cette fonction permet de changer le nom d'un theme
        * \param std::string theme : Le nom de l'ancien theme
        * \param std::string newName : Le nouveau nom a donner au theme
        */
        void editTheme(string theme, string newName);

        /*!
        * \brief Fonction d'edition de donnees
        *
        * Cette fonction permet d'éditer une question
        * \param std::string newQuestion : Le nouveau nom de la question
        * \param int id_question : L'id associé a la question
        */
        void editQuestion(string newQuestion, int id_question);

        /*!
        * \brief Fonction d'edition de donnees
        *
        * Cette fonction permet d'éditer une proposition
        * \param std::string proposition : Le nouveau nom de la proposition
        * \param int goodAnswer : La bonne réponse
        * \param int id_question : L'id de la question associée
        * \param id_proposition : L'id de la proposition
        */
        void editProp(string proposition, int goodAnswer, int id_question, int id_proposition);

        /*!
        * \brief Fonction d'edition de donnees
        *
        * Cette fonction permet d'editer un profil
        * \param std::string user : Le nom de l'utilisateur
        * \param std::string newName : Le nouveau nom a donner a cet utilisateur
        * \param std::string newPwd : Le nouveau mot de passe a donner a cet utilisateur
        * \param int checkAdmin : Etat de la QCheckBox (0,1 ou 2) pour mettre l'utilisateur en admin ou non
        */
        void editUser(string user, string newName, string newPwd, int checkAdmin);

        /*!
        * \brief Fonction de suppression de données
        *
        * Cette fonction permet de supprimer un theme et les questions et propositions associées
        * \param int id_ctg : L'id du theme a supprimer
        */
        void delTheme(int id_ctg);

        /*!
        * \brief Fonction de suppression de données
        *
        * Cette fonction permet de supprimer une question et les propositions associées
        * \param std::string question : Le nom de la question a supprimer
        * \param int id_question : L'id de la question
        */
        void delQuestion(string question, int id_question);

        /*!
        * \brief Fonction de suppression de données
        *
        * Cette fonction permet de supprimer une proposition
        * \param std::string proposition : Le nom de la proposition a supprimer
        */
        void delProp(string proposition);

        /*!
        * \brief Fonction de suppression de données
        *
        * Cette fonction permet de supprimer un utilisateur
        * \param std::string username : Le nom de l'utilisateur a supprimer
        */
        void delUser(string username);


        /*!
        * \brief Getter
        *
        * Cette fonction permet de recuperer le vecteur de Theme
        * \return vector<Theme> themes : Le vecteur de Theme
        */
        vector <Theme> getThemes();

        /*!
        * \brief Getter
        *
        * Cette fonction permet de recuperer le vecteur de Question
        * \return vector<Theme> questions : Le vecteur de Question
        */
        vector <Question> getQuestions();

        /*!
        * \brief Getter
        *
        * Cette fonction permet de recuperer le vecteur de Proposition
        * \return vector<Theme> propositions : Le vecteur de Proposition
        */
        vector <Proposition> getPropositions();

        /*!
        * \brief Getter
        *
        * Cette fonction permet de recuperer le vecteur de User
        * \return vector<Theme> users : Le vecteur de User
        */
        vector <User> getUsers();


    private:
        sql::Driver *driver; /*!< Attribut SQL*/
        sql::Connection *con; /*!< Attribut SQL*/
        sql::Statement *stmt; /*!< Attribut SQL*/
        sql::ResultSet *res; /*!< Attribut SQL*/

        /// Vecteurs
        vector <Theme> themes; /*!< Vecteur de Theme*/
        vector <Question> questions; /*!< Vecteur de Question*/
        vector <Proposition> propositions; /*!< Vecteur de Proposition*/
        vector <User> users; /*!< Vecteur de User*/
};

#endif // DATABASE_H

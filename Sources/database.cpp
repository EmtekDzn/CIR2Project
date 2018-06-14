#include "../Headers/database.hpp"

/*!
 * database.cpp
 * ------------
 *
 * --> Une classe pour se connecter à la base de données et effectuer des requetes SQL sur celle-ci
 * --> Header : database.hpp
 *              ------------
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 *
 */



/*! ________________________________________________________________________________________________
 * Constructeur : Database::Database(std::string, std::string, std::string)
 *
 * Ce constructeur recupere les drivers sql, se connecte a la BDD et initialise sql::Statement *stmt
 *
 * Parametres :
 *      - std::string ipAddress : L'adresse ip de la BDD
 *      - std::string dbName : Le nom de la BDD
 *      - std::string dbPwd : Le mot de passe de la BDD
 * _________________________________________________________________________________________________
 */
Database::Database(string ipAddress, string dbName, string dbPwd) {
    driver = get_driver_instance();
    con = driver->connect("tcp://" + ipAddress, dbName, dbPwd);
    con->setSchema(dbName);
    stmt = con->createStatement();
}




/*! __________________________________
 * Destructeur : Database::~Database()
 *____________________________________
 */
Database::~Database() {
    delete res;
    delete stmt;
    delete con;
}



/*! ____________________________________________________________________________________________________
 * Fonction : std::string Database::checkApostrophes(std::string)
 *
 * Cette fonction renvoie la chaine entrée après avoir doublé les apostrophes s'il y en a
 * Les apostrophes sont sources d'erreurs dans les requetes SQL, on les double pour eviter ces problemes
 *
 * Parametres :
 *      - std::string statement : La chaine a verifier
 *
 * Retour :
 *      - std::string statement : La chaine verifiée
 * _____________________________________________________________________________________________________
 */
string Database::checkApostrophes(string statement) {

    string find = "'";      ///< Le caractere a trouver dans la chaine
    string replace = "''";  ///< La chaine de remplacement

    ///< Parcours de la chaine en cherchant les eventuelles apostrophes
    for(string::size_type i = 0; (i = statement.find(find, i)) != string::npos;) {

            statement.replace(i, find.length(), replace); ///< Lorsqu'une apostrophe est trouvee
            i += replace.length();                        ///< On la double
        }

    return statement; ///< Et on retourne la chaine
}





/*! ____________________________________________________________
 * Fonction : bool Database::testAdmin(std::string, std::string)
 *
 * Cette fonction verifie si un utilisateur est un admin ou non
 *
 * Parametres :
 *      - std::string user : Le nom d'utilisateur
 *      - std::string pwd : Le mot de passe de l'utilisateur
 *
 * Retour :
 *      - true : L'utilisateur est un admin
 *      - false : L'utilisateur n'est pas un admin
 *______________________________________________________________
 */
bool Database::testAdmin(string user, string pwd) {
     /// On verifie les apostrophes
    user = checkApostrophes(user);
    pwd = checkApostrophes(pwd);

    ///Requete SQL : Selectionne admin (0 ou 1) correspondant a l'utilisateur dans la table User
    res = stmt->executeQuery("SELECT admin FROM User WHERE username='"+user+"' AND password='"+pwd+"'");

    if(res->next()) {                   ///< S'il y a un resulat valide
        if(res->getInt("admin")==1) {   ///< Et admin vaut 1
            return true;                ///< On retourne true
        }
    }

    delete res;                         ///< Sinon (ou s'il n'y a pas de resultat) on retourne false
    return false;
}





/*!___________________________________________
 * Fonction : void Database::listThemes()
 *
 *
 * Cette fonction remplit le vecteur de Theme
 *
 * ___________________________________________
 */
void Database::listThemes() {
    themes.clear(); ///< On vide le vecteur (sert pour actualiser les données)

    /// Requete SQL : Selectionne le nom du theme et son id dans la table Theme et trie les resultats par categorie
    res = stmt->executeQuery("SELECT categorie, id_categorie FROM Theme ORDER BY categorie");

    while(res->next()) { ///< Tant qu'il y a un resultat
        themes.push_back(Theme(res->getString("categorie"), res->getInt("id_categorie"))); ///< On l'insere dans le vecteur
    }
    delete res;
}




/*!______________________________________________________________
 * Fonction : void Database::listQuestions_order_by_Categorie()
 *
 *
 * Cette fonction remplit le vecteur de Question, trié par theme
 *
 * ______________________________________________________________
 */
void Database::listQuestions_order_by_Categorie() {
    questions.clear(); ///< On vide le vecteur (sert pour actualiser les données)

    /// Pour chaque theme
     for(size_t i=0 ; i < themes.size() ; i++) {
          /// On recupere les questions et id de Question associées au theme
         res = stmt->executeQuery("SELECT question, id_question FROM Question WHERE Question.id_categorie ="+to_string(themes[i].getIdCategorie())+" ORDER BY question");

         while(res->next()) { ///< Tant qu'il y a un resultat
             questions.push_back(Question(res->getString("question"), themes[i].getIdCategorie(), res->getInt("id_question"))); ///< On l'insere dans le vecteur
         }
         delete res;
     }
}




/*!__________________________________________________________________________________________________________
 * Fonction : void Database::listPropositions(int)
 *
 *
 * Cette fonction remplit le vecteur de Proposition (ce sont les propositions associees a la question entree)
 *
 * Parametres :
 *        - int id_question : La question dont ont veut récuperer les propositions
 * __________________________________________________________________________________________________________
 */
void Database::listPropositions(int id_question) {
    propositions.clear(); ///< On vide le vecteur (sert pour actualiser les données)

    /// Recupere les propositions, sont id et la bonne reponse associées à la question entrée
    res = stmt->executeQuery("SELECT proposition, bonne_reponse, id_question FROM Proposition WHERE id_question='"+to_string(id_question)+"' ORDER BY proposition");
    while(res->next()) { ///< Tant qu'il y a un resultat
        propositions.push_back(Proposition(res->getString("proposition"), res->getInt("id_question"))); ///< On l'insere dans le vecteur
    }
    delete res;
}





/*!_________________________________________
 * Fonction : void Database::listUsers()
 *
 *
 * Cette fonction remplit le vecteur de User
 *
 *__________________________________________
 */
void Database::listUsers() {
    users.clear(); ///< On vide le vecteur (sert pour actualiser les données)

    /// Recupere tous les utilisateurs
    res = stmt->executeQuery("SELECT * FROM User ORDER BY username");

    while(res->next()) { ///< Tant qu'il y a un resultat
        users.push_back(User(res->getInt("id_user"), res->getString("username"), res->getString("password"))); ///< On l'insere dans le vecteur
    }
    delete res;
}




/*!__________________________________________________________________________________
 * Fonction : int Database::getId(std::string, std::string, std::string, std::string)
 *
 * Cette fonction renvoie l'id désiré
 *
 * Parametres :
 *      - std::string id : L'id désiré
 *      - std::string table : La table sur laquelle effectuer la requete
 *      - std::string row : La condition a verifier
 *      - std::string token : La condition
 *
 * Retour :
 *      - std::string res->getInt(id) : L'id désiré
 *      - int 0 : Si le resultat n'a pas abouti
 * ___________________________________________________________________________________
 */
int Database::getId(string id, string table, string row, string token) {
     /// On verifie les apostrophes
     id = checkApostrophes(id);
     table = checkApostrophes(table);
     row = checkApostrophes(row);
     token = checkApostrophes(token);

     /// Recupere l'id désiré
    res = stmt->executeQuery("SELECT "+id+" FROM "+table+" WHERE "+row+"='"+token+"'");
    if(res->next()) {              ///< S'il y a un resultat
        return res->getInt(id);    ///< On le retourne
    }
    return 0;
}




/*!___________________________________________________________________________________________________
 * Fonction : std::string Database::getPwd(std::string)
 *
 * Cette fonction renvoie le mot de passe d'un utilisateur
 *
 * Parametres :
 *      - std::string user : Le nom d'utilisateur
 *
 * Retour :
 *      - std::string res->getString("password") : Le mot de passe retourné par la requete SQL
 *      - std::string "" : Un chaine vide si la requete n'a pas abouti
 * ___________________________________________________________________________________________________
 */
string Database::getPwd(string user) {
        /// Recupere le mot de passe associé a l'utilisateur entré dans la table User
        res = stmt->executeQuery("SELECT password FROM User WHERE username='"+user+"'");

        if(res->next()) {                       ///< S'il y a un resultat valide
            return res->getString("password");  ///< On le retourne
        } else {                                ///< Sinon
            delete res;                         ///< On supprime le resultat
            return "";                          ///< Et on retourne une chaine vide
        }
}



/*!________________________________________________________________
 * Fonction : void Database::addTheme(std::string)
 *
 *
 * Cette fonction permet d'ajouter un theme
 *
 * Parametres :
 *        - std::string newName : Le nom du nouveau theme
 *
 * ________________________________________________________________
 */
void Database::addTheme(string newName) {
    newName = checkApostrophes(newName);

    /// On ajoute le nouveau theme
    stmt->executeUpdate("INSERT INTO Theme (categorie) VALUES ('"+newName+"')");
}




/*!________________________________________________________________
 * Fonction : void Database::editTheme(std::string, std::string)
 *
 *
 * Cette fonction permet de changer le nom d'un theme
 *
 * Parametres :
 *        - std::string theme : Le nom de l'ancien theme
 *        - std::string newName : Le nouveau nom a donner au theme
 * ________________________________________________________________
 */
void Database::editTheme(string theme, string newName) {
    newName = checkApostrophes(newName);

    /// On change le nom du theme entré par le nouveau
    stmt->executeUpdate("UPDATE Theme SET categorie='"+newName+"'WHERE categorie='"+theme+"'");
}




/*!___________________________________________________________________________________________________
 * Fonction : void Database::editUser(std::string, std::string, std::string, int)
 *
 *
 * Cette fonction permet d'editer un utilisateur
 *
 * Parametres :
 *        - std::string user : Le nom de l'utilisateur
 *        - std::string newName : Le nouveau nom a donner a cet utilisateur
 *        - std::string newPwd : Le nouveau mot de passe a donner a cet utilisateur
 *        - int checkAdmin : Etat de la QCheckBox (0,1 ou 2) pour mettre l'utilisateur en admin ou non
 * ___________________________________________________________________________________________________
 */
void Database::editUser(string user, string newName, string newPwd, int checkAdmin) {
    newName = checkApostrophes(newName);
    if(checkAdmin) {     ///< Si la QCheckBox a été cochée
        if(newPwd=="") { ///< Si aucun nouveau mot de passe n'a été entré
             /// On modifie le nom de l'utilisateur, et on le met admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='1' WHERE username='"+user+"'");
       } else { ///< Sinon (nouveau mot de passe entré)
            newPwd = md5(newPwd); ///< On hache le nouveau mot de passe
            /// On modifie le nom et le mot de passe de l'utilisateur, et on le met admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='1' WHERE username='"+user+"'");
        }
   } else { ///< Sinon (QCheckBox pas cochée)
        if(newPwd=="") { ///< Si aucun nouveau mot de passe n'a été entré
               /// On modifie le nom de l'utilisateur, et on le met non admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='0' WHERE username='"+user+"'");
       } else { ///< Sinon (nouveau mot de passe entré)
            newPwd = md5(newPwd); ///< On hache le mot de passe
            /// On modifie le nom et le mot de passe de l'utilisateur, et on le met non admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='0' WHERE username='"+user+"'");
        }
    }
}




/*!___________________________________________________________________________________________________
 * Fonction : void Database::addUser(std::string, std::string, std::string, int)
 *
 *
 * Cette fonction permet d'ajouter un utilisateur
 *
 * Parametres :
 *        - std::string username : Le nom de l'utilisateur
 *        - std::string password : Le nouveau nom a donner a cet utilisateur
 *        - int checkAdmin : Etat de la QCheckBox (0,1 ou 2) pour mettre l'utilisateur en admin ou non
 * ___________________________________________________________________________________________________
 */
void Database::addUser(string username, string password, int checkAdmin) {
    username = checkApostrophes(username);

    password = md5(password); ///< Hachage du mot de passe
    if(checkAdmin) { ///< Si la checkbox est cochée
         /// On ajoute l'utilisateur en admin
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','1')");
    } else {
         /// Sinon on l'ajoute en non admin
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','0')");
    }
}



/*!__________________________________________________________________
 * Fonction : void Database::addQuestion(std::string, int)
 *
 *
 * Cette fonction permet d'ajouter une question
 *
 * Parametres :
 *        - std::string newQuestion : Le nom de la nouvelle question
 *        - int idTheme : L'id du theme de la nouvelle question
 *
 * __________________________________________________________________
 */
void Database::addQuestion(string newQuestion, int idTheme) {
    newQuestion = checkApostrophes(newQuestion);
    /// On ajoute la question et on l'associe au theme choisi
    stmt->executeUpdate("INSERT INTO Question (question, id_categorie) VALUES ('"+newQuestion+"', '"+to_string(idTheme)+"')");
}


/*!_____________________________________________________________________
 * Fonction : void Database::addProp(std::string, int, int)
 *
 *
 * Cette fonction permet d'ajouter une proposition
 *
 * Parametres :
 *        - std::string proposition : Le nom de la nouvelle proposition
 *        - int goodAnswer : La bonne reponse choisie (1,2 ou 3)
 *        - int idQuestion : l'id de la question associée
 *
 * ______________________________________________________________________
 */
void Database::addProp(string proposition, int goodAnswer, int idQuestion) {
    proposition = checkApostrophes(proposition);
    /// Ajoute la proposition
    stmt->executeUpdate("INSERT INTO Proposition (proposition, bonne_reponse, id_question) VALUES ('"+proposition+"', '"+to_string(goodAnswer)+"', '"+to_string(idQuestion)+"')");
}


/*!______________________________________________________________________________
 * Fonction : bool Database::checkIfExists(std::string, std::string, std::string)
 *
 *
 * Cette fonction permet de verifier si l'entrée existe deja en BDD ou non
 *
 * Parametres :
 *        - std::string table : Le nom de la table
 *        - std::string row : : Le nom de la colonne a verifier
 *        - std::string token : : La condition
 *
 * ______________________________________________________________________________
 */
bool Database::checkIfExists(string table, string row, string token) {
    token = checkApostrophes(token);

    /// Selectionne en BDD ce que l'utilisateur a entré
    res = stmt->executeQuery("SELECT `"+row+"` FROM `"+table+"` WHERE "+row+"='"+token+"'");

    if(res->next()) {    ///< S'il y a un resultat
        return true;     ///< On retourne vrai
   } else {              ///< Sinon
        return false;    ///< On retourne faux
    }
}



/*!_______________________________________________________________________
 * Fonction : void Database::editQuestion(std::string, int)
 *
 *
 * Cette fonction permet d'éditer une question
 *
 * Parametres :
 *        - std::string newQuestion : Le nouveau nom de la question
 *        - int id_question : L'id associé a la question
 *
 * ________________________________________________________________________
 */
void Database::editQuestion(string newQuestion, int id_question) {
    newQuestion = checkApostrophes(newQuestion);
    /// Change le nom de la question désirée
    stmt->executeUpdate("UPDATE Question SET question='"+newQuestion+"' WHERE id_question='"+to_string(id_question)+"'");
}



/*!_______________________________________________________________________
 * Fonction : void Database::editProp(std::string, int, int, int)
 *
 *
 * Cette fonction permet d'éditer une proposition
 *
 * Parametres :
 *        - std::string proposition : Le nouveau nom de la proposition
 *        - int goodAnswer : La bonne réponse
 *        - int id_question : L'id de la question associée
 *        - int id_proposition : L'id de la proposition
 *
 * ________________________________________________________________________
 */
void Database::editProp(string proposition, int goodAnswer, int id_question, int id_proposition) {
    proposition = checkApostrophes(proposition);
    /// Change la proposition choisie
    stmt->executeUpdate("UPDATE Proposition SET proposition='"+proposition+"', bonne_reponse ='"+to_string(goodAnswer)+"' WHERE id_question='"+to_string(id_question)+"' AND id_proposition='"+to_string(id_proposition)+"'");
}



/*!_______________________________________________________________________
 * Fonction : void Database::delUser(std::string)
 *
 *
 * Cette fonction permet de supprimer un utilisateur
 *
 * Parametres :
 *        - std::string username : Le nom de l'utilisateur a supprimer
 *
 * ________________________________________________________________________
 */
void Database::delUser(string username) {
    username = checkApostrophes(username);
    /// Suppression
    stmt->executeUpdate("DELETE FROM User WHERE username='"+username+"'");
}



/*!_______________________________________________________________________
 * Fonction : void Database::delProp(std::string)
 *
 *
 * Cette fonction permet de supprimer une proposition
 *
 * Parametres :
 *        - std::string proposition : Le nom de la proposition a supprimer
 *
 * ________________________________________________________________________
 */
void Database::delProp(string proposition) {
    proposition = checkApostrophes(proposition);
    stmt->executeUpdate("DELETE FROM Proposition WHERE proposition='"+proposition+"'");
}


/*!_______________________________________________________________________
 * Fonction : void Database::delQuestion(std::string, int)
 *
 *
 * Cette fonction permet de supprimer une question et les propositions associées
 *
 * Parametres :
 *        - std::string question : Le nom de la question a supprimer
 *        - int id_question : L'id de la question
 *
 * ________________________________________________________________________
 */
void Database::delQuestion(string question, int id_question) {
    question = checkApostrophes(question);

    /// Suppression des propositions associées a la question
    stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+to_string(id_question)+"'");

    /// Suppression de la question
    stmt->executeUpdate("DELETE FROM Question WHERE question='"+question+"'");
}



/*!_______________________________________________________________________
 * Fonction : void Database::delTheme(std::string, int)
 *
 *
 * Cette fonction permet de supprimer une proposition et les questions et propositions associées
 *
 * Parametres :
 *        - int id_ctg : L'id du theme a supprimer
 *
 * ________________________________________________________________________
 */
void Database::delTheme(int id_ctg) {
    string token;
    string id_categorie = to_string(id_ctg); /// On convertit l'id en string pour l'utiliser dans les requetes

    /// On recupere l'id des questions associées au theme
    res = stmt->executeQuery("SELECT id_question FROM Question WHERE id_categorie='"+id_categorie+"'");
    while(res->next()) { ///< Tant qu'il y a un resulat
        token = res->getString("id_question"); ///< On recupere l'id de la question
        stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+token+"'"); ///< Et on supprime les propositions associees
    }
    stmt->executeUpdate("DELETE FROM Question WHERE id_categorie='"+id_categorie+"'"); ///< On supprime les questions associées
    stmt->executeUpdate("DELETE FROM Theme WHERE id_categorie='"+id_categorie+"'"); ///< Puis le theme
}

vector <Theme> Database::getThemes() {
    return themes;
}

vector <Question> Database::getQuestions() {
    return questions;
}

vector <User> Database::getUsers() {
    return users;
}

vector <Proposition> Database::getPropositions() {
    return propositions;
}

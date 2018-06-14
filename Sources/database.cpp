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
    ///Requete SQL : Selectionne admin (0 ou 1) correspondant a l'utilisateur dans la table User
    user = checkApostrophes(user);
    pwd = checkApostrophes(pwd);
    res = stmt->executeQuery("SELECT admin FROM User WHERE username='"+user+"' AND password='"+pwd+"'");

    if(res->next()) {                   ///< S'il y a un resulat valide
        if(res->getInt("admin")==1) {   ///< Et admin vaut 1
            return true;                ///< On retourne true
        }
    }

    delete res;                         ///< Sinon (ou s'il n'y a pas de resultat) on retourne false
    return false;
}





/*!
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
 *
 */
string Database::getPwd(string user) {
        /// Requete SQL : Selectionne le mot de passe associé a l'utilisateur entré dans la table User
        res = stmt->executeQuery("SELECT password FROM User WHERE username='"+user+"'");

        if(res->next()) {                       ///< S'il y a un resultat valide
            return res->getString("password");  ///< On le retourne
        } else {                                ///< Sinon
            delete res;                         ///< On supprime le resultat
            return "";                          ///< Et on retourne une chaine vide
        }
}




/*!
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
 *
 */
int Database::getId(string id, string table, string row, string token) {
     id = checkApostrophes(id);
     table = checkApostrophes(table);
     row = checkApostrophes(row);
     token = checkApostrophes(token);

    res = stmt->executeQuery("SELECT "+id+" FROM "+table+" WHERE "+row+"='"+token+"'");
    if(res->next()) {
        return res->getInt(id);
    }
    return 0;
}





/*!
 * Fonction : void Database::listThemes()
 *
 *
 * Cette fonction remplit le vecteur de Theme
 *
 *
 */
void Database::listThemes() {
    themes.clear(); ///< On vide le tableau (sert pour actualiser les données)

    /// Requete SQL : Selectionne le nom du theme et son id dans la table Theme et trie les resultats par categorie
    res = stmt->executeQuery("SELECT categorie, id_categorie FROM Theme ORDER BY categorie");
    while(res->next()) {
        themes.push_back(Theme(res->getString("categorie"), res->getInt("id_categorie")));
    }
    delete res;
}

void Database::listQuestions_order_by_Categorie() {
    questions.clear();
     for(int i=0 ; i<(int)themes.size() ; i++) {
         res = stmt->executeQuery("SELECT question, id_question FROM Question WHERE Question.id_categorie ="+patch::to_string(themes[i].getIdCategorie())+" ORDER BY question");
         while(res->next()) {
             questions.push_back(Question(res->getString("question"), themes[i].getIdCategorie(), res->getInt("id_question")));
         }
         delete res;
     }
}

void Database::listUsers() {
    users.clear();
    res = stmt->executeQuery("SELECT * FROM User ORDER BY username");
    while(res->next()) {
        users.push_back(User(res->getInt("id_user"), res->getString("username"), res->getString("password")));
    }
    delete res;
}

void Database::listPropositions(int id_question) {
    propositions.clear();
    res = stmt->executeQuery("SELECT proposition, bonne_reponse, id_question FROM Proposition WHERE id_question='"+patch::to_string(id_question)+"' ORDER BY proposition");
    while(res->next()) {
        propositions.push_back(Proposition(res->getString("proposition"), res->getInt("id_question")));
    }
    delete res;
}

void Database::editTheme(string theme, string newName) {
    newName = checkApostrophes(newName);
    stmt->executeUpdate("UPDATE Theme SET categorie='"+newName+"'WHERE categorie='"+theme+"'");
}

void Database::addTheme(string newName) {
    newName = checkApostrophes(newName);
    stmt->executeUpdate("INSERT INTO Theme (categorie) VALUES ('"+newName+"')");
}

void Database::editUser(string user, string newName, string newPwd, int checkAdmin) {
    newName = checkApostrophes(newName);
    if(checkAdmin) {
        if(newPwd=="") {
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='1' WHERE username='"+user+"'");
        } else {
            newPwd = md5(newPwd);
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='1' WHERE username='"+user+"'");
        }
    } else {
        if(newPwd=="") {
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='0' WHERE username='"+user+"'");
        } else {
            newPwd = md5(newPwd);
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='0' WHERE username='"+user+"'");
        }
    }
}

void Database::addUser(string username, string password, int checkAdmin) {
    username = checkApostrophes(username);
    password = md5(password);
    if(checkAdmin) {
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','1')");
    } else {
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','0')");
    }
}

void Database::addQuestion(string newQuestion, int idTheme) {
    newQuestion = checkApostrophes(newQuestion);
    stmt->executeUpdate("INSERT INTO Question (question, id_categorie) VALUES ('"+newQuestion+"', '"+patch::to_string(idTheme)+"')");
}

void Database::addProp(string proposition, int goodAnswer, int idQuestion) {
    proposition = checkApostrophes(proposition);
    stmt->executeUpdate("INSERT INTO Proposition (proposition, bonne_reponse, id_question) VALUES ('"+proposition+"', '"+patch::to_string(goodAnswer)+"', '"+patch::to_string(idQuestion)+"')");
}

bool Database::checkIfExists(string table, string row, string token) {
    token = checkApostrophes(token);
    res = stmt->executeQuery("SELECT `"+row+"` FROM `"+table+"` WHERE "+row+"='"+token+"'");
    if(res->next()) {
        return true;
    } else {
        return false;
    }
}

void Database::editQuestion(string newQuestion, int id_question) {
    newQuestion = checkApostrophes(newQuestion);
    stmt->executeUpdate("UPDATE Question SET question='"+newQuestion+"' WHERE id_question='"+patch::to_string(id_question)+"'");
}

void Database::editProp(string proposition, int goodAnswer, int id_question, int id_proposition) {
    proposition = checkApostrophes(proposition);
    stmt->executeUpdate("UPDATE Proposition SET proposition='"+proposition+"', bonne_reponse ='"+patch::to_string(goodAnswer)+"' WHERE id_question='"+patch::to_string(id_question)+"' AND id_proposition='"+patch::to_string(id_proposition)+"'");
}




void Database::delUser(string username) {
    username = checkApostrophes(username);
    stmt->executeUpdate("DELETE FROM User WHERE username='"+username+"'");
}

void Database::delProp(string proposition) {
    proposition = checkApostrophes(proposition);
    stmt->executeUpdate("DELETE FROM Proposition WHERE proposition='"+proposition+"'");
}

void Database::delQuestion(string question, int id_question) {
    question = checkApostrophes(question);
    stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+patch::to_string(id_question)+"'");
    stmt->executeUpdate("DELETE FROM Question WHERE question='"+question+"'");
}

void Database::delTheme(int id_ctg) {
    string token;
    string id_categorie = patch::to_string(id_ctg);
    res = stmt->executeQuery("SELECT id_question FROM Question WHERE id_categorie='"+id_categorie+"'");
    while(res->next()) {
        token = res->getString("id_question");
        stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+token+"'");
    }
    stmt->executeUpdate("DELETE FROM Question WHERE id_categorie='"+id_categorie+"'");
    stmt->executeUpdate("DELETE FROM Theme WHERE id_categorie='"+id_categorie+"'");
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

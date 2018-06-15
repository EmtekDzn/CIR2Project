#include "../Headers/database.hpp"

/*!
 * \file database.cpp
 * \brief Fichier contenant les methodes de la classe Database
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

Database::Database(string ipAddress, string dbName, string dbPwd) {
    driver = get_driver_instance();
    con = driver->connect("tcp://" + ipAddress, dbName, dbPwd);
    con->setSchema(dbName);
    stmt = con->createStatement();
}



Database::~Database() {
    delete res;
    delete stmt;
    delete con;
}



string Database::checkApostrophes(string statement) {

    string find = "'";      // Le caractere a trouver dans la chaine
    string replace = "''";  // La chaine de remplacement

    // Parcours de la chaine en cherchant les eventuelles apostrophes
    for(string::size_type i = 0; (i = statement.find(find, i)) != string::npos;) {

            statement.replace(i, find.length(), replace); // Lorsqu'une apostrophe est trouvee
            i += replace.length();                        // On la double
        }

    return statement; // Et on retourne la chaine
}



bool Database::testAdmin(string user, string pwd) {
     // On verifie les apostrophes
    user = checkApostrophes(user);
    pwd = checkApostrophes(pwd);

    //Requete SQL : Selectionne admin (0 ou 1) correspondant a l'utilisateur dans la table User
    res = stmt->executeQuery("SELECT admin FROM User WHERE username='"+user+"' AND password='"+pwd+"'");

    if(res->next()) {                   // S'il y a un resulat valide
        if(res->getInt("admin")==1) {   // Et admin vaut 1
            return true;                // On retourne true
        }
    }

    delete res;                         // Sinon (ou s'il n'y a pas de resultat) on retourne false
    return false;
}



bool Database::checkIfExists(string table, string row, string token) {
    token = checkApostrophes(token);

    // Selectionne en BDD ce que l'utilisateur a entré
    res = stmt->executeQuery("SELECT `"+row+"` FROM `"+table+"` WHERE "+row+"='"+token+"'");

    if(res->next()) {    // S'il y a un resultat
        return true;     // On retourne vrai
   } else {              // Sinon
        return false;    // On retourne faux
    }
}



void Database::listThemes() {
    themes.clear(); // On vide le vecteur (sert pour actualiser les données)

    // Requete SQL : Selectionne le nom du theme et son id dans la table Theme et trie les resultats par categorie
    res = stmt->executeQuery("SELECT categorie, id_categorie FROM Theme ORDER BY categorie");

    while(res->next()) { // Tant qu'il y a un resultat
        themes.push_back(Theme(res->getString("categorie"), res->getInt("id_categorie"))); // On l'insere dans le vecteur
    }
    delete res;
}



void Database::listQuestions_order_by_Categorie() {
    questions.clear(); // On vide le vecteur (sert pour actualiser les données)

    // Pour chaque theme
     for(size_t i=0 ; i < themes.size() ; i++) {
          // On recupere les questions et id de Question associées au theme
         res = stmt->executeQuery("SELECT question, id_question FROM Question WHERE Question.id_categorie ="+to_string(themes[i].getIdCategorie())+" ORDER BY question");

         while(res->next()) { // Tant qu'il y a un resultat
             questions.push_back(Question(res->getString("question"), themes[i].getIdCategorie(), res->getInt("id_question"))); // On l'insere dans le vecteur
         }
         delete res;
     }
}



void Database::listPropositions(int id_question) {
    propositions.clear(); // On vide le vecteur (sert pour actualiser les données)

    // Recupere les propositions, sont id et la bonne reponse associées à la question entrée
    res = stmt->executeQuery("SELECT proposition, bonne_reponse, id_question FROM Proposition WHERE id_question='"+to_string(id_question)+"' ORDER BY proposition");
    while(res->next()) { // Tant qu'il y a un resultat
        propositions.push_back(Proposition(res->getString("proposition"), res->getInt("id_question"))); // On l'insere dans le vecteur
    }
    delete res;
}



void Database::listUsers() {
    users.clear(); // On vide le vecteur (sert pour actualiser les données)

    // Recupere tous les utilisateurs
    res = stmt->executeQuery("SELECT * FROM User ORDER BY username");

    while(res->next()) { // Tant qu'il y a un resultat
        users.push_back(User(res->getInt("id_user"), res->getString("username"), res->getString("password"))); // On l'insere dans le vecteur
    }
    delete res;
}



int Database::getId(string id, string table, string row, string token) {
     // On verifie les apostrophes
     id = checkApostrophes(id);
     table = checkApostrophes(table);
     row = checkApostrophes(row);
     token = checkApostrophes(token);

     // Recupere l'id désiré
    res = stmt->executeQuery("SELECT "+id+" FROM "+table+" WHERE "+row+"='"+token+"'");
    if(res->next()) {              // S'il y a un resultat
        return res->getInt(id);    // On le retourne
    }
    return 0;
}



string Database::getPwd(string user) {
        // Recupere le mot de passe associé a l'utilisateur entré dans la table User
        res = stmt->executeQuery("SELECT password FROM User WHERE username='"+user+"'");

        if(res->next()) {                       // S'il y a un resultat valide
            return res->getString("password");  // On le retourne
        } else {                                // Sinon
            delete res;                         // On supprime le resultat
            return "";                          // Et on retourne une chaine vide
        }
}



void Database::addTheme(string newName) {
    newName = checkApostrophes(newName);

    // On ajoute le nouveau theme
    stmt->executeUpdate("INSERT INTO Theme (categorie) VALUES ('"+newName+"')");
}



void Database::addQuestion(string newQuestion, int idTheme) {
    newQuestion = checkApostrophes(newQuestion);
    // On ajoute la question et on l'associe au theme choisi
    stmt->executeUpdate("INSERT INTO Question (question, id_categorie) VALUES ('"+newQuestion+"', '"+to_string(idTheme)+"')");
}



void Database::addProp(string proposition, int goodAnswer, int idQuestion) {
    proposition = checkApostrophes(proposition);
    // Ajoute la proposition
    stmt->executeUpdate("INSERT INTO Proposition (proposition, bonne_reponse, id_question) VALUES ('"+proposition+"', '"+to_string(goodAnswer)+"', '"+to_string(idQuestion)+"')");
}



void Database::addUser(string username, string password, int checkAdmin) {
    username = checkApostrophes(username);

    password = md5(password); // Hachage du mot de passe
    if(checkAdmin) { // Si la checkbox est cochée
         // On ajoute l'utilisateur en admin
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','1')");
    } else {
         // Sinon on l'ajoute en non admin
        stmt->executeUpdate("INSERT INTO User (username, password, admin) VALUES ('"+username+"','"+password+"','0')");
    }
}



void Database::editTheme(string theme, string newName) {
    newName = checkApostrophes(newName);

    // On change le nom du theme entré par le nouveau
    stmt->executeUpdate("UPDATE Theme SET categorie='"+newName+"'WHERE categorie='"+theme+"'");
}



void Database::editQuestion(string newQuestion, int id_question) {
    newQuestion = checkApostrophes(newQuestion);
    // Change le nom de la question désirée
    stmt->executeUpdate("UPDATE Question SET question='"+newQuestion+"' WHERE id_question='"+to_string(id_question)+"'");
}



void Database::editProp(string proposition, int goodAnswer, int id_question, int id_proposition) {
    proposition = checkApostrophes(proposition);
    // Change la proposition choisie
    stmt->executeUpdate("UPDATE Proposition SET proposition='"+proposition+"', bonne_reponse ='"+to_string(goodAnswer)+"' WHERE id_question='"+to_string(id_question)+"' AND id_proposition='"+to_string(id_proposition)+"'");
}



void Database::editUser(string user, string newName, string newPwd, int checkAdmin) {
    newName = checkApostrophes(newName);
    if(checkAdmin) {     // Si la QCheckBox a été cochée
        if(newPwd=="") { // Si aucun nouveau mot de passe n'a été entré
             // On modifie le nom de l'utilisateur, et on le met admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='1' WHERE username='"+user+"'");
       } else { // Sinon (nouveau mot de passe entré)
            newPwd = md5(newPwd); // On hache le nouveau mot de passe
            // On modifie le nom et le mot de passe de l'utilisateur, et on le met admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='1' WHERE username='"+user+"'");
        }
   } else { // Sinon (QCheckBox pas cochée)
        if(newPwd=="") { // Si aucun nouveau mot de passe n'a été entré
               // On modifie le nom de l'utilisateur, et on le met non admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', admin='0' WHERE username='"+user+"'");
       } else { // Sinon (nouveau mot de passe entré)
            newPwd = md5(newPwd); // On hache le mot de passe
            // On modifie le nom et le mot de passe de l'utilisateur, et on le met non admin
            stmt->executeUpdate("UPDATE User SET username='"+newName+"', password='"+newPwd+"', admin='0' WHERE username='"+user+"'");
        }
    }
}



void Database::delTheme(int id_ctg) {
    string token;
    string id_categorie = to_string(id_ctg); // On convertit l'id en string pour l'utiliser dans les requetes

    // On recupere l'id des questions associées au theme
    res = stmt->executeQuery("SELECT id_question FROM Question WHERE id_categorie='"+id_categorie+"'");
    while(res->next()) { // Tant qu'il y a un resulat
        token = res->getString("id_question"); // On recupere l'id de la question
        stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+token+"'"); // Et on supprime les propositions associees
    }
    stmt->executeUpdate("DELETE FROM Question WHERE id_categorie='"+id_categorie+"'"); // On supprime les questions associées
    stmt->executeUpdate("DELETE FROM Theme WHERE id_categorie='"+id_categorie+"'"); // Puis le theme
}



void Database::delQuestion(string question, int id_question) {
    question = checkApostrophes(question);

    // Suppression des propositions associées a la question
    stmt->executeUpdate("DELETE FROM Proposition WHERE id_question='"+to_string(id_question)+"'");

    // Suppression de la question
    stmt->executeUpdate("DELETE FROM Question WHERE question='"+question+"'");
}



void Database::delProp(string proposition) {
    proposition = checkApostrophes(proposition);
    // Suppression de la proposition
    stmt->executeUpdate("DELETE FROM Proposition WHERE proposition='"+proposition+"'");
}



void Database::delUser(string username) {
    username = checkApostrophes(username);
    // Suppression de l'utilisateur
    stmt->executeUpdate("DELETE FROM User WHERE username='"+username+"'");
}



vector <Theme> Database::getThemes() {
    return themes;
}

vector <Question> Database::getQuestions() {
    return questions;
}

vector <Proposition> Database::getPropositions() {
     return propositions;
}

vector <User> Database::getUsers() {
    return users;
}

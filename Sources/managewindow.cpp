#include "../Headers/managewindow.hpp"
#include "../ui/ui_managewindow.h"

/*!
 * \file managewindow.cpp
 * \brief Fichier contenant les methodes de la classe ManageWindow
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

ManageWindow::ManageWindow(Database *dtb, QWidget *parent) : QMainWindow(parent), ui(new Ui::ManageWindow) {

    db = dtb;
    lastWindow = parent;
    checkAdmin = 0;


    ui->setupUi(this); // Mise en place des widgets

    // On remplit les QComboBox
    fillPickers();
    fillThemePicker2();
    fillUserPicker();

    // On cache certains widgets qui s'afficheront plus tard
    ui->goodAnswerPicker->hide();
    ui->addPropLineEdit->hide();
    ui->addPropButton->hide();
    ui->propPicker->hide();
    ui->editPropButton->hide();
    ui->editPropLineEdit->hide();
    ui->deletePropButton->hide();
    ui->goodAnswerPicker_2->hide();
    ui->goodAnswerPicker3->hide();
    ui->addPropLineEdit2->hide();
    ui->addPropButton2->hide();
    ui->addPropLabel->hide();
    ui->editPropLabel->hide();
    ui->addPropLabel2->hide();
}



ManageWindow::~ManageWindow() {
    delete ui;
}




bool ManageWindow::checkSyntax(string question) {
    if(count(question.begin(), question.end(), ',') == 2) { // On comptele nombre de virgules, se resultat vaut 2
        return true;                                        // On retourne true
   } else return false;                                     // Sinon on retourne false
}



void ManageWindow::fillPickers() {

     // On recupere les themes
    db->listThemes();
    themes = db->getThemes();

    // On recupere les questions
    db->listQuestions_order_by_Categorie();
    questions = db->getQuestions();

    // On vide les QComboBox existants (pour permettre l'actualisation des données)
    ui->themePicker->clear();
    ui->questionPicker->clear();

    // On vide les QLineEdit
    ui->themeLineEdit->clear();
    ui->newThemeLineEdit->clear();
    ui->usernameLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->newUsernameLineEdit->clear();
    ui->newPwdLineEdit->clear();

    // On ajout les premiers index
    ui->themePicker->addItem(tr("Choisissez une theme"));
    ui->questionPicker->addItem(tr("Choisissez une question"));

    // Creation d'un vecteur pour recuper les index à désactiver
    std::vector<int> indexToChange;
    size_t k = 1;

    // Pour chaque theme
    for(size_t i=0 ; i < themes.size() ; i++) {
        ui->themePicker->addItem(QString::fromStdString(themes[i].getCategorie())); // On ajoute les theme dans le premier QComboBox
        ui->questionPicker->addItem("-------"+QString::fromStdString(themes[i].getCategorie())+"-------"); // Puis dans le deuxieme
        indexToChange.push_back(k); // On récupere l'index actuel
        k++; // On incrémente le compteur

        // Et pour chaque question
        for(size_t j=0 ; j < questions.size() ; j++) {
            if(questions[j].getIdCategorie() == themes[i].getIdCategorie()) { // Si la question est dans le theme actuel
                ui->questionPicker->addItem(QString::fromStdString(questions[j].getQuestion())); // On l'insere dans le QComboBox
                k++; // Et on increment le compteur
            }
        }
    }

    // Desactivation des index récupérés (pour que l'utilisateur ne puisse pas selectionner de theme dans le QComboBox de questions)
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->questionPicker->model());
        bool disabled= true;
        for(size_t i=0; i < indexToChange.size();i++){
            QStandardItem* item= model->item(indexToChange[i]);
            item->setFlags(disabled? item->flags() & ~Qt::ItemIsEnabled:item->flags() | Qt::ItemIsEnabled);
        }

    if(!ui->themePicker->currentIndex()){         // Si l'utilisateur n'a pas choisi de theme
        ui->themeLineEdit->setReadOnly(true);     // Il ne peut pas ecrire dans le QLineEdit
    }

    // De meme pour l'edition des profils
    if(!ui->userPicker->currentIndex()) {
        ui->usernameLineEdit->setReadOnly(true);
        ui->pwdLineEdit->setReadOnly(true);
    }
}




void ManageWindow::fillThemePicker2() {
    ui->themePicker2->clear(); // On vide le QComboBox
    ui->themePicker2->addItem(tr("Choisissez une theme")); // on ajoute le premier index

    // Pour chaque theme
    for(int i=0 ; i < (int)themes.size() ; i++) {
        ui->themePicker2->addItem(QString::fromStdString(themes[i].getCategorie())); // On l'ajoute dans le QComboBox
    }

    if(!ui->themePicker2->currentIndex()){             // Si l'utilisateur n'a pas choisi de theme
        ui->addQuestionLineEdit->setReadOnly(true);    // Il ne peut pas ecrire dans les QLineEdit
        ui->addPropLineEdit->setReadOnly(true);
    }
}



void ManageWindow::fillAnswerPicker(string question) {
    ui->goodAnswerPicker->clear(); // On vide le selecteur de reponses
    ui->goodAnswerPicker->addItem("Choisissez la bonne reponse"); // On ajoute le premier index

    if(question != "") {           // Si la question n'est pas vide
        string delimiter = ",";    // On définit le délimiteur en tant que virgule
        size_t pos = 0;            // On initialise le compteur de position à 0
        string token;

        // Tant qu'il n'a pas fini de parcourir la chaine et des qu'il trouve une virgule
        while((pos = question.find(delimiter)) != string::npos) {
            token = question.substr(0, pos); // On recupere la premiere partie de la chaine jusqu'a la virgule
            ui->goodAnswerPicker->addItem(QString::fromStdString(token)); // On l'ajoute au selecteur
            question.erase(0,pos + delimiter.length()); // Et on efface cette premiere partie de chaine
        }

        ui->goodAnswerPicker->addItem(QString::fromStdString(question)); // On ajoute au selecteur la partie restante de la chaine

        if(!ui->themePicker2->currentIndex()){              // Si l'utilisateur n'a pas choisi de theme
            ui->addQuestionLineEdit->setReadOnly(true);     // Il ne peut pas ecrire dans les QLineEdit
            ui->addPropLineEdit->setReadOnly(true);
        }
    }
}



void ManageWindow::fillAnswerPicker23(string question) {
    ui->goodAnswerPicker_2->clear();
    ui->goodAnswerPicker_2->addItem("Choisissez la bonne reponse");
    ui->goodAnswerPicker3->clear();
    ui->goodAnswerPicker3->addItem("Choisissez la bonne reponse");

    if(question != "") {
        string delimiter = ",";
        size_t pos = 0;

        string token;

        while((pos = question.find(delimiter)) != string::npos) {
            token = question.substr(0, pos);
            ui->goodAnswerPicker_2->addItem(QString::fromStdString(token));
            ui->goodAnswerPicker3->addItem(QString::fromStdString(token));
            question.erase(0,pos + delimiter.length());
        }
        ui->goodAnswerPicker_2->addItem(QString::fromStdString(question));
        ui->goodAnswerPicker3->addItem(QString::fromStdString(question));
    }
}



void ManageWindow::fillPropPicker(string question) {
    ui->propPicker->clear();
    ui->propPicker->addItem("Choisissez la proposition");
    ui->editPropLineEdit->clear();

    int id_question = db->getId("id_question", "Question", "question", question); // On recupere l'id de la question

    // On recupere les propositions associées
    db->listPropositions(id_question);
    propositions = db->getPropositions();

    // Pour chaque proposition
    for(size_t i=0 ; i < propositions.size() ; i++) {
        ui->propPicker->addItem(QString::fromStdString(propositions[i].getProposition())); // On l'ajoute au selecteur
    }
}



void ManageWindow::fillUserPicker() {

     // On recupere la liste des utilisateurs
    db->listUsers();
    users = db->getUsers();

    ui->userPicker->clear();
    ui->userPicker->addItem("Choisissez un utilisateur");

    // Pour chaque utilisateur
    for(int i=0 ; i < (int)users.size() ; i++) {
        ui->userPicker->addItem(QString::fromStdString(users[i].getUsername())); // On l'ajoute au selecteur
    }
}



void ManageWindow::on_logoutButton_clicked() {
    lastWindow->show(); // On affiche la fenetre de connexion
    this->deleteLater(); // On efface celle-ci
}



void ManageWindow::on_themePicker_activated(const QString &statement) {
    if(ui->themePicker->currentIndex()) {         // Si l'utilisateur a choisi un theme
        ui->themeLineEdit->setReadOnly(false);    // On rend le QLineEdit editable
        selectedTheme = statement.toStdString();  // On recupere le theme
        ui->themeLineEdit->setText(statement);    // On remplit le QLineEdit avec ce theme
        ui->themeLineEdit->setFocus();            // On met le focus sur le QLineEdit
   } else{                                        // Sinon
        ui->themeLineEdit->setReadOnly(true);     // On rend le QLineEdit non editable
        ui->themeLineEdit->clear();               // Et on le vide
    }
}


//Meme principe
void ManageWindow::on_themePicker2_activated(const QString &statement){
    if(ui->themePicker2->currentIndex()) {
        ui->addQuestionLineEdit->setReadOnly(false);
         ui->addPropLineEdit->setReadOnly(false);
        selectedTheme = statement.toStdString();
    } else{
        ui->addQuestionLineEdit->setReadOnly(true);
        ui->addPropLineEdit->setReadOnly(true);
        ui->addQuestionLineEdit->clear();
        ui->addPropLineEdit->clear();

        //On cache certains widgets
        ui->goodAnswerPicker->hide();
        ui->addPropLineEdit->hide();
        ui->addPropButton->hide();
        ui->addPropLabel2->hide();
    }
}


//Meme principe
void ManageWindow::on_questionPicker_activated(const QString &statement) {
    if(ui->questionPicker->currentIndex()) {
        selectedQuestion = statement.toStdString();
        ui->editQuestionLineEdit->setReadOnly(false);
        ui->editQuestionLineEdit->setText(statement);
        ui->editQuestionLineEdit->setFocus();
        fillPropPicker(selectedQuestion);
        fillAnswerPicker23(selectedQuestion);
        ui->propPicker->show();
        ui->editPropButton->show();
        ui->editPropLineEdit->show();
        ui->deletePropButton->show();
        ui->goodAnswerPicker_2->show();
        ui->addPropLineEdit2->show();
        ui->addPropButton2->show();
        ui->editPropLineEdit->clear();
        ui->addPropLineEdit2->clear();
        ui->goodAnswerPicker3->show();
        ui->addPropLabel->show();
        ui->editPropLabel->show();
    } else {
        ui->editQuestionLineEdit->clear();
        ui->editPropLineEdit->clear();
        ui->editQuestionLineEdit->setReadOnly(true);
        selectedQuestion =""; // Chaine vide s'il selectionne "Choisissez.."
        ui->propPicker->hide();
        ui->editPropButton->hide();
        ui->editPropLineEdit->hide();
        ui->deletePropButton->hide();
        ui->goodAnswerPicker_2->hide();
        ui->addPropLineEdit2->hide();
        ui->addPropButton2->hide();
        ui->goodAnswerPicker3->hide();
        ui->addPropLabel->hide();
        ui->editPropLabel->hide();
    }
}


//Meme principe
void ManageWindow::on_propPicker_activated(const QString &statement) {
    if(ui->propPicker->currentIndex()) {
        selectedProposition = statement.toStdString();
        ui->editPropLineEdit->setReadOnly(false);
        ui->editPropLineEdit->setText(statement);
        ui->editPropLineEdit->setFocus();
    } else {
        ui->editPropLineEdit->clear();
        ui->editPropLineEdit->setReadOnly(true);
        selectedProposition = ""; // Chaine vide s'il selectionne "Choisissez.."
    }
}


//Meme principe
void ManageWindow::on_userPicker_activated(const QString &statement) {
    if(ui->userPicker->currentIndex()) {
        ui->usernameLineEdit->setReadOnly(false);
        ui->pwdLineEdit->setReadOnly(false);
        selectedUser = statement.toStdString();
        ui->usernameLineEdit->setText(statement);
        newUsername = ui->usernameLineEdit->text().toStdString();
        pwd = db->getPwd(selectedUser); // On recupere le mot de passe de l'utilisateur selectionné
        if(db->testAdmin(selectedUser, pwd)) {
            ui->makeAdminCheckBox->setCheckState(Qt::Checked);
        } else {
            ui->makeAdminCheckBox->setCheckState(Qt::Unchecked);
        }
    } else {
        ui->usernameLineEdit->setReadOnly(true);
        ui->usernameLineEdit->clear();
        ui->pwdLineEdit->setReadOnly(true);
        ui->pwdLineEdit->clear();
    }
}




void ManageWindow::on_newThemeLineEdit_editingFinished() {
    newThemeName = ui->newThemeLineEdit->text().toStdString();
}

void ManageWindow::on_addQuestionLineEdit_editingFinished() {
    newQuestion = ui->addQuestionLineEdit->text().toStdString();
    fillAnswerPicker(newQuestion); //On actualise les selecteurs
}

void ManageWindow::on_addPropLineEdit_editingFinished() {
    proposition = ui->addPropLineEdit->text().toStdString();
}

void ManageWindow::on_addPropLineEdit2_editingFinished() {
    proposition = ui->addPropLineEdit2->text().toStdString();
}

void ManageWindow::on_newUsernameLineEdit_editingFinished() {
    newUsername = ui->newUsernameLineEdit->text().toStdString();
}

void ManageWindow::on_newPwdLineEdit_editingFinished() {
    newPwd = ui->newPwdLineEdit->text().toStdString();
}





void ManageWindow::on_themeLineEdit_editingFinished() {
    newThemeName = ui->themeLineEdit->text().toStdString();
}

void ManageWindow::on_editQuestionLineEdit_editingFinished() {
    newQuestion = ui->editQuestionLineEdit->text().toStdString();
    fillAnswerPicker23(newQuestion); //On actualise les selecteurs
}

void ManageWindow::on_editPropLineEdit_editingFinished() {
    proposition = ui->editPropLineEdit->text().toStdString();
}

void ManageWindow::on_usernameLineEdit_editingFinished(){
    newUsername = ui->usernameLineEdit->text().toStdString();
}

void ManageWindow::on_pwdLineEdit_editingFinished(){
    newPwd = ui->pwdLineEdit->text().toStdString();
}




void ManageWindow::on_testAdminCheckbox_stateChanged(int state) {
    checkAdmin = state; // On recupere l'etat de la QCheckBox
}

void ManageWindow::on_makeAdminCheckBox_stateChanged(int state) {
    checkAdmin = state;
}




void ManageWindow::on_addThemeButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->newThemeLineEdit->text() != "") { // Si le texte n'est pas vide
        reply = QMessageBox::question(this, "Confirmer", "Ajouter le theme ?", QMessageBox::Yes|QMessageBox::No); // Message de confirmation
        if (reply == QMessageBox::Yes) {     // Si la reponse est oui
            db->addTheme(newThemeName);      // On ajoute le theme
            fillPickers();                   // On actualise les selecteurs
            fillThemePicker2();
        }
   } else { // Sinon
        // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}




void ManageWindow::on_addQuestionButton_clicked() {
    QMessageBox::StandardButton reply;
    // Si la syntaxe est bonne et que la question n'existe pas en bdd
    if(checkSyntax(ui->addQuestionLineEdit->text().toStdString()) && !db->checkIfExists("Question", "question", newQuestion)) {
         // Message de confirmation
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la question ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
             // Ajout de la question
            db->addQuestion(newQuestion, db->getId("id_categorie", "Theme", "categorie", selectedTheme));
            fillPickers(); // On actualise les selecteurs
            ui->goodAnswerPicker->show();    // On affiche les widgets d'ajout de propositions
            ui->addPropLineEdit->show();
            ui->addPropButton->show();
            ui->addPropLabel2->show();
        }
   } else if (ui->addQuestionLineEdit->text() == ""){ // Sinon si le texte est vide
        // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
   } else if (db->checkIfExists("Question", "question", newQuestion)) { // Sinon si la question existe
        // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Cette question existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
    }
    else { // Sinon
         // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Erreur de syntaxe. Format: Reponse1,Reponse2,les deux", QMessageBox::Cancel|QMessageBox::Ok);
    }
}




void ManageWindow::on_addPropButton_clicked() {
    QMessageBox::StandardButton reply;
    //Si le texte n'est pas vide et que l'utilisateur a choisi une bonne reponse
    if(ui->addPropLineEdit->text() != "" && ui->goodAnswerPicker->currentIndex()) {
         // Confirmation
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) { // Si confirmé
             // Ajout
           db->addProp(proposition, ui->goodAnswerPicker->currentIndex(), db->getId("id_question", "Question", "question", newQuestion));
           ui->addPropLineEdit->clear();
        }
   } else if (ui->addPropLineEdit->text() == ""){ // Sinon si texte vide
        // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
   } else { // Sinon
        // Message d'erreur
        reply = QMessageBox::question(this, "Erreur", "Veuillez choisir la bonne réponse.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



//Meme principe
void ManageWindow::on_addPropButton2_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->addPropLineEdit2->text() != "" && !db->checkIfExists("Proposition", "proposition", proposition) && ui->goodAnswerPicker3->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addProp(proposition, 2, db->getId("id_question", "Question", "question", selectedQuestion));
            fillPropPicker(selectedQuestion);
        }
    } else if(db->checkIfExists("Proposition", "proposition", proposition)) {
        reply = QMessageBox::question(this, "Erreur", "Cette question existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
    } else if(!ui->goodAnswerPicker3->currentIndex()){
        reply = QMessageBox::question(this, "Erreur", "Veuillez choisir une bonne reponse.", QMessageBox::Cancel|QMessageBox::Ok);
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



//Meme principe
void ManageWindow::on_addUserButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->newUsernameLineEdit->text() != "" && !db->checkIfExists("User", "username", ui->newUsernameLineEdit->text().toStdString()) && ui->newPwdLineEdit->text().length() > 5 && ui->newUsernameLineEdit->text().length() < 15) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter l'utilisateur ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addUser(newUsername, newPwd, checkAdmin);
            fillUserPicker();
            ui->newUsernameLineEdit->clear();
            ui->newPwdLineEdit->clear();
        }
    } else if(db->checkIfExists("User", "username", ui->newUsernameLineEdit->text().toStdString())){
        reply = QMessageBox::question(this, "Erreur", "Cet utilisateur existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
   } else if(ui->newUsernameLineEdit->text().length() >= 15){
         reply = QMessageBox::question(this, "Erreur", "Votre nom d'utilisateur est trop long.", QMessageBox::Cancel|QMessageBox::Ok);
   } else if (ui->newPwdLineEdit->text().length() <= 5){
        reply = QMessageBox::question(this, "Erreur", "Votre mot de passe est trop court.", QMessageBox::Cancel|QMessageBox::Ok);
   } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
   }
}



//Meme principe
void ManageWindow::on_themeEditButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->themePicker->currentIndex() && !db->checkIfExists("Theme", "categorie", newThemeName) && newThemeName != "") {
        reply = QMessageBox::question(this, "Confirmer", "Effectuer la modificiation ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editTheme(selectedTheme, newThemeName);
            fillPickers();
            fillThemePicker2();
        }
   } else if(db->checkIfExists("Theme", "categorie", newThemeName)) {
        reply = QMessageBox::question(this, "Erreur", "Ce theme existe deja", QMessageBox::Cancel|QMessageBox::Ok);
   } else if(newThemeName == "") {
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir le champ", QMessageBox::Cancel|QMessageBox::Ok);
   } else {
          reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un theme.", QMessageBox::Cancel|QMessageBox::Ok);
   }
}



//Meme principe
void ManageWindow::on_editQuestionButton_clicked() {
    QMessageBox::StandardButton reply;
    if(checkSyntax(newQuestion) && !db->checkIfExists("Question", "question", newQuestion)) {
        reply = QMessageBox::question(this, "Confirmer", "Modifier la question ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editQuestion(newQuestion, db->getId("id_question", "Question", "question", selectedQuestion));
            fillPickers();
            ui->editQuestionLineEdit->clear();
            on_questionPicker_activated("");
        }
    } else if (ui->editQuestionLineEdit->text() == ""){
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    } else if (db->checkIfExists("Question", "question", newQuestion)) {
        reply = QMessageBox::question(this, "Erreur", "Cette question existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
    }
    else {
        reply = QMessageBox::question(this, "Erreur", "Erreur de syntaxe. Format: Reponse1,Reponse2,les deux", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



//Meme principe
void ManageWindow::on_editPropButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->editPropLineEdit->text() != "" && ui->goodAnswerPicker_2->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Modifier la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editProp(proposition, ui->goodAnswerPicker_2->currentIndex(), db->getId("id_question", "Question", "question", selectedQuestion), db->getId("id_proposition", "Proposition", "proposition", selectedProposition));
            fillPropPicker(selectedQuestion);
        }
    } else{
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}




//Meme principe
void ManageWindow::on_editUserPushButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->userPicker->currentIndex() && ui->usernameLineEdit->text().length() < 10 && ui->usernameLineEdit->text() != "") {
        reply = QMessageBox::question(this, "Confirmer", "Effectuer la modificiation ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editUser(selectedUser, newUsername, newPwd, checkAdmin);
            fillUserPicker();
            ui->makeAdminCheckBox->setCheckState(Qt::Unchecked);
            ui->usernameLineEdit->clear();
            ui->pwdLineEdit->clear();
        }
   } else if(ui->usernameLineEdit->text().length() >= 10) {
        reply = QMessageBox::question(this, "Erreur", "Le nom d'utilisateur est trop long.", QMessageBox::Cancel|QMessageBox::Ok);
   } else if(ui->usernameLineEdit->text() == "") {
        reply = QMessageBox::question(this, "Erreur", "Le nom d'utilisateur est trop court.", QMessageBox::Cancel|QMessageBox::Ok);
   } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un utilisateur.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



//Meme principe pour la suppression
void ManageWindow::on_deleteThemeButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->themePicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer ce theme ?\nAttention, cela supprimera aussi les questions associees et leurs propositions.", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delTheme(db->getId("id_categorie", "Theme", "categorie", selectedTheme));
            fillPickers();
            fillThemePicker2();
            ui->themeLineEdit->clear();
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un theme.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



// Meme principe
void ManageWindow::on_deleteQuestionButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->questionPicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer cette question ?\nAttention, cela supprimera aussi les propositions associees.", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delQuestion(selectedQuestion, db->getId("id_question", "Question", "question", selectedQuestion));
            fillPickers();
            ui->editQuestionLineEdit->clear();
            on_questionPicker_activated("");
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner une question.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}




// Meme principe
void ManageWindow::on_deletePropButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->propPicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer cette proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delProp(selectedProposition);
            ui->editPropLineEdit->setReadOnly(true);
            fillPropPicker(selectedQuestion);
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner une proposition.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}



// Meme principe
void ManageWindow::on_deleteUserButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->userPicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer cet utilisateur ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delUser(selectedUser);
            ui->usernameLineEdit->clear();
            ui->makeAdminCheckBox->setCheckState(Qt::Unchecked);
            fillUserPicker();
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un utilisateur.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

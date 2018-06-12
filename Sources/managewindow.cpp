#include "../Headers/managewindow.hpp"
#include "../ui/ui_managewindow.h"

ManageWindow::ManageWindow(Database *dtb, QWidget *parent) : QMainWindow(parent), ui(new Ui::ManageWindow) {

    db = dtb;
    checkAdmin = 0;


    ui->setupUi(this);
    lastWindow = parent;

    fillPickers();
    fillThemePicker2();
    fillUserPicker();

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

void ManageWindow::fillPickers() {

    db->listThemes();
    themes = db->getThemes();

    db->listQuestions_order_by_Categorie();
    questions = db->getQuestions();

    ui->themePicker->clear();
    ui->questionPicker->clear();

    ui->themeLineEdit->clear();
    ui->newThemeLineEdit->clear();
    ui->usernameLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->newUsernameLineEdit->clear();
    ui->newPwdLineEdit->clear();

    ui->themePicker->addItem("Choisissez une theme");
    ui->questionPicker->addItem("Choisissez une question");

    std::vector<int> indexToChange;
    size_t k = 1;

    for(size_t i=0 ; i < themes.size() ; i++) {
        ui->themePicker->addItem(QString::fromStdString(themes[i].getCategorie()));
        ui->questionPicker->addItem("-------"+QString::fromStdString(themes[i].getCategorie())+"-------");
        indexToChange.push_back(k);
        k++;
        for(size_t j=0 ; j < questions.size() ; j++) {
            if(questions[j].getIdCategorie() == themes[i].getIdCategorie()) {
                ui->questionPicker->addItem(QString::fromStdString(questions[j].getQuestion()));
                k++;
            }
        }
    }


    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->questionPicker->model());
        bool disabled= true;
        for(size_t i=0; i < indexToChange.size();i++){
            QStandardItem* item= model->item(indexToChange[i]);
            item->setFlags(disabled? item->flags() & ~Qt::ItemIsEnabled:item->flags() | Qt::ItemIsEnabled);
        }

    if(!ui->themePicker->currentIndex()){
        ui->themeLineEdit->setReadOnly(true);
    }

    if(!ui->userPicker->currentIndex()) {
        ui->usernameLineEdit->setReadOnly(true);
        ui->pwdLineEdit->setReadOnly(true);
    }
}

void ManageWindow::fillThemePicker2() {
    ui->themePicker2->clear();
    ui->themePicker2->addItem("Choisissez une theme");

    for(int i=0 ; i < (int)themes.size() ; i++) {
        ui->themePicker2->addItem(QString::fromStdString(themes[i].getCategorie()));
    }

    if(!ui->themePicker2->currentIndex()){
        ui->addQuestionLineEdit->setReadOnly(true);
        ui->addPropLineEdit->setReadOnly(true);
    }
}

void ManageWindow::fillUserPicker() {
    db->listUsers();
    users = db->getUsers();

    ui->userPicker->clear();
    ui->userPicker->addItem("Choisissez un utilisateur");

    for(int i=0 ; i < (int)users.size() ; i++) {
        ui->userPicker->addItem(QString::fromStdString(users[i].getUsername()));
    }
}

void ManageWindow::fillPropPicker(string question) {
    ui->propPicker->clear();
    ui->propPicker->addItem("Choisissez la proposition");
    ui->editPropLineEdit->clear();

    int id_question = db->getIdQuestion(question);

    db->listPropositions(id_question);
    propositions = db->getPropositions();

    for(size_t i=0 ; i < propositions.size() ; i++) {
        ui->propPicker->addItem(QString::fromStdString(propositions[i].getProposition()));
    }
}

void ManageWindow::fillAnswerPicker(string question) {
    ui->goodAnswerPicker->clear();
    ui->goodAnswerPicker->addItem("Choisissez la bonne reponse");

    if(question != "") {
        string delimiter = ",";
        size_t pos = 0;

        string token;

        while((pos = question.find(delimiter)) != string::npos) {
            token = question.substr(0, pos);
            ui->goodAnswerPicker->addItem(QString::fromStdString(token));
            question.erase(0,pos + delimiter.length());
        }

        ui->goodAnswerPicker->addItem(QString::fromStdString(question));

        if(!ui->themePicker2->currentIndex()){
            ui->addQuestionLineEdit->setReadOnly(true);
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

void ManageWindow::on_logoutButton_clicked() {
    lastWindow->show();
    this->deleteLater();
}

void ManageWindow::on_themePicker_activated(const QString &arg1) {
    if(ui->themePicker->currentIndex()) {
        ui->themeLineEdit->setReadOnly(false);
        selectedTheme = arg1.toStdString();
        ui->themeLineEdit->setText(arg1);
    } else{
        ui->themeLineEdit->setReadOnly(true);
        ui->themeLineEdit->clear();
    }
}

void ManageWindow::on_themeLineEdit_editingFinished() {
    newThemeName = ui->themeLineEdit->text().toStdString();
}

void ManageWindow::on_themeEditButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->themePicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Effectuer la modificiation ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editTheme(selectedTheme, newThemeName);
            fillPickers();
            fillThemePicker2();
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un theme.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

void ManageWindow::on_newThemeLineEdit_editingFinished() {
    newThemeName = ui->newThemeLineEdit->text().toStdString();
}

void ManageWindow::on_addThemeButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->newThemeLineEdit->text() != "") {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter le theme ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addTheme(newThemeName);
            fillPickers();
            fillThemePicker2();
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}


void ManageWindow::on_userPicker_activated(const QString &arg1) {
    if(ui->userPicker->currentIndex()) {
        ui->usernameLineEdit->setReadOnly(false);
        ui->pwdLineEdit->setReadOnly(false);
        selectedUser = arg1.toStdString();
        ui->usernameLineEdit->setText(arg1);
        newUsername = ui->usernameLineEdit->text().toStdString();
        pwd = db->getPwd(selectedUser);
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

void ManageWindow::on_editUserPushButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->userPicker->currentIndex() && ui->usernameLineEdit->text().length() > 5) {
        reply = QMessageBox::question(this, "Confirmer", "Effectuer la modificiation ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editUser(selectedUser, newUsername, newPwd, checkAdmin);
            fillUserPicker();
            ui->makeAdminCheckBox->setCheckState(Qt::Unchecked);
            ui->usernameLineEdit->clear();
            ui->pwdLineEdit->clear();
        }
    } else if(ui->usernameLineEdit->text().length() <= 5) {
        reply = QMessageBox::question(this, "Erreur", "Le nom d'utilisateur est trop court.", QMessageBox::Cancel|QMessageBox::Ok);
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un utilisateur.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

void ManageWindow::on_usernameLineEdit_editingFinished(){
    newUsername = ui->usernameLineEdit->text().toStdString();
}

void ManageWindow::on_pwdLineEdit_editingFinished(){
    newPwd = ui->pwdLineEdit->text().toStdString();
}

void ManageWindow::on_newUsernameLineEdit_editingFinished() {
    newUsername = ui->newUsernameLineEdit->text().toStdString();
}

void ManageWindow::on_newPwdLineEdit_editingFinished() {
    newPwd = ui->newPwdLineEdit->text().toStdString();
}

void ManageWindow::on_testAdminCheckbox_stateChanged(int arg1) {
    checkAdmin = arg1;
}

void ManageWindow::on_addUserButton_clicked() {

    QMessageBox::StandardButton reply;
    if(ui->newUsernameLineEdit->text() != "" && ui->newPwdLineEdit->text() != "" && !db->checkIfExists("User", "username", ui->newUsernameLineEdit->text().toStdString()) && ui->newPwdLineEdit->text().length() > 5) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter l'utilisateur ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addUser(newUsername, newPwd, checkAdmin);
            fillUserPicker();
            ui->newUsernameLineEdit->clear();
            ui->newPwdLineEdit->clear();
        }
    } else if(db->checkIfExists("User", "username", ui->newUsernameLineEdit->text().toStdString())){
        reply = QMessageBox::question(this, "Erreur", "Cet utilisateur existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
    } else if(ui->newPwdLineEdit->text().length() <= 5){

        reply = QMessageBox::question(this, "Erreur", "Votre mot de passe est trop court.", QMessageBox::Cancel|QMessageBox::Ok);
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

void ManageWindow::on_themePicker2_activated(const QString &arg1){
    if(ui->themePicker2->currentIndex()) {
        ui->addQuestionLineEdit->setReadOnly(false);
         ui->addPropLineEdit->setReadOnly(false);
        selectedTheme = arg1.toStdString();
    } else{
        ui->addQuestionLineEdit->setReadOnly(true);
        ui->addPropLineEdit->setReadOnly(true);
        ui->addQuestionLineEdit->clear();
        ui->addPropLineEdit->clear();
        ui->goodAnswerPicker->hide();
        ui->addPropLineEdit->hide();
        ui->addPropButton->hide();
        ui->addPropLabel2->hide();
    }
}

void ManageWindow::on_addQuestionLineEdit_editingFinished() {
    newQuestion = ui->addQuestionLineEdit->text().toStdString();
    fillAnswerPicker(newQuestion);
}

void ManageWindow::on_addPropLineEdit_editingFinished() {
    proposition = ui->addPropLineEdit->text().toStdString();
}

void ManageWindow::on_addQuestionButton_clicked() {

    QMessageBox::StandardButton reply;
    if(checkSyntax(ui->addQuestionLineEdit->text().toStdString()) && !db->checkIfExists("Question", "question", newQuestion)) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la question ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addQuestion(newQuestion, db->getIdTheme(selectedTheme));
            fillPickers();
            ui->goodAnswerPicker->show();
            ui->addPropLineEdit->show();
            ui->addPropButton->show();
            ui->addPropLabel2->show();
        }
    } else if (ui->addQuestionLineEdit->text() == ""){
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    } else if (db->checkIfExists("Question", "question", newQuestion)) {
        reply = QMessageBox::question(this, "Erreur", "Cette question existe deja.", QMessageBox::Cancel|QMessageBox::Ok);
    }
    else {
        reply = QMessageBox::question(this, "Erreur", "Erreur de syntaxe. Format: Reponse1,Reponse2,les deux", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

void ManageWindow::on_addPropButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->addPropLineEdit->text() != "" && ui->goodAnswerPicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
           db->addProp(proposition, ui->goodAnswerPicker->currentIndex(), db->getIdQuestion(newQuestion));
           ui->addPropLineEdit->clear();
        }
    } else if (ui->addPropLineEdit->text() == ""){
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez choisir la bonne réponse.", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

int ManageWindow::checkSyntax(string question) {
    if(count(question.begin(), question.end(), ',')==2) {
        return 1;
    } else return 0;
}

void ManageWindow::on_questionPicker_activated(const QString &arg1) {
    if(ui->questionPicker->currentIndex()) {
        selectedQuestion = arg1.toStdString();
        ui->editQuestionLineEdit->setReadOnly(false);
        ui->editQuestionLineEdit->setText(arg1);
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
        selectedQuestion ="";
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

void ManageWindow::on_editQuestionLineEdit_editingFinished() {
    newQuestion = ui->editQuestionLineEdit->text().toStdString();
    fillAnswerPicker23(newQuestion);
}

void ManageWindow::on_editQuestionButton_clicked() {
    QMessageBox::StandardButton reply;
    if(checkSyntax(newQuestion) && !db->checkIfExists("Question", "question", newQuestion)) {
        reply = QMessageBox::question(this, "Confirmer", "Modifier la question ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editQuestion(newQuestion, db->getIdQuestion(selectedQuestion));
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

void ManageWindow::on_propPicker_activated(const QString &arg1) {
    if(ui->propPicker->currentIndex()) {
        selectedProposition = arg1.toStdString();
        ui->editPropLineEdit->setReadOnly(false);
        ui->editPropLineEdit->setText(arg1);
        ui->editPropLineEdit->setFocus();
    } else {
        ui->editPropLineEdit->clear();
        ui->editPropLineEdit->setReadOnly(true);
        selectedProposition ="";
    }
}

void ManageWindow::on_editPropButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->editPropLineEdit->text() != "" && ui->goodAnswerPicker_2->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Modifier la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->editProp(proposition, ui->goodAnswerPicker_2->currentIndex(), db->getIdQuestion(selectedQuestion), db->getIdProposition(selectedProposition));
            fillPropPicker(selectedQuestion);
        }
    } else if (ui->editQuestionLineEdit->text() == "" || !ui->goodAnswerPicker_2->currentIndex()){
        reply = QMessageBox::question(this, "Erreur", "Veuillez remplir les champs.", QMessageBox::Cancel|QMessageBox::Ok);
    } else {
        reply = QMessageBox::question(this, "Erreur", "Erreur de syntaxe. Format: Reponse1,Reponse2,les deux", QMessageBox::Cancel|QMessageBox::Ok);
    }
}

void ManageWindow::on_editPropLineEdit_editingFinished() {
    proposition = ui->editPropLineEdit->text().toStdString();
}

void ManageWindow::on_addPropLineEdit2_editingFinished() {
    proposition = ui->addPropLineEdit2->text().toStdString();
}

void ManageWindow::on_addPropButton2_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->addPropLineEdit2->text() != "" && !db->checkIfExists("Proposition", "proposition", proposition) && ui->goodAnswerPicker3->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Ajouter la proposition ?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->addProp(proposition, 2, db->getIdQuestion(selectedQuestion));
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
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un utilisateur.", QMessageBox::Yes|QMessageBox::No);
    }
}

void ManageWindow::on_makeAdminCheckBox_stateChanged(int state) {
    checkAdmin = state;
}

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
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner une proposition.", QMessageBox::Yes|QMessageBox::No);
    }
}

void ManageWindow::on_deleteQuestionButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->questionPicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer cette question ?\nAttention, cela supprimera aussi les propositions associees.", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delQuestion(selectedQuestion, db->getIdQuestion(selectedQuestion));
            fillPickers();
            ui->editQuestionLineEdit->clear();
            on_questionPicker_activated("");
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner une question.", QMessageBox::Yes|QMessageBox::No);
    }
}

void ManageWindow::on_deleteThemeButton_clicked() {
    QMessageBox::StandardButton reply;
    if(ui->themePicker->currentIndex()) {
        reply = QMessageBox::question(this, "Confirmer", "Supprimer ce theme ?\nAttention, cela supprimera aussi les questions associees et leurs propositions.", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            db->delTheme(db->getIdTheme(selectedTheme));
            fillPickers();
            fillThemePicker2();
            ui->themeLineEdit->clear();
        }
    } else {
        reply = QMessageBox::question(this, "Erreur", "Veuillez selectionner un theme.", QMessageBox::Yes|QMessageBox::No);
    }
}

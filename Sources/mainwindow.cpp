#include "../Headers/mainwindow.hpp"
#include "../ui/ui_mainwindow.h"

/*!
 * \file mainwindow.cpp
 * \brief Fichier contenant les methodes de la classe MainWindow
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    readConfFile(); // Lecture du fichier de configuration
    ui->setupUi(this); // Mise en place des widgets

    // Remplissage des LineEdit de l'ip et du nom de la BDD (texte récupéré du fichier de configuration)
    ui->ipLineEdit->setText(QString::fromStdString(ipAddress));
    ui->dbnameLineEdit->setText(QString::fromStdString(dbName));
}



MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::readConfFile() {

    ifstream file("Ressources/conf.txt", ios::in); // Ouverture du fichier

    if(!file.fail()) {                       // Si l'ouverture n'a pas échouée
        getline(file, ipAddress);            // On lit les deux lignes
        getline(file, dbName);

        ipAddress = ipAddress.substr(3);     // Et on recupere uniquement les chaines necessaires
        dbName = dbName.substr(7);

        file.close();                        // Puis on ferme le fichier
    }
    else cerr<<"File 'Ressources/conf.txt' doesn't exists"<<endl; // Sinon, message d'erreur en console
}



void MainWindow::on_ipLineEdit_editingFinished() {
    ipAddress = ui->ipLineEdit->text().toStdString(); // Adresse ip
}

void MainWindow::on_dbnameLineEdit_editingFinished() {
    dbName = ui->dbnameLineEdit->text().toStdString(); // Nom de la BDD
}

void MainWindow::on_dbpwdLineEdit_editingFinished() {
    dbPwd = ui->dbpwdLineEdit->text().toStdString(); // Mot de passe de la BDD
}

void MainWindow::on_idLineEdit_editingFinished() {
    user = ui->idLineEdit->text().toStdString(); // Nom d'utilisateur
}

void MainWindow::on_pwdLineEdit_editingFinished() {
    pwd = ui->pwdLineEdit->text().toStdString(); // Mot de passe
}


void MainWindow::on_connectButton_clicked() {

          try {
               // On crée une variable de type Database
              db = new Database(ipAddress, dbName, dbPwd);
          }
          // Gestion des erreurs SQL
          catch(sql::SQLException &e) {
              std::cout << "\nERREUR DE CONNEXION A LA BDD :\n" << std::endl;
              std::cout << "# ERR: SQLException in " << __FILE__;
              std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
              std::cout << "# ERR: " << e.what();
              std::cout << " (MySQL error code: " << e.getErrorCode();
              std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
          }


          if(db->testAdmin(user, md5(pwd))) {               // Si l'utilisateur est un admin
              ui->dbpwdLineEdit->clear();                   // On efface les champs
              ui->idLineEdit->clear();
              ui->pwdLineEdit->clear();
              dbPwd="";
              user="";
              pwd="";
              manageWindow = new ManageWindow(db, this);    // On crée la fenetre de gestion (on lui passe la base de donnée et l'adresse de cette fenetre)
              manageWindow->show();                         // On l'affiche
              hide();                                       // Et on cache la fenetre de connexion
          } else {
               // Sinon on affiche un message d'erreur
              connectionError = new QMessageBox(QMessageBox::Critical, "Erreur", "Identifiant ou Mots de Passes incorrects",QMessageBox::Ok);
              connectionError->show();
          }
}

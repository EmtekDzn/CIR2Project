#include "../Headers/mainwindow.hpp"
#include "../ui/ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    readConfFile();
    ui->setupUi(this);
    ui->ipLineEdit->setText(QString::fromStdString(ipAddress));
    ui->dbnameLineEdit->setText(QString::fromStdString(dbName));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_connectButton_clicked() {

     if(dbPwd != "isen29") {
          connectionError = new QMessageBox(QMessageBox::Critical, "Erreur", "Identifiant ou Mots de Passes incorrects",QMessageBox::Ok);
          connectionError->show();
     } else {
          try {
              db = new Database(ipAddress, dbName, dbPwd);
          }
          catch(sql::SQLException &e) {
              std::cout << "\nERREUR DE CONNEXION A LA BDD :\n" << std::endl;
              std::cout << "# ERR: SQLException in " << __FILE__;
              std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
              std::cout << "# ERR: " << e.what();
              std::cout << " (MySQL error code: " << e.getErrorCode();
              std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
          }

          if(db->testAdmin(user, md5(pwd))) {
              ui->dbpwdLineEdit->clear();
              ui->idLineEdit->clear();
              ui->pwdLineEdit->clear();
              dbPwd="";
              user="";
              pwd="";
              manageWindow = new ManageWindow(db, this);
              manageWindow->show();
              hide();
          } else {
              connectionError = new QMessageBox(QMessageBox::Critical, "Erreur", "Identifiant ou Mots de Passes incorrects",QMessageBox::Ok);
              connectionError->show();
          }
     }
}

void MainWindow::on_ipLineEdit_editingFinished() {
    ipAddress = ui->ipLineEdit->text().toStdString();
}

void MainWindow::on_dbnameLineEdit_editingFinished() {
    dbName = ui->dbnameLineEdit->text().toStdString();
}

void MainWindow::on_dbpwdLineEdit_editingFinished() {
    dbPwd = ui->dbpwdLineEdit->text().toStdString();
}

void MainWindow::on_idLineEdit_editingFinished() {
    user = ui->idLineEdit->text().toStdString();
}

void MainWindow::on_pwdLineEdit_editingFinished() {
    pwd = ui->pwdLineEdit->text().toStdString();
}

void MainWindow::readConfFile() {

    ifstream file("Ressources/conf.txt", ios::in);

    if(!file.fail()) {
        getline(file, ipAddress);
        getline(file, dbName);

        ipAddress = ipAddress.substr(3);
        dbName = dbName.substr(7);

        file.close();
    }
    else cerr<<"File 'Ressources/conf.txt' doesn't exists"<<endl;
}

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

/*!
 * mainwindow.hpp
 * --------------
 *
 *
 * --> Une classe Qt pour gerer la fenetre de connexion
 *
 * --> Details des fonctions dans mainwindow.cpp
 *                                --------------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */

#include "managewindow.hpp"

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow {

    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0); ///< Constructeur
        ~MainWindow(); ///< Destructeur

        void readConfFile(); ///< Fonction de lecture du fichier de configuration


    private slots:
        /// Slots recuperant les entrees utilisateur
        void on_ipLineEdit_editingFinished();
        void on_dbnameLineEdit_editingFinished();
        void on_idLineEdit_editingFinished();
        void on_pwdLineEdit_editingFinished();
        void on_dbpwdLineEdit_editingFinished();

        /// Slot effectuant la connexion
        void on_connectButton_clicked();


    private:
        /// Attributs Qt
        Ui::MainWindow *ui;
        ManageWindow *manageWindow;
        QMessageBox *connectionError;

        string ipAddress;

        string dbUser;
        string user;

        string dbPwd;
        string pwd;

        string dbName;
        Database *db;
};

#endif // MAINWINDOW_HPP

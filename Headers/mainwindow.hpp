#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

/*!
 * \file mainwindow.hpp
 * \brief Fichier contenant la classe MainWindow
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "managewindow.hpp"

namespace Ui {class MainWindow;}

/*! \class MainWindow
 * \brief Une classe Qt pour gerer la fenetre de connexion
 *
 * La classe met en place la bdd et permet de se connecter pour afficher la fenetre de gestion
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

    public:

         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe MainWindow.
            *
            * \param QWidget *parent = 0 : Permet de faire passer un widget parent.
            * Par défaut ce parametre vaut 0
            */
        explicit MainWindow(QWidget *parent = 0);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe MainWindow
            */
        ~MainWindow();

        /*!
         * \brief Fonction de lecture du fichier de configuration
         *
         * Cette fonction lit le fichier de configuration et en extrait les données
         * pour remplir les champs d'entrée d'ip et du nom de la bdd
         */
        void readConfFile();

    public slots:
        /*!
         * \brief Slot recuperant les entrees utilisateur
         *
         * Ce slot stocke dans ipAddress l'ip entrée
         */
        void on_ipLineEdit_editingFinished();

        /*!
         * \brief Slot recuperant les entrees utilisateur
         *
         * Ce slot stocke dans dbName le nom de la bdd entré
         */
        void on_dbnameLineEdit_editingFinished();

        /*!
        * \brief Slot recuperant les entrees utilisateur
        *
        * Ce slot stocke dans dbPwd le mot de passe de la bdd entré
        */
        void on_dbpwdLineEdit_editingFinished();


        /*!
        * \brief Slot recuperant les entrees utilisateur
        *
        * Ce slot stocke dans user le nom d'utilisateur entré
        */
        void on_idLineEdit_editingFinished();

        /*!
         * \brief Slot recuperant les entrees utilisateur
         *
         * Ce slot stocke dans pwd le mot de passe entré
         */
        void on_pwdLineEdit_editingFinished();

        /*!
         * \brief Slot effectuant la connexion
         *
         * Slot du boutton de connexion. Il permet de gerer les erreurs sur les entrées,
         * creer une classe Database et la fenetre de gestion de la BDD.
         */
        void on_connectButton_clicked();


    private:
         // Attributs Qt
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

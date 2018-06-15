#ifndef MANAGEWINDOW_HPP
#define MANAGEWINDOW_HPP

/*!
 * \file managewindow.hpp
 * \brief Fichier contenant la classe ManageWindow
 * \author Pierre-Alban Lagadec
 * \version 0.1
 */

#include "database.hpp"

namespace Ui {class ManageWindow;}

/*! \class ManageWindow
 * \brief Une classe Qt pour gerer la fenetre de gestion de la BDD
 *
 * La classe met en place la bdd et permet de se connecter pour afficher la fenetre de gestion
 */
class ManageWindow : public QMainWindow {
    Q_OBJECT

    public:
         /*!
            *  \brief Constructeur
            *
            *  Constructeur de la classe ManageWindow.
            *
            * \param Database *dtb : Pointeur sur la base de donnée crée dans mainwindow.cpp
            * \param QWidget *parent = 0 : Pointeur sur la fenetre de connexion.
            * Par défaut ce parametre vaut 0
            */
        explicit ManageWindow(Database *dtb, QWidget *parent = 0);

        /*!
            *  \brief Destructeur
            *
            *  Destructeur de la classe ManageWindow
            */
        ~ManageWindow();

        /*!
         * \brief Verification de syntaxe
         *
         * Cette fonction permet de verifier si une question a bien 2 virgules
         * \param std::string question : La chaine a verifier
         * \return int 1 : La chaine contient 2 virgules
         * \return int 0 : La chaine ne contient pas 2 virgules
         */
        bool checkSyntax(string question);

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur de themes et de questions
         */
        void fillPickers();

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur de theme dans l'ajout de questions
         */
        void fillThemePicker2();

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur de bonne reponse dans l'ajout de question
         * \param std::string question : La question a decouper pour remplir le selecteur
         */
        void fillAnswerPicker(string question);

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur de bonne reponse dans l'edition de question
         * \param std::string question : La question a decouper pour remplir le selecteur
         */
        void fillAnswerPicker23(string question);

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur de propositions dans l'édition de questions
         * \param std::string question : La question selectionnée
         */
        void fillPropPicker(string question);

        /*!
         * \brief Fonction de remplissage de QComboBox
         *
         * Cette fonction permet de remplir le selecteur d'utilisateur
         */
        void fillUserPicker();

    public slots:
         /*!
          * \brief Slot du bouton de deconnexion
          *
          * Ce slot permet de se deconnecter
          */
        void on_logoutButton_clicked();

        /*!
         * \brief Slots de QComboBox
         *
         * Ce slot permet de recuperer le texte de l'index selectionné
         * \param const QString &statement : L'adresse du texte
         */
        void on_themePicker_activated(const QString &statement);

        /*!
         * \brief Slots de QComboBox
         *
         * Ce slot permet de recuperer le theme choisi dans le selecteur de
         * theme dans l'ajout de questions
         * \param const QString &statement : L'adresse du texte
         */
        void on_themePicker2_activated(const QString &statement);

        /*!
         * \brief Slots de QComboBox
         *
         * Ce slot permet de recuperer la question choisie par l'utilisateur
         * et d'afficher ou de cacher certains widgets
         * \param const QString &statement : L'adresse du texte
         */
        void on_questionPicker_activated(const QString &statement);

        /*!
         * \brief Slots de QComboBox
         *
         * Ce slot permet de recuperer la proposition selectionnée par l'utilisateur
         * \param const QString &statement : L'adresse du texte
         */
        void on_propPicker_activated(const QString &statement);

        /*!
         * \brief Slots de QComboBox
         *
         * Ce slot permet de recuperer le nom de l'utilisateur selectionné
         * \param const QString &statement : L'adresse du texte
         */
        void on_userPicker_activated(const QString &statement);

        /// Slots des QLineEdit d'ajout

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le nom du theme a ajouter
         */
        void on_newThemeLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le nom de la question a ajouter
         */
        void on_addQuestionLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le nom de la proposition a ajouter
         */
        void on_addPropLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le nom de la proposition a ajouter
         */
        void on_addPropLineEdit2_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le nom de l'utilisateur a ajouter
         */
        void on_newUsernameLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'ajout
         *
         * Ce slot permet d'entrer le mot de passe de l'utilisateur a ajouter
         */
        void on_newPwdLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'edition
         *
         * Ce slot permet d'entrer le nouveau nom du theme a editer
         */
        void on_themeLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'edition
         *
         * Ce slot permet d'entrer le nouveau nom de la question a editer
         */
        void on_editQuestionLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'edition
         *
         * Ce slot permet d'entrer le nouveau nom de la proposition a editer
         */
        void on_editPropLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'edition
         *
         * Ce slot permet d'entrer le nouveau nom de l'utilisateur a editer
         */
        void on_usernameLineEdit_editingFinished();

        /*!
         * \brief Slot de QLineEdit d'edition
         *
         * Ce slot permet d'entrer le nouveau mot de passe de l'utilisateur a editer
         */
        void on_pwdLineEdit_editingFinished();

        /*!
         * \brief Slot de QCheckBox
         *
         * Ce slot permet de recuperer l'etat de la QCheckBox
         * \param int state : L'état de la QCheckBox (0,1 ou 2)
         */
        void on_testAdminCheckbox_stateChanged(int state);

        /*!
         * \brief Slot de QCheckBox
         *
         * Ce slot permet de recuperer l'etat de la QCheckBox
         * \param int state : L'état de la QCheckBox (0,1 ou 2)
         */
        void on_makeAdminCheckBox_stateChanged(int state);

        /*!
         * \brief Slot des bouton d'ajout
         *
         * Ce slot permet d'ajouter un theme lorsqu'il est cliqué après
         * des vérifications
         */
        void on_addThemeButton_clicked();

        /*!
         * \brief Slot des bouton d'ajout
         *
         * Ce slot permet d'ajouter une question lorsqu'il est cliqué après
         * des vérifications
         */
        void on_addQuestionButton_clicked();

        /*!
         * \brief Slot des bouton d'ajout
         *
         * Ce slot permet d'ajouter une proposition lorsqu'il est cliqué après
         * des vérifications
         */
        void on_addPropButton_clicked();

        /*!
         * \brief Slot des bouton d'ajout
         *
         * Ce slot permet d'ajouter une proposition lorsqu'il est cliqué après
         * des vérifications
         */
        void on_addPropButton2_clicked();

        /*!
         * \brief Slot des bouton d'ajout
         *
         * Ce slot permet d'ajouter un utilisateur lorsqu'il est cliqué après
         * des vérifications
         */
        void on_addUserButton_clicked();

        /*!
         * \brief Slot des bouton d'edition
         *
         * Ce slot permet d'editer un theme lorsqu'il est cliqué après
         * des vérifications
         */
        void on_themeEditButton_clicked();

        /*!
         * \brief Slot des bouton d'edition
         *
         * Ce slot permet d'editer une question lorsqu'il est cliqué après
         * des vérifications
         */
        void on_editQuestionButton_clicked();

        /*!
         * \brief Slot des bouton d'edition
         *
         * Ce slot permet d'editer une proposition lorsqu'il est cliqué après
         * des vérifications
         */
        void on_editPropButton_clicked();

        /*!
         * \brief Slot des bouton d'edition
         *
         * Ce slot permet d'editer un utilisateur lorsqu'il est cliqué après
         * des vérifications
         */
        void on_editUserPushButton_clicked();

        /*!
         * \brief Slot des bouton de suppression
         *
         * Ce slot permet de supprimer un theme lorsqu'il est cliqué après
         * des vérifications
         */
        void on_deleteThemeButton_clicked();

        /*!
         * \brief Slot des bouton de suppression
         *
         * Ce slot permet de supprimer une question lorsqu'il est cliqué après
         * des vérifications
         */
        void on_deleteQuestionButton_clicked();

        /*!
         * \brief Slot des bouton de suppression
         *
         * Ce slot permet de supprimer une proposition lorsqu'il est cliqué après
         * des vérifications
         */
        void on_deletePropButton_clicked();

        /*!
         * \brief Slot des bouton de suppression
         *
         * Ce slot permet de supprimer un utilisateur lorsqu'il est cliqué après
         * des vérifications
         */
        void on_deleteUserButton_clicked();

    private:
         // Attributs Qt
        Ui::ManageWindow *ui;
        QWidget *lastWindow;

        Database *db; //Pointeur sur la bdd

        // Attributs selectionnes par l'utilisateur dans les QComboBox
        string selectedTheme;
        string selectedQuestion;
        string selectedUser;
        string selectedProposition;

        // Attributs stockant les entrees utilisateur
        string newThemeName;
        string newQuestion;
        string proposition;
        string newUsername;
        string newPwd;

        string pwd; // Attribut stockant le mot de passe de l'utilisateur selectionné

        int checkAdmin; // Etat de la QCheckBox::admin (0,1 ou 2)

        // Vecteurs
        vector <Theme> themes;
        vector <Question> questions;
        vector <Proposition> propositions;
        vector <User> users;
};

#endif // MANAGEWINDOW_HPP

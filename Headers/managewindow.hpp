#ifndef MANAGEWINDOW_HPP
#define MANAGEWINDOW_HPP

/*!
 * managewindow.hpp
 * ----------------
 *
 *
 * --> Une classe Qt pour gerer la fenetre de gestion de la BDD
 *
 * --> Details des fonctions dans managewindow.cpp
 *                                ----------------
 *
 *
 * Créé par Pierre-Alban Lagadec , 12 Juin 2018
 */


#include "database.hpp"

using namespace std;
namespace Ui {class ManageWindow;}

class ManageWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit ManageWindow(Database *dtb, QWidget *parent = 0); ///< Constructeur
        ~ManageWindow(); ///< Destructeur

        int checkSyntax(string question); ///< Fonction de verification de la syntaxe d'une question

        /// Fonctions de remplissage des QComboBox
        void fillPickers();
        void fillThemePicker2();
        void fillAnswerPicker(string question);
        void fillAnswerPicker23(string question);
        void fillPropPicker(string question);
        void fillUserPicker();

    private slots:
        void on_logoutButton_clicked(); ///< Slot du bouton de deconnexion

        /// Slots des QComboBox
        void on_questionPicker_activated(const QString &arg1);
        void on_propPicker_activated(const QString &arg1);
        void on_themePicker_activated(const QString &arg1);
        void on_themePicker2_activated(const QString &arg1);
        void on_userPicker_activated(const QString &arg1);

        /// Slots des QLineEdit d'ajout
        void on_newThemeLineEdit_editingFinished();
        void on_addQuestionLineEdit_editingFinished();
        void on_addPropLineEdit_editingFinished();
        void on_addPropLineEdit2_editingFinished();
        void on_newUsernameLineEdit_editingFinished();
        void on_newPwdLineEdit_editingFinished();


        /// Slots des QLineEdit d'edition
        void on_themeLineEdit_editingFinished();
        void on_editQuestionLineEdit_editingFinished();
        void on_editPropLineEdit_editingFinished();
        void on_usernameLineEdit_editingFinished();
        void on_pwdLineEdit_editingFinished();

        /// Slots des QCheckBox
        void on_testAdminCheckbox_stateChanged(int arg1);
        void on_makeAdminCheckBox_stateChanged(int state);

        /// Slots des boutons d'ajout
        void on_addThemeButton_clicked();
        void on_addUserButton_clicked();
        void on_addQuestionButton_clicked();
        void on_addPropButton_clicked();
        void on_addPropButton2_clicked();

        /// Slots des boutons d'edition
        void on_themeEditButton_clicked();
        void on_editQuestionButton_clicked();
        void on_editPropButton_clicked();
        void on_editUserPushButton_clicked();

        /// Slots des boutons de suppression
        void on_deleteUserButton_clicked();
        void on_deletePropButton_clicked();
        void on_deleteQuestionButton_clicked();
        void on_deleteThemeButton_clicked();

    private:
        ///Attributs Qt
        Ui::ManageWindow *ui;
        QWidget *lastWindow;

        Database *db; ///< Pointeur sur la BDD

        /// Les attributs selectionnes par l'utilisateur dans les QComboBox
        string selectedTheme;
        string selectedQuestion;
        string selectedUser;
        string selectedProposition;

        /// Les attributs stockant les entrees utilisateur
        string newThemeName;
        string newQuestion;
        string proposition;
        string newUsername;
        string newPwd;

        string pwd; ///< Attribut stockant le mot de passe de l'utilisateur selectionné

        int checkAdmin; ///< Etat de la QCheckBox::admin (0,1 ou 2)

        /// Vecteurs
        vector <Theme> themes;
        vector <Question> questions;
        vector <Proposition> propositions;
        vector <User> users;
};

#endif // MANAGEWINDOW_HPP

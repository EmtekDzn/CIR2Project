/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *ipLineEdit;
    QLineEdit *dbnameLineEdit;
    QLineEdit *dbpwdLineEdit;
    QLineEdit *idLineEdit;
    QLineEdit *pwdLineEdit;
    QPushButton *connectButton;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(315, 495);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter->setCheckable(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(150, 150));
        label->setPixmap(QPixmap(QString::fromUtf8("../ressources/burger.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ipLineEdit = new QLineEdit(centralWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        ipLineEdit->setMinimumSize(QSize(0, 40));
        ipLineEdit->setFocusPolicy(Qt::StrongFocus);
        ipLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(ipLineEdit);

        dbnameLineEdit = new QLineEdit(centralWidget);
        dbnameLineEdit->setObjectName(QStringLiteral("dbnameLineEdit"));
        dbnameLineEdit->setMinimumSize(QSize(0, 40));
        dbnameLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(dbnameLineEdit);

        dbpwdLineEdit = new QLineEdit(centralWidget);
        dbpwdLineEdit->setObjectName(QStringLiteral("dbpwdLineEdit"));
        dbpwdLineEdit->setMinimumSize(QSize(0, 40));
        dbpwdLineEdit->setEchoMode(QLineEdit::Password);
        dbpwdLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(dbpwdLineEdit);

        idLineEdit = new QLineEdit(centralWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setMinimumSize(QSize(0, 40));
        idLineEdit->setFocusPolicy(Qt::StrongFocus);
        idLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(idLineEdit);

        pwdLineEdit = new QLineEdit(centralWidget);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setMinimumSize(QSize(0, 40));
        pwdLineEdit->setFocusPolicy(Qt::StrongFocus);
        pwdLineEdit->setEchoMode(QLineEdit::Password);
        pwdLineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(pwdLineEdit);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMinimumSize(QSize(0, 40));
        connectButton->setFocusPolicy(Qt::ClickFocus);

        verticalLayout_2->addWidget(connectButton);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 315, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Administration BDD", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        label->setText(QString());
        ipLineEdit->setText(QApplication::translate("MainWindow", "172.31.3.61", 0));
        ipLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Adresse IP", 0));
        dbnameLineEdit->setText(QApplication::translate("MainWindow", "projetcir2", 0));
        dbnameLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Nom de la Base", 0));
        dbpwdLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Mot de Passe de la BDD", 0));
        idLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Identifiant", 0));
        pwdLineEdit->setPlaceholderText(QApplication::translate("MainWindow", "Mot de Passe", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Se connecter", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

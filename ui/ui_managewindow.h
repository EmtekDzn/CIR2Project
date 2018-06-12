/********************************************************************************
** Form generated from reading UI file 'managewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEWINDOW_H
#define UI_MANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageWindow
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *themeIndex;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *editLabel;
    QGridLayout *gridLayout_2;
    QPushButton *themeEditButton;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *themePicker;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *themeLineEdit;
    QPushButton *deleteThemeButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_7;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *addLabel;
    QGridLayout *gridLayout_3;
    QPushButton *addThemeButton;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *newThemeLineEdit;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_8;
    QWidget *questionIndex;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_3;
    QComboBox *goodAnswerPicker_2;
    QPushButton *editQuestionButton;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *editQuestionLineEdit;
    QPushButton *deleteQuestionButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *deletePropButton;
    QComboBox *propPicker;
    QComboBox *questionPicker;
    QLineEdit *editPropLineEdit;
    QPushButton *editPropButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *goodAnswerPicker3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_12;
    QLineEdit *addPropLineEdit2;
    QPushButton *addPropButton2;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_17;
    QSpacerItem *verticalSpacer_18;
    QLabel *editPropLabel;
    QLabel *addPropLabel;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *addQuestionButton;
    QComboBox *themePicker2;
    QLineEdit *addQuestionLineEdit;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *addPropButton;
    QLineEdit *addPropLineEdit;
    QComboBox *goodAnswerPicker;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_15;
    QLabel *addPropLabel2;
    QSpacerItem *verticalSpacer_19;
    QSpacerItem *verticalSpacer_10;
    QWidget *userIndex;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *pwdLineEdit;
    QLineEdit *usernameLineEdit;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *deleteUserButton;
    QComboBox *userPicker;
    QPushButton *editUserPushButton;
    QCheckBox *makeAdminCheckBox;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QGridLayout *gridLayout_8;
    QPushButton *addUserButton;
    QLineEdit *newPwdLineEdit;
    QCheckBox *testAdminCheckbox;
    QLineEdit *newUsernameLineEdit;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *logoutSpacer;
    QPushButton *logoutButton;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageWindow)
    {
        if (ManageWindow->objectName().isEmpty())
            ManageWindow->setObjectName(QStringLiteral("ManageWindow"));
        ManageWindow->resize(798, 574);
        actionQuitter = new QAction(ManageWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(ManageWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        themeIndex = new QWidget();
        themeIndex->setObjectName(QStringLiteral("themeIndex"));
        horizontalLayout_2 = new QHBoxLayout(themeIndex);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editLabel = new QLabel(themeIndex);
        editLabel->setObjectName(QStringLiteral("editLabel"));
        QFont font;
        font.setPointSize(20);
        editLabel->setFont(font);

        verticalLayout->addWidget(editLabel);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        themeEditButton = new QPushButton(themeIndex);
        themeEditButton->setObjectName(QStringLiteral("themeEditButton"));

        gridLayout_2->addWidget(themeEditButton, 4, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 5, 2, 1, 1);

        themePicker = new QComboBox(themeIndex);
        themePicker->setObjectName(QStringLiteral("themePicker"));
        themePicker->setMaxVisibleItems(50);

        gridLayout_2->addWidget(themePicker, 1, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 5, 0, 1, 1);

        themeLineEdit = new QLineEdit(themeIndex);
        themeLineEdit->setObjectName(QStringLiteral("themeLineEdit"));

        gridLayout_2->addWidget(themeLineEdit, 2, 0, 1, 3);

        deleteThemeButton = new QPushButton(themeIndex);
        deleteThemeButton->setObjectName(QStringLiteral("deleteThemeButton"));

        gridLayout_2->addWidget(deleteThemeButton, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);


        horizontalLayout_2->addLayout(verticalLayout);

        line = new QFrame(themeIndex);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addLabel = new QLabel(themeIndex);
        addLabel->setObjectName(QStringLiteral("addLabel"));
        addLabel->setFont(font);

        verticalLayout_2->addWidget(addLabel);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addThemeButton = new QPushButton(themeIndex);
        addThemeButton->setObjectName(QStringLiteral("addThemeButton"));

        gridLayout_3->addWidget(addThemeButton, 3, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 5, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_8, 4, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 4, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 4, 2, 1, 1);

        newThemeLineEdit = new QLineEdit(themeIndex);
        newThemeLineEdit->setObjectName(QStringLiteral("newThemeLineEdit"));

        gridLayout_3->addWidget(newThemeLineEdit, 2, 0, 1, 4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 6, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tabWidget->addTab(themeIndex, QString());
        questionIndex = new QWidget();
        questionIndex->setObjectName(QStringLiteral("questionIndex"));
        horizontalLayout_3 = new QHBoxLayout(questionIndex);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(questionIndex);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 18, 2, 1, 1);

        goodAnswerPicker_2 = new QComboBox(questionIndex);
        goodAnswerPicker_2->setObjectName(QStringLiteral("goodAnswerPicker_2"));

        gridLayout_4->addWidget(goodAnswerPicker_2, 8, 0, 1, 2);

        editQuestionButton = new QPushButton(questionIndex);
        editQuestionButton->setObjectName(QStringLiteral("editQuestionButton"));

        gridLayout_4->addWidget(editQuestionButton, 2, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_5, 17, 2, 1, 1);

        editQuestionLineEdit = new QLineEdit(questionIndex);
        editQuestionLineEdit->setObjectName(QStringLiteral("editQuestionLineEdit"));

        gridLayout_4->addWidget(editQuestionLineEdit, 1, 0, 1, 3);

        deleteQuestionButton = new QPushButton(questionIndex);
        deleteQuestionButton->setObjectName(QStringLiteral("deleteQuestionButton"));

        gridLayout_4->addWidget(deleteQuestionButton, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 15, 1, 1, 1);

        deletePropButton = new QPushButton(questionIndex);
        deletePropButton->setObjectName(QStringLiteral("deletePropButton"));

        gridLayout_4->addWidget(deletePropButton, 6, 2, 1, 1);

        propPicker = new QComboBox(questionIndex);
        propPicker->setObjectName(QStringLiteral("propPicker"));

        gridLayout_4->addWidget(propPicker, 6, 0, 1, 2);

        questionPicker = new QComboBox(questionIndex);
        questionPicker->setObjectName(QStringLiteral("questionPicker"));
        questionPicker->setEnabled(true);

        gridLayout_4->addWidget(questionPicker, 0, 0, 1, 2);

        editPropLineEdit = new QLineEdit(questionIndex);
        editPropLineEdit->setObjectName(QStringLiteral("editPropLineEdit"));

        gridLayout_4->addWidget(editPropLineEdit, 7, 0, 1, 2);

        editPropButton = new QPushButton(questionIndex);
        editPropButton->setObjectName(QStringLiteral("editPropButton"));

        gridLayout_4->addWidget(editPropButton, 8, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 15, 2, 1, 1);

        goodAnswerPicker3 = new QComboBox(questionIndex);
        goodAnswerPicker3->setObjectName(QStringLiteral("goodAnswerPicker3"));

        gridLayout_4->addWidget(goodAnswerPicker3, 14, 0, 1, 2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 15, 0, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_12, 3, 2, 1, 1);

        addPropLineEdit2 = new QLineEdit(questionIndex);
        addPropLineEdit2->setObjectName(QStringLiteral("addPropLineEdit2"));

        gridLayout_4->addWidget(addPropLineEdit2, 13, 0, 1, 3);

        addPropButton2 = new QPushButton(questionIndex);
        addPropButton2->setObjectName(QStringLiteral("addPropButton2"));

        gridLayout_4->addWidget(addPropButton2, 14, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_9, 9, 2, 1, 1);

        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_17, 5, 0, 1, 1);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_18, 11, 0, 1, 1);

        editPropLabel = new QLabel(questionIndex);
        editPropLabel->setObjectName(QStringLiteral("editPropLabel"));
        QFont font1;
        font1.setPointSize(13);
        editPropLabel->setFont(font1);

        gridLayout_4->addWidget(editPropLabel, 4, 1, 1, 1);

        addPropLabel = new QLabel(questionIndex);
        addPropLabel->setObjectName(QStringLiteral("addPropLabel"));
        addPropLabel->setFont(font1);

        gridLayout_4->addWidget(addPropLabel, 10, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        line_2 = new QFrame(questionIndex);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(questionIndex);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_4->addWidget(label_2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_16, 15, 2, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 13, 1, 1, 1);

        addQuestionButton = new QPushButton(questionIndex);
        addQuestionButton->setObjectName(QStringLiteral("addQuestionButton"));

        gridLayout_5->addWidget(addQuestionButton, 2, 2, 1, 1);

        themePicker2 = new QComboBox(questionIndex);
        themePicker2->setObjectName(QStringLiteral("themePicker2"));

        gridLayout_5->addWidget(themePicker2, 0, 0, 1, 4);

        addQuestionLineEdit = new QLineEdit(questionIndex);
        addQuestionLineEdit->setObjectName(QStringLiteral("addQuestionLineEdit"));

        gridLayout_5->addWidget(addQuestionLineEdit, 1, 0, 1, 4);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_11, 13, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 13, 0, 1, 1);

        addPropButton = new QPushButton(questionIndex);
        addPropButton->setObjectName(QStringLiteral("addPropButton"));

        gridLayout_5->addWidget(addPropButton, 9, 2, 1, 1);

        addPropLineEdit = new QLineEdit(questionIndex);
        addPropLineEdit->setObjectName(QStringLiteral("addPropLineEdit"));

        gridLayout_5->addWidget(addPropLineEdit, 7, 0, 1, 3);

        goodAnswerPicker = new QComboBox(questionIndex);
        goodAnswerPicker->setObjectName(QStringLiteral("goodAnswerPicker"));

        gridLayout_5->addWidget(goodAnswerPicker, 9, 0, 1, 2);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_13, 3, 2, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_14, 10, 2, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_15, 14, 2, 1, 1);

        addPropLabel2 = new QLabel(questionIndex);
        addPropLabel2->setObjectName(QStringLiteral("addPropLabel2"));
        addPropLabel2->setFont(font1);

        gridLayout_5->addWidget(addPropLabel2, 4, 1, 1, 1);

        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_19, 6, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_5);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_10);


        horizontalLayout_3->addLayout(verticalLayout_4);

        tabWidget->addTab(questionIndex, QString());
        userIndex = new QWidget();
        userIndex->setObjectName(QStringLiteral("userIndex"));
        horizontalLayout_4 = new QHBoxLayout(userIndex);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(userIndex);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setPointSize(20);
        font2.setItalic(false);
        label_3->setFont(font2);

        verticalLayout_5->addWidget(label_3);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_13, 4, 0, 1, 1);

        pwdLineEdit = new QLineEdit(userIndex);
        pwdLineEdit->setObjectName(QStringLiteral("pwdLineEdit"));
        pwdLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_7->addWidget(pwdLineEdit, 2, 0, 1, 3);

        usernameLineEdit = new QLineEdit(userIndex);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));

        gridLayout_7->addWidget(usernameLineEdit, 1, 0, 1, 3);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_14, 4, 1, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_15, 4, 2, 1, 1);

        deleteUserButton = new QPushButton(userIndex);
        deleteUserButton->setObjectName(QStringLiteral("deleteUserButton"));

        gridLayout_7->addWidget(deleteUserButton, 0, 2, 1, 1);

        userPicker = new QComboBox(userIndex);
        userPicker->setObjectName(QStringLiteral("userPicker"));

        gridLayout_7->addWidget(userPicker, 0, 0, 1, 2);

        editUserPushButton = new QPushButton(userIndex);
        editUserPushButton->setObjectName(QStringLiteral("editUserPushButton"));

        gridLayout_7->addWidget(editUserPushButton, 3, 2, 1, 1);

        makeAdminCheckBox = new QCheckBox(userIndex);
        makeAdminCheckBox->setObjectName(QStringLiteral("makeAdminCheckBox"));

        gridLayout_7->addWidget(makeAdminCheckBox, 3, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_5);

        line_3 = new QFrame(userIndex);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(userIndex);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        verticalLayout_6->addWidget(label_4);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        addUserButton = new QPushButton(userIndex);
        addUserButton->setObjectName(QStringLiteral("addUserButton"));

        gridLayout_8->addWidget(addUserButton, 2, 2, 1, 1);

        newPwdLineEdit = new QLineEdit(userIndex);
        newPwdLineEdit->setObjectName(QStringLiteral("newPwdLineEdit"));

        gridLayout_8->addWidget(newPwdLineEdit, 1, 0, 1, 3);

        testAdminCheckbox = new QCheckBox(userIndex);
        testAdminCheckbox->setObjectName(QStringLiteral("testAdminCheckbox"));

        gridLayout_8->addWidget(testAdminCheckbox, 2, 0, 1, 1);

        newUsernameLineEdit = new QLineEdit(userIndex);
        newUsernameLineEdit->setObjectName(QStringLiteral("newUsernameLineEdit"));

        gridLayout_8->addWidget(newUsernameLineEdit, 0, 0, 1, 3);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_17, 3, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_16, 3, 0, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_18, 3, 2, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_11, 4, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_8);


        horizontalLayout_4->addLayout(verticalLayout_6);

        tabWidget->addTab(userIndex, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logoutSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(logoutSpacer);

        logoutButton = new QPushButton(centralWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));

        horizontalLayout->addWidget(logoutButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 2, 1);

        ManageWindow->setCentralWidget(centralWidget);
        menubar = new QMenuBar(ManageWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        ManageWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ManageWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ManageWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionQuitter);

        retranslateUi(ManageWindow);

        tabWidget->setCurrentIndex(2);
        questionPicker->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ManageWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManageWindow)
    {
        ManageWindow->setWindowTitle(QApplication::translate("ManageWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("ManageWindow", "Quitter", 0));
        editLabel->setText(QApplication::translate("ManageWindow", "Editer un theme", 0));
        themeEditButton->setText(QApplication::translate("ManageWindow", "Modifier", 0));
        themeLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Nouveau nom", 0));
        deleteThemeButton->setText(QApplication::translate("ManageWindow", "Supprimer", 0));
        addLabel->setText(QApplication::translate("ManageWindow", "Ajouter un theme", 0));
        addThemeButton->setText(QApplication::translate("ManageWindow", "Ajouter", 0));
        newThemeLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Nom du theme", 0));
        tabWidget->setTabText(tabWidget->indexOf(themeIndex), QApplication::translate("ManageWindow", "Themes", 0));
        label->setText(QApplication::translate("ManageWindow", "Editer une question", 0));
        editQuestionButton->setText(QApplication::translate("ManageWindow", "Modifier", 0));
        editQuestionLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Reponse1, reponse2, les deux ?", 0));
        deleteQuestionButton->setText(QApplication::translate("ManageWindow", "Supprimer", 0));
        deletePropButton->setText(QApplication::translate("ManageWindow", "Supprimer", 0));
        questionPicker->setCurrentText(QString());
        editPropLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Proposition", 0));
        editPropButton->setText(QApplication::translate("ManageWindow", "Modifier", 0));
        addPropLineEdit2->setPlaceholderText(QApplication::translate("ManageWindow", "Proposition", 0));
        addPropButton2->setText(QApplication::translate("ManageWindow", "Ajouter", 0));
        editPropLabel->setText(QApplication::translate("ManageWindow", "Edition de propositions", 0));
        addPropLabel->setText(QApplication::translate("ManageWindow", "Ajout de propositions", 0));
        label_2->setText(QApplication::translate("ManageWindow", "Ajouter une question", 0));
        addQuestionButton->setText(QApplication::translate("ManageWindow", "Ajouter", 0));
        addQuestionLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Reponse1,Reponse2,les deux ?", 0));
        addPropButton->setText(QApplication::translate("ManageWindow", "Ajouter", 0));
        addPropLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Proposition", 0));
        addPropLabel2->setText(QApplication::translate("ManageWindow", "Ajout de propositions", 0));
        tabWidget->setTabText(tabWidget->indexOf(questionIndex), QApplication::translate("ManageWindow", "Questions", 0));
        label_3->setText(QApplication::translate("ManageWindow", "Editer un profil", 0));
        pwdLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Nouveau Mot de Passe", 0));
        usernameLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Nom d'utilisateur", 0));
        deleteUserButton->setText(QApplication::translate("ManageWindow", "Supprimer", 0));
        editUserPushButton->setText(QApplication::translate("ManageWindow", "Modifier", 0));
        makeAdminCheckBox->setText(QApplication::translate("ManageWindow", "Admin", 0));
        label_4->setText(QApplication::translate("ManageWindow", "Ajouter un utilisateur", 0));
        addUserButton->setText(QApplication::translate("ManageWindow", "Ajouter", 0));
        newPwdLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Mot de Passe", 0));
        testAdminCheckbox->setText(QApplication::translate("ManageWindow", "Admin", 0));
        newUsernameLineEdit->setPlaceholderText(QApplication::translate("ManageWindow", "Nom d'utilisateur", 0));
        tabWidget->setTabText(tabWidget->indexOf(userIndex), QApplication::translate("ManageWindow", "Utilisateurs", 0));
        logoutButton->setText(QApplication::translate("ManageWindow", "Se deconnecter", 0));
        menuFichier->setTitle(QApplication::translate("ManageWindow", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class ManageWindow: public Ui_ManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEWINDOW_H

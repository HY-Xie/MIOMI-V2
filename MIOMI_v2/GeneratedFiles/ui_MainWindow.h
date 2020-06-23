/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QWidget *back_widget;
    QGridLayout *gridLayout_2;
    QWidget *login_info_widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *database_connect_status;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *id_lineEdit;
    QLineEdit *pw_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *login_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exit_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1123, 704);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/mainwindow.png")));
        MainWindowClass->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        back_widget = new QWidget(centralWidget);
        back_widget->setObjectName(QStringLiteral("back_widget"));
        gridLayout_2 = new QGridLayout(back_widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        login_info_widget = new QWidget(back_widget);
        login_info_widget->setObjectName(QStringLiteral("login_info_widget"));
        login_info_widget->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(login_info_widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(login_info_widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        database_connect_status = new QLabel(login_info_widget);
        database_connect_status->setObjectName(QStringLiteral("database_connect_status"));
        database_connect_status->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_3->addWidget(database_connect_status);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(login_info_widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(12);
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(login_info_widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        id_lineEdit = new QLineEdit(login_info_widget);
        id_lineEdit->setObjectName(QStringLiteral("id_lineEdit"));
        id_lineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 128);"));

        verticalLayout->addWidget(id_lineEdit);

        pw_lineEdit = new QLineEdit(login_info_widget);
        pw_lineEdit->setObjectName(QStringLiteral("pw_lineEdit"));
        pw_lineEdit->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 128);"));
        pw_lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pw_lineEdit);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        login_pushButton = new QPushButton(login_info_widget);
        login_pushButton->setObjectName(QStringLiteral("login_pushButton"));
        login_pushButton->setFont(font1);
        login_pushButton->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 128);\n"
""));

        horizontalLayout_2->addWidget(login_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        exit_pushButton = new QPushButton(login_info_widget);
        exit_pushButton->setObjectName(QStringLiteral("exit_pushButton"));
        exit_pushButton->setFont(font1);
        exit_pushButton->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 128);"));

        horizontalLayout_2->addWidget(exit_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        gridLayout_2->addWidget(login_info_widget, 1, 1, 2, 2);

        horizontalSpacer_4 = new QSpacerItem(94, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 136, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 1, 3, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 136, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 3, 2, 1, 1);


        gridLayout_3->addWidget(back_widget, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 26));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setFloatable(false);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MIOMI \347\256\241\347\220\206\345\271\263\345\217\260 - Beta 0.2", nullptr));
        label->setText(QApplication::translate("MainWindowClass", "\345\221\230\345\267\245\347\231\273\345\275\225", nullptr));
        database_connect_status->setText(QApplication::translate("MainWindowClass", "a", nullptr));
        label_2->setText(QApplication::translate("MainWindowClass", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QApplication::translate("MainWindowClass", "\345\257\206\347\240\201:", nullptr));
        id_lineEdit->setPlaceholderText(QApplication::translate("MainWindowClass", "\345\267\245\345\217\267\346\210\226\346\211\213\346\234\272\345\217\267", nullptr));
        pw_lineEdit->setPlaceholderText(QApplication::translate("MainWindowClass", "\345\257\206\347\240\201", nullptr));
        login_pushButton->setText(QApplication::translate("MainWindowClass", "\347\231\273\345\275\225", nullptr));
        exit_pushButton->setText(QApplication::translate("MainWindowClass", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

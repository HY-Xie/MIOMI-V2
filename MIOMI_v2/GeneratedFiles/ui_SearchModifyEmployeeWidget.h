/********************************************************************************
** Form generated from reading UI file 'SearchModifyEmployeeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHMODIFYEMPLOYEEWIDGET_H
#define UI_SEARCHMODIFYEMPLOYEEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchModifyEmployeeWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *name_lineEdit;
    QLabel *label_25;
    QLineEdit *tel_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_24;
    QLineEdit *id_lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *search_pushButton;
    QPushButton *save_pushButton;
    QLabel *label_2;
    QTableView *tableView;

    void setupUi(QDialog *SearchModifyEmployeeWidget)
    {
        if (SearchModifyEmployeeWidget->objectName().isEmpty())
            SearchModifyEmployeeWidget->setObjectName(QStringLiteral("SearchModifyEmployeeWidget"));
        SearchModifyEmployeeWidget->resize(1073, 692);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/addCustomer.png")));
        SearchModifyEmployeeWidget->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(SearchModifyEmployeeWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(SearchModifyEmployeeWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        name_lineEdit = new QLineEdit(SearchModifyEmployeeWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout_2->addWidget(name_lineEdit);


        horizontalLayout->addLayout(horizontalLayout_2);

        label_25 = new QLabel(SearchModifyEmployeeWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        horizontalLayout->addWidget(label_25);

        tel_lineEdit = new QLineEdit(SearchModifyEmployeeWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        horizontalLayout->addWidget(tel_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_24 = new QLabel(SearchModifyEmployeeWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        horizontalLayout_3->addWidget(label_24);

        id_lineEdit = new QLineEdit(SearchModifyEmployeeWidget);
        id_lineEdit->setObjectName(QStringLiteral("id_lineEdit"));

        horizontalLayout_3->addWidget(id_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        search_pushButton = new QPushButton(SearchModifyEmployeeWidget);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));
        search_pushButton->setFont(font);

        horizontalLayout_4->addWidget(search_pushButton);

        save_pushButton = new QPushButton(SearchModifyEmployeeWidget);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));
        save_pushButton->setFont(font);

        horizontalLayout_4->addWidget(save_pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(SearchModifyEmployeeWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 128);"));

        verticalLayout->addWidget(label_2);

        tableView = new QTableView(SearchModifyEmployeeWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SearchModifyEmployeeWidget);

        QMetaObject::connectSlotsByName(SearchModifyEmployeeWidget);
    } // setupUi

    void retranslateUi(QDialog *SearchModifyEmployeeWidget)
    {
        SearchModifyEmployeeWidget->setWindowTitle(QApplication::translate("SearchModifyEmployeeWidget", "\346\237\245\350\257\242\345\221\230\345\267\245\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("SearchModifyEmployeeWidget", "\345\247\223\345\220\215", nullptr));
        name_lineEdit->setPlaceholderText(QApplication::translate("SearchModifyEmployeeWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_25->setText(QApplication::translate("SearchModifyEmployeeWidget", "\346\211\213\346\234\272", nullptr));
        tel_lineEdit->setPlaceholderText(QApplication::translate("SearchModifyEmployeeWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_24->setText(QApplication::translate("SearchModifyEmployeeWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        id_lineEdit->setText(QString());
        id_lineEdit->setPlaceholderText(QApplication::translate("SearchModifyEmployeeWidget", "\344\270\215\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        search_pushButton->setText(QApplication::translate("SearchModifyEmployeeWidget", "\346\220\234\347\264\242", nullptr));
        save_pushButton->setText(QApplication::translate("SearchModifyEmployeeWidget", "\344\277\235\345\255\230", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SearchModifyEmployeeWidget: public Ui_SearchModifyEmployeeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHMODIFYEMPLOYEEWIDGET_H

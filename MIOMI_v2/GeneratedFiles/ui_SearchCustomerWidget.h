/********************************************************************************
** Form generated from reading UI file 'SearchCustomerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHCUSTOMERWIDGET_H
#define UI_SEARCHCUSTOMERWIDGET_H

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

class Ui_SearchCustomerWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_25;
    QLineEdit *tel_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_24;
    QLineEdit *vip_lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *search_pushButton;
    QTableView *tableView;

    void setupUi(QDialog *SearchCustomerWidget)
    {
        if (SearchCustomerWidget->objectName().isEmpty())
            SearchCustomerWidget->setObjectName(QStringLiteral("SearchCustomerWidget"));
        SearchCustomerWidget->resize(1021, 693);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/search.png")));
        SearchCustomerWidget->setWindowIcon(icon);
        SearchCustomerWidget->setSizeGripEnabled(false);
        verticalLayout_2 = new QVBoxLayout(SearchCustomerWidget);
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
        label_25 = new QLabel(SearchCustomerWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(12);
        label_25->setFont(font);

        horizontalLayout->addWidget(label_25);

        tel_lineEdit = new QLineEdit(SearchCustomerWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        horizontalLayout->addWidget(tel_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(SearchCustomerWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        name_lineEdit = new QLineEdit(SearchCustomerWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout_2->addWidget(name_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_24 = new QLabel(SearchCustomerWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        horizontalLayout_3->addWidget(label_24);

        vip_lineEdit = new QLineEdit(SearchCustomerWidget);
        vip_lineEdit->setObjectName(QStringLiteral("vip_lineEdit"));

        horizontalLayout_3->addWidget(vip_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        search_pushButton = new QPushButton(SearchCustomerWidget);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));
        search_pushButton->setFont(font);

        horizontalLayout_4->addWidget(search_pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        tableView = new QTableView(SearchCustomerWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SearchCustomerWidget);

        QMetaObject::connectSlotsByName(SearchCustomerWidget);
    } // setupUi

    void retranslateUi(QDialog *SearchCustomerWidget)
    {
        SearchCustomerWidget->setWindowTitle(QApplication::translate("SearchCustomerWidget", "\344\274\232\345\221\230\346\237\245\350\257\242", nullptr));
        label_25->setText(QApplication::translate("SearchCustomerWidget", "\346\211\213\346\234\272", nullptr));
        tel_lineEdit->setPlaceholderText(QApplication::translate("SearchCustomerWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("SearchCustomerWidget", "\345\247\223\345\220\215", nullptr));
        name_lineEdit->setPlaceholderText(QApplication::translate("SearchCustomerWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_24->setText(QApplication::translate("SearchCustomerWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        vip_lineEdit->setText(QString());
        vip_lineEdit->setPlaceholderText(QApplication::translate("SearchCustomerWidget", "\344\270\215\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        search_pushButton->setText(QApplication::translate("SearchCustomerWidget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchCustomerWidget: public Ui_SearchCustomerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHCUSTOMERWIDGET_H

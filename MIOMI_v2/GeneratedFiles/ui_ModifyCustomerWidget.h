/********************************************************************************
** Form generated from reading UI file 'ModifyCustomerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYCUSTOMERWIDGET_H
#define UI_MODIFYCUSTOMERWIDGET_H

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

class Ui_ModifyCustomerWidget
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
    QPushButton *save_pushButton;
    QLabel *label_2;
    QTableView *tableView;

    void setupUi(QDialog *ModifyCustomerWidget)
    {
        if (ModifyCustomerWidget->objectName().isEmpty())
            ModifyCustomerWidget->setObjectName(QStringLiteral("ModifyCustomerWidget"));
        ModifyCustomerWidget->resize(1044, 649);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/modify_vip.png")));
        ModifyCustomerWidget->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(ModifyCustomerWidget);
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
        label_25 = new QLabel(ModifyCustomerWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(12);
        label_25->setFont(font);

        horizontalLayout->addWidget(label_25);

        tel_lineEdit = new QLineEdit(ModifyCustomerWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        horizontalLayout->addWidget(tel_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ModifyCustomerWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        name_lineEdit = new QLineEdit(ModifyCustomerWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout_2->addWidget(name_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_24 = new QLabel(ModifyCustomerWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);

        horizontalLayout_3->addWidget(label_24);

        vip_lineEdit = new QLineEdit(ModifyCustomerWidget);
        vip_lineEdit->setObjectName(QStringLiteral("vip_lineEdit"));

        horizontalLayout_3->addWidget(vip_lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        search_pushButton = new QPushButton(ModifyCustomerWidget);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));
        search_pushButton->setFont(font);

        horizontalLayout_4->addWidget(search_pushButton);

        save_pushButton = new QPushButton(ModifyCustomerWidget);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));
        save_pushButton->setFont(font);

        horizontalLayout_4->addWidget(save_pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        label_2 = new QLabel(ModifyCustomerWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 128);"));

        verticalLayout->addWidget(label_2);

        tableView = new QTableView(ModifyCustomerWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ModifyCustomerWidget);

        QMetaObject::connectSlotsByName(ModifyCustomerWidget);
    } // setupUi

    void retranslateUi(QDialog *ModifyCustomerWidget)
    {
        ModifyCustomerWidget->setWindowTitle(QApplication::translate("ModifyCustomerWidget", "\344\274\232\345\221\230\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        label_25->setText(QApplication::translate("ModifyCustomerWidget", "\346\211\213\346\234\272", nullptr));
        tel_lineEdit->setPlaceholderText(QApplication::translate("ModifyCustomerWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("ModifyCustomerWidget", "\345\247\223\345\220\215", nullptr));
        name_lineEdit->setPlaceholderText(QApplication::translate("ModifyCustomerWidget", "\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_24->setText(QApplication::translate("ModifyCustomerWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        vip_lineEdit->setText(QString());
        vip_lineEdit->setPlaceholderText(QApplication::translate("ModifyCustomerWidget", "\344\270\215\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        search_pushButton->setText(QApplication::translate("ModifyCustomerWidget", "\346\220\234\347\264\242", nullptr));
        save_pushButton->setText(QApplication::translate("ModifyCustomerWidget", "\344\277\235\345\255\230", nullptr));
        label_2->setText(QApplication::translate("ModifyCustomerWidget", "\345\221\230\345\267\245\345\217\257\344\277\256\346\224\271\351\241\271\357\274\232\347\224\265\350\257\235\343\200\201\345\276\256\344\277\241\343\200\201QQ\343\200\201\345\234\260\345\235\200\343\200\201\350\277\221\350\247\206/\346\225\243\345\205\211\345\272\246\346\225\260\357\274\233 \346\227\240\346\263\225\344\277\256\346\224\271\351\241\271\357\274\232\344\274\232\345\221\230\345\217\267\343\200\201\345\247\223\345\220\215\343\200\201\346\200\247\345\210\253\343\200\201\346\266\210\350\264\271\346\254\241\346\225\260\343\200\201\347\247\257\345\210\206\357\274\233\345\217\214\345\207\273\345\215\225\345\205\203\346\240\274\344\277\256\346\224\271\357\274\214\344\277\256\346\224\271\345\256\214\346\210\220\345\220\216\347\202\271\345\207\273\344\277\235\345\255\230\345\215\263\345\217\257\343\200\202(10s \346\220\234\347\264\242\345\210\267\346\226\260)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyCustomerWidget: public Ui_ModifyCustomerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYCUSTOMERWIDGET_H

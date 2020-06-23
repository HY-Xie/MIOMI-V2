/********************************************************************************
** Form generated from reading UI file 'SysConfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSCONFIGURATION_H
#define UI_SYSCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SysConfiguration
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *local_radioButton;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *lan_radioButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *store_lineEdit;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_9;
    QVBoxLayout *verticalLayout;
    QComboBox *type_comboBox;
    QLineEdit *host_lineEdit;
    QLineEdit *name_lineEdit;
    QLineEdit *port_lineEdit;
    QLineEdit *user_lineEdit;
    QLineEdit *pass_lineEdit;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *save_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *SysConfiguration)
    {
        if (SysConfiguration->objectName().isEmpty())
            SysConfiguration->setObjectName(QStringLiteral("SysConfiguration"));
        SysConfiguration->resize(432, 508);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/system_72px_.png")));
        SysConfiguration->setWindowIcon(icon);
        gridLayout = new QGridLayout(SysConfiguration);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        label_4 = new QLabel(SysConfiguration);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(16);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(24, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        local_radioButton = new QRadioButton(SysConfiguration);
        local_radioButton->setObjectName(QStringLiteral("local_radioButton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font1.setPointSize(11);
        local_radioButton->setFont(font1);

        horizontalLayout_4->addWidget(local_radioButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        lan_radioButton = new QRadioButton(SysConfiguration);
        lan_radioButton->setObjectName(QStringLiteral("lan_radioButton"));
        lan_radioButton->setFont(font1);

        horizontalLayout_4->addWidget(lan_radioButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(SysConfiguration);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font2.setPointSize(12);
        label_3->setFont(font2);

        horizontalLayout_5->addWidget(label_3);

        store_lineEdit = new QLineEdit(SysConfiguration);
        store_lineEdit->setObjectName(QStringLiteral("store_lineEdit"));

        horizontalLayout_5->addWidget(store_lineEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(SysConfiguration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        verticalLayout_2->addWidget(label_7);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);

        verticalLayout_2->addWidget(label);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);

        verticalLayout_2->addWidget(label_9);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        type_comboBox = new QComboBox(groupBox);
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName(QStringLiteral("type_comboBox"));

        verticalLayout->addWidget(type_comboBox);

        host_lineEdit = new QLineEdit(groupBox);
        host_lineEdit->setObjectName(QStringLiteral("host_lineEdit"));

        verticalLayout->addWidget(host_lineEdit);

        name_lineEdit = new QLineEdit(groupBox);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        verticalLayout->addWidget(name_lineEdit);

        port_lineEdit = new QLineEdit(groupBox);
        port_lineEdit->setObjectName(QStringLiteral("port_lineEdit"));

        verticalLayout->addWidget(port_lineEdit);

        user_lineEdit = new QLineEdit(groupBox);
        user_lineEdit->setObjectName(QStringLiteral("user_lineEdit"));

        verticalLayout->addWidget(user_lineEdit);

        pass_lineEdit = new QLineEdit(groupBox);
        pass_lineEdit->setObjectName(QStringLiteral("pass_lineEdit"));
        QFont font3;
        font3.setFamily(QStringLiteral("Times New Roman"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        pass_lineEdit->setFont(font3);
        pass_lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(pass_lineEdit);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(groupBox);


        gridLayout->addLayout(verticalLayout_3, 3, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(24, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        save_pushButton = new QPushButton(SysConfiguration);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));
        save_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(save_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        cancel_pushButton = new QPushButton(SysConfiguration);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));
        cancel_pushButton->setFont(font2);

        horizontalLayout_3->addWidget(cancel_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 39, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);


        retranslateUi(SysConfiguration);

        QMetaObject::connectSlotsByName(SysConfiguration);
    } // setupUi

    void retranslateUi(QDialog *SysConfiguration)
    {
        SysConfiguration->setWindowTitle(QApplication::translate("SysConfiguration", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_4->setText(QApplication::translate("SysConfiguration", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        local_radioButton->setText(QApplication::translate("SysConfiguration", "\345\215\225\346\234\272\346\250\241\345\274\217", nullptr));
        lan_radioButton->setText(QApplication::translate("SysConfiguration", "\347\275\221\347\273\234\346\250\241\345\274\217", nullptr));
        label_3->setText(QApplication::translate("SysConfiguration", "\345\255\230\345\202\250\346\234\215\345\212\241\345\231\250", nullptr));
        groupBox->setTitle(QApplication::translate("SysConfiguration", "\346\225\260\346\215\256\345\272\223", nullptr));
        label_5->setText(QApplication::translate("SysConfiguration", "\346\225\260\346\215\256\345\272\223\347\261\273\345\236\213", nullptr));
        label_6->setText(QApplication::translate("SysConfiguration", "\346\225\260\346\215\256\345\272\223\344\270\273\346\234\272", nullptr));
        label_7->setText(QApplication::translate("SysConfiguration", "\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260", nullptr));
        label->setText(QApplication::translate("SysConfiguration", "\346\225\260\346\215\256\345\272\223\347\253\257\345\217\243", nullptr));
        label_8->setText(QApplication::translate("SysConfiguration", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_9->setText(QApplication::translate("SysConfiguration", "\345\257\206\347\240\201", nullptr));
        type_comboBox->setItemText(0, QApplication::translate("SysConfiguration", "QMYSQL", nullptr));

        save_pushButton->setText(QApplication::translate("SysConfiguration", "\344\277\235\345\255\230", nullptr));
        cancel_pushButton->setText(QApplication::translate("SysConfiguration", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SysConfiguration: public Ui_SysConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSCONFIGURATION_H

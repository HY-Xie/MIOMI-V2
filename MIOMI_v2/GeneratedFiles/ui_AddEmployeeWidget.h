/********************************************************************************
** Form generated from reading UI file 'AddEmployeeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMPLOYEEWIDGET_H
#define UI_ADDEMPLOYEEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEmployeeWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_26;
    QLabel *label_27;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_lineEdit;
    QLineEdit *tel_lineEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *weChat_lineEdit;
    QCheckBox *sameAsTel_checkBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *female_radioButton;
    QRadioButton *male_radioButton;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *id_lineEdit;
    QCheckBox *isManager_checkBox;
    QLineEdit *pass_lineEdit;
    QLineEdit *re_pass_lineEdit;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancle_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *AddEmployeeWidget)
    {
        if (AddEmployeeWidget->objectName().isEmpty())
            AddEmployeeWidget->setObjectName(QStringLiteral("AddEmployeeWidget"));
        AddEmployeeWidget->resize(450, 560);
        AddEmployeeWidget->setMinimumSize(QSize(450, 560));
        AddEmployeeWidget->setMaximumSize(QSize(450, 560));
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/new_72px_employee.png")));
        AddEmployeeWidget->setWindowIcon(icon);
        gridLayout = new QGridLayout(AddEmployeeWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(56, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(AddEmployeeWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(AddEmployeeWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_25 = new QLabel(AddEmployeeWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);
        label_25->setLayoutDirection(Qt::LeftToRight);
        label_25->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_25);

        label_22 = new QLabel(AddEmployeeWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);
        label_22->setLayoutDirection(Qt::LeftToRight);
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_22);

        label_23 = new QLabel(AddEmployeeWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);
        label_23->setLayoutDirection(Qt::LeftToRight);
        label_23->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_23);

        label_24 = new QLabel(AddEmployeeWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);
        label_24->setLayoutDirection(Qt::LeftToRight);
        label_24->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_24);

        label_26 = new QLabel(AddEmployeeWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font1);
        label_26->setLayoutDirection(Qt::LeftToRight);
        label_26->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_26);

        label_27 = new QLabel(AddEmployeeWidget);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font1);
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_27);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_lineEdit = new QLineEdit(AddEmployeeWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        verticalLayout->addWidget(name_lineEdit);

        tel_lineEdit = new QLineEdit(AddEmployeeWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        verticalLayout->addWidget(tel_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        weChat_lineEdit = new QLineEdit(AddEmployeeWidget);
        weChat_lineEdit->setObjectName(QStringLiteral("weChat_lineEdit"));

        horizontalLayout->addWidget(weChat_lineEdit);

        sameAsTel_checkBox = new QCheckBox(AddEmployeeWidget);
        sameAsTel_checkBox->setObjectName(QStringLiteral("sameAsTel_checkBox"));

        horizontalLayout->addWidget(sameAsTel_checkBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        female_radioButton = new QRadioButton(AddEmployeeWidget);
        female_radioButton->setObjectName(QStringLiteral("female_radioButton"));
        female_radioButton->setChecked(true);

        horizontalLayout_2->addWidget(female_radioButton);

        male_radioButton = new QRadioButton(AddEmployeeWidget);
        male_radioButton->setObjectName(QStringLiteral("male_radioButton"));

        horizontalLayout_2->addWidget(male_radioButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        id_lineEdit = new QLineEdit(AddEmployeeWidget);
        id_lineEdit->setObjectName(QStringLiteral("id_lineEdit"));

        horizontalLayout_3->addWidget(id_lineEdit);

        isManager_checkBox = new QCheckBox(AddEmployeeWidget);
        isManager_checkBox->setObjectName(QStringLiteral("isManager_checkBox"));

        horizontalLayout_3->addWidget(isManager_checkBox);


        verticalLayout->addLayout(horizontalLayout_3);

        pass_lineEdit = new QLineEdit(AddEmployeeWidget);
        pass_lineEdit->setObjectName(QStringLiteral("pass_lineEdit"));

        verticalLayout->addWidget(pass_lineEdit);

        re_pass_lineEdit = new QLineEdit(AddEmployeeWidget);
        re_pass_lineEdit->setObjectName(QStringLiteral("re_pass_lineEdit"));

        verticalLayout->addWidget(re_pass_lineEdit);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        add_pushButton = new QPushButton(AddEmployeeWidget);
        add_pushButton->setObjectName(QStringLiteral("add_pushButton"));
        add_pushButton->setFont(font1);

        horizontalLayout_5->addWidget(add_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        cancle_pushButton = new QPushButton(AddEmployeeWidget);
        cancle_pushButton->setObjectName(QStringLiteral("cancle_pushButton"));
        cancle_pushButton->setFont(font1);

        horizontalLayout_5->addWidget(cancle_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 1, 1, 2, 1);

        horizontalSpacer_5 = new QSpacerItem(55, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 3, 1, 1, 1);


        retranslateUi(AddEmployeeWidget);

        QMetaObject::connectSlotsByName(AddEmployeeWidget);
    } // setupUi

    void retranslateUi(QDialog *AddEmployeeWidget)
    {
        AddEmployeeWidget->setWindowTitle(QApplication::translate("AddEmployeeWidget", "\346\267\273\345\212\240\346\226\260\345\221\230\345\267\245\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label_2->setText(QApplication::translate("AddEmployeeWidget", "\346\267\273\345\212\240\345\221\230\345\267\245\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("AddEmployeeWidget", "\345\247\223  \345\220\215", nullptr));
        label_25->setText(QApplication::translate("AddEmployeeWidget", "\346\211\213  \346\234\272", nullptr));
        label_22->setText(QApplication::translate("AddEmployeeWidget", "\345\276\256  \344\277\241", nullptr));
        label_23->setText(QApplication::translate("AddEmployeeWidget", "\346\200\247 \345\210\253", nullptr));
        label_24->setText(QApplication::translate("AddEmployeeWidget", "\345\267\245 \345\217\267", nullptr));
        label_26->setText(QApplication::translate("AddEmployeeWidget", "\345\257\206 \347\240\201", nullptr));
        label_27->setText(QApplication::translate("AddEmployeeWidget", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        sameAsTel_checkBox->setText(QApplication::translate("AddEmployeeWidget", "\345\220\214\346\211\213\346\234\272", nullptr));
        female_radioButton->setText(QApplication::translate("AddEmployeeWidget", "\345\245\263", nullptr));
        male_radioButton->setText(QApplication::translate("AddEmployeeWidget", "\347\224\267", nullptr));
        isManager_checkBox->setText(QApplication::translate("AddEmployeeWidget", "\345\272\227\351\225\277", nullptr));
        add_pushButton->setText(QApplication::translate("AddEmployeeWidget", "\346\267\273\345\212\240", nullptr));
        cancle_pushButton->setText(QApplication::translate("AddEmployeeWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEmployeeWidget: public Ui_AddEmployeeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPLOYEEWIDGET_H

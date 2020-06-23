/********************************************************************************
** Form generated from reading UI file 'AddCustomerWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCUSTOMERWIDGET_H
#define UI_ADDCUSTOMERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_AddCustomerWidget
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *label_21;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_26;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_lineEdit;
    QLineEdit *tel_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *weChat_lineEdit;
    QCheckBox *sameAsTel_checkBox;
    QLineEdit *qq_lineEdit;
    QLineEdit *addr_lineEdit;
    QHBoxLayout *horizontalLayout;
    QRadioButton *female_radioButton;
    QRadioButton *male_radioButton;
    QLineEdit *vip_lineEdit;
    QLineEdit *score_lineEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *left_myopia_comboBox;
    QComboBox *left_astigmatism_comboBox;
    QLabel *label_10;
    QComboBox *right_myopia_comboBox;
    QComboBox *right_astigmatism_comboBox;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *add_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancle_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *AddCustomerWidget)
    {
        if (AddCustomerWidget->objectName().isEmpty())
            AddCustomerWidget->setObjectName(QStringLiteral("AddCustomerWidget"));
        AddCustomerWidget->resize(470, 580);
        AddCustomerWidget->setMinimumSize(QSize(470, 580));
        AddCustomerWidget->setMaximumSize(QSize(470, 580));
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/addCustomer.png")));
        AddCustomerWidget->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(AddCustomerWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(239, 509, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_2 = new QLabel(AddCustomerWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(AddCustomerWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(12);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        label_25 = new QLabel(AddCustomerWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font1);

        verticalLayout_2->addWidget(label_25);

        label_22 = new QLabel(AddCustomerWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font1);

        verticalLayout_2->addWidget(label_22);

        label_19 = new QLabel(AddCustomerWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        QFont font2;
        font2.setFamily(QStringLiteral("Algerian"));
        font2.setPointSize(12);
        label_19->setFont(font2);

        verticalLayout_2->addWidget(label_19);

        label_21 = new QLabel(AddCustomerWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font1);

        verticalLayout_2->addWidget(label_21);

        label_23 = new QLabel(AddCustomerWidget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font1);

        verticalLayout_2->addWidget(label_23);

        label_24 = new QLabel(AddCustomerWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font1);

        verticalLayout_2->addWidget(label_24);

        label_26 = new QLabel(AddCustomerWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font1);

        verticalLayout_2->addWidget(label_26);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_lineEdit = new QLineEdit(AddCustomerWidget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        verticalLayout->addWidget(name_lineEdit);

        tel_lineEdit = new QLineEdit(AddCustomerWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        verticalLayout->addWidget(tel_lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        weChat_lineEdit = new QLineEdit(AddCustomerWidget);
        weChat_lineEdit->setObjectName(QStringLiteral("weChat_lineEdit"));

        horizontalLayout_2->addWidget(weChat_lineEdit);

        sameAsTel_checkBox = new QCheckBox(AddCustomerWidget);
        sameAsTel_checkBox->setObjectName(QStringLiteral("sameAsTel_checkBox"));

        horizontalLayout_2->addWidget(sameAsTel_checkBox);


        verticalLayout->addLayout(horizontalLayout_2);

        qq_lineEdit = new QLineEdit(AddCustomerWidget);
        qq_lineEdit->setObjectName(QStringLiteral("qq_lineEdit"));

        verticalLayout->addWidget(qq_lineEdit);

        addr_lineEdit = new QLineEdit(AddCustomerWidget);
        addr_lineEdit->setObjectName(QStringLiteral("addr_lineEdit"));

        verticalLayout->addWidget(addr_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        female_radioButton = new QRadioButton(AddCustomerWidget);
        female_radioButton->setObjectName(QStringLiteral("female_radioButton"));
        female_radioButton->setChecked(true);

        horizontalLayout->addWidget(female_radioButton);

        male_radioButton = new QRadioButton(AddCustomerWidget);
        male_radioButton->setObjectName(QStringLiteral("male_radioButton"));

        horizontalLayout->addWidget(male_radioButton);


        verticalLayout->addLayout(horizontalLayout);

        vip_lineEdit = new QLineEdit(AddCustomerWidget);
        vip_lineEdit->setObjectName(QStringLiteral("vip_lineEdit"));

        verticalLayout->addWidget(vip_lineEdit);

        score_lineEdit = new QLineEdit(AddCustomerWidget);
        score_lineEdit->setObjectName(QStringLiteral("score_lineEdit"));

        verticalLayout->addWidget(score_lineEdit);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        groupBox = new QGroupBox(AddCustomerWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        left_myopia_comboBox = new QComboBox(groupBox);
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->addItem(QString());
        left_myopia_comboBox->setObjectName(QStringLiteral("left_myopia_comboBox"));

        gridLayout->addWidget(left_myopia_comboBox, 1, 1, 1, 1);

        left_astigmatism_comboBox = new QComboBox(groupBox);
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->addItem(QString());
        left_astigmatism_comboBox->setObjectName(QStringLiteral("left_astigmatism_comboBox"));

        gridLayout->addWidget(left_astigmatism_comboBox, 1, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        right_myopia_comboBox = new QComboBox(groupBox);
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->addItem(QString());
        right_myopia_comboBox->setObjectName(QStringLiteral("right_myopia_comboBox"));

        gridLayout->addWidget(right_myopia_comboBox, 2, 1, 1, 1);

        right_astigmatism_comboBox = new QComboBox(groupBox);
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->addItem(QString());
        right_astigmatism_comboBox->setObjectName(QStringLiteral("right_astigmatism_comboBox"));

        gridLayout->addWidget(right_astigmatism_comboBox, 2, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        add_pushButton = new QPushButton(AddCustomerWidget);
        add_pushButton->setObjectName(QStringLiteral("add_pushButton"));
        add_pushButton->setFont(font1);

        horizontalLayout_4->addWidget(add_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cancle_pushButton = new QPushButton(AddCustomerWidget);
        cancle_pushButton->setObjectName(QStringLiteral("cancle_pushButton"));
        cancle_pushButton->setFont(font1);

        horizontalLayout_4->addWidget(cancle_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_3, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(335, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(239, 509, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(335, 47, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(AddCustomerWidget);

        QMetaObject::connectSlotsByName(AddCustomerWidget);
    } // setupUi

    void retranslateUi(QDialog *AddCustomerWidget)
    {
        AddCustomerWidget->setWindowTitle(QApplication::translate("AddCustomerWidget", "\346\267\273\345\212\240\344\274\232\345\221\230", nullptr));
        label_2->setText(QApplication::translate("AddCustomerWidget", "\346\267\273\345\212\240\344\274\232\345\221\230", nullptr));
        label->setText(QApplication::translate("AddCustomerWidget", "\345\247\223\345\220\215", nullptr));
        label_25->setText(QApplication::translate("AddCustomerWidget", "\346\211\213\346\234\272", nullptr));
        label_22->setText(QApplication::translate("AddCustomerWidget", "\345\276\256\344\277\241", nullptr));
        label_19->setText(QApplication::translate("AddCustomerWidget", "QQ", nullptr));
        label_21->setText(QApplication::translate("AddCustomerWidget", "\345\234\260\345\235\200", nullptr));
        label_23->setText(QApplication::translate("AddCustomerWidget", "\346\200\247\345\210\253", nullptr));
        label_24->setText(QApplication::translate("AddCustomerWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        label_26->setText(QApplication::translate("AddCustomerWidget", "\347\247\257\345\210\206", nullptr));
        sameAsTel_checkBox->setText(QApplication::translate("AddCustomerWidget", "\345\220\214\346\211\213\346\234\272", nullptr));
        female_radioButton->setText(QApplication::translate("AddCustomerWidget", "\345\245\263", nullptr));
        male_radioButton->setText(QApplication::translate("AddCustomerWidget", "\347\224\267", nullptr));
        vip_lineEdit->setText(QString());
        groupBox->setTitle(QApplication::translate("AddCustomerWidget", "\345\272\246\346\225\260", nullptr));
        label_7->setText(QApplication::translate("AddCustomerWidget", "\350\277\221\350\247\206", nullptr));
        label_8->setText(QApplication::translate("AddCustomerWidget", "\346\225\243\345\205\211", nullptr));
        label_9->setText(QApplication::translate("AddCustomerWidget", "\345\267\246", nullptr));
        left_myopia_comboBox->setItemText(0, QApplication::translate("AddCustomerWidget", "0", nullptr));
        left_myopia_comboBox->setItemText(1, QApplication::translate("AddCustomerWidget", "25", nullptr));
        left_myopia_comboBox->setItemText(2, QApplication::translate("AddCustomerWidget", "50", nullptr));
        left_myopia_comboBox->setItemText(3, QApplication::translate("AddCustomerWidget", "75", nullptr));
        left_myopia_comboBox->setItemText(4, QApplication::translate("AddCustomerWidget", "100", nullptr));
        left_myopia_comboBox->setItemText(5, QApplication::translate("AddCustomerWidget", "125", nullptr));
        left_myopia_comboBox->setItemText(6, QApplication::translate("AddCustomerWidget", "150", nullptr));
        left_myopia_comboBox->setItemText(7, QApplication::translate("AddCustomerWidget", "175", nullptr));
        left_myopia_comboBox->setItemText(8, QApplication::translate("AddCustomerWidget", "200", nullptr));
        left_myopia_comboBox->setItemText(9, QApplication::translate("AddCustomerWidget", "225", nullptr));
        left_myopia_comboBox->setItemText(10, QApplication::translate("AddCustomerWidget", "250", nullptr));
        left_myopia_comboBox->setItemText(11, QApplication::translate("AddCustomerWidget", "275", nullptr));
        left_myopia_comboBox->setItemText(12, QApplication::translate("AddCustomerWidget", "300", nullptr));
        left_myopia_comboBox->setItemText(13, QApplication::translate("AddCustomerWidget", "325", nullptr));
        left_myopia_comboBox->setItemText(14, QApplication::translate("AddCustomerWidget", "350", nullptr));
        left_myopia_comboBox->setItemText(15, QApplication::translate("AddCustomerWidget", "375", nullptr));
        left_myopia_comboBox->setItemText(16, QApplication::translate("AddCustomerWidget", "400", nullptr));
        left_myopia_comboBox->setItemText(17, QApplication::translate("AddCustomerWidget", "425", nullptr));
        left_myopia_comboBox->setItemText(18, QApplication::translate("AddCustomerWidget", "450", nullptr));
        left_myopia_comboBox->setItemText(19, QApplication::translate("AddCustomerWidget", "475", nullptr));
        left_myopia_comboBox->setItemText(20, QApplication::translate("AddCustomerWidget", "500", nullptr));
        left_myopia_comboBox->setItemText(21, QApplication::translate("AddCustomerWidget", "550", nullptr));
        left_myopia_comboBox->setItemText(22, QApplication::translate("AddCustomerWidget", "600", nullptr));
        left_myopia_comboBox->setItemText(23, QApplication::translate("AddCustomerWidget", "650", nullptr));
        left_myopia_comboBox->setItemText(24, QApplication::translate("AddCustomerWidget", "700", nullptr));
        left_myopia_comboBox->setItemText(25, QApplication::translate("AddCustomerWidget", "750", nullptr));
        left_myopia_comboBox->setItemText(26, QApplication::translate("AddCustomerWidget", "800", nullptr));
        left_myopia_comboBox->setItemText(27, QApplication::translate("AddCustomerWidget", "850", nullptr));
        left_myopia_comboBox->setItemText(28, QApplication::translate("AddCustomerWidget", "900", nullptr));
        left_myopia_comboBox->setItemText(29, QApplication::translate("AddCustomerWidget", "950", nullptr));
        left_myopia_comboBox->setItemText(30, QApplication::translate("AddCustomerWidget", "1000", nullptr));

        left_astigmatism_comboBox->setItemText(0, QApplication::translate("AddCustomerWidget", "0", nullptr));
        left_astigmatism_comboBox->setItemText(1, QApplication::translate("AddCustomerWidget", "25", nullptr));
        left_astigmatism_comboBox->setItemText(2, QApplication::translate("AddCustomerWidget", "50", nullptr));
        left_astigmatism_comboBox->setItemText(3, QApplication::translate("AddCustomerWidget", "75", nullptr));
        left_astigmatism_comboBox->setItemText(4, QApplication::translate("AddCustomerWidget", "100", nullptr));
        left_astigmatism_comboBox->setItemText(5, QApplication::translate("AddCustomerWidget", "125", nullptr));
        left_astigmatism_comboBox->setItemText(6, QApplication::translate("AddCustomerWidget", "150", nullptr));
        left_astigmatism_comboBox->setItemText(7, QApplication::translate("AddCustomerWidget", "175", nullptr));
        left_astigmatism_comboBox->setItemText(8, QApplication::translate("AddCustomerWidget", "200", nullptr));
        left_astigmatism_comboBox->setItemText(9, QApplication::translate("AddCustomerWidget", "225", nullptr));
        left_astigmatism_comboBox->setItemText(10, QApplication::translate("AddCustomerWidget", "250", nullptr));
        left_astigmatism_comboBox->setItemText(11, QApplication::translate("AddCustomerWidget", "275", nullptr));
        left_astigmatism_comboBox->setItemText(12, QApplication::translate("AddCustomerWidget", "300", nullptr));
        left_astigmatism_comboBox->setItemText(13, QApplication::translate("AddCustomerWidget", "325", nullptr));
        left_astigmatism_comboBox->setItemText(14, QApplication::translate("AddCustomerWidget", "350", nullptr));
        left_astigmatism_comboBox->setItemText(15, QApplication::translate("AddCustomerWidget", "375", nullptr));
        left_astigmatism_comboBox->setItemText(16, QApplication::translate("AddCustomerWidget", "400", nullptr));
        left_astigmatism_comboBox->setItemText(17, QApplication::translate("AddCustomerWidget", "425", nullptr));
        left_astigmatism_comboBox->setItemText(18, QApplication::translate("AddCustomerWidget", "450", nullptr));
        left_astigmatism_comboBox->setItemText(19, QApplication::translate("AddCustomerWidget", "475", nullptr));
        left_astigmatism_comboBox->setItemText(20, QApplication::translate("AddCustomerWidget", "500", nullptr));
        left_astigmatism_comboBox->setItemText(21, QApplication::translate("AddCustomerWidget", "550", nullptr));
        left_astigmatism_comboBox->setItemText(22, QApplication::translate("AddCustomerWidget", "600", nullptr));
        left_astigmatism_comboBox->setItemText(23, QApplication::translate("AddCustomerWidget", "650", nullptr));
        left_astigmatism_comboBox->setItemText(24, QApplication::translate("AddCustomerWidget", "700", nullptr));
        left_astigmatism_comboBox->setItemText(25, QApplication::translate("AddCustomerWidget", "750", nullptr));
        left_astigmatism_comboBox->setItemText(26, QApplication::translate("AddCustomerWidget", "800", nullptr));
        left_astigmatism_comboBox->setItemText(27, QApplication::translate("AddCustomerWidget", "850", nullptr));
        left_astigmatism_comboBox->setItemText(28, QApplication::translate("AddCustomerWidget", "900", nullptr));
        left_astigmatism_comboBox->setItemText(29, QApplication::translate("AddCustomerWidget", "950", nullptr));
        left_astigmatism_comboBox->setItemText(30, QApplication::translate("AddCustomerWidget", "1000", nullptr));

        label_10->setText(QApplication::translate("AddCustomerWidget", "\345\217\263", nullptr));
        right_myopia_comboBox->setItemText(0, QApplication::translate("AddCustomerWidget", "0", nullptr));
        right_myopia_comboBox->setItemText(1, QApplication::translate("AddCustomerWidget", "25", nullptr));
        right_myopia_comboBox->setItemText(2, QApplication::translate("AddCustomerWidget", "50", nullptr));
        right_myopia_comboBox->setItemText(3, QApplication::translate("AddCustomerWidget", "75", nullptr));
        right_myopia_comboBox->setItemText(4, QApplication::translate("AddCustomerWidget", "100", nullptr));
        right_myopia_comboBox->setItemText(5, QApplication::translate("AddCustomerWidget", "125", nullptr));
        right_myopia_comboBox->setItemText(6, QApplication::translate("AddCustomerWidget", "150", nullptr));
        right_myopia_comboBox->setItemText(7, QApplication::translate("AddCustomerWidget", "175", nullptr));
        right_myopia_comboBox->setItemText(8, QApplication::translate("AddCustomerWidget", "200", nullptr));
        right_myopia_comboBox->setItemText(9, QApplication::translate("AddCustomerWidget", "225", nullptr));
        right_myopia_comboBox->setItemText(10, QApplication::translate("AddCustomerWidget", "250", nullptr));
        right_myopia_comboBox->setItemText(11, QApplication::translate("AddCustomerWidget", "275", nullptr));
        right_myopia_comboBox->setItemText(12, QApplication::translate("AddCustomerWidget", "300", nullptr));
        right_myopia_comboBox->setItemText(13, QApplication::translate("AddCustomerWidget", "325", nullptr));
        right_myopia_comboBox->setItemText(14, QApplication::translate("AddCustomerWidget", "350", nullptr));
        right_myopia_comboBox->setItemText(15, QApplication::translate("AddCustomerWidget", "375", nullptr));
        right_myopia_comboBox->setItemText(16, QApplication::translate("AddCustomerWidget", "400", nullptr));
        right_myopia_comboBox->setItemText(17, QApplication::translate("AddCustomerWidget", "425", nullptr));
        right_myopia_comboBox->setItemText(18, QApplication::translate("AddCustomerWidget", "450", nullptr));
        right_myopia_comboBox->setItemText(19, QApplication::translate("AddCustomerWidget", "475", nullptr));
        right_myopia_comboBox->setItemText(20, QApplication::translate("AddCustomerWidget", "500", nullptr));
        right_myopia_comboBox->setItemText(21, QApplication::translate("AddCustomerWidget", "550", nullptr));
        right_myopia_comboBox->setItemText(22, QApplication::translate("AddCustomerWidget", "600", nullptr));
        right_myopia_comboBox->setItemText(23, QApplication::translate("AddCustomerWidget", "650", nullptr));
        right_myopia_comboBox->setItemText(24, QApplication::translate("AddCustomerWidget", "700", nullptr));
        right_myopia_comboBox->setItemText(25, QApplication::translate("AddCustomerWidget", "750", nullptr));
        right_myopia_comboBox->setItemText(26, QApplication::translate("AddCustomerWidget", "800", nullptr));
        right_myopia_comboBox->setItemText(27, QApplication::translate("AddCustomerWidget", "850", nullptr));
        right_myopia_comboBox->setItemText(28, QApplication::translate("AddCustomerWidget", "900", nullptr));
        right_myopia_comboBox->setItemText(29, QApplication::translate("AddCustomerWidget", "950", nullptr));
        right_myopia_comboBox->setItemText(30, QApplication::translate("AddCustomerWidget", "1000", nullptr));

        right_astigmatism_comboBox->setItemText(0, QApplication::translate("AddCustomerWidget", "0", nullptr));
        right_astigmatism_comboBox->setItemText(1, QApplication::translate("AddCustomerWidget", "25", nullptr));
        right_astigmatism_comboBox->setItemText(2, QApplication::translate("AddCustomerWidget", "50", nullptr));
        right_astigmatism_comboBox->setItemText(3, QApplication::translate("AddCustomerWidget", "75", nullptr));
        right_astigmatism_comboBox->setItemText(4, QApplication::translate("AddCustomerWidget", "100", nullptr));
        right_astigmatism_comboBox->setItemText(5, QApplication::translate("AddCustomerWidget", "125", nullptr));
        right_astigmatism_comboBox->setItemText(6, QApplication::translate("AddCustomerWidget", "150", nullptr));
        right_astigmatism_comboBox->setItemText(7, QApplication::translate("AddCustomerWidget", "175", nullptr));
        right_astigmatism_comboBox->setItemText(8, QApplication::translate("AddCustomerWidget", "200", nullptr));
        right_astigmatism_comboBox->setItemText(9, QApplication::translate("AddCustomerWidget", "225", nullptr));
        right_astigmatism_comboBox->setItemText(10, QApplication::translate("AddCustomerWidget", "250", nullptr));
        right_astigmatism_comboBox->setItemText(11, QApplication::translate("AddCustomerWidget", "275", nullptr));
        right_astigmatism_comboBox->setItemText(12, QApplication::translate("AddCustomerWidget", "300", nullptr));
        right_astigmatism_comboBox->setItemText(13, QApplication::translate("AddCustomerWidget", "325", nullptr));
        right_astigmatism_comboBox->setItemText(14, QApplication::translate("AddCustomerWidget", "350", nullptr));
        right_astigmatism_comboBox->setItemText(15, QApplication::translate("AddCustomerWidget", "375", nullptr));
        right_astigmatism_comboBox->setItemText(16, QApplication::translate("AddCustomerWidget", "400", nullptr));
        right_astigmatism_comboBox->setItemText(17, QApplication::translate("AddCustomerWidget", "425", nullptr));
        right_astigmatism_comboBox->setItemText(18, QApplication::translate("AddCustomerWidget", "450", nullptr));
        right_astigmatism_comboBox->setItemText(19, QApplication::translate("AddCustomerWidget", "475", nullptr));
        right_astigmatism_comboBox->setItemText(20, QApplication::translate("AddCustomerWidget", "500", nullptr));
        right_astigmatism_comboBox->setItemText(21, QApplication::translate("AddCustomerWidget", "550", nullptr));
        right_astigmatism_comboBox->setItemText(22, QApplication::translate("AddCustomerWidget", "600", nullptr));
        right_astigmatism_comboBox->setItemText(23, QApplication::translate("AddCustomerWidget", "650", nullptr));
        right_astigmatism_comboBox->setItemText(24, QApplication::translate("AddCustomerWidget", "700", nullptr));
        right_astigmatism_comboBox->setItemText(25, QApplication::translate("AddCustomerWidget", "750", nullptr));
        right_astigmatism_comboBox->setItemText(26, QApplication::translate("AddCustomerWidget", "800", nullptr));
        right_astigmatism_comboBox->setItemText(27, QApplication::translate("AddCustomerWidget", "850", nullptr));
        right_astigmatism_comboBox->setItemText(28, QApplication::translate("AddCustomerWidget", "900", nullptr));
        right_astigmatism_comboBox->setItemText(29, QApplication::translate("AddCustomerWidget", "950", nullptr));
        right_astigmatism_comboBox->setItemText(30, QApplication::translate("AddCustomerWidget", "1000", nullptr));

        add_pushButton->setText(QApplication::translate("AddCustomerWidget", "\346\267\273\345\212\240", nullptr));
        cancle_pushButton->setText(QApplication::translate("AddCustomerWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCustomerWidget: public Ui_AddCustomerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCUSTOMERWIDGET_H

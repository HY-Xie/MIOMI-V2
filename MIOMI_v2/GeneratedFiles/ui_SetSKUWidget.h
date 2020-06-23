/********************************************************************************
** Form generated from reading UI file 'SetSKUWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSKUWIDGET_H
#define UI_SETSKUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetSKUWidget
{
public:
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_14;
    QVBoxLayout *verticalLayout;
    QComboBox *glassbrand_comboBox;
    QLineEdit *glassMode_lineEdit;
    QLineEdit *glassColor_lineEdit;
    QLineEdit *glassDegree_lineEdit;
    QLineEdit *glassSku_lineEdit;
    QSpinBox *glassAmount_spinBox;
    QWidget *tab_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *eyedropBrand_lineEdit;
    QLineEdit *eyedropMode_lineEdit;
    QLineEdit *eyedropSku_lineEdit;
    QSpinBox *eyedropAmount_spinBox;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *nursingBrand_lineEdit;
    QLineEdit *nursingMode_lineEdit;
    QLineEdit *nursingColor_lineEdit;
    QLineEdit *nursingSku_lineEdit;
    QSpinBox *nursingAmount_spinBox;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_19;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *washBrand_lineEdit;
    QLineEdit *washMode_lineEdit;
    QLineEdit *washColor_lineEdit;
    QLineEdit *washSku_lineEdit;
    QSpinBox *washAmount_spinBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *save_pushButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancel_pushButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_10;
    QLabel *tableName_label;
    QTableView *tableView;

    void setupUi(QDialog *SetSKUWidget)
    {
        if (SetSKUWidget->objectName().isEmpty())
            SetSKUWidget->setObjectName(QStringLiteral("SetSKUWidget"));
        SetSKUWidget->resize(1337, 756);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/input.png")));
        SetSKUWidget->setWindowIcon(icon);
        horizontalLayout_7 = new QHBoxLayout(SetSKUWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        tabWidget = new QTabWidget(SetSKUWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_2->addWidget(label_14);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        glassbrand_comboBox = new QComboBox(tab);
        glassbrand_comboBox->addItem(QString());
        glassbrand_comboBox->addItem(QString());
        glassbrand_comboBox->setObjectName(QStringLiteral("glassbrand_comboBox"));

        verticalLayout->addWidget(glassbrand_comboBox);

        glassMode_lineEdit = new QLineEdit(tab);
        glassMode_lineEdit->setObjectName(QStringLiteral("glassMode_lineEdit"));

        verticalLayout->addWidget(glassMode_lineEdit);

        glassColor_lineEdit = new QLineEdit(tab);
        glassColor_lineEdit->setObjectName(QStringLiteral("glassColor_lineEdit"));

        verticalLayout->addWidget(glassColor_lineEdit);

        glassDegree_lineEdit = new QLineEdit(tab);
        glassDegree_lineEdit->setObjectName(QStringLiteral("glassDegree_lineEdit"));

        verticalLayout->addWidget(glassDegree_lineEdit);

        glassSku_lineEdit = new QLineEdit(tab);
        glassSku_lineEdit->setObjectName(QStringLiteral("glassSku_lineEdit"));

        verticalLayout->addWidget(glassSku_lineEdit);

        glassAmount_spinBox = new QSpinBox(tab);
        glassAmount_spinBox->setObjectName(QStringLiteral("glassAmount_spinBox"));
        glassAmount_spinBox->setMaximum(9999999);

        verticalLayout->addWidget(glassAmount_spinBox);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_2 = new QGridLayout(tab_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_4->addWidget(label_7);

        label_15 = new QLabel(tab_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(tab_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_4->addWidget(label_16);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        eyedropBrand_lineEdit = new QLineEdit(tab_4);
        eyedropBrand_lineEdit->setObjectName(QStringLiteral("eyedropBrand_lineEdit"));

        verticalLayout_3->addWidget(eyedropBrand_lineEdit);

        eyedropMode_lineEdit = new QLineEdit(tab_4);
        eyedropMode_lineEdit->setObjectName(QStringLiteral("eyedropMode_lineEdit"));

        verticalLayout_3->addWidget(eyedropMode_lineEdit);

        eyedropSku_lineEdit = new QLineEdit(tab_4);
        eyedropSku_lineEdit->setObjectName(QStringLiteral("eyedropSku_lineEdit"));

        verticalLayout_3->addWidget(eyedropSku_lineEdit);

        eyedropAmount_spinBox = new QSpinBox(tab_4);
        eyedropAmount_spinBox->setObjectName(QStringLiteral("eyedropAmount_spinBox"));
        eyedropAmount_spinBox->setMaximum(9999);

        verticalLayout_3->addWidget(eyedropAmount_spinBox);


        horizontalLayout_2->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_6->addWidget(label_9);

        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_6->addWidget(label_10);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_6->addWidget(label_17);

        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_6->addWidget(label_18);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        nursingBrand_lineEdit = new QLineEdit(tab_2);
        nursingBrand_lineEdit->setObjectName(QStringLiteral("nursingBrand_lineEdit"));

        verticalLayout_5->addWidget(nursingBrand_lineEdit);

        nursingMode_lineEdit = new QLineEdit(tab_2);
        nursingMode_lineEdit->setObjectName(QStringLiteral("nursingMode_lineEdit"));

        verticalLayout_5->addWidget(nursingMode_lineEdit);

        nursingColor_lineEdit = new QLineEdit(tab_2);
        nursingColor_lineEdit->setObjectName(QStringLiteral("nursingColor_lineEdit"));

        verticalLayout_5->addWidget(nursingColor_lineEdit);

        nursingSku_lineEdit = new QLineEdit(tab_2);
        nursingSku_lineEdit->setObjectName(QStringLiteral("nursingSku_lineEdit"));

        verticalLayout_5->addWidget(nursingSku_lineEdit);

        nursingAmount_spinBox = new QSpinBox(tab_2);
        nursingAmount_spinBox->setObjectName(QStringLiteral("nursingAmount_spinBox"));
        nursingAmount_spinBox->setMaximum(9999);

        verticalLayout_5->addWidget(nursingAmount_spinBox);


        horizontalLayout_3->addLayout(verticalLayout_5);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_7->addWidget(label_11);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_7->addWidget(label_12);

        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_7->addWidget(label_13);

        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_7->addWidget(label_19);

        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout_7->addWidget(label_20);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        washBrand_lineEdit = new QLineEdit(tab_3);
        washBrand_lineEdit->setObjectName(QStringLiteral("washBrand_lineEdit"));

        verticalLayout_8->addWidget(washBrand_lineEdit);

        washMode_lineEdit = new QLineEdit(tab_3);
        washMode_lineEdit->setObjectName(QStringLiteral("washMode_lineEdit"));

        verticalLayout_8->addWidget(washMode_lineEdit);

        washColor_lineEdit = new QLineEdit(tab_3);
        washColor_lineEdit->setObjectName(QStringLiteral("washColor_lineEdit"));

        verticalLayout_8->addWidget(washColor_lineEdit);

        washSku_lineEdit = new QLineEdit(tab_3);
        washSku_lineEdit->setObjectName(QStringLiteral("washSku_lineEdit"));

        verticalLayout_8->addWidget(washSku_lineEdit);

        washAmount_spinBox = new QSpinBox(tab_3);
        washAmount_spinBox->setObjectName(QStringLiteral("washAmount_spinBox"));
        washAmount_spinBox->setMaximum(9999);

        verticalLayout_8->addWidget(washAmount_spinBox);


        horizontalLayout_4->addLayout(verticalLayout_8);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_9->addWidget(tabWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        save_pushButton = new QPushButton(SetSKUWidget);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));

        horizontalLayout_5->addWidget(save_pushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        cancel_pushButton = new QPushButton(SetSKUWidget);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));

        horizontalLayout_5->addWidget(cancel_pushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_9->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        verticalLayout_9->setStretch(0, 8);
        verticalLayout_9->setStretch(1, 5);
        verticalLayout_9->setStretch(3, 1);
        verticalLayout_9->setStretch(4, 8);

        horizontalLayout_6->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tableName_label = new QLabel(SetSKUWidget);
        tableName_label->setObjectName(QStringLiteral("tableName_label"));

        verticalLayout_10->addWidget(tableName_label);

        tableView = new QTableView(SetSKUWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setSortingEnabled(false);

        verticalLayout_10->addWidget(tableView);


        horizontalLayout_6->addLayout(verticalLayout_10);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 8);

        horizontalLayout_7->addLayout(horizontalLayout_6);


        retranslateUi(SetSKUWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SetSKUWidget);
    } // setupUi

    void retranslateUi(QDialog *SetSKUWidget)
    {
        SetSKUWidget->setWindowTitle(QApplication::translate("SetSKUWidget", "\346\226\260\345\223\201SKU\345\275\225\345\205\245", nullptr));
        label_4->setText(QApplication::translate("SetSKUWidget", "\345\223\201\347\211\214", nullptr));
        label_5->setText(QApplication::translate("SetSKUWidget", "\345\236\213\345\217\267", nullptr));
        label_2->setText(QApplication::translate("SetSKUWidget", "\351\242\234\350\211\262", nullptr));
        label_3->setText(QApplication::translate("SetSKUWidget", "\345\272\246\346\225\260", nullptr));
        label->setText(QApplication::translate("SetSKUWidget", "SKU", nullptr));
        label_14->setText(QApplication::translate("SetSKUWidget", "\346\225\260\351\207\217", nullptr));
        glassbrand_comboBox->setItemText(0, QApplication::translate("SetSKUWidget", "\347\261\263\346\254\247\347\261\263", nullptr));
        glassbrand_comboBox->setItemText(1, QApplication::translate("SetSKUWidget", "\347\276\216\347\233\256\344\274\230\347\236\263", nullptr));

        glassMode_lineEdit->setPlaceholderText(QApplication::translate("SetSKUWidget", "\347\244\272\344\276\213 P04", nullptr));
        glassColor_lineEdit->setPlaceholderText(QApplication::translate("SetSKUWidget", "\347\244\272\344\276\213 \346\267\261\350\223\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SetSKUWidget", "\351\232\220\345\275\242\347\234\274\351\225\234", nullptr));
        label_6->setText(QApplication::translate("SetSKUWidget", "\345\223\201\347\211\214", nullptr));
        label_7->setText(QApplication::translate("SetSKUWidget", "\345\236\213\345\217\267", nullptr));
        label_15->setText(QApplication::translate("SetSKUWidget", "SKU", nullptr));
        label_16->setText(QApplication::translate("SetSKUWidget", "\346\225\260\351\207\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("SetSKUWidget", "\347\234\274\350\215\257\346\260\264", nullptr));
        label_8->setText(QApplication::translate("SetSKUWidget", "\345\223\201\347\211\214", nullptr));
        label_9->setText(QApplication::translate("SetSKUWidget", "\345\236\213\345\217\267", nullptr));
        label_10->setText(QApplication::translate("SetSKUWidget", "\351\242\234\350\211\262", nullptr));
        label_17->setText(QApplication::translate("SetSKUWidget", "SKU", nullptr));
        label_18->setText(QApplication::translate("SetSKUWidget", "\346\225\260\351\207\217", nullptr));
        nursingColor_lineEdit->setText(QString());
        nursingColor_lineEdit->setPlaceholderText(QApplication::translate("SetSKUWidget", "\347\244\272\344\276\213 \346\267\261\350\223\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SetSKUWidget", "\346\212\244\347\220\206\346\266\262", nullptr));
        label_11->setText(QApplication::translate("SetSKUWidget", "\345\223\201\347\211\214", nullptr));
        label_12->setText(QApplication::translate("SetSKUWidget", "\345\236\213\345\217\267", nullptr));
        label_13->setText(QApplication::translate("SetSKUWidget", "\351\242\234\350\211\262", nullptr));
        label_19->setText(QApplication::translate("SetSKUWidget", "SKU", nullptr));
        label_20->setText(QApplication::translate("SetSKUWidget", "\346\225\260\351\207\217", nullptr));
        washColor_lineEdit->setPlaceholderText(QApplication::translate("SetSKUWidget", "\347\244\272\344\276\213 \346\267\261\350\223\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("SetSKUWidget", "\346\264\227\347\234\274\346\266\262", nullptr));
        save_pushButton->setText(QApplication::translate("SetSKUWidget", "\344\277\235\345\255\230", nullptr));
        cancel_pushButton->setText(QApplication::translate("SetSKUWidget", "\345\217\226\346\266\210", nullptr));
        tableName_label->setText(QApplication::translate("SetSKUWidget", "tableName", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetSKUWidget: public Ui_SetSKUWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSKUWIDGET_H

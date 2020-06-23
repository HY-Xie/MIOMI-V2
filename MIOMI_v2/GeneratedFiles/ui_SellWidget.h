/********************************************************************************
** Form generated from reading UI file 'SellWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLWIDGET_H
#define UI_SELLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SellWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *vip_groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QLineEdit *tel_lineEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *vip_lineEdit;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *search_pushButton;
    QFrame *line;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *label_11;
    QLineEdit *scoreInfo_lineEdit;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *telInfo_lineEdit;
    QLabel *label_14;
    QLineEdit *vipInfo_lineEdit;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_12;
    QLineEdit *nameInfo_lineEdit;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *purchaseInfo_lineEdit;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *product_groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *type_comboBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_5;
    QComboBox *sku_comboBox;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *price_doubleSpinBox;
    QSpacerItem *horizontalSpacer_17;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpinBox *num_spinBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancle_pushButton;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *sku_lineEdit;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *left_lineEdit;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *SellWidget)
    {
        if (SellWidget->objectName().isEmpty())
            SellWidget->setObjectName(QStringLiteral("SellWidget"));
        SellWidget->resize(1024, 566);
        SellWidget->setMinimumSize(QSize(0, 0));
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/sell.png")));
        SellWidget->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(SellWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_15 = new QLabel(SellWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_15);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        vip_groupBox = new QGroupBox(SellWidget);
        vip_groupBox->setObjectName(QStringLiteral("vip_groupBox"));
        vip_groupBox->setMinimumSize(QSize(1000, 250));
        vip_groupBox->setMaximumSize(QSize(1000, 250));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        vip_groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(vip_groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label = new QLabel(vip_groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_10->addWidget(label);

        tel_lineEdit = new QLineEdit(vip_groupBox);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        horizontalLayout_10->addWidget(tel_lineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_10);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_2 = new QLabel(vip_groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_9->addWidget(label_2);

        vip_lineEdit = new QLineEdit(vip_groupBox);
        vip_lineEdit->setObjectName(QStringLiteral("vip_lineEdit"));

        horizontalLayout_9->addWidget(vip_lineEdit);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);

        search_pushButton = new QPushButton(vip_groupBox);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));

        horizontalLayout_11->addWidget(search_pushButton);

        horizontalLayout_11->setStretch(0, 5);
        horizontalLayout_11->setStretch(1, 3);
        horizontalLayout_11->setStretch(2, 5);
        horizontalLayout_11->setStretch(3, 6);

        verticalLayout->addLayout(horizontalLayout_11);

        line = new QFrame(vip_groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_13 = new QLabel(vip_groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 4, 1, 1);

        label_11 = new QLabel(vip_groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 1, 1, 1);

        scoreInfo_lineEdit = new QLineEdit(vip_groupBox);
        scoreInfo_lineEdit->setObjectName(QStringLiteral("scoreInfo_lineEdit"));

        gridLayout->addWidget(scoreInfo_lineEdit, 1, 5, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 2, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 3, 1, 1);

        telInfo_lineEdit = new QLineEdit(vip_groupBox);
        telInfo_lineEdit->setObjectName(QStringLiteral("telInfo_lineEdit"));

        gridLayout->addWidget(telInfo_lineEdit, 1, 2, 1, 1);

        label_14 = new QLabel(vip_groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 1, 1, 1);

        vipInfo_lineEdit = new QLineEdit(vip_groupBox);
        vipInfo_lineEdit->setObjectName(QStringLiteral("vipInfo_lineEdit"));

        gridLayout->addWidget(vipInfo_lineEdit, 2, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 0, 6, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 0, 1, 1);

        label_12 = new QLabel(vip_groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 0, 4, 1, 1);

        nameInfo_lineEdit = new QLineEdit(vip_groupBox);
        nameInfo_lineEdit->setObjectName(QStringLiteral("nameInfo_lineEdit"));

        gridLayout->addWidget(nameInfo_lineEdit, 0, 2, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 3, 1, 1);

        purchaseInfo_lineEdit = new QLineEdit(vip_groupBox);
        purchaseInfo_lineEdit->setObjectName(QStringLiteral("purchaseInfo_lineEdit"));

        gridLayout->addWidget(purchaseInfo_lineEdit, 0, 5, 1, 1);

        label_10 = new QLabel(vip_groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        label_3 = new QLabel(vip_groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_8->addWidget(label_3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_3->addWidget(vip_groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        product_groupBox = new QGroupBox(SellWidget);
        product_groupBox->setObjectName(QStringLiteral("product_groupBox"));
        product_groupBox->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(product_groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(product_groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);

        type_comboBox = new QComboBox(product_groupBox);
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName(QStringLiteral("type_comboBox"));
        type_comboBox->setMinimumSize(QSize(100, 0));
        type_comboBox->setFont(font1);

        horizontalLayout->addWidget(type_comboBox);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);

        label_5 = new QLabel(product_groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_2->addWidget(label_5);

        sku_comboBox = new QComboBox(product_groupBox);
        sku_comboBox->setObjectName(QStringLiteral("sku_comboBox"));
        sku_comboBox->setMinimumSize(QSize(280, 0));
        sku_comboBox->setFont(font1);

        horizontalLayout_2->addWidget(sku_comboBox);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_18);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(product_groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_3->addWidget(label_6);

        price_doubleSpinBox = new QDoubleSpinBox(product_groupBox);
        price_doubleSpinBox->setObjectName(QStringLiteral("price_doubleSpinBox"));
        price_doubleSpinBox->setMaximum(10000);
        price_doubleSpinBox->setValue(0);

        horizontalLayout_3->addWidget(price_doubleSpinBox);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_17);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(product_groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        horizontalLayout_4->addWidget(label_7);

        num_spinBox = new QSpinBox(product_groupBox);
        num_spinBox->setObjectName(QStringLiteral("num_spinBox"));
        num_spinBox->setMinimum(0);
        num_spinBox->setValue(0);

        horizontalLayout_4->addWidget(num_spinBox);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        ok_pushButton = new QPushButton(product_groupBox);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));
        ok_pushButton->setFont(font1);

        horizontalLayout_5->addWidget(ok_pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        cancle_pushButton = new QPushButton(product_groupBox);
        cancle_pushButton->setObjectName(QStringLiteral("cancle_pushButton"));
        cancle_pushButton->setFont(font1);

        horizontalLayout_5->addWidget(cancle_pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_7);

        line_2 = new QFrame(product_groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 35, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_8 = new QLabel(product_groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout_12->addWidget(label_8);

        sku_lineEdit = new QLineEdit(product_groupBox);
        sku_lineEdit->setObjectName(QStringLiteral("sku_lineEdit"));
        sku_lineEdit->setFont(font1);

        horizontalLayout_12->addWidget(sku_lineEdit);


        horizontalLayout_14->addLayout(horizontalLayout_12);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(product_groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        horizontalLayout_13->addWidget(label_9);

        left_lineEdit = new QLineEdit(product_groupBox);
        left_lineEdit->setObjectName(QStringLiteral("left_lineEdit"));
        left_lineEdit->setFont(font1);

        horizontalLayout_13->addWidget(left_lineEdit);


        horizontalLayout_14->addLayout(horizontalLayout_13);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_16);


        verticalLayout_2->addLayout(horizontalLayout_14);


        verticalLayout_3->addWidget(product_groupBox);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 64, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        verticalLayout_4->setStretch(1, 7);
        verticalLayout_4->setStretch(2, 1);

        retranslateUi(SellWidget);

        QMetaObject::connectSlotsByName(SellWidget);
    } // setupUi

    void retranslateUi(QDialog *SellWidget)
    {
        SellWidget->setWindowTitle(QApplication::translate("SellWidget", "\351\224\200\345\224\256", nullptr));
        label_15->setText(QApplication::translate("SellWidget", "\351\224\200       \345\224\256        \351\241\265", nullptr));
        vip_groupBox->setTitle(QApplication::translate("SellWidget", "\344\274\232\345\221\230\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("SellWidget", "\346\211\213\346\234\272", nullptr));
        tel_lineEdit->setText(QString());
        tel_lineEdit->setPlaceholderText(QApplication::translate("SellWidget", "\344\270\215\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        label_2->setText(QApplication::translate("SellWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        vip_lineEdit->setText(QString());
        vip_lineEdit->setPlaceholderText(QApplication::translate("SellWidget", "\345\217\257\350\207\252\351\246\226\344\275\215\351\235\236\351\233\266\345\274\200\345\247\213", nullptr));
        search_pushButton->setText(QApplication::translate("SellWidget", "\346\237\245\350\257\242", nullptr));
        label_13->setText(QApplication::translate("SellWidget", "\347\247\257\345\210\206", nullptr));
        label_11->setText(QApplication::translate("SellWidget", "\346\211\213\346\234\272", nullptr));
        label_14->setText(QApplication::translate("SellWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        label_12->setText(QApplication::translate("SellWidget", "\346\266\210\350\264\271\346\254\241\346\225\260", nullptr));
        label_10->setText(QApplication::translate("SellWidget", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QApplication::translate("SellWidget", "\344\277\241\346\201\257\346\240\270\345\256\236", nullptr));
        product_groupBox->setTitle(QApplication::translate("SellWidget", "\344\272\247\345\223\201", nullptr));
        label_4->setText(QApplication::translate("SellWidget", "\347\261\273\345\236\213", nullptr));
        type_comboBox->setItemText(0, QApplication::translate("SellWidget", "\351\232\220\345\275\242\347\234\274\351\225\234", nullptr));
        type_comboBox->setItemText(1, QApplication::translate("SellWidget", "\347\234\274\350\215\257\346\260\264", nullptr));
        type_comboBox->setItemText(2, QApplication::translate("SellWidget", "\346\212\244\347\220\206\346\266\262", nullptr));
        type_comboBox->setItemText(3, QApplication::translate("SellWidget", "\346\264\227\347\234\274\346\266\262", nullptr));

        label_5->setText(QApplication::translate("SellWidget", "SKU", nullptr));
        label_6->setText(QApplication::translate("SellWidget", "\345\215\225\344\273\267", nullptr));
        label_7->setText(QApplication::translate("SellWidget", "\346\225\260\351\207\217", nullptr));
        ok_pushButton->setText(QApplication::translate("SellWidget", "\347\241\256\345\256\232", nullptr));
        cancle_pushButton->setText(QApplication::translate("SellWidget", "\345\217\226\346\266\210", nullptr));
        label_8->setText(QApplication::translate("SellWidget", "SKU", nullptr));
        label_9->setText(QApplication::translate("SellWidget", "\347\216\260\346\234\211\345\272\223\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellWidget: public Ui_SellWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLWIDGET_H

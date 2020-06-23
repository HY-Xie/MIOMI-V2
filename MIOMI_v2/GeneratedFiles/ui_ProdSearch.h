/********************************************************************************
** Form generated from reading UI file 'ProdSearch.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODSEARCH_H
#define UI_PRODSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProdSearch
{
public:
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QDateEdit *from_dateEdit;
    QLabel *label;
    QDateEdit *to_dateEdit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *search_pushButton;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QTableView *glass_tableView;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *glassMoney_label;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QTableView *eyedrop_tableView;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLabel *eyedropMoney_label;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QTableView *nursing_tableView;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *nursingMoney_label;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QTableView *wash_tableView;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *washMoney_label;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *moneyLabel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_2;

    void setupUi(QDialog *ProdSearch)
    {
        if (ProdSearch->objectName().isEmpty())
            ProdSearch->setObjectName(QStringLiteral("ProdSearch"));
        ProdSearch->resize(1210, 803);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/find.png")));
        ProdSearch->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(ProdSearch);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget = new QTabWidget(ProdSearch);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        from_dateEdit = new QDateEdit(tab);
        from_dateEdit->setObjectName(QStringLiteral("from_dateEdit"));

        horizontalLayout->addWidget(from_dateEdit);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        to_dateEdit = new QDateEdit(tab);
        to_dateEdit->setObjectName(QStringLiteral("to_dateEdit"));

        horizontalLayout->addWidget(to_dateEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        search_pushButton = new QPushButton(tab);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));

        horizontalLayout->addWidget(search_pushButton);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout->addWidget(label_7);

        glass_tableView = new QTableView(tab);
        glass_tableView->setObjectName(QStringLiteral("glass_tableView"));

        verticalLayout->addWidget(glass_tableView);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        glassMoney_label = new QLabel(tab);
        glassMoney_label->setObjectName(QStringLiteral("glassMoney_label"));

        horizontalLayout_7->addWidget(glassMoney_label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        eyedrop_tableView = new QTableView(tab);
        eyedrop_tableView->setObjectName(QStringLiteral("eyedrop_tableView"));

        verticalLayout_2->addWidget(eyedrop_tableView);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        eyedropMoney_label = new QLabel(tab);
        eyedropMoney_label->setObjectName(QStringLiteral("eyedropMoney_label"));

        horizontalLayout_5->addWidget(eyedropMoney_label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        nursing_tableView = new QTableView(tab);
        nursing_tableView->setObjectName(QStringLiteral("nursing_tableView"));

        verticalLayout_3->addWidget(nursing_tableView);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        nursingMoney_label = new QLabel(tab);
        nursingMoney_label->setObjectName(QStringLiteral("nursingMoney_label"));

        horizontalLayout_4->addWidget(nursingMoney_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        wash_tableView = new QTableView(tab);
        wash_tableView->setObjectName(QStringLiteral("wash_tableView"));

        verticalLayout_4->addWidget(wash_tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        washMoney_label = new QLabel(tab);
        washMoney_label->setObjectName(QStringLiteral("washMoney_label"));

        horizontalLayout_6->addWidget(washMoney_label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        moneyLabel = new QLabel(tab);
        moneyLabel->setObjectName(QStringLiteral("moneyLabel"));

        horizontalLayout_2->addWidget(moneyLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_3->addWidget(tabWidget);


        retranslateUi(ProdSearch);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ProdSearch);
    } // setupUi

    void retranslateUi(QDialog *ProdSearch)
    {
        ProdSearch->setWindowTitle(QApplication::translate("ProdSearch", "\346\261\207\346\200\273\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("ProdSearch", "\345\210\260", nullptr));
        search_pushButton->setText(QApplication::translate("ProdSearch", "\346\237\245\350\257\242", nullptr));
        label_7->setText(QApplication::translate("ProdSearch", "\351\232\220\345\275\242\347\234\274\351\225\234", nullptr));
        label_6->setText(QApplication::translate("ProdSearch", "\351\207\221\351\242\235:", nullptr));
        glassMoney_label->setText(QString());
        label_8->setText(QApplication::translate("ProdSearch", "\347\234\274\350\215\257\346\260\264", nullptr));
        label_4->setText(QApplication::translate("ProdSearch", "\351\207\221\351\242\235:", nullptr));
        eyedropMoney_label->setText(QString());
        label_9->setText(QApplication::translate("ProdSearch", "\346\212\244\347\220\206\346\266\262", nullptr));
        label_3->setText(QApplication::translate("ProdSearch", "\351\207\221\351\242\235:", nullptr));
        nursingMoney_label->setText(QString());
        label_10->setText(QApplication::translate("ProdSearch", "\346\264\227\347\234\274\346\266\262", nullptr));
        label_5->setText(QApplication::translate("ProdSearch", "\351\207\221\351\242\235:", nullptr));
        washMoney_label->setText(QString());
        label_2->setText(QApplication::translate("ProdSearch", "\346\200\273\351\207\221\351\242\235:", nullptr));
        moneyLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ProdSearch", "\346\227\245\346\234\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ProdSearch", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProdSearch: public Ui_ProdSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODSEARCH_H

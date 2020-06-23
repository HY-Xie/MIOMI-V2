/********************************************************************************
** Form generated from reading UI file 'PersonalConsumptionDetailWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALCONSUMPTIONDETAILWIDGET_H
#define UI_PERSONALCONSUMPTIONDETAILWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PersonalConsumptionDetailWidget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *vip_lineEdit;
    QLabel *label_3;
    QLineEdit *tel_lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *search_pushButton;
    QTableView *tableView;
    QLabel *moneylabel;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableView *tableView2;

    void setupUi(QDialog *PersonalConsumptionDetailWidget)
    {
        if (PersonalConsumptionDetailWidget->objectName().isEmpty())
            PersonalConsumptionDetailWidget->setObjectName(QStringLiteral("PersonalConsumptionDetailWidget"));
        PersonalConsumptionDetailWidget->resize(1117, 735);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/member_record.png")));
        PersonalConsumptionDetailWidget->setWindowIcon(icon);
        horizontalLayout_4 = new QHBoxLayout(PersonalConsumptionDetailWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(PersonalConsumptionDetailWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        vip_lineEdit = new QLineEdit(PersonalConsumptionDetailWidget);
        vip_lineEdit->setObjectName(QStringLiteral("vip_lineEdit"));
        vip_lineEdit->setFont(font);

        horizontalLayout->addWidget(vip_lineEdit);


        horizontalLayout_2->addLayout(horizontalLayout);

        label_3 = new QLabel(PersonalConsumptionDetailWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        tel_lineEdit = new QLineEdit(PersonalConsumptionDetailWidget);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));
        tel_lineEdit->setFont(font);

        horizontalLayout_2->addWidget(tel_lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        search_pushButton = new QPushButton(PersonalConsumptionDetailWidget);
        search_pushButton->setObjectName(QStringLiteral("search_pushButton"));
        search_pushButton->setFont(font);

        horizontalLayout_2->addWidget(search_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(PersonalConsumptionDetailWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        moneylabel = new QLabel(PersonalConsumptionDetailWidget);
        moneylabel->setObjectName(QStringLiteral("moneylabel"));
        moneylabel->setFont(font);

        verticalLayout->addWidget(moneylabel);


        horizontalLayout_3->addLayout(verticalLayout);

        line = new QFrame(PersonalConsumptionDetailWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(PersonalConsumptionDetailWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        tableView2 = new QTableView(PersonalConsumptionDetailWidget);
        tableView2->setObjectName(QStringLiteral("tableView2"));

        verticalLayout_2->addWidget(tableView2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 8);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 4);

        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(PersonalConsumptionDetailWidget);

        QMetaObject::connectSlotsByName(PersonalConsumptionDetailWidget);
    } // setupUi

    void retranslateUi(QDialog *PersonalConsumptionDetailWidget)
    {
        PersonalConsumptionDetailWidget->setWindowTitle(QApplication::translate("PersonalConsumptionDetailWidget", "\344\270\252\344\272\272\346\266\210\350\264\271\350\257\246\346\203\205", nullptr));
        label->setText(QApplication::translate("PersonalConsumptionDetailWidget", "\344\274\232\345\221\230\345\217\267", nullptr));
        vip_lineEdit->setPlaceholderText(QApplication::translate("PersonalConsumptionDetailWidget", "\350\207\252\351\235\236\351\233\266\351\246\226\344\275\215\350\276\223\345\205\245", nullptr));
        label_3->setText(QApplication::translate("PersonalConsumptionDetailWidget", "\346\211\213\346\234\272", nullptr));
        tel_lineEdit->setPlaceholderText(QApplication::translate("PersonalConsumptionDetailWidget", "\344\270\215\346\224\257\346\214\201\346\250\241\347\263\212\346\237\245\350\257\242", nullptr));
        search_pushButton->setText(QApplication::translate("PersonalConsumptionDetailWidget", "\346\220\234\347\264\242", nullptr));
        moneylabel->setText(QApplication::translate("PersonalConsumptionDetailWidget", "TextLabel", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PersonalConsumptionDetailWidget: public Ui_PersonalConsumptionDetailWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALCONSUMPTIONDETAILWIDGET_H

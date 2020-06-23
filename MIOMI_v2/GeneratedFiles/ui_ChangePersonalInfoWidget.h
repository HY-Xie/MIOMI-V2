/********************************************************************************
** Form generated from reading UI file 'ChangePersonalInfoWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPERSONALINFOWIDGET_H
#define UI_CHANGEPERSONALINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePersonalInfoWidget
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *old_password_lineEdit;
    QLineEdit *new_password_lineEdit;
    QLineEdit *re_new_password_lineEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *note_textEdit;
    QFrame *line;
    QLabel *label_4;
    QFrame *line_2;
    QPushButton *save_pushButton;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QToolButton *photo_toolButton;
    QLabel *photo_label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_25;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *id_lineEdit;
    QLineEdit *tel_lineEdit;
    QLineEdit *addr_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_22;
    QLabel *label_30;
    QVBoxLayout *verticalLayout;
    QLineEdit *name_lineEdit;
    QLineEdit *weChat_lineEdit;
    QLineEdit *email_lineEdit;

    void setupUi(QDialog *ChangePersonalInfoWidget)
    {
        if (ChangePersonalInfoWidget->objectName().isEmpty())
            ChangePersonalInfoWidget->setObjectName(QStringLiteral("ChangePersonalInfoWidget"));
        ChangePersonalInfoWidget->resize(997, 437);
        QIcon icon(QIcon::fromTheme(QStringLiteral(":/MainWindow/Resources/peronal_setting.png")));
        ChangePersonalInfoWidget->setWindowIcon(icon);
        groupBox = new QGroupBox(ChangePersonalInfoWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(80, 230, 351, 161));
        groupBox->setMinimumSize(QSize(100, 160));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(12);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font);

        verticalLayout_6->addWidget(label_27);

        label_28 = new QLabel(groupBox);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);

        verticalLayout_6->addWidget(label_28);

        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font);

        verticalLayout_6->addWidget(label_29);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        old_password_lineEdit = new QLineEdit(groupBox);
        old_password_lineEdit->setObjectName(QStringLiteral("old_password_lineEdit"));
        old_password_lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(old_password_lineEdit);

        new_password_lineEdit = new QLineEdit(groupBox);
        new_password_lineEdit->setObjectName(QStringLiteral("new_password_lineEdit"));
        new_password_lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(new_password_lineEdit);

        re_new_password_lineEdit = new QLineEdit(groupBox);
        re_new_password_lineEdit->setObjectName(QStringLiteral("re_new_password_lineEdit"));
        re_new_password_lineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_5->addWidget(re_new_password_lineEdit);


        horizontalLayout_2->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ChangePersonalInfoWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 230, 281, 160));
        groupBox_2->setMinimumSize(QSize(100, 160));
        groupBox_2->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        note_textEdit = new QTextEdit(groupBox_2);
        note_textEdit->setObjectName(QStringLiteral("note_textEdit"));

        horizontalLayout_3->addWidget(note_textEdit);

        line = new QFrame(ChangePersonalInfoWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 400, 909, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_4 = new QLabel(ChangePersonalInfoWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 12, 198, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(20);
        label_4->setFont(font1);
        line_2 = new QFrame(ChangePersonalInfoWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(60, 54, 911, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        save_pushButton = new QPushButton(ChangePersonalInfoWidget);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));
        save_pushButton->setGeometry(QRect(770, 340, 93, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(11);
        save_pushButton->setFont(font2);
        layoutWidget = new QWidget(ChangePersonalInfoWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(741, 77, 152, 231));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        photo_toolButton = new QToolButton(layoutWidget);
        photo_toolButton->setObjectName(QStringLiteral("photo_toolButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(photo_toolButton->sizePolicy().hasHeightForWidth());
        photo_toolButton->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::FieldRole, photo_toolButton);

        photo_label = new QLabel(layoutWidget);
        photo_label->setObjectName(QStringLiteral("photo_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(60);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(photo_label->sizePolicy().hasHeightForWidth());
        photo_label->setSizePolicy(sizePolicy1);
        photo_label->setMinimumSize(QSize(150, 200));
        photo_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, photo_label);

        layoutWidget1 = new QWidget(ChangePersonalInfoWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(94, 80, 631, 141));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);

        verticalLayout_4->addWidget(label_25);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font);

        verticalLayout_4->addWidget(label_26);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        id_lineEdit = new QLineEdit(layoutWidget1);
        id_lineEdit->setObjectName(QStringLiteral("id_lineEdit"));

        verticalLayout_3->addWidget(id_lineEdit);

        tel_lineEdit = new QLineEdit(layoutWidget1);
        tel_lineEdit->setObjectName(QStringLiteral("tel_lineEdit"));

        verticalLayout_3->addWidget(tel_lineEdit);

        addr_lineEdit = new QLineEdit(layoutWidget1);
        addr_lineEdit->setObjectName(QStringLiteral("addr_lineEdit"));

        verticalLayout_3->addWidget(addr_lineEdit);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);

        verticalLayout_2->addWidget(label_22);

        label_30 = new QLabel(layoutWidget1);
        label_30->setObjectName(QStringLiteral("label_30"));
        QFont font3;
        font3.setFamily(QStringLiteral("Viner Hand ITC"));
        font3.setPointSize(12);
        label_30->setFont(font3);

        verticalLayout_2->addWidget(label_30);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_lineEdit = new QLineEdit(layoutWidget1);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        verticalLayout->addWidget(name_lineEdit);

        weChat_lineEdit = new QLineEdit(layoutWidget1);
        weChat_lineEdit->setObjectName(QStringLiteral("weChat_lineEdit"));

        verticalLayout->addWidget(weChat_lineEdit);

        email_lineEdit = new QLineEdit(layoutWidget1);
        email_lineEdit->setObjectName(QStringLiteral("email_lineEdit"));

        verticalLayout->addWidget(email_lineEdit);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(ChangePersonalInfoWidget);

        QMetaObject::connectSlotsByName(ChangePersonalInfoWidget);
    } // setupUi

    void retranslateUi(QDialog *ChangePersonalInfoWidget)
    {
        ChangePersonalInfoWidget->setWindowTitle(QApplication::translate("ChangePersonalInfoWidget", "\344\270\252\344\272\272\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        groupBox->setTitle(QApplication::translate("ChangePersonalInfoWidget", "\345\257\206\347\240\201", nullptr));
        label_27->setText(QApplication::translate("ChangePersonalInfoWidget", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_28->setText(QApplication::translate("ChangePersonalInfoWidget", "\346\226\260\345\257\206\347\240\201", nullptr));
        label_29->setText(QApplication::translate("ChangePersonalInfoWidget", "\351\207\215\346\226\260\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        groupBox_2->setTitle(QApplication::translate("ChangePersonalInfoWidget", "\345\244\207\346\263\250", nullptr));
        label_4->setText(QApplication::translate("ChangePersonalInfoWidget", "\344\270\252\344\272\272\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        save_pushButton->setText(QApplication::translate("ChangePersonalInfoWidget", "\344\277\235\345\255\230", nullptr));
        label->setText(QString());
        photo_toolButton->setText(QApplication::translate("ChangePersonalInfoWidget", "\351\200\211\346\213\251...", nullptr));
        photo_label->setText(QApplication::translate("ChangePersonalInfoWidget", "\347\205\247\347\211\207", nullptr));
        label_3->setText(QApplication::translate("ChangePersonalInfoWidget", "\345\221\230\345\267\245\345\217\267", nullptr));
        label_25->setText(QApplication::translate("ChangePersonalInfoWidget", "\346\211\213\346\234\272", nullptr));
        label_26->setText(QApplication::translate("ChangePersonalInfoWidget", "\345\234\260\345\235\200", nullptr));
        label_2->setText(QApplication::translate("ChangePersonalInfoWidget", "\345\247\223\345\220\215", nullptr));
        label_22->setText(QApplication::translate("ChangePersonalInfoWidget", "\345\276\256\344\277\241", nullptr));
        label_30->setText(QApplication::translate("ChangePersonalInfoWidget", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePersonalInfoWidget: public Ui_ChangePersonalInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPERSONALINFOWIDGET_H

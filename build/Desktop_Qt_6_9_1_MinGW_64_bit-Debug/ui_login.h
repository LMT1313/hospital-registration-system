/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_login;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_role;
    QPushButton *pushButton_login;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(717, 464);
        login->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 731, 471));
        widget->setStyleSheet(QString::fromUtf8("#widget{border-image: url(:/image/bg.png);}"));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(540, 60, 76, 49));
        QFont font;
        font.setPointSize(23);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(450, 160, 239, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEdit_login = new QLineEdit(layoutWidget);
        lineEdit_login->setObjectName("lineEdit_login");
        lineEdit_login->setMinimumSize(QSize(200, 25));
        lineEdit_login->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(lineEdit_login);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(450, 220, 239, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        lineEdit_password = new QLineEdit(layoutWidget1);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setMinimumSize(QSize(200, 25));
        lineEdit_password->setMaximumSize(QSize(16777215, 25));
        lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(lineEdit_password);

        layoutWidget2 = new QWidget(widget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(430, 310, 273, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBox_role = new QComboBox(layoutWidget2);
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->setObjectName("comboBox_role");

        horizontalLayout_3->addWidget(comboBox_role);

        pushButton_login = new QPushButton(layoutWidget2);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setMinimumSize(QSize(3, 0));

        horizontalLayout_3->addWidget(pushButton_login);

        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_3->addWidget(pushButton_2);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 430, 191, 20));
        layoutWidget2->raise();
        layoutWidget2->raise();
        layoutWidget2->raise();
        label->raise();
        label_4->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("login", "\350\264\246\345\217\267", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_login->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit_login->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("login", "\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_password->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        comboBox_role->setItemText(0, QCoreApplication::translate("login", "\346\202\243\350\200\205", nullptr));
        comboBox_role->setItemText(1, QCoreApplication::translate("login", "\345\214\273\347\224\237", nullptr));
        comboBox_role->setItemText(2, QCoreApplication::translate("login", "\346\212\244\345\243\253", nullptr));
        comboBox_role->setItemText(3, QCoreApplication::translate("login", "\347\256\241\347\220\206\345\221\230", nullptr));

        comboBox_role->setCurrentText(QString());
        comboBox_role->setPlaceholderText(QCoreApplication::translate("login", "\347\224\250\346\210\267", nullptr));
        pushButton_login->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        label_4->setText(QCoreApplication::translate("login", "\345\277\230\350\256\260\345\257\206\347\240\201\350\257\267\350\201\224\347\263\273\347\256\241\347\220\206\345\221\230\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

/********************************************************************************
** Form generated from reading UI file 'nurse.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NURSE_H
#define UI_NURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nurse
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_welcome;
    QPushButton *pushButton_return;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget_nur;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *tableWidget_0;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_1;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QTextEdit *textEdit_1;
    QSpacerItem *verticalSpacer;
    QWidget *page_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2_num;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2_sub;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_4;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_5_old;
    QLineEdit *lineEdit_5_new;
    QLabel *label_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;

    void setupUi(QWidget *nurse)
    {
        if (nurse->objectName().isEmpty())
            nurse->setObjectName("nurse");
        nurse->resize(837, 521);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nurse->sizePolicy().hasHeightForWidth());
        nurse->setSizePolicy(sizePolicy);
        nurse->setStyleSheet(QString::fromUtf8("background-image: url(:/image/wel.png);"));
        verticalLayout_3 = new QVBoxLayout(nurse);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_welcome = new QLabel(nurse);
        label_welcome->setObjectName("label_welcome");

        horizontalLayout_3->addWidget(label_welcome);

        pushButton_return = new QPushButton(nurse);
        pushButton_return->setObjectName("pushButton_return");

        horizontalLayout_3->addWidget(pushButton_return);

        horizontalLayout_3->setStretch(0, 10);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        listWidget = new QListWidget(nurse);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(115, 0));
        listWidget->setMaximumSize(QSize(115, 16777215));
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: rgb(212, 236, 243);\n"
"    outline: none; /* \345\205\263\351\224\256\357\274\232\347\247\273\351\231\244\350\231\232\347\272\277\346\241\206 */\n"
"    border: 1px solid #ccc;\n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\347\232\204\351\241\271\357\274\210\345\214\205\346\213\254\346\234\211\347\204\246\347\202\271\345\222\214\346\262\241\347\204\246\347\202\271\347\232\204\346\203\205\345\206\265\357\274\211 */\n"
"QListWidget::item:selected, \n"
"QListWidget::item:selected:active, \n"
"QListWidget::item:selected:!active {\n"
"    background-color: #000000;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\344\275\206\346\234\252\351\200\211\344\270\255\357\274\210\345\217\257\351\200\211\357\274\214\345\242\236\345\212\240\344\272\244\344\272\222\346\204\237\357\274\211 */\n"
"QListWidget::item:hover {\n"
"    background-color: rgba(0, 0, 0, 20); /* \346\267\241\346\267\241\347\232\204\347\201\260\350\211\262"
                        " */\n"
"}"));

        horizontalLayout_4->addWidget(listWidget);

        stackedWidget_nur = new QStackedWidget(nurse);
        stackedWidget_nur->setObjectName("stackedWidget_nur");
        stackedWidget_nur->setStyleSheet(QString::fromUtf8("QPushButton, QLineEdit, QComboBox, QListWidget, QTextEdit,QDateEdit {\n"
"    border: 1px solid black;\n"
"}\n"
"QHeaderView::section {\n"
"    border-bottom: 1px solid black;  /* \345\205\263\351\224\256\357\274\232\345\274\272\345\210\266\346\230\276\347\244\272\345\272\225\351\203\250\351\273\221\347\272\277 */\n"
"    border-right: 1px solid #dddddd; /* \345\217\257\351\200\211\357\274\232\347\273\231\345\210\227\344\271\213\351\227\264\344\271\237\345\212\240\346\235\241\347\273\206\347\272\277 */\n"
"    background-color: #f0f0f0;       /* \345\217\257\351\200\211\357\274\232\347\273\231\350\241\250\345\244\264\345\212\240\344\270\252\347\201\260\350\211\262\350\203\214\346\231\257\357\274\214\345\214\272\345\210\206\346\233\264\346\230\216\346\230\276 */\n"
"    padding: 4px;                    /* \345\217\257\351\200\211\357\274\232\345\242\236\345\212\240\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235\357\274\214\350\256\251\346\226\207\345\255\227\344\270\215\350\264\264\350\276\271 */\n"
""
                        "}\n"
"QTableWidget {\n"
"    border: 1px solid black;       /* \350\241\250\346\240\274\346\225\264\344\275\223\347\232\204\345\244\226\350\276\271\346\241\206 */\n"
"    gridline-color: black;         /* \345\206\205\351\203\250\345\215\225\345\205\203\346\240\274\347\272\277\346\235\241\351\242\234\350\211\262 */\n"
"}"));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName("verticalLayout_4");
        tableWidget_0 = new QTableWidget(page);
        tableWidget_0->setObjectName("tableWidget_0");

        verticalLayout_4->addWidget(tableWidget_0);

        stackedWidget_nur->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(page_2);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_1 = new QLineEdit(page_2);
        lineEdit_1->setObjectName("lineEdit_1");

        horizontalLayout->addWidget(lineEdit_1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_save = new QPushButton(page_2);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout->addWidget(pushButton_save);

        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        textEdit_1 = new QTextEdit(page_2);
        textEdit_1->setObjectName("textEdit_1");

        verticalLayout_5->addWidget(textEdit_1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        stackedWidget_nur->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout = new QVBoxLayout(page_3);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(100, -1, 170, -1);
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2_num = new QLineEdit(page_3);
        lineEdit_2_num->setObjectName("lineEdit_2_num");

        gridLayout->addWidget(lineEdit_2_num, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(page_3);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 10, 170, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_2_sub = new QPushButton(page_3);
        pushButton_2_sub->setObjectName("pushButton_2_sub");

        horizontalLayout_2->addWidget(pushButton_2_sub);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        stackedWidget_nur->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_nur->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_2 = new QVBoxLayout(page_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(1);
        gridLayout_2->setContentsMargins(120, 50, 200, -1);
        lineEdit_5_old = new QLineEdit(page_5);
        lineEdit_5_old->setObjectName("lineEdit_5_old");

        gridLayout_2->addWidget(lineEdit_5_old, 0, 1, 1, 1);

        lineEdit_5_new = new QLineEdit(page_5);
        lineEdit_5_new->setObjectName("lineEdit_5_new");

        gridLayout_2->addWidget(lineEdit_5_new, 1, 1, 1, 1);

        label_4 = new QLabel(page_5);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_7 = new QLabel(page_5);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(190, -1, 250, 100);
        pushButton_5 = new QPushButton(page_5);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_5->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_5);

        stackedWidget_nur->addWidget(page_5);

        horizontalLayout_4->addWidget(stackedWidget_nur);

        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(nurse);

        stackedWidget_nur->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(nurse);
    } // setupUi

    void retranslateUi(QWidget *nurse)
    {
        nurse->setWindowTitle(QCoreApplication::translate("nurse", "Form", nullptr));
        label_welcome->setText(QCoreApplication::translate("nurse", "\346\254\242\350\277\216\346\202\250", nullptr));
        pushButton_return->setText(QCoreApplication::translate("nurse", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("nurse", "\346\237\245\347\234\213\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("nurse", "\345\215\217\345\212\251\350\257\212\347\226\227", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("nurse", "\347\274\264\350\264\271\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("nurse", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QCoreApplication::translate("nurse", "\351\242\204\347\272\246\347\274\226\345\217\267", nullptr));
        pushButton_save->setText(QCoreApplication::translate("nurse", "\346\217\220\344\272\244", nullptr));
        label_3->setText(QCoreApplication::translate("nurse", "\347\274\264\350\264\271\346\226\271\345\274\217", nullptr));
        label_2->setText(QCoreApplication::translate("nurse", "\351\242\204\347\272\246\347\274\226\345\217\267", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("nurse", "\345\276\256\344\277\241", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("nurse", "\346\224\257\344\273\230\345\256\235", nullptr));

        pushButton_2_sub->setText(QCoreApplication::translate("nurse", "\346\217\220\344\272\244", nullptr));
        label_4->setText(QCoreApplication::translate("nurse", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("nurse", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_5->setText(QCoreApplication::translate("nurse", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class nurse: public Ui_nurse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NURSE_H

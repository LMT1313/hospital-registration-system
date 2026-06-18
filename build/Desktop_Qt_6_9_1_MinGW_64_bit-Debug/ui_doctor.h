/********************************************************************************
** Form generated from reading UI file 'doctor.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTOR_H
#define UI_DOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_doctor
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_id;
    QPushButton *pushButton_return;
    QWidget *bigwidgt;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QSpinBox *spinBox_0_amount;
    QLabel *label_2;
    QDateEdit *dateEdit_0_d;
    QLabel *label_3;
    QComboBox *comboBox_0_t;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_0_fabu;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *checkBox_2;
    QTableWidget *tableWidget_1;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_2_number;
    QTextEdit *lineEdit_2_res;
    QTextEdit *lineEdit_2_beizhu;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_2_save;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QLineEdit *lineEdit_3;
    QTextEdit *textEdit_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3_look;
    QPushButton *pushButton_3_mod;
    QPushButton *pushButton_3_add;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableWidget_haomesg;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_4_stop;
    QWidget *page_6;
    QWidget *page_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_7_qur;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7_add;
    QPushButton *pushButton_7_del;
    QTableWidget *tableWidget_7;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_7_sub;
    QWidget *page_8;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_5_old_2;
    QLineEdit *lineEdit_5_new_2;
    QLabel *label_10;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_6;

    void setupUi(QWidget *doctor)
    {
        if (doctor->objectName().isEmpty())
            doctor->setObjectName("doctor");
        doctor->resize(944, 517);
        doctor->setStyleSheet(QString::fromUtf8("background-image: url(:/image/wel.png);"));
        verticalLayout_5 = new QVBoxLayout(doctor);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_id = new QLabel(doctor);
        label_id->setObjectName("label_id");

        horizontalLayout->addWidget(label_id);

        pushButton_return = new QPushButton(doctor);
        pushButton_return->setObjectName("pushButton_return");

        horizontalLayout->addWidget(pushButton_return);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);

        bigwidgt = new QWidget(doctor);
        bigwidgt->setObjectName("bigwidgt");
        bigwidgt->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(bigwidgt);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        listWidget = new QListWidget(bigwidgt);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
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

        stackedWidget = new QStackedWidget(bigwidgt);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"QPushButton, QLineEdit, QComboBox, QListWidget, QTextEdit, QDateEdit {\n"
"    border: 1px solid black;\n"
"}\n"
"QHeaderView::section {\n"
"    border-bottom: 1px solid black;  /* \345\205\263\351\224\256\357\274\232\345\274\272\345\210\266\346\230\276\347\244\272\345\272\225\351\203\250\351\273\221\347\272\277 */\n"
"    border-right: 1px solid #dddddd; /* \345\217\257\351\200\211\357\274\232\347\273\231\345\210\227\344\271\213\351\227\264\344\271\237\345\212\240\346\235\241\347\273\206\347\272\277 */\n"
"    background-color: #f0f0f0;       /* \345\217\257\351\200\211\357\274\232\347\273\231\350\241\250\345\244\264\345\212\240\344\270\252\347\201\260\350\211\262\350\203\214\346\231\257\357\274\214\345\214\272\345\210\206\346\233\264\346\230\216\346\230\276 */\n"
"    padding: 4px;                    /* \345\217\257\351\200\211\357\274\232\345\242\236\345\212\240\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235\357\274\214\350\256\251\346\226\207\345\255\227\344\270\215\350\264\264\350\276\271"
                        " */\n"
"}\n"
"QTableWidget {\n"
"    border: 1px solid black;       /* \350\241\250\346\240\274\346\225\264\344\275\223\347\232\204\345\244\226\350\276\271\346\241\206 */\n"
"    gridline-color: black;         /* \345\206\205\351\203\250\345\215\225\345\205\203\346\240\274\347\272\277\346\235\241\351\242\234\350\211\262 */\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_6 = new QVBoxLayout(page);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 0, 10, -1);
        gridWidget = new QWidget(page);
        gridWidget->setObjectName("gridWidget");
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(220, -1, 190, -1);
        label_4 = new QLabel(gridWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        spinBox_0_amount = new QSpinBox(gridWidget);
        spinBox_0_amount->setObjectName("spinBox_0_amount");
        spinBox_0_amount->setMinimum(5);
        spinBox_0_amount->setMaximum(20);

        gridLayout->addWidget(spinBox_0_amount, 2, 1, 1, 1);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        dateEdit_0_d = new QDateEdit(gridWidget);
        dateEdit_0_d->setObjectName("dateEdit_0_d");

        gridLayout->addWidget(dateEdit_0_d, 0, 1, 1, 1);

        label_3 = new QLabel(gridWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        comboBox_0_t = new QComboBox(gridWidget);
        comboBox_0_t->addItem(QString());
        comboBox_0_t->addItem(QString());
        comboBox_0_t->setObjectName("comboBox_0_t");

        gridLayout->addWidget(comboBox_0_t, 1, 1, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 6);

        horizontalLayout_5->addWidget(gridWidget);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(250, 0, 250, 150);
        pushButton_0_fabu = new QPushButton(page);
        pushButton_0_fabu->setObjectName("pushButton_0_fabu");

        horizontalLayout_6->addWidget(pushButton_0_fabu);


        verticalLayout_6->addLayout(horizontalLayout_6);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_7 = new QVBoxLayout(page_2);
        verticalLayout_7->setObjectName("verticalLayout_7");
        checkBox_2 = new QCheckBox(page_2);
        checkBox_2->setObjectName("checkBox_2");

        verticalLayout_7->addWidget(checkBox_2);

        tableWidget_1 = new QTableWidget(page_2);
        tableWidget_1->setObjectName("tableWidget_1");

        verticalLayout_7->addWidget(tableWidget_1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_8 = new QVBoxLayout(page_3);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(70, 20, 130, -1);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, -1, 0, 0);
        label = new QLabel(page_3);
        label->setObjectName("label");

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");

        gridLayout_5->addWidget(label_8, 2, 0, 1, 1);

        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");

        gridLayout_5->addWidget(label_7, 1, 0, 1, 1);

        lineEdit_2_number = new QLineEdit(page_3);
        lineEdit_2_number->setObjectName("lineEdit_2_number");

        gridLayout_5->addWidget(lineEdit_2_number, 0, 1, 1, 1);

        lineEdit_2_res = new QTextEdit(page_3);
        lineEdit_2_res->setObjectName("lineEdit_2_res");

        gridLayout_5->addWidget(lineEdit_2_res, 1, 1, 1, 1);

        lineEdit_2_beizhu = new QTextEdit(page_3);
        lineEdit_2_beizhu->setObjectName("lineEdit_2_beizhu");

        gridLayout_5->addWidget(lineEdit_2_beizhu, 2, 1, 1, 1);

        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 3);

        horizontalLayout_7->addLayout(gridLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(300, 30, 300, 100);
        pushButton_2_save = new QPushButton(page_3);
        pushButton_2_save->setObjectName("pushButton_2_save");

        horizontalLayout_8->addWidget(pushButton_2_save);


        verticalLayout_8->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        horizontalLayout_9 = new QHBoxLayout(page_4);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, -1, 270, -1);
        label_11 = new QLabel(page_4);
        label_11->setObjectName("label_11");

        horizontalLayout_2->addWidget(label_11);

        lineEdit_3 = new QLineEdit(page_4);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_2->addWidget(lineEdit_3);


        verticalLayout_9->addLayout(horizontalLayout_2);

        textEdit_3 = new QTextEdit(page_4);
        textEdit_3->setObjectName("textEdit_3");

        verticalLayout_9->addWidget(textEdit_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(70, 10, 70, -1);
        pushButton_3_look = new QPushButton(page_4);
        pushButton_3_look->setObjectName("pushButton_3_look");

        horizontalLayout_3->addWidget(pushButton_3_look);

        pushButton_3_mod = new QPushButton(page_4);
        pushButton_3_mod->setObjectName("pushButton_3_mod");

        horizontalLayout_3->addWidget(pushButton_3_mod);

        pushButton_3_add = new QPushButton(page_4);
        pushButton_3_add->setObjectName("pushButton_3_add");

        horizontalLayout_3->addWidget(pushButton_3_add);


        verticalLayout_9->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_2);

        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(2, 2);
        verticalLayout_9->setStretch(3, 1);

        horizontalLayout_9->addLayout(verticalLayout_9);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_10 = new QVBoxLayout(page_5);
        verticalLayout_10->setObjectName("verticalLayout_10");
        tableWidget_haomesg = new QTableWidget(page_5);
        tableWidget_haomesg->setObjectName("tableWidget_haomesg");

        verticalLayout_10->addWidget(tableWidget_haomesg);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(550, 5, 40, -1);
        pushButton_4_stop = new QPushButton(page_5);
        pushButton_4_stop->setObjectName("pushButton_4_stop");

        horizontalLayout_10->addWidget(pushButton_4_stop);


        verticalLayout_10->addLayout(horizontalLayout_10);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        verticalLayout = new QVBoxLayout(page_7);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        horizontalLayout_11->setContentsMargins(0, -1, 0, -1);
        label_5 = new QLabel(page_7);
        label_5->setObjectName("label_5");

        horizontalLayout_11->addWidget(label_5);

        lineEdit_7 = new QLineEdit(page_7);
        lineEdit_7->setObjectName("lineEdit_7");

        horizontalLayout_11->addWidget(lineEdit_7);

        pushButton_7_qur = new QPushButton(page_7);
        pushButton_7_qur->setObjectName("pushButton_7_qur");

        horizontalLayout_11->addWidget(pushButton_7_qur);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        pushButton_7_add = new QPushButton(page_7);
        pushButton_7_add->setObjectName("pushButton_7_add");

        horizontalLayout_11->addWidget(pushButton_7_add);

        pushButton_7_del = new QPushButton(page_7);
        pushButton_7_del->setObjectName("pushButton_7_del");
        pushButton_7_del->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_11->addWidget(pushButton_7_del);

        horizontalLayout_11->setStretch(1, 3);
        horizontalLayout_11->setStretch(2, 2);
        horizontalLayout_11->setStretch(3, 4);

        verticalLayout->addLayout(horizontalLayout_11);

        tableWidget_7 = new QTableWidget(page_7);
        tableWidget_7->setObjectName("tableWidget_7");

        verticalLayout->addWidget(tableWidget_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(450, -1, 100, -1);
        pushButton_7_sub = new QPushButton(page_7);
        pushButton_7_sub->setObjectName("pushButton_7_sub");

        horizontalLayout_12->addWidget(pushButton_7_sub);

        horizontalLayout_12->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_12);

        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        verticalLayout_2 = new QVBoxLayout(page_8);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setHorizontalSpacing(7);
        gridLayout_3->setContentsMargins(120, 50, 200, -1);
        lineEdit_5_old_2 = new QLineEdit(page_8);
        lineEdit_5_old_2->setObjectName("lineEdit_5_old_2");

        gridLayout_3->addWidget(lineEdit_5_old_2, 0, 1, 1, 1);

        lineEdit_5_new_2 = new QLineEdit(page_8);
        lineEdit_5_new_2->setObjectName("lineEdit_5_new_2");

        gridLayout_3->addWidget(lineEdit_5_new_2, 1, 1, 1, 1);

        label_10 = new QLabel(page_8);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        label_12 = new QLabel(page_8);
        label_12->setObjectName("label_12");

        gridLayout_3->addWidget(label_12, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        horizontalLayout_14->setContentsMargins(190, -1, 250, 100);
        pushButton_6 = new QPushButton(page_8);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_14->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_14);

        stackedWidget->addWidget(page_8);

        horizontalLayout_4->addWidget(stackedWidget);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 6);

        verticalLayout_5->addWidget(bigwidgt);


        retranslateUi(doctor);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(doctor);
    } // setupUi

    void retranslateUi(QWidget *doctor)
    {
        doctor->setWindowTitle(QCoreApplication::translate("doctor", "Form", nullptr));
        label_id->setText(QCoreApplication::translate("doctor", "\346\254\242\350\277\216\346\202\250", nullptr));
        pushButton_return->setText(QCoreApplication::translate("doctor", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("doctor", "\346\237\245\347\234\213\345\267\262\345\217\221\345\270\203\345\217\267\346\272\220", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("doctor", "\345\217\221\345\270\203\345\217\267\346\272\220", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("doctor", "\346\237\245\347\234\213\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("doctor", "\345\206\231\347\227\205\345\216\206", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("doctor", "\345\274\200\350\215\257", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("doctor", "\345\214\273\345\230\261\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("doctor", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QCoreApplication::translate("doctor", "\345\217\257\351\242\204\347\272\246\345\217\267\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("doctor", "\345\235\220\350\257\212\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("doctor", "\345\235\220\350\257\212\346\227\266\351\227\264", nullptr));
        comboBox_0_t->setItemText(0, QCoreApplication::translate("doctor", "\344\270\212\345\215\210 8:00-12:00", nullptr));
        comboBox_0_t->setItemText(1, QCoreApplication::translate("doctor", "\344\270\213\345\215\210 14:00-18:00", nullptr));

        pushButton_0_fabu->setText(QCoreApplication::translate("doctor", "\345\217\221\345\270\203", nullptr));
        checkBox_2->setText(QCoreApplication::translate("doctor", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
        label->setText(QCoreApplication::translate("doctor", "\351\242\204\347\272\246\347\274\226\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("doctor", "\347\227\205\345\216\206\345\244\207\346\263\250", nullptr));
        label_7->setText(QCoreApplication::translate("doctor", "\350\257\212\346\226\255\347\273\223\346\236\234", nullptr));
        pushButton_2_save->setText(QCoreApplication::translate("doctor", "\344\277\235\345\255\230", nullptr));
        label_11->setText(QCoreApplication::translate("doctor", "\351\242\204\347\272\246\347\274\226\345\217\267", nullptr));
        pushButton_3_look->setText(QCoreApplication::translate("doctor", "\346\237\245\347\234\213", nullptr));
        pushButton_3_mod->setText(QCoreApplication::translate("doctor", "\344\277\256\346\224\271", nullptr));
        pushButton_3_add->setText(QCoreApplication::translate("doctor", "\346\226\260\345\242\236", nullptr));
        pushButton_4_stop->setText(QCoreApplication::translate("doctor", "\346\232\202\345\201\234", nullptr));
        label_5->setText(QCoreApplication::translate("doctor", "\351\242\204\347\272\246\347\274\226\345\217\267", nullptr));
        pushButton_7_qur->setText(QCoreApplication::translate("doctor", "\346\237\245\350\257\242", nullptr));
        pushButton_7_add->setText(QString());
        pushButton_7_del->setText(QString());
        pushButton_7_sub->setText(QCoreApplication::translate("doctor", "\346\217\220\344\272\244", nullptr));
        label_10->setText(QCoreApplication::translate("doctor", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_12->setText(QCoreApplication::translate("doctor", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_6->setText(QCoreApplication::translate("doctor", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class doctor: public Ui_doctor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTOR_H

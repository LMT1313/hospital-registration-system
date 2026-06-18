/********************************************************************************
** Form generated from reading UI file 'patient.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_H
#define UI_PATIENT_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Patient
{
public:
    QVBoxLayout *verticalLayout_7;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_id;
    QPushButton *pushButton_return;
    QWidget *bigwidgt;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_sex;
    QLineEdit *lineEdit_age;
    QLabel *label_3;
    QLineEdit *lineEdit_adr;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_phone;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_save;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox_1_1;
    QComboBox *comboBox_1_2;
    QDateEdit *dateEdit;
    QComboBox *comboBox_1_time;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_1_q;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox_2_dept;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2_yuyue;
    QTableWidget *tableWidget_2_show;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *comboBox_3_q;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QTextBrowser *textBrowser_3_intro;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_3_q;
    QWidget *page_5;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_4_q;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4_pay;
    QPushButton *pushButton_4_tuikuan;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5_old;
    QLineEdit *lineEdit_5_new;
    QLabel *label;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QWidget *page_7;

    void setupUi(QWidget *Patient)
    {
        if (Patient->objectName().isEmpty())
            Patient->setObjectName("Patient");
        Patient->resize(845, 522);
        Patient->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/image/wel.png);\n"
""));
        verticalLayout_7 = new QVBoxLayout(Patient);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalWidget_2 = new QWidget(Patient);
        horizontalWidget_2->setObjectName("horizontalWidget_2");
        horizontalWidget_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 1px solid black;\n"
"  border-radius: 2px; \n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(10, -1, 20, -1);
        label_id = new QLabel(horizontalWidget_2);
        label_id->setObjectName("label_id");
        label_id->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_id);

        pushButton_return = new QPushButton(horizontalWidget_2);
        pushButton_return->setObjectName("pushButton_return");
        pushButton_return->setMinimumSize(QSize(100, 0));
        pushButton_return->setMaximumSize(QSize(100, 16777215));
        pushButton_return->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(pushButton_return);


        verticalLayout_7->addWidget(horizontalWidget_2);

        bigwidgt = new QWidget(Patient);
        bigwidgt->setObjectName("bigwidgt");
        bigwidgt->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_2 = new QHBoxLayout(bigwidgt);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        listWidget = new QListWidget(bigwidgt);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("\n"
"QListWidget {\n"
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
"    background-color: rgba(0, 0, 0, 20); /* \346\267\241\346\267\241\347\232\204\347\201\260\350\211"
                        "\262 */\n"
"}"));

        horizontalLayout_2->addWidget(listWidget);

        stackedWidget = new QStackedWidget(bigwidgt);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("QPushButton, QLineEdit, QComboBox, QListWidget, QTextEdit,QDateEdit {\n"
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
        verticalLayout_9 = new QVBoxLayout(page);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(100, 20, 170, -1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setContentsMargins(100, -1, 50, -1);
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_name = new QLineEdit(page);
        lineEdit_name->setObjectName("lineEdit_name");

        gridLayout_2->addWidget(lineEdit_name, 0, 1, 1, 1);

        comboBox_sex = new QComboBox(page);
        comboBox_sex->addItem(QString());
        comboBox_sex->addItem(QString());
        comboBox_sex->setObjectName("comboBox_sex");

        gridLayout_2->addWidget(comboBox_sex, 1, 1, 1, 1);

        lineEdit_age = new QLineEdit(page);
        lineEdit_age->setObjectName("lineEdit_age");

        gridLayout_2->addWidget(lineEdit_age, 2, 1, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_adr = new QLineEdit(page);
        lineEdit_adr->setObjectName("lineEdit_adr");

        gridLayout_2->addWidget(lineEdit_adr, 4, 1, 1, 1);

        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_phone = new QLineEdit(page);
        lineEdit_phone->setObjectName("lineEdit_phone");

        gridLayout_2->addWidget(lineEdit_phone, 3, 1, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        verticalLayout_9->addLayout(verticalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(200, -1, 200, 50);
        pushButton_save = new QPushButton(page);
        pushButton_save->setObjectName("pushButton_save");

        horizontalLayout_7->addWidget(pushButton_save);


        verticalLayout_9->addLayout(horizontalLayout_7);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(5);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(140, 50, 170, -1);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setVerticalSpacing(7);
        gridLayout_3->setContentsMargins(100, -1, 50, -1);
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");

        gridLayout_3->addWidget(label_11, 3, 0, 1, 1);

        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 1, 0, 1, 1);

        comboBox_1_1 = new QComboBox(page_2);
        comboBox_1_1->addItem(QString());
        comboBox_1_1->setObjectName("comboBox_1_1");

        gridLayout_3->addWidget(comboBox_1_1, 0, 1, 1, 1);

        comboBox_1_2 = new QComboBox(page_2);
        comboBox_1_2->addItem(QString());
        comboBox_1_2->setObjectName("comboBox_1_2");

        gridLayout_3->addWidget(comboBox_1_2, 1, 1, 1, 1);

        dateEdit = new QDateEdit(page_2);
        dateEdit->setObjectName("dateEdit");

        gridLayout_3->addWidget(dateEdit, 2, 1, 1, 1);

        comboBox_1_time = new QComboBox(page_2);
        comboBox_1_time->addItem(QString());
        comboBox_1_time->addItem(QString());
        comboBox_1_time->setObjectName("comboBox_1_time");

        gridLayout_3->addWidget(comboBox_1_time, 3, 1, 1, 1);


        horizontalLayout_9->addLayout(gridLayout_3);


        verticalLayout_10->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(250, -1, 220, 60);
        pushButton_1_q = new QPushButton(page_2);
        pushButton_1_q->setObjectName("pushButton_1_q");

        horizontalLayout_8->addWidget(pushButton_1_q);


        verticalLayout_10->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_13 = new QVBoxLayout(page_3);
        verticalLayout_13->setObjectName("verticalLayout_13");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        comboBox_2_dept = new QComboBox(page_3);
        comboBox_2_dept->addItem(QString());
        comboBox_2_dept->setObjectName("comboBox_2_dept");

        horizontalLayout_12->addWidget(comboBox_2_dept);

        checkBox_2 = new QCheckBox(page_3);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_12->addWidget(checkBox_2);

        pushButton = new QPushButton(page_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_12->addWidget(pushButton);

        pushButton_2_yuyue = new QPushButton(page_3);
        pushButton_2_yuyue->setObjectName("pushButton_2_yuyue");

        horizontalLayout_12->addWidget(pushButton_2_yuyue);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(2, 1);
        horizontalLayout_12->setStretch(3, 1);

        verticalLayout_13->addLayout(horizontalLayout_12);

        tableWidget_2_show = new QTableWidget(page_3);
        tableWidget_2_show->setObjectName("tableWidget_2_show");
        tableWidget_2_show->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_13->addWidget(tableWidget_2_show);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_12 = new QVBoxLayout(page_4);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, -1, 10, -1);
        comboBox_3_q = new QComboBox(page_4);
        comboBox_3_q->addItem(QString());
        comboBox_3_q->setObjectName("comboBox_3_q");

        horizontalLayout_10->addWidget(comboBox_3_q);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);


        verticalLayout_11->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        textBrowser_3_intro = new QTextBrowser(page_4);
        textBrowser_3_intro->setObjectName("textBrowser_3_intro");

        horizontalLayout_11->addWidget(textBrowser_3_intro);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_11);

        tableWidget_3_q = new QTableWidget(page_4);
        tableWidget_3_q->setObjectName("tableWidget_3_q");

        verticalLayout_11->addWidget(tableWidget_3_q);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 1);
        verticalLayout_11->setStretch(2, 10);

        verticalLayout_12->addLayout(verticalLayout_11);

        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        verticalLayout_6 = new QVBoxLayout(page_5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableWidget_4_q = new QTableWidget(page_5);
        tableWidget_4_q->setObjectName("tableWidget_4_q");

        verticalLayout_6->addWidget(tableWidget_4_q);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(300, -1, 50, -1);
        pushButton_4_pay = new QPushButton(page_5);
        pushButton_4_pay->setObjectName("pushButton_4_pay");

        horizontalLayout->addWidget(pushButton_4_pay);

        pushButton_4_tuikuan = new QPushButton(page_5);
        pushButton_4_tuikuan->setObjectName("pushButton_4_tuikuan");

        horizontalLayout->addWidget(pushButton_4_tuikuan);


        verticalLayout_6->addLayout(horizontalLayout);

        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        verticalLayout_4 = new QVBoxLayout(page_6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(1);
        gridLayout->setContentsMargins(120, 50, 200, -1);
        lineEdit_5_old = new QLineEdit(page_6);
        lineEdit_5_old->setObjectName("lineEdit_5_old");

        gridLayout->addWidget(lineEdit_5_old, 0, 1, 1, 1);

        lineEdit_5_new = new QLineEdit(page_6);
        lineEdit_5_new->setObjectName("lineEdit_5_new");

        gridLayout->addWidget(lineEdit_5_new, 1, 1, 1, 1);

        label = new QLabel(page_6);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(page_6);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(190, -1, 250, 100);
        pushButton_5 = new QPushButton(page_6);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_5->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        stackedWidget->addWidget(page_7);

        horizontalLayout_2->addWidget(stackedWidget);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout_7->addWidget(bigwidgt);


        retranslateUi(Patient);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Patient);
    } // setupUi

    void retranslateUi(QWidget *Patient)
    {
        Patient->setWindowTitle(QCoreApplication::translate("Patient", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        horizontalWidget_2->setWhatsThis(QCoreApplication::translate("Patient", "<html><head/><body><p><img src=\":/image/bg.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_id->setText(QCoreApplication::translate("Patient", "\345\275\223\345\211\215\347\224\250\346\210\267\357\274\232", nullptr));
        pushButton_return->setText(QCoreApplication::translate("Patient", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Patient", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Patient", "\345\217\267\346\272\220\346\237\245\350\257\242\344\270\216\351\242\204\347\272\246", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Patient", "\347\247\221\345\256\244\345\214\273\347\224\237\346\237\245\350\257\242", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Patient", "\350\256\242\345\215\225\346\237\245\350\257\242", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Patient", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QCoreApplication::translate("Patient", "\345\271\264\351\276\204", nullptr));
        comboBox_sex->setItemText(0, QCoreApplication::translate("Patient", "\347\224\267", nullptr));
        comboBox_sex->setItemText(1, QCoreApplication::translate("Patient", "\345\245\263", nullptr));

        label_3->setText(QCoreApplication::translate("Patient", "\346\200\247\345\210\253", nullptr));
        label_6->setText(QCoreApplication::translate("Patient", "\345\234\260\345\235\200", nullptr));
        label_5->setText(QCoreApplication::translate("Patient", "\350\201\224\347\263\273\347\224\265\350\257\235", nullptr));
        label_2->setText(QCoreApplication::translate("Patient", "\345\247\223\345\220\215", nullptr));
        pushButton_save->setText(QCoreApplication::translate("Patient", "\344\277\235\345\255\230", nullptr));
        label_10->setText(QCoreApplication::translate("Patient", "\346\227\245\346\234\237", nullptr));
        label_11->setText(QCoreApplication::translate("Patient", "\346\227\266\351\227\264", nullptr));
        label_8->setText(QCoreApplication::translate("Patient", "\347\247\221\345\256\244", nullptr));
        label_9->setText(QCoreApplication::translate("Patient", "\345\214\273\347\224\237", nullptr));
        comboBox_1_1->setItemText(0, QCoreApplication::translate("Patient", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));

        comboBox_1_2->setItemText(0, QCoreApplication::translate("Patient", "\351\200\211\346\213\251\345\214\273\347\224\237", nullptr));

        comboBox_1_time->setItemText(0, QCoreApplication::translate("Patient", "\344\270\212\345\215\210 8:00-12:00", nullptr));
        comboBox_1_time->setItemText(1, QCoreApplication::translate("Patient", "\344\270\213\345\215\210 14:00-18:00", nullptr));

        pushButton_1_q->setText(QCoreApplication::translate("Patient", "\351\242\204\347\272\246", nullptr));
        comboBox_2_dept->setItemText(0, QCoreApplication::translate("Patient", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));

        checkBox_2->setText(QCoreApplication::translate("Patient", "\345\217\252\346\230\276\347\244\272\346\234\211\345\217\267", nullptr));
        pushButton->setText(QCoreApplication::translate("Patient", "\346\237\245\350\257\242", nullptr));
        pushButton_2_yuyue->setText(QCoreApplication::translate("Patient", "\351\242\204\347\272\246", nullptr));
        comboBox_3_q->setItemText(0, QCoreApplication::translate("Patient", "\351\200\211\346\213\251\347\247\221\345\256\244", nullptr));

        pushButton_4_pay->setText(QCoreApplication::translate("Patient", "\346\224\257\344\273\230", nullptr));
        pushButton_4_tuikuan->setText(QCoreApplication::translate("Patient", "\345\217\226\346\266\210\351\242\204\347\272\246", nullptr));
        label->setText(QCoreApplication::translate("Patient", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("Patient", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Patient", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Patient: public Ui_Patient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_H

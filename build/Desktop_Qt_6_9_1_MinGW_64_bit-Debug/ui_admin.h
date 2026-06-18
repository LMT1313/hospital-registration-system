/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_admin;
    QPushButton *pushButton_return;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget_adm;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *comboBox_0;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget_0;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_0_add;
    QPushButton *pushButton_0_del;
    QPushButton *pushButton_3_mod;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_1;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_1_save;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_9;
    QWidget *widget_2_copy;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2_copy;
    QPushButton *pushButton_2_rec;
    QWidget *page_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3_add;
    QPushButton *pushButton_3_del;
    QPushButton *pushButton_3_save;
    QWidget *page_5;
    QWidget *page_6;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5_old;
    QLineEdit *lineEdit_5_new;
    QLabel *label;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_5;
    QWidget *page_7;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_8;
    QTableView *tableView_0;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_11;
    QTableView *tableView_1;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_12;
    QTableView *tableView_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_9;
    QTableView *tableView_3;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName("admin");
        admin->resize(842, 530);
        admin->setStyleSheet(QString::fromUtf8("background-image: url(:/image/wel.png);"));
        verticalLayout_2 = new QVBoxLayout(admin);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(8, -1, 8, -1);
        label_admin = new QLabel(admin);
        label_admin->setObjectName("label_admin");

        horizontalLayout_3->addWidget(label_admin);

        pushButton_return = new QPushButton(admin);
        pushButton_return->setObjectName("pushButton_return");

        horizontalLayout_3->addWidget(pushButton_return);

        horizontalLayout_3->setStretch(0, 4);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        listWidget = new QListWidget(admin);
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

        stackedWidget_adm = new QStackedWidget(admin);
        stackedWidget_adm->setObjectName("stackedWidget_adm");
        stackedWidget_adm->setStyleSheet(QString::fromUtf8("QPushButton, QLineEdit, QComboBox, QListWidget, QTextEdit,QDateEdit\357\274\214QSpinBox {\n"
"    border: 1px solid black;\n"
"}\n"
"QHeaderView::section {\n"
"    border-bottom: 1px solid black;  /* \345\205\263\351\224\256\357\274\232\345\274\272\345\210\266\346\230\276\347\244\272\345\272\225\351\203\250\351\273\221\347\272\277 */\n"
"    border-right: 1px solid #dddddd; /* \345\217\257\351\200\211\357\274\232\347\273\231\345\210\227\344\271\213\351\227\264\344\271\237\345\212\240\346\235\241\347\273\206\347\272\277 */\n"
"    background-color: #f0f0f0;       /* \345\217\257\351\200\211\357\274\232\347\273\231\350\241\250\345\244\264\345\212\240\344\270\252\347\201\260\350\211\262\350\203\214\346\231\257\357\274\214\345\214\272\345\210\206\346\233\264\346\230\216\346\230\276 */\n"
"    padding: 4px;                    /* \345\217\257\351\200\211\357\274\232\345\242\236\345\212\240\344\270\200\347\202\271\345\206\205\350\276\271\350\267\235\357\274\214\350\256\251\346\226\207\345\255\227\344\270\215\350\264\264"
                        "\350\276\271 */\n"
"}\n"
"QTableWidget {\n"
"    border: 1px solid black;       /* \350\241\250\346\240\274\346\225\264\344\275\223\347\232\204\345\244\226\350\276\271\346\241\206 */\n"
"    gridline-color: black;         /* \345\206\205\351\203\250\345\215\225\345\205\203\346\240\274\347\272\277\346\235\241\351\242\234\350\211\262 */\n"
"}\n"
""));
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        comboBox_0 = new QComboBox(page);
        comboBox_0->setObjectName("comboBox_0");
        comboBox_0->setEditable(false);

        horizontalLayout_6->addWidget(comboBox_0);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout_5->addLayout(horizontalLayout_6);

        tableWidget_0 = new QTableWidget(page);
        tableWidget_0->setObjectName("tableWidget_0");

        verticalLayout_5->addWidget(tableWidget_0);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_0_add = new QPushButton(widget);
        pushButton_0_add->setObjectName("pushButton_0_add");

        horizontalLayout->addWidget(pushButton_0_add);

        pushButton_0_del = new QPushButton(widget);
        pushButton_0_del->setObjectName("pushButton_0_del");

        horizontalLayout->addWidget(pushButton_0_del);

        pushButton_3_mod = new QPushButton(widget);
        pushButton_3_mod->setObjectName("pushButton_3_mod");

        horizontalLayout->addWidget(pushButton_3_mod);


        verticalLayout_5->addWidget(widget);

        stackedWidget_adm->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_6 = new QVBoxLayout(page_2);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableWidget_1 = new QTableWidget(page_2);
        tableWidget_1->setObjectName("tableWidget_1");

        verticalLayout_6->addWidget(tableWidget_1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(-1, -1, 50, 15);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        pushButton_1_save = new QPushButton(page_2);
        pushButton_1_save->setObjectName("pushButton_1_save");

        horizontalLayout_7->addWidget(pushButton_1_save);

        horizontalLayout_7->setStretch(0, 5);
        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_7);

        stackedWidget_adm->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        horizontalLayout_9 = new QHBoxLayout(page_3);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        widget_2_copy = new QWidget(page_3);
        widget_2_copy->setObjectName("widget_2_copy");
        horizontalLayout_8 = new QHBoxLayout(widget_2_copy);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(175, 2, 200, -1);
        pushButton_2_copy = new QPushButton(widget_2_copy);
        pushButton_2_copy->setObjectName("pushButton_2_copy");

        verticalLayout->addWidget(pushButton_2_copy);

        pushButton_2_rec = new QPushButton(widget_2_copy);
        pushButton_2_rec->setObjectName("pushButton_2_rec");

        verticalLayout->addWidget(pushButton_2_rec);


        horizontalLayout_8->addLayout(verticalLayout);


        horizontalLayout_9->addWidget(widget_2_copy);

        stackedWidget_adm->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        horizontalLayout_5 = new QHBoxLayout(page_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableWidget_3 = new QTableWidget(page_4);
        tableWidget_3->setObjectName("tableWidget_3");

        verticalLayout_3->addWidget(tableWidget_3);

        widget_2 = new QWidget(page_4);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_3_add = new QPushButton(widget_2);
        pushButton_3_add->setObjectName("pushButton_3_add");

        horizontalLayout_2->addWidget(pushButton_3_add);

        pushButton_3_del = new QPushButton(widget_2);
        pushButton_3_del->setObjectName("pushButton_3_del");

        horizontalLayout_2->addWidget(pushButton_3_del);

        pushButton_3_save = new QPushButton(widget_2);
        pushButton_3_save->setObjectName("pushButton_3_save");

        horizontalLayout_2->addWidget(pushButton_3_save);


        verticalLayout_3->addWidget(widget_2);


        horizontalLayout_5->addLayout(verticalLayout_3);

        stackedWidget_adm->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget_adm->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        verticalLayout_4 = new QVBoxLayout(page_6);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(7);
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

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(190, -1, 250, 100);
        pushButton_5 = new QPushButton(page_6);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_10->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_10);

        stackedWidget_adm->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        verticalLayout_7 = new QVBoxLayout(page_7);
        verticalLayout_7->setObjectName("verticalLayout_7");
        tabWidget = new QTabWidget(page_7);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_8 = new QVBoxLayout(tab);
        verticalLayout_8->setObjectName("verticalLayout_8");
        tableView_0 = new QTableView(tab);
        tableView_0->setObjectName("tableView_0");

        verticalLayout_8->addWidget(tableView_0);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_11 = new QHBoxLayout(tab_2);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        tableView_1 = new QTableView(tab_2);
        tableView_1->setObjectName("tableView_1");

        horizontalLayout_11->addWidget(tableView_1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        horizontalLayout_12 = new QHBoxLayout(tab_3);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName("tableView_2");

        horizontalLayout_12->addWidget(tableView_2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_9 = new QVBoxLayout(tab_4);
        verticalLayout_9->setObjectName("verticalLayout_9");
        tableView_3 = new QTableView(tab_4);
        tableView_3->setObjectName("tableView_3");

        verticalLayout_9->addWidget(tableView_3);

        tabWidget->addTab(tab_4, QString());

        verticalLayout_7->addWidget(tabWidget);

        stackedWidget_adm->addWidget(page_7);

        horizontalLayout_4->addWidget(stackedWidget_adm);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 6);

        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(admin);

        stackedWidget_adm->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Form", nullptr));
        label_admin->setText(QCoreApplication::translate("admin", "\346\254\242\350\277\216\346\202\250", nullptr));
        pushButton_return->setText(QCoreApplication::translate("admin", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("admin", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("admin", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("admin", "\346\225\260\346\215\256\347\256\241\347\220\206", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("admin", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("admin", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("admin", "\346\237\245\347\234\213\346\227\245\345\277\227", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_0_add->setText(QCoreApplication::translate("admin", "\346\226\260\345\242\236", nullptr));
        pushButton_0_del->setText(QCoreApplication::translate("admin", "\345\210\240\351\231\244", nullptr));
        pushButton_3_mod->setText(QCoreApplication::translate("admin", "\344\277\235\345\255\230", nullptr));
        pushButton_1_save->setText(QCoreApplication::translate("admin", "\344\277\235\345\255\230", nullptr));
        pushButton_2_copy->setText(QCoreApplication::translate("admin", "\345\244\207\344\273\275\346\226\207\344\273\266", nullptr));
        pushButton_2_rec->setText(QCoreApplication::translate("admin", "\346\201\242\345\244\215", nullptr));
        pushButton_3_add->setText(QCoreApplication::translate("admin", "\346\226\260\345\242\236", nullptr));
        pushButton_3_del->setText(QCoreApplication::translate("admin", "\345\210\240\351\231\244", nullptr));
        pushButton_3_save->setText(QCoreApplication::translate("admin", "\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("admin", "\346\227\247\345\257\206\347\240\201", nullptr));
        label_7->setText(QCoreApplication::translate("admin", "\346\226\260\345\257\206\347\240\201", nullptr));
        pushButton_5->setText(QCoreApplication::translate("admin", "\344\277\235\345\255\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("admin", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("admin", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("admin", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("admin", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H

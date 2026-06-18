/********************************************************************************
** Form generated from reading UI file 'zdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZDIALOG_H
#define UI_ZDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ZDialog
{
public:

    void setupUi(QDialog *ZDialog)
    {
        if (ZDialog->objectName().isEmpty())
            ZDialog->setObjectName("ZDialog");
        ZDialog->resize(400, 300);

        retranslateUi(ZDialog);

        QMetaObject::connectSlotsByName(ZDialog);
    } // setupUi

    void retranslateUi(QDialog *ZDialog)
    {
        ZDialog->setWindowTitle(QCoreApplication::translate("ZDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ZDialog: public Ui_ZDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZDIALOG_H

#ifndef ZDIALOG_H
#define ZDIALOG_H

#include <QDialog>

namespace Ui {
class ZDialog;
}

class ZDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZDialog(QString fee,QWidget *parent = nullptr);
    ~ZDialog();

private:
    Ui::ZDialog *ui;
};

#endif // ZDIALOG_H

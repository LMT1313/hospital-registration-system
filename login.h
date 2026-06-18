#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include<QLabel>
#include"patient.h"
#include"doctor.h"
#include"nurse.h"
#include"admin.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    Patient pat;
    doctor doc;
    nurse nus;
    admin adm;
    QAction *eyeAction;

};
#endif // LOGIN_H

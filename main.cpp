#include "login.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include<QFile>
//#include"patient.h"
#include"dialog.h"
#include"zdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");



    // 方式 B：不配置 DSN，直接写连接字符串（推荐，更灵活）

    db.setDatabaseName(QString("DRIVER={MySQL ODBC 8.0 Unicode Driver};"
                               "SERVER=localhost;"
                               "DATABASE=hospital_registration;"
                               "USER=root;"
                               "PASSWORD=123456;"
                               "PORT=3306;"
                               "CHARSET=utf8;"
                               "USE_UNICODE_RESULT=1;"
                               "NO_SCHEMA=1;"
                               "OPTION=3;"));


    // 3. 打开连接
    if (db.open()) {
        qDebug() << "数据库连接成功！";
    } else {
        qDebug() << "连接失败：" << db.lastError().text();
    }
    login w;
    w.show();
    // Patient pat;
    // pat.inital("445101199001011234");
    // pat.show();
    return a.exec();
}

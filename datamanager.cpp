#include "datamanager.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
datamanager::datamanager(QObject *parent)
    : QObject{parent}
{}

bool datamanager::login(QString id, QString password,QString role)
{

    if(role=="患者"){

        QSqlQuery query;
        query.prepare("SELECT Pat_name FROM patient WHERE Pat_id = :id AND Pat_pwd = :pwd ");

        // 3. 绑定参数（防止 SQL 注入）
        query.bindValue(":id", id);
        query.bindValue(":pwd", password);


        // 4. 执行并判断结果
        if (query.exec()) {
            if (query.next()) {
                return true;
            } else {

                return false;
            }
        } else {
            qDebug() << "SQL执行失败:" << query.lastError().text();
            return false;
        }
        query.finish();
    }
    else if(role=="医生"){

        QSqlQuery query;
        query.prepare("SELECT Doc_name FROM doctor WHERE Doc_id = :id AND Doc_pwd = :pwd ");

        // 3. 绑定参数（防止 SQL 注入）
        query.bindValue(":id", id);
        query.bindValue(":pwd", password);


        // 4. 执行并判断结果
        if (query.exec()) {
            if (query.next()) {
                return true;
            } else {

                return false;
            }
        } else {
            qDebug() << "SQL执行失败:" << query.lastError().text();
            return false;
        }
        query.finish();
    }
    else if(role=="护士"){

        QSqlQuery query;
        query.prepare("SELECT Nur_name FROM nurse WHERE Nur_id = :id AND Nur_pwd = :pwd ");

        // 3. 绑定参数（防止 SQL 注入）
        query.bindValue(":id", id);
        query.bindValue(":pwd", password);


        // 4. 执行并判断结果
        if (query.exec()) {
            if (query.next()) {
                return true;
            } else {

                return false;
            }
        } else {
            qDebug() << "SQL执行失败:" << query.lastError().text();
            return false;
        }
        query.finish();
    }
    else {

        QSqlQuery query;
        query.prepare("SELECT Adm_name FROM administrator WHERE Adm_id = :id AND Adm_pwd = :pwd ");

        // 3. 绑定参数（防止 SQL 注入）
        query.bindValue(":id", id);
        query.bindValue(":pwd", password);


        // 4. 执行并判断结果
        if (query.exec()) {
            if (query.next()) {
                return true;
            } else {

                return false;
            }
        } else {
            qDebug() << "SQL执行失败:" << query.lastError().text();
            return false;
        }
        query.finish();
    }


}
//注册
int datamanager::sign(QString id, QString password)
{
    QSqlQuery query0;
    query0.prepare("SELECT Pat_name FROM patient WHERE Pat_id = :id ");

    // 3. 绑定参数（防止 SQL 注入）
    query0.bindValue(":id", id);



    // 4. 执行并判断结果
    if (query0.exec()) {
        if (query0.next()) {
            return 0;
        }
    }



    QSqlQuery query;

    query.prepare("INSERT INTO patient (Pat_id, Pat_pwd) VALUES (:id, :pwd)");

    // 3. 绑定值
    query.bindValue(":id", id);
    query.bindValue(":pwd", password);

    // 4. 执行插入
    if (query.exec()) {
        query.finish();
        return 1; // 注册成功
    } else {
        return 2; // 数据库执行错误
    }

}

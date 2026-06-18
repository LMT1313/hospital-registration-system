#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include<QString>
#include<QSqlQuery>
class datamanager : public QObject
{
    Q_OBJECT

public:
    explicit datamanager(QObject *parent = nullptr);
    static bool login(QString id,QString password,QString role);
    static int sign(QString id,QString password);

signals:
};

#endif // DATAMANAGER_H

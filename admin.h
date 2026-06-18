#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include<QListWidgetItem>
#include<QSqlTableModel>
namespace Ui {
class admin;
}

class admin : public QWidget
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();
    void initial(QString &id);
    void loadTableData(int index);
    void loadpermis();
    void updatepermit();
void loadsys();
    void inilog();
signals:
    void loginreturn();


private slots:
    void on_pushButton_return_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);



    void on_comboBox_0_currentIndexChanged(int index);

    void on_pushButton_0_add_clicked();

    void on_pushButton_0_del_clicked();


    void on_pushButton_3_mod_clicked();

    void on_pushButton_1_save_clicked();

    void on_pushButton_2_copy_clicked();

    void on_pushButton_2_rec_clicked();

    void on_pushButton_3_add_clicked();

    void on_pushButton_3_del_clicked();


    void on_pushButton_3_save_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::admin *ui;
    int m_id;
    QSqlTableModel *orderLogModel;
    QSqlTableModel *payModel;
    QSqlTableModel *souModel;
    QSqlTableModel *medModel;
};

#endif // ADMIN_H

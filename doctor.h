#ifndef DOCTOR_H
#define DOCTOR_H

#include <QWidget>
#include<QListWidgetItem>
namespace Ui {
class doctor;
}

class doctor : public QWidget
{
    Q_OBJECT

public:
    explicit doctor(QWidget *parent = nullptr);
    ~doctor();
    void inital(QString id);
    //void initialtable();
    //void initalpat();
    void initalhaoyuan();
    void rollback();
    void updatepermit();
    bool queueday(int ordid);

signals:
    void loginreturn();
private slots:


    void on_listWidget_itemClicked(QListWidgetItem *item);


    // void on_pushButton__0_q_clicked();

    // void on_pushButton_0_modify_clicked();

    void on_pushButton_0_fabu_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_2_save_clicked();

    void on_pushButton_3_look_clicked();

    void on_pushButton_3_mod_clicked();

    void on_pushButton_3_add_clicked();

    void on_pushButton_4_stop_clicked();

    void on_pushButton_7_qur_clicked();

    void on_pushButton_7_del_clicked();

    void on_pushButton_7_sub_clicked();

    void on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1);

    void on_pushButton_7_add_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::doctor *ui;
    int m_id;
};

#endif // DOCTOR_H

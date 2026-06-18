#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>
#include<QString>
#include<QListWidgetItem>
namespace Ui {
class Patient;
}

class Patient : public QWidget
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = nullptr,QString id="");
    ~Patient();
    void inital(QString id);
    void initaldept();
    void quaryorder();

    void rollback();
    void updatepermit();
    int zhifu(QString fee,int i);
signals:
    void loginreturn();

private slots:


    void on_listWidget_itemClicked(QListWidgetItem *item);


    void on_pushButton_save_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_clicked();

    void on_comboBox_3_q_currentTextChanged(const QString &arg1);

    void on_comboBox_1_1_currentTextChanged(const QString &arg1);

    void on_pushButton_1_q_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_tuikuan_clicked();

    void on_pushButton_4_pay_clicked();

    void on_pushButton_2_yuyue_clicked();

private:
    Ui::Patient *ui;
    QString m_id;
    QAction *eyeAction;
    QAction *eyeAction2;
};

#endif // PATIENT_H

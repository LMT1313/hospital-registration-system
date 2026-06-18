#ifndef NURSE_H
#define NURSE_H

#include <QWidget>
#include<QListWidgetItem>
namespace Ui {
class nurse;
}

class nurse : public QWidget
{
    Q_OBJECT

public:
    explicit nurse(QWidget *parent = nullptr);
    ~nurse();
    void initial(QString &id);
    void initialpat();
    void updatepermit();
    void rollback();

signals:
    void loginreturn();
private slots:
    void on_pushButton_return_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_save_clicked();

    void on_pushButton_2_sub_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::nurse *ui;
    int m_id;
};

#endif // NURSE_H

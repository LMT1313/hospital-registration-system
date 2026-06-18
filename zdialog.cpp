#include "zdialog.h"
#include "ui_zdialog.h"
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
ZDialog::ZDialog(QString fee,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ZDialog)
{
    ui->setupUi(this);
    setWindowTitle("支付宝支付 - 医院挂号系统");
    setFixedSize(350, 480);
    setStyleSheet("background-color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 1. 标题 (支付宝蓝)
    QLabel *titleLabel = new QLabel("支付宝支付");
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #1677FF;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // 2. 订单详情
    QLabel *infoLabel = new QLabel(QString("应付金额：￥%2").arg(fee));
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("color: #333; font-size: 14px;");

    // 3. 二维码 (指向你的支付宝收款码资源)
    QLabel *qrLabel = new QLabel();
    QPixmap qrPixmap(":/image/code.png");
    if(qrPixmap.isNull()) {
        qrLabel->setText("支付宝二维码加载失败");
        qrLabel->setStyleSheet("color: gray; border: 1px solid #eee;");
    } else {
        qrLabel->setPixmap(qrPixmap.scaled(220, 220, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    qrLabel->setAlignment(Qt::AlignCenter);

    // 4. 提示
    QLabel *tipLabel = new QLabel("请使用支付宝扫描二维码完成支付");
    tipLabel->setStyleSheet("color: #888; font-size: 12px;");
    tipLabel->setAlignment(Qt::AlignCenter);

    // 5. 按钮布局
    QHBoxLayout *btnLayout = new QHBoxLayout();

    QPushButton *btnDone = new QPushButton("我已支付");
    btnDone->setStyleSheet(
        "QPushButton { background-color: #1677FF; color: white; padding: 10px; border-radius: 5px; font-weight: bold; }"
        "QPushButton:hover { background-color: #0056CC; }"
        );


    QPushButton *btnCancel = new QPushButton("取消支付");
    btnCancel->setStyleSheet(
        "QPushButton { background-color: #f5f5f5; color: #666; padding: 10px; border-radius: 5px; border: 1px solid #ddd; }"
        "QPushButton:hover { background-color: #eeeeee; }"
        );



 btnLayout->addWidget(btnDone);
    btnLayout->addWidget(btnCancel);


    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(qrLabel);
    mainLayout->addWidget(tipLabel);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(btnLayout);

    // 事件连接
    connect(btnDone, &QPushButton::clicked, this, &ZDialog::accept);
    connect(btnCancel, &QPushButton::clicked, this, &ZDialog::reject);
}


ZDialog::~ZDialog()
{
    delete ui;
}

#include "dialog.h"
#include "ui_dialog.h"
#include<QVBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
Dialog::Dialog(QString fee,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    setWindowTitle("微信支付 - 医院挂号系统");
    setFixedSize(350, 480); // 稍微调高一点高度以容纳按钮
    setStyleSheet("background-color: white;");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 1. 标题
    QLabel *titleLabel = new QLabel("微信支付");
    titleLabel->setStyleSheet("font-size: 20px; font-weight: bold; color: #07C160;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // 2. 订单详情
    QLabel *infoLabel = new QLabel(QString("应付金额：￥%1").arg(fee));
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("color: #333; font-size: 14px;");

    // 3. 二维码
    QLabel *qrLabel = new QLabel();
    QPixmap qrPixmap(":/image/code.png");
    if(qrPixmap.isNull()) {
        qrLabel->setText("二维码加载失败\n请检查资源路径");
        qrLabel->setStyleSheet("color: red; border: 1px dashed gray;");
    } else {
        qrLabel->setPixmap(qrPixmap.scaled(220, 220, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    qrLabel->setAlignment(Qt::AlignCenter);

    // 4. 提示
    QLabel *tipLabel = new QLabel("请使用微信扫描二维码完成支付");
    tipLabel->setStyleSheet("color: #888; font-size: 12px;");
    tipLabel->setAlignment(Qt::AlignCenter);

    // --- 5. 按钮部分 ---
    QHBoxLayout *btnLayout = new QHBoxLayout();

    // 取消按钮
    QPushButton *btnCancel = new QPushButton("取消支付");
    btnCancel->setCursor(Qt::PointingHandCursor);
    btnCancel->setStyleSheet(
        "QPushButton { background-color: #f5f5f5; color: #666; padding: 10px; border-radius: 5px; border: 1px solid #ddd; }"
        "QPushButton:hover { background-color: #eeeeee; }"
        );

    // 确认支付按钮
    QPushButton *btnDone = new QPushButton("我已支付");
    btnDone->setCursor(Qt::PointingHandCursor);
    btnDone->setStyleSheet(
        "QPushButton { background-color: #07C160; color: white; padding: 10px; border-radius: 5px; font-weight: bold; }"
        "QPushButton:hover { background-color: #06AD56; }"
        );
  btnLayout->addWidget(btnDone);
    btnLayout->addWidget(btnCancel);


    // 添加到主布局
    mainLayout->addWidget(titleLabel);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(infoLabel);
    mainLayout->addWidget(qrLabel);
    mainLayout->addWidget(tipLabel);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(btnLayout);

    // --- 6. 事件连接 ---
    // 点击“我已支付”，关闭对话框并返回 Accepted 状态
    connect(btnDone, &QPushButton::clicked, this, &Dialog::accept);

    // 点击“取消支付”，关闭对话框并返回 Rejected 状态
    connect(btnCancel, &QPushButton::clicked, this, &Dialog::reject);


}

Dialog::~Dialog()
{
    delete ui;
}

#include "login.h"
#include "ui_login.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include<QTime>
#include"datamanager.h"
login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);


    setWindowTitle("医院挂号系统 - 用户登录");

    connect(&pat,&Patient::loginreturn,[&](){
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
        eyeAction->setChecked(false);
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        this->show();
    });
    connect(&doc,&doctor::loginreturn,[&](){
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
         eyeAction->setChecked(false);
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        this->show();
    });
    connect(&nus,&nurse::loginreturn,[&](){
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
         eyeAction->setChecked(false);
        ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        this->show();
    });
    connect(&adm,&admin::loginreturn,[&](){
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
         eyeAction->setChecked(false);
         ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        this->show();

    });

    eyeAction = new QAction(this);
    eyeAction->setIcon(QIcon(":/image/eye_close.png"));
    eyeAction->setCheckable(true); // 设置为可选中状态
    ui->lineEdit_password->addAction(eyeAction,QLineEdit::TrailingPosition);
    connect(eyeAction, &QAction::toggled, this, [=](bool checked){
        if (checked) {
            // 睁眼：显示明文，换图标
            eyeAction->setIcon(QIcon(":/image/eye_open.png"));
            ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
        } else {
            // 闭眼：隐藏密码，换图标
            eyeAction->setIcon(QIcon(":/image/eye_close.png"));
            ui->lineEdit_password->setEchoMode(QLineEdit::Password);
        }
    });
    // --- 3. 信号与槽连接 ---
    // connect(m_btnLogin, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    // connect(m_btnRegister, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);

    // // 支持回车键登录
    // connect(m_lineEditPass, &QLineEdit::returnPressed, this, &LoginWindow::onLoginClicked);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_login_clicked()
{

     QString role = ui->comboBox_role->currentText();
    if(role!="管理员"){
    QSqlQuery query;
    query.prepare("SELECT Par_value FROM system_param WHERE Par_name = '维护时间'");

    if (query.exec() && query.next()) {

        QString timeRange = query.value(0).toString(); // 例如 "02:00-06:00"

        // 1. 使用 '-' 分割字符串
        QStringList parts = timeRange.split("-");
        if (parts.size() != 2) return ; // 格式错误则跳过
        // 2. 转换为 QTime 对象
        QTime startTime = QTime::fromString(parts[0].trimmed(), "HH:mm");
        QTime endTime = QTime::fromString(parts[1].trimmed(), "HH:mm");
        QTime currentTime = QTime::currentTime();
        // 3. 时间段判断逻辑
        bool isMaintenance = false;
        if (startTime < endTime) {
            // 普通时间段（如 02:00 到 06:00）

            if (currentTime >= startTime && currentTime <= endTime) {
                isMaintenance = true;
            }
        } else {
            // 跨年/跨天时间段（如 23:00 到 02:00）
            if (currentTime >= startTime || currentTime <= endTime) {
                isMaintenance = true;
            }
        }

        if (isMaintenance) {
            QMessageBox::critical(nullptr, "系统维护",
                                  QString("当前处于系统维护时间 (%1)，请稍后再试！").arg(timeRange));
            return ;
        }

    }


}

    // 1. 获取输入框内容并去除前后空格
    QString id = ui->lineEdit_login->text().trimmed();
    QString password = ui->lineEdit_password->text();

    // 2. 非空判断
    if (id.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "提示", "账号或密码不能为空！");
        return;
    }

    // 3. 调用验证接口 (假设接口名为 verifyLogin)
    // 这里我们直接写出逻辑，方便你参考如何操作数据库
    if (datamanager::login(id, password,role)) {
        QMessageBox::information(this, "成功", "登录成功！           ");
        // 这里可以跳转到主界面
        this->close();
        ui->comboBox_role->setCurrentIndex(0);
        if(role=="患者"){
            pat.inital(id);
            pat.show();
        }
        else if(role=="医生"){
            doc.inital(id);
            doc.show();
        }
        else if(role=="护士"){
            nus.initial(id);
            nus.show();
        }
        else{
            adm.initial(id);
            adm.show();
        }



    } else {
        QMessageBox::critical(this, "错误", "账号或密码错误，请重试。");
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
    }
}


void login::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT Par_value FROM system_param WHERE Par_name = '维护时间'");

    if (query.exec() && query.next()) {

        QString timeRange = query.value(0).toString(); // 例如 "02:00-06:00"

        // 1. 使用 '-' 分割字符串
        QStringList parts = timeRange.split("-");
        if (parts.size() != 2) return ; // 格式错误则跳过
        // 2. 转换为 QTime 对象
        QTime startTime = QTime::fromString(parts[0].trimmed(), "HH:mm");
        QTime endTime = QTime::fromString(parts[1].trimmed(), "HH:mm");
        QTime currentTime = QTime::currentTime();
        // 3. 时间段判断逻辑
        bool isMaintenance = false;
        if (startTime < endTime) {
            // 普通时间段（如 02:00 到 06:00）

            if (currentTime >= startTime && currentTime <= endTime) {
                isMaintenance = true;
            }
        } else {
            // 跨年/跨天时间段（如 23:00 到 02:00）
            if (currentTime >= startTime || currentTime <= endTime) {
                isMaintenance = true;
            }
        }

        if (isMaintenance) {
            QMessageBox::critical(nullptr, "系统维护",
                                  QString("当前处于系统维护时间 (%1)，请稍后再试！").arg(timeRange));
            return ;
        }

    }

    // 1. 获取界面数据
    QString username = ui->lineEdit_login->text().trimmed();
    QString password = ui->lineEdit_password->text();
    QString role = ui->comboBox_role->currentText(); // 获取下拉框当前文字
    // 3. 非空验证
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "提示", "账号和密码不能为空！");
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
        return;
    }

    // 2. 判断身份：必须是“患者”
    if (role != "患者") {
        QMessageBox::warning(this, "注册限制", "抱歉，目前系统仅支持“患者”自助注册。\n医护人员请联系管理员开通账号。");
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
        return;
    }



    // 4. 业务逻辑：检查账号是否存在 -> 执行注册
    int res=datamanager::sign(username, password);
    if (res==0) {
        QMessageBox::critical(this, "注册失败", "该账号已存在，不可注册。");
        ui->lineEdit_password->clear(); // 清空密码框
        ui->lineEdit_password->setFocus(); // 光标重新聚焦
    } else {
        if (res==1) {
            QMessageBox::information(this, "成功", "注册成功！现在可以登录了。");
            ui->lineEdit_password->clear(); // 清空密码框
            ui->lineEdit_password->setFocus(); // 光标重新聚焦
        } else {
            QMessageBox::critical(this, "错误", "数据库写入失败，请稍后再试。");
            ui->lineEdit_password->clear(); // 清空密码框
            ui->lineEdit_password->setFocus(); // 光标重新聚焦
        }
    }
}


#include "nurse.h"
#include "ui_nurse.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
nurse::nurse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nurse)
{
    ui->setupUi(this);
    setWindowTitle("医院挂号系统 - 护士界面");
    ui->stackedWidget_nur->setCurrentIndex(3);

}

nurse::~nurse()
{
    delete ui;
}

void nurse::initial(QString &id)

{
    ui->listWidget->clearSelection();
    ui->stackedWidget_nur->setCurrentIndex(3);
    m_id=id.toInt();
    ui->label_welcome->setText("欢迎您："+id);
    updatepermit();
    initialpat();
}

void nurse::initialpat()
{
    // 设置列数（这里以 7 列为例）
    ui->tableWidget_0->setColumnCount(7);

    // 定义表头文字
    QStringList headers;
    headers << "患者姓名" << "患者编号" << "预约编号" <<"就诊日期"<< "订单状态" << "支付状态" << "诊断结果" << "医嘱建议";

    // 设置表头
    ui->tableWidget_0->setHorizontalHeaderLabels(headers);

    // --- 样式美化（可选） ---

    // 1. 让表头自适应内容宽度
    ui->tableWidget_0->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // 2. 最后一列（通常是医嘱，文字较多）拉伸填充剩余空间
    ui->tableWidget_0->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);

    // // 3. 设置表头高亮和交替行颜色（增强可读性）
    // ui->tableWidget_0->setAlternatingRowColors(true);
    // ui->tableWidget_0->setStyleSheet("alternate-background-color: #f5faff; background-color: white;");

    // 4. 禁止编辑（护士站通常只读）
    ui->tableWidget_0->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 5. 选中整行
    ui->tableWidget_0->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_0->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );





    //在nurse表根据护士id找到科室id，在order表找该科室的所有患者，显示本科室就诊患者的基本信息、挂号订单信息、病历信息、医嘱信息
    ui->tableWidget_0->setRowCount(0); // 清空表格

    QSqlQuery query;
    // 准备 SQL：通过护士 ID 穿透到科室的所有患者数据
    QString sql =
        "SELECT "
        "  p.Pat_name, p.Pat_id, o.Ord_id, o.Ord_status, o.Ord_paystatus,s.Sou_date, "
        "  m.Med_diagnose, a.Adv_content "
        "FROM nurse n "
        "JOIN `porder` o ON n.Dep_id = o.Dep_id "
        "JOIN source s ON s.Sou_id = o.Sou_id "
        "JOIN patient p ON o.Pat_id = p.Pat_id "
        "LEFT JOIN medical m ON o.Ord_id = m.Ord_id "
        "LEFT JOIN advice a ON m.Med_id = a.Med_id "
        "WHERE n.Nur_id = :nid "
        "ORDER BY s.Sou_date DESC";

    query.prepare(sql);
    query.bindValue(":nid", m_id); // 登录时记录的护士ID

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            ui->tableWidget_0->insertRow(row);

            // 填充数据
            ui->tableWidget_0->setItem(row, 0, new QTableWidgetItem(query.value("Pat_name").toString()));
            ui->tableWidget_0->setItem(row, 1, new QTableWidgetItem(query.value("Pat_id").toString()));
            ui->tableWidget_0->setItem(row, 2, new QTableWidgetItem(query.value("Ord_id").toString()));
            ui->tableWidget_0->setItem(row, 3, new QTableWidgetItem(query.value("Sou_date").toString()));
            ui->tableWidget_0->setItem(row, 4, new QTableWidgetItem(query.value("Ord_status").toString()));
            ui->tableWidget_0->setItem(row, 5, new QTableWidgetItem(query.value("Ord_paystatus").toString()));
            // 状态显示优化：如果是“待就诊”且没病历，诊疗信息显示“尚未就诊”
            QString diagnose = query.value("Med_diagnose").toString();
            if (diagnose.isEmpty()) diagnose = "---";
            ui->tableWidget_0->setItem(row, 6, new QTableWidgetItem(diagnose));

            QString advice = query.value("Adv_content").toString();
            if (advice.isEmpty()) advice = "---";
            ui->tableWidget_0->setItem(row, 7, new QTableWidgetItem(advice));



            // 在循环内部填充完 item 后加入：
            QTableWidgetItem *statusItem = ui->tableWidget_0->item(row, 4); // 订单状态列
            QTableWidgetItem *payItem = ui->tableWidget_0->item(row, 5); // 支付状态列
            QString status = query.value("Ord_status").toString();
            QString pstatus = query.value("Ord_paystatus").toString();

            if (status == "待就诊") {
                statusItem->setForeground(QBrush(Qt::red)); // 蓝色提醒
                statusItem->setFont(QFont("Microsoft YaHei", 9, QFont::Bold));
            }



            row++;
        }
    } else {
        QMessageBox::critical(this, "查询失败", query.lastError().text());
    }
}

void nurse::updatepermit()
{
    QString roleName="护士";
    QSqlQuery query;
    // 1. 查询该角色的权限字符串
    query.prepare("SELECT Per_func FROM role_permission WHERE Role_name = :role");
    query.bindValue(":role", roleName);

    QString permissionStr = "";
    if (query.exec() && query.next()) {
        permissionStr = query.value(0).toString(); // 获取如 "个人信息、预约挂号"
    }

    // 2. 将字符串按顿号拆分为列表
    // QString::SkipEmptyParts 防止因为末尾多了一个顿号导致拆出空项
    QStringList allowedList = permissionStr.split("、", Qt::SkipEmptyParts);

    // 3. 遍历 ListWidget 控制显示或隐藏
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        QString itemText = item->text().trimmed(); // 去掉前后空格确保匹配准确

        // 如果该项不在权限列表里，则隐藏
        if (allowedList.contains(itemText)) {
            ui->listWidget->setRowHidden(i, false); // 显示
        } else {
            ui->listWidget->setRowHidden(i, true);  // 隐藏
        }
    }
}

void nurse::rollback()
{
    ui->lineEdit_1->clear();
    ui->textEdit_1->clear();
    ui->lineEdit_2_num->clear();
    ui->comboBox_2->setCurrentIndex(0);
    initialpat();
    ui->lineEdit_5_new->clear();
    ui->lineEdit_5_old->clear();
}

void nurse::on_pushButton_return_clicked()
{
    emit loginreturn();
    this->close();
}


void nurse::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString text = item->text().trimmed(); // 获取点击条目的文字
    rollback();

    if (text == "查看患者信息") {
        ui->stackedWidget_nur->setCurrentIndex(0);

    }
    else if (text == "协助诊疗") {
        ui->stackedWidget_nur->setCurrentIndex(1);

    }
    else if (text == "修改密码") {
        ui->stackedWidget_nur->setCurrentIndex(4);

    }
    else
        ui->stackedWidget_nur->setCurrentIndex(2);


}


void nurse::on_pushButton_save_clicked()
{
    //先要判断有没有填，根据用户填的订单编号，找病历信息表，如果已经有了，就把用户填的text增加进Med_note（保留原有的内容）
    //如果没有就插入一条，去order表里面找patid

    // 1. 获取输入
    QString ordIdStr = ui->lineEdit_1->text().trimmed();
    QString newNote = ui->textEdit_1->toPlainText().trimmed(); // 用户填写的追加备注

    // 2. 判断必填项
    if (ordIdStr.isEmpty() || newNote.isEmpty()) {
        QMessageBox::warning(this, "提示", "请填写预约编号和备注内容！");
        return;
    }
    int ordId = ordIdStr.toInt();

    // 开启事务
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    // 3. 查找病历表中是否已有该订单的记录
    QSqlQuery query;
    query.prepare("SELECT Med_id, Med_note FROM medical WHERE Ord_id = :oid");
    query.bindValue(":oid", ordId);

    if (query.exec() && query.next()) {
        // --- 情况 A: 已有病历，执行 UPDATE 追加备注 ---
        int medId = query.value("Med_id").toInt();

        QSqlQuery updateQuery;
        // 使用 CONCAT 追加内容，并在中间加个分号或换行区分
        updateQuery.prepare("UPDATE medical SET Med_note = CONCAT(IFNULL(Med_note,''), :appendNote) "
                            "WHERE Med_id = :mid");
        updateQuery.bindValue(":appendNote", "\n[护士追加]: " + newNote);
        updateQuery.bindValue(":mid", medId);

        if (updateQuery.exec()) {
            db.commit();
            QMessageBox::information(this, "成功", "备注已成功追加到原有病历中！");
            ui->lineEdit_1->clear();
            ui->textEdit_1->clear();

        } else {
            db.rollback();
            QMessageBox::critical(this, "失败", "更新备注失败：" + updateQuery.lastError().text());
        }
    }
    else{
        QMessageBox::critical(this, "失败", "该患者未有病例        " );
        ui->lineEdit_1->clear();
        ui->textEdit_1->clear();
    }

    ui->textEdit_1->clear();
}


void nurse::on_pushButton_2_sub_clicked()
{
    //先判断用户订单编号是否输入，在order表找到预约编号，如果缴费状态是已支付，则提示，否则更改缴费状态，
    //在pay增加一行信息
    // 1. 获取用户输入的订单编号
    QString ordIdStr = ui->lineEdit_2_num->text().trimmed();
    QString payType = ui->comboBox_2->currentText(); // 假设有缴费方式下拉框

    // 2. 判断订单编号是否输入
    if (ordIdStr.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号！");
        return;
    }
    int ordId = ordIdStr.toInt();

    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();

    // 3. 在 order 表中找到该订单信息
    QSqlQuery query;
    query.prepare("SELECT Pat_id, Ord_fee, Ord_paystatus FROM `porder` WHERE Ord_id = :oid");
    query.bindValue(":oid", ordId);

    if (query.exec() && query.next()) {
        QString patId = query.value("Pat_id").toString();
        double fee = query.value("Ord_fee").toDouble();
        QString payStatus = query.value("Ord_paystatus").toString();

        // 4. 判断缴费状
        if (payStatus == "已支付"||payStatus == "已退款") {
            QMessageBox::information(this, "提示", "该订单已完成缴费，无需重复操作。");
            db.rollback(); // 结束事务
            ui->lineEdit_2_num->clear();
            ui->comboBox_2->setCurrentIndex(0);
            return;
        }


        // 5. 更改订单缴费状态
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE `porder` SET Ord_paystatus = '已支付' WHERE Ord_id = :oid");
        updateQuery.bindValue(":oid", ordId);

        if (!updateQuery.exec()) {
            db.rollback();
            QMessageBox::critical(this, "失败", "更新订单支付状态失败：" + updateQuery.lastError().text());
            return;
        }

        // 6. 在 pay 表增加一行信息
        QSqlQuery payQuery;
        payQuery.prepare("INSERT INTO pay (Ord_id, Pat_id, Pay_amount, Pay_type, Pay_time) "
                         "VALUES (:oid, :pid, :amount, :type, NOW())");
        payQuery.bindValue(":oid", ordId);
        payQuery.bindValue(":pid", patId);
        payQuery.bindValue(":amount", fee);
        payQuery.bindValue(":type", payType); // 微信/支付宝/线下缴费

        if (payQuery.exec()) {
            // 提交事务
            if (db.commit()) {
                QMessageBox::information(this, "成功", QString("缴费成功！金额：￥%1").arg(fee));
                ui->lineEdit_2_num->clear();
                ui->comboBox_2->setCurrentIndex(0);
            } else {
                db.rollback();
                QMessageBox::critical(this, "错误", "事务提交失败！");
            }
        } else {
            db.rollback();
            QMessageBox::critical(this, "失败", "写入缴费记录失败：" + payQuery.lastError().text());
        }
    } else {
        db.rollback();
        QMessageBox::warning(this, "错误", "未找到该预约编号，请检查输入是否正确。");
        ui->lineEdit_2_num->clear();
        ui->comboBox_2->setCurrentIndex(0);
    }
}


void nurse::on_pushButton_5_clicked()
{
    QString oldPwd = ui->lineEdit_5_old->text().trimmed();
    QString newPwd = ui->lineEdit_5_new->text().trimmed();

    // 2. 非空校验
    if (oldPwd.isEmpty() || newPwd.isEmpty()) {
        QMessageBox::warning(this, "提示", "旧密码和新密码不能为空！");
        return;
    }

    // 3. 验证旧密码是否正确
    // 假设当前登录用户的 ID 存储在变量 m_id 中
    QSqlQuery query;
    query.prepare("SELECT Nur_pwd FROM nurse WHERE Nur_id = :id");
    query.bindValue(":id", m_id);

    if (query.exec() && query.next()) {
        QString dbPwd = query.value(0).toString();

        if (dbPwd != oldPwd) {
            QMessageBox::critical(this, "错误", "旧密码输入错误，请重新输入！");
            ui->lineEdit_5_old->clear();
            return;
        }
    } else {
        QMessageBox::critical(this, "错误", "查询用户信息失败！");
        ui->lineEdit_5_old->clear();
        ui->lineEdit_5_new->clear();
        return;
    }

    // 4. 二次确认修改
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认修改", "您确定要修改密码吗？修改后需重新登录。",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // 5. 执行更新操作
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE nurse SET Nur_pwd = :newPwd WHERE Nur_id = :id");
        updateQuery.bindValue(":newPwd", newPwd);
        updateQuery.bindValue(":id", m_id);

        if (updateQuery.exec()) {
            QMessageBox::information(this, "成功", "密码修改成功，请重新登录！");

            // 可选：修改成功后自动注销或清空输入框
            ui->lineEdit_5_old->clear();
            ui->lineEdit_5_new->clear();
            // 2. 发射信号
            emit loginreturn();
            // 3. 关闭（或隐藏）当前主界面
            this->close();


        } else {
            QMessageBox::critical(this, "失败", "数据库更新失败：" + updateQuery.lastError().text());
        }
    }
    else{
        ui->lineEdit_5_old->clear();
        ui->lineEdit_5_new->clear();

    }
}


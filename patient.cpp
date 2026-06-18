#include "patient.h"
#include "ui_patient.h"
#include<QSqlQuery>
#include<QMessageBox>
#include<QSqlError>
#include<QCalendarWidget>
#include<dialog.h>
#include<zdialog.h>
Patient::Patient(QWidget *parent,QString id)
    : QWidget(parent)
    , ui(new Ui::Patient)
{
    ui->setupUi(this);
    setWindowTitle("医院挂号系统 - 用户界面");
    ui->stackedWidget->setCurrentIndex(6);
    initaldept();
    updatepermit();
    // 1. 获取当前日期
    QDate today = QDate::currentDate();

    // 2. 计算 7 天后的日期
    QDate maxDate = today.addDays(7);
    // 3. 设置 QDateEdit 的范围
    ui->dateEdit->setMinimumDate(today);   // 只能选今天及以后
    ui->dateEdit->setMaximumDate(maxDate); // 只能选 7 天之内

    // 4. 设置默认显示的日期为今天
    ui->dateEdit->setDate(today);

    // 5. (可选) 弹出日历窗口，让用户选择更方便
    ui->dateEdit->setCalendarPopup(true);

    // 1. 初始化密码输入框
    ui->lineEdit_5_new->setEchoMode(QLineEdit::Password);
    ui->lineEdit_5_old->setEchoMode(QLineEdit::Password);

    // 2. 创建一个 Action 并设置闭眼图标
    eyeAction = new QAction(this);
    eyeAction->setIcon(QIcon(":/image/eye_close.png"));
    eyeAction->setCheckable(true); // 设置为可选中状态

    eyeAction2 = new QAction(this);
    eyeAction2->setIcon(QIcon(":/image/eye_close.png"));
    eyeAction2->setCheckable(true); // 设置为可选中状态

    // 3. 将 Action 添加到 LineEdit 的右侧
    ui->lineEdit_5_old->addAction(eyeAction, QLineEdit::TrailingPosition);
    ui->lineEdit_5_new->addAction(eyeAction2, QLineEdit::TrailingPosition);
    // 4. 连接 Action 的触发信号
    connect(eyeAction, &QAction::toggled, this, [=](bool checked){
        if (checked) {
            // 睁眼：显示明文，换图标
            eyeAction->setIcon(QIcon(":/image/eye_open.png"));
            ui->lineEdit_5_old->setEchoMode(QLineEdit::Normal);
        } else {
            // 闭眼：隐藏密码，换图标
            eyeAction->setIcon(QIcon(":/image/eye_close.png"));
            ui->lineEdit_5_old->setEchoMode(QLineEdit::Password);
        }
    });
    connect(eyeAction2, &QAction::toggled, this, [=](bool checked){
        if (checked) {
            // 睁眼：显示明文，换图标
            eyeAction->setIcon(QIcon(":/image/eye_open.png"));
            ui->lineEdit_5_new->setEchoMode(QLineEdit::Normal);
        } else {
            // 闭眼：隐藏密码，换图标
            eyeAction->setIcon(QIcon(":/image/eye_close.png"));
            ui->lineEdit_5_new->setEchoMode(QLineEdit::Password);
        }
    });



}

Patient::~Patient()
{
    delete ui;
}
//加载个人信息
void Patient::inital(QString id)
{
    ui->listWidget->clearSelection();
    ui->stackedWidget->setCurrentIndex(6);
    m_id=id;
    ui->label_id->setText("欢迎您："+id);

    QSqlQuery query;
    query.prepare("SELECT Pat_name, Pat_gender, Pat_age, Pat_phone, Pat_address "
                  "FROM patient WHERE Pat_id = :id");
    query.bindValue(":id", m_id);

    // 3. 执行并填充
    if (query.exec()) {
        if (query.next()) {
            // 从查询结果中取值 (注意索引顺序要和 SELECT 语句一致)
            QString name    = query.value(0).toString();
            QString gender  = query.value(1).toString();
            QString age;
            if(query.value(2).isNull())
                age="";
            else
                age     = query.value(2).toString();

            QString phone   = query.value(3).toString();
            QString address = query.value(4).toString();

            // 4. 把值放回 UI 控件
            ui->lineEdit_name->setText(name);
            ui->lineEdit_phone->setText(phone);
            ui->lineEdit_adr->setText(address);
            ui->lineEdit_age->setText(age);

            // 性别是 ComboBox，需要匹配文字
            ui->comboBox_sex ->setCurrentText(gender);

            qDebug() << "个人数据加载成功";
        }
    } else {
        qDebug() << "加载数据失败：" << query.lastError().text();
    }
}
//加载科室
void Patient::initaldept()
{


    // 2. 准备查询语句
    QSqlQuery query;
    // 使用 DISTINCT 可以去除重复的科室名（如果表里有重复的话）
    if (query.exec("SELECT DISTINCT Dep_name FROM department")) {
        while (query.next()) {
            // 获取第一列的值（索引为0）
            QString deptName = query.value(0).toString();

            // 3. 加入到 QComboBox
            ui->comboBox_1_1->addItem(deptName);
            ui->comboBox_2_dept->addItem(deptName);
            ui->comboBox_3_q->addItem(deptName);


        }
        qDebug() << "科室列表加载成功";
    } else {
        qDebug() << "获取科室失败：" << query.lastError().text();
    }
}
//获取订单信息（从视图）
void Patient::quaryorder()
{
    /// 1. 设置表头 (与视图中的别名一一对应)
    QStringList headers;
    headers << "预约编号" << "患者编号" << "患者姓名"<< "医生姓名"
            << "医生职称" << "科室名称" << "下单时间" << "挂号费用"
            << "支付状态" << "订单状态" << "就诊日期" << "就诊时段";

    ui->tableWidget_4_q->setColumnCount(headers.size());
    ui->tableWidget_4_q->setHorizontalHeaderLabels(headers);

    // 基础外观设置
    ui->tableWidget_4_q->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_4_q->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_4_q->horizontalHeader()->setStretchLastSection(true); // 最后一列自适应
    ui->tableWidget_4_q->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_4_q->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );
    // 2. 执行视图查询
    QSqlQuery query;
    // 假设你的视图名字叫 v_porder_info
    query.prepare("SELECT * FROM my_patient_orders WHERE `患者编号` = :pid");
    query.bindValue(":pid", m_id); // m_id 为当前登录患者的ID
    if (query.exec()) {
        ui->tableWidget_4_q->setRowCount(0); // 先清空
        int row = 0;

        while (query.next()) {
            ui->tableWidget_4_q->insertRow(row);
            for (int col = 0; col < headers.size(); ++col) {
                // 处理空值，防止出现随机数字或 0
                QVariant val = query.value(col);
                QString text = val.isNull() ? "" : val.toString();

                QTableWidgetItem *item = new QTableWidgetItem(text);
                item->setTextAlignment(Qt::AlignCenter);

                // 顺手给“订单状态”列加点颜色标识（假设在第10列）
                if (col == 9) {
                    if (text == "待就诊") item->setForeground(Qt::blue);
                    else if (text == "已取消") item->setForeground(Qt::red);
                    else if (text == "已完成") item->setForeground(Qt::darkGreen);
                }

                ui->tableWidget_4_q->setItem(row, col, item);
            }
            row++;
        }
    } else {
        QMessageBox::critical(this, "视图读取失败", query.lastError().text());
    }

    // 自动调整列宽
    ui->tableWidget_4_q->setColumnHidden(1, true);
    ui->tableWidget_4_q->setColumnHidden(2, true);
    ui->tableWidget_4_q->resizeColumnsToContents();



}

void Patient::rollback()
{
    ui->comboBox_1_1->setCurrentIndex(0);
    ui->comboBox_1_2->clear();
    ui->comboBox_1_2->addItem("选择医生");
    ui->comboBox_1_time->setCurrentIndex(-1);

    // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
    ui->dateEdit->setDate(QDate::currentDate());




    ui->comboBox_2_dept->setCurrentIndex(0);
    ui->checkBox_2->setChecked(false);
    ui->tableWidget_2_show->setRowCount(0);

    ui->comboBox_3_q->setCurrentIndex(0);
    ui->textBrowser_3_intro->clear();
    ui->tableWidget_3_q->setRowCount(0);

    updatepermit();

    eyeAction->setChecked(false);
    ui->lineEdit_5_old->setEchoMode(QLineEdit::Password);
    eyeAction2->setChecked(false);
    ui->lineEdit_5_new->setEchoMode(QLineEdit::Password);
    ui->lineEdit_5_old->clear();
    ui->lineEdit_5_new->clear();
}

void Patient::updatepermit()
{
    QString roleName="患者";
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

int Patient::zhifu(QString fee,int i)
{
    if(i==0){
        Dialog dlg(fee,nullptr);
        if (dlg.exec() == QDialog::Accepted) {
            return 1;
        } else {
            return 0;
        }
    }
    else{
        ZDialog dlg(fee,nullptr);
        if (dlg.exec() == QDialog::Accepted) {
            return 1;
        } else {
            return 0;
        }
    }

}






void Patient::on_listWidget_itemClicked(QListWidgetItem *item)
{
    rollback();
    QString text = item->text(); // 获取点击条目的文字

    if (text == "个人信息管理") {
        ui->stackedWidget->setCurrentIndex(0);

    }
    else if (text == "号源查询与预约") {
        ui->stackedWidget->setCurrentIndex(2);

    }
    else if (text == "科室医生查询") {
        ui->stackedWidget->setCurrentIndex(3);

    }
    else if (text == "订单查询") {
        quaryorder();
        ui->stackedWidget->setCurrentIndex(4);

    }
    else if (text == "预约挂号") {
        ui->stackedWidget->setCurrentIndex(1);

    }
    else {
        ui->stackedWidget->setCurrentIndex(5);

    }
}








//保存
void Patient::on_pushButton_save_clicked()
{
    qDebug()<<m_id;
    // 1. 从界面获取输入内容
    QString name = ui->lineEdit_name->text().trimmed();
    QString gender = ui->comboBox_sex->currentText();
    QString age = ui->lineEdit_age->text().trimmed();
    QString phone = ui->lineEdit_phone->text().trimmed();
    QString address = ui->lineEdit_adr->text().trimmed();
    qDebug() <<gender<< "性别长度：" << gender.length();
    // 2. 简单校验（防止必填项为空）
    if (name.isEmpty() || phone.isEmpty()) {
        QMessageBox::warning(this, "提示", "姓名和电话不能为空！");
        return;
    }
    if (phone.length()!=11) {
        QMessageBox::critical(this, "错误", "保存失败，输入的信息不合理，请检查");
        return;
    }



    QSqlQuery query;
    // 使用 UPDATE 语句，通过 WHERE 子句锁定当前用户
    query.prepare("UPDATE patient SET Pat_name = :name, Pat_gender = :gender, "
                  "Pat_age = :age, Pat_phone = :phone, Pat_address = :address "
                  "WHERE Pat_id = :id");

    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":age", age);
    query.bindValue(":phone", phone);
    query.bindValue(":address", address);
    query.bindValue(":id", m_id); // 锁定当前登录的人

    if (query.exec()) {
        QMessageBox::information(this, "成功", "个人信息保存成功！");
    } else {
        qDebug() << "保存失败：" << query.lastError().text();
        QMessageBox::critical(this, "错误", "保存失败，输入的信息不合理，请检查");
    }
}


void Patient::on_pushButton_return_clicked()
{
    if (QMessageBox::question(this, "退出", "确定要退出登录吗？") == QMessageBox::Yes) {
        // 2. 发射信号
        emit loginreturn();
        // 3. 关闭（或隐藏）当前主界面
        this->close();
    }
}

//2_查询
void Patient::on_pushButton_clicked()
{

    // --- 1. 初始化表格配置 (共 11 列) ---
    ui->tableWidget_2_show->setColumnCount(11);
    QStringList headers;
    headers << "号源编号" << "医生编号" << "医生姓名" << "医生职称"
            << "就诊日期" << "就诊时段" << "总号数" << "剩余号数"
            << "已预约数" << "挂号费用" << "号源状态";
    ui->tableWidget_2_show->setHorizontalHeaderLabels(headers);

    // 基础样式设置
    ui->tableWidget_2_show->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableWidget_2_show->horizontalHeader()->setStretchLastSection(true); // 最后一列自动填充
    ui->tableWidget_2_show->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2_show->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2_show->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );

    QString selectedDept = ui->comboBox_2_dept->currentText();
    if(selectedDept == "选择科室") {
        QMessageBox::critical(this, "错误", "请选择科室");
        return;
    }
    bool hideFull = ui->checkBox_2->isChecked();

    // --- 3. 编写 SQL 语句 (排除科室名称，选取其余字段) ---
    // 注意：字段名必须与你视图中的 AS 别名完全一致
    QString sql = "SELECT 号源编号, 医生编号, 医生姓名, 医生职称, "
                  "就诊日期, 就诊时段, 总号数, 剩余号数, "
                  "已预约数, 挂号费用, 号源状态 "
                  "FROM my_doctor_sources "
                  "WHERE 科室名称 = :deptName "
                  "AND 号源状态 != '已暂停'";

    if (hideFull) {
        sql += " AND 号源状态 = '可预约'";
    }
    sql += " ORDER BY 就诊日期 ASC, 就诊时段 ASC";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":deptName", selectedDept);

    // --- 4. 执行查询并填充数据 ---
    if (query.exec()) {
        ui->tableWidget_2_show->setRowCount(0);
        int row = 0;
        while (query.next()) {
            ui->tableWidget_2_show->insertRow(row);

            for(int col = 0; col < 11; ++col) {
                QString value = query.value(col).toString();             
                if(col == 10) { // 号源状态：如果是“已满”显示红色提醒
                    QTableWidgetItem *item = new QTableWidgetItem(value);
                    if(value == "已满") item->setForeground(Qt::red);
                    item->setTextAlignment(Qt::AlignCenter);
                    ui->tableWidget_2_show->setItem(row, col, item);
                    continue;
                }

                QTableWidgetItem *item = new QTableWidgetItem(value);
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_2_show->setItem(row, col, item);
            }
            row++;
        }

        if(row == 0) {
            QMessageBox::information(this, "提示", "当前条件下没有符合要求的号源");
        }
    } else {
        QMessageBox::warning(this, "数据库错误", query.lastError().text());
    }



}


void Patient::on_comboBox_3_q_currentTextChanged(const QString &deptName)
{
    if (deptName=="选择科室" ) {
        ui->textBrowser_3_intro->clear();
        ui->tableWidget_3_q->setRowCount(0);
        return ;
    }
    if (deptName.isEmpty() ) {
        QMessageBox::critical(this, "错误", "请选择科室    ");
        return ;
    }

    // --- 第一部分：查询科室详情 ---
    QSqlQuery queryDept;
    queryDept.prepare("SELECT Dep_intro, Dep_location FROM department WHERE Dep_name = :name");
    queryDept.bindValue(":name", deptName);

    if (queryDept.exec() && queryDept.next()) {
        QString fullText = "科室简介：" + queryDept.value(0).toString()+ "\n" + "科室位置：" + queryDept.value(1).toString();
        ui->textBrowser_3_intro->setText(fullText);
    }

    // --- 第二部分：查询该科室下的医生详情 ---
    // 这里需要联合查询 Doctors 和 Departments 表
    ui->tableWidget_3_q->setRowCount(0); // 清空旧数据

    QSqlQuery queryDoc;
    QString sql = "SELECT d.Doc_name, d.Doc_title, d.Doc_major, d.Doc_phone,d.Doc_status "
                  "FROM doctor d "
                  "JOIN department dept ON d.Dep_id = dept.Dep_id "
                  "WHERE dept.Dep_name = :deptName";

    queryDoc.prepare(sql);
    queryDoc.bindValue(":deptName", deptName);




    ui->tableWidget_3_q->setColumnCount(5);

    // 定义表头文字
    QStringList headers;
    headers << "医生" << "职称" << "擅长领域" << "联系电话" << "坐诊状态";

    // 设置表头
    ui->tableWidget_3_q->setHorizontalHeaderLabels(headers);

    // --- 样式美化（可选） ---

    // 1. 让表头自适应内容宽度
    ui->tableWidget_3_q->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // 2. 最后一列（通常是医嘱，文字较多）拉伸填充剩余空间
    ui->tableWidget_3_q->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);

    // // 3. 设置表头高亮和交替行颜色（增强可读性）
    // ui->tableWidget_0->setAlternatingRowColors(true);
    // ui->tableWidget_0->setStyleSheet("alternate-background-color: #f5faff; background-color: white;");

    // 4. 禁止编辑（护士站通常只读）
    ui->tableWidget_3_q->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 5. 选中整行
    ui->tableWidget_3_q->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_3_q->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );

    if (queryDoc.exec()) {
        int row = 0;
        while (queryDoc.next()) {
            ui->tableWidget_3_q->insertRow(row);
            ui->tableWidget_3_q->setItem(row, 0, new QTableWidgetItem(queryDoc.value(0).toString()));
            ui->tableWidget_3_q->setItem(row, 1, new QTableWidgetItem(queryDoc.value(1).toString()));
            ui->tableWidget_3_q->setItem(row, 2, new QTableWidgetItem(queryDoc.value(2).toString()));
            ui->tableWidget_3_q->setItem(row, 3, new QTableWidgetItem(queryDoc.value(3).toString()));
            ui->tableWidget_3_q->setItem(row, 4, new QTableWidgetItem(queryDoc.value(4).toString()));
            row++;
        }
    } else {
        qDebug() << "查询医生详情失败：" << queryDoc.lastError().text();
    }
}


void Patient::on_comboBox_1_1_currentTextChanged(const QString &deptName)
{
    //查询医生表，把deptName里的医生都加到下拉列表里
    // 1. 防止空操作
    if (deptName.isEmpty() ) {
        QMessageBox::critical(this, "错误", "请选择科室    ");
        return;
    }

    // 2. 清空医生下拉列表
    ui->comboBox_1_2->clear();
    ui->comboBox_1_2->addItem("选择医生");

    // 3. 执行查询
    // 方案：通过联合查询，根据科室名字直接找医生
    QSqlQuery query;
    QString sql = "SELECT d.Doc_name "
                  "FROM doctor d "
                  "JOIN department dept ON d.Dep_id = dept.Dep_id "
                  "WHERE dept.Dep_name = :deptName";

    query.prepare(sql);
    query.bindValue(":deptName", deptName);

    if (query.exec()) {
        while (query.next()) {
            QString docName = query.value(0).toString();
            ui->comboBox_1_2->addItem(docName);
        }
        qDebug() << "医生列表更新成功，所属科室：" << deptName;
    } else {
        qDebug() << "查询医生失败：" << query.lastError().text();
    }
}


void Patient::on_pushButton_1_q_clicked()
{

    // 1. 获取界面输入
    QString deptName = ui->comboBox_1_1->currentText();
    QString docName = ui->comboBox_1_2->currentText();
    QString selectedDate = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString selectedTime = ui->comboBox_1_time->currentText();

    // 2. 基本校验（同前）
    if (deptName.contains("选择") || docName.contains("选择")) {
        QMessageBox::warning(this, "提示", "请完整选择科室、医生及就诊时间！");
        return;
    }

    // 3. 先通过名字和时间获取 Sou_id (存储过程需要这个输入参数)
    QSqlQuery query;
    query.prepare("SELECT Sou_id FROM source s "
                  "JOIN doctor d ON s.Doc_id = d.Doc_id "
                  "JOIN department dept ON s.Dep_id = dept.Dep_id "
                  "WHERE dept.Dep_name = :deptName AND d.Doc_name = :docName "
                  "AND s.Sou_date = :sDate AND s.Sou_time = :sTime");
    query.bindValue(":deptName", deptName);
    query.bindValue(":docName", docName);
    query.bindValue(":sDate", selectedDate);
    query.bindValue(":sTime", selectedTime);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "未找到对应号源，请重新选择。");

        ui->comboBox_1_1->setCurrentIndex(0);
        ui->comboBox_1_2->clear();
        ui->comboBox_1_2->addItem("选择医生");
        ui->comboBox_1_time->setCurrentIndex(-1);

        // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
        ui->dateEdit->setDate(QDate::currentDate());

        return;
    }
    int souId = query.value(0).toInt();






    // 4. 调用存储过程 1：sp_patient_register
    // 参数说明：IN p_pat_id, IN p_sou_id, OUT p_result_code, OUT p_result_msg, OUT p_ord_id
    QSqlQuery procRegister;
    procRegister.prepare("CALL sp_patient_register(:pid, :sid, @res_code, @res_msg, @oid)");
    procRegister.bindValue(":pid", m_id);
    procRegister.bindValue(":sid", souId);

    if (!procRegister.exec()) {
        QMessageBox::critical(this, "系统错误", "无法调用挂号程序：" + procRegister.lastError().text());

        ui->comboBox_1_1->setCurrentIndex(0);
        ui->comboBox_1_2->clear();
        ui->comboBox_1_2->addItem("选择医生");
        ui->comboBox_1_time->setCurrentIndex(-1);

        // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
        ui->dateEdit->setDate(QDate::currentDate());
        return;
    }

    // 获取存储过程的输出参数
    QSqlQuery resQuery("SELECT @res_code, @res_msg, @oid");
    resQuery.next();
    int resCode = resQuery.value(0).toInt();
    QString resMsg = resQuery.value(1).toString();
    int orderId = resQuery.value(2).toInt();

    if (resCode != 0) {
        QMessageBox::warning(this, "预约失败", resMsg+"        "); // 这里会显示“号源已满”或“重复预约”等

        ui->comboBox_1_1->setCurrentIndex(0);
        ui->comboBox_1_2->clear();
        ui->comboBox_1_2->addItem("选择医生");
        ui->comboBox_1_time->setCurrentIndex(-1);

        // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
        ui->dateEdit->setDate(QDate::currentDate());
        return;
    }

    // 5. 预约成功，询问支付及支付方式
    QMessageBox msgBox;
    msgBox.setText("预约成功！订单号：" + QString::number(orderId));
    msgBox.setInformativeText("请选择支付方式，或稍后支付。");
    QPushButton *wxBtn = msgBox.addButton("微信支付", QMessageBox::AcceptRole);
    QPushButton *aliBtn = msgBox.addButton("支付宝支付", QMessageBox::AcceptRole);
    QPushButton *cancelBtn = msgBox.addButton("稍后支付", QMessageBox::RejectRole);

    msgBox.exec();

    QString payType = "";
    if (msgBox.clickedButton() == wxBtn) payType = "微信";
    else if (msgBox.clickedButton() == aliBtn) payType = "支付宝";
    else {

        ui->comboBox_1_1->setCurrentIndex(0);
        ui->comboBox_1_2->clear();
        ui->comboBox_1_2->addItem("选择医生");
        ui->comboBox_1_time->setCurrentIndex(-1);

        // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
        ui->dateEdit->setDate(QDate::currentDate());

        return;
    }

    // 6. 调用存储过程 2：sp_pay_order
    // 参数说明：IN p_ord_id, IN p_pay_type, OUT p_result_code, OUT p_result_msg
    QSqlQuery procPay;
    procPay.prepare("CALL sp_pay_order(:oid, :ptype, @p_res_code, @p_res_msg)");
    procPay.bindValue(":oid", orderId);
    procPay.bindValue(":ptype", payType);

    if (procPay.exec()) {
        QSqlQuery payResQuery("SELECT @p_res_code, @p_res_msg");
        payResQuery.next();
        if (payResQuery.value(0).toInt() == 0) {
            QMessageBox::information(this, "成功", "支付完成，请准时就诊！");
        } else {
            QMessageBox::warning(this, "支付失败", payResQuery.value(1).toString());
        }
    }
    qDebug()<<"重置";
    // 1. 下拉框 (QComboBox) 恢复到未选中状态（索引设为 -1）
    // 或者使用 ui->comboBox_1_1->setCurrentIndex(0) 恢复到第一个默认选项
    ui->comboBox_1_1->setCurrentIndex(0);
    ui->comboBox_1_2->setCurrentIndex(0);
    ui->comboBox_1_time->setCurrentIndex(-1);

    // 2. 日期控件 (QDateEdit) 恢复为当前系统日期
    ui->dateEdit->setDate(QDate::currentDate());

}


void Patient::on_pushButton_5_clicked()
{
    //判断用户输入的旧密码，新密码是否为空，为空报错
    //在patient表找该用户的id，判断是否和旧密码相同，不同报错
    //是否确认修改，是，修改数据库
    // 1. 获取输入并去空格
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
    query.prepare("SELECT Pat_pwd FROM patient WHERE Pat_id = :id");
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
        updateQuery.prepare("UPDATE patient SET Pat_pwd = :newPwd WHERE Pat_id = :id");
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


void Patient::on_pushButton_4_tuikuan_clicked()
{
    //判断用户是否选中一行，否则报错
    //先询问用户是否确认取消订单
    //调用存储过程去取消订单
    // 1. 判断是否选中一行
    int currentRow = ui->tableWidget_4_q->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先在列表中选中要取消的订单！");
        return;
    }

    // 2. 获取订单编号（假设“订单编号”在第 0 列）
    QString orderId = ui->tableWidget_4_q->item(currentRow, 0)->text();
    // 获取当前登录患者 ID (假设存储在 m_id 中)
    QString patientId = m_id;

    // 3. 询问用户是否确认取消
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认取消",
                                  QString("您确定要取消订单 [%1] 吗？").arg(orderId),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) return;

    // 4. 调用存储过程 sp_cancel_order
    QSqlQuery query;
    query.prepare("CALL sp_cancel_porder(:oid, :pid, @res_code, @res_msg)");
    query.bindValue(":oid", orderId.toInt());
    query.bindValue(":pid", patientId);

    if (query.exec()) {
        // 获取输出参数
        QSqlQuery resQuery("SELECT @res_code, @res_msg");
        if (resQuery.next()) {
            int resCode = resQuery.value(0).toInt();
            QString resMsg = resQuery.value(1).toString();

            if (resCode == 0) {
                QMessageBox::information(this, "成功", "订单已成功取消，号源已释放。");

                QSqlQuery query;
                // 建议先删除关联数据（如果有外键约束），或者确保外键是 ON DELETE CASCADE
                query.prepare("DELETE FROM `pay` WHERE Ord_id = :id");
                query.bindValue(":id", orderId.toInt());
                query.exec();

                quaryorder();
            } else {
                // 显示存储过程返回的具体错误（如：已超过取消时间）
                QMessageBox::warning(this, "取消失败", resMsg);
            }
        }
    } else {
        QMessageBox::critical(this, "系统错误", "无法执行取消指令：" + query.lastError().text());
    }
}


void Patient::on_pushButton_4_pay_clicked()
{
    //用户是否选中某一行，没有报错
    //获取那一行的第七列的支付状态，如果是未支付，问他微信还是支付宝，获取第一列的订单号，更新order表
    //以及在pay表新增一行，否则告诉他已支付
    // 1. 判断是否选中行
    int currentRow = ui->tableWidget_4_q->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先在列表中选中要缴费的订单！");
        return;
    }

    // 2. 获取必要数据
    // 假设：第0列是订单号，第7列是下单时间，第8列是支付状态（请根据你视图的实际列索引调整）
    // 根据你之前的视图定义：0:订单编号, 7:挂号费用, 8:支付状态
    QString ord_id = ui->tableWidget_4_q->item(currentRow, 0)->text();
    double fee = ui->tableWidget_4_q->item(currentRow, 7)->text().toDouble();
    QString payStatus = ui->tableWidget_4_q->item(currentRow, 8)->text();
    QString ordStatus=ui->tableWidget_4_q->item(currentRow,9)->text();
    // 3. 检查支付状态
    if (payStatus != "未支付") {
        QMessageBox::information(this, "提示", "该订单已支付或已退款，无需重复操作。");
        return;
    }
    if (ordStatus == "已取消"||ordStatus == "已过期") {
        QMessageBox::information(this, "提示", "该订单已取消或已过期。            ");
        return;
    }

    // 4. 询问支付方式
    QMessageBox msgBox;
    msgBox.setWindowTitle("确认支付");
    msgBox.setText(QString("订单号：%1\n需支付金额：%2 元").arg(ord_id).arg(fee));
    msgBox.setInformativeText("请选择支付方式：");

    QPushButton *wxBtn = msgBox.addButton("微信", QMessageBox::AcceptRole);
    QPushButton *aliBtn = msgBox.addButton("支付宝", QMessageBox::AcceptRole);
    QPushButton *cancelBtn = msgBox.addButton("取消", QMessageBox::RejectRole);

    msgBox.exec();

    QString payType = "";
    if (msgBox.clickedButton() == wxBtn) {
        payType = "微信";
        if(zhifu(QString::number(fee, 'f', 2),0)!=1)
            return ;
    }
    else if (msgBox.clickedButton() == aliBtn) {
        payType = "支付宝";
        if(zhifu(QString::number(fee, 'f', 2),1)!=1)
            return ;
    }
    else return; // 用户点击了取消

    // 5. 数据库事务操作
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction(); // 开启事务

    QSqlQuery query;
    bool success = true;

    // A. 更新 order 表状态
    query.prepare("UPDATE `porder` SET Ord_paystatus = '已支付' WHERE Ord_id = :oid");
    query.bindValue(":oid", ord_id);
    if (!query.exec()) success = false;

    // B. 在 pay 表新增记录
    if (success) {
        query.prepare("INSERT INTO pay (Ord_id, Pat_id, Pay_amount, Pay_type, Pay_time) "
                      "VALUES (:oid, :pid, :amount, :ptype, NOW())");
        query.bindValue(":oid", ord_id);
        query.bindValue(":pid", m_id); // m_id 为当前患者编号
        query.bindValue(":amount", fee);
        query.bindValue(":ptype", payType);
        if (!query.exec()) success = false;
    }

    // 6. 结果处理
    if (success) {
        db.commit(); // 提交事务
        QMessageBox::information(this, "成功", "支付成功！");
        quaryorder();// 刷新表格显示
    } else {
        db.rollback(); // 回滚事务
        QMessageBox::critical(this, "失败", "支付处理过程中出错：" + query.lastError().text());
    }
}


void Patient::on_pushButton_2_yuyue_clicked()
{
    //先判断用户有没有选中一行，没有就提示
    // 然后从那行获取下面的数据
    // QString deptName
    // QString docName
    // QString selectedDate
    // QString selectedTime
    // 1. 获取当前选中的行号
    int currentRow = ui->tableWidget_2_show->currentRow();

    // 2. 判断用户有没有选中一行
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先从列表中选择一位医生进行挂号！");
        return;
    }
    //根据m_id查询patient表,看一下所有字段是否都填了，如果有没填的就报错告诉他哪个没填，密码一定填了，不用看了
    QSqlQuery mquery;
    // 1. 准备查询语句 (不查询密码，节省资源)
    mquery.prepare("SELECT Pat_name, Pat_gender, Pat_age, Pat_phone, Pat_card, Pat_address "
                  "FROM patient WHERE Pat_id = :id");
    mquery.bindValue(":id", m_id);

    if (mquery.exec()) {
        if (mquery.next()) {
            // 2. 定义字段名与中文含义的映射，方便报错
            QMap<QString, QString> fieldMap;
            fieldMap.insert("Pat_name", "姓名");
            fieldMap.insert("Pat_gender", "性别");
            fieldMap.insert("Pat_age", "年龄");
            fieldMap.insert("Pat_phone", "联系电话");
            fieldMap.insert("Pat_address", "联系地址");

            QStringList missingFields;

            // 3. 遍历检查每个字段
            QMapIterator<QString, QString> i(fieldMap);
            while (i.hasNext()) {
                i.next();
                QVariant val = mquery.value(i.key());

                // 判断逻辑：值为空、或者是空字符串
                if (val.isNull() || val.toString().trimmed().isEmpty()) {
                    missingFields << i.value();
                }
            }

            // 4. 如果有没填的，汇总报错
            if (!missingFields.isEmpty()) {
                QString errorMsg = "请先完善个人信息再进行预约      ";
                QMessageBox::warning(this, "完善信息提示", errorMsg);
                return ;
            } else {
                qDebug() << "信息完整，验证通过。";
            }
        } else {
            QMessageBox::critical(this, "错误", "未找到该患者账号信息！");
             return ;
        }
    } else {
        qDebug() << "数据库查询失败：" << mquery.lastError().text();
         return ;
    }





    // 3. 从选中的行中获取数据
    // 注意：这里的列索引必须和你前面 SELECT 出来的顺序完全对应
    // 根据之前的代码：0:医生姓名, 1:就诊日期, 2:就诊时段, 3:剩余号数, 4:挂号费用...

    QString docName      = ui->tableWidget_2_show->item(currentRow, 2)->text(); // 医生姓名
    QString selectedDate = ui->tableWidget_2_show->item(currentRow, 4)->text(); // 就诊日期
    QString selectedTime = ui->tableWidget_2_show->item(currentRow, 5)->text(); // 就诊时段
    QString fee = ui->tableWidget_2_show->item(currentRow, 9)->text(); // 就诊时段
    int souId        = ui->tableWidget_2_show->item(currentRow, 0)->text().toInt();
    // 特殊处理：deptName（科室名称）
    // 因为你在表格里隐藏了科室名称，所以直接从界面上的 ComboBox 获取最准确
    QString deptName = ui->comboBox_2_dept->currentText();

    // 4. 业务逻辑检查：如果剩余号数为0，虽然前面过滤了，但为了保险可以再加一层判断
    int remain = ui->tableWidget_2_show->item(currentRow, 7)->text().toInt();
    if (remain <= 0) {
        QMessageBox::critical(this, "错误", "该医生号源已满              ");
        return;
    }




    // 4. 调用存储过程 1：sp_patient_register
    // 参数说明：IN p_pat_id, IN p_sou_id, OUT p_result_code, OUT p_result_msg, OUT p_ord_id
    QSqlQuery procRegister;
    procRegister.prepare("CALL sp_patient_register(:pid, :sid, @res_code, @res_msg, @oid)");
    procRegister.bindValue(":pid", m_id);
    procRegister.bindValue(":sid", souId);

    if (!procRegister.exec()) {
        QMessageBox::critical(this, "系统错误", "无法调用挂号程序：" + procRegister.lastError().text());

        return;
    }

    // 获取存储过程的输出参数
    QSqlQuery resQuery("SELECT @res_code, @res_msg, @oid");
    resQuery.next();
    int resCode = resQuery.value(0).toInt();
    QString resMsg = resQuery.value(1).toString();
    int orderId = resQuery.value(2).toInt();

    if (resCode != 0) {
        QMessageBox::warning(this, "预约失败", resMsg+"        "); // 这里会显示“号源已满”或“重复预约”等

        return;
    }

    // 5. 预约成功，询问支付及支付方式
    QMessageBox msgBox;
    msgBox.setText("预约成功！订单号：" + QString::number(orderId));
    msgBox.setInformativeText("请选择支付方式，或稍后支付。");
    QPushButton *wxBtn = msgBox.addButton("微信支付", QMessageBox::AcceptRole);
    QPushButton *aliBtn = msgBox.addButton("支付宝支付", QMessageBox::AcceptRole);
    QPushButton *cancelBtn = msgBox.addButton("稍后支付", QMessageBox::RejectRole);

    msgBox.exec();

    QString payType = "";
    if (msgBox.clickedButton() == wxBtn) {
        payType = "微信";
        if(zhifu(fee,0)!=1)
            return ;
    }
    else if (msgBox.clickedButton() == aliBtn) {
        payType = "支付宝";
        if(zhifu(fee,1)!=1)
            return ;
    }
    else {

        ui->tableWidget_2_show->clearSelection();
        return;
    }

    // 6. 调用存储过程 2：sp_pay_order
    // 参数说明：IN p_ord_id, IN p_pay_type, OUT p_result_code, OUT p_result_msg
    QSqlQuery procPay;
    procPay.prepare("CALL sp_pay_order(:oid, :ptype, @p_res_code, @p_res_msg)");
    procPay.bindValue(":oid", orderId);
    procPay.bindValue(":ptype", payType);

    if (procPay.exec()) {
        QSqlQuery payResQuery("SELECT @p_res_code, @p_res_msg");
        payResQuery.next();
        if (payResQuery.value(0).toInt() == 0) {
            QMessageBox::information(this, "成功", "支付完成，请准时就诊！");
            on_pushButton_clicked();
            ui->tableWidget_2_show->clearSelection();
        } else {
            QMessageBox::warning(this, "支付失败", payResQuery.value(1).toString());
        }
    }

}


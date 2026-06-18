#include "doctor.h"
#include "ui_doctor.h"
#include<QMessageBox>
#include<QString>
#include<QSqlQuery>
#include<QSqlError>
doctor::doctor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::doctor)
{
    ui->setupUi(this);
    setWindowTitle("医院挂号系统 - 医生界面");
    ui->stackedWidget->setCurrentIndex(5);

    ui->tableWidget_7->verticalHeader()->setVisible(false);
    ui->tableWidget_7->setColumnCount(4);
    ui->tableWidget_7->hideColumn(0);
    // 2. 设置表头文字（对应你数据库中的 Pre_drug, Pre_dosage, Pre_day）
    QStringList headers;
    headers << "id"<<"药品名称" << "用药剂量" << "服用天数";
    ui->tableWidget_7->setHorizontalHeaderLabels(headers);
    // QObject::connect(ui->tableWidget_7, &QTableWidget::cellChanged, [=](int row, int column) {
    //     // 如果当前编辑的是最后一行，且格子里不是空的
    //     if (column>1&&row == ui->tableWidget_7->rowCount() - 1) {
    //         QString text = ui->tableWidget_7->item(row, column)->text();
    //         if (!text.isEmpty()) {
    //             int newRow = ui->tableWidget_7->rowCount();
    //             ui->tableWidget_7->insertRow(newRow);
    //             // 初始化新行的格子，防止报错
    //             QTableWidgetItem *idItem = new QTableWidgetItem("-1");
    //             ui->tableWidget_7->setItem(newRow, 0, idItem);
    //             for(int j = 1; j < 4; ++j) {
    //                 ui->tableWidget_7->setItem(newRow, j, new QTableWidgetItem(""));
    //             }
    //         }
    //     }
    // });
    // 5. 选中整行
    ui->tableWidget_7->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_7->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );




    // 1. 设置列数（对应 SQL 中的 10 个字段）
    ui->tableWidget_1->setColumnCount(11);

    // 2. 定义表头文字
    QStringList headers2;
    headers2 << "预约编号" << "患者账号"  << "姓名" << "性别"
             << "年龄" << "联系电话"  <<"就诊日期"<<"订单状态"<<"就诊记录" << "病历备注"<<"患者就诊状态";

    ui->tableWidget_1->setHorizontalHeaderLabels(headers2);

    // 3. 基础外观设置
    ui->tableWidget_1->verticalHeader()->setVisible(false);      // 隐藏左侧行号

    // 5. 选中整行
    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_1->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );
    ui->tableWidget_1->setEditTriggers(QAbstractItemView::NoEditTriggers);  // 禁止双击修改内容


    ui->pushButton_7_add->setIcon(QIcon(":/image/add.png")); // 替换成你真实的资源路径
    //ui->pushButton_7_add->setIconSize(QSize(24, 24));       // 设置图标显示大小
    ui->pushButton_7_add->setToolTip("新增处方行");            // 鼠标悬停提示

    // --- 设置删除按钮 (-) ---
    ui->pushButton_7_del->setIcon(QIcon(":/image/sub.png")); // 替换成你真实的资源路径
    //ui->pushButton_7_del->setIconSize(QSize(24, 24));
    ui->pushButton_7_del->setToolTip("删除选中行");
}

doctor::~doctor()
{
    delete ui;
}

void doctor::inital(QString id)
{




    ui->listWidget->clearSelection();
    updatepermit();
    ui->stackedWidget->setCurrentIndex(5);
    m_id=id.toInt();
    ui->label_id->setText("欢迎您："+id);


    // 1. 获取当前日期
    QDate today = QDate::currentDate();
    QSqlQuery query;
    QString paramName="号源发布提前天数";
    int days;
    query.prepare("SELECT Par_value FROM system_param WHERE Par_name = :pname");
    query.bindValue(":pname", paramName);

    if (query.exec() && query.next()) {
        days = query.value(0).toInt();
    }

    QDate mDate = today.addDays(1);
    QDate maxDate = today.addDays(days);
    // 3. 设置 QDateEdit 的范围
    ui->dateEdit_0_d->setMinimumDate(mDate);   // 只能选以后
    ui->dateEdit_0_d->setMaximumDate(maxDate); // 只能选 7 天之内

    // 4. 设置默认显示的日期为今天
    ui->dateEdit_0_d->setDate(mDate);

    // 5. (可选) 弹出日历窗口，让用户选择更方便
    ui->dateEdit_0_d->setCalendarPopup(true);

}

// void doctor::initialtable()
// {
//     int currentRows = ui->tableWidget_7->rowCount();
//     ui->tableWidget_7->setRowCount(currentRows + 15) ;
//     for (int i = currentRows; i < currentRows+15; ++i) {
//         // 重要：给每一行的隐藏列设置默认值 "-1"
//         // 这样医生直接在这些行打字，提交时程序就知道这是要 INSERT 的新药
//         QTableWidgetItem *idItem = new QTableWidgetItem("-1");
//         ui->tableWidget_7->setItem(i, 0, idItem);

//         // 初始化其他列，防止程序访问空指针崩溃
//         ui->tableWidget_7->setItem(i, 1, new QTableWidgetItem(""));
//         ui->tableWidget_7->setItem(i, 2, new QTableWidgetItem(""));
//         ui->tableWidget_7->setItem(i, 3, new QTableWidgetItem(""));
//     }
// }



void doctor::initalhaoyuan()
{
    //获取视图中医生id是m_id是的所有信息，其中，第2，3，4，5列隐藏显示在tablewidgt

    // 1. 设置表头（必须与视图定义的 AS 别名顺序完全一致）
    QStringList headers;
    headers << "号源编号" << "医生编号" << "医生姓名" << "医生职称"
            << "科室名称" << "就诊日期" << "就诊时段" << "总号数"
            << "剩余号数" << "已预约数" << "挂号费用" << "号源状态";

    ui->tableWidget_haomesg->setColumnCount(headers.size());
    ui->tableWidget_haomesg->setHorizontalHeaderLabels(headers);

    // 2. 查询视图并过滤医生 ID
    QSqlQuery query;

    query.prepare("SELECT * FROM my_doctor_sources WHERE `医生编号` = :mid");
    query.bindValue(":mid", m_id); // m_id 为当前登录医生的 ID

    if (query.exec()) {
        ui->tableWidget_haomesg->setRowCount(0);
        int row = 0;
        while (query.next()) {
            ui->tableWidget_haomesg->insertRow(row);
            for (int col = 0; col < headers.size(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                item->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget_haomesg->setItem(row, col, item);
            }
            row++;
        }

        // 3. 隐藏第 2, 3, 4, 5 列 (索引 1, 2, 3, 4)
        // 如果你是想隐藏：医生编号、医生姓名、医生职称、科室名称
        ui->tableWidget_haomesg->setColumnHidden(1, true);
        ui->tableWidget_haomesg->setColumnHidden(2, true);
        ui->tableWidget_haomesg->setColumnHidden(3, true);
        ui->tableWidget_haomesg->setColumnHidden(4, true);


        // 4. 界面美化
        ui->tableWidget_haomesg->resizeColumnsToContents();
        ui->tableWidget_haomesg->horizontalHeader()->setStretchLastSection(true);
        // 5. 选中整行
        ui->tableWidget_haomesg->setSelectionBehavior(QAbstractItemView::SelectRows);
        // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
        ui->tableWidget_haomesg->setStyleSheet(
            "QTableWidget::item:selected {"
            "    background-color: #3399FF;" // 经典的天蓝色
            "    color: white;"              // 选中时文字变为白色，保证清晰
            "}"
            );
    } else {
        QMessageBox::critical(this, "错误", "无法获取排班视图：" + query.lastError().text());
    }
}

void doctor::rollback()
{

    ui->dateEdit_0_d->setDate(QDate::currentDate().addDays(1));
    ui->comboBox_0_t->setCurrentIndex(-1);
    ui->spinBox_0_amount->setValue(5);
    ui->lineEdit_2_beizhu->clear();

    ui->lineEdit_2_number->clear();
    ui->lineEdit_2_res->clear();

    ui->lineEdit_3->clear();
    ui->textEdit_3->clear();

    ui->tableWidget_7->setRowCount(0);
    ui->lineEdit_7->clear();

    ui->checkBox_2->setChecked(false);

    ui->lineEdit_5_old_2->clear();
    ui->lineEdit_5_new_2->clear();


}

void doctor::updatepermit()
{
    QString roleName="医生";
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

bool doctor::queueday(int ordid)
{
//查询视图，根据ordid,找到就诊日期如果不等于当天，就提示错误
    QSqlQuery query;
    // 1. 准备查询语句，根据预约编号从视图中找就诊日期
    // 注意：这里的视图名称请替换为你数据库里真实的视图名字
    query.prepare("SELECT 就诊日期 FROM my_patient_orders WHERE 预约编号 = :id");
    query.bindValue(":id", ordid);

    if (query.exec()) {
        if (query.next()) {
            // 2. 获取数据库中的就诊日期
            QDate souDate = query.value("就诊日期").toDate();
            // 3. 获取当前系统日期
            QDate today = QDate::currentDate();

            // 4. 比对日期
            if (souDate != today) {
                // 如果日期不是今天，弹出错误提示
                QMessageBox::critical(this, "就诊校验失败",
                                      QString("该患者预约的就诊日期为 %1，不是今天（%2），请确认是否输入错误！")
                                          .arg(souDate.toString("yyyy-MM-dd"))
                                          .arg(today.toString("yyyy-MM-dd")));

                // 这里可以根据业务逻辑决定是否抛出异常或返回 false
                return false;
            } else {
                qDebug() << "日期校验通过，准许就诊。";
                return true;
            }
        } else {
            QMessageBox::warning(this, "查询失败", "未找到对应的预约记录。");
            return false;
        }
    } else {
        qDebug() << "查询视图出错：" << query.lastError().text();
        return false;
    }
}




void doctor::on_listWidget_itemClicked(QListWidgetItem *item)
{
    rollback();
    QString text = item->text().trimmed(); // 获取点击条目的文字

    if (text == "发布号源") {
        ui->stackedWidget->setCurrentIndex(0);

    }
    else if (text == "查看患者信息") {
        on_checkBox_2_checkStateChanged(Qt::CheckState::Unchecked);
        ui->stackedWidget->setCurrentIndex(1);

    }
    else if (text == "写病历") {
        ui->stackedWidget->setCurrentIndex(2);

    }
    else if (text == "医嘱管理") {
        ui->stackedWidget->setCurrentIndex(3);

    }
    else if (text == "开药") {
        ui->tableWidget_7->setRowCount(0);
        ui->stackedWidget->setCurrentIndex(6);

    }
    else if (text == "修改密码") {
        ui->stackedWidget->setCurrentIndex(7);

    }
    else  {
        initalhaoyuan();
        ui->stackedWidget->setCurrentIndex(4);

    }

}








// void doctor::on_pushButton__0_q_clicked()
// {
//     // //根据号源编号，然后看看那个号源是不是这个医生发布的，是就把信息填入界面中
//     // // 1. 获取输入的号源编号
//     // QString souIdStr = ui->lineEdit_0_s->text().trimmed();
//     // if (souIdStr.isEmpty()) {
//     //     QMessageBox::warning(this, "提示", "请输入号源编号！");
//     //     return;
//     // }
//     // int souId = souIdStr.toInt();

//     // // 2. 查询数据库
//     // // 约束条件：Sou_id 必须匹配，且 Doc_id 必须是当前登录的医生
//     // QSqlQuery query;
//     // query.prepare("SELECT Sou_date, Sou_time, Sou_remain, Sou_fee FROM source "
//     //               "WHERE Sou_id = :sid AND Doc_id = :did");
//     // query.bindValue(":sid", souId);
//     // query.bindValue(":did", m_id); // 假设登录时保存了当前医生ID

//     // if (query.exec()) {
//     //     if (query.next()) {
//     //         // 3. 查到了：将数据填入界面控件
//     //         QDate sDate = query.value("Sou_date").toDate();
//     //         QString sTime = query.value("Sou_time").toString();
//     //         int sRemain = query.value("Sou_remain").toInt();
//     //         double sFee = query.value("Sou_fee").toDouble();

//     //         // 填入日期
//     //         ui->dateEdit_0_d->setDate(sDate);

//     //         // 填入时段 (设置 ComboBox 的当前文字)
//     //         int timeIndex = ui->comboBox_0_t->findText(sTime);
//     //         if (timeIndex != -1) {
//     //             ui->comboBox_0_t->setCurrentIndex(timeIndex);
//     //         } else {
//     //             // 如果下拉框里没有这个时段，手动添加一个，防止显示空白
//     //             ui->comboBox_0_t->addItem(sTime);
//     //             ui->comboBox_0_t->setCurrentText(sTime);
//     //         }

//     //         // 填入号数和费用
//     //         ui->spinBox_0_amount->setValue(sRemain);
//     //         ui->doubleSpinBox_0_fee->setValue(sFee);


//     //         QMessageBox::information(this, "成功", "已加载号源信息         ");

//     //     } else {
//     //         // 没查到或者不是该医生的号源
//     //         QMessageBox::warning(this, "错误", "未找到该编号的号源信息，或您无权查看他人发布的号源信息。");
//     //     }
//     // } else {
//     //     QMessageBox::critical(this, "数据库错误", query.lastError().text());
//     // }
// }


// void doctor::on_pushButton_0_modify_clicked()
// {
//     // QString souIdStr = ui->lineEdit_0_s->text().trimmed();
//     // if (souIdStr.isEmpty()) {
//     //     QMessageBox::warning(this, "提示", "请输入号源编号！");
//     //     return;
//     // }
//     // int souId = souIdStr.toInt();
//     // // 1. 获取界面输入
//     // QString dateStr = ui->dateEdit_0_d->date().toString("yyyy-MM-dd");
//     // QString timeStr = ui->comboBox_0_t->currentText();
//     // int remain = ui->spinBox_0_amount->value();
//     // double fee = ui->doubleSpinBox_0_fee->value();

//     // // 假设当前医生的 ID 存在变量 m_doctorId 中
//     // int docId = m_id;



//     // // --- 逻辑 A：修改已有号源 ---

//     // // 1. 先查找该医生在这一天、这个时段是否真的有号源
//     // QSqlQuery query;
//     // query.prepare("SELECT Sou_total, Sou_remain FROM source "
//     //               "WHERE Sou_id = :sid");
//     // query.bindValue(":sid", souId);


//     // if (query.exec() && query.next()) {
//     //     int oldTotal = query.value("Sou_total").toInt();
//     //     int oldRemain = query.value("Sou_remain").toInt();


//     //     int newtotal =oldTotal-oldRemain+remain;

//     //     // 4. 执行更新
//     //     QSqlQuery updateQuery;
//     //     updateQuery.prepare("UPDATE source SET Sou_total = :total, Sou_remain = :remain, Sou_fee = :fee, Sou_date = :date, Sou_time = :time "
//     //                         "WHERE Sou_id = :sid");
//     //     updateQuery.bindValue(":total", newtotal);
//     //     updateQuery.bindValue(":remain", remain);
//     //     updateQuery.bindValue(":fee", fee);
//     //     updateQuery.bindValue(":sid", souId);
//     //     updateQuery.bindValue(":date", dateStr);
//     //     updateQuery.bindValue(":time", timeStr);

//     //     if (updateQuery.exec()) {
//     //         QMessageBox::information(this, "成功", "号源信息已成功修改！");
//     //     } else {
//     //         QMessageBox::critical(this, "失败", "数据库更新失败：" + updateQuery.lastError().text());
//     //     }

//     // }

// }
void doctor::on_pushButton_0_fabu_clicked()
{
    // 1. 获取界面输入
    QString dateStr = ui->dateEdit_0_d->date().toString("yyyy-MM-dd");
    QString timeStr = ui->comboBox_0_t->currentText();
    int total = ui->spinBox_0_amount->value();
    //查询doctor，获取医生的title,再查询参数表，根据不同的tile对应不同的参数名，其中挂号费用就是参数额
    QSqlQuery query;
    QString title = "";

    // 1. 先查医生的职称
    query.prepare("SELECT Doc_title FROM doctor WHERE Doc_id = :did");
    query.bindValue(":did", m_id);
    if (query.exec() && query.next()) {
        title = query.value(0).toString();
    }

    // 2. 根据职称映射到参数表里的 Par_name
    QString paramName = "";
    if (title.contains("主任") || title.contains("副主任")) {
        paramName = "专家挂号费用";
    } else if (title.contains("主治")) {
        paramName = "普通挂号费用";
    } else if (title.contains("特需")) {
        paramName = "特需挂号费用";
    } else {
        paramName = "普通挂号费用"; // 默认保底
    }

    // 3. 从系统参数表获取具体金额
    double fee = 0.0;
    query.prepare("SELECT Par_value FROM system_param WHERE Par_name = :pname");
    query.bindValue(":pname", paramName);

    if (query.exec() && query.next()) {
        fee = query.value(0).toDouble();
    }


    if(dateStr.isEmpty()||timeStr.isEmpty()||total<=0){
        QMessageBox::warning(this, "输入错误", "请输入准确的号源信息！           ");

    }
    QSqlQuery procQuery;
    procQuery.prepare("CALL sp_doctor_publish_source(:did, :sdate, :stime, :stotal, :sfee, @res_code, @res_msg, @sid)");
    procQuery.bindValue(":did", m_id);
    procQuery.bindValue(":sdate", dateStr);
    procQuery.bindValue(":stime", timeStr);
    procQuery.bindValue(":stotal", total);
    procQuery.bindValue(":sfee", fee);
    qDebug()<<"total"<<total;
    if (procQuery.exec()) {
        // 获取输出参数
        QSqlQuery resQuery("SELECT @res_code, @res_msg, @sid");
        resQuery.next();
        int resCode = resQuery.value(0).toInt();
        QString resMsg = resQuery.value(1).toString();
        QString am = resQuery.value(2).toString();
        if (resCode == 0) {
            QMessageBox::information(this, "成功", "号源:"+am+" 发布成功");
            ui->dateEdit_0_d->setDate(QDate::currentDate().addDays(1));
            ui->comboBox_0_t->setCurrentIndex(-1);
            ui->spinBox_0_amount->setValue(5);
        } else {
            QMessageBox::warning(this, "发布失败", resMsg);
        }
    } else {
        QMessageBox::critical(this, "系统错误", "无法连接存储过程");
    }
}


void doctor::on_pushButton_return_clicked()
{
    if (QMessageBox::question(this, "退出", "确定要退出登录吗？") == QMessageBox::Yes) {
        // 2. 发射信号
        emit loginreturn();
        // 3. 关闭（或隐藏）当前主界面
        this->close();
    }

}


void doctor::on_pushButton_2_save_clicked()
{
    //先判断用户有没有输入完（订单编号，诊断结果，备注，药品名称，计量），调用存储函数填写完medical，然后再填prescription
    // 1. 获取界面输入
    QString ordIdStr = ui->lineEdit_2_number->text().trimmed(); // 订单编号
    QString diagnose = ui->lineEdit_2_res->toPlainText().trimmed(); // 诊断结果
    QString note = ui->lineEdit_2_beizhu->toPlainText().trimmed(); // 备注
    //QString drugName = ui->lineEdit_2_name->text().trimmed(); // 药品名称
    //QString dosage = ui->lineEdit_2_shuliang->text().trimmed(); // 剂量

    // 2. 判断输入是否完整 (非空校验)
    if (ordIdStr.isEmpty() || diagnose.isEmpty() ) {
        QMessageBox::warning(this, "提示", "请完整填写患者病历信息！");
        return;
    }
    int ordId = ordIdStr.toInt();
    if(!queueday(ordId)){
        ui->lineEdit_2_beizhu->clear();
        ui->lineEdit_2_number->clear();
        ui->lineEdit_2_res->clear();

        return ;
    }
    // 3. 调用存储过程 sp_complete_visit
    // 参数：IN p_ord_id, IN p_doc_id, IN p_med_diagnose, IN p_med_note, OUT p_res_code, OUT p_res_msg, OUT p_med_id
    QSqlQuery procQuery;
    procQuery.prepare("CALL sp_complete_visit(:oid, :did, :diag, :note, @res_code, @res_msg, @mid)");
    procQuery.bindValue(":oid", ordId);
    procQuery.bindValue(":did", m_id); // 当前医生ID
    procQuery.bindValue(":diag", diagnose);
    procQuery.bindValue(":note", note);

    if (!procQuery.exec()) {
        QMessageBox::critical(this, "数据库错误", "调用存储过程失败：" + procQuery.lastError().text());
        return;
    }

    // 获取存储过程返回结果
    QSqlQuery resQuery("SELECT @res_code, @res_msg, @mid");
    resQuery.next();
    int resCode = resQuery.value(0).toInt();
    QString resMsg = resQuery.value(1).toString();
    int medId = resQuery.value(2).toInt();

    if (resCode != 0) {
        QMessageBox::warning(this, "操作失败", resMsg);
        ui->lineEdit_2_res->clear();
        ui->lineEdit_2_beizhu->clear();
        ui->lineEdit_2_number->clear();
        return;
    }
QMessageBox::information(this, "提交成功", "该患者的病历记录已更新，您现在可以进行后续的开药操作。");
    // 5. 可选：清空界面方便下次录入
    ui->lineEdit_2_beizhu->clear();
    ui->lineEdit_2_number->clear();
    ui->lineEdit_2_res->clear();

    // 刷新患者列表表格
    on_checkBox_2_checkStateChanged(Qt::CheckState::Unchecked);
}


void doctor::on_pushButton_3_look_clicked()
{
    //判断用户有没有输入订单编号，在medical根据订单编号，找病例编号，根据病例编号在advice找，找不到要报错，找到医嘱内容显示出来text
    // 1. 获取输入的订单编号
    QString ordIdStr = ui->lineEdit_3->text().trimmed();
    if (ordIdStr.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号以查询医嘱！");
        return;
    }

    // 2. 执行联合查询
    // 逻辑：通过 order 表关联 medical 表，再关联 advice 表
    // 如果你的 advice 表直接关联了 Med_id，可以用下面的 JOIN 语句
    QSqlQuery query;
    QString sql = "SELECT a.Adv_content "
                  "FROM medical m "
                  "JOIN advice a ON m.Med_id = a.Med_id "
                  "WHERE m.Ord_id = :oid";

    query.prepare(sql);
    query.bindValue(":oid", ordIdStr.toInt());

    if (query.exec()) {
        if (query.next()) {
            // 3. 找到医嘱：显示到 textEdit 或 label 中
            QString adviceContent = query.value("Adv_content").toString();
            ui->textEdit_3->setPlainText(adviceContent);

            QMessageBox::information(this, "查询成功", "已加载该患者的医嘱信息。");
        } else {
            // 4. 找不到的情况（可能是没写病历，或者病历下没写医嘱）
            // 进一步检查是为了给用户更精准的提示
            QSqlQuery checkMed;
            checkMed.prepare("SELECT Med_id FROM medical WHERE Ord_id = :oid");
            checkMed.bindValue(":oid", ordIdStr.toInt());
            checkMed.exec();

            if (!checkMed.next()) {
                QMessageBox::warning(this, "查询失败", "该患者尚未创建病历，请先保存就诊记录！");
            } else {
                QMessageBox::information(this, "提示", "该患者的病历暂无关联的医嘱内容。");
                ui->textEdit_3->clear();
            }
        }
    } else {
        QMessageBox::critical(this, "错误", "数据库查询出错：" + query.lastError().text());
    }
}


void doctor::on_pushButton_3_mod_clicked()
{
    //判断用户有没有输入订单编号，在medical根据订单编号，找病例编号，根据病例编号在advice找，找不到要报错，找到把用户输入的医嘱写进数据库
    // 1. 获取输入
    QString ordIdStr = ui->lineEdit_3->text().trimmed();
    QString advContent = ui->textEdit_3->toPlainText().trimmed();

    // 2. 非空校验
    if (ordIdStr.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号！");
        return;
    }
    if (advContent.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入要修改的医嘱内容！");
        return;
    }

    // 3. 开启事务（确保查询和更新逻辑一致）
    QSqlDatabase::database().transaction();

    // 第一步：根据 Ord_id 找到 Med_id
    QSqlQuery query;
    query.prepare("SELECT Med_id FROM medical WHERE Ord_id = :oid");
    query.bindValue(":oid", ordIdStr.toInt());

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "错误", "未找到该患者对应的病历，请先保存就诊信息！");
        QSqlDatabase::database().rollback();
        return;
    }

    int medId = query.value("Med_id").toInt();

    // 第二步：检查 advice 表中是否已经存在该 Med_id 的医嘱
    QSqlQuery checkAdv;
    checkAdv.prepare("SELECT Adv_id FROM advice WHERE Med_id = :mid");
    checkAdv.bindValue(":mid", medId);
    checkAdv.exec();

    bool exists = checkAdv.next();
    QSqlQuery actionQuery;

    if (exists) {
        // 如果存在，执行更新 (UPDATE)
        actionQuery.prepare("UPDATE advice SET Adv_content = :content WHERE Med_id = :mid");
    } else {
        QSqlDatabase::database().rollback();
        QMessageBox::warning(this, "提示", "未找到已有医嘱，请点击‘新增’按钮进行添加。");
        return; // 直接返回是合理的
    }

    actionQuery.bindValue(":mid", medId);
    actionQuery.bindValue(":content", advContent);

    if (actionQuery.exec()) {
        QSqlDatabase::database().commit();
        QMessageBox::information(this, "成功", "医嘱已成功写入数据库！");
        ui->lineEdit_3->clear();
        ui->textEdit_3->clear();
    } else {
        QSqlDatabase::database().rollback();
        QMessageBox::critical(this, "失败", "医嘱写入失败：" + actionQuery.lastError().text());
    }
}


void doctor::on_pushButton_3_add_clicked()
{
    //判断用户有没有输入订单编号，在medical根据订单编号，找病例编号，新增一条数据在advice
    // 1. 获取界面输入
    QString ordIdStr = ui->lineEdit_3->text().trimmed(); // 订单编号
    QString advContent = ui->textEdit_3->toPlainText().trimmed(); // 医嘱内容

    // 2. 基本校验
    if (ordIdStr.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号！");
        return;
    }
    if (advContent.isEmpty()) {
        QMessageBox::warning(this, "提示", "医嘱内容不能为空！");
        return;
    }
    if(!queueday(ordIdStr.toInt())){
        return ;
    }
    // 3. 数据库操作：先找 Med_id，再新增 Advice
    QSqlQuery query;

    // 步骤 A：根据订单号找到对应的病历编号 (Med_id)
    // 建议同时校验 Doc_id，确保只有接诊医生能开医嘱
    query.prepare("SELECT Med_id FROM medical WHERE Ord_id = :oid AND Doc_id = :did");
    query.bindValue(":oid", ordIdStr.toInt());
    query.bindValue(":did", this->m_id);

    if (!query.exec()) {
        QMessageBox::critical(this, "错误", "查询病历失败：" + query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "操作失败", "未找到对应的病历记录，请确认：\n1. 预约编号是否正确\n2. 是否已经保存过就诊记录");
        return;
    }

    int medId = query.value("Med_id").toInt();
    QSqlQuery checkAdv;
    checkAdv.prepare("SELECT Adv_id FROM advice WHERE Med_id = :mid");
    checkAdv.bindValue(":mid", medId);
    checkAdv.exec();

    bool exists = checkAdv.next();


    if (exists) {
        QMessageBox::critical(this, "失败", "已有医嘱，请点击‘修改’按钮进行修改。" );
        return ;
    }
    // 步骤 B：向 advice 表插入新数据
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO advice (Med_id, Doc_id, Adv_content, Adv_create) "
                        "VALUES (:mid, :did, :content, NOW())");
    insertQuery.bindValue(":mid", medId);
    insertQuery.bindValue(":did", this->m_id);
    insertQuery.bindValue(":content", advContent);

    if (insertQuery.exec()) {
        QMessageBox::information(this, "成功", "医嘱已成功下达！");

        // 可选：操作成功后清空输入框
        ui->lineEdit_3->clear();
        ui->textEdit_3->clear();
    } else {
        QMessageBox::critical(this, "失败", "添加医嘱失败：" + insertQuery.lastError().text());
    }
}


void doctor::on_pushButton_4_stop_clicked()
{
    //先判断是否选中一行
    //获取该行的号源编号，以及总号数，剩余号数
    //先问是否确认暂停，是就更新order表，剩余号数为0，总号数也修改
    // 1. 判断是否选中一行
    int currentRow = ui->tableWidget_haomesg->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选中要暂停的号源！");
        return;
    }

    // 2. 获取该行的关键数据
    // 假设索引：0:号源编号, 7:总号数, 8:剩余号数, 11:号源状态
    QString souId = ui->tableWidget_haomesg->item(currentRow, 0)->text();
    int total = ui->tableWidget_haomesg->item(currentRow, 7)->text().toInt();
    int remain = ui->tableWidget_haomesg->item(currentRow, 8)->text().toInt();
    QString status = ui->tableWidget_haomesg->item(currentRow, 11)->text();

    // 校验：如果已经满了或者已经是停诊状态，无需操作
    if (remain <= 0 || status == "已满") {
        QMessageBox::information(this, "提示", "该号源已无剩余可预约名额，无需暂停。");
        return;
    }

    // 3. 询问用户是否确认暂停
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认暂停",
                                  QString("确定要暂停号源 [%1] 吗？\n暂停后剩余的 %2 个名额将被取消。").arg(souId).arg(remain),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) return;

    // 4. 更新 source 表
    // 逻辑：总号数 = 总号数 - 剩余数 (即变成已预约数)，剩余数 = 0
    // 这样做的目的是让“已预约”的人不受影响，但不再允许新的人进来
    QSqlQuery query;
    query.prepare("UPDATE source SET Sou_total = Sou_total - Sou_remain, Sou_remain = 0 WHERE Sou_id = :sid");
    query.bindValue(":sid", souId);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "该号源已成功暂停，可预约数已清零。");
        // 5. 刷新界面
        initalhaoyuan();
    } else {
        QMessageBox::critical(this, "错误", "操作失败：" + query.lastError().text());
    }
}





void doctor::on_pushButton_7_qur_clicked()
{
    // 先判断用户是否输入订单编号，没有警告
    // 查询medical获取medid，然后在prescription表找medid，没有就提示
    // 有就把药品名称计量天数显示出来
    // 1. 设置列数（必须先设置列数，才能设置表头标签）



    QString ordId = ui->lineEdit_7->text().trimmed();

    // 1. 判断是否输入订单编号
    if (ordId.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号！");
        return;
    }

    // 2. 查询 medical 表获取 Med_id
    QSqlQuery query;
    query.prepare("SELECT Med_id FROM medical WHERE Ord_id = :ordId");
    query.bindValue(":ordId", ordId.toInt());

    if (!query.exec()) {
        qDebug() << "查询 medical 失败:" << query.lastError().text();
        return;
    }

    if (!query.next()) {
        QMessageBox::information(this, "提示", "未找到该患者的病历信息。");
        return;
    }

    int medId = query.value("Med_id").toInt();
    QSqlQuery query2;

    // 3. 在 prescription 表找药品信息
    query2.prepare("SELECT Pre_id,Pre_drug, Pre_dosage, Pre_day FROM prescription WHERE Med_id = :medId");
    query2.bindValue(":medId", medId);

    if (!query2.exec()) {
        qDebug() << "查询 prescription 失败:" << query2.lastError().text();
        return;
    }

    // 4. 清空旧表格内容并显示新结果
    // 先清空
    ui->tableWidget_7->setRowCount(0);
    bool hasData = false;
    while (query2.next()) {
        hasData = true;
        // 1. 获取当前行号

        int currentRow = ui->tableWidget_7->rowCount();
        ui->tableWidget_7->insertRow(currentRow);

        // 2. 获取字段内容（增加 Pre_id）
        int preId = query2.value("Pre_id").toInt(); // 确保你的 SQL 语句里查了这一项
        QString drugName = query2.value("Pre_drug").toString();
        QString dosage = query2.value("Pre_dosage").toString();
        int days = query2.value("Pre_day").toInt();

        // 3. 填充到表格
        // 第 0 列存 ID（虽然界面看不见，但数据在那儿）
        ui->tableWidget_7->setItem(currentRow, 0, new QTableWidgetItem(QString::number(preId)));
        // 往后挪一列
        ui->tableWidget_7->setItem(currentRow, 1, new QTableWidgetItem(drugName));
        ui->tableWidget_7->setItem(currentRow, 2, new QTableWidgetItem(dosage));
        ui->tableWidget_7->setItem(currentRow, 3, new QTableWidgetItem(QString::number(days)));


    }
    if (!hasData) {
        QMessageBox::information(this, "提示", "该病历下暂无处方药品记录。");

    }

}
void doctor::on_pushButton_7_del_clicked()
{
    //看用户是否选中一行
    //把这行在表格中删除
    //提示用户需要按下提交按钮才是正式提交
    // 1. 获取当前选中的行索引
    int currentRow = ui->tableWidget_7->currentRow();

    // 2. 判断用户是否选中了一行 (currentRow 为 -1 表示未选中)

    if (currentRow < 0) {
        QMessageBox::warning(this, "操作提示", "请先在表格中点击选择要删除的那一行。");
        return;
    }

    // 3. 弹出确认对话框（可选，防止误删）
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除", "确定要移除这一行吗？",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    // 4. 执行“软删除”逻辑
    // 获取隐藏的 ID 项（假设在第 0 列）
    QTableWidgetItem *idItem = ui->tableWidget_7->item(currentRow, 0);

    if (idItem) {
        // 将 ID 标记为 -2，表示“待从数据库删除”
        if(idItem->text()=="-1")
        {
           ui->tableWidget_7->removeRow(currentRow);
        }
        else
        {
            idItem->setText("-2");
            // 5. 视觉上隐藏这一行（而不是物理删除）
            ui->tableWidget_7->setRowHidden(currentRow, true);

        }
    }



    // 5. 提示用户正式提交
    // 这里使用红色或者醒目的文字提示，或者在界面的状态栏显示
    QMessageBox::information(this, "本地已删除",
                             "该行已从当前列表中移除。\n请注意：必须点击下方的【提交】按钮，修改才会同步到数据库。");
}


void doctor::on_pushButton_7_sub_clicked()
{
    //遍历所有行，如果id是-1，就insert，如果-2，就删除
    //告诉提交成功

    // 2. 查询 medical 表获取 Med_id
    QString ordId = ui->lineEdit_7->text().trimmed();

    // 1. 判断是否输入订单编号
    if (ordId.isEmpty()) {
        QMessageBox::warning(this, "提示", "请输入预约编号！");
        return;
    }
    if(!queueday(ordId.toInt())){
        return ;
    }

    // 2. 查询 medical 表获取 Med_id
    QSqlQuery query2;
    query2.prepare("SELECT Med_id FROM medical WHERE Ord_id = :ordId");
    query2.bindValue(":ordId", ordId);

    if (!query2.exec()) {
        qDebug() << "查询 medical 失败:" << query2.lastError().text();
        return;
    }

    if (!query2.next()) {
        QMessageBox::information(this, "提示", "未找到该患者的病历信息。");
        return;
    }

    int medId = query2.value("Med_id").toInt();




    QSqlDatabase db = QSqlDatabase::database();
    db.transaction(); // 【重要】开启事务，确保所有操作要么全部成功，要么全部失败
    QSqlQuery query;
    bool success = true;

    // 假设这些 ID 你已经通过登录信息或界面变量拿到了
    int currentMedId = medId;
    int currentDocId = m_id;




    for (int i = 0; i < ui->tableWidget_7->rowCount(); ++i) {
        // 1. 获取隐藏列的 ID 值
        QTableWidgetItem *idItem = ui->tableWidget_7->item(i, 0);
        if (!idItem) continue;

        QString idVal = idItem->text();
        QString drugName = ui->tableWidget_7->item(i, 1)->text();
        QString dosage = ui->tableWidget_7->item(i, 2)->text();
        // 去掉我们显示的“ 天”字，转回数字
        QString day1 = ui->tableWidget_7->item(i, 3)->text();
        if (drugName.isEmpty()||dosage.isEmpty()||day1.isEmpty()) {
             qDebug() << "缺失"<<drugName<<" "<<dosage<<" "<<day1 ;
            success = false;
            break;
        }
        int days=day1.toInt();
        // 2. 根据 ID 分支处理
        if (idVal == "-2") {
            // 【状态 -2】：执行删除
            // 如果原本就是新加的(-1)变成(-2)，其实数据库没记录，不用管
            // 如果是正数变回来的，才需要删（不过你现在的逻辑是直接把 ID 改成了 -2）
            // 建议删除逻辑：如果该行有原始 ID（存放在另一个 Role 里更好），则删除。
            // 这里我们假设你只想删除数据库中存在的记录：
            // 注意：如果这行是新加的直接删，不需要操作数据库
            query.prepare("DELETE FROM prescription WHERE Med_id = :medId AND Pre_drug = :drug");
            query.bindValue(":medId", currentMedId);
            query.bindValue(":drug", drugName);
        }
        else if (idVal == "-1") {
            // 【状态 -1】：执行插入
            if (drugName.isEmpty()) continue; // 过滤空白行

            query.prepare("INSERT INTO prescription (Med_id, Doc_id, Pre_drug, Pre_dosage, Pre_day, Pre_create) "
                          "VALUES (:medId, :docId, :drug, :dosage, :days, NOW())");
            query.bindValue(":medId", currentMedId);
            query.bindValue(":docId", currentDocId);
            query.bindValue(":drug", drugName);
            query.bindValue(":dosage", dosage);
            query.bindValue(":days", days);
        }
        else if(idVal.toInt()>0){
            // 【状态 正数】：执行更新（防止医生修改了现有的药品剂量或天数）
            query.prepare("UPDATE prescription SET Pre_drug = :drug, Pre_dosage = :dosage, "
                          "Pre_day = :days WHERE Pre_id = :preId");
            query.bindValue(":drug", drugName);
            query.bindValue(":dosage", dosage);
            query.bindValue(":days", days);
            query.bindValue(":preId", idVal.toInt());
        }

        if (!query.exec()) {
            success = false;
            qDebug() << "SQL Error:" << query.lastError().text();
            break;
        }
    }

    // 3. 提交事务并反馈结果
    if (success) {
        db.commit();
        QMessageBox::information(this, "提交成功", "处方信息已成功同步至服务器！");
        on_pushButton_7_qur_clicked();
        // 可选：提交后重新刷新一遍表格，让所有 -1, -2 的状态消失，变回正常的数据库 ID
        // this->queryPrescription();
    } else {
        db.rollback();
        QMessageBox::critical(this, "提交失败", "数据库操作异常，请检查网络或数据格式。");
    }
}


void doctor::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    ui->tableWidget_1->setRowCount(0); // 清空旧数据

    QSqlQuery query;

    // 1. 准备 SQL 语句：
    // 使用 JOIN 连接 source 表，获取 Sou_date
    QString sql = "SELECT o.Ord_id, o.Pat_id, o.Ord_status, s.Sou_date, p.Pat_name, p.Pat_gender, "
                  "p.Pat_age, p.Pat_phone, p.Pat_card, m.Med_diagnose, m.Med_note, o.Ord_paystatus "
                  "FROM `porder` o "
                  "JOIN source s ON o.Sou_id = s.Sou_id "  // 关联号源表
                  "JOIN patient p ON o.Pat_id = p.Pat_id "
                  "LEFT JOIN medical m ON o.Ord_id = m.Ord_id "
                  "WHERE o.Doc_id = :did";

    // 2. 逻辑判断：如果 CheckBox 没被点击（没勾选），则只显示当天的号源
    // 假设 checkbox 变量名是 ui->checkBox_showAll
    if (!ui->checkBox_2->isChecked()) {
        sql += " AND s.Sou_date = CURDATE()";
    }

    query.prepare(sql);
    query.bindValue(":did", m_id); // 绑定当前登录医生 ID

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            ui->tableWidget_1->insertRow(row);

            // 依次填充表格
            ui->tableWidget_1->setItem(row, 0, new QTableWidgetItem(query.value("Ord_id").toString()));
            ui->tableWidget_1->setItem(row, 1, new QTableWidgetItem(query.value("Pat_id").toString()));
            ui->tableWidget_1->setItem(row, 2, new QTableWidgetItem(query.value("Pat_name").toString()));
            ui->tableWidget_1->setItem(row, 3, new QTableWidgetItem(query.value("Pat_gender").toString()));
            ui->tableWidget_1->setItem(row, 4, new QTableWidgetItem(query.value("Pat_age").toString()));
            ui->tableWidget_1->setItem(row, 5, new QTableWidgetItem(query.value("Pat_phone").toString()));

            // --- 新增：第 6 列填充坐诊日期 ---
            ui->tableWidget_1->setItem(row, 6, new QTableWidgetItem(query.value("Sou_date").toDate().toString("yyyy-MM-dd")));

            ui->tableWidget_1->setItem(row, 7, new QTableWidgetItem(query.value("Ord_status").toString()));
            ui->tableWidget_1->setItem(row, 8, new QTableWidgetItem(query.value("Med_diagnose").toString()));
            ui->tableWidget_1->setItem(row, 9, new QTableWidgetItem(query.value("Med_note").toString()));
            if(query.value("Sou_date").toDate()==QDate::currentDate()&&query.value("Ord_paystatus").toString()=="已支付"&&query.value("Ord_status").toString()=="待就诊"){
                 ui->tableWidget_1->setItem(row, 10, new QTableWidgetItem("可就诊"));
            }

            row++;
        }
    } else {
        qDebug() << "查询患者列表失败：" << query.lastError().text();
    }
}


void doctor::on_pushButton_7_add_clicked()
{
    // 1. 获取当前已经有多少行
    int currentRowCount = ui->tableWidget_7->rowCount();

    // 2. 在末尾插入一行
    ui->tableWidget_7->insertRow(currentRowCount);

    // 3. 【关键】初始化新行的每一个单元格
    // 假设你有 4 列
     ui->tableWidget_7->setItem(currentRowCount, 0, new QTableWidgetItem("-1"));
    for (int col = 1; col < 4; ++col) {
        ui->tableWidget_7->setItem(currentRowCount, col, new QTableWidgetItem(""));
    }

    // 4. 自动滚动到最新的一行，方便医生输入
    ui->tableWidget_7->scrollToBottom();
}


void doctor::on_pushButton_6_clicked()
{
    QString oldPwd = ui->lineEdit_5_old_2->text().trimmed();
    QString newPwd = ui->lineEdit_5_new_2->text().trimmed();

    // 2. 非空校验
    if (oldPwd.isEmpty() || newPwd.isEmpty()) {
        QMessageBox::warning(this, "提示", "旧密码和新密码不能为空！");
        return;
    }

    // 3. 验证旧密码是否正确
    // 假设当前登录用户的 ID 存储在变量 m_id 中
    QSqlQuery query;
    query.prepare("SELECT Doc_pwd FROM doctor WHERE Doc_id = :id");
    query.bindValue(":id", m_id);

    if (query.exec() && query.next()) {
        QString dbPwd = query.value(0).toString();

        if (dbPwd != oldPwd) {
            QMessageBox::critical(this, "错误", "旧密码输入错误，请重新输入！");
            ui->lineEdit_5_old_2->clear();
            ui->lineEdit_5_new_2->clear();
            return;
        }
    } else {
        QMessageBox::critical(this, "错误", "查询用户信息失败！");
        ui->lineEdit_5_old_2->clear();
        ui->lineEdit_5_new_2->clear();
        return;
    }

    // 4. 二次确认修改
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认修改", "您确定要修改密码吗？修改后需重新登录。",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // 5. 执行更新操作
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE doctor SET Doc_pwd = :newPwd WHERE Doc_id = :id");
        updateQuery.bindValue(":newPwd", newPwd);
        updateQuery.bindValue(":id", m_id);

        if (updateQuery.exec()) {
            QMessageBox::information(this, "成功", "密码修改成功，请重新登录！");

            // 可选：修改成功后自动注销或清空输入框
            ui->lineEdit_5_old_2->clear();
            ui->lineEdit_5_new_2->clear();
            // 2. 发射信号
            emit loginreturn();
            // 3. 关闭（或隐藏）当前主界面
            this->close();


        } else {
            QMessageBox::critical(this, "失败", "数据库更新失败：" + updateQuery.lastError().text());
        }
    }
    else{
        ui->lineEdit_5_old_2->clear();
        ui->lineEdit_5_new_2->clear();

    }
}


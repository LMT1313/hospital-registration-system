#include "admin.h"
#include "ui_admin.h"
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include<QProcess>
#include<QDateTime>
#include<QFileDialog>
#include<QDir>
#include<QSqlTableModel>
admin::admin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
    setWindowTitle("医院挂号系统 - 管理员界面");
    ui->stackedWidget_adm->setCurrentIndex(4);
    ui->comboBox_0->addItem("患者信息管理");
    ui->comboBox_0->addItem("医生信息管理");
    ui->comboBox_0->addItem("护士信息管理");
    loadpermis();
    loadsys();
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_return_clicked()
{
    emit loginreturn();
    this->close();
}
void admin::initial(QString &id){
     ui->listWidget->clearSelection();
    ui->stackedWidget_adm->setCurrentIndex(4);//4
    m_id=id.toInt();
    ui->label_admin->setText("欢迎您："+id);
    updatepermit();
    loadTableData(0);
        loadpermis();
    loadsys();
        inilog();
}

void admin::loadTableData(int index)
{
    ui->tableWidget_0->setRowCount(0); // 清空旧数据
    QSqlQuery query;
    QString sql;
    QStringList headers;

    // 根据选择的索引切换 SQL 和 表头
    switch (index) {
    case 0: // 患者信息
        sql = "SELECT Pat_id, Pat_pwd, Pat_name, Pat_gender, Pat_age, Pat_phone, Pat_card, Pat_address FROM patient";
        headers << "身份证号" << "密码"<< "姓名" << "性别" << "年龄" << "联系电话" << "就诊卡号" << "联系地址";
        break;

    case 1: // 医生信息
        sql = "SELECT Doc_id, Doc_pwd, Doc_name, Doc_title, Doc_major, Dep_id, Doc_phone, Doc_status FROM doctor";
        headers << "医生编号" << "密码"<< "姓名" << "职称" << "擅长领域" << "科室编号" << "联系电话" << "状态";
        break;

    case 2: // 护士信息
        sql = "SELECT Nur_id, Nur_pwd, Nur_name, Dep_id, Nur_phone, Nur_status FROM nurse";
        headers << "护士编号" << "密码"<< "姓名" << "科室编号" << "联系电话" << "工作状态";
        break;
    }

    // 设置表格列数与表头
    ui->tableWidget_0->setColumnCount(headers.size());
    ui->tableWidget_0->setHorizontalHeaderLabels(headers);

    // 执行数据库查询
    if (query.exec(sql)) {
        int row = 0;
        while (query.next()) {
            ui->tableWidget_0->insertRow(row);
            // 循环填充每一列的值
            for (int col = 0; col < headers.size(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                if (col == 0) {
                    // 第一列（主键）禁止编辑
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                }
                item->setTextAlignment(Qt::AlignCenter); // 居中显示
                ui->tableWidget_0->setItem(row, col, item);
            }
            row++;
        }
    } else {
        qDebug() << "数据加载失败:" << query.lastError().text();
    }

    // 自动调整列宽
    ui->tableWidget_0->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // 最后一列拉伸
    ui->tableWidget_0->horizontalHeader()->setStretchLastSection(true);
    // 5. 选中整行
    ui->tableWidget_0->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_0->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );
}

void admin::loadpermis()
{
    ui->tableWidget_1->setRowCount(0); // 清空旧数据
    QSqlQuery query;
    QString sql;
    QStringList headers;

    sql = "SELECT Per_id, Role_name, Per_func, Per_data FROM role_permission";
    headers << "权限编号" << "角色名称"<< "功能权限" << "数据权限";


    // 设置表格列数与表头
    ui->tableWidget_1->setColumnCount(headers.size());
    ui->tableWidget_1->setHorizontalHeaderLabels(headers);

    // 执行数据库查询
    if (query.exec(sql)) {
        int row = 0;
        while (query.next()) {
            ui->tableWidget_1->insertRow(row);
            // 循环填充每一列的值
            for (int col = 0; col < headers.size(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                if (col == 0||col==1) {
                    // 第一列（主键）禁止编辑
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                }
                item->setTextAlignment(Qt::AlignCenter); // 居中显示
                ui->tableWidget_1->setItem(row, col, item);
            }
            row++;
        }
    } else {
        qDebug() << "数据加载失败:" << query.lastError().text();
    }
    // 3. 基础外观设置
    ui->tableWidget_1->verticalHeader()->setVisible(false);      // 隐藏左侧行号
    // 自动调整列宽
    ui->tableWidget_1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // 最后一列拉伸
    ui->tableWidget_1->horizontalHeader()->setStretchLastSection(true);
    // 5. 选中整行
    ui->tableWidget_1->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_1->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );
}

void admin::updatepermit()
{

    QSqlQuery query;
    // 1. 查询该角色的权限字符串
    query.prepare("SELECT Per_func FROM administrator as a join role_permission as r on a.Adm_role=r.Role_name  WHERE Per_id = :id");
    query.bindValue(":id", m_id);

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

void admin::loadsys()
{
    ui->tableWidget_3->setRowCount(0); // 清空旧数据
    QSqlQuery query;
    QString sql;
    QStringList headers;

    sql = "SELECT Par_id, Par_name, Par_value, Par_note FROM system_param";
    headers << "参数编号" << "参数名称(不可修改)"<< "参数值" << "参数说明";


    // 设置表格列数与表头
    ui->tableWidget_3->setColumnCount(headers.size());
    ui->tableWidget_3->setHorizontalHeaderLabels(headers);

    // 执行数据库查询
    if (query.exec(sql)) {
        int row = 0;
        while (query.next()) {
            ui->tableWidget_3->insertRow(row);
            // 循环填充每一列的值
            for (int col = 0; col < headers.size(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                if (col == 0||col==1) {
                    // 第一列（主键）禁止编辑
                    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
                }
                item->setTextAlignment(Qt::AlignCenter); // 居中显示
                ui->tableWidget_3->setItem(row, col, item);
            }
            row++;
        }
    } else {
        qDebug() << "数据加载失败:" << query.lastError().text();
    }
    // 3. 基础外观设置
    ui->tableWidget_3->verticalHeader()->setVisible(false);      // 隐藏左侧行号

    // 自动调整列宽
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    // 最后一列拉伸
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
    // 5. 选中整行
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置样式表：指定选中状态 (item:selected) 的背景色和文字颜色
    ui->tableWidget_3->setStyleSheet(
        "QTableWidget::item:selected {"
        "    background-color: #3399FF;" // 经典的天蓝色
        "    color: white;"              // 选中时文字变为白色，保证清晰
        "}"
        );

}

void admin::inilog()
{
  //页签名字为订单日志
  //在tableview展示表中内容
  ui->tabWidget->setTabText(0,"订单日志");
  ui->tabWidget->setTabText(1, "支付日志");
  ui->tabWidget->setTabText(2, "号源日志");
  ui->tabWidget->setTabText(3, "病历日志");
  // 1. 初始化模型
  orderLogModel = new QSqlTableModel(this);

  // 2. 绑定数据库表
  orderLogModel->setTable("order_log");

  // 3. 设置表头（让界面更友好，显示中文）
  orderLogModel->setHeaderData(0, Qt::Horizontal, "日志ID");
  orderLogModel->setHeaderData(1, Qt::Horizontal, "订单编号");
  orderLogModel->setHeaderData(2, Qt::Horizontal, "患者证件号");
  orderLogModel->setHeaderData(3, Qt::Horizontal, "操作类型");
  orderLogModel->setHeaderData(4, Qt::Horizontal, "日志时间");
  orderLogModel->setHeaderData(5, Qt::Horizontal, "备注信息");



  // 5. 执行查询
  orderLogModel->select();

  // 6. 将模型设置到你的 TableView (假设变量名是 tableView_orderLog)
  ui->tableView_0->setModel(orderLogModel);

  // 7. 细节优化
  ui->tableView_0->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置为只读
  ui->tableView_0->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 自动填充宽度
  // 开启自动换行
  ui->tableView_0->setWordWrap(true);

  // 调整行高以适应换行后的内容
  ui->tableView_0->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  ui->tableView_0->verticalHeader()->hide();

  // 1. 设置页签名字（假设这三个页签的索引是 1, 2, 3）
  ui->tabWidget->setTabText(1, "支付日志");
  ui->tabWidget->setTabText(2, "号源日志");
  ui->tabWidget->setTabText(3, "病历日志");

  // --- A. 支付日志表 (payment_log) ---
  payModel = new QSqlTableModel(this);
  payModel->setTable("payment_log");
  payModel->setHeaderData(0, Qt::Horizontal, "日志ID");
  payModel->setHeaderData(1, Qt::Horizontal, "订单ID");
  payModel->setHeaderData(2, Qt::Horizontal, "患者证件号");
  payModel->setHeaderData(3, Qt::Horizontal, "支付金额");
  payModel->setHeaderData(4, Qt::Horizontal, "支付时间");
  payModel->setHeaderData(5, Qt::Horizontal, "备注");
  //payModel->setSort(4, Qt::DescendingOrder); // 按支付时间倒序
  payModel->select();

  ui->tableView_1->setModel(payModel);
  ui->tableView_1->verticalHeader()->hide(); // 隐藏行前面的号
  ui->tableView_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->tableView_1->setEditTriggers(QAbstractItemView::NoEditTriggers);

  // --- B. 号源日志表 (source_log) ---
  souModel = new QSqlTableModel(this);
  souModel->setTable("source_log");
  souModel->setHeaderData(0, Qt::Horizontal, "日志ID");
  souModel->setHeaderData(1, Qt::Horizontal, "号源ID");
  souModel->setHeaderData(2, Qt::Horizontal, "医生ID");
  souModel->setHeaderData(3, Qt::Horizontal, "就诊日期");
  souModel->setHeaderData(4, Qt::Horizontal, "动作");
  souModel->setHeaderData(5, Qt::Horizontal, "操作时间");
  souModel->setSort(5, Qt::DescendingOrder);
  souModel->select();

  ui->tableView_2->setModel(souModel);
  ui->tableView_2->verticalHeader()->hide(); // 隐藏行前面的号
  ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

  // --- C. 病历日志表 (medical_log) ---
  medModel = new QSqlTableModel(this);
  medModel->setTable("medical_log");
  medModel->setHeaderData(0, Qt::Horizontal, "日志ID");
  medModel->setHeaderData(1, Qt::Horizontal, "病历ID");
  medModel->setHeaderData(2, Qt::Horizontal, "患者证件号");
  medModel->setHeaderData(3, Qt::Horizontal, "医生ID");
  medModel->setHeaderData(4, Qt::Horizontal, "创建时间");
  medModel->setHeaderData(5, Qt::Horizontal, "备注");
  medModel->setSort(4, Qt::DescendingOrder);
  medModel->select();

  ui->tableView_3->setModel(medModel);
  ui->tableView_3->verticalHeader()->hide(); // 隐藏行前面的号
  ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
  // 开启自动换行
  ui->tableView_3->setWordWrap(true);

  // 调整行高以适应换行后的内容
  ui->tableView_3->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void admin::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString text = item->text().trimmed(); // 获取点击条目的文字
    ui->comboBox_0->setCurrentIndex(0);

    ui->tableWidget_0->clearSelection(); // 清除所有选中高亮
    ui->tableWidget_0->setCurrentCell(-1, -1); // 重置当前焦点单元格
    ui->tableWidget_1->clearSelection(); // 清除所有选中高亮
    ui->tableWidget_1->setCurrentCell(-1, -1); // 重置当前焦点单元格
    ui->tableWidget_3->clearSelection(); // 清除所有选中高亮
    ui->tableWidget_3->setCurrentCell(-1, -1); // 重置当前焦点单元格
    ui->lineEdit_5_new->clear();
    ui->lineEdit_5_old->clear();
    if (text == "用户管理") {
        ui->stackedWidget_adm->setCurrentIndex(0);

    }
    else if (text == "权限管理") {
        ui->stackedWidget_adm->setCurrentIndex(1);

    }
    else if (text == "数据管理") {
        ui->stackedWidget_adm->setCurrentIndex(2);

    }
    else if (text == "修改密码") {
        ui->stackedWidget_adm->setCurrentIndex(5);

    }
    else if (text == "查看日志") {
        orderLogModel->select();
        payModel->select();
        souModel->select();
        medModel->select();
        ui->stackedWidget_adm->setCurrentIndex(6);

    }
    else
        ui->stackedWidget_adm->setCurrentIndex(3);
}



void admin::on_comboBox_0_currentIndexChanged(int index)
{
    loadTableData(index);
}


void admin::on_pushButton_0_add_clicked()
{
    // 1. 在表格末尾插入新行
    int rowCount = ui->tableWidget_0->rowCount();
    ui->tableWidget_0->insertRow(rowCount);

    // 2. 为新行的每一列创建空的 Item
    int columnCount = ui->tableWidget_0->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        if(col==1){
            QTableWidgetItem *item = new QTableWidgetItem("123456");
            // 设置背景颜色为浅黄色，提醒用户这一行是新加的，还没保存
            item->setBackground(QBrush(QColor(255, 255, 224)));
            ui->tableWidget_0->setItem(rowCount, col, item);
        }
        else{
        QTableWidgetItem *item = new QTableWidgetItem("");
        // 设置背景颜色为浅黄色，提醒用户这一行是新加的，还没保存
        item->setBackground(QBrush(QColor(255, 255, 224)));
        ui->tableWidget_0->setItem(rowCount, col, item);
        }

    }

    // 3. 自动滚动到新行并选中第一个单元格
    ui->tableWidget_0->setCurrentCell(rowCount, 0);
    ui->tableWidget_0->editItem(ui->tableWidget_0->item(rowCount, 0));
}


void admin::on_pushButton_0_del_clicked()
{
    // 1. 获取当前选中的行
    int currentRow = ui->tableWidget_0->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先在表格中选中要删除的行！");
        return;
    }

    // 2. 获取当前下拉框的类型，确定主键名和表名
    int typeIndex = ui->comboBox_0->currentIndex();
    QString tableName;
    QString primaryKeyName;
    QString displayName;

    if (typeIndex == 0) { // 患者
        tableName = "patient";
        primaryKeyName = "Pat_id";
        displayName = ui->tableWidget_0->item(currentRow, 2)->text(); // 姓名
    } else if (typeIndex == 1) { // 医生
        tableName = "doctor";
        primaryKeyName = "Doc_id";
        displayName = ui->tableWidget_0->item(currentRow, 2)->text(); // 姓名
    } else { // 护士
        tableName = "nurse";
        primaryKeyName = "Nur_id";
        displayName = ui->tableWidget_0->item(currentRow, 2)->text(); // 姓名
    }

    // 获取该行的主键值（假设主键都在第 0 列）
    QString primaryKeyValue = ui->tableWidget_0->item(currentRow, 0)->text();

    // 3. 二次确认弹窗
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除",
                                  QString("确定要删除 %1 (编号:%2) 吗？\n此操作不可撤销！")
                                      .arg(displayName).arg(primaryKeyValue),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) return;

    // 4. 执行删除 SQL
    QSqlQuery query;
    // 使用占位符防止 SQL 注入
    QString sql = QString("DELETE FROM %1 WHERE %2 = :id").arg(tableName).arg(primaryKeyName);

    query.prepare(sql);
    query.bindValue(":id", primaryKeyValue);

    if (query.exec()) {
        QMessageBox::information(this, "成功", "记录已成功删除！");
        loadTableData(typeIndex); // 重新加载当前表数据，刷新显示
    } else {
        // 如果删除失败，通常是因为外键约束（例如该医生还有未完成的订单）
        QString errorMsg = query.lastError().text();
        if (errorMsg.contains("foreign key constraint fails")) {
            QMessageBox::critical(this, "删除失败", "该人员关联了其他业务数据（如订单、病历），无法直接删除！");
        } else {
            QMessageBox::critical(this, "错误", "删除操作失败：" + errorMsg);
        }
    }
}


void admin::on_pushButton_3_mod_clicked()
{

    // 1. 检查是否选中了行
    int currentRow = ui->tableWidget_0->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选中您需要保存的那一行！");
        return;
    }
    // 2. 获取该行第一个单元格的背景颜色
    QTableWidgetItem *firstItem = ui->tableWidget_0->item(currentRow, 0);
    if (!firstItem) return;

    QColor bgColor = firstItem->background().color();
    // 判断是否为浅黄色 (255, 255, 224) —— 这是我们在新增行时设置的颜色
    bool isNewRow = (bgColor == QColor(255, 255, 224));

    if (isNewRow) {
        // --- 执行新增逻辑 ---
        int typeIndex = ui->comboBox_0->currentIndex();
        QSqlQuery query;

        QString id = ui->tableWidget_0->item(currentRow, 0)->text().trimmed();
        QString pwd = ui->tableWidget_0->item(currentRow, 1)->text().trimmed();
        QString name = ui->tableWidget_0->item(currentRow, 2)->text().trimmed();



        // 2. 非空判断校验
        if ( id.isEmpty() || name.isEmpty() || pwd.isEmpty()) {
            QMessageBox::critical(this, "错误", "账号、姓名和密码不能为空，请检查填写！");
            return;
        }
        if(typeIndex==0&&ui->tableWidget_0->item(currentRow,3)->text().trimmed().isEmpty()){
            QMessageBox::critical(this, "错误", "性别不能为空，请检查填写！");
            return;
        }
        if((typeIndex==1&&ui->tableWidget_0->item(currentRow,7)->text().trimmed().isEmpty())){
            QMessageBox::critical(this, "错误", "状态不能为空，请检查填写！");
            return;
        }
        if((typeIndex==2&&ui->tableWidget_0->item(currentRow,5)->text().trimmed().isEmpty())){
            QMessageBox::critical(this, "错误", "状态不能为空，请检查填写！");
            return;
        }
        // 3. 根据表类型执行插入
        if (typeIndex == 0) { // Patient
            query.prepare("INSERT INTO patient (Pat_id, Pat_pwd, Pat_name, Pat_gender, Pat_age, Pat_phone, Pat_card, Pat_address) "
                          "VALUES (:id, :pwd, :name, :gender, :age, :phone, :card, :addr)");
            query.bindValue(":id", id);
            query.bindValue(":pwd", pwd);
            query.bindValue(":name", name);
            query.bindValue(":gender", ui->tableWidget_0->item(currentRow, 3)->text());
            query.bindValue(":age", ui->tableWidget_0->item(currentRow, 4)->text().toInt());
            query.bindValue(":phone", ui->tableWidget_0->item(currentRow, 5)->text());
            query.bindValue(":card", ui->tableWidget_0->item(currentRow, 6)->text());
            query.bindValue(":addr", ui->tableWidget_0->item(currentRow, 7)->text());
        }
        else if (typeIndex == 1) { // Doctor
            query.prepare("INSERT INTO doctor (Doc_id, Doc_pwd, Doc_name, Doc_title, Doc_major, Dep_id, Doc_phone, Doc_status) "
                          "VALUES (:id, :pwd, :name, :title, :major, :dep, :phone, '正常')");
            query.bindValue(":id", id.toInt());
            query.bindValue(":pwd", pwd);
            query.bindValue(":name", name);
            query.bindValue(":title", ui->tableWidget_0->item(currentRow, 3)->text());
            query.bindValue(":major", ui->tableWidget_0->item(currentRow, 4)->text());
            query.bindValue(":dep", ui->tableWidget_0->item(currentRow, 5)->text().toInt());
            query.bindValue(":phone", ui->tableWidget_0->item(currentRow, 6)->text());
        }
        else if (typeIndex == 2) { // 护士 (Nurse) —— 补充完整部分
            query.prepare("INSERT INTO nurse (Nur_id, Nur_pwd, Nur_name, Dep_id, Nur_phone, Nur_status) "
                          "VALUES (:id, :pwd, :name, :dep, :phone, '正常')");
            query.bindValue(":id", id.toInt());     // 护士编号
            query.bindValue(":pwd", pwd);           // 初始密码
            query.bindValue(":name", name);         // 姓名
            query.bindValue(":dep", ui->tableWidget_0->item(currentRow, 3)->text().toInt()); // 所属科室编号
            query.bindValue(":phone", ui->tableWidget_0->item(currentRow, 4)->text());       // 联系电话

        }

        // 4. 执行结果
        if (query.exec()) {
            QMessageBox::information(this, "成功", "新数据已成功插入数据库！");
            // 关键：插入成功后，重新加载数据，颜色会变回白色，逻辑闭环
            loadTableData(typeIndex);
        } else {
            QMessageBox::critical(this, "失败", "插入失败：请检查数据输入的格式         ");
        }
    }
    else{
        // 2. 确定当前操作的表和字段
        int typeIndex = ui->comboBox_0->currentIndex();
        QString tableName;
        QString primaryKeyName;
        QStringList fields;

        if (typeIndex == 0) { // Patient
            tableName = "patient";
            primaryKeyName = "Pat_id";
            fields << "Pat_id" << "Pat_pwd"<< "Pat_name" << "Pat_gender" << "Pat_age" << "Pat_phone" << "Pat_card" << "Pat_address";
        } else if (typeIndex == 1) { // Doctor
            tableName = "doctor";
            primaryKeyName = "Doc_id";
            fields << "Doc_id" << "Doc_pwd"<< "Doc_name" << "Doc_title" << "Doc_major" << "Dep_id" << "Doc_phone" << "Doc_status";
        } else { // Nurse
            tableName = "nurse";
            primaryKeyName = "Nur_id";
            fields << "Nur_id" << "Nur_pwd"<< "Nur_name" << "Dep_id" << "Nur_phone" << "Nur_status";
        }

        // 3. 获取主键值（第0列）
        QString primaryKeyValue = ui->tableWidget_0->item(currentRow, 0)->text();

        // 4. 构建动态 UPDATE 语句
        // 我们采取“全行更新”策略：一次性把该行所有列都更新一遍
        QString sql = QString("UPDATE %1 SET ").arg(tableName);
        for (int i = 1; i < fields.size(); ++i) { // 从 1 开始，跳过主键
            sql += QString("%1 = :val%2").arg(fields[i]).arg(i);
            if (i < fields.size() - 1) sql += ", ";
        }
        sql += QString(" WHERE %1 = :id").arg(primaryKeyName);

        // 5. 绑定参数并执行
        QSqlQuery query;
        query.prepare(sql);

        // 绑定每一列的新值
        for (int i = 1; i < fields.size(); ++i) {
            QString val = ui->tableWidget_0->item(currentRow, i)->text().trimmed();
            query.bindValue(QString(":val%1").arg(i), val);
        }
        query.bindValue(":id", primaryKeyValue);

        // 6. 执行结果反馈
        if (query.exec()) {
            QMessageBox::information(this, "成功", "该行修改已成功保存到数据库！");
            // 可选：重新加载以确保 UI 数据与数据库完全同步
            loadTableData(typeIndex);
        } else {
            QMessageBox::critical(this, "保存失败", "修改失败请检查数据输入的格式         " );
        }
    }
}


void admin::on_pushButton_1_save_clicked()
{

    // 1. 检查是否选中了行
    int currentRow = ui->tableWidget_1->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选中您需要保存的那一行！");
        return;
    }

    // 2. 安全获取数据 (防止空指针)
    // 假设：0:Per_id, 1:Role_name, 2:Per_func, 3:Per_data
    auto getItemText = [&](int col) {
        QTableWidgetItem *it = ui->tableWidget_1->item(currentRow, col);
        return it ? it->text().trimmed() : "";
    };
    int id=ui->tableWidget_1->item(currentRow,0)->text().toInt();
    QString func = getItemText(2);
    QString data = getItemText(3);


    // 4. 构建正确的 SQL 语句
    // 注意：UPDATE 后面没有 FROM，且必须带 WHERE
    QString sql = "UPDATE role_permission SET "
                  "Per_func = :func, "
                  "Per_data = :data "
                  "WHERE Per_id = :id";

    QSqlQuery query;
    query.prepare(sql);

    // 5. 绑定参数
    query.bindValue(":func", func);
    query.bindValue(":data", data);
    query.bindValue(":id", id); // 主键作为更新条件

    // 6. 执行并反馈
    if (query.exec()) {
        QMessageBox::information(this, "成功", "该角色权限已成功保存！");
        loadpermis(); // 刷新表格
    } else {
        QMessageBox::critical(this, "保存失败", "数据库错误：" + query.lastError().text());
    }

}


void admin::on_pushButton_2_copy_clicked()
{
    // 1. 生成默认文件名（HIS_备份_日期时间.sql）
    QString defaultName = QString("HIS_Backup_%1.sql")
                              .arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));

    // 2. 弹出文件保存对话框，让用户选择路径
    // 参数：父窗口, 标题, 默认路径+文件名, 过滤器
    QString selectedPath = QFileDialog::getSaveFileName(this,
                                                        "选择备份保存位置",
                                                        QDir::homePath() + "/" + defaultName,
                                                        "SQL Files (*.sql)");

    // 3. 检查用户是否取消了选择
    if (selectedPath.isEmpty()) {
        return;
    }

    // 4. 执行备份
    // 注意：--single-transaction 保证备份期间数据一致性
    // --routines 备份存储过程
    QString cmd = "mysqldump";
    QStringList args;
    args << "-u" << "root"
         << "-p123456" // 注意：-p和密码之间没有空格
         << "--routines"
         << "--events"
         << "--single-transaction"
         << "hospital_registration";
//<< "--databases"
    QProcess process;
    process.setStandardOutputFile(selectedPath); // 将输出直接写入用户选中的路径
    process.start(cmd, args);

    if (process.waitForFinished()) {
        if (process.exitCode() == 0) {
            QMessageBox::information(this, "成功", "数据库已完整备份至：\n" + selectedPath);
        } else {
            QMessageBox::critical(this, "失败", "备份过程出错，请检查数据库配置。");
        }
    } else {
        QMessageBox::critical(this, "错误", "无法启动备份进程：" + process.errorString());
    }
}


void admin::on_pushButton_2_rec_clicked()
{
    QSqlQuery query;
    if (query.exec("SET GLOBAL log_bin_trust_function_creators = 1;")) {
        qDebug() << "存储函数创建权限已开启";
    } else {
        // 如果报错，通常是因为没有管理员权限，可以尝试直接运行恢复
        qDebug() << "权限设置失败：" << query.lastError().text();
    }
    // 让用户选择要恢复的 SQL 文件
    QString filePath = QFileDialog::getOpenFileName(this, "选择备份文件进行恢复", "", "SQL Files (*.sql)");

    if (filePath.isEmpty()) return;

    // 二次确认，防止误操作覆盖当前数据
    auto btn = QMessageBox::warning(this, "确认恢复",
                                    "恢复操作将覆盖当前数据库所有内容！\n建议先备份当前数据。确认继续？",
                                    QMessageBox::Yes | QMessageBox::No);
    if (btn == QMessageBox::No) return;




    QProcess *process = new QProcess(this);

    // 1. 设置输入文件
    process->setStandardInputFile(filePath);

    // 2. 关键：确保使用 mysql 客户端处理特殊指令
    // 如果环境里有多个 mysql，建议写绝对路径，例如 "C:/mysql/bin/mysql.exe"
    QString program = "mysql";

    QStringList arguments;
    arguments << "-uroot"
              << "-p123456"
              << "-f"
              << "--comments"            // 必须：允许处理文件中的特殊注释块
              << "--default-character-set=utf8mb4" // 必须：匹配你文件开头的 utf8mb4
              << "copyhospital_registration";

    process->start(program, arguments);

    if (process->waitForFinished()) {
        QString errors = process->readAllStandardError();
        if (process->exitCode() == 0) {
            QMessageBox::information(this, "成功", "数据库已完整恢复！");
        } else {
            // 如果报错，重点看这里
            QMessageBox::critical(this, "恢复失败", "错误详情：\n" + errors);
        }
    } else {
        QMessageBox::critical(this, "致命错误", "无法启动 mysql 进程，请检查环境变量。");
    }
    process->deleteLater();


    // QProcess process;
    // process.setStandardInputFile(filePath); // 从选中的文件读取

    // // 执行 mysql 导入命令
    // process.start("mysql", QStringList() << "-uroot" << "-p123456" << "copyhospital_registration");

    // if (process.waitForFinished() && process.exitCode() == 0) {
    //     QMessageBox::information(this, "恢复成功", "数据已回滚至选定备份点。");
    // } else {
    //     QMessageBox::critical(this, "错误", "恢复失败：" + process.readAllStandardError());
    // }
}


void admin::on_pushButton_3_add_clicked()
{
    // 1. 在表格末尾插入新行
    int rowCount = ui->tableWidget_3->rowCount();
    ui->tableWidget_3->insertRow(rowCount);

    // 2. 为新行的每一列创建空的 Item
    int columnCount = ui->tableWidget_3->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        QTableWidgetItem *item = new QTableWidgetItem("");
        // 设置背景颜色为浅黄色，提醒用户这一行是新加的，还没保存
        item->setBackground(QBrush(QColor(255, 255, 224)));
        ui->tableWidget_3->setItem(rowCount, col, item);
    }

    // 3. 自动滚动到新行并选中第一个单元格
    ui->tableWidget_3->setCurrentCell(rowCount, 0);
    ui->tableWidget_3->editItem(ui->tableWidget_3->item(rowCount, 1));
}


void admin::on_pushButton_3_del_clicked()
{
    //删除选定行
    // 1. 获取当前选中的行索引
    int currentRow = ui->tableWidget_3->currentRow(); // 假设你的表格变量名是 tableWidget_param
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先在表格中选中要删除的参数行！");
        return;
    }

    // 2. 获取该行的主键 Par_id (假设 Par_id 在第 0 列)
    QString parId = ui->tableWidget_3->item(currentRow, 0)->text();
    QString parName = ui->tableWidget_3->item(currentRow, 1)->text(); // 获取名称用于提示

    // 3. 弹出二次确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认删除",
                                  QString("确定要永久删除参数 [%1] (编号: %2) 吗？").arg(parName, parId),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return;
    }

    // 4. 执行删除 SQL 语句
    QSqlQuery query;
    query.prepare("DELETE FROM system_param WHERE Par_id = :id");
    query.bindValue(":id", parId.toInt());

    if (query.exec()) {
        QMessageBox::information(this, "成功", "系统参数已成功删除！");

        // 5. 刷新表格数据（调用你之前写的加载函数）
        loadsys();
    } else {
        QMessageBox::critical(this, "错误", "删除失败：" + query.lastError().text());
    }
}





void admin::on_pushButton_3_save_clicked()
{
    //如果选中的行是浅黄色，说明需要新增，要判断数据输入完全
    //否则是修改
    int currentRow = ui->tableWidget_3->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "提示", "请先选中您需要保存的那一行！");
        return;
    }

    QTableWidgetItem *firstItem = ui->tableWidget_3->item(currentRow, 0);
    if (!firstItem) return;

    // 获取背景颜色判断状态
    QColor bgColor = firstItem->background().color();
    bool isNewRow = (bgColor == QColor(255, 255, 224)); // 浅黄色

    // 1. 获取并清理输入数据
    QString id = ui->tableWidget_3->item(currentRow, 0)->text().trimmed();   // Par_id
    QString name = ui->tableWidget_3->item(currentRow, 1)->text().trimmed(); // Par_name
    QString value = ui->tableWidget_3->item(currentRow, 2)->text().trimmed(); // Par_value
    QString note = ui->tableWidget_3->item(currentRow, 3)->text().trimmed();  // Par_note

    // 2. 数据完整性校验 (核心校验)
    if (name.isEmpty() || value.isEmpty()) {
        QMessageBox::warning(this, "输入不完整", "参数名称和参数值不能为空！");
        return;
    }

    QSqlQuery query;
    if (isNewRow) {
        // ---- 新增逻辑 ----
        // 注意：Par_id 是自增的，通常不需要手动插入，除非你表格里让用户填了 ID
        query.prepare("INSERT INTO system_param (Par_name, Par_value, Par_note) "
                      "VALUES (:name, :value, :note)");
    } else {
        // ---- 修改逻辑 ----

        query.prepare("UPDATE system_param SET Par_name=:name, Par_value=:value, Par_note=:note "
                      "WHERE Par_id=:id");
        query.bindValue(":id", id.toInt());
    }

    // 3. 绑定通用参数
    query.bindValue(":name", name);
    query.bindValue(":value", value);
    query.bindValue(":note", note);

    // 4. 执行
    if (query.exec()) {
        QMessageBox::information(this, "成功", isNewRow ? "新增参数成功！        " : "修改已保存！         ");
        loadsys(); // 重新加载数据，颜色会自动变回白色
    } else {
        QMessageBox::critical(this, "数据库错误", query.lastError().text());
    }
}


void admin::on_pushButton_5_clicked()
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
    query.prepare("SELECT Adm_pwd FROM administrator WHERE Adm_id = :id");
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
        updateQuery.prepare("UPDATE administrator SET Adm_pwd = :newPwd WHERE Adm_id = :id");
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


#include "SellWidget.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QDate>

SellWidget::SellWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	addCustomerWidget_ = nullptr;

	db_ = nullptr;
	currentId_ = "";
	duty_ = DEFAULT_;




	// 
	//connect(ui.vip_lineEdit, &QLineEdit::editingFinished, this, &SellWidget::searchCustomer);
	//connect(ui.tel_lineEdit, &QLineEdit::returnPressed, this, &SellWidget::searchCustomer);

	connect(ui.type_comboBox, &QComboBox::currentTextChanged, this, &SellWidget::updateSkuComboBox);
	connect(ui.sku_comboBox, &QComboBox::currentTextChanged, this, &SellWidget::updateProductCheck);

	connect(ui.search_pushButton, &QPushButton::clicked, this, &SellWidget::searchCustomer);

	connect(ui.ok_pushButton, &QPushButton::clicked, this, &SellWidget::ok_pushButton_slot);
	connect(ui.cancle_pushButton, &QPushButton::clicked, this, &SellWidget::close);


	
}

SellWidget::~SellWidget()
{
	
		db_ = nullptr;
		if (addCustomerWidget_ != nullptr)
		{
			delete addCustomerWidget_;
			addCustomerWidget_ = nullptr;
		}
	
}

void SellWidget::searchCustomer()
{
	ui.nameInfo_lineEdit->clear();
	ui.telInfo_lineEdit->clear();
	ui.vipInfo_lineEdit->clear();
	ui.purchaseInfo_lineEdit->clear();
	ui.scoreInfo_lineEdit->clear();

	QString tel = ui.tel_lineEdit->text();
	QString vip = ui.vip_lineEdit->text();
	if (vip.size() > 0 && vip.length() < 6)
	{
		int res = 6 - vip.length();
		for (int i = 0; i < res; ++i)
			vip.insert(0, "0");
	}

	QVector<QString> fields;
	QString error;
	int numOfResult = -1;

	if (db_->open())
	{
		if (!tel.isEmpty())
		{
			numOfResult = searchStarInTable("customer", "tel", tel, fields, error);
			
		}
		else if (!vip.isEmpty())
		{
			numOfResult = searchStarInTable("customer", "vip", vip, fields, error);
		}
		
		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("错误"), tr("数据库打开失败"));
		return;
	}
	
	if (numOfResult == 1)
	{
		ui.nameInfo_lineEdit->setText(fields[1]);
		ui.telInfo_lineEdit->setText(fields[2]);
		ui.vipInfo_lineEdit->setText(fields[0]);
		ui.purchaseInfo_lineEdit->setText(fields[11]);
		ui.scoreInfo_lineEdit->setText(fields[12]);

		ui.product_groupBox->setDisabled(false);
	}
	else if(numOfResult >1)
	{	
		QMessageBox::information(this, tr("警告"), tr("找到多条记录，重新输入检索条件"));
		ui.product_groupBox->setDisabled(true);
	}
	else if (numOfResult < 0)
	{
		//QMessageBox::information(this, tr("错误"), error);
		ui.product_groupBox->setDisabled(true);
	}
	else
	{
		ui.product_groupBox->setDisabled(true);
		int result = QMessageBox::question(this, tr("提示"), tr("该用户不是会员，是否现在添加会员"), QMessageBox::Yes, QMessageBox::No);
		if (result == QMessageBox::Yes)
		{
			addCustomerWidget_ = new AddCustomerWidget(this);
			connect(this, &SellWidget::sendInfo, addCustomerWidget_, &AddCustomerWidget::receiveInfo);
			connect(this, &SellWidget::sendTel, addCustomerWidget_, &AddCustomerWidget::receiveTel);
			emit sendInfo(db_, duty_, currentId_);
			emit sendTel(tel);
			addCustomerWidget_->setWindowModality(Qt::WindowModal);
			//addCustomerWidget_->setAttribute(Qt::WA_DeleteOnClose);
			addCustomerWidget_->show();
		}
		else
		{
			//disconnect(ui.vip_lineEdit, &QLineEdit::editingFinished, this, &SellWidget::searchCustomer);
			//disconnect(ui.vip_lineEdit, &QLineEdit::returnPressed, this, &SellWidget::searchCustomer);
			//disconnect(ui.tel_lineEdit, &QLineEdit::editingFinished, this, &SellWidget::searchCustomer);
			//disconnect(ui.tel_lineEdit, &QLineEdit::returnPressed, this, &SellWidget::searchCustomer);
			return;
		}
			
	}
	
}

void SellWidget::updateSkuComboBox(const QString &text)
{
	QString tableName;
	QString sku;
	if (text == QObject::tr("隐形眼镜"))
	{
		tableName = "glass";
		sku = "glass_sku";
	}
	else if (text == QObject::tr("眼药水"))
	{
		tableName = "eyedrop";
		sku = "eyedrop_sku";
	}
	else if (text == QObject::tr("护理液"))
	{
		tableName = "nursing";
		sku = "nursing_sku";
	}		
	else if (text == QObject::tr("洗眼液"))
	{
		tableName = "wash";
		sku = "wash_sku";
	}
	else
	{

	}

	if (db_->open())
	{
		QString error;
		QStringList skuVecs;
		searchColumnInTable(tableName, sku, skuVecs, error);
		ui.sku_comboBox->clear();
		ui.sku_comboBox->addItems(skuVecs);
	}
	else
	{
		QMessageBox::information(this, tr("错误"), db_->lastError().text());
	}
	
	


}

void SellWidget::updateProductCheck(const QString & text)
{
	//QString sku = ui.sku_comboBox->currentText();
	QString sku = text;
	QString type = ui.type_comboBox->currentText();
	QString tableName;
	QString value;
	QString colName;
	if (type == QObject::tr("隐形眼镜"))
	{
		tableName = "glass";
		value = "glass_amount";
		colName = "glass_sku";
	}
	else if (type == QObject::tr("眼药水"))
	{
		tableName = "eyedrop";
		value = "eyedrop_amount";
		colName = "eyedrop_sku";
	}
	else if (type == QObject::tr("护理液"))
	{
		tableName = "nursing";
		value = "nursing_amount";
		colName = "nursing_sku";
	}
	else if (type == QObject::tr("洗眼液"))
	{
		tableName = "wash";
		value = "wash_amount";
		colName = "wash_sku";
	}
	else
	{
		;

	}

	QString sql = "select " + value + " from " + tableName + " where " + colName + " = '" + sku + "'";
	QSqlQuery query;
	if (db_->open())
	{
		if (query.exec(sql))
		{
			query.seek(-1);
			query.next();
			QString currentNum =  query.value(0).toString();
			ui.left_lineEdit->setText(currentNum);
			ui.sku_lineEdit->setText(sku);
		}
		else
		{
			QMessageBox::information(this, tr("错误"), query.lastError().text());
		}

		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("错误"), db_->lastError().text());
	}
}

int SellWidget::searchStarInTable(const QString & tableName, const QString &colName, const QString & value, QVector<QString>& fields, QString &error)
{
	int size = -1;
	fields.clear();
	QString sql = "select * from " + tableName + " where " + colName + " = '" + value + "'";
	QSqlQuery query;
	if (query.exec(sql))
	{
		size = query.size();
		if (size == 1)
		{
			int cols = query.record().count();
			query.seek(-1);
			query.next();
			for (int i = 0; i < cols; ++i)
			{
				fields.push_back(query.value(i).toString());
			}
		}
	}
	else
	{
		size = -1;
	}
	
	error = query.lastError().text();
	return size;
}

void SellWidget::searchColumnInTable(const QString &tableName, const QString &colName, QStringList & vec, QString &error)
{
	// TODO: insert return statement here
	vec.clear();
	QString sql = "select " + colName + " from " + tableName;
	QSqlQuery query;
	int numOfResult;
	if (query.exec(sql))
	{
		numOfResult = query.size();
		query.seek(-1);
		while (query.next())
		{
			vec.push_back(query.value(0).toString());
		}
		
	}
	else
	{
		error = query.lastError().text();
	}
}

void SellWidget::ok_pushButton_slot()
{
	// 获取所需变量
	
	QSqlQuery query;

	// 2. 获取会员信息
	QString vip = ui.vipInfo_lineEdit->text();
	
	int oldScore = ui.scoreInfo_lineEdit->text().toInt();
	int oldPurchaseNum = ui.purchaseInfo_lineEdit->text().toInt();

	// 获取产品信息
	QString sku = ui.sku_lineEdit->text();
	double singlePrice = ui.price_doubleSpinBox->value();
	int oneTime_number = ui.num_spinBox->value();
	double oneTime_consumption = singlePrice * oneTime_number;
	int currentAmount = ui.left_lineEdit->text().toInt();

	// 获取日期
	QString date = QDate::currentDate().toString("yyyy-MM-dd");

	// 判断库存、购买数量是否为0
	if (currentAmount == 0)
	{
		QMessageBox::information(this, tr("操作失败"), tr("该款卖光了, 补货后操作"));
		return;
	}
	if (oneTime_number == 0)
	{
		QMessageBox::information(this, tr("操作失败"), tr("输入数量"));
		return;
	}

	QString tableName;
	QString type = ui.type_comboBox->currentText();
	QString value, colName;
	if (type == QObject::tr("隐形眼镜"))
	{
		tableName = "glass";
		value = "glass_amount";
		colName = "glass_sku";
	}
	else if (type == QObject::tr("眼药水"))
	{
		tableName = "eyedrop";
		value = "eyedrop_amount";
		colName = "eyedrop_sku";
	}
	else if (type == QObject::tr("护理液"))
	{
		tableName = "nursing";
		value = "nursing_amount";
		colName = "nursing_sku";
	}
	else if (type == QObject::tr("洗眼液"))
	{
		tableName = "wash";
		value = "wash_amount";
		colName = "wash_sku";
	}
	else
	{
		;

	}
	// 再次核对信息
	QString checkNum; checkNum.setNum(oneTime_number);
	QString checkPrice; checkPrice.setNum(singlePrice);
	QString checkInfo = QObject::tr("请再次核对以下信息，订单出错将无法更改!\n") +
		QObject::tr("会员号：") + vip + QObject::tr(";     姓名：") + ui.nameInfo_lineEdit->text() + QObject::tr("\n")
		+ QObject::tr("SKU: ") + sku + QObject::tr(";     数量：") + checkNum + QObject::tr(";      单价：") + checkPrice + QObject::tr("元");
	int whether = QMessageBox::information(this, QObject::tr("再次核对订单"), checkInfo, QMessageBox::Ok, QMessageBox::Cancel);
	if (whether == QMessageBox::Cancel)
	{
		return;
	}
	
	if (db_->open())
	{
		// 1. 获取消费表主键
		QString orderSql = "select * from consumption";
		int order;
		if (query.exec(orderSql))
		{
			int size = query.size();
			order = query.size() + 1;
		}

		// 1. 添加购买记录
		QSqlQuery insert_query;
		QString order_str; order_str.setNum(order);
		QString consumption_str; consumption_str.setNum(oneTime_consumption);
		QString number_str; number_str.setNum(oneTime_number);
		QString insertSql = "insert into consumption values ('" + order_str + "', '" + vip + "', '" + sku + "', '" + consumption_str + "', '" + number_str + "', '" + date + "')";
		/*insert_query.prepare("insert into consumption (order, vip, sku, oneTime_consumption, oneTime_number, date) "
			"values (:order, :vip, :sku,  :oneTime_consumption, :oneTime_number, :date)");
		insert_query.bindValue(":order", QVariant(order));
		insert_query.bindValue(":vip", QVariant(vip));
		insert_query.bindValue(":sku", QVariant(sku));
		insert_query.bindValue(":oneTime_consumption", QVariant(oneTime_consumption));
		insert_query.bindValue(":oneTime_number", QVariant(oneTime_number));
		insert_query.bindValue(":date", QVariant(date));*/
		if (!insert_query.exec(insertSql))
		{
			QMessageBox::information(this, tr("操作失败"), insert_query.lastError().text());
			db_->close();
			return;
		}
		else
		{
			// 2. 插入成功后，更新相关表， 会员表：改积分和购买次数 ； 商品表： 该库存
			// a. 更新会员
			int score = (int)oneTime_consumption / 10;
			QString newScore; newScore.setNum(oldScore + score);
			QString newPurchaseNum; newPurchaseNum.setNum(oldPurchaseNum + 1);
			QString updateCustomerSql = "update customer set purchase_num = '" + newPurchaseNum + "', score = '" + newScore + "' where vip = '" + vip + "'";
			if (!query.exec(updateCustomerSql))
			{
				QMessageBox::information(this, tr("操作失败"), query.lastError().text());
				db_->close();
				return;
			}
			// b. 更新商品
			QString newAmount; newAmount.setNum(currentAmount - oneTime_number);
			QString updateProdSql = "update " + tableName + " set " + value + " ='" + newAmount + "' where " + colName + " = '" + sku + "'";

			if (!query.exec(updateProdSql))
			{
				QMessageBox::information(this, tr("操作失败"), query.lastError().text());
				db_->close();
				return;
			}

			// 更新界面
			ui.purchaseInfo_lineEdit->setText(newPurchaseNum);
			ui.scoreInfo_lineEdit->setText(newScore);
			ui.left_lineEdit->setText(newAmount);

			QString content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t新增销售: ") + order_str + QObject::tr(": ") + vip + QObject::tr(", 产品: ") + sku + QObject::tr(" ") + number_str + QObject::tr("个");
			writeLog(content);
			writeLogToDatabase(db_, currentId_, QObject::tr("销售"), order_str + QObject::tr(": ") + vip + QObject::tr(", 产品: ") + sku + QObject::tr(" ") + number_str + QObject::tr("个"), 0);
			QMessageBox::information(this, tr("完成"), tr("操作成功"));
		}
		
			
		
		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("错误"), db_->lastError().text());
	}
}

void SellWidget::initGUI()
{
	ui.nameInfo_lineEdit->setDisabled(true);
	ui.telInfo_lineEdit->setDisabled(true);
	ui.vipInfo_lineEdit->setDisabled(true);
	ui.purchaseInfo_lineEdit->setDisabled(true);
	ui.scoreInfo_lineEdit->setDisabled(true);

	
	ui.sku_lineEdit->setDisabled(true);
	ui.left_lineEdit->setDisabled(true);
	ui.product_groupBox->setDisabled(true);

	updateSkuComboBox("隐形眼镜");
}

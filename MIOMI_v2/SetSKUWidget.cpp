#include "SetSKUWidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
SetSKUWidget::SetSKUWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";
	model_ = nullptr;

	model_ = new QSqlTableModel(this);
	//connect(ui.tableView->horizontalHeader(), &QHeaderView::sectionClicked, this, &SetSKUWidget::mySort);

	connect(ui.save_pushButton, &QPushButton::clicked, this, &SetSKUWidget::save_pushButton_slot);
	connect(ui.cancel_pushButton, &QPushButton::clicked, this, &SetSKUWidget::close);
	
	// 输入结束，显示SKU
	connect(ui.glassMode_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayGlassSku);
	connect(ui.glassColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayGlassSku);
	connect(ui.glassDegree_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayGlassSku);

	connect(ui.eyedropBrand_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayEyedropSku);
	connect(ui.eyedropMode_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayEyedropSku);

	connect(ui.nursingBrand_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayNursingSku);
	connect(ui.nursingMode_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayNursingSku);
	connect(ui.nursingColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayNursingSku);

	connect(ui.washBrand_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayWashSku);
	connect(ui.washMode_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayWashSku);
	connect(ui.washColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::displayWashSku);


	// 颜色输入结束，自动去除“色”字
	connect(ui.glassColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::deleteLastChar);
	connect(ui.nursingColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::deleteLastChar);
	connect(ui.washColor_lineEdit, &QLineEdit::editingFinished, this, &SetSKUWidget::deleteLastChar);

	// 切换tab， 触发view更新
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &SetSKUWidget::changeTableView);

	// 双击，自动填充
	connect(ui.tableView, &QTableView::doubleClicked, this, &SetSKUWidget::obtainValues);
}

SetSKUWidget::~SetSKUWidget()
{

	db_ = nullptr;

	if (model_ != nullptr)
	{
		delete model_;
		model_ = nullptr;
	}
}

void SetSKUWidget::initGUI()
{
	ui.glassSku_lineEdit->setDisabled(true);
	ui.eyedropSku_lineEdit->setDisabled(true);
	ui.nursingSku_lineEdit->setDisabled(true);
	ui.washSku_lineEdit->setDisabled(true);

	ui.tabWidget->setCurrentIndex(0);
	changeTableView(ui.tabWidget->currentIndex());
}

void SetSKUWidget::changeTableView(int tabIdx)
{
	if (db_->open())
	{
		
		ui.tableName_label->setText(ui.tabWidget->tabText(ui.tabWidget->currentIndex()));
		if (ui.tabWidget->currentIndex() == 0)	// 眼镜
		{
			
			model_->setTable("glass");
			model_->select();
			int numOfFields = model_->record().count();
			QVector<QString> fieldNames(numOfFields);
			fieldNames.clear();
			fieldNames.push_back(QObject::tr("SKU"));
			fieldNames.push_back(QObject::tr("品牌"));
			fieldNames.push_back(QObject::tr("型号"));
			fieldNames.push_back(QObject::tr("颜色"));
			fieldNames.push_back(QObject::tr("度数"));
			fieldNames.push_back(QObject::tr("数量"));
			for (int i = 0; i < numOfFields; ++i)
			{
				model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
			}
			
			
		}

		if (ui.tabWidget->currentIndex() == 1) //	眼药水
		{
			model_->setTable("eyedrop");
			model_->select();
			int numOfFields = model_->record().count();
			QVector<QString> fieldNames(numOfFields);
			fieldNames.clear();
			fieldNames.push_back(QObject::tr("SKU"));
			fieldNames.push_back(QObject::tr("品牌"));
			fieldNames.push_back(QObject::tr("型号"));
			fieldNames.push_back(QObject::tr("数量"));
			for (int i = 0; i < numOfFields; ++i)
			{
				model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
			}
		}

		if (ui.tabWidget->currentIndex() == 2) // 护理液
		{
			model_->setTable("nursing");
			model_->select();
			int numOfFields = model_->record().count();
			QVector<QString> fieldNames(numOfFields);
			fieldNames.clear();
			fieldNames.push_back(QObject::tr("SKU"));
			fieldNames.push_back(QObject::tr("品牌"));
			fieldNames.push_back(QObject::tr("型号"));
			fieldNames.push_back(QObject::tr("颜色"));
			fieldNames.push_back(QObject::tr("数量"));
			for (int i = 0; i < numOfFields; ++i)
			{
				model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
			}
		}

		if (ui.tabWidget->currentIndex() == 3)	// 洗眼液
		{
			model_->setTable("wash");
			model_->select();
			int numOfFields = model_->record().count();
			QVector<QString> fieldNames(numOfFields);
			fieldNames.clear();
			fieldNames.push_back(QObject::tr("SKU"));
			fieldNames.push_back(QObject::tr("品牌"));
			fieldNames.push_back(QObject::tr("型号"));
			fieldNames.push_back(QObject::tr("颜色"));
			fieldNames.push_back(QObject::tr("数量"));
			for (int i = 0; i < numOfFields; ++i)
			{
				model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
			}
		}
		ui.tableView->setColumnWidth(0, 250);
		ui.tableView->setColumnWidth(1, 150);
		ui.tableView->sortByColumn(0);
		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);	// 设置行选中
		ui.tableView->setGridStyle(Qt::DashLine);
		ui.tableView->setModel(model_);
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

		db_->close();
	}
	
}

void SetSKUWidget::processGlass()
{
	QString brand = ui.glassbrand_comboBox->currentText();
	QString mode = ui.glassMode_lineEdit->text();
	QString color = ui.glassColor_lineEdit->text();
	// 判断最后是否有“色”字
	/*QString lastChar = color.back();
	if (lastChar == QObject::tr("色"))
		color.remove(QObject::tr("色"));*/
	QString degree = ui.glassDegree_lineEdit->text();
	QString sku = getGlassSKU(brand, mode, color, degree);
	int amount = ui.glassAmount_spinBox->value();
	if (!sku.isEmpty())
	{
		QString content;

		if (db_->open())
		{
			int currentAmount;
			if (skuHasExist("glass", "glass_amount", "glass_sku", sku, currentAmount))	// 已经存在， 只需更新
			{
				int newAmount = currentAmount + amount;
				if (updateAmount("glass", "glass_amount", "glass_sku", sku, newAmount))
				{
					QString num; num = num.setNum(amount);
					QString newNum; newNum = newNum.setNum(newAmount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("当前库存: ") + newNum;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("当前库存: ") + newNum, 1);
					ui.glassAmount_spinBox->setValue(0);
				}
				else
				{
					QMessageBox::information(this, QObject::tr("错误"), QObject::tr("添加过程出错"));
					db_->close();
					return;
				}
			}
			else     // 不存在，需要添加
			{
				QSqlQuery insert_query;
				insert_query.prepare("insert into glass (glass_sku, glass_brand, glass_mode, glass_color, glass_degree, glass_amount) "
					"values (:glass_sku, :glass_brand, :glass_mode, :glass_color, :glass_degree, :glass_amount)");
				insert_query.bindValue(":glass_sku", sku);
				insert_query.bindValue(":glass_brand", brand);
				insert_query.bindValue(":glass_mode", mode);
				insert_query.bindValue(":glass_color", color);
				insert_query.bindValue(":glass_degree", degree);
				insert_query.bindValue(":glass_amount", amount);


				if (!insert_query.exec())
				{
					QMessageBox::information(this, tr("添加错误"), insert_query.lastError().text());
					db_->close();
					return;
				}
				else  // 添加成功
				{
					//ui.glassAmount_spinBox->setValue(0);
					QString num; num = num.setNum(amount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num, 1);
				}
			}
			db_->close();
			ui.glassMode_lineEdit->clear();
			ui.glassColor_lineEdit->clear();
			ui.glassDegree_lineEdit->clear();
			ui.glassSku_lineEdit->clear();
			ui.glassAmount_spinBox->setValue(0);

		}
		else {
			QMessageBox::information(this, tr("错误"), tr("数据库打开失败") + db_->lastError().text());
		}
	}
	else
	{
		QMessageBox::information(this, tr("提示"), tr("信息输入完整"));
	}
	
	
}

void SetSKUWidget::processEyedrop()
{
	QString brand = ui.eyedropBrand_lineEdit->text();
	QString mode = ui.eyedropMode_lineEdit->text();
	QString sku = getGlassSKU(brand, mode);
	int amount = ui.eyedropAmount_spinBox->value();

	if (sku.isEmpty())
	{
		QMessageBox::information(this, tr("警告"), tr("信息输入不完整"));
		return;
	}
	else
	{
		if (db_->open())
		{
			QString content;
			int currentAmount;
			if (skuHasExist("eyedrop", "eyedrop_amount", "eyedrop_sku", sku, currentAmount))	// 已经存在， 只需更新
			{
				int newAmount = currentAmount + amount;
				if (updateAmount("eyedrop", "eyedrop_amount", "eyedrop_sku", sku, newAmount))
				{
					QString num; num = num.setNum(amount);
					QString newNum; newNum = newNum.setNum(newAmount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum, 1);
					ui.glassAmount_spinBox->setValue(0);
				}
				else
				{
					QMessageBox::information(this, QObject::tr("错误"), QObject::tr("添加过程出错"));
					db_->close();
					return;
				}
			}
			else     // 不存在，需要添加
			{
				QSqlQuery insert_query;
				insert_query.prepare("insert into eyedrop (eyedrop_sku, eyedrop_brand, eyedrop_mode, eyedrop_amount) "
					"values (:eyedrop_sku, :eyedrop_brand, :eyedrop_mode, :eyedrop_amount )");
				insert_query.bindValue(":eyedrop_sku", sku);
				insert_query.bindValue(":eyedrop_brand", brand);
				insert_query.bindValue(":eyedrop_mode", mode);
				insert_query.bindValue(":eyedrop_amount", amount);


				if (!insert_query.exec())
				{
					QMessageBox::information(this, tr("添加错误"), insert_query.lastError().text());
					db_->close();
					return;
				}
				else  // 添加成功
				{
					//ui.glassAmount_spinBox->setValue(0);
					QString num; num = num.setNum(amount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num, 1);
				}
			}
			db_->close();
			ui.eyedropBrand_lineEdit->clear();
			ui.eyedropMode_lineEdit->clear();
			ui.eyedropSku_lineEdit->clear();
			ui.eyedropAmount_spinBox->setValue(0);

		}
		else {
			QMessageBox::information(this, tr("错误"), tr("数据库打开失败") + db_->lastError().text());
		}
	}

	
}

void SetSKUWidget::processNursing()
{
	QString brand = ui.nursingBrand_lineEdit->text();
	QString mode = ui.nursingMode_lineEdit->text();
	QString color = ui.nursingColor_lineEdit->text();
	QString sku = getGlassSKU(brand, mode, color);
	int amount = ui.nursingAmount_spinBox->value();

	if (sku.isEmpty())
	{
		QMessageBox::information(this, tr("警告"), tr("信息输入不完整"));
		return;
	}
	else
	{
		if (db_->open())
		{
			QString content;
			int currentAmount;
			if (skuHasExist("nursing", "nursing_amount", "nursing_sku", sku, currentAmount))	// 已经存在， 只需更新
			{
				int newAmount = currentAmount + amount;
				if (updateAmount("nursing", "nursing_amount", "nursing_sku", sku, newAmount))
				{
					QString num; num = num.setNum(amount);
					QString newNum; newNum = newNum.setNum(newAmount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum, 1);
					ui.glassAmount_spinBox->setValue(0);
				}
				else
				{
					QMessageBox::information(this, QObject::tr("错误"), QObject::tr("添加过程出错"));
					db_->close();
					return;
				}
			}
			else     // 不存在，需要添加
			{
				QSqlQuery insert_query;
				insert_query.prepare("insert into nursing (nursing_sku, nursing_brand, nursing_mode, nursing_color, nursing_amount) "
					"values (:nursing_sku, :nursing_brand, :nursing_mode, :nursing_color, :nursing_amount )");
				insert_query.bindValue(":nursing_sku", sku);
				insert_query.bindValue(":nursing_brand", brand);
				insert_query.bindValue(":nursing_mode", mode);
				insert_query.bindValue(":nursing_color", color);
				insert_query.bindValue(":nursing_amount", amount);


				if (!insert_query.exec())
				{
					QMessageBox::information(this, tr("添加错误"), insert_query.lastError().text());
					db_->close();
					return;
				}
				else  // 添加成功
				{
					//ui.glassAmount_spinBox->setValue(0);
					QString num; num = num.setNum(amount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num, 1);
				}
			}
			db_->close();
			ui.eyedropBrand_lineEdit->clear();
			ui.eyedropMode_lineEdit->clear();
			ui.eyedropSku_lineEdit->clear();
			ui.eyedropAmount_spinBox->setValue(0);

		}
		else {
			QMessageBox::information(this, tr("错误"), tr("数据库打开失败") + db_->lastError().text());
		}
	}

}

void SetSKUWidget::processWash()
{
	QString brand = ui.washBrand_lineEdit->text();
	QString mode = ui.washMode_lineEdit->text();
	QString color = ui.washColor_lineEdit->text();
	QString sku = getGlassSKU(brand, mode, color);
	int amount = ui.washAmount_spinBox->value();

	if (sku.isEmpty())
	{
		QMessageBox::information(this, tr("警告"), tr("信息输入不完整"));
		return;
	}
	else
	{
		if (db_->open())
		{
			QString content;
			int currentAmount;
			if (skuHasExist("wash", "wash_amount", "wash_sku", sku, currentAmount))	// 已经存在， 只需更新
			{
				int newAmount = currentAmount + amount;
				if (updateAmount("wash", "wash_amount", "wash_sku", sku, newAmount))
				{
					QString num; num = num.setNum(amount);
					QString newNum; newNum = newNum.setNum(newAmount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + newNum, 1);
					ui.glassAmount_spinBox->setValue(0);
				}
				else
				{
					QMessageBox::information(this, QObject::tr("错误"), QObject::tr("添加过程出错"));
					db_->close();
					return;
				}
			}
			else     // 不存在，需要添加
			{
				QSqlQuery insert_query;
				insert_query.prepare("insert into wash (wash_sku, wash_brand, wash_mode, wash_color, wash_amount) "
					"values (:wash_sku, :wash_brand, :wash_mode, :wash_color, :wash_amount )");
				insert_query.bindValue(":wash_sku", sku);
				insert_query.bindValue(":wash_brand", brand);
				insert_query.bindValue(":wash_mode", mode);
				insert_query.bindValue(":wash_color", color);
				insert_query.bindValue(":wash_amount", amount);


				if (!insert_query.exec())
				{
					QMessageBox::information(this, tr("添加错误"), insert_query.lastError().text());
					db_->close();
					return;
				}
				else  // 添加成功
				{
					//ui.glassAmount_spinBox->setValue(0);
					QString num; num = num.setNum(amount);
					content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t操作进货SKU, 添加了") + num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num;
					writeLog(content);
					writeLogToDatabase(db_, currentId_, QObject::tr("进货"), num + QObject::tr("个 ") + sku + QObject::tr(". ") + QObject::tr("现在总数: ") + num, 1);
				}
			}
			db_->close();
			ui.eyedropBrand_lineEdit->clear();
			ui.eyedropMode_lineEdit->clear();
			ui.eyedropSku_lineEdit->clear();
			ui.eyedropAmount_spinBox->setValue(0);

		}
		else {
			QMessageBox::information(this, tr("错误"), tr("数据库打开失败") + db_->lastError().text());
		}
	}
}


QString SetSKUWidget::getGlassSKU(const QString & brand, const QString & mode, const QString & color, const QString & degree)
{
	QString sku;
	if (brand.size() != 0 && mode.size() != 0)
	{
		if (color.size() == 0 && degree.size() == 0)
		{
			sku = brand + "-" + mode;
			return sku;
		}

		if (degree.size() == 0)
		{
			sku = brand + "-" + mode + "-" + color;
			return sku;
		}

		sku = brand + "-" + mode + "-" + color + "-" + degree;
		return sku;
	}
	return "";
	
	
}

bool SetSKUWidget::skuHasExist(const QString & tableName, const QString &col, const QString & item, const QString &value, int & amount)
{
	amount = -1;
	QSqlQuery query;
	QString sql = "select " + col + " from " + tableName + " where " + item + " = '" + value + "'";
	query.exec(sql);
	if (query.first())
	{
		int numOfItem = query.size();
		//if (numOfItem > 1)
		//{
		//	QMessageBox::information(this, tr("错误"), tr("数据库中存在多条相同的SKU"));
		//	return false;
		//}
		query.seek(-1); 
		query.next();
		amount = query.value(0).toInt();
		return true;
	}
	else
	{
		amount = 0;
		return false;
	}
		
	
}

bool SetSKUWidget::updateAmount(const QString & tableName, const QString & col, const QString & item, const QString & value, const int & amount)
{
	QSqlQuery query;
	QString newValue; 
	newValue = newValue.setNum(amount);

	QString sql = "update " + tableName + " set " + col + " = '" + newValue + "' where " + item + " = '" + value + "'";
	if (query.exec(sql))
	{
		return true;
	}

	return false;
}

void SetSKUWidget::save_pushButton_slot()
{
	if(ui.tabWidget->currentIndex() == 0)
		processGlass();
	else if(ui.tabWidget->currentIndex() == 1)
		processEyedrop();
	else if(ui.tabWidget->currentIndex() == 2)
		processNursing();
	else if(ui.tabWidget->currentIndex() == 3)
		processWash();

	changeTableView(ui.tabWidget->currentIndex());
}

void SetSKUWidget::displayGlassSku()
{
	QString brand = ui.glassbrand_comboBox->currentText();
	QString mode = ui.glassMode_lineEdit->text();
	QString color = ui.glassColor_lineEdit->text();
	QString degree = ui.glassDegree_lineEdit->text();
	
		
	QString sku = getGlassSKU(brand, mode, color, degree);
	if (mode.size() != 0 && color.size() != 0 && degree.size() != 0)
		ui.glassSku_lineEdit->setText(sku);
}

void SetSKUWidget::displayEyedropSku()
{
	QString brand = ui.eyedropBrand_lineEdit->text();
	QString mode = ui.eyedropMode_lineEdit->text();


	QString sku = getGlassSKU(brand, mode);
	if (brand.size() != 0 && mode.size() != 0)
		ui.eyedropSku_lineEdit->setText(sku);
}

void SetSKUWidget::displayNursingSku()
{
	QString brand = ui.nursingBrand_lineEdit->text();
	QString mode = ui.nursingMode_lineEdit->text();
	QString color = ui.nursingColor_lineEdit->text();

	QString sku = getGlassSKU(brand, mode, color);
	if (brand.size() != 0 && mode.size() != 0 && color.size() != 0)
		ui.nursingSku_lineEdit->setText(sku);
}

void SetSKUWidget::displayWashSku()
{
	QString brand = ui.washBrand_lineEdit->text();
	QString mode = ui.washMode_lineEdit->text();
	QString color = ui.washColor_lineEdit->text();

	QString sku = getGlassSKU(brand, mode, color);
	if (brand.size() != 0 && mode.size() != 0 && color.size() != 0)
		ui.washSku_lineEdit->setText(sku);
}

void SetSKUWidget::deleteLastChar()
{
	QString color;
	if (ui.tabWidget->currentIndex() == 0)
	{
		color = ui.glassColor_lineEdit->text();
		if (color.size() > 0)
		{
			if (color.back() == QObject::tr("色"))
				color.remove(QObject::tr("色"));
			ui.glassColor_lineEdit->setText(color);
		}
		
	}
	
	if (ui.tabWidget->currentIndex() == 2)  // 护理液
	{
		color = ui.nursingColor_lineEdit->text();
		if (color.size() > 0)
		{
			if (color.back() == QObject::tr("色"))
				color.remove(QObject::tr("色"));
			ui.nursingColor_lineEdit->setText(color);
		}
		
	}
	if (ui.tabWidget->currentIndex() == 3)  // 护理液
	{
		color = ui.washColor_lineEdit->text();
		if (color.size() > 0)
		{
			if (color.back() == QObject::tr("色"))
				color.remove(QObject::tr("色"));
			ui.washColor_lineEdit->setText(color);
		}

	}

}

void SetSKUWidget::mySort(int col)
{
	if (db_->open())
	{
		ui.tableView->sortByColumn(col, Qt::AscendingOrder);
		ui.tableView->setModel(model_);
		db_->close();
	}
		
}

void SetSKUWidget::obtainValues(const QModelIndex & index)
{
	QSqlRecord record = model_->record(index.row());
	if (ui.tabWidget->currentIndex() == 0)	// 眼镜
	{
		QString sku = model_->record(index.row()).value(0).toString();
		QString brand = model_->record(index.row()).value(1).toString();
		QString mode = model_->record(index.row()).value(2).toString();
		QString color = model_->record(index.row()).value(3).toString();
		QString degree = model_->record(index.row()).value(4).toString();

		ui.glassbrand_comboBox->setCurrentText(brand);
		ui.glassMode_lineEdit->setText(mode);
		ui.glassColor_lineEdit->setText(color);
		ui.glassDegree_lineEdit->setText(degree);
		ui.glassSku_lineEdit->setText(sku);
	}
	if (ui.tabWidget->currentIndex() == 1)	//眼药水
	{
		QString sku = model_->record(index.row()).value(0).toString();
		QString brand = model_->record(index.row()).value(1).toString();
		QString mode = model_->record(index.row()).value(2).toString();

		ui.eyedropBrand_lineEdit->setText(brand);
		ui.eyedropMode_lineEdit->setText(mode);
		ui.eyedropSku_lineEdit->setText(sku);
	}
	
	if (ui.tabWidget->currentIndex() == 2)	// 护理液
	{
		QString sku = model_->record(index.row()).value(0).toString();
		QString brand = model_->record(index.row()).value(1).toString();
		QString mode = model_->record(index.row()).value(2).toString();
		QString color = model_->record(index.row()).value(3).toString();

		ui.nursingBrand_lineEdit->setText(brand);
		ui.nursingMode_lineEdit->setText(mode);
		ui.nursingColor_lineEdit->setText(color);
		ui.nursingSku_lineEdit->setText(sku);
	}

	if (ui.tabWidget->currentIndex() == 3)
	{
		QString sku = model_->record(index.row()).value(0).toString();
		QString brand = model_->record(index.row()).value(1).toString();
		QString mode = model_->record(index.row()).value(2).toString();
		QString color = model_->record(index.row()).value(3).toString();

		ui.washBrand_lineEdit->setText(brand);
		ui.washMode_lineEdit->setText(mode);
		ui.washColor_lineEdit->setText(color);
		ui.washSku_lineEdit->setText(sku);
	}
}

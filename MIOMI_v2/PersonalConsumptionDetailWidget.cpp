#include "PersonalConsumptionDetailWidget.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>


PersonalConsumptionDetailWidget::PersonalConsumptionDetailWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	model_ = nullptr;
	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";

	connect(ui.search_pushButton, &QPushButton::clicked, this, &PersonalConsumptionDetailWidget::search_pushButton_slot);
}

PersonalConsumptionDetailWidget::~PersonalConsumptionDetailWidget()
{
	db_ = nullptr;
	if (model_ != nullptr)
	{
		delete model_;
		model_ = nullptr;
	}
}



double PersonalConsumptionDetailWidget::computeTotalMoney()
{
	double totalMoney = 0.0;
	if (model_ != nullptr)
	{
		
		QSqlQuery query = model_->query();
		query.seek(-1);
		while (query.next())
		{
			totalMoney += query.value(3).toDouble();
		}
		
	}
	return totalMoney;
}

void PersonalConsumptionDetailWidget::search_pushButton_slot()
{

	QString vip = ui.vip_lineEdit->text();
	QString tel = ui.tel_lineEdit->text();
	if (vip.size() > 0 && vip.length() < 6)
	{
		int res = 6 - vip.length();
		for (int i = 0; i < res; ++i)
			vip.insert(0, "0");
	}

	if (db_->open())
	{
		QString sql;
		if (!vip.isEmpty())
		{
			sql = "vip = '" + vip + "'";
		}
		else if (!tel.isEmpty())
		{
			// sql = " tel = '" + tel + "'";
			// 先找vip
			QSqlQuery query("select vip from customer where tel = '" + tel + "'");
			if (!query.exec())
			{
				QMessageBox::information(this, tr("失败"), tr("未找到"));
				db_->close();
			}
			else
			{
				query.seek(-1);
				query.next();
				vip = query.value(0).toString();
				sql = "vip = '" + vip + "'";
			}
		}

		model_->setFilter(sql);
		if (model_->query().exec())
		{
			if (model_->query().size() < 1)
			{
				QMessageBox::information(this, tr("查询结果"), tr("未找到消费记录"));
			}
			else
			{		// 找到
				ui.tableView->setModel(model_);
				double totalMoney = computeTotalMoney();
				QString moneyLableContent; moneyLableContent.setNum(totalMoney);
				ui.moneylabel->setText(QObject::tr("总金额: ") + moneyLableContent);

				ui.vip_lineEdit->clear();
				ui.tel_lineEdit->clear();

			}
		}
		else
		{
			QMessageBox::information(this, tr("错误"), model_->query().lastError().text());
		}

		db_->close();
	}

}

void PersonalConsumptionDetailWidget::initGUI()
{
	

	// 左侧
	if (db_->open())
	{
		model_ = new QSqlTableModel(nullptr, *db_);
		model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
		model_->setTable("consumption");
		model_->select();

		int numOfFields = model_->record().count();

		fieldNames_.clear();
		fieldNames_.push_back(QObject::tr("单号"));
		fieldNames_.append(QObject::tr("会员号"));
		fieldNames_.append(QObject::tr("SKU"));
		fieldNames_.append(QObject::tr("单次消费金额"));
		fieldNames_.append(QObject::tr("单次购买数量"));
		fieldNames_.append(QObject::tr("日期"));

		for (int i = 0; i < numOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames_.at(i));
		}
		//model_->setHeaderData(0, Qt::Horizontal, tr("会员号"));

		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);		// 设置行选中

		ui.tableView->setGridStyle(Qt::DashLine);
		
		ui.tableView->setModel(model_);
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		ui.tableView->setColumnWidth(2, 200);
		double totalMoney = computeTotalMoney();
		QString moneyLableContent; moneyLableContent.setNum(totalMoney);
		ui.moneylabel->setText(QObject::tr("总金额: ") + moneyLableContent);

		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("中断"), db_->lastError().text());
		return;
	}
	

}

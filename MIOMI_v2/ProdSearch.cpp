#include "ProdSearch.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <cassert>
ProdSearch::ProdSearch(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	for (int i = 0; i < 4; ++i)
	{
		models_[i] = nullptr;
	}

	db_ = nullptr;
	
	currentId_ = "";
	duty_ = DEFAULT_;


	
	allSkus_.clear();
	allSaleAmount_.clear();
	allMoney_.clear();
	allStock_.clear();


	connect(ui.search_pushButton, &QPushButton::clicked, this, &ProdSearch::search_pushButton_slot);

}

ProdSearch::~ProdSearch()
{
	db_ = nullptr;

	for (int i = 0; i < 4; ++i)
	{
		if (models_[i] != nullptr)
		{
			delete models_[i];
			models_[i] = nullptr;
		}
	}
}


void ProdSearch::obtainAllSkuAndStock(int n)
{
	allSkus_.clear();
	allStock_.clear();
	QString sql;
	for (int i = 0; i < n; ++i)
	{
		if(i == 0)
			sql = "select glass_sku, glass_amount from glass";
		if (i == 1)
			sql = "select eyedrop_sku, eyedrop_amount from eyedrop";
		if (i == 2)
			sql = "select nursing_sku, nursing_amount from nursing";
		if (i == 3)
			sql = "select wash_sku, wash_amount from wash";

		QVector<QString> thisSkus;
		QVector<int> thisStock;
		thisSkus.clear();
		thisStock.clear();

		QSqlQuery query(sql);
		if (!query.exec())
		{
			QMessageBox::information(this, tr("错误"), query.lastError().text());
			return;
		}
		else
		{
			query.seek(-1);
			while (query.next())
			{
				thisSkus.push_back(query.value(0).toString());
				thisStock.push_back(query.value(1).toInt());
				//qDebug() << query.value(0).toString();
			}
			allSkus_.push_back(thisSkus);
			allStock_.push_back(thisStock);
		}
	}
	assert(allSkus_.size() == allStock_.size());
	for (int i = 0; i < allStock_.size(); ++i)
	{
		assert(allSkus_[i].size() == allStock_[i].size());
	}

}

void ProdSearch::obtainAllSaleAmount(const QString &begin, const QString &end)
{
	allSaleAmount_.clear();
	for (int i = 0; i < 4; ++i)
	{
		QVector<QString> sku = allSkus_[i];
		QVector<int> thisAmount; thisAmount.clear();
		for (int j = 0; j < sku.size(); ++j)
		{
			
			int saleAmount = 0;
			QString sku_str = sku[j];
			QString sql = "select oneTime_number from consumption where  sku = '" + sku_str + "' and date >= '" + begin + "' and date <= '" + end + "'";
			QSqlQuery query(sql);
			if (!query.exec())
			{
				QMessageBox::information(this, tr("错误"), query.lastError().text());
				return;
			}
			else
			{
				qDebug() << query.size();
				if (query.size() == 0)
					saleAmount = 0;
				else
				{
					query.seek(-1);
					while (query.next())
					{
						int amount = query.value(0).toInt();
						saleAmount += amount;
					}
				}
				thisAmount.push_back(saleAmount);
			}
			
		}
		allSaleAmount_.push_back(thisAmount);
		
	}

}

void ProdSearch::obtainAllMoney(const QString & begin, const QString & end)
{
	allMoney_.clear();
	for (int i = 0; i < 4; ++i)
	{
		QVector<double> money;
		QVector<QString> sku = allSkus_[i];
		for (int j = 0; j < sku.size(); ++j)
		{
			int saleMoney = 0;
			QString sku_str = sku[j];
			QString sql = "select oneTime_consumption from consumption where  sku = '" + sku_str + "' and date >= '" + begin + "' and date <= '" + end + "'";
			QSqlQuery query(sql);
			if (!query.exec())
			{
				QMessageBox::information(this, tr("错误"), query.lastError().text());
				return;
			}
			else
			{
				if (query.size() == 0)
					saleMoney = 0;
				else
				{
					query.seek(-1);
					while (query.next())
					{
						int amount = query.value(0).toDouble();
						saleMoney += amount;
					}
				}
				money.push_back(saleMoney);
			}
		}
		allMoney_.push_back(money);
	}
}



void ProdSearch::search_pushButton_slot()
{
	if (db_->open())
	{
		QString beginTime = ui.from_dateEdit->date().toString("yyyy-MM-dd");
		QString endTime = ui.to_dateEdit->date().toString("yyyy-MM-dd");
		obtainAllSaleAmount(beginTime, endTime);
		obtainAllMoney(beginTime, endTime);

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < allSkus_[i].size(); ++j)
			{
				QString sku = allSkus_[i][j];
				QString amount; amount.setNum(allSaleAmount_[i][j]);
				QString money; money.setNum(allMoney_[i][j]);
				QString stock; stock.setNum(allStock_[i][j]);
				//QStandardItem sku_item(sku);
				//QStandardItem amount_item(amount);
				//QStandardItem money_item(money);
				//QStandardItem stock_item(stock);
				//models_[i]->setItem(j, 0, &sku_item);
				//models_[i]->setItem(j, 1, &amount_item);
				//models_[i]->setItem(j, 2, &money_item);
				//models_[i]->setItem(j, 3, &stock_item);
				models_[i]->setItem(j, 0, new QStandardItem(sku));
				models_[i]->setItem(j, 1, new QStandardItem(amount));
				models_[i]->setItem(j, 2, new QStandardItem(money));
				models_[i]->setItem(j, 3, new QStandardItem(stock));
			}
			//view[i]->setModel(models_[i]);
		}
		
		QString totalMoney, glassMoney, eyedropMoney, nursingMoney, washMoney;
		computeTotalMoney(totalMoney, glassMoney, eyedropMoney, nursingMoney, washMoney);
		ui.glassMoney_label->setText(glassMoney);
		ui.eyedropMoney_label->setText(eyedropMoney);
		ui.nursingMoney_label->setText(nursingMoney);
		ui.washMoney_label->setText(washMoney);
		ui.moneyLabel->setText(totalMoney);

		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("错误"), db_->lastError().text());
		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		view[i]->setModel(models_[i]);
		view[i]->setColumnWidth(0, 200);
		view[i]->setColumnWidth(1, 60);
		view[i]->setColumnWidth(2, 60);
		view[i]->setColumnWidth(3, 70);

		// 整行选中
		view[i]->setSelectionBehavior(QAbstractItemView::SelectRows);
		// 不可编辑
		view[i]->setEditTriggers(QAbstractItemView::NoEditTriggers);

		// 排序
		models_[i]->sort(1, Qt::DescendingOrder);
	}
	
}

void ProdSearch::computeTotalMoney(QString & totalMoney, QString & glassMoney, QString & eyedropMoney, QString & nursingMoney, QString & washMoney)
{
	// QVector<QVector<double> > allMoney_;
	
	double money[4] = { 0.0 };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < allMoney_[i].size(); ++j)
		{
			money[i] += allMoney_[i][j];
		}
	}
	glassMoney = glassMoney.setNum(money[0]);
	eyedropMoney = eyedropMoney.setNum(money[1]);
	nursingMoney = nursingMoney.setNum(money[2]);
	washMoney = washMoney.setNum(money[3]);

	totalMoney = totalMoney.setNum(money[0] + money[1] + money[2] + money[3]);
}

void ProdSearch::initGUI()
{
	view[0] = ui.glass_tableView;
	view[1] = ui.eyedrop_tableView;
	view[2] = ui.nursing_tableView;
	view[3] = ui.wash_tableView;

	ui.from_dateEdit->setDate(QDate::currentDate());
	ui.to_dateEdit->setDate(QDate::currentDate());


	if (db_->open())
	{
		obtainAllSkuAndStock(4);
		db_->close();
	}


	// 设置表头 和 列宽
	for (int i = 0; i < 4; ++i)
	{
		models_[i] = new QStandardItemModel();
		models_[i]->setHorizontalHeaderItem(0, new QStandardItem(tr("SKU")));
		models_[i]->setHorizontalHeaderItem(1, new QStandardItem(tr("销量")));
		models_[i]->setHorizontalHeaderItem(2, new QStandardItem(tr("金额")));
		models_[i]->setHorizontalHeaderItem(3, new QStandardItem(tr("现有库存")));

	}

	

	

}


#include "SearchCustomerWidget.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QVector>
#include <QMessageBox>
SearchCustomerWidget::SearchCustomerWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";
	model_ = nullptr;

	connect(ui.search_pushButton, &QPushButton::clicked, this, &SearchCustomerWidget::search_pushButton_slot);

	searchTimer = new QTimer(this);
	connect(searchTimer, &QTimer::timeout, this, &SearchCustomerWidget::search_pushButton_slot);
	//searchTimer->start(10000);
}

SearchCustomerWidget::~SearchCustomerWidget()
{
	db_ = nullptr;

	if (model_ != nullptr)
	{
		delete model_;
		model_ = nullptr;
	}
}

void SearchCustomerWidget::search_pushButton_slot()
{
	QString tel = ui.tel_lineEdit->text();
	QString name = ui.name_lineEdit->text();
	QString vip = ui.vip_lineEdit->text();
	if (vip.size() != 0 && vip.length() < 6)
	{
		int res = 6 - vip.length();
		for (int i = 0; i < res; ++i)
		{
			vip.insert(0, "0");
		}
	}

	
	
	if (db_->open())
	{
		model_ = new QSqlTableModel(this, *db_);
		model_->setTable("customer");
		model_->select();
		QString sqlWhere;
		if (!tel.isEmpty())
		{

			sqlWhere = "tel like '%" + tel + "%'";
		}
		else if (!name.isEmpty())
		{
			sqlWhere = "name like '%" + name + "%'";
		}
		else if (!vip.isEmpty())
		{
			sqlWhere = "vip like '%" + vip + "%'";
		}
		else
			sqlWhere = "";

		model_->setFilter(sqlWhere);
		int numOfFields = model_->record().count();
		QVector<QString> fieldNames(numOfFields);
		fieldNames.clear();
		fieldNames.push_back(QObject::tr("会员号"));
		fieldNames.append(QObject::tr("姓名"));
		fieldNames.append(QObject::tr("电话"));
		fieldNames.append(QObject::tr("性别"));
		fieldNames.append(QObject::tr("微信"));
		fieldNames.append(QObject::tr("QQ"));
		fieldNames.append(QObject::tr("地址"));
		fieldNames.append(QObject::tr("近视度数(左)"));
		fieldNames.append(QObject::tr("近视度数(右)"));
		fieldNames.append(QObject::tr("散光度数(左)"));
		fieldNames.append(QObject::tr("散光度数(右)"));
		fieldNames.append(QObject::tr("购买数量"));
		fieldNames.append(QObject::tr("积分"));
		for (int i = 0; i < numOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
		}
		//model_->setHeaderData(0, Qt::Horizontal, tr("会员号"));
		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);	// 设置行选中
		ui.tableView->setGridStyle(Qt::DashLine);
		ui.tableView->setModel(model_);
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

		QString content;
		if (!model_->query().first())
		{
			//QMessageBox::information(this, tr("提示"), tr("未找到对应条目"));
			content = QObject::tr("工号： ") + currentId_ + QObject::tr("查询操作 ") + sqlWhere + QObject::tr(" 未找到对应条目") + model_->query().lastError().text();
		}
		else
		{
			content = QObject::tr("工号： ") + currentId_ + QObject::tr("查询操作 ") + sqlWhere;
			// 使用了自动刷新，不能清空，如果清空，需要改动的代码比较多，需重设逻辑
			/*ui.tel_lineEdit->clear();
			ui.name_lineEdit->clear();
			ui.vip_lineEdit->clear();*/
			//writeLog(content);
			//writeLog(content, 1); // 如果失败，改写入系统日志
		}

		
		
		db_->close();
	}
	else
	{
		QString content = QObject::tr("工号: ") + currentId_ + QObject::tr("\t数据库连接失败") + db_->lastError().text();
		QMessageBox::information(this, tr("错误"), tr("数据库连接失败") + db_->lastError().text());
		writeLog(content, 1);
	}
	
}

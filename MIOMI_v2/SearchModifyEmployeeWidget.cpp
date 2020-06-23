#include "SearchModifyEmployeeWidget.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>

#include "Delegate.h"
#include <cassert>
#include <QMenu>
SearchModifyEmployeeWidget::SearchModifyEmployeeWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	search_timer = nullptr;
	save_timer = nullptr;

	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";
	model_ = nullptr;

	

	createRightMenu();
	connect(ui.tableView, &QTableView::customContextMenuRequested, this, &SearchModifyEmployeeWidget::clicked_rightMenu);

	fieldNames_.clear();

	search_timer = new QTimer(this);
	connect(search_timer, &QTimer::timeout, this, &SearchModifyEmployeeWidget::search_pushButton_slot);
	//search_timer->start(10000);	// 10s 一搜索

	save_timer = new QTimer(this);
	connect(save_timer, &QTimer::timeout, this, &SearchModifyEmployeeWidget::save_pushButton_slot);
	//save_timer->start(8000);	// 8s 一保存

	connect(ui.search_pushButton, &QPushButton::clicked, this, &SearchModifyEmployeeWidget::search_pushButton_slot);
	connect(ui.save_pushButton, &QPushButton::clicked, this, &SearchModifyEmployeeWidget::save_pushButton_slot);
	connect(ui.tableView, &QTableView::doubleClicked, this, &SearchModifyEmployeeWidget::obtain_oldValue_slot);
}

SearchModifyEmployeeWidget::~SearchModifyEmployeeWidget()
{
	db_ = nullptr;
	if (model_ != nullptr)
	{
		delete model_;
		model_ = nullptr;
	}

	if (search_timer != nullptr)
	{
		delete search_timer;
		search_timer = nullptr;
	}
	if (save_timer != nullptr)
	{
		delete save_timer;
		save_timer = nullptr;
	}
}

void SearchModifyEmployeeWidget::search_pushButton_slot()
{
	QString name = ui.name_lineEdit->text();
	QString tel = ui.tel_lineEdit->text();
	QString id = ui.id_lineEdit->text();
	if (id.size() != 0 && id.length() < 6)
	{
		int res = 6 - id.length();
		for (int i = 0; i < res; ++i)
		{
			id.insert(0, "0");
		}
	}

	if (db_->open())
	{
		model_ = new QSqlTableModel(nullptr, *db_);
		model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
		model_->setTable("employee");
		model_->select();
		QString sqlWhere;
		if (!name.isEmpty())
		{
			sqlWhere = "employee_Name like '%" + name + "%'";
			
		}
		else if (!tel.isEmpty())
		{
			sqlWhere = "employee_Tel like '%" + tel + "%'";
		}
		else if (!id.isEmpty())
		{
			sqlWhere = "employee_Id like '%" + id + "%'";
		}
		else
			sqlWhere = "";

		model_->setFilter(sqlWhere);
		model_->removeColumns(9, 2);	// 移除照片 和 备注
		model_->removeColumn(7);	// 移除身份
		fieldNames_.clear();
		fieldNames_.push_back(tr("工号"));
		fieldNames_.push_back(tr("姓名"));
		fieldNames_.push_back(tr("性别"));
		fieldNames_.push_back(tr("电话"));
		fieldNames_.push_back(tr("微信"));
		fieldNames_.push_back(tr("地址"));
		fieldNames_.push_back(tr("Email"));
		if (duty_ == MANAGER_ || duty_ == STAFF_)
		{
			model_->removeColumn(7);
			

		}
		else if (duty_ == BOSS_)
		{
			fieldNames_.push_back(tr("密码"));
			
		}
		int currentNumOfFields = model_->record().count();
		for (int i = 0; i < currentNumOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames_[i]);
		}

		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);		// 设置行选中
		ui.tableView->setGridStyle(Qt::DashLine);
		ui.tableView->setModel(model_);
		if (duty_ == STAFF_ || duty_ == MANAGER_)
		{
			ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		}
		else if (duty_ == BOSS_)
		{
			ui.tableView->setItemDelegateForColumn(0, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(1, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(2, new NotEditableDelegate(ui.tableView));
		}
		
		QString content;
		if (!model_->query().first())
		{
			QMessageBox::information(this, tr("提示"), tr("未找到对应条目"));
			content = QObject::tr("工号： ") + currentId_ + QObject::tr("查询操作 ") + sqlWhere + QObject::tr(" 未找到对应条目") + model_->query().lastError().text();
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

void SearchModifyEmployeeWidget::obtain_oldValue_slot(const QModelIndex & index)
{
	indexRecord_.push_back(index);
	QSqlRecord record = model_->record(index.row());
	valueRecord_.push_back(model_->record(index.row()).value(index.column()).toString());
}

void SearchModifyEmployeeWidget::save_pushButton_slot()
{
	if (model_ != nullptr)
	{
		if (db_->open())
			model_->submitAll();
		db_->close();

		assert(indexRecord_.size() == valueRecord_.size());
		QString content; content.clear();
		QString header = QObject::tr("工号: ") + currentId_ + "\t";
		for (int i = 0; i < indexRecord_.size(); ++i)
		{
			QString oldValue = valueRecord_[i];		// 旧值

			QModelIndex index = indexRecord_[i];
			QString id = model_->record(index.row()).value(0).toString();
			QString name = model_->record(index.row()).value(1).toString();
			QString newValue = model_->record(index.row()).value(index.column()).toString();		// 新值
			QString fieldName = fieldNames_[index.column()];

			if (oldValue == newValue)
				continue;
			else
			{
				content = QObject::tr("修改") + id + name + QObject::tr("的") + fieldName + QObject::tr("字段为") + newValue + QObject::tr("（原值为") + oldValue + QObject::tr(").");
				writeLog(header + content);
				writeLogToDatabase(db_, currentId_, QObject::tr("修改"), content, 0);
				valueRecord_[i] = newValue;
			}
			

		}
	}
}

void SearchModifyEmployeeWidget::closeEvent(QCloseEvent * event)
{
	assert(indexRecord_.size() == valueRecord_.size());
	QString content; content.clear();
	for (int i = 0; i < indexRecord_.size(); ++i)
	{
		QString oldValue = valueRecord_[i];		// 旧值

		QModelIndex index = indexRecord_[i];
		QString vip = model_->record(index.row()).value(0).toString();
		QString name = model_->record(index.row()).value(1).toString();
		QString newValue = model_->record(index.row()).value(index.column()).toString();		// 新值
		QString fieldName = fieldNames_[index.column()];

		if (oldValue == newValue)
			continue;
		else {
			int res = QMessageBox::question(this, tr("确定退出？"), tr("您有修改项未保存，继续退出将放弃所有修改!"), tr("继续退出"), tr("取消"));
			if (res == 0)
				event->accept();
			else
				event->ignore();

		}


	}
}

void SearchModifyEmployeeWidget::initGUIAccordingCurrentId()
{
	if (duty_ == MANAGER_ || duty_ == STAFF_)
	{
		ui.save_pushButton->setVisible(false);		// 只查看，不修改
		
		if (duty_ == MANAGER_)
		{
			ui.label_2->setText(tr("右键将员工设为离职"));
			ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);  // 右键菜单
		}
	}
	else
	{
		ui.label_2->setText(tr("工号、姓名、性别无法修改"));
		ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);  // 右键菜单
	}
		
}



void SearchModifyEmployeeWidget::createRightMenu()
{
	rightMenu_ = new QMenu(ui.tableView);

	action_dimission_ = new QAction(tr("离职"), this);
	connect(action_dimission_, &QAction::triggered, this, &SearchModifyEmployeeWidget::dimission_slot);

	rightMenu_->addAction(action_dimission_);
}

void SearchModifyEmployeeWidget::clicked_rightMenu(const QPoint & pos)
{
	selectedRow = ui.tableView->currentIndex().row();
	rightMenu_->exec(QCursor::pos());
	
}

void SearchModifyEmployeeWidget::dimission_slot()
{
	QModelIndex index = model_->index(selectedRow, 0);
	QString id = model_->data(index).toString();
	QString name = model_->data(model_->index(selectedRow, 1)).toString();
	int res = QMessageBox::information(this, tr("确认"), tr("确定将 ") + id + tr(" ") + name + tr(" 设为离职？ 离职后将无法登录"), tr("是"), tr("否"));
	if (res == 1)
		return;
	QSqlQuery query;
	//QString sql = "select employee_Duty from employee where employee_Id = '" + id + "'";
	QString sql = "update employee set employee_Duty = 4 where employee_Id = '" + id + "'";
	if (db_->open())
	{
		if (query.exec(sql))
		{
			QMessageBox::information(this, tr("设置成功"), tr("已将工号") + id + tr(" 设置为离职"));
		}
		else
		{
			QMessageBox::information(this, tr("失败"), query.lastError().text());
		}

		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("错误"), db_->lastError().text());
	}
}
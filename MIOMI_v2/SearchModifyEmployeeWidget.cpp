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
	//search_timer->start(10000);	// 10s һ����

	save_timer = new QTimer(this);
	connect(save_timer, &QTimer::timeout, this, &SearchModifyEmployeeWidget::save_pushButton_slot);
	//save_timer->start(8000);	// 8s һ����

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
		model_->removeColumns(9, 2);	// �Ƴ���Ƭ �� ��ע
		model_->removeColumn(7);	// �Ƴ����
		fieldNames_.clear();
		fieldNames_.push_back(tr("����"));
		fieldNames_.push_back(tr("����"));
		fieldNames_.push_back(tr("�Ա�"));
		fieldNames_.push_back(tr("�绰"));
		fieldNames_.push_back(tr("΢��"));
		fieldNames_.push_back(tr("��ַ"));
		fieldNames_.push_back(tr("Email"));
		if (duty_ == MANAGER_ || duty_ == STAFF_)
		{
			model_->removeColumn(7);
			

		}
		else if (duty_ == BOSS_)
		{
			fieldNames_.push_back(tr("����"));
			
		}
		int currentNumOfFields = model_->record().count();
		for (int i = 0; i < currentNumOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames_[i]);
		}

		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);		// ������ѡ��
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
			QMessageBox::information(this, tr("��ʾ"), tr("δ�ҵ���Ӧ��Ŀ"));
			content = QObject::tr("���ţ� ") + currentId_ + QObject::tr("��ѯ���� ") + sqlWhere + QObject::tr(" δ�ҵ���Ӧ��Ŀ") + model_->query().lastError().text();
		}
		
		db_->close();
	}
	else
	{
		QString content = QObject::tr("����: ") + currentId_ + QObject::tr("\t���ݿ�����ʧ��") + db_->lastError().text();
		QMessageBox::information(this, tr("����"), tr("���ݿ�����ʧ��") + db_->lastError().text());
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
		QString header = QObject::tr("����: ") + currentId_ + "\t";
		for (int i = 0; i < indexRecord_.size(); ++i)
		{
			QString oldValue = valueRecord_[i];		// ��ֵ

			QModelIndex index = indexRecord_[i];
			QString id = model_->record(index.row()).value(0).toString();
			QString name = model_->record(index.row()).value(1).toString();
			QString newValue = model_->record(index.row()).value(index.column()).toString();		// ��ֵ
			QString fieldName = fieldNames_[index.column()];

			if (oldValue == newValue)
				continue;
			else
			{
				content = QObject::tr("�޸�") + id + name + QObject::tr("��") + fieldName + QObject::tr("�ֶ�Ϊ") + newValue + QObject::tr("��ԭֵΪ") + oldValue + QObject::tr(").");
				writeLog(header + content);
				writeLogToDatabase(db_, currentId_, QObject::tr("�޸�"), content, 0);
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
		QString oldValue = valueRecord_[i];		// ��ֵ

		QModelIndex index = indexRecord_[i];
		QString vip = model_->record(index.row()).value(0).toString();
		QString name = model_->record(index.row()).value(1).toString();
		QString newValue = model_->record(index.row()).value(index.column()).toString();		// ��ֵ
		QString fieldName = fieldNames_[index.column()];

		if (oldValue == newValue)
			continue;
		else {
			int res = QMessageBox::question(this, tr("ȷ���˳���"), tr("�����޸���δ���棬�����˳������������޸�!"), tr("�����˳�"), tr("ȡ��"));
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
		ui.save_pushButton->setVisible(false);		// ֻ�鿴�����޸�
		
		if (duty_ == MANAGER_)
		{
			ui.label_2->setText(tr("�Ҽ���Ա����Ϊ��ְ"));
			ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);  // �Ҽ��˵�
		}
	}
	else
	{
		ui.label_2->setText(tr("���š��������Ա��޷��޸�"));
		ui.tableView->setContextMenuPolicy(Qt::CustomContextMenu);  // �Ҽ��˵�
	}
		
}



void SearchModifyEmployeeWidget::createRightMenu()
{
	rightMenu_ = new QMenu(ui.tableView);

	action_dimission_ = new QAction(tr("��ְ"), this);
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
	int res = QMessageBox::information(this, tr("ȷ��"), tr("ȷ���� ") + id + tr(" ") + name + tr(" ��Ϊ��ְ�� ��ְ���޷���¼"), tr("��"), tr("��"));
	if (res == 1)
		return;
	QSqlQuery query;
	//QString sql = "select employee_Duty from employee where employee_Id = '" + id + "'";
	QString sql = "update employee set employee_Duty = 4 where employee_Id = '" + id + "'";
	if (db_->open())
	{
		if (query.exec(sql))
		{
			QMessageBox::information(this, tr("���óɹ�"), tr("�ѽ�����") + id + tr(" ����Ϊ��ְ"));
		}
		else
		{
			QMessageBox::information(this, tr("ʧ��"), query.lastError().text());
		}

		db_->close();
	}
	else
	{
		QMessageBox::information(this, tr("����"), db_->lastError().text());
	}
}
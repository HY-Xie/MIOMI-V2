#include "ModifyCustomerWidget.h"
#include <QSqlQuery>
#include <QMessageBox>

#include <QDebug>
#include <cassert>
ModifyCustomerWidget::ModifyCustomerWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);


	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";

	old_value_ = "";
	new_value_ = "";

	model_ = nullptr;

	

	connect(ui.search_pushButton, &QPushButton::clicked, this, &ModifyCustomerWidget::search_pushButton_slot);
	connect(ui.tableView, &QTableView::doubleClicked, this, &ModifyCustomerWidget::obtain_oldValue_slot);
	connect(ui.save_pushButton, &QPushButton::clicked, this, &ModifyCustomerWidget::save_pushButton_slot);


	search_timer = new QTimer(this);
	connect(search_timer, &QTimer::timeout, this, &ModifyCustomerWidget::search_pushButton_slot);
	//search_timer->start(10000);	// 10s   


	save_timer = new QTimer(this);
	connect(save_timer, &QTimer::timeout, this, &ModifyCustomerWidget::save_pushButton_slot);
	//search_timer->start(8000);	// 8s 

	
	
	
}

ModifyCustomerWidget::~ModifyCustomerWidget()
{
	db_ = nullptr;
	if (model_ != nullptr)
	{
		delete model_;
		model_ = nullptr;
	}
	
}

void ModifyCustomerWidget::search_pushButton_slot()
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
		model_ = new QSqlTableModel(nullptr, *db_);
		model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
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
		
		fieldNames_.clear();
		fieldNames_.push_back(QObject::tr("��Ա��"));
		fieldNames_.append(QObject::tr("����"));
		fieldNames_.append(QObject::tr("�绰"));
		fieldNames_.append(QObject::tr("�Ա�"));
		fieldNames_.append(QObject::tr("΢��"));
		fieldNames_.append(QObject::tr("QQ"));
		fieldNames_.append(QObject::tr("��ַ"));
		fieldNames_.append(QObject::tr("���Ӷ���(��)"));
		fieldNames_.append(QObject::tr("���Ӷ���(��)"));
		fieldNames_.append(QObject::tr("ɢ�����(��)"));
		fieldNames_.append(QObject::tr("ɢ�����(��)"));
		fieldNames_.append(QObject::tr("��������"));
		fieldNames_.append(QObject::tr("����"));
		for (int i = 0; i < numOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames_.at(i));
		}
		//model_->setHeaderData(0, Qt::Horizontal, tr("��Ա��"));

		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);		// ������ѡ��

		ui.tableView->setGridStyle(Qt::DashLine);
		ui.tableView->setModel(model_);
		//ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		if (duty_ == STAFF_ || duty_ == MANAGER_)
		{
			ui.tableView->setItemDelegateForColumn(0, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(1, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(3, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(11, new NotEditableDelegate(ui.tableView));
			ui.tableView->setItemDelegateForColumn(12, new NotEditableDelegate(ui.tableView));
		}
		
		QString content;
		if (!model_->query().first())
		{
			//QMessageBox::information(this, tr("��ʾ"), tr("δ�ҵ���Ӧ��Ŀ"));
			content = QObject::tr("���ţ� ") + currentId_ + QObject::tr("�������� ") + sqlWhere + QObject::tr(" δ������Ҫ�޸ĵĻ�Ա��Ϣ") + model_->query().lastError().text();
			//search_timer->stop();
			//save_timer->stop();
			//search_timer->start(10000);	// 10s  
			//save_timer->start(8000);
		}
		else
		{
			content = QObject::tr("���ţ� ") + currentId_ + QObject::tr("�������� ") + sqlWhere;
			/*ui.tel_lineEdit->clear();
			ui.name_lineEdit->clear();
			ui.vip_lineEdit->clear();*/

		}

		//writeLog(content);

		db_->close();
	}
	else
	{
		QString content = QObject::tr("����: ") + currentId_ + QObject::tr("\t���ݿ�����ʧ��") + db_->lastError().text();
		QMessageBox::information(this, tr("����"), tr("���ݿ�����ʧ��") + db_->lastError().text());
		writeLog(content, 1);
	}
}

void ModifyCustomerWidget::save_pushButton_slot()
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
			QString vip = model_->record(index.row()).value(0).toString();
			QString name = model_->record(index.row()).value(1).toString();
			QString newValue = model_->record(index.row()).value(index.column()).toString();		// ��ֵ
			QString fieldName = fieldNames_[index.column()];

			if (oldValue == newValue)
				continue;
			else
			{
				content = QObject::tr("�޸�") + vip + name + QObject::tr("��") + fieldName + QObject::tr("�ֶ�Ϊ") + newValue + QObject::tr("��ԭֵΪ") + oldValue + QObject::tr(").");
				writeLog(header + content);
				writeLogToDatabase(db_, currentId_, QObject::tr("�޸�"), content, 0);
				valueRecord_[i] = newValue;
			}
			

		}
	}
}



void ModifyCustomerWidget::obtain_oldValue_slot(const QModelIndex &index)
{
	//qDebug() << index;
	//qDebug() << ui.tableView->currentIndex().row();
	//qDebug() << index.row();
	indexRecord_.push_back(index);

	QSqlRecord record = model_->record(index.row());
	//int row = index.row();
	//int col = index.column();
	//value_ = record.value(0).toString();
	//old_value_ = record.value(col).toString();
	valueRecord_.push_back(model_->record(index.row()).value(index.column()).toString());
}



void ModifyCustomerWidget::closeEvent(QCloseEvent * event)
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


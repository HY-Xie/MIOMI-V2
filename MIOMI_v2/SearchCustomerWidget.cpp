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
		fieldNames.push_back(QObject::tr("��Ա��"));
		fieldNames.append(QObject::tr("����"));
		fieldNames.append(QObject::tr("�绰"));
		fieldNames.append(QObject::tr("�Ա�"));
		fieldNames.append(QObject::tr("΢��"));
		fieldNames.append(QObject::tr("QQ"));
		fieldNames.append(QObject::tr("��ַ"));
		fieldNames.append(QObject::tr("���Ӷ���(��)"));
		fieldNames.append(QObject::tr("���Ӷ���(��)"));
		fieldNames.append(QObject::tr("ɢ�����(��)"));
		fieldNames.append(QObject::tr("ɢ�����(��)"));
		fieldNames.append(QObject::tr("��������"));
		fieldNames.append(QObject::tr("����"));
		for (int i = 0; i < numOfFields; ++i)
		{
			model_->setHeaderData(i, Qt::Horizontal, fieldNames.at(i));
		}
		//model_->setHeaderData(0, Qt::Horizontal, tr("��Ա��"));
		ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);	// ������ѡ��
		ui.tableView->setGridStyle(Qt::DashLine);
		ui.tableView->setModel(model_);
		ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

		QString content;
		if (!model_->query().first())
		{
			//QMessageBox::information(this, tr("��ʾ"), tr("δ�ҵ���Ӧ��Ŀ"));
			content = QObject::tr("���ţ� ") + currentId_ + QObject::tr("��ѯ���� ") + sqlWhere + QObject::tr(" δ�ҵ���Ӧ��Ŀ") + model_->query().lastError().text();
		}
		else
		{
			content = QObject::tr("���ţ� ") + currentId_ + QObject::tr("��ѯ���� ") + sqlWhere;
			// ʹ�����Զ�ˢ�£�������գ������գ���Ҫ�Ķ��Ĵ���Ƚ϶࣬�������߼�
			/*ui.tel_lineEdit->clear();
			ui.name_lineEdit->clear();
			ui.vip_lineEdit->clear();*/
			//writeLog(content);
			//writeLog(content, 1); // ���ʧ�ܣ���д��ϵͳ��־
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

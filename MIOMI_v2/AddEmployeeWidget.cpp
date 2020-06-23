#include "AddEmployeeWidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
AddEmployeeWidget::AddEmployeeWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";
	numOfEmployee_ = 0;

	// ��ʼ��GUI
	ui.sameAsTel_checkBox->setChecked(true);
	ui.id_lineEdit->setDisabled(true);

	connect(ui.add_pushButton, &QPushButton::clicked, this, &AddEmployeeWidget::add_pushButton_slot);
	connect(ui.name_lineEdit, &QLineEdit::editingFinished, this, &AddEmployeeWidget::setCurrentNumberOfEmployee);
	connect(ui.tel_lineEdit, &QLineEdit::editingFinished, this, &AddEmployeeWidget::sameAsTel_weChat_slot);
	connect(ui.sameAsTel_checkBox, &QCheckBox::stateChanged, this, &AddEmployeeWidget::checkBoxState_slot);
}

AddEmployeeWidget::~AddEmployeeWidget()
{
	db_ = nullptr;
}

int AddEmployeeWidget::getCurrentNumOfEmployee()
{
	QString sql = "select * from employee";
	QSqlQuery query;
	int numberOfEmployee = -1;
	if (db_->open())
	{
		if (query.exec(sql))
		{
			numberOfEmployee = query.size();
		}
		else
		{
			QMessageBox::information(this, tr("����"), query.lastError().text());
			numberOfEmployee = -1;
		}
		db_->close();
	}
	return numberOfEmployee;
}

void AddEmployeeWidget::setCurrentNumberOfEmployee()
{
	int numOfEmployee = getCurrentNumOfEmployee();
	QString id = QString(QString::number(numOfEmployee + 1, 10));
	int res = 6 - id.length();
	if (id.length() < 6)
	{
		for (int i = 0; i < res; ++i)
			id.insert(0, "0");
	}
	ui.id_lineEdit->setText(id);
}

void AddEmployeeWidget::sameAsTel_weChat_slot()
{
	if (ui.sameAsTel_checkBox->isChecked())
	{
		ui.weChat_lineEdit->setText(ui.tel_lineEdit->text());
	}
}

void AddEmployeeWidget::checkBoxState_slot()
{
	if (!ui.sameAsTel_checkBox->isChecked())
	{
		ui.weChat_lineEdit->clear();
	}
	else
		ui.weChat_lineEdit->setText(ui.tel_lineEdit->text());
}

void AddEmployeeWidget::add_pushButton_slot()
{
	QString name = ui.name_lineEdit->text();
	QString tel = ui.tel_lineEdit->text();
	QString weChat = ui.weChat_lineEdit->text();
	QString id = ui.id_lineEdit->text();
	QString sex;
	if (ui.female_radioButton->isChecked())
		sex = QObject::tr("Ů");
	else if (ui.male_radioButton->isChecked())
		sex = QObject::tr("��");

	if (db_->open())
	{
		if (name.isEmpty())	// ��������Ϊ��
		{
			//QMessageBox::warning(this, tr("������Ϣ"), QStringLiteral("������ʾ"));
			QMessageBox::warning(this, tr("������Ϣ"), tr("����������Ϊ�գ�"));
			db_->close();
			return;
		}
		if (tel.length() != 11)		// �ֻ�����11λ
		{
			QMessageBox::warning(this, tr("������Ϣ"), tr("�ֻ�������������,���������룡"));
			db_->close();
			return;
		}
		QSqlQuery tel_query;		// ��ѯ�ֻ������Ƿ��ظ�
		QString tel_select_query = "select  * from employee where tel = " + tel;
		tel_query.prepare(tel_select_query);
		//qDebug() << tel_select_query;
		tel_query.exec();
		if (tel_query.exec())	// �����ݿ����ҵ���ͬ�ֻ�����
		{
			if (tel_query.first())
			{

				QMessageBox::warning(this, tr("������Ϣ"), tr("�ֻ������Ѵ���,���������룡"));
				db_->close();
				return;

			}
		}

		// �ж�����
		QString pass = ui.pass_lineEdit->text();
		QString re_pass = ui.re_pass_lineEdit->text();
		if (pass.size() == 0)
		{
			QMessageBox::information(this, tr("��ʾ"), tr("���벻��Ϊ��!"));
			db_->close();
			return;
		}
		else if (pass != re_pass)
		{
			QMessageBox::information(this, tr("��ʾ"), tr("�����������벻ͬ!"));
			db_->close();
			return;
		}
		
		// �ж���Ա�����
		DUTY duty;
		if (ui.isManager_checkBox->isChecked())
		{
			duty = MANAGER_;
		}
		else
		{
			duty = STAFF_;
		}

		// ��ʼ����
		//QSqlQuery insert_query;
		////QString insert_sql = "insert into employee (employee_Id, employee_Name, employee_Sex, employee_Tel, employee_WeChat, employee_Duty, employee_PassWord) values(?,?,?,?,?,?,?)";
		//QString insert_sql = "insert into employee values(?,?,?,?,?,?,?,?,?,?,?)";
		//insert_query.prepare(insert_sql);


		//QVariantList ids, names, sexs, tels,  weChats, addrs, emails, duties, passWords, photos, notes;
		//ids.append(QVariant(id));
		//names.append(QVariant(name));
		//sexs.append(QVariant(sex));
		//tels.append(QVariant(tel));
		//weChats.append(QVariant(weChat));
		//addrs.append(QVariant(""));
		//emails.append(QVariant(""));
		//duties.append(QVariant(duty));
		//passWords.append(QVariant(pass));
		//photos.append(QVariant(""));
		//notes.append(QVariant(""));


		//insert_query.addBindValue(id);
		//insert_query.addBindValue(names);
		//insert_query.addBindValue(sexs);
		//insert_query.addBindValue(tels);
		//insert_query.addBindValue(weChats);
		//insert_query.addBindValue(addrs);
		//insert_query.addBindValue(emails);
		//insert_query.addBindValue(duties);
		//insert_query.addBindValue(passWords);
		//insert_query.addBindValue(photos);
		//insert_query.addBindValue(notes);

		//if (!insert_query.execBatch())
		//{
		//	//qDebug() << insert_query.lastError();
		//	QMessageBox::information(this, tr("��Ա�����ʧ��"), insert_query.lastError().text());
		//	db_->close();
		//	return;
		//}
		//else
		//{
		//	QMessageBox::information(this, tr("��Ա����ӳɹ�"), tr("��Ա����ӳɹ���"));
		//}


		// 
		QSqlQuery insert_query;
		insert_query.prepare("insert into employee (employee_Id, employee_Name, employee_Sex, employee_Tel, employee_WeChat, employee_Duty, employee_PassWord) "
			"values (:employee_Id, :employee_Name, :employee_Sex, :employee_Tel, :employee_WeChat, :employee_Duty, :employee_PassWord)");
		insert_query.bindValue(":employee_Id", id);
		insert_query.bindValue(":employee_Name", name);
		insert_query.bindValue(":employee_Sex", sex);
		insert_query.bindValue(":employee_Tel", tel);
		insert_query.bindValue(":employee_WeChat", weChat);
		insert_query.bindValue(":employee_Duty", duty);
		insert_query.bindValue(":employee_PassWord", pass);

		if (!insert_query.exec())
		{
			QMessageBox::information(this, tr("��Ա�����ʧ��"), insert_query.lastError().text());
			db_->close();
			return;
		}
		else
			QMessageBox::information(this, tr("��Ա����ӳɹ�"), tr("��Ա����ӳɹ���"));

		db_->close();
	}
	ui.name_lineEdit->clear();
	ui.tel_lineEdit->clear();
	ui.weChat_lineEdit->clear();
	ui.id_lineEdit->clear();
	ui.female_radioButton->setChecked(true);
	if (ui.isManager_checkBox->isChecked())
	{
		ui.isManager_checkBox->setChecked(false);
	}
	ui.pass_lineEdit->clear();
	ui.re_pass_lineEdit->clear();

	QString context = QObject::tr("����: ") + currentId_ + QObject::tr("\t���Ա��Ա") + id + " " + name;
	writeLog(context);
	writeLogToDatabase(db_, currentId_, QObject::tr("���Ա��"), id + QObject::tr(" ") + name, 0);
}

void AddEmployeeWidget::initGUIAccordingCurrentId()
{
	if (duty_ == MANAGER_)
	{
		ui.isManager_checkBox->setDisabled(true);
	}
	else if (duty_ == BOSS_)
	{
		ui.isManager_checkBox->setDisabled(false);
	}

	setCurrentNumberOfEmployee();


}

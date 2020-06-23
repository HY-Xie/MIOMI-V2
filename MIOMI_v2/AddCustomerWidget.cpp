#include "AddCustomerWidget.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>
AddCustomerWidget::AddCustomerWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	// ��ʼ��
	db_ = nullptr;
	duty_ = DEFAULT_;
	currentId_ = "";
	numOfCustomer_ = 0;

	// ��ʼ��GUI
	ui.sameAsTel_checkBox->setChecked(true);
	//ui.score_lineEdit->setText("0");
	ui.score_lineEdit->setDisabled(true);

	connect(ui.add_pushButton, &QPushButton::clicked, this, &AddCustomerWidget::add_pushButton_slot);

	connect(ui.name_lineEdit, &QLineEdit::editingFinished, this, &AddCustomerWidget::setCurrentNumOfCustomer);
	connect(ui.tel_lineEdit, &QLineEdit::editingFinished, this, &AddCustomerWidget::sameAsTel_weChat_slot);
	connect(ui.sameAsTel_checkBox, &QCheckBox::stateChanged, this, &AddCustomerWidget::checkBoxState_slot);
	
}

AddCustomerWidget::~AddCustomerWidget()
{
	db_ = nullptr;
}

void AddCustomerWidget::closeEvent(QCloseEvent * event)
{
	/*QString content = QObject::tr("����: ") + currentId_ + QObject::tr(" �ر���ӻ�Ա�Ի���");
	writeLog(content);*/

}

void AddCustomerWidget::add_pushButton_slot()
{
	QString name = ui.name_lineEdit->text();
	QString tel = ui.tel_lineEdit->text();
	QString weChat = ui.weChat_lineEdit->text();
	QString qq = ui.qq_lineEdit->text();
	QString addr = ui.addr_lineEdit->text();
	QString vip = ui.vip_lineEdit->text();
	int score;
	if (ui.score_lineEdit->isEnabled())
	{
		score = ui.score_lineEdit->text().toInt();
	}
	else
		score = 0;
	
	QString sex;
	if (ui.female_radioButton->isChecked())
		sex = QObject::tr("Ů");
	else if (ui.male_radioButton->isChecked())
		sex = QObject::tr("��");
	QString left_myopia = ui.left_myopia_comboBox->currentText();
	QString right_myopia = ui.right_myopia_comboBox->currentText();
	QString left_astigmatism = ui.left_astigmatism_comboBox->currentText();
	QString right_astigmatism = ui.right_astigmatism_comboBox->currentText();
	int purchasedAmount = 0;

	if (db_->open())
	{
		// �ж�
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
		QString tel_select_query = "select  * from customer where tel = " + tel;
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

		// ��ʼ����
		QSqlQuery insert_query;
		QString insert_sql = "insert into customer values(?,?,?,?,?,?,?,?,?,?,?,?,?)";
		insert_query.prepare(insert_sql);


		QVariantList vips, names, tels, sexs, weChats, qqs, addrs, left_myopias, right_myopias, left_astigmatisms, right_astigmatisms, purchase_nums, scores;
		vips.append(QVariant(vip));
		names.append(QVariant(name));
		tels.append(QVariant(tel));
		sexs.append(QVariant(sex));
		weChats.append(QVariant(weChat));
		qqs.append(QVariant(qq));
		addrs.append(QVariant(addr));
		left_myopias.append(QVariant(left_myopia));
		right_myopias.append(QVariant(right_myopia));
		left_astigmatisms.append(QVariant(left_astigmatism));
		right_astigmatisms.append(QVariant(right_astigmatism));
		purchase_nums.append(QVariant(purchasedAmount));
		scores.append(QVariant(score));

		insert_query.addBindValue(vips);
		insert_query.addBindValue(names);
		insert_query.addBindValue(tels);
		insert_query.addBindValue(sexs);
		insert_query.addBindValue(weChats);
		insert_query.addBindValue(qqs);
		insert_query.addBindValue(addrs);
		insert_query.addBindValue(left_myopias);
		insert_query.addBindValue(right_myopias);
		insert_query.addBindValue(left_astigmatisms);
		insert_query.addBindValue(right_astigmatisms);
		insert_query.addBindValue(purchase_nums);
		insert_query.addBindValue(scores);

		if (!insert_query.execBatch())
		{
			//qDebug() << insert_query.lastError();
			QMessageBox::information(this, tr("�»�Ա���ʧ��"), insert_query.lastError().text());
			db_->close();
			return;
		}
		else
		{
			QMessageBox::information(this, tr("�»�Ա��ӳɹ�"), tr("�»�Ա��ӳɹ���"));
		}


		db_->close();
	}
	
	ui.name_lineEdit->clear();
	ui.tel_lineEdit->clear();
	ui.weChat_lineEdit->clear();
	ui.qq_lineEdit->clear();
	ui.addr_lineEdit->clear();
	ui.female_radioButton->setChecked(true);
	ui.vip_lineEdit->clear();
	ui.score_lineEdit->clear();
	ui.left_myopia_comboBox->setCurrentIndex(0);
	ui.right_myopia_comboBox->setCurrentIndex(0);
	ui.left_astigmatism_comboBox->setCurrentIndex(0);
	ui.right_astigmatism_comboBox->setCurrentIndex(0);

	QString context = QObject::tr("����: ") + currentId_ + QObject::tr("\n����»�Ա ") + vip + " " + name;
	writeLog(context);
	writeLogToDatabase(db_, currentId_, QObject::tr("��ӻ�Ա"), vip + QObject::tr(" ") + name, 0);
}

int AddCustomerWidget::getCurrentNumOfCustomer()
{
	QString sql = "select * from customer";
	QSqlQuery query;
	int numOfCustomer = -1;
	if (db_->open())
	{
		if (query.exec(sql))
		{
			numOfCustomer =  query.size();
		}
		else
		{
			QMessageBox::information(this, tr("����"), query.lastError().text());
			numOfCustomer = -1;
		}
		db_->close();
	}
	return numOfCustomer;
}

void AddCustomerWidget::setCurrentNumOfCustomer()
{
	int numOfCustomer = getCurrentNumOfCustomer();
	QString vip = QString(QString::number(numOfCustomer+101, 10));
	int res = 6 - vip.length();
	if (vip.length() < 6)
	{
		for (int i = 0; i < res; ++i)
			vip.insert(0, "0");
	}
	ui.vip_lineEdit->setText(vip);
}

void AddCustomerWidget::sameAsTel_weChat_slot()
{
	if (ui.sameAsTel_checkBox->isChecked())
	{
		ui.weChat_lineEdit->setText(ui.tel_lineEdit->text());
	}
}

void AddCustomerWidget::checkBoxState_slot()
{
	if (!ui.sameAsTel_checkBox->isChecked())
	{
		ui.weChat_lineEdit->clear();
	}
	else
		ui.weChat_lineEdit->setText(ui.tel_lineEdit->text());
}

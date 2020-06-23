#include "ChangePersonalInfoWidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include "GlobalPath.h"
#include "RunningMode.h"
ChangePersonalInfoWidget::ChangePersonalInfoWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	fields_.clear();

	db_ = nullptr;;
	duty_ = DEFAULT_;
	currentId_ = "";
	image_ = nullptr;
	image_ = new QImage();

	connect(ui.save_pushButton, &QPushButton::clicked, this, &ChangePersonalInfoWidget::save_pushButton_slot);
	connect(ui.photo_toolButton, &QPushButton::clicked, this, &ChangePersonalInfoWidget::photo_toolButton_slot);
}

ChangePersonalInfoWidget::~ChangePersonalInfoWidget()
{
	db_ = nullptr;

	if (image_ != nullptr)
	{
		delete image_;
		image_ = nullptr;
	}
}

void ChangePersonalInfoWidget::initInfoAccording(const QString & currentId)
{
	if (db_->open())
	{
		QSqlQuery query;
		QString sql = "select * from employee where employee_Id = '" + currentId_ + "'";
		if (query.exec(sql))
		{
			if (query.first())
			{
				query.seek(-1);
				query.next();
				//qDebug() << query.value(0).toString();
				int numOfFields = query.record().count();
				for (int i = 0; i < numOfFields; ++i)
				{
					fields_.push_back(query.value(i).toString());
				}
				
				ui.id_lineEdit->setText(fields_[0]);  ui.id_lineEdit->setDisabled(true);
				ui.name_lineEdit->setText(fields_[1]);	ui.name_lineEdit->setDisabled(true);
				ui.tel_lineEdit->setText(fields_[3]);
				ui.weChat_lineEdit->setText(fields_[4]);
				ui.addr_lineEdit->setText(fields_[5]);
				ui.email_lineEdit->setText(fields_[6]);
				ui.note_textEdit->setText(fields_[10]);

				
				if (image_->load(fields_[9]))
				{
					//image_->scaled(ui.photo_label->size());  // 首次载入，不缩放（默认有大小合适的图片)
					ui.photo_label->setPixmap(QPixmap::fromImage(*image_));
				}
					
			}
		}
		else
		{
			
		}
		db_->close();
		//update();
	}
}

void ChangePersonalInfoWidget::save_pushButton_slot()
{
	QString tel = ui.tel_lineEdit->text();
	if (db_->open())
	{
		if (tel.length() != 11)		// 手机号码11位
		{
			QMessageBox::warning(this, tr("警告信息"), tr("手机号码输入有误,请重新输入！"));
			db_->close();
			return;
		}

		QSqlQuery tel_query;		// 查询手机号码是否重复
		QString tel_select_query = "select  * from employee where employee_Tel = " + tel;
		tel_query.prepare(tel_select_query);
		//qDebug() << tel_select_query;
		tel_query.exec();
		if (tel_query.exec())	// 在数据库中找到相同手机号码
		{
			if (tel_query.size() > 1)
			{

				QMessageBox::warning(this, tr("警告信息"), tr("手机号码已存在,请重新输入！"));
				db_->close();
				return;

			}
		}
		db_->close();
	}
	QString weChat = ui.weChat_lineEdit->text();
	QString addr = ui.addr_lineEdit->text();
	QString notes = ui.note_textEdit->toPlainText();
	QString email = ui.email_lineEdit->text();

	QString photoPath = fields_[9];	// 此处不可能下标越界
	image_->save(photoPath);

	QString password = fields_[8];	// 旧密码

	if (ui.new_password_lineEdit->text().length() > 0)
	{
		if (ui.old_password_lineEdit->text().isEmpty())
		{
			QMessageBox::information(this, tr("提示"), tr("如要修改密码，需输入旧密码"));
			return;
		}
		else if (ui.old_password_lineEdit->text() != fields_[8])
		{
			QMessageBox::information(this, tr("提示"), tr("旧密码输入错误，请重新输入"));
			ui.old_password_lineEdit->clear();
			return;
		}
		else if (ui.new_password_lineEdit->text() != ui.re_new_password_lineEdit->text())
		{
			QMessageBox::information(this, tr("提示"), tr("两次输入密码不一致，请重新输入"));
			ui.new_password_lineEdit->clear();
			ui.re_new_password_lineEdit->clear();
			return;
		}
		else
		{
			password = ui.new_password_lineEdit->text();
		}
	}


	QString update_sql = "update employee set employee_Tel = '" + tel + "'," +
		" employee_WeChat = '" + weChat + "'," +
		" employee_Address = '" + addr + "'," +
		" employee_Email = '" + email + "'," +
		" employee_PassWord = '" + password + "'," +
		" employee_Notes = '" + notes + "'," +
		" employee_PhotoPath = '" + photoPath + "'"
		" where employee_Id = '" + currentId_ + "'";


	// 开始更新
	if (db_->open())
	{
		QSqlQuery query;
		QString title;
		QString content;
		if (query.exec(update_sql))
		{
			title = QObject::tr("更新成功");
			content = QObject::tr("所有个人信息更新完成");
			QMessageBox::information(this, title, content);
		}
		else
		{
			title = QObject::tr("更新失败");
			content = QObject::tr("更新失败");
			QMessageBox::information(this, title, content + query.lastError().text());
		}
		

		writeLog(QObject::tr("工号: ") + currentId_ + "\t" + content + " " + query.lastError().text());

		db_->close();
	}
}


void ChangePersonalInfoWidget::photo_toolButton_slot()
{

	// 获取选择图像路径
	QString fileName = QFileDialog::getOpenFileName(this, tr("选择图片"), QDir::homePath(), tr("((*.png *.jpg))"));
	//QString fileName = "C:/Users/Desktop/1.jpg";
	if (fileName.isEmpty())
		return;
	


	// 更名、获取要保存到的路径
	QString photoName = fileName.split("/").back();
	QString ext = photoName.split(".").back();
	QString path;
	if (LAN == true)
		path = STORE_HOST + "/MIOMI/employee_photos/";
	else
		path = QDir::homePath() + "/MIOMI/employee_photos/";
	QString newPathAndName = path + "photo_" + currentId_ + "." + ext;
	//image_->load(newPathAndName);

	// 按原路径载入图片
	image_->load(fileName);
	*image_ = image_->scaled(ui.photo_label->size());	// 缩放
	// 将缩放后的图片保存到新路径
	//image_->save(newPathAndName); 此处不保存，在save slot中保存
	// 更新 数据库中保存的路径
	fields_[9] = newPathAndName;
	ui.photo_label->setPixmap(QPixmap::fromImage(*image_));

	/*if (QFile::copy(fileName, newPathAndName))
	{
		
		image_->load(fields_[9]);
		image_->scaled(ui.photo_label->size());
		ui.photo_label->setPixmap(QPixmap::fromImage(*image_));
	}
	else
	{
		if (QFile::exists(newPathAndName))
			QFile::remove(newPathAndName);
		QFile::copy(fileName, newPathAndName);
		fields_[9] = newPathAndName;
		image_->load(fields_[9]);
		image_->scaled(ui.photo_label->size());
		ui.photo_label->setPixmap(QPixmap::fromImage(*image_));
	}*/

	
	
}

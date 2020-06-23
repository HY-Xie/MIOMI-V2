#include "SysConfiguration.h"
#include "ChineseSupport.h"
#include "Log.h"
#include "RunningMode.h"
#include "DatabaseInfo.h"
#include "GlobalPath.h"
#include <QDir>
#include <QMessageBox>

SysConfiguration::SysConfiguration(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	
	loadCurrentSetting();



	connect(ui.local_radioButton, &QRadioButton::clicked, this, &SysConfiguration::setLocal);
	connect(ui.lan_radioButton, &QRadioButton::clicked, this,&SysConfiguration::setLan);

	connect(ui.save_pushButton, &QPushButton::clicked, this, &SysConfiguration::saveCurrentSetting);
	connect(ui.cancel_pushButton, &QPushButton::clicked, this, &SysConfiguration::close);
}

SysConfiguration::~SysConfiguration()
{
}


void SysConfiguration::setLocal()
{
	lan_ = false;
	ui.lan_radioButton->setChecked(false);
	ui.local_radioButton->setChecked(true);

	ui.store_lineEdit->setText("//127.0.0.1");
	ui.type_comboBox->setCurrentText("QMYSQL");
	ui.host_lineEdit->setText("127.0.0.1");
	ui.name_lineEdit->setText("miomi");
	ui.port_lineEdit->setText("3306");
	ui.user_lineEdit->setText("root");
	ui.pass_lineEdit->setText("toor");
}
void SysConfiguration::setLan()
{
	lan_ = true;
	ui.lan_radioButton->setChecked(true);
	ui.local_radioButton->setChecked(false);
	
	ui.store_lineEdit->clear();
	ui.store_lineEdit->setPlaceholderText(tr("输入：//+存储IP地址"));
	ui.type_comboBox->setCurrentText("QMYSQL");
	
	ui.host_lineEdit->clear();
	ui.host_lineEdit->setPlaceholderText(tr("数据库IP地址"));
	ui.name_lineEdit->setText("miomi");
	ui.port_lineEdit->setText("3306");
	ui.user_lineEdit->setText("root");
	ui.pass_lineEdit->setText("toor");
}

void SysConfiguration::loadCurrentSetting()
{
	store_ = STORE_HOST;
	
	type_ = DATABASE_TYPE;
	host_ = DATABASE_HOST;
	name_ = DATABASE_NAME;
	user_ = DATABASE_USER;
	pass_ = DATABASE_PASS;
	port_ = DATABASE_PORT;

	lan_ = LAN;

	if (lan_)
	{
		ui.lan_radioButton->setChecked(true);
	}
	else
		ui.local_radioButton->setChecked(true);

	ui.store_lineEdit->setText(store_);
	ui.type_comboBox->setCurrentText(type_);
	ui.host_lineEdit->setText(host_);
	ui.name_lineEdit->setText(name_);
	ui.port_lineEdit->setText(port_);
	ui.user_lineEdit->setText(user_);
	ui.pass_lineEdit->setText(pass_);


}
void SysConfiguration::saveCurrentSetting()
{
	// 保存运行模式配置文件
	setRunningMode(QDir::homePath() + "/MIOMI/miomi_configuration/" + "running_config.md5", lan_);
	// 保存数据库连接配置文件
	QString passWord = ui.pass_lineEdit->text();
	encryptString(passWord);
	writeDatabaseCOnfiguration(QDir::homePath() + "/MIOMI/miomi_configuration/" + "db_config.md5",
		ui.type_comboBox->currentText(),
		ui.host_lineEdit->text(),
		ui.name_lineEdit->text(),
		ui.user_lineEdit->text(),
		passWord,
		ui.port_lineEdit->text());
	// 保存 存储服务器配置文件
	saveStoreHost(QDir::homePath() + "/MIOMI/miomi_configuration/" + "store_config.md5");

	QMessageBox::information(this, tr("保存成功"), tr("新配置将在下次重启后生效！"));

	this->close();
}
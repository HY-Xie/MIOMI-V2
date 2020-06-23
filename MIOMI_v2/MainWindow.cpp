#include "MainWindow.h"

#include "DatabaseInfo.h"
#include "RunningMode.h"
#include "Log.h"
#include "GlobalPath.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QIcon>
#include <QPalette>
#include <QString>
#include <ctime>
#include <cstdlib>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setCentralWidget(ui.back_widget);
	ui.back_widget->setMouseTracking(true);
	setMouseTracking(true);

	initRelatedFiles();
	// ������ʼ��
	
	logoff_timer = nullptr;
	logoff_timer = new QTimer(this);
	connect(logoff_timer, &QTimer::timeout, this, &MainWindow::logoff_timeout);
	logoff_timer->setInterval(1000 * 3600);
	logoff_timer->start();

	db_ = nullptr;
	login_success = false;
	duty_ = DEFAULT_;
	currentId_ = "";
	background_ = nullptr;
	image_vec_.clear();
	permanent_label_ = new QLabel();
	//ui.statusBar->addPermanentWidget(permanent_label_);
	changePermanentStatusBar(tr("δ��¼ "));

	

	addCustomerWidget_ = nullptr;
	searchCustomer_ = nullptr;
	modifyCustomer_ = nullptr;
	sysSetting_ = nullptr;
	changePersonalInfo_ = nullptr;
	addEmployee_ = nullptr;
	searchModifyEmployee_ = nullptr;
	setSKU_ = nullptr;
	sell_ = nullptr;
	personalConsumptionDetail_ = nullptr;
	prodSearch_ = nullptr;

	

	image_vec_.push_back(":/MainWindow/Resources/background_6m.png");
	image_vec_.push_back(":/MainWindow/Resources/background1.jpg");
	image_vec_.push_back(":/MainWindow/Resources/background_3.jpg");
	//image_vec_.push_back(":/MainWindow/Resources/background1.jpg");
	//image_vec_.push_back(":/MainWindow/Resources/background_6m.png");
	//image_vec_.push_back(":/MainWindow/Resources/background_6m.png");
	// ��ʼ������
	initGUI();
		// ��ʼ��actoin������
	//disableAllActionsAtBegin();	// �ú���������
	judgeActionStatus();
	//ui.back_widget->repaint();
		// ������ñ���ͼƬ
	srand((int)time(0)); 
		// ���� [X, Y] ֮��������rand() % (Y - X + 1) + X
		// https://blog.csdn.net/qq_21808961/article/details/78204418
		// int idx = rand() % (image_vec_.size()-1 - 0 + 1) + 0;
	int idx = rand() % image_vec_.size();
	background_ = new QImage();
	background_->load(image_vec_[idx]);
	ui.back_widget->setAutoFillBackground(true);
	QPalette pal(palette());
	pal.setBrush(QPalette::Window, QBrush(background_->scaled(ui.back_widget->size(), Qt::IgnoreAspectRatio,
		Qt::SmoothTransformation)));
	ui.back_widget->setPalette(pal);

	// Singals and SLots
	connect(ui.id_lineEdit, &QLineEdit::editingFinished, this, 
		[=]() {
		QString name = ui.id_lineEdit->text();
		if (name.size() != 0 && name.length() < 6)
		{
			int res = 6 - name.length();
			for (int i = 0; i < res; ++i)
				name.insert(0, "0");
			ui.id_lineEdit->setText(name);
		}
	});
	
	connect(ui.pw_lineEdit, &QLineEdit::returnPressed, this, &MainWindow::login_pushButton_slot);
	connect(ui.login_pushButton, &QPushButton::clicked, this, &MainWindow::login_pushButton_slot);
	connect(ui.exit_pushButton, &QPushButton::clicked, this, &MainWindow::close);

	// ���������Ĭ���������ݿ�
#ifdef MY_DEBUG
	DATABASE_HOST = "127.0.0.1";
	DATABASE_NAME = "miomi";
	DATABASE_USER = "root";
	DATABASE_PASS = "toor";
#endif

	db_ = new QSqlDatabase(QSqlDatabase::addDatabase(DATABASE_TYPE));
	db_->setHostName(DATABASE_HOST);
	db_->setDatabaseName(DATABASE_NAME);
	db_->setUserName(DATABASE_USER);
	db_->setPassword(DATABASE_PASS);
	db_->setPort(DATABASE_PORT.toInt());
	if (db_->open())
	{
		ui.database_connect_status->setText(tr("���ݿ����ӳɹ����ɼ�����¼") + db_->lastError().text());
		QString context = "���ݿ����ӳɹ�" ;
		writeLog(context,1);
		db_->close();
	}
	else {
		ui.database_connect_status->setText(tr("���ݿ�����ʧ�ܣ��޷���¼ : ") + db_->lastError().text());
		QString context = QObject::tr("���ݿ�����ʧ��: ") + db_->lastError().text();
		writeLog(context,1);
		ui.login_pushButton->setDisabled(true);
		QMessageBox::information(this, tr("����ʧ��"), context);
		return;
	}
	
	//addCustomerWidget_ = new AddCustomerWidget();
	//searchCustomer_ = new SearchCustomerWidget(this);
	//modifyCustomer_ = new ModifyCustomerWidget(this);
	//personalConsumptionDetail_ = new PersonalConsumptionDetailWidget(this);
	//addEmployee_ = new AddEmployeeWidget(this);
	//searchModifyEmployee_ = new SearchModifyEmployeeWidget(this);
	//setSKU_ = new SetSKUWidget(this);
	//sell_ = new SellWidget(this);
	//prodSearch_ = new ProdSearch(this);
	//sysSetting_ = new SysConfiguration(this);
	//changePersonalInfo_ = new ChangePersonalInfoWidget(this);

	// �����ã� ��ɾ
	//ui.id_lineEdit->setText("000001");
	//ui.pw_lineEdit->setText("111111");
}

MainWindow::~MainWindow()
{
	if (db_ != nullptr)
	{
		delete db_;
		db_ = nullptr;
	}

	if (logoff_timer != nullptr)
	{
		delete logoff_timer;
		logoff_timer = nullptr;
	}

	if (background_ != nullptr)
	{
		delete background_;
		background_ = nullptr;
	}
	////////////////////////////////

	/*if (addCustomerWidget_ != nullptr)
	{
		delete addCustomerWidget_;
		addCustomerWidget_ = nullptr;
	}
	if (searchCustomer_ != nullptr)
	{
		delete searchCustomer_;
		searchCustomer_ = nullptr;
	}*/

	/*if (changePersonalInfo_ != nullptr)
	{
		delete changePersonalInfo_;
		changePersonalInfo_ = nullptr;
	}

	if (modifyCustomer_ != nullptr)
	{
		delete modifyCustomer_;
		modifyCustomer_ = nullptr;
	}
	if (sysSetting_ != nullptr)
	{
		delete sysSetting_;
		sysSetting_ = nullptr;
	}
	if (addEmployee_ != nullptr)
	{
		delete addEmployee_;
		addEmployee_ = nullptr;
	}
	if (searchModifyEmployee_ != nullptr)
	{
		delete searchModifyEmployee_;
		searchModifyEmployee_ = nullptr;
	}

	if (setSKU_ != nullptr)
	{
		delete setSKU_;
		setSKU_ = nullptr;
	}

	if (sell_ != nullptr)
	{
		delete sell_;
		sell_ = nullptr;
	}

	if (personalConsumptionDetail_ != nullptr)
	{
		delete personalConsumptionDetail_;
		personalConsumptionDetail_ = nullptr;
	}

	if (prodSearch_ != nullptr);
	{
		delete prodSearch_;
		prodSearch_ = nullptr;
	}*/
}

int MainWindow::getCurrentNumOfCustomer()
{
	QString sql = "select * from customer";
	QSqlQuery query;
	int numOfCustomer = -1;
	if (db_->open())
	{
		if (query.exec(sql))
		{
			numOfCustomer = query.size();
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



void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
	if (login_success)
	{
		newPos = event->pos();
		
		oldPos = newPos;

		deciedLogOff();
	}
}

void MainWindow::deciedLogOff()
{
	if (login_success)
	{
		if (newPos == oldPos)
		{
			logoff_timer->start();
		}
		else
		{
			logoff_timer->stop();
		}
	}
}

void MainWindow::logoff_timeout()
{
	logoff_slot();
	QMessageBox::information(this, tr("�Զ�ע��"), tr("���ڳ�ʱ���޲�����ϵͳ�Զ�ע���������µ�¼"));
}





void MainWindow::login_pushButton_slot()
{
	QString id = ui.id_lineEdit->text();
	QString pw = ui.pw_lineEdit->text();
	if (id.isEmpty() || pw.isEmpty())
	{
		if (id.isEmpty())
		{
			QMessageBox::information(this, QObject::tr("�˺Ŵ���"), QObject::tr("�˺Ų���Ϊ��"));
			//writeLog("����Ϊ��");
			return;
		}
		if (pw.isEmpty())
		{
			QMessageBox::information(this, QObject::tr("����Ϊ��"), QObject::tr("���벻��Ϊ��"));
			//writeLog("����Ϊ��");
			return;
		}
	}
	if (id.length() < 6)
	{
		int res = 6 - id.length();
		for (int i = 0; i < res; ++i)
		{
			id.insert(0, "0");
		}
	}
	bool flag = false;
	if (db_->open())
	{
		
		QSqlQuery query;
		QString sql = "select employee_Id, employee_PassWord, employee_Duty, employee_Tel from employee where employee_Id = '" + id + "' or employee_Tel = '" + id + "'";
		QString title, message, content;
		login_success = false;
		if (query.exec(sql))
		{
			query.next();
			QString first_id = query.value(0).toString();
			QString first_pw = query.value(1).toString();
			QString first_tel = query.value(3).toString();
			int first_duty = query.value(2).toString().toInt();
			if (first_duty == DIMISSION_)
			{
				title = QObject::tr("�޷���¼");
				message = QObject::tr("��ְ��Ա�޷���¼");
			}
			else if (first_id.isEmpty())
			{
				title = QObject::tr("�û�������");
				message = QObject::tr("�û������ڣ��˶Ժ����룡");
				
			}
			else
			{
				if (pw != first_pw)
				{
					// �������
					title = QObject::tr("�������");
					message = QObject::tr("����������������룡");
					flag = true;
					
				}
				else
				{
					title = QObject::tr("��¼�ɹ�");
					message = QObject::tr("��¼�ɹ�");
					login_success = true;
					if (first_duty == 1)
						duty_ = BOSS_;
					if (first_duty == 2)
						duty_ = MANAGER_;
					if (first_duty == 3)
						duty_ = STAFF_;
					
					currentId_ = first_id;
				}

			}
		}
		else
		{
			title = QObject::tr("SQL��ѯ����");
			message = query.lastError().text();
		}
		writeLog(QObject::tr("����: ") + id + "\t" +  message);
		QMessageBox::information(this, title, message);
		if (login_success)
		{
			ui.login_info_widget->close(); 
			
			
			/*permanent_label_->setText(tr("��ǰ��¼����: ") + id);
			ui.statusBar->addPermanentWidget(permanent_label_);*/
			changePermanentStatusBar(tr("��ǰ��¼����: ") + id + tr(" "));
			
		}
		
		db_->close();
		
	}

	if (!flag)
		ui.id_lineEdit->clear();
	ui.pw_lineEdit->clear();

	ui.mainToolBar->removeAction(action_sysConfiguration_);

	judgeActionStatus();
	
}





void MainWindow::logoff_slot()
{
	login_success = false;
	duty_ = DEFAULT_;
	QString context = QObject::tr("���ţ�") + currentId_ + QObject::tr("\tע��");
	currentId_ = "";
	writeLog(context);
	/*permanent_label_->setText("");
	ui.statusBar->addPermanentWidget(permanent_label_);*/
	changePermanentStatusBar(tr("δ��¼ "));
	judgeActionStatus();
	ui.mainToolBar->addAction(action_sysConfiguration_);
	ui.login_info_widget->show();
	if (addCustomerWidget_ != nullptr)
	{
		delete  addCustomerWidget_;
		addCustomerWidget_ = nullptr;
	}
	if (searchCustomer_ != nullptr)
	{
		delete  searchCustomer_;
		searchCustomer_ = nullptr;
	}
		

}

void MainWindow::addCustomer_openWidget_slot()
{
	addCustomerWidget_ = new AddCustomerWidget(this);
	connect(this, &MainWindow::sendInfo, addCustomerWidget_, &AddCustomerWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	addCustomerWidget_->setWindowModality(Qt::WindowModal);
	addCustomerWidget_->setAttribute(Qt::WA_DeleteOnClose);
	addCustomerWidget_->show();
}

void MainWindow::searchCustomer_openWidget_slot()
{
	searchCustomer_ = new SearchCustomerWidget(this);
	connect(this, &MainWindow::sendInfo, searchCustomer_, &SearchCustomerWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	searchCustomer_->setWindowModality(Qt::WindowModal);
	searchCustomer_->setAttribute(Qt::WA_DeleteOnClose);
	//searchCustomer_->show();
	searchCustomer_->showMaximized();

}

void MainWindow::modifyCustomer_openWidget_slot()
{
	modifyCustomer_ = new ModifyCustomerWidget(this);
	connect(this, &MainWindow::sendInfo, modifyCustomer_, &ModifyCustomerWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	modifyCustomer_->setWindowModality(Qt::WindowModal);
	modifyCustomer_->setAttribute(Qt::WA_DeleteOnClose);
	//searchCustomer_->show();
	modifyCustomer_->showMaximized();
}

void MainWindow::personalConsumptionDetail_openWidget_slot()
{
	personalConsumptionDetail_ = new PersonalConsumptionDetailWidget(this);
	connect(this, &MainWindow::sendInfo, personalConsumptionDetail_, &PersonalConsumptionDetailWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	personalConsumptionDetail_->setWindowModality(Qt::WindowModal);
	personalConsumptionDetail_->setAttribute(Qt::WA_DeleteOnClose);
	personalConsumptionDetail_->initGUI();
	personalConsumptionDetail_->show();
}

void MainWindow::addAmployee_openWidget_slot()
{
	addEmployee_ = new AddEmployeeWidget(this);
	connect(this, &MainWindow::sendInfo, addEmployee_, &AddEmployeeWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	addEmployee_->setWindowModality(Qt::WindowModal);
	addEmployee_->setAttribute(Qt::WA_DeleteOnClose);
	//searchCustomer_->show();
	addEmployee_->initGUIAccordingCurrentId();
	addEmployee_->setFixedSize(500, 580);
	addEmployee_->show();
}

void MainWindow::searchModifyEmployee_openWidget_slot()
{
	searchModifyEmployee_ = new SearchModifyEmployeeWidget(this);
	connect(this, &MainWindow::sendInfo, searchModifyEmployee_, &SearchModifyEmployeeWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	searchModifyEmployee_->setWindowModality(Qt::WindowModal);
	searchModifyEmployee_->setAttribute(Qt::WA_DeleteOnClose);
	//searchModifyEmployee_->setGeometry(300, 300, 1010, 610);
	//searchModifyEmployee_->setFixedSize(1200, 650);
	searchModifyEmployee_->initGUIAccordingCurrentId();
	searchModifyEmployee_->showMaximized();

}

void MainWindow::setSKU_openWidget_slot()
{
	setSKU_ = new SetSKUWidget(this);
	connect(this, &MainWindow::sendInfo, setSKU_, &SetSKUWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	setSKU_->setWindowModality(Qt::WindowModal);
	setSKU_->setAttribute(Qt::WA_DeleteOnClose);
	setSKU_->initGUI();
	setSKU_->show();
}

void MainWindow::sell_openWidget_slot()
{
	sell_ = new SellWidget(this);
	connect(this, &MainWindow::sendInfo, sell_, &SellWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	sell_->setWindowModality(Qt::WindowModal);
	sell_->setAttribute(Qt::WA_DeleteOnClose);
	sell_->initGUI();
	sell_->show();
}

void MainWindow::prodSearch_openWidget_slot()
{
	prodSearch_ = new ProdSearch(this);
	connect(this, &MainWindow::sendInfo, prodSearch_, &ProdSearch::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	prodSearch_->setWindowModality(Qt::WindowModal);
	prodSearch_->setAttribute(Qt::WA_DeleteOnClose);
	prodSearch_->initGUI();
	prodSearch_->showMaximized();
}



void MainWindow::sysConfiguration_openWidget_slot()
{
	sysSetting_ = new SysConfiguration(this);
	sysSetting_->setWindowModality(Qt::WindowModal);
	sysSetting_->setAttribute(Qt::WA_DeleteOnClose);
	sysSetting_->setFixedSize(450, 500);
	sysSetting_->show();
}

void MainWindow::changePersonalInfo_openWidget_slot()
{
	changePersonalInfo_ = new ChangePersonalInfoWidget(this);
	connect(this, &MainWindow::sendInfo, changePersonalInfo_, &ChangePersonalInfoWidget::receiveInfo);
	emit sendInfo(db_, duty_, currentId_);
	changePersonalInfo_->setWindowModality(Qt::WindowModal);
	changePersonalInfo_->setAttribute(Qt::WA_DeleteOnClose);
	changePersonalInfo_->initInfoAccording(currentId_);
	changePersonalInfo_->setFixedSize(1000, 440);
	changePersonalInfo_->show();
}


void MainWindow::initRelatedFiles()
{

	// 1. ��־�ļ��� �ڵ�ǰĿ¼�´�����־�ļ��У������Ƿ�ʹ�ø���LAN��ֵ����
	QString logFolder = QDir::homePath() + "/MIOMI/logs/";
	QDir logDir = QDir(logFolder);
	if (!logDir.exists())
	{
		//logDir.mkpath(logFolder);
		logDir.mkpath(logFolder + "userlogs/");
		logDir.mkpath(logFolder + "syslogs/");
	}


	// 2. ���ݿ������ļ���
	// a. �����ļ����Ƿ����, �����ھʹ���
	//QString folder = QDir::currentPath() + "/miomi_configuration/";
	//QString folder = "./" "miomi_configuration/";
	QString folder = QDir::homePath() + "/MIOMI/miomi_configuration/";
	QDir dir = QDir(folder);
	bool has = dir.exists(folder);
	if (!has)	// ���û�У������ļ���
	{
		//bool success = dir.mkdir(folder);
		bool success = dir.mkpath(folder);
		if (!success)
		{
			QMessageBox::information(this, tr("����"), tr("���������ļ��д���ʧ��"));
   			writeLog("���������ļ��д���ʧ��", 1);
			exit(-1);
		}
		else
		{
			// ���ݿ������ļ�
			QString pass = DATABASE_PASS;		// ϵͳ��һ�����У�������DATABASE_PASS��Ҫ�ã������ڴ˴�����
			encryptString(pass);	// д֮ǰ����
			writeDatabaseCOnfiguration(folder + "db_config.md5",
				DATABASE_TYPE,
				DATABASE_HOST,
				DATABASE_NAME,
				DATABASE_USER,
				pass,
				DATABASE_PORT);

			// ����ģʽ�����ļ���Ĭ�ϵ�����LAN == false��
			setRunningMode(folder + "running_config.md5", LAN);

			// �洢�����ļ�
			saveStoreHost(folder + "store_config.md5");
			
		}
	}
	else    // ����У���ȡ���ݿ�������ļ�
	{
		
		readDatabaseConfiguration(folder + "db_config.md5");
		decryptString(DATABASE_PASS);	// ��ȡ֮�����
		loadRunningMode(folder + "running_config.md5");
		loadStoreHost(folder + "store_config.md5");
	}


	// �ڵ�ǰĿ¼�´������Ա����Ƭ���ļ��У������Ƿ�ʹ�ø���LAN��ֵ����
	QString employeePhotoFolder = QDir::homePath() + "/MIOMI/employee_photos/";
	QDir employee_dir = QDir(employeePhotoFolder);
	if (!employee_dir.exists())
		employee_dir.mkpath(employeePhotoFolder);

	
}

// ��ͬ�û���¼����ĵĹ�����ԣ�ȫ������initGUI�д�����ͨ��paintEvent�����Ƿ����
// �÷������ã���Ч�����ã����paintEvent����update�������������˸
// ���û��update�������ڲ˵�������������
void MainWindow::initGUI()
{
	

	initActions();
	initMenus();
	initToolBars();
	initStatusBars();
}
void MainWindow::initActions()
{	
	// --------------------------------�ļ�
	action_logoff_ = new QAction(QIcon(":/MainWindow/Resources/logoff.png"), tr("ע��"), this);
	action_logoff_->setStatusTip(tr("ע��/�˳���¼"));
	connect(action_logoff_, &QAction::triggered, this, &MainWindow::logoff_slot);

	action_exit_ = new QAction(QIcon(":/MainWindow/Resources/exit.png"), tr("�˳�"), this);
	action_exit_->setStatusTip(tr("�˳�����ƽ̨"));
	connect(action_exit_, &QAction::triggered, this, &MainWindow::close);

	// --------------------------------��Ա
	action_addCustomer_ = new QAction(QIcon(":/MainWindow/Resources/addCustomer.png"), tr("��ӻ�Ա"), this);
	action_addCustomer_->setStatusTip(tr("����»�Ա"));
	connect(action_addCustomer_, &QAction::triggered, this, &MainWindow::addCustomer_openWidget_slot);

	action_searchCustomer_ = new QAction(QIcon(":/MainWindow/Resources/search.png"), tr("��ѯ��Ա"), this);
	action_searchCustomer_->setStatusTip(tr("��ѯ���л�Ա��Ϣ���޷�������Ϣ�޸�"));
	connect(action_searchCustomer_, &QAction::triggered, this, &MainWindow::searchCustomer_openWidget_slot);

	action_modifyCustomer_ = new QAction(QIcon(":/MainWindow/Resources/modify_vip.png"), tr("�޸Ļ�Ա"), this);
	action_modifyCustomer_->setStatusTip(tr("�޸Ļ�Ա��Ϣ"));
	connect(action_modifyCustomer_, &QAction::triggered, this, &MainWindow::modifyCustomer_openWidget_slot);

	action_personalConsumptionDetail_ = new QAction(QIcon(":/MainWindow/Resources/member_record.png"), tr("������������"), this);
	action_personalConsumptionDetail_->setStatusTip(tr("��ѯ��Ա��������"));
	connect(action_personalConsumptionDetail_, &QAction::triggered, this, &MainWindow::personalConsumptionDetail_openWidget_slot);


	// --------------------------------Ա��
	action_addAmployee_ = new QAction(QIcon(":/MainWindow/Resources/new_72px_employee.png"), tr("���Ա��"), this);
	action_searchCustomer_->setStatusTip(tr("�����Ա��"));
	connect(action_addAmployee_, &QAction::triggered, this, &MainWindow::addAmployee_openWidget_slot);

	action_searchModifyEmployee_ = new QAction(QIcon(":/MainWindow/Resources/users_search.png"), tr("��ѯ/�޸�Ա��"), this);
	action_searchModifyEmployee_->setStatusTip(tr("��ѯ/�޸�Ա����Ϣ"));
	connect(action_searchModifyEmployee_, &QAction::triggered, this, &MainWindow::searchModifyEmployee_openWidget_slot);
	
	// --------------------------------��Ʒ
	action_setSKU_ = new QAction(QIcon(":/MainWindow/Resources/input.png"), tr("����"), this);
	action_setSKU_->setStatusTip(tr("�»�¼�벢����SKU"));
	connect(action_setSKU_, &QAction::triggered, this, &MainWindow::setSKU_openWidget_slot);

	action_sell_ = new QAction(QIcon(":/MainWindow/Resources/sell.png"), tr("����"), this);
	action_sell_->setStatusTip(tr("����"));
	connect(action_sell_, &QAction::triggered, this, &MainWindow::sell_openWidget_slot);

	action_prodSearch_ = new QAction(QIcon(":/MainWindow/Resources/find.png"), tr("��ѯ"), this);
	action_prodSearch_->setStatusTip(tr("��ѯ"));
	connect(action_prodSearch_, &QAction::triggered, this, &MainWindow::prodSearch_openWidget_slot);


	// --------------------------------����
	action_changePersonalInfo_ = new QAction(QIcon(":/MainWindow/Resources/peronal_setting.png"), tr("������Ϣ�޸�"), this);
	action_changePersonalInfo_->setStatusTip(tr("�޸ĸ�����Ϣ"));
	connect(action_changePersonalInfo_, &QAction::triggered, this, &MainWindow::changePersonalInfo_openWidget_slot);

	action_sysConfiguration_ = new QAction(QIcon(":/MainWindow/Resources/system_72px_.png"), tr("ϵͳ����"), this);
	action_sysConfiguration_->setStatusTip(tr("�޸�ϵͳ����"));
	connect(action_sysConfiguration_, &QAction::triggered, this, &MainWindow::sysConfiguration_openWidget_slot);


	
}
void MainWindow::initMenus()
{
	// �ļ��˵�
	menu_file_ = menuBar()->addMenu(tr("�ļ�"));
	menu_file_->addAction(action_logoff_);
	menu_file_->addAction(action_exit_);

	// ��Ա����˵�
	menu_membership_ = menuBar()->addMenu(tr("��Ա����"));
	menu_membership_->addAction(action_addCustomer_);
	menu_membership_->addAction(action_searchCustomer_);
	menu_membership_->addAction(action_modifyCustomer_);
	menu_membership_->addAction(action_personalConsumptionDetail_);
	

	// ��Ʒ�˵�
	menu_product_ = menuBar()->addMenu(tr("��Ʒ����"));
	menu_product_->addAction(action_setSKU_);
	menu_product_->addAction(action_sell_);
	menu_product_->addAction(action_prodSearch_);
	

	// Ա���˵�
	menu_employee_ = menuBar()->addMenu(tr("Ա������"));
	menu_employee_->addAction(action_addAmployee_);
	menu_employee_->addAction(action_searchModifyEmployee_);

	
	
	
	// ���ò˵�
	menu_setting_ = menuBar()->addMenu(tr("����"));
	menu_setting_->addAction(action_sysConfiguration_);		
	menu_setting_->addSeparator();
	menu_setting_personalSetting = menu_setting_->addMenu(tr("��������"));// �Ӳ˵�
	menu_setting_personalSetting->addAction(action_changePersonalInfo_);
}
void MainWindow::initToolBars()
{
	// ��Ա
	//ui.mainToolBar->setWindowOpacity(0);
	//ui.mainToolBar->addAction(action_logoff_);
	ui.mainToolBar->addAction(action_addCustomer_);
	ui.mainToolBar->addAction(action_searchCustomer_);
	ui.mainToolBar->addAction(action_modifyCustomer_);
	ui.mainToolBar->addAction(action_personalConsumptionDetail_);

	// Ա��
	ui.mainToolBar->addSeparator();	
	ui.mainToolBar->addAction(action_addAmployee_);
	ui.mainToolBar->addAction(action_searchModifyEmployee_);


	// ��Ʒ
	ui.mainToolBar->addSeparator();
	//ui.mainToolBar->addAction(action_setSKU_);
	ui.mainToolBar->addAction(action_setSKU_);
	ui.mainToolBar->addAction(action_sell_);
	ui.mainToolBar->addAction(action_prodSearch_);




	// ����
	ui.mainToolBar->addSeparator();
	//ui.mainToolBar->addAction(action_changePersonalInfo_);
	ui.mainToolBar->addAction(action_sysConfiguration_);		// ϵͳ���ã���½��ӽ����Ƴ�
	
}
void MainWindow::initStatusBars()
{
	/*if (login_success)
		ui.statusBar->showMessage(tr("��ǰ��¼���ţ�") + currentId_);
	else
		ui.statusBar->showMessage(tr("δ��¼"));*/
	if(LAN == true)
		ui.statusBar->showMessage(tr("׼������(LAN)"));
	else
		ui.statusBar->showMessage(tr("׼������(����ģʽ)"));
}

void MainWindow::disableAllActionsAtBegin()		// �ĺ���������
{
	action_logoff_->setDisabled(true);
	action_addCustomer_->setDisabled(true);
	action_searchCustomer_->setDisabled(true);
	action_changePersonalInfo_->setDisabled(true);
	

}

void MainWindow::judgeActionStatus()
{
	action_exit_->setDisabled(false);	// ��Զ�ɼ�
	

	if (login_success)	// ��¼�ɹ�
	{	// ��¼�ɹ���ȫ���ɼ�
		action_logoff_->setDisabled(false);
		action_addCustomer_->setDisabled(false);
		action_searchCustomer_->setDisabled(false);
		action_changePersonalInfo_->setDisabled(false);
		action_modifyCustomer_->setDisabled(false);
		action_addAmployee_->setDisabled(false);
		action_searchModifyEmployee_->setDisabled(false);
		action_setSKU_->setDisabled(false);
		action_sell_->setDisabled(false);
		action_personalConsumptionDetail_->setDisabled(false);
		action_prodSearch_->setDisabled(false);
		action_sysConfiguration_->setDisabled(false);	

		if (duty_ == BOSS_)
		{

		}
		if (duty_ == MANAGER_)
		{
			action_sysConfiguration_->setDisabled(true);
		}
		if (duty_ == STAFF_)
		{
			action_addAmployee_->setDisabled(true);
			action_sysConfiguration_->setDisabled(true);
		}
	}
	else
	{
		// �����˳������������ڵ�½ǰ�������� �� δ��¼ʱ״̬��
		action_logoff_->setDisabled(true);
		action_addCustomer_->setDisabled(true);
		action_searchCustomer_->setDisabled(true);
		action_changePersonalInfo_->setDisabled(true);
		action_modifyCustomer_->setDisabled(true);
		action_addAmployee_->setDisabled(true);
		action_searchModifyEmployee_->setDisabled(true);
		action_setSKU_->setDisabled(true);
		action_sell_->setDisabled(true);
		action_personalConsumptionDetail_->setDisabled(true);
		action_prodSearch_->setDisabled(true);
		action_sysConfiguration_->setDisabled(true);
	}
}

void MainWindow::changePermanentStatusBar(const QString & label)
{
	permanent_label_->setText(label);
	ui.statusBar->addPermanentWidget(permanent_label_);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
	
	//initStatusBars();
	

	

	//update();

}

void MainWindow::closeEvent(QCloseEvent * event)
{
	QString context = QObject::tr("����: ") + currentId_ + QObject::tr("\t�˳�"); 
	if(!currentId_.isEmpty())
		writeLog(context);
	currentId_ = "";
	

}

void MainWindow::resizeEvent(QResizeEvent * event)
{
	/*QWidget::resizeEvent(event);
	QDesktopWidget* desktopWidget = QApplication::desktop();
	QRect deskRect = desktopWidget->availableGeometry();
	QRect back_rect = QRect(0, 0, this->width(), this->height());
	ui.back_label->setGeometry(back_rect);
	QImage img = background_.scaled(back_rect.width(), back_rect.height(), Qt::IgnoreAspectRatio, Qt::FastTransformation);
	ui.back_label->setAutoFillBackground(true);
	ui.back_label->setScaledContents(true);
	QPalette palette = ui.back_label->palette();
	palette.setBrush(ui.back_label->backgroundRole(), QBrush(img.scaled(ui.back_label->size(), Qt::KeepAspectRatio, Qt::FastTransformation)));
	ui.back_label->setPalette(palette);*/

	QWidget::resizeEvent(event);
	QPalette pal(palette());
	QImage *img = new QImage();
	*img = *background_;
	//pal.setBrush(QPalette::Window, QBrush(img->scaled(event->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
	pal.setBrush(QPalette::Window, QBrush(img->scaled(ui.back_widget->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
	ui.back_widget->setPalette(pal);
	delete img;
}


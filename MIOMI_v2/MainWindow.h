#pragma once
#include "ChineseSupport.h"
#include <QSqlDatabase>
#include "Duty.h"
#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QImage>
#include <QVector>

#include <QPaintEvent>
#include <QCloseEvent>
#include <QResizeEvent>

#include "AddCustomerWidget.h"
#include "SearchCustomerWidget.h"
#include "ChangePersonalInfoWidget.h"
#include "ModifyCustomerWidget.h"
#include "SysConfiguration.h"
#include "AddEmployeeWidget.h"
#include "SearchModifyEmployeeWidget.h"
#include "SellWidget.h"
#include "SetSKUWidget.h"
#include "PersonalConsumptionDetailWidget.h"
#include "ProdSearch.h"


#include <QTimer>
#include <QMouseEvent>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	int getCurrentNumOfCustomer();
private:
	QTimer * logoff_timer;
	QPoint oldPos;
	QPoint newPos;
	void mouseMoveEvent(QMouseEvent *event);
	void deciedLogOff();
	void logoff_timeout();

	QSqlDatabase * db_;
	bool login_success = false;
	DUTY duty_;
	QString currentId_;
	QVector<QString> image_vec_;
	QImage *background_;
	QLabel *permanent_label_;
	


private:	// gui
	// 文件
	QMenu * menu_file_;
	QAction * action_logoff_;
	void login_pushButton_slot();
	void logoff_slot();
	QAction * action_exit_;
	// 会员管理
	QMenu * menu_membership_;
	QAction * action_addCustomer_;
	void addCustomer_openWidget_slot();
	AddCustomerWidget * addCustomerWidget_;

	QAction * action_searchCustomer_;
	void searchCustomer_openWidget_slot();
	SearchCustomerWidget *searchCustomer_;

	QAction * action_modifyCustomer_;
	void modifyCustomer_openWidget_slot();
	ModifyCustomerWidget *modifyCustomer_;

	QAction *action_personalConsumptionDetail_;
	void personalConsumptionDetail_openWidget_slot();
	PersonalConsumptionDetailWidget * personalConsumptionDetail_;


	// 员工管理
	QMenu * menu_employee_;
	QAction * action_addAmployee_;
	void addAmployee_openWidget_slot();
	AddEmployeeWidget *addEmployee_;

	QAction * action_searchModifyEmployee_;
	void searchModifyEmployee_openWidget_slot();
	SearchModifyEmployeeWidget * searchModifyEmployee_;

	//  商品管理
	QMenu * menu_product_;

	QAction *action_setSKU_;
	void setSKU_openWidget_slot();
	SetSKUWidget *setSKU_;

	QAction *action_sell_;
	void sell_openWidget_slot();
	SellWidget * sell_;

	QAction *action_prodSearch_;
	void prodSearch_openWidget_slot();
	ProdSearch * prodSearch_;





	// 设置
	QMenu * menu_setting_;
	QAction * action_sysConfiguration_;
	void sysConfiguration_openWidget_slot();
	SysConfiguration * sysSetting_;

	QMenu * menu_setting_personalSetting;
	QAction * action_changePersonalInfo_; 
	void changePersonalInfo_openWidget_slot();
	ChangePersonalInfoWidget *changePersonalInfo_;


	
	
	void initRelatedFiles();	// 系统启动后，先处理日志文件和数据库配置文件
	
	void initGUI();
	void initActions();
	void initMenus();
	void initToolBars();
	void initStatusBars();
	void disableAllActionsAtBegin();
	void judgeActionStatus();
	void changePermanentStatusBar(const QString & label = "");

	void paintEvent(QPaintEvent *event);
	void closeEvent(QCloseEvent *event);
	void resizeEvent(QResizeEvent *event);
	




signals:
	void sendDB(QSqlDatabase *db);
	void sendDuty(DUTY duty);
	void sendCurrentId(QString currentId);
	void sendInfo(QSqlDatabase *db, DUTY duty, QString currentId);


	
};

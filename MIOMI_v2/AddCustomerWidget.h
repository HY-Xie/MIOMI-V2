#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>

#include <QDialog>
#include "ui_AddCustomerWidget.h"

#include <QCloseEvent>

class AddCustomerWidget : public QDialog
{
	Q_OBJECT

public:
	AddCustomerWidget(QWidget *parent = Q_NULLPTR);
	~AddCustomerWidget();

private:
	Ui::AddCustomerWidget ui;

private:
	QSqlDatabase * db_;
	QString currentId_;
	DUTY duty_;
	int numOfCustomer_;
	

	void closeEvent(QCloseEvent *event);
	void add_pushButton_slot();

	int getCurrentNumOfCustomer();
	void setCurrentNumOfCustomer();
	void sameAsTel_weChat_slot();
	void checkBoxState_slot();



public:	// 接收信息的槽
	void receiveDB(QSqlDatabase *db) { db_ = db; }
	void receiveDuty(DUTY duty) { duty_ = duty; }
	void receiveCurrentId(QString currentId) { currentId_ = currentId; }
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId;}

	void receiveTel(QString tel) { ui.tel_lineEdit->setText(tel); }

};

#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>

#include <QDialog>
#include "ui_AddEmployeeWidget.h"

class AddEmployeeWidget : public QDialog
{
	Q_OBJECT

public:
	AddEmployeeWidget(QWidget *parent = Q_NULLPTR);
	~AddEmployeeWidget();

private:
	Ui::AddEmployeeWidget ui;

private:
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;
	int numOfEmployee_;

	int getCurrentNumOfEmployee();
	void setCurrentNumberOfEmployee();
	void sameAsTel_weChat_slot();
	void checkBoxState_slot();

	void add_pushButton_slot();

public:
	void initGUIAccordingCurrentId();


public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId;}
};

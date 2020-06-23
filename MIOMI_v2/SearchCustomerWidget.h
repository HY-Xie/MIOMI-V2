#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QDialog>
#include "ui_SearchCustomerWidget.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTimer>

class SearchCustomerWidget : public QDialog
{
	Q_OBJECT

public:
	SearchCustomerWidget(QWidget *parent = Q_NULLPTR);
	~SearchCustomerWidget();

private:
	Ui::SearchCustomerWidget ui;

private:
	QTimer * searchTimer;

	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;

	QSqlTableModel * model_;


	void search_pushButton_slot();

public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

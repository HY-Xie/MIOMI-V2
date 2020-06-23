#pragma once

#include <QDialog>
#include "ui_PersonalConsumptionDetailWidget.h"
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QVector>
class PersonalConsumptionDetailWidget : public QDialog
{
	Q_OBJECT

public:
	PersonalConsumptionDetailWidget(QWidget *parent = Q_NULLPTR);
	~PersonalConsumptionDetailWidget();

private:
	Ui::PersonalConsumptionDetailWidget ui;

private:

	

	QSqlTableModel * model_;
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;

	QVector<QString> fieldNames_;


	double computeTotalMoney();

	void search_pushButton_slot();

public:
	void initGUI();



public: // 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

#pragma once

#include <QDialog>
#include "ui_SellWidget.h"
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QStringList>
#include "AddCustomerWidget.h"
class SellWidget : public QDialog
{
	Q_OBJECT

public:
	SellWidget(QWidget *parent = Q_NULLPTR);
	~SellWidget();

private:
	Ui::SellWidget ui;

private:
	QSqlDatabase * db_;
	QString currentId_;
	DUTY duty_;

	AddCustomerWidget * addCustomerWidget_;



	void searchCustomer();
	void updateSkuComboBox(const QString &text);
	void updateProductCheck(const QString &text);

	int searchStarInTable(const QString & tableName, const QString &colName, const QString & value, QVector<QString>& fields, QString & error);
	void searchColumnInTable(const QString &tableName, const QString &colName, QStringList & vec, QString &error);


	void ok_pushButton_slot();
public:
	void initGUI();


signals:
	void sendInfo(QSqlDatabase *db, DUTY duty, QString currentId);
	void sendTel(QString tel);

public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

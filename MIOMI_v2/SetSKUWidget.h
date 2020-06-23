#pragma once

#include <QDialog>
#include "ui_SetSKUWidget.h"
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
class SetSKUWidget : public QDialog
{
	Q_OBJECT

public:
	SetSKUWidget(QWidget *parent = Q_NULLPTR);
	~SetSKUWidget();

private:
	Ui::SetSKUWidget ui;

private:
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;
	QSqlTableModel * model_;


	void processGlass();
	void processEyedrop();
	void processNursing();
	void processWash();


	QString getGlassSKU(const QString &brand, const QString &mode, const QString &color = "",
		const QString &degree = "");

	bool skuHasExist(const QString &tableName, const QString &col, const QString &item, const QString &value, int & amount);
	bool updateAmount(const QString &tableName, const QString &col, const QString &item, const QString &value, const int &amount);

	void save_pushButton_slot();

	void displayGlassSku();
	void displayEyedropSku();
	void displayNursingSku();
	void displayWashSku();

	void deleteLastChar();
	void mySort(int col);

	void obtainValues(const QModelIndex & index);
public:
	void initGUI();
	void changeTableView(int tabIdx);


	
public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

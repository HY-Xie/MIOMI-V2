#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"
#include <QSqlDatabase>

#include <QDialog>
#include "ui_ChangePersonalInfoWidget.h"
#include <QVector>
#include <QImage>

class ChangePersonalInfoWidget : public QDialog
{
	Q_OBJECT

public:
	ChangePersonalInfoWidget(QWidget *parent = Q_NULLPTR);
	~ChangePersonalInfoWidget();

private:
	Ui::ChangePersonalInfoWidget ui;

private:
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;

	QImage * image_;
	

public:
	void initInfoAccording(const QString &currentId);

private:
	
	QVector<QString> fields_;

	void save_pushButton_slot();
	void photo_toolButton_slot();

public: // 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

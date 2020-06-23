#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTimer>
#include <QVector>
#include <QDialog>
#include "ui_SearchModifyEmployeeWidget.h"
#include <QModelIndex>
#include <QCloseEvent>
class SearchModifyEmployeeWidget : public QDialog
{
	Q_OBJECT

public:
	SearchModifyEmployeeWidget(QWidget *parent = Q_NULLPTR);
	~SearchModifyEmployeeWidget();

private:
	Ui::SearchModifyEmployeeWidget ui;

private:
	QMenu * rightMenu_;
	QAction *action_dimission_;
	int selectedRow;
	void createRightMenu();
	void clicked_rightMenu(const QPoint &pos);
	void dimission_slot();

	QTimer * search_timer;
	QTimer * save_timer;

	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;
	QSqlTableModel * model_;
	QVector<QString> fieldNames_;

	QVector<QModelIndex> indexRecord_;	// 记录每次双击操作的index
	QVector<QString> valueRecord_;		// 记录每次双击操作修改前的值

	QString old_value_;
	QString new_value_;
	QString value_;

	void search_pushButton_slot();
	void obtain_oldValue_slot(const QModelIndex &index);
	void save_pushButton_slot();

	void closeEvent(QCloseEvent *event);
public:
	void initGUIAccordingCurrentId();


public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

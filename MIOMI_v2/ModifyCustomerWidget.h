#pragma once
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QSqlRecord>

#include <QDialog>
#include "ui_ModifyCustomerWidget.h"

#include <QVector>
#include <QModelIndex>
#include <QCloseEvent>
#include <QTimer>
#include <QHttpPart>
#include "Delegate.h"
//#include <QItemDelegate>
//class NotEditableDelegate : public QItemDelegate
//{
//	Q_OBJECT
//public:
//	explicit NotEditableDelegate(QObject *parent = 0)
//		: QItemDelegate(parent)
//	{}
//
//protected:
//	bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
//	{
//		return false;
//	}
//	QWidget* createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const
//	{
//		return Q_NULLPTR;
//	}
//
//};




class ModifyCustomerWidget : public QDialog
{
	Q_OBJECT

public:
	ModifyCustomerWidget(QWidget *parent = Q_NULLPTR);
	~ModifyCustomerWidget();

private:
	Ui::ModifyCustomerWidget ui;

private:
	QTimer * search_timer;
	QTimer * save_timer;

	QSqlTableModel * model_;
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;
	QVector<QString> fieldNames_;		// ��ű�ͷ����

	QVector<QModelIndex> indexRecord_;	// ��¼ÿ��˫��������index
	QVector<QString> valueRecord_;		// ��¼ÿ��˫�������޸�ǰ��ֵ
	/*QVector<QString> vipRecord_;*/

	void search_pushButton_slot();
	void save_pushButton_slot();
	void obtain_oldValue_slot(const QModelIndex &index);
	
	

	QString old_value_;
	QString new_value_;
	QString value_;

	void closeEvent(QCloseEvent *event);




public: // ������Ϣ�Ĳ�
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId;}
};

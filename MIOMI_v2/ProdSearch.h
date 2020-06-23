#pragma once

#include <QDialog>
#include "ui_ProdSearch.h"
#include "ChineseSupport.h"
#include "Duty.h"
#include "Log.h"

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDate>
#include <QStandardItemModel>
class ProdSearch : public QDialog
{
	Q_OBJECT

public:
	ProdSearch(QWidget *parent = Q_NULLPTR);
	~ProdSearch();

private:
	Ui::ProdSearch ui;

private:
	QStandardItemModel * models_[4];
	QSqlDatabase * db_;
	DUTY duty_;
	QString currentId_;
	QTableView * view[4];

	QString today;
	QString before;

	QVector<QString> glassSkus_;
	QVector<QString> eyedropSkus_;
	QVector<QString> nursingSkus_;
	QVector<QString> washSkus_;

	QVector<QVector<QString> > allSkus_;
	QVector<QVector<int> > allSaleAmount_;
	QVector<QVector<double> > allMoney_;
	QVector<QVector<int> > allStock_;
	void obtainAllSkuAndStock(int n);	// n仅代表目前有几大类商品
	void obtainAllSaleAmount(const QString &begin, const QString &end);
	void obtainAllMoney(const QString &begin, const QString &end);
	

	void search_pushButton_slot();
	void computeTotalMoney(QString &toalMoney, QString &glassMoney, QString &eyedropMoney, QString &nursingMoney, QString &washMoney);

public:

	void initGUI();

public:	// 接收信息的槽
	void receiveInfo(QSqlDatabase *db, DUTY duty, QString currentId) { db_ = db; duty_ = duty; currentId_ = currentId; }
};

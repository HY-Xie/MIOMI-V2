#pragma once

#include <QDialog>
#include "ui_SysConfiguration.h"
#include <QString>

class SysConfiguration : public QDialog
{
	Q_OBJECT

public:
	SysConfiguration(QWidget *parent = Q_NULLPTR);
	~SysConfiguration();


private:
	QString store_, type_, host_, name_, user_, pass_, port_;
	bool lan_;

	void setLocal();
	void setLan();
	void loadCurrentSetting();
	void saveCurrentSetting();

private:
	Ui::SysConfiguration ui;
};

#pragma once
#include <QString>
#include <QFile>
#include <fstream>
#include <ios>
#include <string>
#include <iostream>
#include <QDebug>

extern QString DATABASE_TYPE;
extern QString DATABASE_HOST;
extern QString DATABASE_NAME;
extern QString DATABASE_USER;
extern QString DATABASE_PASS;
extern QString DATABASE_PORT;

void setDATABASE_TYPE(const QString & value); 
void setDATABASE_HOST(const QString & value); 
void setDATABASE_NAME(const QString & value); 
void setDATABASE_USER(const QString & value);
void setDATABASE_PASS(const QString & value);
void setDATABASE_PORT(const QString & value);




void encryptString(QString &str);
void decryptString(QString &str);


bool readDatabaseConfiguration(const QString &fileName);


bool writeDatabaseCOnfiguration(const QString &file,
	const QString &type,
	const QString &host,
	const QString &name,
	const QString &user,
	const QString &pass,
	const QString &port);


/*
配置文件格式：

# Configuration 
DATABASE_TYPE QMYSQL
DATABASE_HOST 127.0.0.1
DATABASE_NAME miomi
DATABASE_USER root
DATABASE_PASS toor
DATABASE_PORT 3306

*/
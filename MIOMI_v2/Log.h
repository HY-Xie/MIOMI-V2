#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <QString>
#include <windows.h> 
#include <ios>

#include <QDate>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>

// ------------------------------------------------
/*
路径说明：
1. 软件使用前，需先建立文件夹 （win10）
1. 日志文件夹，位置随意，名字为 MIOMI_LOGS, 内含两个文件夹SysLogs 和 UserLogs，将MIOMI_LOGS设置为共享。

*/

// //127.0.0.1/testShare/remoteFile.txt
// 数据库配置文件保存在本地
//QString STORE_HOST = "//127.0.0.1";
//void setSTORE_HOST(const QString & host) { STORE_HOST = host; }
//const QString DATABASE_CONFIGURATION_PATH = "./configuration/";
//const QString DATABASE_CONFIGURATION_NAME = "./database_config.md5/";
//
//
//
//const QString LOG_PATH = "/MIOMI_LOGS/";
//const QString USERLOG_PATH = LOG_PATH + "UserLogs/";
//const QString SYSLOG_PATH = LOG_PATH + "SysLogs/";



class Log
{
public:

	Log();
	~Log();

private:
	SYSTEMTIME time;

	QString userFileName;
	QString sysFileName;

	QString dateName;
	QString timeName;

	QString storeHost;

public:
	// 0： 默认，用户日志
	// 1： 系统日志
	void writeLog(const QString &log, int flag = 0);

};

void writeLog(const QString &content, int flag = 0);

void writeLogToDatabase(QSqlDatabase * db, const QString &currentId, const QString &operatin, const QString &content, int flag);


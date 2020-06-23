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
·��˵����
1. ���ʹ��ǰ�����Ƚ����ļ��� ��win10��
1. ��־�ļ��У�λ�����⣬����Ϊ MIOMI_LOGS, �ں������ļ���SysLogs �� UserLogs����MIOMI_LOGS����Ϊ����

*/

// //127.0.0.1/testShare/remoteFile.txt
// ���ݿ������ļ������ڱ���
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
	// 0�� Ĭ�ϣ��û���־
	// 1�� ϵͳ��־
	void writeLog(const QString &log, int flag = 0);

};

void writeLog(const QString &content, int flag = 0);

void writeLogToDatabase(QSqlDatabase * db, const QString &currentId, const QString &operatin, const QString &content, int flag);


#include "Log.h"
#include "GlobalPath.h"
#include "RunningMode.h"
#include <QDir>
Log::Log()
{
	GetLocalTime(&time);
	QString str;
	QString year = str.setNum(time.wYear);
	QString month = str.setNum(time.wMonth);
	QString day = str.setNum(time.wDay);

	QString hour = str.setNum(time.wHour);
	QString minute = str.setNum(time.wMinute);
	QString second = str.setNum(time.wSecond);
	dateName = year + "-" + month + "-" + day;
	timeName = hour + "-" + minute + "-" + second;

	if (LAN == true)
	{
		userFileName = STORE_HOST + "/MIOMI_LOGS/UserLogs/" + dateName + ".log";
		sysFileName = STORE_HOST + "/MIOMI_LOGS/SysLogs/" + dateName + ".log";
	}
	else
	{
		//userFileName = QDir::currentPath() + "/MIOMI_LOGS/UserLogs/" + dateName + ".log";
		userFileName = QDir::homePath() + "/MIOMI/logs/userlogs/" + dateName + ".log";
		
		//sysFileName = QDir::currentPath() + "/MIOMI_LOGS/SysLogs/" + dateName + ".log";
		sysFileName = QDir::homePath() + "/MIOMI/logs/syslogs/" + dateName + ".log";
	}
	
}


Log::~Log()
{
}

void Log::writeLog(const QString &log, int flag)
{


	std::ofstream of;
	
	if (flag == 0)
	{
		of.open(userFileName.toStdString(), std::ios_base::app);
	}
	else if (flag == 1)
	{
		of.open(sysFileName.toStdString(), std::ios_base::app);
	}
	
	if (of.is_open())
	{
		
		QString complete_log = dateName + "--" + timeName + ": " + log;
		std::string str_log = complete_log.toStdString();
		of << str_log << std::endl;
		of.close();
	}
}

void writeLog(const QString &content, int flag)
{
	Log *log = new Log();
	if(flag == 0)
		log->writeLog(content);
	if (flag == 1)
		log->writeLog(content, 1);
	delete log;
}



void writeLogToDatabase(QSqlDatabase * db, const QString &currentId, const QString &operatin, const QString &content, int flag)
{
	QDate today = QDate::currentDate();
	QString date = today.toString("yyyy-MM-dd");
	QSqlQuery query;
	QString seqrch_sql = "select * from log_table";
	

	if (flag == 0)
	{
		if (db->open())
		{
			;
		}
		
	}
	query.exec(seqrch_sql);
	int currentItemNum = query.size();
	currentItemNum++;
	QString currentNumStr; currentNumStr.setNum(currentItemNum);
	QString sql = "insert into log_table values ( " + currentNumStr + ", '" + currentId + "', '" + operatin + "', '" + content + "', '" + date + "')";
	query.exec(sql);

	if (flag == 0)
		db->close();

}
#include "DatabaseInfo.h"

QString DATABASE_TYPE = "QMYSQL";
QString DATABASE_HOST = "13.250.41.253";
QString DATABASE_NAME = "miomi";
QString DATABASE_USER = "root1";
QString DATABASE_PASS = "PassW0rd.";
QString DATABASE_PORT = "3306";


void setDATABASE_TYPE(const QString & value) {
	DATABASE_TYPE = value;
}
void setDATABASE_HOST(const QString & value) {
	DATABASE_HOST = value;
}
void setDATABASE_NAME(const QString & value) {
	DATABASE_NAME = value;
}

void setDATABASE_USER(const QString & value) {
	DATABASE_USER = value;
}
void setDATABASE_PASS(const QString & value) {
	DATABASE_PASS = value;
}
void setDATABASE_PORT(const QString & value) {
	DATABASE_PORT = value;
}

void encryptString(QString &str)
{
	QString copyStr = str;
	str.clear();
	for (int i = 0; i < copyStr.length(); ++i)
	{
		//QString thisChar = copyChar.at(i) + 5;
		char thisChar = copyStr[i].toLatin1();
		char encryptedChar = (char)(thisChar + 5);
		QChar encryptedQChar = QChar(encryptedChar);
		str.append(encryptedQChar);
	}
}

void decryptString(QString &str)
{
	QString copyStr = str;
	str.clear();
	for (int i = 0; i < copyStr.length(); ++i)
	{
		//QString thisChar = copyChar.at(i) + 5;
		char thisChar = copyStr[i].toLatin1();
		char encryptedChar = (char)(thisChar - 5);
		QChar encryptedQChar = QChar(encryptedChar);
		str.append(encryptedQChar);
	}
}

bool readDatabaseConfiguration(const QString &fileName)
{
	// 1. 
	std::ifstream ifile(fileName.toStdString(), std::ios_base::in);
	{
		if (ifile.is_open())
		{

			std::string c_type;
			getline(ifile, c_type);
			//std::cout << c_type << std::endl;
			QString type = QString::fromStdString(c_type);
			DATABASE_TYPE = type.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			std::string c_host;
			getline(ifile, c_host);
			//std::cout << c_type << std::endl;
			QString host = QString::fromStdString(c_host);
			DATABASE_HOST = host.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			std::string c_name;
			getline(ifile, c_name);
			//std::cout << c_type << std::endl;
			QString name = QString::fromStdString(c_name);
			DATABASE_NAME = name.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			std::string c_user;
			getline(ifile, c_user);
			//std::cout << c_type << std::endl;
			QString user = QString::fromStdString(c_user);
			DATABASE_USER = user.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			std::string c_pass;
			getline(ifile, c_pass);
			//std::cout << c_type << std::endl;
			QString pass = QString::fromStdString(c_pass);
			DATABASE_PASS = pass.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			std::string c_port;
			getline(ifile, c_port);
			//std::cout << c_type << std::endl;
			QString prot = QString::fromStdString(c_port);
			DATABASE_PORT = prot.split(" ").back();
			//qDebug() << DATABASE_TYPE;

			ifile.close();
			return true;
		}
	}

	return false;
}


bool writeDatabaseCOnfiguration(const QString &file,
	const QString &type,
	const QString &host,
	const QString &name,
	const QString &user,
	const QString &pass,
	const QString &port)
{
	// 1. 判断文件是否存在，不存在，就创建，写入参数值
	std::ofstream ofile(file.toStdString(), std::ios_base::out);
	if (ofile.is_open())
	{
		ofile << "DATABASE_TYPE" << " " << type.toStdString() << std::endl;
		ofile << "DATABASE_HOST" << " " << host.toStdString() << std::endl;
		ofile << "DATABASE_NAME" << " " << name.toStdString() << std::endl;
		ofile << "DATABASE_USER" << " " << user.toStdString() << std::endl;
		ofile << "DATABASE_PASS" << " " << pass.toStdString() << std::endl;
		ofile << "DATABASE_PORT" << " " << port.toStdString() << std::endl;

		ofile.close();
		return true;
	}

	return false;
}
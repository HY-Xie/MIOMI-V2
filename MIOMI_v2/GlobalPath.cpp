#include "GlobalPath.h"
#include <QDir>
#include <fstream>
#include <iostream>
#include <string>
#include <ios>
QString STORE_HOST = "//127.0.0.1";
//QString LOCAL_SETTING_HOST = QDir::homePath();		


bool saveStoreHost(const QString &fileName)
{
	std::ofstream ofile(fileName.toStdString(), std::ios_base::out);
	if (ofile.is_open())
	{
		ofile << STORE_HOST.toStdString() << std::endl;
		ofile.close();
		return true;
	}
	return false;
}

bool loadStoreHost(const QString &fileName)
{
	std::ifstream ifile(fileName.toStdString(), std::ios_base::in);
	if (ifile.is_open())
	{
		std::string line;
		getline(ifile, line);
		STORE_HOST = QString::fromStdString(line);
		ifile.close();
		return true;
	}
	return false;
}
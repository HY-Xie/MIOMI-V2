#include "RunningMode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ios>

bool LAN = false;


void setRunningMode(const QString &fileName, bool status)
{
	std::ofstream ofile(fileName.toStdString(), std::ios_base::out);
	if (ofile.is_open())
	{
		if (status == false)
		{
			ofile << "0" << std::endl;
		}
			
		else
			ofile << "1" << std::endl;

		ofile.close();
	}
}

void loadRunningMode(const QString &fileName)
{
	std::ifstream ifile(fileName.toStdString(), std::ios_base::in);
	if (ifile.is_open())
	{
		std::string line;
		getline(ifile, line);
		if (line == "1")
			LAN = true;
		else if (line == "0")
			LAN = false;

		ifile.close();
	}
}
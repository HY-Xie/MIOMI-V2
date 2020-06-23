#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <qdir.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QApplication::addLibraryPath("./plugins");
	/*QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath()) + QDir::separator() +

		"plugins");

	a.addLibraryPath(strLibPath);*/
	MainWindow w;
	//w.show();
	w.showMaximized();
	return a.exec();
}

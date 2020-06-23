#pragma once
#include <QString>
#include <string>
extern QString STORE_HOST;		// 是否使用该变量，在程序中使用LAN判定


bool saveStoreHost(const QString &fileName);
bool loadStoreHost(const QString &fileName);

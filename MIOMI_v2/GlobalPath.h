#pragma once
#include <QString>
#include <string>
extern QString STORE_HOST;		// �Ƿ�ʹ�øñ������ڳ�����ʹ��LAN�ж�


bool saveStoreHost(const QString &fileName);
bool loadStoreHost(const QString &fileName);

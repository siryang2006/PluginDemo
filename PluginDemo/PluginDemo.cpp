// PluginDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PluginManager.h"
#include <PluginInstance.h>
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int error = 0;
	PluginInstance *pPluginCollectorOrigin = PluginManager::GetInstance().Load("PluginCollectorOrigin", error);
	PluginInstance *pPluginSaveEnd = PluginManager::GetInstance().Load("PluginSaveEnd", error);
	PluginInstance *pPluginScanEnd = PluginManager::GetInstance().Load("PluginScanEnd", error);
	pPluginCollectorOrigin->connectNextPlugin(pPluginSaveEnd);
	pPluginCollectorOrigin->connectNextPlugin(pPluginScanEnd);

	PluginManager::GetInstance().RunALL();
	system("pause");
	return 0;
}
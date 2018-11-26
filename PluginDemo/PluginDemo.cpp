// PluginDemo.cpp : 定义控制台应用程序的入口点。
//

#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif
#include "PluginManager.h"
#include <PluginInstance.h>


int main(int argc, char* argv[])
{
	int error = 0;
	PluginInstance *pPluginCollectorOrigin = PluginManager::GetInstance().Load("PluginCollectorOrigin", error);
	PluginInstance *pPluginSaveEnd = PluginManager::GetInstance().Load("PluginSaveEnd", error);
	PluginInstance *pPluginScanEnd = PluginManager::GetInstance().Load("PluginScanEnd", error);
	pPluginCollectorOrigin->connectNextPlugin(pPluginSaveEnd);
	pPluginCollectorOrigin->connectNextPlugin(pPluginScanEnd);

	PluginManager::GetInstance().RunALL();
#ifdef _WIN32
	system("pause");
#endif
	return 0;
}

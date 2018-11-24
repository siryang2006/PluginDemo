// PluginScanEnd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"


#include "ScanPluginInstance.h"

int CreatePlugin(PluginInstance **pPluginInstance)
{
	*pPluginInstance = new ScanPluginInstance();
	if (*pPluginInstance == NULL)
	{
		return -1;
	}

	return 0;
}
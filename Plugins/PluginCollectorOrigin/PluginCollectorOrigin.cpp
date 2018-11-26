// PluginCollectorOrigin.cpp : 定义 DLL 应用程序的导出函数。
#include "CollectorPluginInstance.h"

int CreatePlugin(PluginInstance **pPluginInstance)
{
	*pPluginInstance = new CollectorPluginInstance();
	if (*pPluginInstance == NULL)
	{
		return -1;
	}

	return 0;
}

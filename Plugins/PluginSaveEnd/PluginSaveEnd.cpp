// PluginSaveEnd.cpp : 定义 DLL 应用程序的导出函数。
//

//#include "stdafx.h"

#include "SaveToEsPluginInstance.h"

int CreatePlugin(PluginInstance **pPluginInstance)
{
	*pPluginInstance = new SaveToEsPluginInstance();
	if (*pPluginInstance == NULL)
	{
		return -1;
	}

	return 0;
}

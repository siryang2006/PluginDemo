// PluginCollectorOrigin.cpp : ���� DLL Ӧ�ó���ĵ���������
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

// PluginSaveEnd.cpp : ���� DLL Ӧ�ó���ĵ���������
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

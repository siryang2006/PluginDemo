// PluginScanEnd.cpp : ���� DLL Ӧ�ó���ĵ���������
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
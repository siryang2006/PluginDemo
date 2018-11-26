//#include "stdafx.h"
#include <string.h>
#include "SaveToEsPluginInstance.h"


SaveToEsPluginInstance::SaveToEsPluginInstance()
{
}

int SaveToEsPluginInstance::input(void *data, int len)
{
	char data1[1000] = { 0 };
	sprintf(data1, "%s_SaveToEsPluginInstance::input", (char*)data);
	return this->output(data1, strlen(data1));
}

SaveToEsPluginInstance::~SaveToEsPluginInstance()
{
}

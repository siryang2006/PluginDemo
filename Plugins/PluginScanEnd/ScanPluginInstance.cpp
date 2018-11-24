#include "stdafx.h"
#include "ScanPluginInstance.h"


ScanPluginInstance::ScanPluginInstance()
{
}

int ScanPluginInstance::input(void *data, int len)
{
	char data1[1000] = { 0 };
	sprintf(data1, "%s_ScanPluginInstance::input", (char*)data);
	return this->output(data1, strlen(data1));
}

ScanPluginInstance::~ScanPluginInstance()
{
}

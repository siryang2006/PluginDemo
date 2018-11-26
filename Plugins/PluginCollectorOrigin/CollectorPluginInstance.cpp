#ifdef _WIN32
#include "stdafx.h"
#endif
#include <string.h>
#include "CollectorPluginInstance.h"



CollectorPluginInstance::CollectorPluginInstance()
	:PluginInstance()
{
}

int CollectorPluginInstance::run()
{
	for (int i = 0; i < 10; i++)
	{
		char data[100] = {0};
		sprintf(data, "%d_CollectorPluginInstance::run", i);
		this->input(data, strlen(data)+1);
	}
	return 0;
}

int CollectorPluginInstance::input(void *data, int len)
{
	char data1[100] = { 0 };
	sprintf(data1, "%s_CollectorPluginInstance::input", (char*)data);
	return this->output(data1, strlen(data1));
}

CollectorPluginInstance::~CollectorPluginInstance()
{
}

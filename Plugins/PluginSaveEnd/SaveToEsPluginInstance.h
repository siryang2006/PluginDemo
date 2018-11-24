#pragma once
#include <PluginInstance.h>
class SaveToEsPluginInstance :
	public PluginInstance
{
public:
	SaveToEsPluginInstance();
	~SaveToEsPluginInstance();

	virtual int input(void *data, int len);
};


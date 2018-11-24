#pragma once
#include <PluginInstance.h>
class CollectorPluginInstance :
	public PluginInstance
{
public:
	CollectorPluginInstance();
	~CollectorPluginInstance();

	virtual bool Load() { return true; }
	virtual bool UnLoad() { return true; }

	virtual int run();
	virtual int input(void *data, int len);
	//virtual int output(void *data, int len);
};


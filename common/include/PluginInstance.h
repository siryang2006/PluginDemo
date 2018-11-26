#ifndef PLUGININSTANCE_INCLUDE
#define PLUGININSTANCE_INCLUDE

#include <stdio.h>
#include <string>
#include <vector>
#include <assert.h>
#include "Export.h"
#include <DynamicLib.h>

class /*PLUGINCORE_API*/ PluginInstance
{
public:
	explicit PluginInstance() 
		: m_pDynamicLib(NULL){}

	virtual ~PluginInstance(){ m_pDynamicLib = NULL; }

	virtual int run()
	{
		return 0;
	}

	virtual int input(void *data, int len)
	{
		return output(data, len);
	}

	int output(void *data, int len)
	{
		printf("[%s_output]\n\n", (char*)data);
		for (int i = 0; i < (int)m_nextPluginVector.size(); i++)
		{
			PluginInstance *pPluginInstance = m_nextPluginVector[i];
			if (pPluginInstance != NULL) 
			{
				pPluginInstance->input(data, len);
			}
		}
		return 0;
	}

	bool connectNextPlugin(PluginInstance *pPluginInstance)
	{
		assert(pPluginInstance);
		m_nextPluginVector.push_back(pPluginInstance);
		return 0;
	}

	void SetDynamicLib(DynamicLib *pDynamicLib)
	{
		assert(pDynamicLib != NULL);
		m_pDynamicLib = pDynamicLib;
	}

	DynamicLib *GetDynamicLib()
	{
		return m_pDynamicLib;
	}

private:
	PluginInstance(const PluginInstance &rhs);
	const PluginInstance &operator=(const PluginInstance &rhs);

private:
	DynamicLib *m_pDynamicLib;
	std::vector<PluginInstance*> m_nextPluginVector;
};

//插件加载和卸载时调用的函数
typedef int(*CREATE_PLUGIN_FUN)(PluginInstance **);
#endif




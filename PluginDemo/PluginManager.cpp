#include "PluginManager.h"
#include "DynamicLib.h"
#include "PluginInstance.h"

PluginManager::PluginManager()
{
}

PluginManager &PluginManager::GetInstance()
{
	static PluginManager inst;
	return inst;
}

int PluginManager::RunALL()
{
	std::map<std::string, PluginInstance *>::iterator iter = m_mapPlugins.begin();
	while (iter != m_mapPlugins.end())
	{
		PluginInstance *pPluginInstance = iter->second;
		assert(pPluginInstance != NULL);
		pPluginInstance->run();
		iter++;
	}
	return 0;
}

PluginInstance* PluginManager::Load(const std::string &strName, int &errCode)
{
	std::map<std::string, PluginInstance *>::iterator iter = m_mapPlugins.find(strName);
	if (iter == m_mapPlugins.end())	//不存在就需要插入
	{
		DynamicLib* pLib = new DynamicLib;
		if (pLib != NULL)
		{
			if (!pLib->LoadLib(strName.c_str()))
			{
				errCode = -1;
				delete pLib;
				pLib = NULL;
				return NULL;
			}

			CREATE_PLUGIN_FUN pFun = (CREATE_PLUGIN_FUN)pLib->GetSymbolAddress("CreatePlugin");
			if (pFun != NULL)
			{
				PluginInstance* pPlugin = NULL;
				int ret = pFun(&pPlugin);
				if (ret == 0){
					pPlugin->SetDynamicLib(pLib);
					m_mapPlugins.insert(make_pair(strName, pPlugin));
					errCode = 0;
				}
				else {
					errCode = -1;
				}

				return pPlugin;
			}

			errCode = -1;
			return NULL;
		}
	}

	else		//如果存在，在插件列表里面寻找名字是strName的插件
	{
		PluginInstance* pPlugin = iter->second;
		if (pPlugin == NULL)
		{
			errCode = -1;
		}
		return pPlugin;
	}

	errCode = -1;
	return NULL;

}

bool PluginManager::UnLoad(const std::string &strName)
{
	std::map<std::string, PluginInstance *>::iterator iter = m_mapPlugins.find(strName);
	if (iter != m_mapPlugins.end())
	{
		PluginInstance *pPluginInstance = iter->second;
		assert(pPluginInstance != NULL);
		DynamicLib *pLib = pPluginInstance->GetDynamicLib();
		assert(pLib != NULL);
		pLib->FreeLib();
		delete pLib;
		delete pPluginInstance;

		//然后从列表中删除
		m_mapPlugins.erase(iter);
		return true;
	}

	return false;
}

bool PluginManager::UnLoadAll()
{
	std::map<std::string, PluginInstance *>::iterator iter = m_mapPlugins.begin();
	while (iter != m_mapPlugins.end())
	{
		PluginInstance *pPluginInstance = iter->second;
		if (pPluginInstance != NULL) 
		{
			DynamicLib *pLib = pPluginInstance->GetDynamicLib();
			delete pPluginInstance;
			pPluginInstance = NULL;

			if (pLib != NULL)
			{
				pLib->FreeLib();
				delete pLib;
				pLib = NULL;
			}
			else
			{
				assert(false);
			}
		}
		else
		{
			assert(false);
		}

		//然后从列表中删除
		m_mapPlugins.erase(iter++);
	}
	return true;
}

PluginManager::~PluginManager()
{
	UnLoadAll();
}

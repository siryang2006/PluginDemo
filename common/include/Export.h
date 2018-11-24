#ifdef PLUGINCORE_EXPORTS		
#ifdef __GNUC__
#define PLUGINCORE_API __attribute__((dllexport))
#else
#define PLUGINCORE_API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define PLUGINCORE_API __attribute__((dllimport))
#else
#define PLUGINCORE_API __declspec(dllimport)
#endif
#endif

class PluginInstance;
extern "C" PLUGINCORE_API int CreatePlugin(PluginInstance **pPluginInstance);
/*extern "C" PLUGINCORE_API int input(void *data, int len);
extern "C" PLUGINCORE_API int output(void *data, int len);
extern "C" PLUGINCORE_API bool connectNextPlugin(PluginInstance *pPluginInstance);
extern "C" PLUGINCORE_API bool run();*/

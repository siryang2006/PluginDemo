#include <PluginInstance.h>
class ScanPluginInstance :
	public PluginInstance
{
public:
	ScanPluginInstance();
	~ScanPluginInstance();

	virtual int input(void *data, int len);
};


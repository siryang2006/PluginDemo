CC=gcc
CFLAGS=-g -Wall -O2 -lstdc++
LDFLAGS=-L/usr/lib/
LIBS=-L/usr/lib/ -ldl
INCLUDES= -I./common/include
all:PluginDemo PluginCollectorOrigin PluginSaveEnd PluginScanEnd

PluginDemo: DynamicLib.o PluginManager.o
	$(CC) -o ./bin/PluginDemo $(INCLUDES) $(CFLAGS) ./bin/DynamicLib.o ./bin/PluginManager.o ./PluginDemo/PluginDemo.cpp $(LIBS)

DynamicLib.o: ./PluginDemo/DynamicLib.h
	$(CC) -o ./bin/DynamicLib.o $(CFLAGS) $(INCLUDES) -c ./PluginDemo/DynamicLib.cpp

PluginManager.o: ./PluginDemo/PluginManager.h
	$(CC) -o ./bin/PluginManager.o $(CFLAGS) $(INCLUDES) -c ./PluginDemo/PluginManager.cpp


PluginCollectorOrigin: CollectorPluginInstance.o
	$(CC) $(INCLUDES) -fPIC -shared ./bin/CollectorPluginInstance.o $(INCLUDES) ./Plugins/PluginCollectorOrigin/PluginCollectorOrigin.cpp -o ./bin/PluginCollectorOrigin.so

CollectorPluginInstance.o: ./Plugins/PluginCollectorOrigin/CollectorPluginInstance.h
	$(CC) -o ./bin/CollectorPluginInstance.o $(INCLUDES) -c -fPIC -shared $(INCLUDES) ./Plugins/PluginCollectorOrigin/CollectorPluginInstance.cpp



PluginSaveEnd: SaveToEsPluginInstance.o
	$(CC) $(INCLUDES) -fPIC -shared ./bin/SaveToEsPluginInstance.o $(INCLUDES) ./Plugins/PluginSaveEnd/PluginSaveEnd.cpp -o ./bin/PluginSaveEnd.so

SaveToEsPluginInstance.o: ./Plugins/PluginSaveEnd/SaveToEsPluginInstance.h
	$(CC) -o ./bin/SaveToEsPluginInstance.o $(INCLUDES) -c -fPIC -shared  $(INCLUDES) ./Plugins/PluginSaveEnd/SaveToEsPluginInstance.cpp



PluginScanEnd: ScanPluginInstance.o
	$(CC) $(INCLUDES) -fPIC -shared $(INCLUDES) ./bin/ScanPluginInstance.o ./Plugins/PluginScanEnd/PluginScanEnd.cpp -o ./bin/PluginScanEnd.so

ScanPluginInstance.o: ./Plugins/PluginScanEnd/ScanPluginInstance.h
	$(CC) -o ./bin/ScanPluginInstance.o -fPIC -shared  $(INCLUDES) -c ./Plugins/PluginScanEnd/ScanPluginInstance.cpp

clean:
	rm  -f ./bin/*.o ./bin/PluginDemo ./bin/*.so

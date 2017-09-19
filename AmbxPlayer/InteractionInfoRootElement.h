#ifndef __InteractionInfoRootElement_h__
#define __InteractionInfoRootElement_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class InteractionInfoRootElement 
{
public:
	InteractionInfoRootElement();
	virtual ~InteractionInfoRootElement();
	void addDeviceCommand(DeviceCommandBaseType* command);
	TimeStampType* getTimeStamp();
	vector<DeviceCommandBaseType*>* getDeviceCommandList()
	{
		return this->deviceCommandList;
	}
private:
	static string xmlUTF;
	static string attribute;

	// Device Command Element List
	vector<DeviceCommandBaseType*>* deviceCommandList;

	// SensedInfo Element List

};


#endif
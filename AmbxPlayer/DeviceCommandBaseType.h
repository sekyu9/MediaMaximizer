#ifndef __DeviceCommandBaseType_h__
#define __DeviceCommandBaseType_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>

#include "TimeStampType.h"
#include "ParsingHelper.h"
#include "EffectBaseType.h"
#include "SensoryDeviceCapabilityBaseType.h"


using namespace std;

class DeviceCommandBaseType{
public:
	DeviceCommandBaseType();
	DeviceCommandBaseType(EffectBaseType*, SensoryDeviceCapabilityBaseType*);
	virtual ~DeviceCommandBaseType();



	/* getter & setter */
	void setTimeStamp(TimeStampType* timeStamp)
	{
		this->timeStamp = timeStamp;
	}

	TimeStampType* getTimeStamp() 
	{
		return this->timeStamp;
	}

	bool getIsID() 
	{
		return this->isID;
	}

	void setId(string id)
	{
		isID = true;
		this->id = id;
	}

	string getId() 
	{
		return this->id;
	}

	void setIsDeviceIdRef(bool isDeviceIdRef)
	{
		this->isDeviceIdRef = isDeviceIdRef;
	}

	bool getIsDeviceIdRef() 
	{
		return this->isDeviceIdRef;
	}

	void setDeviceIdRef(string deviceIdRef)
	{
		isDeviceIdRef = true;
		this->deviceIdRef = deviceIdRef;
	}

	string getDeviceIdRef() 
	{
		return this->deviceIdRef;
	}

	void setIsActivate(bool isActivate)
	{
		this->isActivate = isActivate;
	}

	bool getIsActivate() 
	{
		return this->isActivate;
	}

	void setActivate(bool activate)
	{
		isActivate = true;
		this->activate = activate;
	}

	bool getActivate() 
	{
		return this->activate;
	}


	void setDuration(int duration)
	{
		this->duration = duration;
	}

	const string getTypeName() const
	{
		return typeName;
	}

	const char* getParam2() const;
	const char* getParam3() const;

protected:
	// time stamp element
	TimeStampType* timeStamp;

	// attributes
	string typeName;

	bool isID;
	string id;

	bool isDeviceIdRef;
	string deviceIdRef;

	bool isActivate;
	bool activate;

	int duration;

	char* packetBuffer;

};
#endif
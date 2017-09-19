#ifndef __CoolingCommandType_h__
#define __CoolingCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class CoolingCommandType : public DeviceCommandBaseType
{
public:
	CoolingCommandType();
	CoolingCommandType(EffectBaseType*,  SensoryDeviceCapabilityBaseType*);
	virtual ~CoolingCommandType();


	/* getter & setter */
	bool getIsIntensity()
	{
		return this->isIntensity;
	}

	void setIsIntensity(bool isIntensity)
	{
		this->isIntensity = isIntensity;
	}

	long getIntensity()
	{
		return intensity;
	}

	void setIntensity(long intensity)
	{
		this->isIntensity = true;
		this->intensity = intensity;
	}
protected:
	bool isIntensity;
	long intensity;

};

#endif
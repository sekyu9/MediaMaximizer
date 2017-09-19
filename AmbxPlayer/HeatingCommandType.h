#ifndef __HeatingCommandType_h__
#define __HeatingCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class HeatingCommandType : public DeviceCommandBaseType
{
public:
	HeatingCommandType();
	HeatingCommandType(EffectBaseType*, SensoryDeviceCapabilityBaseType*);
	virtual ~HeatingCommandType();



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
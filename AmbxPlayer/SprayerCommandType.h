#ifndef __SprayerCommandType_h__
#define __SprayerCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class SprayerCommandType : public DeviceCommandBaseType
{
public:
	SprayerCommandType();
	SprayerCommandType(EffectBaseType*, SensoryDeviceCapabilityBaseType*);
	virtual ~SprayerCommandType();


	/* getter & setter */
	bool getIsSprayingType()
	{
		return this->isSprayingType;
	}

	void setIsSprayingType(bool isSprayingType)
	{
		this->isSprayingType = isSprayingType;
	}

	string getSprayingType()
	{
		return this->sprayingType;
	}

	void setSprayingType(string sprayingType)
	{
		this->isSprayingType = true;
		this->sprayingType = sprayingType;
	}

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
	bool isSprayingType;
	string sprayingType;

	bool isIntensity;
	long intensity;

};

#endif
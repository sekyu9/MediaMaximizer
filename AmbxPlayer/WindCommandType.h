#ifndef __WindCommandType_h__
#define __WindCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class WindCommandType : public DeviceCommandBaseType
{
public:
	WindCommandType();
	WindCommandType(EffectBaseType*, SensoryDeviceCapabilityBaseType*);
	virtual ~WindCommandType();



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
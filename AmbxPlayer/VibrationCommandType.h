#ifndef __VibrationCommandType_h__
#define __VibrationCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class VibrationCommandType : public DeviceCommandBaseType
{
public:
	VibrationCommandType();
	VibrationCommandType(EffectBaseType*,  SensoryDeviceCapabilityBaseType*);
	virtual ~VibrationCommandType();


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
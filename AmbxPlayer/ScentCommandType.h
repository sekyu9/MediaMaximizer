#ifndef __ScentCommandType_h__
#define __ScentCommandType_h__

#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ScentCommandType : public DeviceCommandBaseType
{
public:
	ScentCommandType();
	ScentCommandType(EffectBaseType*,  SensoryDeviceCapabilityBaseType*);
	virtual ~ScentCommandType();



	/* getter & setter */
	bool getIsScent()
	{
		return this->isScent;
	}

	void setIsScent(bool scent)
	{
		this->scent = scent;
	}

	string getScent()
	{
		return this->scent;
	}

	void setScent(string scent)
	{
		this->isScent = true;
		this->scent = scent;
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
	bool isScent;
	string scent;

	bool isIntensity;
	long intensity;

};

#endif
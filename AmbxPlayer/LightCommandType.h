#ifndef __LightCommandType_h__
#define __LightCommandType_h__


#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include "ColorType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class LightCommandType : public DeviceCommandBaseType
{
public:
	LightCommandType();
	LightCommandType(EffectBaseType*, SensoryDeviceCapabilityBaseType*);
	virtual ~LightCommandType();

	/* getter & setter */
	bool getIsColor()
	{
		return this->isColor;
	}

	void setIsColor(bool isColor) 
	{
		this->isColor = isColor;
	}

	ColorType& getColor()
	{
		return color;
	}

	void setColor(ColorType color) 
	{
		isColor = true;
		this->color = color;
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
		isIntensity = true;
		this->intensity = intensity;
	}
	
protected:
	ColorType color;
	bool isColor;

	bool isIntensity;
	long intensity;
};


#endif
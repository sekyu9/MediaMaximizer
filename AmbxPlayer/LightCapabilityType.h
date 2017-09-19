#ifndef __LightCapabilityType_h__
#define __LightCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"
#include "ColorType.h"

#include <vector>
#include <iostream>

using namespace std;

class LightCapabilityType : public SensoryDeviceCapabilityBaseType{
public:
	LightCapabilityType(ElementBaseType* e);
	virtual ~LightCapabilityType() {};
	void mappingData();

	vector<ColorType>* getColorElementList() const
	{
		return colorElementList;
	}

	void setColorElementList(vector<ColorType>* colorElementList)
	{
		this->colorElementList = colorElementList;
	}

	bool isIsColorElementList() const
	{
		return isColorElementList;
	}

	void setIsColorElementList(bool isColorElementList)
	{
		this->isColorElementList = isColorElementList;
	}

	bool isIsMaxIntensity() const
	{
		return isMaxIntensity;
	}

	void setIsMaxIntensity(bool isMaxIntensity)
	{
		this->isMaxIntensity = isMaxIntensity;
	}

	bool isIsNumOfLightLevels() const
	{
		return isNumOfLightLevels;
	}

	void setIsNumOfLightLevels(bool isNumOfLightLevels)
	{
		this->isNumOfLightLevels = isNumOfLightLevels;
	}

	bool isIsUnit() const
	{
		return isUnit;
	}

	void setIsUnit(bool isUnit)
	{
		this->isUnit = isUnit;
	}

	int getMaxIntensity() const
	{
		return maxIntensity;
	}

	void setMaxIntensity(int maxIntensity)
	{
		this->maxIntensity = maxIntensity;
	}

	int getNumOfLightLevels() const
	{
		return numOfLightLevels;
	}

	void setNumOfLightLevels(int numOfLightLevels)
	{
		this->numOfLightLevels = numOfLightLevels;
	}

	string getUnit() const
	{
		return unit;
	}

	void setUnit(string unit)
	{
		this->unit = unit;
	}
private:
	// Color Element sequence
	bool isColorElementList;
	vector<ColorType>* colorElementList;
	// attribute
	bool isUnit;
	string unit;
	bool isMaxIntensity;
	int maxIntensity;
	bool isNumOfLightLevels;
	int numOfLightLevels;

};
#endif
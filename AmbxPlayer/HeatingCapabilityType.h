#ifndef __HeatingCapabilityType_h__
#define __HeatingCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class HeatingCapabilityType : public SensoryDeviceCapabilityBaseType{
public:
	HeatingCapabilityType(ElementBaseType* e);
	virtual ~HeatingCapabilityType() {};
	void mappingData();

	bool isIsMaxIntensity() const
	{
		return isMaxIntensity;
	}

	void setIsMaxIntensity(bool isMaxIntensity)
	{
		this->isMaxIntensity = isMaxIntensity;
	}

	bool isIsMinIntensity() const
	{
		return isMinIntensity;
	}

	void setIsMinIntensity(bool isMinIntensity)
	{
		this->isMinIntensity = isMinIntensity;
	}

	bool isIsNumOfLevels() const
	{
		return isNumOfLevels;
	}

	void setIsNumOfLevels(bool isNumOfLevels)
	{
		this->isNumOfLevels = isNumOfLevels;
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

	int getMinIntensity() const
	{
		return minIntensity;
	}

	void setMinIntensity(int minIntensity)
	{
		this->minIntensity = minIntensity;
	}

	int getNumOfLevels() const
	{
		return numOfLevels;
	}

	void setNumOfLevels(int numOfLevels)
	{
		this->numOfLevels = numOfLevels;
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
	// attribute
	bool isMaxIntensity;
	int maxIntensity;
	bool isMinIntensity;
	int minIntensity;
	bool isUnit;
	string unit;
	bool isNumOfLevels;
	int numOfLevels;
};

#endif
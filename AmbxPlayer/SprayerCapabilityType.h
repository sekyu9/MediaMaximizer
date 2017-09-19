#ifndef __SprayerCapabilityType_h__
#define __SprayerCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class SprayerCapabilityType : public SensoryDeviceCapabilityBaseType
{
public:
	SprayerCapabilityType(ElementBaseType* e);
	virtual ~SprayerCapabilityType() {};
	void mappingData();

	bool isIsMaxIntensity() const
	{
		return isMaxIntensity;
	}

	void setIsMaxIntensity(bool isMaxIntensity)
	{
		this->isMaxIntensity = isMaxIntensity;
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

	int getNumOfLevels() const
	{
		return numOfLevels;
	}

	void setNumOfLevels(int numOfLevels)
	{
		this->numOfLevels = numOfLevels;
	}

	bool isIsSprayingType() const
	{
		return isSprayingType;
	}

	void setIsSprayingType(bool isSprayingType)
	{
		this->isSprayingType = isSprayingType;
	}

	string getSprayingType() const
	{
		return sprayingType;
	}

	void setSprayingType(string sprayingType)
	{
		this->sprayingType = sprayingType;
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
	bool isSprayingType;
	string sprayingType;
	bool isMaxIntensity;
	int maxIntensity;
	bool isUnit;
	string unit;
	bool isNumOfLevels;
	int numOfLevels;
};

#endif
#ifndef __FogCapabilityType_h__
#define __FogCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class FogCapabilityType : public SensoryDeviceCapabilityBaseType{
public:
	FogCapabilityType(ElementBaseType* e);
	virtual ~FogCapabilityType() {};
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
	bool isUnit;
	string unit;
	bool isNumOfLevels;
	int numOfLevels;
};

#endif
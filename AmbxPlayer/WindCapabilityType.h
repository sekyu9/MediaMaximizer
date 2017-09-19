#ifndef __WindCapabilityType_h__
#define WindCapabilytyType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class WindCapabilityType : public SensoryDeviceCapabilityBaseType
{
public:
	WindCapabilityType(ElementBaseType* e);
	virtual ~WindCapabilityType() {};
	void mappingData();

	bool isIsMaxWindSpeed() const
	{
		return isMaxWindSpeed;
	}

	void setIsMaxWindSpeed(bool isMaxWindSpeed)
	{
		this->isMaxWindSpeed = isMaxWindSpeed;
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

	int getMaxWindSpeed() const
	{
		return maxWindSpeed;
	}

	void setMaxWindSpeed(int maxWindSpeed)
	{
		this->maxWindSpeed = maxWindSpeed;
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
	bool isMaxWindSpeed;
	int maxWindSpeed;
	bool isUnit;
	string unit;
	bool isNumOfLevels;
	int numOfLevels;
};

#endif
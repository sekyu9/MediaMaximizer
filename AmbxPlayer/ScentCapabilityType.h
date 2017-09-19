#ifndef __ScentCapabilityType_h__
#define __ScentCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class ScentCapabilityType : public SensoryDeviceCapabilityBaseType
{
public:
	ScentCapabilityType(ElementBaseType* e);
	virtual ~ScentCapabilityType() {};
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

	bool isIsScentElementList() const
	{
		return isScentElementList;
	}

	void setIsScentElementList(bool isScentElementList)
	{
		this->isScentElementList = isScentElementList;
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

	vector<string>* getScentElementList() const
	{
		return scentElementList;
	}

	void setScentElementList(vector<string>* scentElementList)
	{
		this->scentElementList = scentElementList;
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
	bool isScentElementList;
	vector<string>* scentElementList;
	// attribute
	bool isMaxIntensity;
	int maxIntensity;
	bool isUnit;
	string unit;
	bool isNumOfLevels;
	int numOfLevels;
};

#endif


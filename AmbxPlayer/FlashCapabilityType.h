#ifndef __FlashCapabilityType_h__
#define __FlashCapabilityType_h__

#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"
#include "LightCapabilityType.h"
#include <vector>
#include <iostream>

using namespace std;

class FlashCapabilityType : public LightCapabilityType{
public:
		FlashCapabilityType(ElementBaseType* e);
	virtual ~FlashCapabilityType() {};
	void mappingData();

	bool isIsMaxFrequency() const
	{
		return isMaxFrequency;
	}

	void setIsMaxFrequency(bool isMaxFrequency)
	{
		this->isMaxFrequency = isMaxFrequency;
	}

	bool isIsNumOfFreqLevels() const
	{
		return isNumOfFreqLevels;
	}

	void setIsNumOfFreqLevels(bool isNumOfFreqLevels)
	{
		this->isNumOfFreqLevels = isNumOfFreqLevels;
	}

	int getMaxFrequency() const
	{
		return maxFrequency;
	}

	void setMaxFrequency(int maxFrequency)
	{
		this->maxFrequency = maxFrequency;
	}

	int getNumOfFreqLevels() const
	{
		return numOfFreqLevels;
	}

	void setNumOfFreqLevels(int numOfFreqLevels)
	{
		this->numOfFreqLevels = numOfFreqLevels;
	}

private:
	// attribute
	bool isMaxFrequency;
	int maxFrequency;
	bool isNumOfFreqLevels;
	int numOfFreqLevels;
};

#endif
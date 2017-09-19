#ifndef __FlashCommandType_h__
#define __FlashCommandType_h__

#include "stdafx.h"
#include "LightCommandType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class FlashCommandType : public LightCommandType
{
public:
	FlashCommandType();
	FlashCommandType(EffectBaseType*,  SensoryDeviceCapabilityBaseType*);
	virtual ~FlashCommandType();

	/* getter & setter */
	bool getIsFrequency()
	{
		return this->isFrequency;
	}

	void setIsFrequency(bool isFrequency)
	{
		this->isFrequency = isFrequency;
	}

	long getFrequency()
	{
		return this->frequency;
	}

	void setFrequency(long frequency)
	{
		isFrequency = true;
		this->frequency = frequency;
	}
private:
	bool isFrequency;
	long frequency;

};

#endif
#ifndef __FlashType_h__
#define __FlashType_h__

#include "stdafx.h"
#include "EffectBaseType.h"
#include "LightType.h"

class FlashType: public LightType{
public:
	FlashType(ElementBaseType* e);
	virtual ~FlashType();
	//override method
	void mappingData();

	    int getFrequency() const
    {
        return frequency;
    }

    void setFrequency(int frequency)
    {
        this->frequency = frequency;
    }

    bool isIsFrequency() const
    {
        return isFrequency;
    }

    void setIsFrequency(bool isFrequency)
    {
        this->isFrequency = isFrequency;
    }

private:
    bool isFrequency;
    int frequency;
};

#endif
#ifndef __LightType_h__
#define __LightType_h__

#include "stdafx.h"
#include "EffectBaseType.h"
#include "ColorType.h"

class LightType: public EffectBaseType{
public:
	//constructor
	LightType(ElementBaseType* e);
	virtual ~LightType();

	void mappingData();
	//getter & setter
ColorType getColor() const
    {
        return color;
    }

    void setColor(ColorType color)
    {
        this->color = color;
    }

    vector<float>* getIntensityRange() const
    {
        return intensity_range;
    }

    void setIntensityRange(vector<float>* intensityRange)
    {
        intensity_range = intensityRange;
    }

    float getIntensityValue() const
    {
        return intensity_value;
    }

    void setIntensityValue(float intensityValue)
    {
        intensity_value = intensityValue;
    }

    bool isIsColor() const
    {
        return isColor;
    }

    void setIsColor(bool isColor)
    {
        this->isColor = isColor;
    }

    bool isIsIntensityRange() const
    {
        return isIntensity_range;
    }

    void setIsIntensityRange(bool isIntensityRange)
    {
        isIntensity_range = isIntensityRange;
    }

    bool isIsIntensityValue() const
    {
        return isIntensity_value;
    }

    void setIsIntensityValue(bool isIntensityValue)
    {
        isIntensity_value = isIntensityValue;
    }
protected:
	ColorType color;
    bool isColor;
	float intensity_value;
	bool isIntensity_value;
	vector<float>* intensity_range;
	bool isIntensity_range;
};

#endif

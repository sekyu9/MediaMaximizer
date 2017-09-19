#ifndef __TemperatureType_h__
#define __TemperatureType_h__

#include "stdafx.h"
#include "EffectBaseType.h"

class TemperatureType : public EffectBaseType{
public:
	/** constructor **/
	TemperatureType(ElementBaseType* e);
	virtual ~TemperatureType();
	/** override method **/
	void mappingData();

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
	bool isIntensity_value;
	float intensity_value;
	
	bool isIntensity_range;
	vector<float>* intensity_range;
};


#endif
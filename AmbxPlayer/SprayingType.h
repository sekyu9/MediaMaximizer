#ifndef __SprayingType_h__
#define __SprayingType_h__

#include "stdafx.h"
#include "EffectBaseType.h"

class SprayingType : public EffectBaseType{
public:
	/** constructor **/
	SprayingType(ElementBaseType* e);
	virtual ~SprayingType();
	
	/** override method **/
	void mappingData();

	vector<float>* getIntensityRange() const {
		return intensity_range;
	}

	void setIntensityRange(vector<float>* intensityRange) {
		intensity_range = intensityRange;
	}

	float getIntensityValue() const {
		return intensity_value;
	}


	void setIntensityValue(float intensityValue) {
		intensity_value = intensityValue;
	}

	bool isIsIntensityRange() const {
		return isIntensity_range;
	}

	void setIsIntensityRange(bool isIntensityRange) {
		isIntensity_range = isIntensityRange;
	}

	bool isIsIntensityValue() const {
		return isIntensity_value;
	}

	void setIsIntensityValue(bool isIntensityValue) {
		isIntensity_value = isIntensityValue;
	}

	bool isIsSprayingType() const {
		return isSprayingType;
	}

	void setIsSprayingType(bool isSprayingType) {
		isSprayingType = isSprayingType;
	}

	string getSprayingType() const {
		return sprayingType;
	}

	void setSprayingType(string sprayingType) {
		this->sprayingType = sprayingType;
	}

protected:
	bool isIntensity_value;
	float intensity_value;

	bool isIntensity_range;
	vector<float>* intensity_range;	

	bool isSprayingType;
	string sprayingType;
};

#endif
#include "stdafx.h"
#include "FogType.h"
#include <stdlib.h>
#include "ParsingHelper.h"

FogType::FogType(ElementBaseType* e) 
: EffectBaseType(e)
{
	this->isIntensity_range = false;
	this->isIntensity_value = false;
}

FogType::~FogType()
{
	delete this->intensity_range;
}

void FogType::mappingData()
{
	EffectBaseType::mappingData();
	
	AttributeMap* map = elementBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("intensity-value");
	if(mapI != map->end())
	{
		this->intensity_value = atof((mapI->second).c_str());
		this->isIntensity_value = true;
	}

	mapI = map->find("intensity-range");
	if(mapI != map->end())
	{
	    this->intensity_range = ParsingHelper::getIntensityValue(mapI->second);
	    vector<float>::iterator i;
	    this->isIntensity_range = true;
	}
}
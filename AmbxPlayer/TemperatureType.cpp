#include "stdafx.h"
#include "TemperatureType.h"
#include <stdlib.h>
#include "ParsingHelper.h"

TemperatureType::TemperatureType(ElementBaseType* e) 
: EffectBaseType(e)
{
	
}

TemperatureType::~TemperatureType()
{
	delete this->intensity_range;
}

void TemperatureType::mappingData()
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
	    this->isIntensity_range = true;
	}	
}
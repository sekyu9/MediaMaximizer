#include "stdafx.h"
#include "SprayingType.h"
#include <stdlib.h>
#include "ParsingHelper.h"

SprayingType::SprayingType(ElementBaseType* e) 
: EffectBaseType(e)
{
	
}

SprayingType::~SprayingType()
{
	delete this->intensity_range;
}

void SprayingType::mappingData()
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

	mapI = map->find("sprayingType");
	if(mapI != map->end())
	{
		this->sprayingType = mapI->second;
	}


}
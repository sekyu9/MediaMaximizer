#include "stdafx.h"
#include "VibrationType.h"
#include <stdlib.h>
#include "ParsingHelper.h"


VibrationType::VibrationType(ElementBaseType* e) 
: EffectBaseType(e)
{
	
}

VibrationType::~VibrationType()
{
	delete this->intensity_range;
}

void VibrationType::mappingData()
{
	EffectBaseType::mappingData();
	
	AttributeMap* map = elementBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("intensity-value");
	if(mapI != map->end())
	{
		this->intensity_value = atof((mapI->second).c_str());
		this->isIntensity_value;
	}

	mapI = map->find("intensity-range");
	if(mapI != map->end())
	{
	    this->intensity_range = ParsingHelper::getIntensityValue(mapI->second);
	    this->isIntensity_range;
	}
}
#include "stdafx.h"
#include "WindType.h"
#include <stdlib.h>
#include "ParsingHelper.h"


WindType::WindType(ElementBaseType* e) 
: EffectBaseType(e)
{
	this->isIntensity_value = false;
	this->isIntensity_range = false;
	this->intensity_range = NULL;
}

WindType::~WindType()
{
	delete this->intensity_range;
}

void WindType::mappingData()
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
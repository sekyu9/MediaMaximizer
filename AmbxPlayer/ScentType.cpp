#include "stdafx.h"
#include "ScentType.h"
#include <stdlib.h>
#include "ParsingHelper.h"

ScentType::ScentType(ElementBaseType* e) 
: EffectBaseType(e)
{
	
}

ScentType::~ScentType()
{
	delete this->intensity_range;
}

void ScentType::mappingData()
{
	EffectBaseType::mappingData();
	
	AttributeMap* map = elementBaseType->getAttributeMap();

	AttributeMap::iterator mapI = map->find("scent");
	if(mapI != map->end())
	{
		this->scent = ParsingHelper::removeNamespace(mapI->second);
		this->isScent = true;
	}

	mapI = map->find("intensity-value");
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
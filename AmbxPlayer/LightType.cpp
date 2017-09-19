#include "stdafx.h"
#include "LightType.h"
#include <stdlib.h>
#include "ParsingHelper.h"

LightType::LightType(ElementBaseType* e) 
: EffectBaseType(e)
{
	isIntensity_range = false;
	isIntensity_value = false;
	//isColor = false;
	this->intensity_range = NULL;
}
LightType::~LightType()
{
	delete this->intensity_range;
}

void LightType::mappingData(){
	//call super::mappingData
	EffectBaseType::mappingData();
	//attrubute mapping
	AttributeMap* map = elementBaseType->getAttributeMap();

	AttributeMap::iterator mapI = map->find("color");
	if(mapI != map->end())
	{
		/* only color name type */
		color.setNamedColorType(ParsingHelper::removeNamespace(mapI->second));
		color.setNameColorFlag(true);

		isColor = true;
	}

	mapI = map->find("intensity-value");
	if(mapI != map->end())
	{
		this->intensity_value = atof((mapI->second).c_str());
		isIntensity_value = true;
	}

	mapI = map->find("intensity-range");  
	if(mapI != map->end())
	{
	    this->intensity_range = ParsingHelper::getIntensityValue(mapI->second);
	    isIntensity_range = true;
	}
} 
#include "stdafx.h"
#include "FlashType.h"
#include "LightType.h"
#include <stdlib.h>

FlashType::FlashType(ElementBaseType* e) 
: LightType(e)
{
	this->isFrequency = false;
}

FlashType::~FlashType()
{
	
}

void FlashType::mappingData()  
{
	/** call super::mappingData **/
	LightType::mappingData();

	/** Attribute mapping **/
	AttributeMap* map = elementBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("frequency");
	if(mapI != map->end())
	{
		this->frequency = atoi((mapI->second).c_str());
		this->isFrequency = true;
	}
}
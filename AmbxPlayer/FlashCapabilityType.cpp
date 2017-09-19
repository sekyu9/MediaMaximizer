#include "stdafx.h"
#include "FlashCapabilityType.h"
#include <string>
#include <stdlib.h>

using namespace std;

FlashCapabilityType::FlashCapabilityType(ElementBaseType* e) 
: LightCapabilityType(e)
{
}

void FlashCapabilityType::mappingData()
{
	LightCapabilityType::mappingData();	
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("maxFrequency");
	if(mapI != map->end())
	{
		this->maxFrequency = atoi((mapI->second).c_str());
		this->isMaxFrequency = true;
	}

	mapI = map->find("numOfFreqLevels");
	if(mapI != map->end())
	{
		this->numOfFreqLevels = atoi((mapI->second).c_str());
		this->isNumOfFreqLevels = true;
	}
}
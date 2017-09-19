#include "stdafx.h"
#include "WindCapabilityType.h"
#include <string>
#include <stdlib.h>

using namespace std;

WindCapabilityType::WindCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
}

void WindCapabilityType::mappingData()
{
	SensoryDeviceCapabilityBaseType::mappingData();	
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("maxWindSpeed");
	if(mapI != map->end())
	{
		this->maxWindSpeed = atoi((mapI->second).c_str());
		this->isMaxWindSpeed = true;
	}

	mapI = map->find("unit");
	if(mapI != map->end())
	{
		this->unit = mapI->second;
		this->isUnit = true;
	}

	mapI = map->find("numOfLevels");
	if(mapI != map->end())
	{
		this->numOfLevels = atoi((mapI->second).c_str());
		this->isNumOfLevels = true;
	}
}
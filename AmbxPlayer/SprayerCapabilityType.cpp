#include "stdafx.h"
#include "SprayerCapabilityType.h"
#include <string>
#include <stdlib.h>

using namespace std;

SprayerCapabilityType::SprayerCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
	isSprayingType = false;
	isMaxIntensity = false;
	isUnit = false;
	isNumOfLevels = false;
}

void SprayerCapabilityType::mappingData()
{
	SensoryDeviceCapabilityBaseType::mappingData();	
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();

	AttributeMap::iterator mapI = map->find("sprayingType");
	if(mapI != map->end())
	{
		this->sprayingType = mapI->second;
		this->isSprayingType = true;
	}

	mapI = map->find("maxIntensity");
	if(mapI != map->end())
	{
		this->maxIntensity = atoi((mapI->second).c_str());
		this->isMaxIntensity= true;
	}

	mapI = map->find("unit");
	if(mapI != map->end())
	{
		this->unit = mapI->second;
		this->isUnit= true;
	}

	mapI = map->find("numOfLevels");
	if(mapI != map->end())
	{
		this->numOfLevels = atoi((mapI->second).c_str());
		this->isNumOfLevels= true;
	}
}
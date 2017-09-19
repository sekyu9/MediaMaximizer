#include "stdafx.h"
#include "HeatingCapabilityType.h"
#include <string>
#include <stdlib.h>

using namespace std;

HeatingCapabilityType::HeatingCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
}

void HeatingCapabilityType::mappingData()
{

	SensoryDeviceCapabilityBaseType::mappingData();	
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("maxIntensity");
	if(mapI != map->end())
	{
		this->maxIntensity = atoi((mapI->second).c_str());
		this->isMaxIntensity = true;
	}

	mapI = map->find("minIntensity");
	if(mapI != map->end())
	{
		this->minIntensity = atoi((mapI->second).c_str());
		this->isMinIntensity = true;
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

	cout << endl;
}
#include "stdafx.h"
#include "VibrationCapabilityType.h"
#include <string>
#include <stdlib.h>

using namespace std;

VibrationCapabilityType::VibrationCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
}

void VibrationCapabilityType::mappingData()
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
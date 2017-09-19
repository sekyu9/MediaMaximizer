#include "stdafx.h"
#include "SensoryDeviceCapabilityBaseType.h"

#include <string>
#include <stdlib.h>

using namespace std;

SensoryDeviceCapabilityBaseType::SensoryDeviceCapabilityBaseType(ElementBaseType* e){
	this->sensoryDeviceCapabilityBaseType = e;
}

void SensoryDeviceCapabilityBaseType::mappingData(){
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("id");
	if(mapI != map->end())
	{
		this->id = mapI->second;
		this->isId = true;
	}

	mapI = map->find("zerothOrderDelayTime");
	if(mapI != map->end())
	{
		this->zerothOrderDelayTime = atoi((mapI->second).c_str());
		this->isZerothOrderDelayTime = true;
	}

	mapI = map->find("firstOrderDelayTime");
	if(mapI != map->end())
	{
		this->firstOrderDelayTime = atoi((mapI->second).c_str());
		this->isFirstOrderDelayTime = true;
	}

	mapI = map->find("locator");
	if(mapI != map->end())
	{
		this->locator = mapI->second;
		this->isLocator = true;
	}
}
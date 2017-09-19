#include "stdafx.h"
#include "ScentCapabilityType.h"
#include "ParsingHelper.h"

#include <string>
#include <stdlib.h>

using namespace std;

ScentCapabilityType::ScentCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
	this->scentElementList = new vector<string>;
}

void ScentCapabilityType::mappingData()
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

	/** Element mapping **/
	vector<ElementBaseType*>* elementList = sensoryDeviceCapabilityBaseType->getChildList();
	vector<ElementBaseType*>::iterator i;
	for(i = elementList->begin(); 
        i != elementList->end(); 
        i++)
	{
		scentElementList->push_back(ParsingHelper::removeNamespace((*i)->getContent()));
		this->isScentElementList = true;
	}	
}
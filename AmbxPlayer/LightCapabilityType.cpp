#include "stdafx.h"
#include "LightCapabilityType.h"
#include "ParsingHelper.h"

#include <string>
#include <stdlib.h>

using namespace std;

LightCapabilityType::LightCapabilityType(ElementBaseType* e) 
: SensoryDeviceCapabilityBaseType(e)
{
	this->colorElementList = new vector<ColorType>;
}
void LightCapabilityType::mappingData()
{
	SensoryDeviceCapabilityBaseType::mappingData();	
	/** Attribute mapping **/
	AttributeMap* map = sensoryDeviceCapabilityBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("unit");
	if(mapI != map->end())
	{
		this->unit = mapI->second;
		this->isUnit = true;
	}

	mapI = map->find("maxIntensity");
	if(mapI != map->end())
	{
		this->maxIntensity = atoi((mapI->second).c_str());
		this->isMaxIntensity = true;
	}

	mapI = map->find("numOfLightLevels");
	if(mapI != map->end())
	{
		this->numOfLightLevels = atoi((mapI->second).c_str());
		this->isNumOfLightLevels = true;
	}

	cout << endl;

	/** Element mapping **/
	vector<ElementBaseType*>* elementList = sensoryDeviceCapabilityBaseType->getChildList();
	vector<ElementBaseType*>::iterator i;

	for(i = elementList->begin(); 
        i != elementList->end(); 
        i++)
	{
		ColorType color;

		color.setNamedColorType(ParsingHelper::removeNamespace((*i)->getContent()));
		colorElementList->push_back(color);
		this->isColorElementList = true;
	}
	cout<<endl;

}
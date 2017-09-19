#include "stdafx.h"
#include "EffectBaseType.h"
#include <string>
#include <stdlib.h>

using namespace std;

EffectBaseType::EffectBaseType(ElementBaseType* e) 
{
	this->elementBaseType = e;

	isSupplementalInformationList = false;
    supplementalInformationList = 0;
    isId = false;
    isAutoExtractionType = false;
    isActivate = false;
    isDuration = false;
    isFade = false;
    isAlt = false;
    isPriority = false;
    isLocation = false;
    isAdaptType = false;
    isAdaptRange = false;
    isPts = false;
    isTimeScale = false;
}

EffectBaseType::~EffectBaseType()
{
	for(int i = 0; i < supplementalInformationList->size(); i++)
	{
		ElementBaseType* e = supplementalInformationList->at(i);
		delete e;
	}
	delete supplementalInformationList;
}

void EffectBaseType::mappingData(){
	//Element mapping
	supplementalInformationList = elementBaseType->getChildList();

		/** Attribute mapping **/
	AttributeMap* map = elementBaseType->getAttributeMap();
	AttributeMap::iterator mapI = map->find("id");
	if(mapI != map->end())
	{
		this->id = mapI->second;
		this->isId = true;
	}

	mapI = map->find("autoExtractionType");
	if(mapI != map->end())
	{
		this->autoExtractionType = mapI->second;
		this->isAutoExtractionType = true;
	}

	mapI = map->find("activate");
	if(mapI != map->end())
	{
		if(mapI->second == "true") 
		{
			this->activate = true;
		}
		else if(mapI->second == "false")
		{
			this->activate = false;
		}
		this->isActivate = true;
	}

	mapI = map->find("duration");
	if(mapI != map->end())
	{
		this->duration = atoi((mapI->second).c_str());
		this->isDuration = true;
	}

	mapI = map->find("fade");
	if(mapI != map->end())
	{
		this->fade = atoi((mapI->second).c_str());
		this->isFade = true;
	}

	mapI = map->find("alt");
	if(mapI != map->end())
	{
		this->alt = mapI->second;
		this->isAlt = true;
	}

	mapI = map->find("priority");
	if(mapI != map->end())
	{
		this->priority = atoi((mapI->second).c_str());
		this->isPriority = true;
	}

	mapI = map->find("location");
	if(mapI != map->end())
	{
		this->location = mapI->second;
		this->isLocation = true;
	}

	mapI = map->find("adaptType");
	if(mapI != map->end())
	{
		this->adaptType = mapI->second;
		this->isAdaptType = true;
	}

	mapI = map->find("adaptRange");
	if(mapI != map->end())
	{
		this->adaptRange = atoi((mapI->second).c_str());
		this->isAdaptRange = true;
	}

	mapI = map->find("pts");
	if(mapI != map->end())
	{
		this->pts = atoi((mapI->second).c_str());
		this->isPts = true;
	}

	mapI = map->find("timeScale");
	if(mapI != map->end())
	{
		this->timeScale = atoi((mapI->second).c_str());
		this->isTimeScale = true;
	}

}
#include "stdafx.h"
#include "ReferenceEffectElement.h"
#include <stdlib.h>

ReferenceEffectElement::ReferenceEffectElement(ElementBaseType* e) 
{
	this->elementBaseType = e;
}

ReferenceEffectElement::~ReferenceEffectElement()
{
	
}

void ReferenceEffectElement::mappingData()
{

	/** Attribute mapping **/
	AttributeMap* map = elementBaseType->getAttributeMap();
	
	AttributeMap::iterator mapI = map->find("uri");
	if(mapI != map->end())
	{
		this->uri = mapI->second;
	}

	mapI = map->find("id");
	if(mapI != map->end())
	{
		this->id = mapI->second;
	}

	mapI = map->find("autoExtractionType");
	if(mapI != map->end())
	{
		this->autoExtractionType = mapI->second;
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
	}

	mapI = map->find("duration");
	if(mapI != map->end())
	{
		this->duration = atoi((mapI->second).c_str());
 	}

	mapI = map->find("fade");
	if(mapI != map->end())
	{
		this->fade = atoi((mapI->second).c_str());
	}

	mapI = map->find("alt");
	if(mapI != map->end())
	{
		this->alt = mapI->second;
	}

	mapI = map->find("priority");
	if(mapI != map->end())
	{
		this->priority = atoi((mapI->second).c_str());
	}

	mapI = map->find("location");
	if(mapI != map->end())
	{
		this->location = mapI->second;
	}

	mapI = map->find("adaptType");
	if(mapI != map->end())
	{
		this->adaptType = mapI->second;
	}

	mapI = map->find("adaptRange");
	if(mapI != map->end())
	{
		this->adaptRange = atoi((mapI->second).c_str());
	}

	mapI = map->find("pts");
	if(mapI != map->end())
	{
		this->pts = atoi((mapI->second).c_str());
	}

	mapI = map->find("timeScale");
	if(mapI != map->end())
	{
		this->timeScale = atoi((mapI->second).c_str());
	}


}
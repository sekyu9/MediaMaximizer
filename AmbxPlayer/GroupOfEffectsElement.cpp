#include "stdafx.h"
#include "GroupOfEffectsElement.h"
#include <vector>
#include "SEMRootElement.h"
#include "LightType.h"
#include "FlashType.h"
#include "FogType.h"
#include "ScentType.h"
#include "SprayingType.h"
#include "TemperatureType.h"
#include "VibrationType.h"
#include "WindType.h"
#include <stdlib.h>

GroupOfEffectsElement::GroupOfEffectsElement(ElementBaseType* e)
{
	this->goe = e;
	this->effectList = new vector<EffectBaseType*>;
	this->referenceEffectList = new vector<ReferenceEffectElement*>;
}

GroupOfEffectsElement::~GroupOfEffectsElement()
{
	for(int i = 0; i < effectList->size(); i++)
	{
		EffectBaseType* e = effectList->at(i);
		delete e;
	}
	delete effectList;

	for(int i = 0; i < referenceEffectList->size(); i++)
	{
		ReferenceEffectElement* r = referenceEffectList->at(i);
		delete r;
	}
	delete referenceEffectList;
}

void GroupOfEffectsElement::mappingData()
{

	/** Attribute mapping **/
	AttributeMap* map = goe->getAttributeMap();
	AttributeMap::iterator mapI = map->find("activate");
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
	cout << endl;

	/** Mapping Element **/
	vector<ElementBaseType*>* elementList = goe->getChildList();
	vector<ElementBaseType*>::iterator i;
	for(i = elementList->begin(); 
        i != elementList->end(); 
        i++)
	{
		if(((*i)->getName()) == "Effect" )
		{
			EffectBaseType* effect = getEffect(*i);
			effectList->push_back(effect);
		}
		else if((*i)->getName() == "ReferenceEffect")
		{
			ReferenceEffectElement* referenceEffect = new ReferenceEffectElement(*i);
			referenceEffect->mappingData();
			referenceEffectList->push_back(referenceEffect);
		}
	}
}
EffectBaseType* GroupOfEffectsElement::getEffect(ElementBaseType* e)
{
	EffectBaseType* effect = NULL;
	AttributeMap* map = e->getAttributeMap();
	AttributeMap::iterator i = map->find("type");

	if(i->second == "LightType") 
	{
		effect = new LightType(e);
		((LightType*)effect)->mappingData(); 
	}
	else if(i->second == "FlashType") 
	{
		effect = new FlashType(e);
		((FlashType*)effect)->mappingData();
	}
	else if(i->second == "TemperatureType") 
	{
		effect = new TemperatureType(e);
		((TemperatureType*)effect)->mappingData();
	}
	else if(i->second == "WindType") 
	{
		effect = new WindType(e);
		((WindType*)effect)->mappingData();
	}
	else if(i->second == "VibrationType") 
	{
		effect = new VibrationType(e);
		((VibrationType*)effect)->mappingData();
	}
	else if(i->second == "SprayingType") 
	{
		effect = new SprayingType(e);
		((SprayingType*)effect)->mappingData();
	}
	else if(i->second == "ScentType") 
	{
		effect = new ScentType(e);
		((ScentType*)effect)->mappingData();
	}
	else if(i->second == "FogType") 
	{
		effect = new FogType(e);
		((FogType*)effect)->mappingData();
	}
	else 
	{
		effect = new EffectBaseType(e);
	}
	return effect;
} 
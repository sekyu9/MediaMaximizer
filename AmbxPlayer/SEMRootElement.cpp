#include "stdafx.h"
#include "SEMRootElement.h"
#include "LightType.h"
#include "FlashType.h"
#include "FogType.h"
#include "ScentType.h"
#include "SprayingType.h"
#include "TemperatureType.h"
#include "VibrationType.h"
#include "WindType.h"
#include <string>
#include <stdlib.h>

using namespace std;

SEMRootElement::SEMRootElement(ElementBaseType* semRootElement)
{
	this->sem = semRootElement;
	this->childElementList = NULL;
	this->descriptionMetadata = NULL;
	this->declarationsList = new vector<DeclarationsElement*>;
	this->effectList = new vector<EffectBaseType*>;
	this->groupOfEffectsList = new vector<GroupOfEffectsElement*>;
	this->referenceEffectList = new vector<ReferenceEffectElement*>;

	this->timeScale = 1000l;
}
SEMRootElement::~SEMRootElement()
{
	delete this->descriptionMetadata;

	for(int i = 0; i < declarationsList->size(); i++)
	{
		DeclarationsElement* d = declarationsList->at(i);
		delete d;
	}
	delete declarationsList;

	for(int i = 0; i < effectList->size(); i++)
	{
		EffectBaseType* e = effectList->at(i);
		delete e;
	}
	delete effectList;

	for(int i = 0; i < groupOfEffectsList->size(); i++)
	{
		GroupOfEffectsElement* g = groupOfEffectsList->at(i);
		delete g;
	}
	delete groupOfEffectsList;

	for(int i = 0; i < referenceEffectList->size(); i++)
	{
		ReferenceEffectElement* r = referenceEffectList->at(i);
		delete r;
	}
	delete referenceEffectList;	

}

void SEMRootElement::mappingData(){
	//mapping Attribute
	AttributeMap* map = sem->getAttributeMap();

	AttributeMap::iterator mapI = map->find("pts");
	if(mapI != map->end())
	{
		this->pts = atoi((mapI->second).c_str());
	}
	mapI = map->find("timeScale");	
	if(mapI != map->end())
	{
		this->timeScale = atoi((mapI->second).c_str());
	}
	mapI = map->find("puMode");	
	if(mapI != map->end())
	{
		this->puMode = mapI->second;
	}

	cout << endl << endl;
	//mapping Element
	this->childElementList = sem->getChildList();
	vector<ElementBaseType*>::iterator i;
	for(int i = 0; i < childElementList->size();i++){
		ElementBaseType* e = childElementList->at(i);
		if((e)->getName() == "DescriptionMetadata")
		{
			this->descriptionMetadata = new DescriptionMetadataElement(e);
			descriptionMetadata->mappingData();
		}
		else if((e)->getName() == "Declarations")
		{
			DeclarationsElement* declarations = new DeclarationsElement(e);			
			declarations->mappingData();
			declarationsList->push_back(declarations);

		}
		else if((e)->getName() == "GroupOfEffects")
		{
			GroupOfEffectsElement* groupOfEffects = new GroupOfEffectsElement(e);
			groupOfEffects->mappingData();
			groupOfEffectsList->push_back(groupOfEffects);

		}
		else if(((e)->getName()) == "Effect" )
		{
			EffectBaseType* effect = getEffect(e);
			effectList->push_back(effect);
		}
		else if((e)->getName() == "ReferenceEffect")
		{
			ReferenceEffectElement* referenceEffect = new ReferenceEffectElement(e);
			referenceEffect->mappingData();
			referenceEffectList->push_back(referenceEffect);
		}
	}
}
EffectBaseType* SEMRootElement::getEffect(ElementBaseType* e)
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
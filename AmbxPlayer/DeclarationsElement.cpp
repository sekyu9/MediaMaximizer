#include "stdafx.h"
#include "DeclarationsElement.h"
#include <vector>
#include "SEMRootElement.h"

DeclarationsElement::DeclarationsElement(ElementBaseType* e)
{
	this->declarations = e;
	this->effectList = new vector<EffectBaseType*>;
	this->groupOfEffectsList = new vector<GroupOfEffectsElement*>;
}

DeclarationsElement::~DeclarationsElement()
{
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
}

void DeclarationsElement::mappingData()
{

	vector<ElementBaseType*>* elementList = declarations->getChildList();
	vector<ElementBaseType*>::iterator i;
	/** Mapping Element **/
	for(i = elementList->begin(); 
        i != elementList->end(); 
        i++)
	{
		if(((*i)->getName()) == "Effect" )
		{
			EffectBaseType* effect = SEMRootElement::getEffect(*i);
			effectList->push_back(effect);
		}
		else if((*i)->getName() == "GroupOfEffects")
		{
			GroupOfEffectsElement* groupOfEffects = new GroupOfEffectsElement(*i);
			groupOfEffects->mappingData();
			groupOfEffectsList->push_back(groupOfEffects);
		}
		else if((*i)->getName() == "Parameter")
		{
			
		}
	}
}
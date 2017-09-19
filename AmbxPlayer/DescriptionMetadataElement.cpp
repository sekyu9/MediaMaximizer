#include "stdafx.h"
#include "DescriptionMetadataElement.h"
#include <vector>
#include "SEMRootElement.h"

DescriptionMetadataElement::DescriptionMetadataElement(ElementBaseType* e)
{
	this->descriptionMetadata = e;
	this->mpeg7DescriptionMetadataList = new vector<ElementBaseType*>;
	this->classificationSchemeAliasList = new vector<ElementBaseType*>;
}

DescriptionMetadataElement::~DescriptionMetadataElement()
{
	delete this->mpeg7DescriptionMetadataList;
	delete this->classificationSchemeAliasList;
}

void DescriptionMetadataElement::mappingData()
{

	/** Attribute mapping **/
	AttributeMap* map = descriptionMetadata->getAttributeMap();
	AttributeMap::iterator mapI = map->find("id");
	if(mapI != map->end())
	{
		this->id = mapI->second;
	}

	mapI = map->find("alias");
	if(mapI != map->end())
	{
		this->alias = mapI->second;
	}

	mapI = map->find("href");
	if(mapI != map->end())
	{
		this->href = mapI->second;
	}

	/** Mapping Element **/
	vector<ElementBaseType*>* elementList = descriptionMetadata->getChildList();
	vector<ElementBaseType*>::iterator i;
	for(i = elementList->begin(); 
        i != elementList->end(); 
        i++)
	{
		if(((*i)->getName()) == "ClassificationSchemeAlias" )
		{
			classificationSchemeAliasList->push_back(*i);
		}
		else 
		{
			mpeg7DescriptionMetadataList->push_back(*i);
		}
	}
}
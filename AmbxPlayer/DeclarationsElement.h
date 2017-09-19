#ifndef __DeclarationsElement_h__
#define __DeclarationsElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"
#include "EffectBaseType.h"
#include "ReferenceEffectElement.h"
#include "GroupOfEffectsElement.h"
#include <vector>
#include <iostream>

class DeclarationsElement{
public:
	DeclarationsElement(ElementBaseType* e);
	virtual ~DeclarationsElement();

	void mappingData();

	/*getter & setter*/
	ElementBaseType* getDeclarations() const
    {
        return declarations;
    }

    void setDeclarations(ElementBaseType* declarations)
    {
        this->declarations = declarations;
    }

    vector<EffectBaseType*>* getEffectList() const
    {
        return effectList;
    }

    void setEffectList(vector<EffectBaseType*>* effectList)
    {
        this->effectList = effectList;
    }

    vector<GroupOfEffectsElement*>* getGroupOfEffectsList() const
    {
        return groupOfEffectsList;
    }

    void setGroupOfEffectsList(vector<GroupOfEffectsElement*>* groupOfEffectsList)
    {
        this->groupOfEffectsList = groupOfEffectsList;
    }

    string getId() const
    {
        return id;
    }

    void setId(string id)
    {
        this->id = id;
    }
    
private:
	// DeclarationsElement
	ElementBaseType* declarations;

	/** Attribute List **/
	// SEMBaseType
	string id;

	// Child Element List
	vector<EffectBaseType*>* effectList;
	vector<GroupOfEffectsElement*>* groupOfEffectsList;
	// parameter list;
};


#endif
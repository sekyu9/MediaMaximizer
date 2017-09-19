#ifndef __SEMRootElement_h__
#define __SEMRootElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"
#include "EffectBaseType.h"
#include "GroupOfEffectsElement.h"
#include "ReferenceEffectElement.h"
#include "DeclarationsElement.h"
#include "DescriptionMetadataElement.h"

#include <vector>
#include <iostream>

//using namespace std;

class SEMRootElement{
public:
	//constructor
	SEMRootElement(ElementBaseType* semRootElement);
	virtual ~SEMRootElement();

	void mappingData();
	static EffectBaseType* getEffect(ElementBaseType* e);

	/*getter & setter*/
	 vector<ElementBaseType*>* getChildElementList() const
    {
        return childElementList;
    }

    void setChildElementList(vector<ElementBaseType*>* childElementList)
    {
        this->childElementList = childElementList;
    }

	  vector<DeclarationsElement*>* getDeclarationsList() const
    {
        return declarationsList;
    }

    void setDeclarationsList(vector<DeclarationsElement*>* declarationsList)
    {
        this->declarationsList = declarationsList;
    }

    DescriptionMetadataElement* getDescriptionMetadata() const
    {
        return descriptionMetadata;
    }

    void setDescriptionMetadata(DescriptionMetadataElement* descriptionMetadata)
    {
        this->descriptionMetadata = descriptionMetadata;
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
	vector<ReferenceEffectElement*>* getReferenceEffectList() const
    {
        return referenceEffectList;
    }

    void setReferenceEffectList(vector<ReferenceEffectElement*>* referenceEffectList)
    {
        this->referenceEffectList = referenceEffectList;
    }

	int getPts() const
    {
        return pts;
    }

    void setPts(int pts)
    {
        this->pts = pts;
    }

    string getPuMode() const
    {
        return puMode;
    }

    void setPuMode(string puMode)
    {
        this->puMode = puMode;
    }
	 ElementBaseType* getSem() const
    {
        return sem;
    }

    void setSem(ElementBaseType* sem)
    {
        this->sem = sem;
    }

    int getTimeScale() const
    {
        return timeScale;
    }

    void setTimeScale(int timeScale)
    {
        this->timeScale = timeScale;
    }
private:
	// SEM Root Element 
	ElementBaseType* sem;
	// Child Element List
	vector<ElementBaseType*>* childElementList;
	// Group Of Effects List
	vector<GroupOfEffectsElement*>* groupOfEffectsList;
	// Description Metadata
	DescriptionMetadataElement* descriptionMetadata;

	// Declarations List
	vector<DeclarationsElement*>* declarationsList;
	// Effect List
	vector<EffectBaseType*>* effectList;

	// Reference Effect List
	vector<ReferenceEffectElement*>* referenceEffectList;
	// Any Attribute
	int pts;
	int timeScale;
	string puMode;
};
#endif
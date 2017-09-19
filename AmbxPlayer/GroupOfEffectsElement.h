#ifndef __GroupOfEffectsElement_h__
#define __GroupOfEffectsElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"
#include "EffectBaseType.h"
#include "ReferenceEffectElement.h"
#include <vector>
#include <iostream>

class GroupOfEffectsElement{
public:
	GroupOfEffectsElement(ElementBaseType* e);
	virtual ~GroupOfEffectsElement();

    EffectBaseType* getEffect(ElementBaseType* e);
	void mappingData();

	/*getter & setter*/
	bool isActivate() const
    {
        return activate;
    }

    void setActivate(bool activate)
    {
        this->activate = activate;
    }

    int getAdaptRange() const
    {
        return adaptRange;
    }

    void setAdaptRange(int adaptRange)
    {
        this->adaptRange = adaptRange;
    }

    string getAdaptType() const
    {
        return adaptType;
    }

    void setAdaptType(string adaptType)
    {
        this->adaptType = adaptType;
    }

    string getAlt() const
    {
        return alt;
    }

    void setAlt(string alt)
    {
        this->alt = alt;
    }

    int getDuration() const
    {
        return duration;
    }

    void setDuration(int duration)
    {
        this->duration = duration;
    }

    vector<EffectBaseType*>* getEffectList() const
    {
        return effectList;
    }

    void setEffectList(vector<EffectBaseType*>* effectList)
    {
        this->effectList = effectList;
    }

    int getFade() const
    {
        return fade;
    }

    void setFade(int fade)
    {
        this->fade = fade;
    }

    ElementBaseType* getGoe() const
    {
        return goe;
    }

    void setGoe(ElementBaseType* goe)
    {
        this->goe = goe;
    }

    string getLocation() const
    {
        return location;
    }

    void setLocation(string location)
    {
        this->location = location;
    }

    int getPriority() const
    {
        return priority;
    }

    void setPriority(int priority)
    {
        this->priority = priority;
    }

    int getPts() const
    {
        return pts;
    }

    void setPts(int pts)
    {
        this->pts = pts;
    }

    vector<ReferenceEffectElement*>* getReferenceEffectList() const
    {
        return referenceEffectList;
    }

    void setReferenceEffectList(vector<ReferenceEffectElement*>* referenceEffectList)
    {
        this->referenceEffectList = referenceEffectList;
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
	// Group Of Effects Element
	ElementBaseType* goe;

	// Child Element List
	vector<EffectBaseType*>* effectList;
	vector<ReferenceEffectElement*>* referenceEffectList;

	// SEMBaseAttributes
	bool activate;
	int duration;
	int fade;
	string alt;
	int priority;
	string location;

	// SEMAdaptabilityAttributes
	string adaptType;
	int adaptRange;

	// any attribute
	int pts;
	int timeScale;
};


#endif
#ifndef __ReferenceEffectElement_h__
#define __ReferenceEffectElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"

using namespace std;

class ReferenceEffectElement{
public:
	ReferenceEffectElement(ElementBaseType* e);
    virtual ~ReferenceEffectElement();
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

    string getAutoExtractionType() const
    {
        return autoExtractionType;
    }

    void setAutoExtractionType(string autoExtractionType)
    {
        this->autoExtractionType = autoExtractionType;
    }

    int getDuration() const
    {
        return duration;
    }

    void setDuration(int duration)
    {
        this->duration = duration;
    }

    ElementBaseType* getElementBaseType() const
    {
        return elementBaseType;
    }

    void setElementBaseType(ElementBaseType* elementBaseType)
    {
        this->elementBaseType = elementBaseType;
    }

    int getFade() const
    {
        return fade;
    }

    void setFade(int fade)
    {
        this->fade = fade;
    }

    string getId() const
    {
        return id;
    }

    void setId(string id)
    {
        this->id = id;
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

    int getTimeScale() const
    {
        return timeScale;
    }

    void setTimeScale(int timeScale)
    {
        this->timeScale = timeScale;
    }

    string getUri() const
    {
        return uri;
    }

    void setUri(string uri)
    {
        this->uri = uri;
    }
protected:
	// this
	ElementBaseType* elementBaseType;

	/** Attributes **/
	string uri;

	// SEM Base Type
	string id;
	string autoExtractionType;

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
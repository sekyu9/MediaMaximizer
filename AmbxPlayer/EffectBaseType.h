#ifndef __EffectBaseType_h__
#define __EffectBaseType_h__

#include "stdafx.h"
#include "ElementBaseType.h"

using namespace std;

class EffectBaseType{
public:
	EffectBaseType(ElementBaseType* e);
    virtual ~EffectBaseType();
    void mappingData();

    /** getter & setter **/
    bool getActivate() const
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

    bool isIsActivate() const
    {
        return isActivate;
    }

    void setIsActivate(bool isActivate)
    {
        this->isActivate = isActivate;
    }

    bool isIsAdaptRange() const
    {
        return isAdaptRange;
    }

    void setIsAdaptRange(bool isAdaptRange)
    {
        this->isAdaptRange = isAdaptRange;
    }

    bool isIsAdaptType() const
    {
        return isAdaptType;
    }

    void setIsAdaptType(bool isAdaptType)
    {
        this->isAdaptType = isAdaptType;
    }

    bool isIsAlt() const
    {
        return isAlt;
    }

    void setIsAlt(bool isAlt)
    {
        this->isAlt = isAlt;
    }

    bool isIsAutoExtractionType() const
    {
        return isAutoExtractionType;
    }

    void setIsAutoExtractionType(bool isAutoExtractionType)
    {
        this->isAutoExtractionType = isAutoExtractionType;
    }

    bool isIsDuration() const
    {
        return isDuration;
    }

    void setIsDuration(bool isDuration)
    {
        this->isDuration = isDuration;
    }

    bool isIsFade() const
    {
        return isFade;
    }

    void setIsFade(bool isFade)
    {
        this->isFade = isFade;
    }

    bool isIsId() const
    {
        return isId;
    }

    void setIsId(bool isId)
    {
        this->isId = isId;
    }

    bool isIsLocation() const
    {
        return isLocation;
    }

    void setIsLocation(bool isLocation)
    {
        this->isLocation = isLocation;
    }

    bool isIsPriority() const
    {
        return isPriority;
    }

    void setIsPriority(bool isPriority)
    {
        this->isPriority = isPriority;
    }

    bool isIsPts() const
    {
        return isPts;
    }

    void setIsPts(bool isPts)
    {
        this->isPts = isPts;
    }

    bool isIsSupplementalInformationList() const
    {
        return isSupplementalInformationList;
    }

    void setIsSupplementalInformationList(bool isSupplementalInformationList)
    {
        this->isSupplementalInformationList = isSupplementalInformationList;
    }

    bool isIsTimeScale() const
    {
        return isTimeScale;
    }

    void setIsTimeScale(bool isTimeScale)
    {
        this->isTimeScale = isTimeScale;
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

    vector<ElementBaseType*>* getSupplementalInformationList() const
    {
        return supplementalInformationList;
    }

    void setSupplementalInformationList(vector<ElementBaseType*>* supplementalInformationList)
    {
        this->supplementalInformationList = supplementalInformationList;
    }

    int getTimeScale() const
    {
        return timeScale;
    }

    void setTimeScale(int timeScale)
    {
        this->timeScale = timeScale;
    }


protected:
    ElementBaseType* elementBaseType;
    // child element
    bool isSupplementalInformationList;
    vector<ElementBaseType*>* supplementalInformationList;
    // attribute
    bool isId;
    string id;
    bool isAutoExtractionType;
    string autoExtractionType;
    // SEMBaseAttributes
    bool isActivate;
    bool activate;
    bool isDuration;
    int duration;
    bool isFade;
    int fade;
    bool isAlt;
    string alt;
    bool isPriority;
    int priority;
    bool isLocation;
    string location;
    // SEMAdaptabilityAttributes
    bool isAdaptType;
    string adaptType;
    bool isAdaptRange;
    int adaptRange;
    // any attribute
    bool isPts;
    int pts;
    bool isTimeScale;
    int timeScale;
};	
#endif
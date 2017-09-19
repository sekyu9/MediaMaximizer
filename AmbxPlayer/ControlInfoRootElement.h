#ifndef __ControlInfoRootElement_h__
#define __ControlInfoRootElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"
#include "SensoryDeviceCapabilityBaseType.h"


#include <vector>
#include <iostream>

using namespace std;

class ControlInfoRootElement{
public:
	
	ControlInfoRootElement(ElementBaseType* controlInfoRootElement);
    SensoryDeviceCapabilityBaseType* getSensoryDeviceCapabilityType(ElementBaseType* e);
    void mappingData();

    vector<ElementBaseType*>* getChildElementList() const
    {
        return childElementList;
    }

    void setChildElementList(vector<ElementBaseType*>* childElementList)
    {
        this->childElementList = childElementList;
    }

    ElementBaseType* getCi() const
    {
        return ci;
    }

    void setCi(ElementBaseType* ci)
    {
        this->ci = ci;
    }

    vector<ElementBaseType*>* getSensorAdaptationPreferenceList() const
    {
        return sensorAdaptationPreferenceList;
    }

    void setSensorAdaptationPreferenceList(vector<ElementBaseType*>* sensorAdaptationPreferenceList)
    {
        this->sensorAdaptationPreferenceList = sensorAdaptationPreferenceList;
    }

    vector<ElementBaseType*>* getSensorDeviceCapabilityList() const
    {
        return sensorDeviceCapabilityList;
    }

    void setSensorDeviceCapabilityList(vector<ElementBaseType*>* sensorDeviceCapabilityList)
    {
        this->sensorDeviceCapabilityList = sensorDeviceCapabilityList;
    }

    vector<SensoryDeviceCapabilityBaseType*>* getSensoryDeviceCapabilityList() const
    {
        return sensoryDeviceCapabilityList;
    }

    void setSensoryDeviceCapabilityList(vector<SensoryDeviceCapabilityBaseType*>* sensoryDeviceCapabilityList)
    {
        this->sensoryDeviceCapabilityList = sensoryDeviceCapabilityList;
    }

    SensoryDeviceCapabilityBaseType* getSDC(int);

private:
    // Control Info Root Element 
    ElementBaseType* ci;
    // Child Element List
    vector<ElementBaseType*>* childElementList;
    vector<SensoryDeviceCapabilityBaseType*>* sensoryDeviceCapabilityList;
    vector<ElementBaseType*>* sensorDeviceCapabilityList;
    vector<ElementBaseType*>* sensorAdaptationPreferenceList;
};

#endif
#ifndef __SensoryDeviceCapabilityBaseType_h__
#define __SensoryDeviceCapabilityBaseType_h__

#include "stdafx.h"
#include "ElementBaseType.h"

#include <vector>
#include <iostream>

using namespace std;

class SensoryDeviceCapabilityBaseType
{
public:
    SensoryDeviceCapabilityBaseType(ElementBaseType* aensoryDeviceCapabilityBaseType);
    virtual ~SensoryDeviceCapabilityBaseType() {};
    void mappingData();

    int getFirstOrderDelayTime() const
    {
        return firstOrderDelayTime;
    }

    void setFirstOrderDelayTime(int firstOrderDelayTime)
    {
        this->firstOrderDelayTime = firstOrderDelayTime;
    }

    string getId() const
    {
        return id;
    }

    void setId(string id)
    {
        this->id = id;
    }

    bool isIsFirstOrderDelayTime() const
    {
        return isFirstOrderDelayTime;
    }

    void setIsFirstOrderDelayTime(bool isFirstOrderDelayTime)
    {
        this->isFirstOrderDelayTime = isFirstOrderDelayTime;
    }

    bool isIsId() const
    {
        return isId;
    }

    void setIsId(bool isId)
    {
        this->isId = isId;
    }

    bool isIsLocator() const
    {
        return isLocator;
    }

    void setIsLocator(bool isLocator)
    {
        this->isLocator = isLocator;
    }

    bool isIsZerothOrderDelayTime() const
    {
        return isZerothOrderDelayTime;
    }

    void setIsZerothOrderDelayTime(bool isZerothOrderDelayTime)
    {
        this->isZerothOrderDelayTime = isZerothOrderDelayTime;
    }

    string getLocator() const
    {
        return locator;
    }

    void setLocator(string locator)
    {
        this->locator = locator;
    }

    ElementBaseType* getSensoryDeviceCapabilityBaseType() const
    {
        return sensoryDeviceCapabilityBaseType;
    }

    void setSensoryDeviceCapabilityBaseType(ElementBaseType* sensoryDeviceCapabilityBaseType)
    {
        this->sensoryDeviceCapabilityBaseType = sensoryDeviceCapabilityBaseType;
    }

    int getZerothOrderDelayTime() const
    {
        return zerothOrderDelayTime;
    }

    void setZerothOrderDelayTime(int zerothOrderDelayTime)
    {
        this->zerothOrderDelayTime = zerothOrderDelayTime;
    }

protected:
    // Control Info Root Element 
    ElementBaseType* sensoryDeviceCapabilityBaseType;
    // TerminalCapabilityBaseType -> DIABaseType -> <attribute name="id" type="ID" use="optional"/>
    bool isId;
    string id;
    // SensoryDeviceCapabilityBaseTypeAttributes
    bool isZerothOrderDelayTime;
    int zerothOrderDelayTime;
    bool isFirstOrderDelayTime;
    int firstOrderDelayTime;
    bool isLocator;
    string locator;
};

#endif
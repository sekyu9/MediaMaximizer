#include "stdafx.h"
#include "ControlInfoRootElement.h"

#include "LightCapabilityType.h"
#include "WindCapabilityType.h"
#include "VibrationCapabilityType.h"
//#include "FlashCapabilityType.h"
//#include "HeatingCapabilityType.h"
//#include "CoolingCapabilityType.h"
//#include "FogCapabilityType.h"
//#include "ScentCapabilityType.h"
//#include "SprayerCapabilityType.h"


#include "constants.h"






#include <string>
#include <stdlib.h>

using namespace std;

ControlInfoRootElement::ControlInfoRootElement(ElementBaseType* controlInfoRootElement)
{
	this->ci = controlInfoRootElement;
	this->childElementList = new vector<ElementBaseType*>;
	this->sensoryDeviceCapabilityList = new vector<SensoryDeviceCapabilityBaseType*>;
	this->sensorDeviceCapabilityList = new vector<ElementBaseType*>;
	this->sensorAdaptationPreferenceList = new vector<ElementBaseType*>;
}

SensoryDeviceCapabilityBaseType* ControlInfoRootElement::getSensoryDeviceCapabilityType(ElementBaseType* e)
{
	SensoryDeviceCapabilityBaseType* capability = NULL;
	AttributeMap* map = e->getAttributeMap();
	AttributeMap::iterator i = map->find("type");
		if(i->second == "LightCapabilityType") 
	{
		capability = new LightCapabilityType(e);
		((LightCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "WindCapabilityType") 
	{
		capability = new WindCapabilityType(e);
		((WindCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "VibrationCapabilityType") 
	{
		capability = new VibrationCapabilityType(e);
		((VibrationCapabilityType*)capability)->mappingData(); 
	}
	else 
	{
		capability = new SensoryDeviceCapabilityBaseType(e);
	}
	/*else if(i->second == "FlashCapabilityType") 
	{
		capability = new FlashCapabilityType(e);
		((FlashCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "HeatingCapabilityType") 
	{
		capability = new HeatingCapabilityType(e);
		((HeatingCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "CoolingCapabilityType") 
	{
		capability = new CoolingCapabilityType(e);
		((CoolingCapabilityType*)capability)->mappingData(); 
	}*/
	/*else if(i->second == "ScentCapabilityType") 
	{
		capability = new ScentCapabilityType(e);
		((ScentCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "FogCapabilityType") 
	{
		capability = new FogCapabilityType(e);
		((FogCapabilityType*)capability)->mappingData(); 
	}
	else if(i->second == "SprayerCapabilityType") 
	{
		capability = new SprayerCapabilityType(e);
		((SprayerCapabilityType*)capability)->mappingData(); 
	}*/
	return capability;
}


void ControlInfoRootElement::mappingData(){
	/** Mapping Element **/
	this->childElementList = ci->getChildList();	
	vector<ElementBaseType*>::iterator i;

	for(i = childElementList->begin(); 
        i != childElementList->end(); 
        i++)
	{
		if((*i)->getName() == "SensoryDeviceCapabilityList")
		{
			vector<ElementBaseType*>* elementList = (*i)->getChildList();
			vector<ElementBaseType*>::iterator j;
			for(j = elementList->begin(); j != elementList->end(); j++) 
			{
				SensoryDeviceCapabilityBaseType* capability = getSensoryDeviceCapabilityType(*j);
				sensoryDeviceCapabilityList->push_back(capability);
			}
		}
	}
}

SensoryDeviceCapabilityBaseType* ControlInfoRootElement::getSDC(int type){
	if(sensoryDeviceCapabilityList != 0)
	{
		SensoryDeviceCapabilityBaseType *sdc = 0;

		for(int i = 0; i < sensoryDeviceCapabilityList->size(); i++)
		{
			sdc = sensoryDeviceCapabilityList->at(i);

			if(type == SDC::LIGHT && dynamic_cast<LightCapabilityType*>(sdc))
    			break;
			else if(type == SDC::WIND && dynamic_cast<WindCapabilityType*>(sdc))
	    		break;
	    	else if(type == SDC::VIBRATION && dynamic_cast<VibrationCapabilityType*>(sdc))
	    		break;
			/*
			else if(type == SDC::FLASH && dynamic_cast<FlashCapabilityType*>(sdc))
    			break;
	    	else if(type == SDC::HEATING && dynamic_cast<HeatingCapabilityType*>(sdc))
	    		break;
	    	else if(type == SDC::COOLING && dynamic_cast<CoolingCapabilityType*>(sdc))
	    		break;
	    	else if(type == SDC::SCENT && dynamic_cast<ScentCapabilityType*>(sdc))
	    		break;
	    	else if(type == SDC::FOG && dynamic_cast<FogCapabilityType*>(sdc))
	    		break;
	    	else if(type == SDC::SPRAYER && dynamic_cast<SprayerCapabilityType*>(sdc))
	    		break;*/
	    }

	    return sdc;
	}
	else
	{
		return (SensoryDeviceCapabilityBaseType*)0;
	}
}
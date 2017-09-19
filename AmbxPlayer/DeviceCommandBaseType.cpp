#include "stdafx.h"
#include "DeviceCommandBaseType.h"
#include "ClockTickTimeType.h"
#include "ParsingHelper.h"

#include "LightCommandType.h"
#include "WindCommandType.h"
#include "VibrationCommandType.h"
#include "SprayerCommandType.h"

DeviceCommandBaseType::DeviceCommandBaseType()
{
	isID = false;
	isDeviceIdRef = false;
	isActivate = false;
}

DeviceCommandBaseType::DeviceCommandBaseType(EffectBaseType * effect, SensoryDeviceCapabilityBaseType *sdc)
{
	isID = false;
	isDeviceIdRef = false;
	isActivate = false;

	//Effect

	if(effect != 0)
	{
		if(effect->isIsActivate())
		{
			this->activate = effect->getActivate();
			this->isActivate = true;
		}

		if(effect->isIsId())
		{
			this->id = effect->getId();
			this->isID = true;
		}

		if(effect->isIsDuration())
		{
			this->duration = effect->getDuration();
		}
		
		timeStamp = new ClockTickTimeType();

		((ClockTickTimeType*)timeStamp)->setTimeScale(effect->getTimeScale());                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		((ClockTickTimeType*)timeStamp)->setPts(effect->getPts());
		

		// SDC
		if(sdc != 0)
		{
			
		}
	}

	isDeviceIdRef = true;
	deviceIdRef = "deviceIdRef";
}

DeviceCommandBaseType::~DeviceCommandBaseType()
{
	delete timeStamp;
}


const char* DeviceCommandBaseType::getParam2() const
{
	char *param2 = (char*)malloc(sizeof(char) * 10);

	if(typeName == "LightType")
	{
		strcpy(param2, ParsingHelper::toString(((LightCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "WindType")
	{
		strcpy(param2, ParsingHelper::toString(((WindCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "VibrationType")
	{
		strcpy(param2, ParsingHelper::toString(((VibrationCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "SprayerType")
	{
		strcpy(param2, ParsingHelper::toString(((SprayerCommandType*)this)->getIntensity()).c_str());
	}
	
	strcat(param2, "/");
	strcat(param2, ParsingHelper::toString(duration).c_str());


	return (const char*)param2;
}



/*else if(typeName == "FlashType")
	{
		strcpy(param2, ParsingHelper::toString(((FlashCommandType*)this)->getFrequency()).c_str());
	}
	else if(typeName == "HeatingType")
	{
		strcpy(param2, ParsingHelper::toString(((HeatingCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "CoolingType")
	{
		strcpy(param2, ParsingHelper::toString(((CoolingCommandType*)this)->getIntensity()).c_str());
	}
	
	else if(typeName == "ScentType")
	{
		strcpy(param2, ParsingHelper::toString(((ScentCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "FogType")
	{
		strcpy(param2, ParsingHelper::toString(((FogCommandType*)this)->getIntensity()).c_str());
	}
	else if(typeName == "SprayerType")
	{
		strcpy(param2, ParsingHelper::toString(((SprayerCommandType*)this)->getIntensity()).c_str());
	}
*/

#include "stdafx.h"
#include "CoolingCommandType.h"
#include "TemperatureType.h"
#include "CoolingCapabilityType.h"

CoolingCommandType::CoolingCommandType()
{
	this->typeName = "CoolingType";

	this->isIntensity = false;
}

CoolingCommandType::CoolingCommandType(EffectBaseType *effect,  SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "CoolingType";

	isIntensity = false;
	
	TemperatureType *temperatureType = (TemperatureType*)effect;
	CoolingCapabilityType *coolingCapabilityType = (CoolingCapabilityType*)sdc;

	// Effect
	if(temperatureType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 100.0f };

		if(temperatureType->isIsIntensityValue())
			intensity = temperatureType->getIntensityValue();

		if(temperatureType->isIsIntensityRange())
		{
			range[0] = temperatureType->getIntensityRange()->at(0);
			range[1] = temperatureType->getIntensityRange()->at(1);
		}


		// SDC
		if(coolingCapabilityType != 0)
		{
			if(coolingCapabilityType->isIsMinIntensity())
			{
				if(range[0] < coolingCapabilityType->getMinIntensity())
				{
					range[0] = coolingCapabilityType->getMinIntensity();

					if(intensity < range[0])
						intensity = range[0];
				}
			}

			if(coolingCapabilityType->isIsMaxIntensity())
			{
				if(range[1] > coolingCapabilityType->getMaxIntensity())
				{
					range[1] = coolingCapabilityType->getMaxIntensity();

					if(intensity > range[1])
						intensity = range[1];
				}
			}

			if(coolingCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / coolingCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << coolingCapabilityType->getNumOfLevels() << endl;
				
				intensity -= range[0];

				for(int i = 1; i < coolingCapabilityType->getNumOfLevels() + 1; i++)
				{
					if(intensity >= section * (i - 1) && intensity <= section * i)
					{
						float gap = section * i - intensity;

						if(gap <= section / 2)
							intensity = section * i;
						else
							intensity = section * (i - 1);

						break;
					}
				}

				cout << "Scaled intensity: " << intensity << endl;
			}
		}

		this->setIntensity(intensity * 100 / (range[1] - range[0]));

		cout << "> Cooling intensity: " << this->getIntensity() << endl;
	}
}

CoolingCommandType::~CoolingCommandType()
{

}

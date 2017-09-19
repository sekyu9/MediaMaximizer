#include "stdafx.h"
#include "HeatingCommandType.h"
#include "TemperatureType.h"
#include "HeatingCapabilityType.h"


HeatingCommandType::HeatingCommandType()
{
	this->typeName = "HeatingType";

	this->isIntensity = false;
}

HeatingCommandType::HeatingCommandType(EffectBaseType *effect,  SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "HeatingType";

	isIntensity = false;
	
	TemperatureType *temperatureType = (TemperatureType*)effect;
	HeatingCapabilityType *heatingCapabilityType = (HeatingCapabilityType*)sdc;

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
		if(heatingCapabilityType != 0)
		{
			if(heatingCapabilityType->isIsMinIntensity())
			{
				if(range[0] < heatingCapabilityType->getMinIntensity())
				{
					range[0] = heatingCapabilityType->getMinIntensity();

					if(intensity < range[0])
						intensity = range[0];
				}
			}

			if(heatingCapabilityType->isIsMaxIntensity())
			{
				if(range[1] > heatingCapabilityType->getMaxIntensity())
				{
					range[1] = heatingCapabilityType->getMaxIntensity();

					if(intensity > range[1])
						intensity = range[1];
				}
			}

			if(heatingCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / heatingCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << heatingCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < heatingCapabilityType->getNumOfLevels() + 1; i++)
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

		cout << "> Heating intensity: " << this->getIntensity() << endl;
	}
}

HeatingCommandType::~HeatingCommandType()
{

}


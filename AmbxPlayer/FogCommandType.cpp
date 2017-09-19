#include "stdafx.h"
#include "FogCommandType.h"
#include "FogType.h"
#include "FogCapabilityType.h"

FogCommandType::FogCommandType()
{
	this->typeName = "FogType";

	this->isIntensity = false;
}

FogCommandType::FogCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "FogType";

	isIntensity = false;

	FogType *fogType = (FogType*)effect;
	FogCapabilityType *fogCapabilityType = (FogCapabilityType*)sdc;

	// Effect
	if(fogType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 10.0f };

		if(fogType->isIsIntensityValue())
			intensity = fogType->getIntensityValue();

		if(fogType->isIsIntensityRange())
		{
			range[0] = fogType->getIntensityRange()->at(0);
			range[1] = fogType->getIntensityRange()->at(1);
		}


		// SDC
		if(fogCapabilityType != 0)
		{
			if(fogCapabilityType->isIsMaxIntensity())
			{
				if(fogCapabilityType->isIsMaxIntensity())
				{
					if(range[1] > fogCapabilityType->getMaxIntensity())
					{
						range[1] = fogCapabilityType->getMaxIntensity();

						if(intensity > range[1])
							intensity = range[1];
					}
				}
			}

			if(fogCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / fogCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << fogCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < fogCapabilityType->getNumOfLevels() + 1; i++)
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

		cout << "> Fog intensity: " << this->getIntensity() << endl;
	}
}

FogCommandType::~FogCommandType()
{

}


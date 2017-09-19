#include "stdafx.h"
#include "SprayerCommandType.h"
#include "SprayingType.h"
#include "SprayerCapabilityType.h"
#include "SprayingCS.h"

SprayerCommandType::SprayerCommandType()
{
	this->typeName = "SprayerType";

	this->isSprayingType = false;
	this->isIntensity = false;
}

SprayerCommandType::SprayerCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "SprayerType";

	isSprayingType = false;
	isIntensity = false;

	SprayingType *sprayingType = (SprayingType*)effect;
	SprayerCapabilityType *sprayerCapabilityType = (SprayerCapabilityType*)sdc;

	// Effect
	if(sprayingType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 10.0f };

		if(sprayingType->isIsSprayingType())
			this->sprayingType = sprayingType->getSprayingType();

		if(sprayingType->isIsIntensityValue())
			intensity = sprayingType->getIntensityValue();

		if(sprayingType->isIsIntensityRange())
		{
			range[0] = sprayingType->getIntensityRange()->at(0);
			range[1] = sprayingType->getIntensityRange()->at(1);
		}



		// SDC
		if(sprayerCapabilityType != 0)
		{
			if(sprayerCapabilityType->isIsSprayingType())
			{
				this->setSprayingType(sprayerCapabilityType->getSprayingType());
			}

			if(sprayerCapabilityType->isIsMaxIntensity())
			{
				if(sprayerCapabilityType->isIsMaxIntensity())
				{
					if(range[1] > sprayerCapabilityType->getMaxIntensity())
					{
						range[1] = sprayerCapabilityType->getMaxIntensity();

						if(intensity > range[1])
							intensity = range[1];
					}
				}
			}

			if(sprayerCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / sprayerCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << sprayerCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < sprayerCapabilityType->getNumOfLevels() + 1; i++)
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

		cout << "> Spraying intensity: " << this->getIntensity() << endl;
	}
}

SprayerCommandType::~SprayerCommandType()
{

}


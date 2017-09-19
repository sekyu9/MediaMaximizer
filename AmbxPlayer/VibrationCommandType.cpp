#include "stdafx.h"
#include "VibrationCommandType.h"
#include "VibrationType.h"
#include "VibrationCapabilityType.h"

VibrationCommandType::VibrationCommandType()
{
	this->typeName = "VibrationType";

	this->isIntensity = false;
}

VibrationCommandType::VibrationCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "VibrationType";

	isIntensity = false;

	VibrationType *vibrationType = (VibrationType*)effect;
	VibrationCapabilityType *vibrationCapabilityType = (VibrationCapabilityType*)sdc;
	
	// Effect
	if(vibrationType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 50.0f };

		if(vibrationType->isIsIntensityValue())
			intensity = vibrationType->getIntensityValue();

		if(vibrationType->isIsIntensityRange())
		{
			range[0] = vibrationType->getIntensityRange()->at(0);
			range[1] = vibrationType->getIntensityRange()->at(1);
		}

		// SDC
		if(vibrationCapabilityType != 0)
		{
			if(vibrationCapabilityType->isIsMaxIntensity())
			{
				if(vibrationCapabilityType->isIsMaxIntensity())
				{
					if(range[1] > vibrationCapabilityType->getMaxIntensity())
					{
						range[1] = vibrationCapabilityType->getMaxIntensity();

						if(intensity > range[1])
							intensity = range[1];
					}
				}
			}

			if(vibrationCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / vibrationCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << vibrationCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < vibrationCapabilityType->getNumOfLevels() + 1; i++)
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

		cout << "> Vibration intensity: " << this->getIntensity() << endl;
	}
}

VibrationCommandType::~VibrationCommandType()
{

}


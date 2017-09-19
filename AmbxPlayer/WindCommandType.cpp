#include "stdafx.h"
#include "WindCommandType.h"
#include "WindType.h"
#include "WindCapabilityType.h"

WindCommandType::WindCommandType()
{
	this->typeName = "WindType";

	this->isIntensity = false;
}

WindCommandType::WindCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "WindType";

	isIntensity = false;
	
	WindType *windType = (WindType*)effect;
	WindCapabilityType *windCapabilityType = (WindCapabilityType*)sdc;

	// Effect
	if(windType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 12.0f };

		if(windType->isIsIntensityValue())
			intensity = windType->getIntensityValue();

		if(windType->isIsIntensityRange())
		{
			range[0] = windType->getIntensityRange()->at(0);
			range[1] = windType->getIntensityRange()->at(1);
		}

		// SDC
		if(windCapabilityType != 0)
		{
			if(windCapabilityType->isIsMaxWindSpeed())
			{
				if(range[1] > windCapabilityType->getMaxWindSpeed())
				{
					range[1] = windCapabilityType->getMaxWindSpeed();

					if(intensity > range[1])
						intensity = range[1];
				}
			}

			if(windCapabilityType->isIsNumOfLevels())
			{
				double section = (double)(range[1] - range[0]) / windCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << windCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];
				  
				for(int i = 1; i < windCapabilityType->getNumOfLevels() + 1; i++)
				{
					if(intensity >= section * (i - 1) && intensity <= section * i)
					{
						float gap =  section * i - intensity;

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

		this->setIntensity(intensity * 100 / (range[1] - range[0] ));

		cout << "> Wind intensity: " << this->getIntensity() << endl;
	}
}

WindCommandType::~WindCommandType()
{

}


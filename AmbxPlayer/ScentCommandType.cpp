#include "stdafx.h"
#include "ScentCommandType.h"
#include "ScentType.h"
#include "ScentCapabilityType.h"
#include "ScentCS.h"

ScentCommandType::ScentCommandType()
{
	this->typeName = "ScentType";

	this->isScent = false;
	this->isIntensity = false;
}

ScentCommandType::ScentCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "ScentType";

	isScent = false;
	isIntensity = false;

	ScentType *scentType = (ScentType*)effect;
	ScentCapabilityType *scentCapabilityType = (ScentCapabilityType*)sdc;

	// Effect
	if(scentType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.0f, 10.0f };

		if(scentType->isIsScent())
			this->setScent(scentType->getScent());

		if(scentType->isIsIntensityValue())
			intensity = scentType->getIntensityValue();

		if(scentType->isIsIntensityRange())
		{
			range[0] = scentType->getIntensityRange()->at(0);
			range[1] = scentType->getIntensityRange()->at(1);
		}


		// SDC
		if(scentCapabilityType != 0)
		{
			if(scentCapabilityType->isIsScentElementList() && scentType->isIsScent())
			{
				string scent = scentType->getScent();
				vector<string> *deviceScentList = scentCapabilityType->getScentElementList();
				bool scentFlag = false;

				for(int i = 0; i < deviceScentList->size(); i++)
				{
					if(deviceScentList->at(i) == scent)
					{
						scentFlag = true;
						break;
					}
				}

				if(!scentFlag)
				{
					this->isScent = false;
				}
			}

			if(scentCapabilityType->isIsMaxIntensity())
			{
				if(scentCapabilityType->isIsMaxIntensity())
				{
					if(range[1] > scentCapabilityType->getMaxIntensity())
					{
						range[1] = scentCapabilityType->getMaxIntensity();

						if(intensity > range[1])
							intensity = range[1];
					}
				}
			}

			if(scentCapabilityType->isIsNumOfLevels())
			{
				float section = (float)(range[1] - range[0]) / scentCapabilityType->getNumOfLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << scentCapabilityType->getNumOfLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < scentCapabilityType->getNumOfLevels() + 1; i++)
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

		cout << "> Scent intensity: " << this->getIntensity() << endl;
	}
}

ScentCommandType::~ScentCommandType()
{

}


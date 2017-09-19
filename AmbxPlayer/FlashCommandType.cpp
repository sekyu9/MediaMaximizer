#include "stdafx.h"
#include "FlashCommandType.h"

#include "FlashType.h"
#include "FlashCapabilityType.h"

FlashCommandType::FlashCommandType()
{
	this->typeName = "FlashType";

	this->isFrequency = false;
}

FlashCommandType::FlashCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: LightCommandType(effect, sdc)
{
	this->typeName = "FlashType";

	isFrequency = false;

	FlashType *flashType = (FlashType*)effect;
	FlashCapabilityType *flashCapabilityType = (FlashCapabilityType*)sdc;

	// Effect
	if(flashType != 0)
	{
		int frequency = 0;
		int range[2] = { 0, 100 };

		if(flashType->isIsFrequency())
			frequency = flashType->getFrequency();


		// SDC
		if(flashCapabilityType != 0)
		{
			if(flashCapabilityType->isIsMaxFrequency())
			{
				if(range[1] > flashCapabilityType->getMaxFrequency())
				{
					range[1] = flashCapabilityType->getMaxFrequency();

					if(frequency > range[1])
						frequency = range[1];
				}
			}

			if(flashCapabilityType->isIsNumOfFreqLevels())
			{
				float section = (float)(range[1] - range[0]) / flashCapabilityType->getNumOfFreqLevels();
				
				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Frequency: " << frequency << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << flashCapabilityType->getNumOfFreqLevels() << endl;
			
				frequency -= range[0];

				for(int i = 1; i < flashCapabilityType->getNumOfFreqLevels() + 1; i++)
				{
					if(frequency >= section * (i - 1) && frequency <= section * i)
					{
						float gap = section * i - frequency;

						if(gap <= section / 2)
							frequency = section * i;
						else
							frequency = section * (i - 1);

						break;
					}
				}

				cout << "Scaled frequency: " << frequency << endl;
			}
		}

		this->setFrequency(frequency * 100 / (range[1] - range[0]));

		cout << "> Flash frequency: " << this->getFrequency() << endl;
	}
}

FlashCommandType::~FlashCommandType()
{
}


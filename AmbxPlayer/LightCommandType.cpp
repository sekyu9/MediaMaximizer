#include "stdafx.h"
#include "LightCommandType.h"
#include "LightType.h"
#include "LightCapabilityType.h"

LightCommandType::LightCommandType()
{
	this->typeName = "LightType";
	this->isColor = false;
	this->isIntensity = false;
}

LightCommandType::~LightCommandType()
{
}

LightCommandType::LightCommandType(EffectBaseType *effect, SensoryDeviceCapabilityBaseType *sdc)
	: DeviceCommandBaseType(effect, sdc)
{
	this->typeName = "LightType";

	isColor = false;
	isIntensity = false;

	LightType *lightType = (LightType*)effect;
	LightCapabilityType *lightCapabilityType = (LightCapabilityType*)sdc;

	// Effect
	if(lightType != 0)
	{
		float intensity = 0.0f;
		float range[2] = { 0.00001f, 32000.0f };

		if(lightType->isIsColor())
		{
			ColorCS* cs = new ColorCS();

			this->setColor(lightType->getColor());
			cout << "isColor" << endl;

			color.setColorRGBType(cs->convertColorToRGB(color.getNamedColorType()));

			//cs->convertToAmbxRGB(color.getColorRGBType());
		}
			

		if(lightType->isIsIntensityValue())
			intensity = lightType->getIntensityValue();

		if(lightType->isIsIntensityRange())
		{
			range[0] = lightType->getIntensityRange()->at(0);
			range[1] = lightType->getIntensityRange()->at(1);
		}

		// SDC
		if(lightCapabilityType != 0)
		{
			if(lightCapabilityType->isIsColorElementList() && lightType->isIsColor())
			{
				///////	
				ColorType color = lightType->getColor();
				//////

				vector<ColorType> *deviceColorList = lightCapabilityType->getColorElementList();
				bool colorFlag = false;

				for(int i = 0; i < deviceColorList->size(); i++)
				{
					if(deviceColorList->at(i) == color)
				 	{
						colorFlag = true;
				 		break;
				 	}
				}

				if(!colorFlag)
				{
					this->isColor = false;
				}

			}

			if(lightCapabilityType->isIsMaxIntensity())
			{
				if(range[1] > lightCapabilityType->getMaxIntensity())
				{
					range[1] = lightCapabilityType->getMaxIntensity();

					if(intensity > range[1])
						intensity = range[1];
				}
			}

			if(lightCapabilityType->isIsNumOfLightLevels())
			{
				float section = (float)(range[1] - range[0]) / lightCapabilityType->getNumOfLightLevels();

				cout << "Max: " << range[1] << endl;
				cout << "Min: " << range[0] << endl;
				cout << "Intensity: " << intensity << endl;
				cout << "Section: " << section << endl;
				cout << "Num: " << lightCapabilityType->getNumOfLightLevels() << endl;

				intensity -= range[0];

				for(int i = 1; i < lightCapabilityType->getNumOfLightLevels() + 1; i++)
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

		cout << "> Light intensity: " << this->getIntensity() << endl;

	}
}




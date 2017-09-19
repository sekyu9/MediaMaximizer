#include "StdAfx.h"
#include "Ambx.h"

Ambx::Ambx(void)
{
	amBXCreateInterface(&pIamBX,1,0,"amBX_Console","1.1",NULL,false);
	client = new Client();

	LightIsCreate = false;
	FanIsCreate = false;
	RumbleIsCreate = false;
}

Ambx::~Ambx(void)
{
}

void Ambx::Play(vector<DeviceCommandBaseType*>* deviceCommandList, int i, DWORD videoCur)
{
	DeviceCommandBaseType* dc = deviceCommandList->at(i);

	if(dc->getTypeName() == "LightType")
	{		
		if(dc->getActivate() == true)
		{
			if(LightIsCreate == false)
			{
				pIamBX->createLight(pIamBX,
					(amBX_loc)(0), 
					(amBX_height)amBX_EVERYHEIGHT, 
					&apIamBXLight);
				LightIsCreate = true;
			}
			ConvertToAmbxRGB(  ((ColorType)(((LightCommandType*)dc)->getColor())).getColorRGBType()  );

			apIamBXLight->setCol(apIamBXLight, 
				amBX_R,
				amBX_G,
				amBX_B);

			pIamBX->update(pIamBX, 0);
		}
		else
		{
			LightIsCreate = false;
			apIamBXLight->release(apIamBXLight);
		}
	}
	if(dc->getTypeName() == "WindType")
	{
		if(dc->getActivate() == true)
		{
			if(FanIsCreate == false)
			{
			pIamBX->createFan(pIamBX, 
				(amBX_loc)(0), 
				(amBX_height)amBX_EVERYHEIGHT,
				&apIamBXFan);

				FanIsCreate = true;
			}
			apIamBXFan->setIntensity(apIamBXFan,
				(amBX_float)((WindCommandType*)dc)->getIntensity()/100);
			pIamBX->update(pIamBX, 0);
		}
		else
		{
			FanIsCreate = false;
			apIamBXFan->release(apIamBXFan);
		}
	}
	if(dc->getTypeName() == "VibrationType")
	{
		if(dc->getActivate() == true)
		{
			if(RumbleIsCreate == false)
			{
				pIamBX->createRumble(pIamBX, 
					(amBX_loc)(0), 
					(amBX_height)amBX_EVERYHEIGHT,
					&apIamBXRumble);

				RumbleIsCreate = true;
			}
			apIamBXRumble->setRumble(apIamBXRumble,
				"amBX_explosion", 10.0f, (amBX_float)((VibrationCommandType*)dc)->getIntensity()/100);

			pIamBX->update(pIamBX, 0);
		}
		else
		{
			RumbleIsCreate = false;
			apIamBXRumble->release(apIamBXRumble);
		}
	}


	if(dc->getTypeName() == "SprayerType")
	{
		if(dc->getActivate() == true)
		{
			if(SprayerCreate == false)
			{	
				//통신하여 데이터를 보내서 스타트.
				client->MessageSender(((SprayerCommandType*)dc)->getIntensity());
				SprayerCreate = true;
			}
		
		}
		else
		{		
				//통신하여 데이터를 보내서 정지.
				client->MessageSender(((SprayerCommandType*)dc)->getIntensity());
				SprayerCreate = false;
		}
	}

	//DeviceCommandBaseType* dc = deviceCommandList->at(i);
	/*while(clock() < endwait * CLOCKS_PER_SEC)
	{
		for(int i = 0; deviceCommandList->size(); i++)
		{
			DeviceCommandBaseType* dc = deviceCommandList->at(i);

			if((dynamic_cast<ClockTickTimeType*>(dc->getTimeStamp())->getPts()
				/dynamic_cast<ClockTickTimeType*>(dc->getTimeStamp())->getTimeScale()) == clock()/CLOCKS_PER_SEC)
			{
				if(dc->getTypeName() == "LightType")
				{
					if(dc->getActivate() == true)
					{
						ConvertToAmbxRGB(((ColorType*)((LightCommandType*)dc))->getColorRGBType());

						apIamBXLight->setCol(apIamBXLight, 
							amBX_R,
							amBX_G,
							amBX_B);

						pIamBX->update(pIamBX, 0);
					}
					else
					{
						apIamBXLight->release(apIamBXLight);
					}
				}
				if(dc->getTypeName() == "WindType")
				{
					if(dc->getActivate() == true)
					{
						Sleep(300);

						apIamBXFan->setIntensity(apIamBXFan,
							(amBX_float)((WindCommandType*)dc)->getIntensity()/100);

						pIamBX->update(pIamBX, 0);
					}
					else
					{
						apIamBXFan->release(apIamBXFan);
					}
				}
				if(dc->getTypeName() == "VibrationType")
				{
					if(dc->getActivate() == true)
					{
						Sleep(300);

						apIamBXRumble->setRumble(apIamBXRumble,
							"amBX_explosion", 10.0f, (amBX_float)((VibrationCommandType*)dc)->getIntensity()/100);

						pIamBX->update(pIamBX, 0);
					}
					else
					{
						apIamBXRumble->release(apIamBXRumble);
					}
				}
			}
		}
	}*/
}

void Ambx::ConvertToAmbxRGB(string colorRGBType)
{
		int i;
		int checkCount=0;
		
		string rgbBuffer="";
	
		for(i = 0;i < colorRGBType.length(); i++)
		{
			if(colorRGBType.at(i) != ':')
			{
				rgbBuffer+=colorRGBType.at(i);
			} 
			else
			{
				switch(checkCount)
				{
				case 0:
					this->amBX_R = ((amBX_float)atoi(rgbBuffer.c_str()))/255;
					break;
				case 1:
					this->amBX_G = ((amBX_float)atoi(rgbBuffer.c_str()))/255;
					break;
				case 2:
					this->amBX_B = ((amBX_float)atoi(rgbBuffer.c_str()))/255;
					break;
				}
	
				rgbBuffer = "";
				checkCount++;
			}
		}
}
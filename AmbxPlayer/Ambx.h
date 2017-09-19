#pragma once

#include "StdAfx.h"

#include "LightCommandType.h"
#include "WindCommandType.h"
#include "VibrationCommandType.h"
#include "SprayerCommandType.h"

#include "ColorType.h"

#include "IamBX.h"
#include "IamBX_Light.h"
#include "IamBX_Fan.h"
#include "IamBX_Rumble.h"

#include "DeviceCommandBaseType.h"
#include "ClockTickTimeType.h"

#include "Client.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>
#include <time.h>

using namespace std;

class Ambx
{
	public:
		Ambx(void);
		~Ambx(void);

		amBX_float getAmBX_R(){
			return this->amBX_R;
		}
		amBX_float getAmBX_G(){
			return this->amBX_G;
		}
		amBX_float getAmBX_B(){
			return this->amBX_B;
		}
		void setAmBX_R(amBX_float r){
			this->amBX_R = r;
		}
		void setAmBX_G(amBX_float g){
			this->amBX_G = g;
		}
		void setAmBX_B(amBX_float b){
			this->amBX_B = b;
		}
	private:
		IamBX* pIamBX;
		IamBX_Light* apIamBXLight;
		IamBX_Fan* apIamBXFan;
		IamBX_Rumble* apIamBXRumble;

		amBX_float amBX_R;
		amBX_float amBX_G;
		amBX_float amBX_B;

		Client* client;

		bool LightIsCreate;
		bool FanIsCreate;
		bool RumbleIsCreate;
		bool SprayerCreate;

	public:
		void Play(vector<DeviceCommandBaseType*>* deviceCommandList, int i, DWORD videoCur);

		void ConvertToAmbxRGB(string colorRGBType);
};


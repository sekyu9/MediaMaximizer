#ifndef __ColorType_h__
#define __ColorType_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "ColorCS.h"

using namespace std;

class ColorType{
public:
	ColorType();

	void operator=(ColorType& color)
	{
		this->namedColorFlag = color.getNameColorFlag();
		this->namedColorType = color.getNamedColorType();
		this->colorRGBType = color.getColorRGBType();
	}
	bool operator==(const ColorType &color)
	{
		bool isSame = false;

		if(this->namedColorFlag)
		{
			if(this->namedColorType.compare(color.namedColorType)==0)
				isSame = true;
		}		 
		else
		{
			if(colorRGBType.compare(color.colorRGBType)==0)
				isSame = true;
		}

		return isSame;
	}
	bool getNameColorFlag()
	{
		return namedColorFlag;
	}

	void setNameColorFlag(bool nameColorFlag)
	{
		this->namedColorFlag = nameColorFlag;
	}

	string getNamedColorType()
	{
		return namedColorType;
	}

	void setNamedColorType(string namedColorType)
	{
		this->namedColorType = namedColorType;
	}

	string getColorRGBType()
	{
		return this->colorRGBType;
	}

	void setColorRGBType(string colorRGBType)
	{
		this->colorRGBType = colorRGBType;
	}
private:
	ColorCS cs;
	bool namedColorFlag;
	string namedColorType;
	string colorRGBType;
};

#endif
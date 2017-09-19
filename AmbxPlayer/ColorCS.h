#ifndef __ColorCS_h__
#define __ColorCS_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ColorCS
{
public:
	static string convertStringToBinary(string colorString);
	static string convertBinaryToString(string colorBinary);
	static string convertColorToRGB(string colorName);

	//void convertToAmbxRGB(string colorRGBType);
private:
	static const int COLOR_CS_ARRAY_SIZE = 500; 

	static string uri;

	static string colorStringArray [COLOR_CS_ARRAY_SIZE];
			
	static string colorBinaryArray [COLOR_CS_ARRAY_SIZE];

	static string colorRGBArray [COLOR_CS_ARRAY_SIZE];

};

#endif
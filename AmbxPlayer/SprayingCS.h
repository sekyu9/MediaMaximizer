#ifndef __SprayingCS_h__
#define __SprayingCS_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class SprayingCS
{
public:
	static string convertStringToBinary(string sprayingString);
	static string convertBinaryToString(string sprayingBinary);
private:
	static const int SPRAYING_CS_ARRAY_SIZE = 5; 

	static string uri;

	static string sprayingStringArray [SPRAYING_CS_ARRAY_SIZE];
			
	static string sprayingBinaryArray [SPRAYING_CS_ARRAY_SIZE];

};

#endif
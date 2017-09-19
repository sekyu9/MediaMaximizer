#ifndef __ScentCS_h__
#define __ScentCS_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ScentCS
{
public:
	static string convertStringToBinary(string scentString);
	static string convertBinaryToString(string scentBinary);
private:
	static const int SCENT_CS_ARRAY_SIZE = 500; 

	static string uri;

	static string scentStringArray [SCENT_CS_ARRAY_SIZE];
			
	static string scentBinaryArray [SCENT_CS_ARRAY_SIZE];

};

#endif
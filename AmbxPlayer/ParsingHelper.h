#ifndef __ParsingHelper_h__
#define __ParsingHelper_h__

#include "stdafx.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ParsingHelper{
public:
	ParsingHelper();
	~ParsingHelper();

	static vector<float>* getIntensityValue(string intenSityValue);
	static vector<string> getSplitPacket(const char* packetBuffer);
	static string removeNamespace(string value);
	static string extractURL(string);
	static string toString(int);
	static string toString(long);
	static const char* convertTime(int);
};

#endif
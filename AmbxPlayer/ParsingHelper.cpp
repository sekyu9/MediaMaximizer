#include "stdafx.h"
#include "ParsingHelper.h"
#include <string>
#include <stdlib.h>

using namespace std;

vector<float>* ParsingHelper::getIntensityValue(string intenSityValue)
{
	vector<float>* intenSityValueList = new vector<float>;
	char delim = ' ';
	stringstream ss(intenSityValue);
	string item;

	while(getline(ss, item, delim))
	{
		intenSityValueList->push_back(atof(item.c_str()));
	}

	return intenSityValueList;
}

vector<string> ParsingHelper::getSplitPacket(const char* packetBuffer)
{
	vector<string> splitPacket;
	char delim = ':';
	stringstream ss(packetBuffer);
	string item;

	while(getline(ss, item, delim))
	{
		splitPacket.push_back(item);
	}

	return splitPacket;			
}

string ParsingHelper::removeNamespace(string value)
{
	string retvalue;
	char delim = ':';
	stringstream ss(value);
	string item;

	while(getline(ss, item, delim))
	{
		retvalue = item;
	}

	return retvalue;		
}

string ParsingHelper::extractURL(string url)
{
	string dividedUrl;
	stringstream ss(url);
	string item;
	int size = 0;

	while(getline(ss, item, '/'))
	{
		dividedUrl = item;
	}

	for(int i = dividedUrl.size() - 1; i >= 0; i--)
	{
		string tmp(dividedUrl, i, 1);

		if(tmp == ".")
		{
			size = i;
			break;
		}
	}

	string ret(dividedUrl, 0, size);

	return ret;
}

string ParsingHelper::toString(int val)
{
	ostringstream ss;
	ss << val;

	return ss.str();
}

string ParsingHelper::toString(long val)
{
	ostringstream ss;
	ss << val;

	return ss.str();
}

const char* ParsingHelper::convertTime(int time)
{
	int sec = 0;
    int min = 0;
    int hour = 0;

    sec = time % 60;
    min = time / 60;
    hour = min / 60;
    min = min % 60;

    string hh = toString(hour);
    string mm = toString(min);
    string ss = toString(sec);

    if(hh.size() == 1)
    	hh = "0" + hh;
    
    if(mm.size() == 1)
    	mm = "0" + mm;

    if(ss.size() == 1)
    	ss = "0" + ss;

    string ret = hh + mm + ss + "00";

    return ret.c_str();
}
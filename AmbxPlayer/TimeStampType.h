#ifndef __TimeStampType_h__
#define __TimeStampType_h__

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class TimeStampType{
public:
	TimeStampType();
	virtual ~TimeStampType();

protected:
	string typeName;
};


#endif
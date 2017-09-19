#ifndef __ClockTickTimeType_h__
#define __ClockTickTimeType_h__

#include "stdafx.h"
#include "TimeStampType.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class ClockTickTimeType : public TimeStampType
{
public:
	ClockTickTimeType();
	virtual ~ClockTickTimeType();

	/* getter & setter */
	bool getIsTimeScale()
	{
		return this->isTimeScale;
	}

	void setIsTimeScale(bool isTimeScale)
	{
		this->isTimeScale = isTimeScale;
	}

	long getTimeScale()
	{
		return this->timeScale;
	}

	void setTimeScale(long timeScale)
	{
		this->isTimeScale = true;
		this->timeScale = timeScale;
	}

	long getPts()
	{
		return this->pts;
	}

	void setPts(long pts)
	{
		this->pts = pts;
	}
private:
	bool isTimeScale;
	long timeScale;
	long pts;
};

#endif
#ifndef __Engine_h__
#define __Engine_h__

#include "stdafx.h"
#include <xercesc/parsers/SAXParser.hpp>

#include "UXSAXHandler.h"
#include "SEMRootElement.h"
#include "ControlInfoRootElement.h"
#include "InteractionInfoRootElement.h"

using namespace std;

class Engine{
public:
	//Constructor and Destructor
	Engine();
	~Engine();

	//Getters and Setters
	const string getTitle() const 
	{
		return title;
	}
	void setTitle(string title)
	{
		this->title = title;
	}

	const float getTemperature() const
	{
		return temperature;
	}

	void setTemperature(float temperature)
	{
		this->temperature = temperature;
	}
	
	SEMRootElement* getSEM() const 
	{
		return sem;
	}

	void setSEM(SEMRootElement* sem) 
	{
		this->sem = sem;
	}

	InteractionInfoRootElement* getIIDL() const 
	{
		return iidl;
	}

	void setIIDL(InteractionInfoRootElement* iidl) 
	{
		this->iidl = iidl;
	}

	ControlInfoRootElement* getCI() const 
	{
		return ci;
	}

	void setCI(ControlInfoRootElement* ci) 
	{
		this->ci = ci;
	}
	//Public methods
	bool loadXML(int);
	void createDeviceCommand();
private:
	//private methods
	void initSAXParser();
	void parseXML(SAXParser*, string);
	void createIIDL(vector<EffectBaseType*>*);

	//member variables
	string title;
	float temperature;
	int time;
	SAXParser *parser;
	UXSaxHandler *docHandler;

	SEMRootElement *sem;
	ControlInfoRootElement *ci;
	InteractionInfoRootElement *iidl;
};

#endif
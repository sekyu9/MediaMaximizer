#include "stdafx.h"
#include "Engine.h"

#include <io.h>
#include <algorithm>

#include "LightType.h"
#include "FlashType.h"
#include "TemperatureType.h"
#include "WindType.h"
#include "VibrationType.h"
#include "SprayingType.h"
#include "ScentType.h"
#include "FogType.h"

#include "DeviceCommandBaseType.h"
#include "CoolingCommandType.h"
#include "FlashCommandType.h"
#include "FogCommandType.h"
#include "HeatingCommandType.h"
#include "LightCommandType.h"
#include "ScentCommandType.h"
#include "SprayerCommandType.h"
#include "VibrationCommandType.h"
#include "WindCommandType.h"

#include "ClockTickTimeType.h"

#include "ParsingHelper.h"

#include "constants.h"

bool CompareObj(DeviceCommandBaseType *first, DeviceCommandBaseType *second )
{	
	return dynamic_cast<ClockTickTimeType*>(first->getTimeStamp())->getPts() < dynamic_cast<ClockTickTimeType*>(second->getTimeStamp())->getPts();
}

Engine::Engine()
{
	title = "-1";
	temperature = 25.0f;
	time = -1;

	sem = 0;
	ci = 0;

	iidl = new InteractionInfoRootElement();
}
Engine::~Engine()
{
	if(sem != 0)
	{
		delete sem;
		sem = 0;
	}
	if(ci != 0)
	{
		delete ci;
		ci = 0;
	}
	if(iidl != 0)
	{
		delete iidl;
		iidl = 0;
	}
}

bool Engine::loadXML(int xml)
{
	if(xml == XML::SEM && sem != 0)
	{
		delete sem;
		sem = 0;
	}
	if(xml == XML::CIDL && ci != 0)
	{
		delete ci;
		ci = 0;
	}

	try
	{
		initSAXParser();

		string xmlFileName;

		if(xml == XML::SEM)
		{
			xmlFileName = this->title;
		}
		else if(xml == XML::CIDL)
		{
			xmlFileName = "CIDLInstance.xml";
		}
		if(access(xmlFileName.c_str(), 0) == 0)
		{
			parseXML(parser, xmlFileName);

			if(docHandler->getRoot() ==0)
				return false;

			if(xml == XML::SEM)
			{
				sem = new SEMRootElement(docHandler->getRoot());
				sem->mappingData();
			}
			else if(xml == XML::CIDL)
			{
				ci = new ControlInfoRootElement(docHandler->getRoot());
				ci->mappingData();
			}
		}
		else
		{
			cout << "Error: " << xmlFileName << "not found." << endl;
			return false;
		}
	}
	catch(int &exception)
	{
		if(exception == 0)
		{
			cout << "Error: PArser initialization error." << endl;
		}
		else if(exception == 1)
		{
			cout << "Error: XML Parsing error." << endl;

			delete parser;
			delete docHandler;
		}
		return false;
	}

	return true;
}

void Engine::initSAXParser()
{
	try
	{
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch)
	{
		char *message = XMLString::transcode(toCatch.getMessage());
		cout << "Error: during initialization :\n"
			 << message << "\n";
		XMLString::release(&message);

		throw 0;
	}

	parser = new SAXParser();
	parser->setDoNamespaces(true);

	docHandler = new UXSaxHandler();
	ErrorHandler *errHandler = (ErrorHandler*)docHandler;

	parser->setDocumentHandler(docHandler);
	parser->setErrorHandler(errHandler);
}

void Engine::parseXML(SAXParser *parser, string xmlFile)
{
	try
	{
		parser->parse(xmlFile.c_str());
	}
	catch (const XMLException &toCatch)
	{
		char *message = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n"
			 << message << "\n";
		XMLString::release(&message);

		throw 1;
	}
	catch (const SAXParseException &toCatch)
	{
		char *message  = XMLString::transcode(toCatch.getMessage());
		cout << "Exception message is: \n"
			 << message << "\n";
		XMLString::release(&message);

		throw 1;
	}
	catch (...)
	{
		cout << "Unexpected Exception \n";

		throw 1;
	}
}


void Engine::createDeviceCommand()
{
	//get effect List
	vector<EffectBaseType*> *eList = sem->getEffectList();

	createIIDL(eList);

	//get froup of effect List
	vector<GroupOfEffectsElement*> *goeList = sem->getGroupOfEffectsList();

	for(vector<GroupOfEffectsElement*>::iterator i = goeList->begin();
		i != goeList->end();
		++i)
	{
		eList = (*i)->getEffectList();

		//Set pts
		for(vector<EffectBaseType*>::iterator iter = eList->begin();
			iter != eList->end();
			++iter) 
		{
			(*iter)->setPts((*i)->getPts());
		}
		createIIDL(eList);
	}

	sort(iidl->getDeviceCommandList()->begin(), iidl->getDeviceCommandList()->end(), CompareObj);
}

void Engine::createIIDL(vector<EffectBaseType*> *eList)
{
	//Initialize
	EffectBaseType *effect = 0;
	SensoryDeviceCapabilityBaseType *sdc = 0;

	DeviceCommandBaseType *dc = 0;

	for(int i = 0; i < eList->size(); i++)
	{
		//Initialize
		effect = eList->at(i);
		sdc = 0;
		dc = 0;

		effect->setTimeScale(sem->getTimeScale());

		//Find correct effect type
		if(dynamic_cast<LightType*>(effect))
		{
			/*if(dynamic_cast<FlashType*>(effect))
			{
				if(ci != 0)
				{
					sdc = ci->getSDC(SDC::FLASH);
				}
				dc = new FlashCommandType(effect, sdc);
			}*/
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::LIGHT);
			}
			dc = new LightCommandType(effect, sdc);

		}
		
		else if(dynamic_cast<WindType*>(effect))
		{
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::WIND);
			}
			dc = new WindCommandType(effect, sdc);
		}
		else if(dynamic_cast<VibrationType*>(effect))
		{
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::VIBRATION);
			}

			dc = new VibrationCommandType(effect, sdc);
		}
		/*
		else if(dynamic_cast<TemperatureType*>(effect))
		{
			float gap = this->temperature - ((TemperatureType*)effect)->getIntensityValue();
			if(gap >= 0)
			{
				if(ci != 0)
				{
					sdc = ci->getSDC(SDC::COOLING);
				}
				dc = new CoolingCommandType(effect,  sdc);
			}
			else
			{
				if(ci != 0)
				{
					sdc = ci->getSDC(SDC::HEATING);
				}
				
				dc = new HeatingCommandType(effect,  sdc);
			}
		}
		*/
		else if(dynamic_cast<SprayingType*>(effect)) 
		{
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::SPRAYER);
			}

			dc = new SprayerCommandType(effect, sdc);
		}
		/*
		else if(dynamic_cast<ScentType*>(effect)) 
		{
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::SCENT);
			}

			dc = new ScentCommandType(effect, sdc);
		}
		else if(dynamic_cast<FogType*>(effect)) 
		{
			if(ci != 0)
			{
				sdc = ci->getSDC(SDC::FOG);
			}

			dc = new FogCommandType(effect,  sdc);
		}*/

		//Make IIDL
		if(dc != 0)
		{
			iidl->addDeviceCommand(dc);
		}
	}
}



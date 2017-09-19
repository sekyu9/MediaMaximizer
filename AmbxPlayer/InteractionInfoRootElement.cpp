#include "stdafx.h"
#include "InteractionInfoRootElement.h"
#include "LightCommandType.h"
#include "WindCommandType.h"
#include "VibrationCommandType.h"
#include "ClockTickTimeType.h"

string InteractionInfoRootElement::xmlUTF = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
string InteractionInfoRootElement::attribute = "xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:mpeg7=\"urn:mpeg:mpeg7:schema:2004\" xmlns:mpegvct=\"urn:mpeg:mpeg-v:2010:01-CT-NS\" xmlns:iidl=\"urn:mpeg:mpeg-v:2010:01-IIDL-NS\" xmlns:dcv=\"urn:mpeg:mpeg-v:2010:01-DCV-NS\" xsi:schemaLocation=\"urn:mpeg:mpeg-v:2010:01-DCV-NS MPEG-V-DCV.xsd\"";

InteractionInfoRootElement::InteractionInfoRootElement()
{
	this->deviceCommandList = new vector<DeviceCommandBaseType*>();
}


InteractionInfoRootElement::~InteractionInfoRootElement()
{
	vector<DeviceCommandBaseType*>::iterator i;
	for(i = deviceCommandList->begin(); i != deviceCommandList->end(); i++)
	{
		delete *i;
	}
	delete deviceCommandList;
}

void InteractionInfoRootElement::addDeviceCommand(DeviceCommandBaseType* command)
{
	this->deviceCommandList->push_back(command);
}
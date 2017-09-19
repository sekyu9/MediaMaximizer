#include "stdafx.h"

#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "UXSAXHandler.h"
#include "SEMRootElement.h"
#include "ControlInfoRootElement.h"
#include "InteractionInfoRootElement.h"
#include "Engine.h"
#include "constants.h"

//using namespace std;
//using namespace xercesc;

typedef map<string, string> AttributeMap;
void parseXML(SAXParser* parser, const char* xmlFile);

int main(int argc, char* args[]){

	//XMLParser start-----------------------
	try{
		XMLPlatformUtils::Initialize();
	}catch(const XMLException& toCatch){
		char* message = XMLString::transcode(toCatch.getMessage());
		cout<< "Error during initialization! :\n"
			<< message << "\n";
		XMLString::release(&message);
		return 1;
	}
	
	SAXParser* parser = new SAXParser();
	parser->setDoNamespaces(true);

	UXSaxHandler* docHandler = new UXSaxHandler();
	ErrorHandler* errHandler = (ErrorHandler*) docHandler;

	parser -> setDocumentHandler(docHandler);
	parser -> setErrorHandler(errHandler);


	Engine *engine = new Engine();

	int size;
	string title;

	while(1)
	{
		
		// Set media title
		engine->setTitle(title);

		// Load SEM and CI
		if(engine->loadXML(XML::SEM))
		{
			cout << "System: Loaded SEM." << endl;

			if(engine->loadXML(XML::CIDL))
				cout << "System: Loaded CIDL." << endl;
			else
				cout << "Error: Failed to load CIDL file." << endl;

			engine->createDeviceCommand();
			cout << "System: Created device commands." << endl;	
		} 
		
		cout << endl;
		break;
	}

	delete engine;
	

	return 0;

}
void parseXML(SAXParser* parser, const char* xmlFile)
{
    try {
        parser->parse(xmlFile);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (const SAXParseException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
    }
}
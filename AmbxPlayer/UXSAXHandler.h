#ifndef __UXSaxHandler_h__
#define __UXSaxHandler_h__

#include "stdafx.h"
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/framework/XMLFormatter.hpp>
#include <vector>
#include "ElementBaseType.h"


using namespace xercesc;
using namespace std;

typedef vector<ElementBaseType> ElementBaseTypeList;

class UXSaxHandler : public HandlerBase{
public:
	//constructor
	UXSaxHandler();

	virtual ~UXSaxHandler();

	//getter & setter
	ElementBaseType* getRoot()
	{
		return root;
	}

	//member method
	void startElement(const XMLCh* const, AttributeList&);
    void fatalError(const SAXParseException&);
    void endElement(const XMLCh* const name);
    void characters (const XMLCh *const chars, const XMLSize_t length);
    string removeNamespace(string s);

private:
	int treeLevel;
	ElementBaseType* root;
	ElementBaseType* currentElement;
	ElementBaseType* createdElement;
};
#endif
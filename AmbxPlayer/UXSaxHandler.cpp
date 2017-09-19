#include "stdafx.h"
#include <map>
#include "UXSAXHandler.h"
#include <iostream>
#include <string>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/AttributeList.hpp>

//using namespace std;

/** constructor **/
UXSaxHandler::UXSaxHandler() 
: HandlerBase()
{
    this->root = NULL;
    this->currentElement = NULL;
    this->createdElement = NULL;
    this->treeLevel = -1;
}

UXSaxHandler::~UXSaxHandler()
{
}


void UXSaxHandler::startElement(const XMLCh* const name,
                           AttributeList& attr)
{
    treeLevel++;
    createdElement = new ElementBaseType(currentElement, treeLevel);
	cout<<"---------------"<<endl;
	cout<<currentElement->getName()<<endl;
	//cout<<createdElement->getName()<<endl;
    // attributes mapping
    int len = attr.getLength();
    for(int i = 0; i < len; i++) 
    {
        char* aName = XMLString::transcode(attr.getName(i));
        char* aValue = XMLString::transcode(attr.getValue(i));    
        createdElement->addAttribute(removeNamespace(string(aName)), removeNamespace(string(aValue)));
        XMLString::release(&aName);        
        XMLString::release(&aValue);        
    }


    // element name mapping
    string elementName = string(XMLString::transcode(name));
    createdElement->setName(removeNamespace(elementName));
    
    if(currentElement != NULL)           // not root element
    {
        currentElement->addChildElement(createdElement);
    }
    else                                 // root element
    {
        root = createdElement;
    }
    
    currentElement = createdElement;
}

void UXSaxHandler::characters(const XMLCh *const chars, const XMLSize_t length)   
{
    string content = string(XMLString::transcode(chars));
    for(int i = 0; i < content.length(); i++)
    {
        if(content[i] == ' ' || content[i] == '\n') content.erase(i, 1);
    }

    ElementBaseType* parent = currentElement->getParent();
    if(parent != NULL)
    {
        vector<ElementBaseType*>* v = parent->getChildList();
        if(!(v->empty()) )
        {
            ElementBaseType* e = v->back();
            e->setContent(content);
        }
    }
}

void UXSaxHandler::fatalError(const SAXParseException& exception)
{
    char* message = XMLString::transcode(exception.getMessage());
    cout << "Fatal Error: " << message
         << " at line: " << exception.getLineNumber()
         << endl;
    XMLString::release(&message);
}

void UXSaxHandler::endElement(const XMLCh* const name)
{
    treeLevel--;
    currentElement = currentElement->getParent();
}

string UXSaxHandler::removeNamespace(string s)
{
    int pos = s.find(":");
    if(pos == -1 ) return s;
    else return s.substr(pos+1);
}
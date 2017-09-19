#include "stdafx.h"
#include "ElementBaseType.h"
#include <iostream>

using namespace std;

ElementBaseType::ElementBaseType()
{
	this->attributeMap = new AttributeMap();
	this->childElementList = new vector<ElementBaseType*>;
	this->parent = NULL;
	this->level = -1;
}

ElementBaseType::ElementBaseType(ElementBaseType* parent, int level)
{
	this->attributeMap = new AttributeMap();
	this->childElementList = new vector<ElementBaseType*>;
	this->parent = parent;
	this->level = level;
}

ElementBaseType::~ElementBaseType()
{
	for(int i = 0; i < childElementList->size(); i++)
	{
		ElementBaseType* e = childElementList->at(i);
		delete e;
	}
}

void ElementBaseType::addAttribute(string name, string value)
{
	
	if(attributeMap->insert(pair<string, string>(name, value)).second == false)//같은 값을 가지면 attribute i
	{
		cout << "Attribute inserting is failed" << endl;
	}
}

void ElementBaseType::addChildElement(ElementBaseType* child)
{
	this->childElementList->push_back(child);
}
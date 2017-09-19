#ifndef __ElementBaseType_h__
#define __ElementBaseType_h__

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef map<string, string> AttributeMap;

class ElementBaseType{
public:
	//constructor
	ElementBaseType();
	ElementBaseType(ElementBaseType* parent, int level);

	virtual ~ElementBaseType();

	//getter & setter
	void setName(string name)
	{
		this->name = name;
	}

	string getName()
	{
	    return name;
	}

	void setAttributeMap(AttributeMap* attributeMap) 
	{
		this->attributeMap = attributeMap;
	}

	AttributeMap* getAttributeMap()
	{
		return attributeMap;
	}

	ElementBaseType* getParent()
	{
		return parent;
	}

	int getLevel()
	{
		return level;
	}

	vector<ElementBaseType*>* getChildList()
	{
		return childElementList;
	}

	void setContent(string s)
	{
		this->content = s;
	}

	string getContent()
	{
		return content;
	}
	void setTest(int tree)
	{
		this->level = tree;
	}
	//member method
	void addAttribute(string name, string value);
	void addChildElement(ElementBaseType* e);

private:
	string name;
	AttributeMap* attributeMap;
	vector<ElementBaseType*>* childElementList;
	string content;
	ElementBaseType* parent;
	int level;
};

#endif

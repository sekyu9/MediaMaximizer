#ifndef __DescriptionMetadataElement_h__
#define __DescriptionMetadataElement_h__

#include "stdafx.h"
#include "ElementBaseType.h"
#include <vector>
#include <iostream>


class DescriptionMetadataElement
{
public:
	DescriptionMetadataElement(ElementBaseType* e);
	virtual ~DescriptionMetadataElement();

	void mappingData();

	/*getter & setter*/
	string getAlias() const
    {
        return alias;
    }

    void setAlias(string alias)
    {
        this->alias = alias;
    }

    vector<ElementBaseType*>* getClassificationSchemeAliasList() const
    {
        return classificationSchemeAliasList;
    }

    void setClassificationSchemeAliasList(vector<ElementBaseType*>* classificationSchemeAliasList)
    {
        this->classificationSchemeAliasList = classificationSchemeAliasList;
    }

    ElementBaseType* getDescriptionMetadata() const
    {
        return descriptionMetadata;
    }

    void setDescriptionMetadata(ElementBaseType* descriptionMetadata)
    {
        this->descriptionMetadata = descriptionMetadata;
    }

    string getHref() const
    {
        return href;
    }

    void setHref(string href)
    {
        this->href = href;
    }

    string getId() const
    {
        return id;
    }

    void setId(string id)
    {
        this->id = id;
    }

    vector<ElementBaseType*>* getMpeg7DescriptionMetadataList() const
    {
        return mpeg7DescriptionMetadataList;
    }

    void setMpeg7DescriptionMetadataList(vector<ElementBaseType*>* mpeg7DescriptionMetadataList)
    {
        this->mpeg7DescriptionMetadataList = mpeg7DescriptionMetadataList;
    }

private:
	// Group Of Effects Element
	ElementBaseType* descriptionMetadata;

	/** MPEG7 DescriptionMetadata Element List **/
	vector<ElementBaseType*>* mpeg7DescriptionMetadataList;

	/** ClassificationSchemeAlias Element List **/
	vector<ElementBaseType*>* classificationSchemeAliasList;

	/** SEMBaseType **/
	string id;

	/** attribute **/
	string alias;
	string href;
};

#endif
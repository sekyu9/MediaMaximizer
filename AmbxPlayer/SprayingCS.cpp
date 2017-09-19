#include "stdafx.h"
#include "SprayingCS.h"

string SprayingCS::uri = "urn:mpeg:mpeg-v:01-SI-SprayingTypeCS-NS:";

string SprayingCS::sprayingStringArray [] = { "water" };

string SprayingCS::sprayingBinaryArray [] = { "00000000" };

string SprayingCS::convertBinaryToString(string sprayingBinary)
{
	string retValue;

	for (int i = 0; i < SPRAYING_CS_ARRAY_SIZE; i++) {
		if (sprayingBinary.compare(sprayingBinaryArray[i]) == 0) {
			//retValue = uri + sprayingStringArray[i];
			retValue = sprayingStringArray[i].append(uri);
			break;
		}
	}

	return retValue;

}

string SprayingCS::convertStringToBinary(string sprayingString)
{
	string retValue;

	if (sprayingString.compare("") == 0)
		return NULL;

	if (sprayingString.find(uri) != -1)
	{
		// remove uri from sprayingString
		sprayingString = sprayingString.substr(uri.size(), sprayingString.size() - uri.size());
	}

	for (int i = 0; i < SPRAYING_CS_ARRAY_SIZE; i++) {
		if (sprayingString.compare(sprayingStringArray[i]) == 0) {
			retValue = sprayingBinaryArray[i];
			break;
		}
	}

	return retValue;
}
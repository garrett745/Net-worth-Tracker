#include "data  Dependencies.h"

std::string addCommasToInt(const int& numToAddCommas)
{
	std::string output;
	std::string sBuffer = std::to_string(numToAddCommas);
	int commaForNetA = 0;

	while (pow(1000, commaForNetA) <= numToAddCommas)
	{
		if (pow(1000, commaForNetA + 1) > numToAddCommas)
		{
			break;
		}
		commaForNetA++;
	}

	int placeOfComma1 = sBuffer.size() % 3;
	if (placeOfComma1 == 0) placeOfComma1 = 3;

	for (int i = 0; i < placeOfComma1; i++)
	{
		output.push_back(sBuffer[i]);
	}
	if (commaForNetA == 0)
	{
		return output;
	}

	output.push_back(',');

	for (int i = 0; i < sBuffer.size() - placeOfComma1 + commaForNetA - 1; i++)
	{
		if (i % 3 == 0 && i != 0 && i != sBuffer.size() - placeOfComma1 + commaForNetA - 2)
		{
			output.push_back(',');
		}
		output.push_back(sBuffer[i + placeOfComma1]);
	}
	
	return output;
}
#pragma once
#include "data  Dependencies.h"

struct timeStamp
{
	int quarter;
	int year;
	int revisedDataIttoratior;

	void operator =(std::string input)
	{
		std::string buffer = "";

		buffer = input[1];
		quarter = std::stof(buffer);

		buffer.erase();
		buffer.push_back(input[3]); buffer.push_back(input[4]); buffer.push_back(input[5]); buffer.push_back(input[6]);
		year = std::stof(buffer);

		buffer.erase();
		buffer = input[13];
		revisedDataIttoratior = std::stof(buffer);
	}

	bool operator ==(timeStamp compair)
	{
		if (timeStamp::quarter == compair.quarter && timeStamp::year == compair.year && timeStamp::revisedDataIttoratior == compair.revisedDataIttoratior)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class data
{
public:
	timeStamp timeStamp;
	unsigned int netWorthA; //actual
	unsigned int netWorthE; //estimated

	data();
	data(int quarter, int year);

	std::string stringFormat(bool saveFormat = false) const;


};

bool timestampExists(timeStamp compair, std::vector<data>& masterDataList);
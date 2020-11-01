#include "data.h"

data::data()
{
	data::timeStamp.quarter = 0;
	data::timeStamp.year = 0;

	data::timeStamp.revisedDataIttoratior = 0;

	data::netWorthA = 0;
	data::netWorthE = 0;
}

data::data(int quarter, int year)
{
	data::timeStamp.quarter = quarter;
	data::timeStamp.year = year;

	data::timeStamp.revisedDataIttoratior = 0;

	data::netWorthA = 0;
	data::netWorthE = 0;
}

std::string data::stringFormat(bool saveFormat) const
{
	std::string outputData = "";
	std::string stringNetWorthA;
	std::string stringNetWorthE;

	switch (saveFormat)
	{
	case true:
	{
		stringNetWorthA = std::to_string(netWorthA);
		stringNetWorthE = std::to_string(netWorthE);

		outputData += "Q" + std::to_string(timeStamp.quarter) + " " + std::to_string(timeStamp.year) + " " + "RVI: " + std::to_string(timeStamp.revisedDataIttoratior) + "\n"
			+ "Net Worth: " + stringNetWorthA + " " + "Net Worth Estimate: " + std::to_string(netWorthE) + "\n\n";

		return outputData;
	}
	case false:
	{
		stringNetWorthA = addCommasToInt(netWorthA);
		stringNetWorthE = addCommasToInt(netWorthE);

		outputData += "Q" + std::to_string(timeStamp.quarter) + " " + std::to_string(timeStamp.year) + " " + "RVI: " + std::to_string(timeStamp.revisedDataIttoratior) + "\n"
			+ "Net Worth: $" + stringNetWorthA + " " + "Net Worth Estimate: $" + std::to_string(netWorthE) + "\n\n";

		return outputData;
	}
	}
}

bool timestampExists(timeStamp compair, std::vector<data>& masterDataList)
{
	for (int i = 0; i < masterDataList.size(); i++)
	{
		if (compair.year == masterDataList[i].timeStamp.year && compair.quarter == masterDataList[i].timeStamp.quarter)
		{
			return true;
		}
	}
	return false;
}